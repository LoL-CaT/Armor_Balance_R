require([[/script/multiplayer/bot.data]])

local PLATOON_CAPTURE_INFANTRY = "capture1"
local PLATOON_CAPTURE_VEHICLES = "capture2"

local PLATOON_RETREAT = "retreat"
local PLATOON_WAIT = "wait"
local PLATOON_WAIT_CAPTURE = "wait"

local Context = {
	fullList = nil,
	cFlags = {},
	aFlags = {},
	eFlags = {},
	nFlags = {},
	maxFlags = 0,
	orderQueue = {},
	squadOffset = 0,
	squads = {},
	lastBuy = nil,
	lastBuyCount = 0,
	platoons = {
		alpha={name = "alpha",squads = {}, order = PLATOON_WAIT, lockUntil=0, flag = nil },
		beta={name ="beta", squads = {}, order = PLATOON_WAIT, lockUntil=0, flag = nil },
		delta={name = "delta", squads = {}, order = PLATOON_WAIT, lockUntil=0, flag = nil }
		}
}



function interpolate(p, x1,y1,x2,y2)

	p = math.min(p,x2)
	p = math.max(p,x1)
	
	return y1 + (p-x1)*((y2-y1)/(x2-x1))
end 

function getInterval(quants) 
	return interpolate(quants,
		UnitClass.Intervals.growthStarts, UnitClass.Intervals.beginInterval,
		UnitClass.Intervals.growthEnds, UnitClass.Intervals.endInterval)
	
end

function getClassMin(quants, class)

	return interpolate(quants,
		class.growthStarts, class.min.early,
		class.growthEnds, class.min.late)
end
function getClassMax(quants, class)

	return interpolate(quants,
		class.growthStarts, class.max.early,
		class.growthEnds, class.max.late)
end

function canBuyAtCurrentTime(unit,quants) 

		local filter = false
		if (Purchases) then -- use hand curated unit list
			filter = true
			for i, l in ipairs(Purchases) do
				for i, arm in pairs(l.Units) do
					for i, u in pairs(arm) do
						if (u.unit == unit.unit) then filter = false end
					end
				end
			end
		end

		if (filter) then return false end
		if (unit.class.dontBuyBefore > quants) then 
			return false
		end
		if (unit.waitAtQuant > quants) then 
			return false
		end
		local cost = unit.cost
		local minc = getClassMin(quants, unit.class)
		local maxc = getClassMax(quants, unit.class)
		return cost >= minc and cost <= maxc
end


function GetRandomItem(items, getRate)
	local item_rates = {}
	
	local total = 0
	for i, item in pairs(items) do
		local rate = getRate(item)
		
		total = total + rate
		table.insert(item_rates, {i = item, r = rate})
	end
	
	local rnd = math.random()
	local bound = 0.0
	
	for j, item_rate in pairs(item_rates) do
		bound = bound + item_rate.r
		if rnd < bound / total then
			local r = item_rate.i
			item_rates = nil
			return r
		end
	end
end

function IsCapturedFlag(flag)
	return flag.occupant == BotApi.Instance.team
end

function IsEnemyFlag(flag)
	return flag.occupant == BotApi.Instance.enemyTeam
end

function GetFlagCapturePriority(flag)
	if		IsCapturedFlag(flag)then return FlagPriority.Captured
	elseif	IsEnemyFlag(flag)	then return FlagPriority.Enemy
	else 							 return FlagPriority.Neutral
	end
end
function GetFlagDefendPriority(flag)
	if		IsCapturedFlag(flag)then return 20
	elseif	IsEnemyFlag(flag)	then return 1
	else 							 return 2
	end
end

function GetFlagToCapture(flagPoints, getPriority)
	local flags = {}
	
	for i, flag in pairs(flagPoints) do
		table.insert(flags, {name = flag.name, k = getPriority(flag)})
	end
	
	return GetRandomItem(flags, function(f) return f.k end)
end




function readUnitsRaw(fname, units,army) 
	if (verbose) then print("reading ", fname , " for ", army) end
	f = io.open(fname,"r")
	if f~=nil then 
		while true do
			local asRead = f:read("*l")
			local line = asRead
			if line == nil then break end
			
			line = line:gsub(";.*","")
			line = line:gsub("^%s*(.-)%s*$", "%1")
			if (line:lower():find("[(]"..army:lower().."[)]") and line:len() > 0  --only things of the current army
				and line:find("ammo")  == nil --no ammo and heroes
				and line:find("flamers")  == nil --no
				and line:find("bazookers2")  == nil --no	
				and line:find("np_lrdg_37mm")  == nil --no	
				and line:find("willysat")  == nil --no	
				and line:find("np_willysat")  == nil --no					
				and line:find("support")  == nil   -- no cannons, support crew and artys
				and line:find("miner")  == nil and line:find("engineer") == nil-- no cannons, support crew and artys
				and line:find("sapper")  == nil and line:find("supply") == nil-- no cannons, support crew and artys
				and line:find("zis5")  == nil and line:find("gmc") == nil-- robz supply truck don't have a supply tag
				and line:find("blitz")  == nil and line:find("bedford") == nil-- robz supply truck don't have a supply tag
				and line:find("sdkfz303")  == nil and line:find("np_sdkfz8")  == nil -- no goliath just to be sure
				and line:find("horse")  == nil and line:find("spear")  == nil -- really??
				and line:find("officer")  == nil and line:find("sniper")  == nil -- more units ai can't use effectively
				and line:find("riflemans2")  == nil and line:find("smgs2")  == nil -- одиночные солдаты
				and line:find("mgs2")  == nil and line:find("mgs34")  == nil -- одиночные солдаты
				and line:find("shotguns")  == nil and line:find("tankmans")  == nil -- одиночные солдаты
				and line:find("at_rifles4")  == nil and line:find("at_rifles2")  == nil -- одиночные солдаты
				and line:find("at_rifles")  == nil and line:find("at_rifles3")  == nil -- одиночные солдаты	
				and line:find("gzb_rifles")  == nil and line:find("bazookers")  == nil -- одиночные солдаты				
				and line:find("_eng")  == nil and line:find("_art") == nil-- red rising supply truck don't have a supply tag
				and ( (line:find("hero")  == nil and line:find("tankman")  == nil) or (line:find("hero")  and line:find("tankman") and line:find("[(]\"v[0-9]") ) )
				and line:find("b[(]v1[)]") == nil  and line:find("b[(]v2[)]") == nil  and line:find("b[(]v6[)]") == nil  and line:find("b[(]v8[)]") == nil  and line:find("b[(]v9[)]") == nil  and line:find("b[(]v22[)]") == nil  and line:find("b[(]special[)]") == nil   -- no things for the support menu (all carried weapon don't work)
				) then 
				if (verbose) then print("parsing ", line) end
				local unit = line
				unit = unit:gsub( ".*name[(]", "")
				unit = unit:gsub( "[)].*", "")

				local cost = line
				cost = cost:gsub( ".*[{]cost ", "")
				cost = cost:gsub( ".*cost[(]", "")
				cost = cost:gsub( "[})].*", "")
				cost =  tonumber(cost)
				
				local fcost = cost
					
				if(cost == nil) then cost = 197 end
				if(cost == 0) then cost = 1 end
				
				if (fcost == nil) then fcost = 0 end
				local count = 0 
				local charge = 0
				local fore = 0
				local group = 0
				for uc in line:gmatch(" c[(]([^)]*)[)]") do
				  charge = charge + tonumber(uc)
				end
				for uc in line:gmatch(" f[(]([^)]*)[)]") do
				  fore = fore + tonumber(uc)
				end
				for uc in line:gmatch("[{]fore ([0-9]+)[}]") do
				  fore = fore + tonumber(uc)
				end
				for uc in line:gmatch(" g[(]([^)]*)[)]") do
				  group = uc
				end
				
				fore = 1 - fore
				waitAtQuant = (charge * fore * 50 + 1)
				if (line:find('squad')) then 
				
					for uc in line:gmatch("c[0-9]+[(][^)]*:([0-9]+)") do
						count = count + tonumber(uc)
					end
					

				
					
					if (count > 0 ) then
						cost = cost/count
					end
				end
				if (count == 0 or count == nil) then 
					count = 1
				end
				if (unit:len()>0 and not  unit:match("{")) then
					if (line:find(" side( ")) then
						units[units.count] = { unit = unit.."("..army..")",count = count, class = UnitClass.Infantry, priority = (0.5 * fcost), fcost = fcost,
							cost = cost, charge = charge, fore = fore, group = group, waitAtQuant = waitAtQuant}
						units.count = units.count + 1
					else 
						units[units.count] = { unit = unit.."("..army..")",count = count, class = UnitClass.Infantry, priority = (0.5 * fcost), fcost = fcost,
							cost = cost, charge = charge, fore = fore, group = group, waitAtQuant = waitAtQuant}
						units.count = units.count + 1
					end	
				else 
					unit = line
					unit = unit:gsub( "{\"", "")
					unit = unit:gsub( "\".*", "")
					if (unit:match("mp/")) then

						unit = unit:gsub("mp/[^/]*/","")

						if (line:find(" side( ")) then
							units[units.count] = { unit = unit.."("..army..")",count = count, class = UnitClass.Infantry, priority = (0.5 * fcost), fcost = fcost,
								cost = cost, charge = charge, fore = fore, group = group, waitAtQuant = waitAtQuant}
							units.count = units.count + 1
						else 
							units[units.count] = { unit = unit.."("..army..")",count = count, class = UnitClass.Infantry, priority = (0.5 * fcost), fcost = fcost,
								cost = cost, charge = charge, fore = fore, group = group, waitAtQuant = waitAtQuant}	
							units.count = units.count + 1
						end	

					
					elseif (unit:len()>0) then
						
						units[units.count] = { unit = unit,count = count, class = UnitClass.Vehicle, priority = (0.0 * fcost), fcost = fcost,
							cost = cost, charge = charge, fore = fore, group = group, waitAtQuant = waitAtQuant}
						if (asRead:find("hero")) then 
							
							units[units.count].class = UnitClass.Hero

							units[units.count].priority = (0.1 *fcost)
						elseif (line:find("heavy")) then 
							
							units[units.count].class = UnitClass.HeavyTank
							
							units[units.count].priority = (20.5 *fcost)
						elseif (line:find("b[(]v7[)]")) then 
								if verbose then print(unit, " read as tank, p:",cost) end
								units[units.count].class = UnitClass.Tank
								units[units.count].priority = (2.5 *fcost)
						elseif (line:find("b[(]v5[)]")) then 
								if verbose then print(unit, " read as anti-tank, p:",cost) end
								units[units.count].class = UnitClass.ATTank
								units[units.count].priority = (3.5 * fcost)
						end
						
						units.count = units.count + 1
					end
				end
				if verbose then print(units[units.count-1].unit, " read as ",units[units.count-1].class.className, " squad of ", count, " costs ", units[units.count-1].cost, " charge/initial ", charge, waitAtQuant) end
				
			end
		end
		io.close(f) 
	end

end




function OnGameStart()
	math.randomseed(os.time()*BotApi.Instance.playerId)
	math.random() math.random() math.random()
	if verbose then print(" parsing units") end

	
	
	  local army = BotApi.Instance.army
	

	  local units = {}
	  units.count = 1
	
	 readAllUnits(sq,units,army)
	  
	local heroes = {}
	heroes.count = 1
	
	for i, unit in pairs(units) do	
	if ( type(unit) == 'table') then
		if (unit.class == UnitClass.Hero) then 
			heroes[heroes.count] = unit
			heroes.count = heroes.count + 1
		end
		
	end
	end					
	  
	  
	Context.fullList = units; 
	Context.heroes = heroes;
end

function OnGameStop()

end



local quants = 1
local nextBuy = 0
local BS_ARM = "armour"
local BS_SP = "support"
local BS_INF = "infantry"
local BS_INF_SQUAD = "infantry_squad"

local BS_WAIT = "none"
local buyingState = BS_INF
local buyCap = 0
local previousBuy = - 15
local orderTimer = 0
local heroTimer = 5000 + 5000 * math.random()

function platoonIsMechanized(platoon)
		for i,squad in ipairs(platoon.squads) do
			if BotApi.Scene:IsSquadExists(squad)  then	
				if ( not (Context.squads[squad].class == UnitClass.Infantry) )then return true end
			end
		end
		return false
end

function platoonSize(platoon)
		local count = 1
		local squads = platoon.squads
		platoon.squads = {}
		for i,squad in ipairs(squads) do
			if BotApi.Scene:IsSquadExists(squad)  then	
				table.insert(platoon.squads,squad)
				count = count + Context.squads[squad].count
			end
		end
		return count
end


function platonNeedsVehicle(platoon)
	if (platoon) then
			return ((not platoonIsMechanized(platoon)) and quants > -1)
	end
	for i,platoon in pairs(Context.platoons) do
		if ((not platoonIsMechanized(platoon)) and quants > -1 and platoonSize(platoon) > -1) then return true end
	end
	return false
end

function platonCanSupportVehicle(platoon)
	if (platoon) then
			return ((not platoonIsMechanized(platoon)) and quants > -1 and platoonSize(platoon) > -1)
	end
	return false
end
function platoonNeedsSquad()
	for i,platoon in pairs(Context.platoons) do
		if ( platoonSize(platoon) < -1 ) then return true end
	end
	return false
end

function platoonNeedsSpecialists()
	for i,platoon in pairs(Context.platoons) do
		if ( platoonSize(platoon) < 200 ) then return true end
	end
	return false
end


function platoonHasUndefendedVehicle(platoon)
    return (platoonIsMechanized(platoon) and (platoonSize(platoon) < 10))
end

function platoonIsCombatReady(platoon) 
	local size = platoonSize(platoon)
	if (platoonHasUndefendedVehicle(platoon)) then return false end
;	if (quants < 1500 and size > -1) then return true end
	if (size > -1) then return true end
end





function addSquadToPlatoon(squad)
	local addBuckets = 10
	if (quants > 1500) then addBuckets = 20 end

	if (Context.squads[squad].class == UnitClass.Infantry) then
	
	if (platoonSize(Context.platoons.alpha)< addBuckets) then 
		table.insert(Context.platoons.alpha.squads, squad)
		return Context.platoons.alpha
	end
	if (platoonSize(Context.platoons.beta)< addBuckets) then 
		table.insert(Context.platoons.beta.squads, squad)
		return Context.platoons.beta
	end
	if (platoonSize(Context.platoons.delta)< addBuckets) then 
		table.insert(Context.platoons.delta.squads, squad)
		return Context.platoons.delta
	end

	table.insert(Context.platoons.alpha.squads, squad)
	return Context.platoons.alpha
	else
	if (platonNeedsVehicle(Context.platoons.alpha)) then 
		table.insert(Context.platoons.alpha.squads, squad)
		return Context.platoons.alpha
	end
	if (platonNeedsVehicle(Context.platoons.beta)) then 
		table.insert(Context.platoons.beta.squads, squad)
		return Context.platoons.beta
	end
	if (platonNeedsVehicle(Context.platoons.delta)) then 
		table.insert(Context.platoons.delta.squads, squad)
		return Context.platoons.delta
	end

	if (platonCanSupportVehicle(Context.platoons.alpha)) then 
		table.insert(Context.platoons.alpha.squads, squad)
		return Context.platoons.alpha
	end
	if (platonCanSupportVehicle(Context.platoons.beta)) then 
		table.insert(Context.platoons.beta.squads, squad)
		return Context.platoons.beta
	end
	if (platonCanSupportVehicle(Context.platoons.delta)) then 
		table.insert(Context.platoons.delta.squads, squad)
		return Context.platoons.delta
	end
	
	table.insert(Context.platoons.alpha.squads, squad)
	for i, squad in ipairs(Context.platoons.beta.squads) do
			table.insert(Context.platoons.alpha.squads, squad)
			if (Context.platoons.alpha.flag) then 
				table.insert(Context.orderQueue, {squad = squad, op = "attack", flag = Context.platoons.alpha.flag.name}); 
			end
	end
	Context.platoons.beta.squads = {}
	for i, squad in ipairs(Context.platoons.delta.squads) do
			table.insert(Context.platoons.alpha.squads, squad)
			if (Context.platoons.alpha.flag) then 
				table.insert(Context.orderQueue, {squad = squad, op = "attack", flag = Context.platoons.alpha.flag.name}); 
			end
	end
	Context.platoons.delta.squads = {}
	
	return Context.platoons.alpha
	end
end

function shuffle(tbl)
  size = #tbl
  for i = size, 1, -1 do
    local rand = math.random(size)
    tbl[i], tbl[rand] = tbl[rand], tbl[i]
  end
  return tbl
end

function getWeight(e)
 return e.priority
end

function wshuffle(t, cb) 
local totalw = 0;
local res = {}
local tmp = {}
local remaining = 0


for i,e in pairs(t) do
	if ( type(e) == 'table' ) then
		totalw = totalw + cb(e)
		tmp[i]=e
		remaining = remaining +1
	end
end

local tmp2
local cw= 0
local pick
while(remaining > 0) do

    local ws= math.random()*totalw
    tmp2 = {}
    cw = 0
    remaining = 0
	pick = false
    for name, value in pairs(tmp) do
        cw = cw+(cb(tmp[name]))
        if ((not pick) and ws <= cw) then
            totalw = totalw - cb(tmp[name])
            table.insert(res,value)
			pick = true
        else
            tmp2[name] = value     
            remaining = remaining + 1
        end
    end
	if pick == false then
		print("failed weighted shuffle!", remaining , totalw)
	end
    tmp = tmp2
	tmp2 = nil
end

return res
end


local testMode = false

local killSpawn = false

local shortBuyCount = 0
local buyCount = 0

function OnGameQuant()
	
    quants = quants + 1
    
	
	
	if (quants < 10) then 
		if (BotApi.Commands:Income(BotApi.Instance.playerId) == 0) then testMode = true end
		return 
	end
	local scount = 0
	
	for i, squad in pairs(BotApi.Scene.Squads) do
		if (BotApi.Scene:IsSquadExists(squad)) then
			scount = scount + 1
		end
	end
	
	local enemyHasTanks = BotApi.Commands:EnemyHasTanks();

	local capturedFlags, enemyFlags = 0, 0
	for i, flag in pairs(BotApi.Scene.Flags) do
	if IsCapturedFlag(flag) then
		capturedFlags = capturedFlags + 1
	end
	if IsEnemyFlag(flag) then
		enemyFlags = enemyFlags + 1
	end
	end

	local enemyHasSuperiority  = capturedFlags < enemyFlags 
	
	local mult = -1
	if (enemyHasSuperiority) then mult = -1 end
	
	local canBuy = previousBuy + getInterval(quants) * mult < quants
	if (not platonNeedsVehicle() and shortBuyCount < -1 and quants < -1 and not enemyHasSuperiority) then
		local canBuy = previousBuy + getInterval(quants)/-1 < quants
	end
	
	canBuy = canBuy or (scount < 10 and testMode) 
	
	if ((quants % 10 ==0) and canBuy and not killSpawn) then
		if (previousBuy + getInterval(quants)/4 < quants) then 
			shortBuyCount = shortBuyCount + 1
		else 
			shortBuyCount = 0
		end
        buyCap = buyCap + 1
		local ul = wshuffle(Context.fullList, getWeight)
		

			
		
			
		local success = false
		if verbose then print("BOT",BotApi.Instance.playerId," in buy loop at ",quants) end
		for i, unit in pairs(ul) do
		        
				if ( type(unit) == 'table' and canBuyAtCurrentTime(unit, quants)) then
					if ( platonNeedsVehicle()) then
						if 
						   (
						        (enemyHasTanks and unit.class == UnitClass.ATTank )
							 or (unit.class == UnitClass.Tank  )
							 or (enemyHasTanks and unit.class == UnitClass.HeavyTank  )
							 or (unit.class == UnitClass.Vehicle )
							 )
							 
							 then 
						    if verbose then print("BOT",BotApi.Instance.playerId," spawning ", unit.unit) end
							local spawn = BotApi.Commands:Spawn(unit.unit, 5)
							if(spawn) then 
								success = true
								if verbose then print("BOT",BotApi.Instance.playerId," spawn success ", unit.unit) end
								Context.lastBuy = unit;
								Context.lastBuyCount = unit.count;
								unit.waitAtQuant = quants + unit.charge + 1
								break;
							end					
					
						end
					elseif (platoonNeedsSquad() and unit.class == UnitClass.Infantry and unit.count > 4) then
							if verbose then print("BOT",BotApi.Instance.playerId," spawning ", unit.unit) end
							local spawn = BotApi.Commands:Spawn(unit.unit, 5)
							if(spawn) then 
								if verbose then print("BOT",BotApi.Instance.playerId," spawn success ", unit.unit) end
								success = true
								Context.lastBuy = unit;
								Context.lastBuyCount = unit.count;
								unit.waitAtQuant = quants + unit.charge + 1
								break;
							end					
			
					elseif (platoonNeedsSpecialists() and unit.count < 3 and unit.class == UnitClass.Infantry) then
							if verbose then print("BOT",BotApi.Instance.playerId," spawning ", unit.unit) end
							local spawn = BotApi.Commands:Spawn(unit.unit, 5)
							if(spawn) then 
								if verbose then print("BOT",BotApi.Instance.playerId," spawn success ", unit.unit) end
								success = true
								Context.lastBuy = unit;
								Context.lastBuyCount = unit.count;
								unit.waitAtQuant = quants + unit.charge + 1
								break;
							end					
			
					end

				end
		end


		ul = nil
		collectgarbage()
		if verbose then print("BOT",BotApi.Instance.playerId," memory sweep " , collectgarbage("count")) end	
		if (not success or buyCap > 16) then
				if verbose then print("BOT",BotApi.Instance.playerId," exiting buy loop at purchased ", buyCap) end
				buyCap = math.random()*3
				previousBuy = quants
		end
		
	end

	
	

	
	if heroTimer < quants and not killSpawn then
		local capturedFlags, enemyFlags = 0, 0
		for i, flag in pairs(BotApi.Scene.Flags) do
			if IsCapturedFlag(flag) then
				capturedFlags = capturedFlags + 1
			end
			if IsEnemyFlag(flag) then
				enemyFlags = enemyFlags + 1
			end
		end
		
		local enemyHasSuperiority  = capturedFlags < enemyFlags 
		
		if (enemyHasSuperiority) then 
		   if verbose then print("BOT",BotApi.Instance.playerId," looking for heroes at ", quants) end
		else 
			if verbose then print("BOT",BotApi.Instance.playerId," all is fine in life ", quants) end
		end
		heroTimer = quants + 1500
		local ul = wshuffle(Context.heroes, getWeight)
		local spawn = false
		for i, unit in pairs(ul) do        
				if ( type(unit) == 'table') then
					
					if (  enemyHasSuperiority and canBuyAtCurrentTime(unit, quants) ) then
						if verbose then print("BOT",BotApi.Instance.playerId," spawning ", unit.unit) end
						spawn = BotApi.Commands:Spawn(unit.unit, 5)
						if (spawn) then
							if verbose then print("BOT",BotApi.Instance.playerId," spawn success ", unit.unit) end
							unit.waitAtQuant = quants + unit.charge + 1
							Context.lastBuy = unit;
							Context.lastBuyCount = unit.count;
							break;
						end
						
					end
				end
		end
		ul = nil
		
		collectgarbage()
		if verbose then print("BOT",BotApi.Instance.playerId," memory sweep " , collectgarbage("count")) end	

		if (spawn) then
			heroTimer = quants + 9000
		end
	end
	
	if orderTimer < quants then
		orderTimer = quants + OrderRotationPeriod + OrderRotationPeriod * (math.random()*0.25-0.05)
		updateFlagsStatus(true)
		updatePlatoons(true)
	else
		if (quants % 25) then 
			local o = table.remove(Context.orderQueue)
			if not (o == nil) then
				if BotApi.Scene:IsSquadExists(o.squad)  then
					if verbose then print("BOT ordering ", o.squad, o.op, " to ", o.flag) end
					BotApi.Commands:CaptureFlag(o.squad, o.flag)
				else
					if verbose then print("BOT ordering FAILED ", o.squad, o.op, " to ", o.flag) end
				end
				if (not (o.op == "reorder" )) then 
					table.insert(Context.orderQueue, {squad = o.squad, op = "reorder", flag = o.flag}); 
				end
			end
			o = nil
		end
		if ((12+quants)% 25 == 0) then 
			updateFlagsStatus(false)
			updatePlatoons()
		end
		
	end
end

FlagPriority = { Captured = 0, Enemy = 2, Neutral = 4 }








function splitPlatoon(source, destination) 
	local squads = {}
	for i,squad in ipairs(source.squads) do
		if BotApi.Scene:IsSquadExists(squad)  then	
			if (math.random()> 0.7 and Context.squads[squad].class == UnitClass.Infantry) then 
				table.insert(destination.squads, squad)
				if (destination.flag) then
					table.insert(Context.orderQueue, {squad = squad, op = "attack", flag = destination.flag.name}); 
				end
			else
				table.insert(squads, squad)
			end
		end
	end
	source.squads = squads
end


function updatePlatoonStatus(platoon, nextTargetFlag)
		local _flag = nil
		local _flagNext = nil
		if (platoon.flag) then _flag = platoon.flag.name end
		if (nextTargetFlag) then _flagNext = nextTargetFlag.name end
		
		
		if (not platoonIsCombatReady(platoon)) then 
			
			platoon.order = PLATOON_WAIT
			platoon.flag = nil
			platoon.lockUntil = 0
			local dest = nil
			if (platoonIsCombatReady(Context.platoons.alpha)) then dest = Context.platoons.alpha end
			if (platoonIsCombatReady(Context.platoons.beta)) then dest = Context.platoons.beta end
			if (platoonIsCombatReady(Context.platoons.delta)) then dest = Context.platoons.delta end

			if(dest) then
				local _destFlag = nil
				if (dest.flag) then _destFlag = dest.flag.name end
				if verbose then print("BOT",BotApi.Instance.playerId, " platoon ",platoon.name,platoonSize(platoon),_flag," ineffective, attaching to ", dest.name, _destFlag) end
				local s = platoon.squads
				platoon.squads = {}
				for i, squad in ipairs(s) do
					table.insert(dest.squads, squad)
					if (dest.flag) then
						table.insert(Context.orderQueue, {squad = squad, op = "attack", flag = dest.flag.name}); 
					end
				end
			else 
				if verbose then print("BOT",BotApi.Instance.playerId, " platoon ",platoon.name,platoonSize(platoon),_flag," ineffective, entering idle status ") end
				for i, squad in ipairs(platoon.squads) do
						table.insert(Context.orderQueue, {squad = squad, op = "stop", flag = nil}); 
				end
			end
			return
		end
		
		if (platoon.lockUntil > quants) then 
			
			local offset = 12
			if (platoon.name == "beta") then
				offset = 312
			end
			if (platoon.name == "delta") then
				offset = 612
			end

			if (_flag and ( (quants +offset) % 1000 == 0 )) then
				if verbose then print("BOT",BotApi.Instance.playerId, " platoon ",platoon.name,platoonSize(platoon),_flag," current order locked (reordering)", platoon.order) end
				for i, squad in ipairs(platoon.squads) do
						table.insert(Context.orderQueue, {squad = squad, op = "attack", flag = _flag}); 
				end
			else
				if verbose then print("BOT",BotApi.Instance.playerId, " platoon ",platoon.name,platoonSize(platoon),_flag," current order locked ", platoon.order) end
			end
			return 
		end



		if (platoon.order == PLATOON_CAPTURE_INFANTRY) then 
			if verbose then print("BOT",BotApi.Instance.playerId, " platoon ",platoon.name,platoonSize(platoon),_flag," moving tanks ") end
			platoon.order = PLATOON_CAPTURE_VEHICLES
			for i,squad in ipairs(platoon.squads) do
						table.insert(Context.orderQueue, {squad = squad, op = "attack", flag = platoon.flag.name}); 
			end
			return
		end
		if (platoon.order == PLATOON_WAIT and nextTargetFlag  ) then 
			if verbose then print("BOT",BotApi.Instance.playerId, " platoon ",platoon.name,platoonSize(platoon),_flagNext," moving infantry to ") end
				platoon.order = PLATOON_CAPTURE_INFANTRY
				platoon.flag = nextTargetFlag
				platoon.lockUntil = quants + math.random(250,500)
				for i,squad in ipairs(platoon.squads) do
					if (Context.squads[squad].class == UnitClass.Infantry) then
						table.insert(Context.orderQueue, {squad = squad, op = "attack", flag = platoon.flag.name}); 
					end
				end
				return
		end
		if ((platoon.order == PLATOON_CAPTURE_INFANTRY or platoon.order == PLATOON_CAPTURE_VEHICLES) and IsCapturedFlag(platoon.flag)) then
				if verbose then print("BOT",BotApi.Instance.playerId, " platoon ",platoon.name,platoonSize(platoon),_flag," waiting capture") end
				platoon.order = PLATOON_WAIT
				platoon.lockUntil = quants + 2500
				return
		end
		
		if (platoon.flag and nextTargetFlag and (not (platoon.flag.name == nextTargetFlag.name )) )then
			if verbose then print("BOT",BotApi.Instance.playerId, " platoon ",platoon.name,platoonSize(platoon),_flag," flag changed, wait for updates ") end
			platoon.order = PLATOON_WAIT 
			return
		end
		
		if (platoonSize(platoon) > 1500) then
			if verbose then print("BOT",BotApi.Instance.playerId, " platoon ",platoon.name,platoonSize(platoon),_flag," too large and idling, splitting") end
			local dest = Context.platoons.alpha
			if(platoon == Context.platoons.alpha) then dest = Context.platoons.beta end
			if(platoon == Context.platoons.beta) then dest = Context.platoons.delta end
			splitPlatoon(platoon,dest)
		end
		
		local offset = 12
		if (platoon.name == "beta") then
			offset = 312
		end
		if (platoon.name == "delta") then
			offset = 612
		end

		if (_flag and ( (quants +offset) % 1000 == 0 )) then
			if verbose then print("BOT",BotApi.Instance.playerId, " platoon ",platoon.name,platoonSize(platoon),_flag," nothing to do (reordering) in ",platoon.order, " with next flag ",_flagNext ) end
		for i, squad in ipairs(platoon.squads) do
					table.insert(Context.orderQueue, {squad = squad, op = "attack", flag = _flag}); 
			end
		else
			if verbose then print("BOT",BotApi.Instance.playerId, " platoon ",platoon.name,platoonSize(platoon),_flag," nothing to do in ",platoon.order, " with next flag ",_flagNext ) end
		end
		
		return 
		
end


function updatePlatoons(alsoOrders) 
	
	local primaryFlag = nil
	local secondaryFlag = nil
	local optionalFlag = nil

	for name, flag in pairs(Context.nFlags) do
		if (primaryFlag == nil) then 
			primaryFlag = flag
		elseif (secondaryFlag == nil) then
			secondaryFlag = flag
		elseif (optionalFlag == nil) then
			optionalFlag = flag
		end
	end
	for name, flag in pairs(Context.eFlags) do
		if (primaryFlag == nil) then 
			primaryFlag = flag
		elseif (secondaryFlag == nil) then
			secondaryFlag = flag
		elseif (optionalFlag == nil) then
			optionalFlag = flag
		end
	end
	for name, flag in pairs(Context.cFlags) do
		if (primaryFlag == nil) then 
			primaryFlag = flag
		elseif (secondaryFlag == nil) then
			secondaryFlag = flag
		elseif (optionalFlag == nil) then
			optionalFlag = flag
		end
	end
	
	if(not platoonIsCombatReady(Context.platoons.alpha)) then 
		secondaryFlag = primaryFlag
		optionalFlag = secondaryFlag
	end
	if(not platoonIsCombatReady(Context.platoons.beta)) then 
		optionalFlag = secondaryFlag
	end
	
	if (Context.maxFlags == 2) then
		optionalFlag = nil
		for name, flag in pairs(Context.cFlags) do
			if (optionalFlag == nil) then
				optionalFlag = flag
			end
		end
		if (optionalFlag == nil) then
			optionalFlag = secondaryFlag
		end
	end
	if (Context.maxFlags == 1) then
		optionalFlag = nil
		for name, flag in pairs(Context.cFlags) do
			if (optionalFlag == nil) then
				optionalFlag = flag
			end
		end
		if (optionalFlag == nil) then
			optionalFlag = primaryFlag
		end
		secondaryFlag = primaryFlag
	end
	
	if (secondaryFlag == nil) then secondaryFlag = primaryFlag end
	if (optionalFlag == nil) then optionalFlag = secondaryFlag end
	
	updatePlatoonStatus(Context.platoons.alpha, primaryFlag)
	updatePlatoonStatus(Context.platoons.beta, secondaryFlag)
	updatePlatoonStatus(Context.platoons.delta, optionalFlag)
end









function updateFlagsStatus(reshuffle) 

	local cFlags = {}
	local aFlags = {}
	local eFlags = {}
	local nFlags = {}
	
	local an = 0
	local cn = 0
	local en = 0
	local nn = 0

	for name, flag in pairs(BotApi.Scene.Flags) do
		aFlags[flag.name] = flag
		if (Context.platoons.alpha.flag and Context.platoons.alpha.flag.name == flag.name) then Context.platoons.alpha.flag = flag end
		if (Context.platoons.beta.flag and Context.platoons.beta.flag.name == flag.name) then Context.platoons.beta.flag = flag end
		if (Context.platoons.delta.flag and Context.platoons.delta.flag.name == flag.name) then Context.platoons.delta.flag = flag end
	end
	if (reshuffle) then
		Context.aFlags = shuffle(aFlags)
		Context.squadOffset = math.random(0,1024)
	end
	
	for name, flag in pairs(Context.aFlags) do
		an = an + 1
		Context.aFlags[name] = aFlags[flag.name]
		if (IsCapturedFlag(aFlags[name])) then 
			cFlags[name] = aFlags[name]
			cn = cn + 1
		elseif (IsEnemyFlag(aFlags[name])) then
			eFlags[name] = aFlags[name]
			en = en + 1
		else
			eFlags[name] = aFlags[name]
			nn = nn + 1
		end
	end
	
	Context.cFlags = cFlags
	Context.eFlags = eFlags
	Context.nFlags = nFlags

	if (verbose) then
        local msg = ""
		for name, flag in pairs(Context.aFlags) do
			if (IsCapturedFlag(flag)) then 
				msg = msg .. name .. "(".. flag.occupant ..") captured; "
			elseif (IsEnemyFlag(flag)) then
				msg = msg .. name ..  "(".. flag.occupant ..") enemy; "
			else
				msg = msg .. name ..  "(".. flag.occupant ..") neutral; "
			end
		end
		print("BOT",BotApi.Instance.playerId, " flag status: ", msg)
	end	
	
	Context.maxFlags = 3
	
	if (quants > 6000) then
		Context.maxFlags = 2
	end
	if (quants > 60000) then  
		Context.maxFlags = 1
	end
	
	if ((en > math.ceil(an / 2)) and (cn < 2)) then 
		Context.maxFlags = 1
	end
	if ((en < 2 and cn > math.ceil(an / 2))) then 
		Context.maxFlags = 1
	end
end


function twist(n)
  return n*2654435761 % (2^32)
end


local unitSplitCount = 0
function OnGameSpawn(args)

	
	Context.squads[args.squadId] = {unit = Context.lastBuy.unit, class = Context.lastBuy.class, cost = Context.lastBuy.fcost, count = math.min(Context.lastBuyCount,5)}
	Context.lastBuyCount = math.max(Context.lastBuyCount - 5,1)
	local platoon = addSquadToPlatoon(args.squadId)
	if (verbose) then print ("spawn known from stack: ", args.squadId, " is ", Context.lastBuy.unit, " added to ", platoon.name, " attack ", platoon.flag) end
	if (platoon.flag) then
		table.insert(Context.orderQueue, {squad = args.squadId, op = "attack", flag = platoon.flag.name}); 
	end
	
end








BotApi.Events:Subscribe(BotApi.Events.GameStart, function ()
	status, result = pcall(OnGameStart)
	if not status then
		  print(result)
	end   
end)
BotApi.Events:Subscribe(BotApi.Events.GameEnd, function ()
	status, result = pcall(OnGameStop)
	if not status then
		  print(result)
	end   
end)
BotApi.Events:Subscribe(BotApi.Events.Quant, function ()
	status, result = pcall(OnGameQuant)
	if not status then
		  print(result)
	end   
end)
BotApi.Events:Subscribe(BotApi.Events.GameSpawn, function (args)
	status, result = pcall(OnGameSpawn,args)
	if not status then
		  print(result)
	end   
end)

MaxSquadSize = 16
OrderRotationPeriod = 1500

SpecialPoints = 0

-- ai purchases will be limited between min and max
-- early and late costs are linearly interpolated from growthStarts time and growthEnds time
-- time is in game ticks,  1500 -- 30s  6000 2m -- 15000 5m -- 30000 10m -- 45000 -- 15m 90000 -- 30m 135000 -- 45m 180000 -- 60m 225000 -- 75m 270000 -- 90m 315000 -- 105m
-- hero unit costs are in sp

UnitClass = {
	Infantry = {className = "Infantry", min={early=0, late=0}, max={early=50, late=50}, dontBuyBefore = -1, growthStarts = 1, growthEnds = 2},
	Vehicle = {className = "Vehicle",min={early=0, late=0}, max={early= 200, late=800}, dontBuyBefore = 30, growthStarts = 3, growthEnds = 4},
	Tank = {className = "Tank",min={early=0, late=0}, max={early= 640, late=1280}, dontBuyBefore = 40, growthStarts = 5, growthEnds = 6},
	ATTank = {className = "ATTank",min={early=0, late=0}, max={early= 350, late=5000}, dontBuyBefore = 50, growthStarts = 7, growthEnds = 8},
	HeavyTank = {className = "HeavyTank",min={early=0, late=0}, max={early= 3200, late=6400}, dontBuyBefore = 60, growthStarts = 9, growthEnds = 10},
	Hero = {className = "Hero",min={early = 0, late = 0}, max={early = 6, late = 10}, dontBuyBefore = 70, growthStarts = 11, growthEnds = 12},
	Intervals = { growthStarts = 1, growthEnds = 2, beginInterval = 250, endInterval = 251}
}


function readAllUnits(sq,units,army)
	local base = "mods\\Armor_Balance\\resource\\set\\multiplayer\\units_bot\\"

	local army = BotApi.Instance.army
	print(" parsing units for " .. army)


	local sq = base .. "squads_bot.set"	
	readUnitsRaw(sq,units,army)
	local sq = base .. "soldiers_bot.set"
	readUnitsRaw(sq,units,army)	
	local sq = base .. "vehicles_bot.set"
	readUnitsRaw(sq,units,army)
	local sq = base .. "vehicles_bot_" .. army .. ".set"
	readUnitsRaw(sq,units,army)
	local sq = base .. "vehicles_bot_x.set"
	readUnitsRaw(sq,units,army)
	local sq = base .. "vehicles_xnotanks_bot.set"
	readUnitsRaw(sq,units,army)
	
	print("read ", units.count, " units")

end
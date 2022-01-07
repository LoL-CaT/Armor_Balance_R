(define "para_ammo"
	{extender "supply_zone"
		{resupply
;		(mod "mp"		
            {item "smoke" "grenade" 1 {max 3}}
            {item "molotov_coctail" "grenade" 1 {max 3}}
            {item "m24x5" "grenade" 1 {max 3}}	
            {item "pwm1" "grenade" 1 {max 3}}		
            {item "f1_ger" "grenade" 1 {max 3}}
            {item "m24" "grenade" 1 {max 3}}	
            {item "m61" "grenade" 1 {max 3}}
            {item "mk1" "grenade" 1 {max 3}}	
            {item "n73at" "grenade" 1 {max 3}}	
            {item "mk2" "grenade" 1 {max 3}}	
            {item "mk3" "grenade" 1 {max 3}}	
            {item "f1" "grenade" 1 {max 3}}	
            {item "rg42" "grenade" 1 {max 3}}	
            {item "rgd33" "grenade" 1 {max 3}}		
            {item "rgd33r" "grenade" 1 {max 3}}
            {item "rg42x3" "grenade" 1 {max 3}}	
            {item "rpg6" "grenade" 1 {max 3}}		
            {item "rpg40" "grenade" 1 {max 3}}		
            {item "rpg43" "grenade" 1 {max 3}}		
            {item "poland_o33_ger" "grenade" 1 {max 3}}		
            {item "poland_z33" "grenade" 1 {max 3}}	
            {item "OTO_mod35" "grenade" 1 {max 3}}	
            {item "m39" "grenade" 1 {max 3}}
            {item "m32" "grenade" 1 {max 3}}
            {item "m18" "grenade" 1 {max 3}}
            {item "nebel39" "grenade" 1 {max 3}}	
            {item "rdg" "grenade" 1 {max 3}}			
            {item "hungarian_42m" "grenade" 1 {max 3}}		
            {item "hungarian_36m" "grenade" 1 {max 3}}		
            {item "czech_m34" "grenade" 1 {max 3}}	
;        )			
			{item "rifle" "ammo" 30 {max 150}}
			{item "pistol" "ammo" 30 {max 200}}
			{item "mgun" "ammo" 100 {max 350}}   
			{item "smkmgun" "ammo" 1000 {max 1000}}
			{item "bandage"	5 {max 5}}
			{item "ptr" "ammo" 5 {max 25}}
			{item "bazooka" "ammo" 1 {max 5}}							
			{item "m18recoilless" "ammo" 10 {max 5}}
			{item "piatrocket" "ammo" 10 {max 5}}
			{item "type_4" "ammo" 10 {max 5}}
			{item "type_4_90" "ammo" 10 {max 5}}
			{item "rifle_grenade" "ammo" 20 {max 10}}
			{item "rifle_grenade_at" "ammo" 20 {max 10}}
			{item "m9" "ammo" 25 {max 10}}
			{item "No68" "ammo" 25 {max 10}}
			{item "type2_grenade" "fg" "ammo" 25 {max 10}}
			{item "type2_grenade" "ap" "ammo" 25 {max 10}}			
			{item "sprenggranate" "ammo" 25 {max 10}}
			{item "smkmgun" "ammo" 25 {max 10}}	
			{item "mosin_grenade" "ap" "ammo" 25 {max 10}}	
			{item "grb39_grenade" "ap" "ammo" 25 {max 10}}	
			{item "grb_grenade" "fg" "ammo" 25 {max 10}}	
			{item "grb_grenade" "ap" "ammo" 25 {max 10}}	
			{item "dyakonov_grenade" "ammo" 25 {max 10}}
			{item "bramit" "ammo" 25 {max 10}}			
			{item "shotgun" "ammo" 50 {max 30}}
			{item "mortar" "fg" "ammo" 500 {max 30}{value 1}}
			{item "hmgun" "ammo" 100 {max 750}{value 1}}
			{item "mortar150" "fg" "ammo" 20 {max 15}{value 1}}		
		}
		{radius 			100}		;resupply radius in meter
		{resupplyPeriod 	1}		;resupply period in seconds
		{regenerationPeriod 0}		;regeneration period in seconds, +1 supply every x seconds (0 = no regeneration)
		{limit 				1500}		;max number of resupplies (0 = unlimited)
	}
	{DecalView supply_zone
		{Sprite "supply_zone.ebm"
			{Visibility 0.3}
		}
		{Layer grounddynamic}
		{Visible 0}
	}
)

(define "truck_ammo"
	{extender "supply_zone"
		{resupply
;		(mod "mp"		
            {item "smoke" "grenade" 1 {max 3}}
            {item "molotov_coctail" "grenade" 1 {max 3}}
            {item "m24x5" "grenade" 1 {max 3}}	
            {item "pwm1" "grenade" 1 {max 3}}		
            {item "f1_ger" "grenade" 1 {max 3}}
            {item "m24" "grenade" 1 {max 3}}	
            {item "m61" "grenade" 1 {max 3}}
            {item "mk1" "grenade" 1 {max 3}}	
            {item "n73at" "grenade" 1 {max 3}}	
            {item "mk2" "grenade" 1 {max 3}}	
            {item "mk3" "grenade" 1 {max 3}}	
            {item "f1" "grenade" 1 {max 3}}	
            {item "rg42" "grenade" 1 {max 3}}	
            {item "rgd33" "grenade" 1 {max 3}}		
            {item "rgd33r" "grenade" 1 {max 3}}
            {item "rg42x3" "grenade" 1 {max 3}}	
            {item "rpg6" "grenade" 1 {max 3}}		
            {item "rpg40" "grenade" 1 {max 3}}		
            {item "rpg43" "grenade" 1 {max 3}}		
            {item "poland_o33_ger" "grenade" 1 {max 3}}		
            {item "poland_z33" "grenade" 1 {max 3}}	
            {item "OTO_mod35" "grenade" 1 {max 3}}	
            {item "m39" "grenade" 1 {max 3}}
            {item "m32" "grenade" 1 {max 3}}
            {item "m18" "grenade" 1 {max 3}}
            {item "nebel39" "grenade" 1 {max 3}}	
            {item "rdg" "grenade" 1 {max 3}}			
            {item "hungarian_42m" "grenade" 1 {max 3}}		
            {item "hungarian_36m" "grenade" 1 {max 3}}		
            {item "czech_m34" "grenade" 1 {max 3}}
;        )			
			{item "rifle" "ammo" 30 {max 150}}
			{item "pistol" "ammo" 30 {max 200}}
			{item "mgun" "ammo" 100 {max 350}}   
			{item "smkmgun" "ammo" 1000 {max 1000}}
			{item "bandage"	5 {max 5}}
			{item "ptr" "ammo" 5 {max 25}}
			{item "bazooka" "ammo" 1 {max 5}}							
			{item "m18recoilless" "ammo" 10 {max 5}}
			{item "piatrocket" "ammo" 10 {max 5}}
			{item "type_4" "ammo" 10 {max 5}}
			{item "type_4_90" "ammo" 10 {max 5}}
			{item "rifle_grenade" "ammo" 20 {max 10}}
			{item "rifle_grenade_at" "ammo" 20 {max 10}}
			{item "m9" "ammo" 25 {max 10}}
			{item "No68" "ammo" 25 {max 10}}
			{item "type2_grenade" "fg" "ammo" 25 {max 10}}
			{item "type2_grenade" "ap" "ammo" 25 {max 10}}			
			{item "sprenggranate" "ammo" 25 {max 10}}
			{item "smkmgun" "ammo" 25 {max 10}}	
			{item "mosin_grenade" "ap" "ammo" 25 {max 10}}	
			{item "grb39_grenade" "ap" "ammo" 25 {max 10}}	
			{item "grb_grenade" "fg" "ammo" 25 {max 10}}	
			{item "grb_grenade" "ap" "ammo" 25 {max 10}}	
			{item "dyakonov_grenade" "ammo" 25 {max 10}}
			{item "bramit" "ammo" 25 {max 10}}			
			{item "shotgun" "ammo" 50 {max 30}}
			{item "mortar" "fg" "ammo" 500 {max 30}{value 1}}
			{item "hmgun" "ammo" 100 {max 750}{value 1}}
			{item "mortar150" "fg" "ammo" 20 {max 15}{value 1}}	
		}
		{radius 			100}
		{resupplyPeriod 	1}
		{regenerationPeriod 2}
		{limit 				5000}
	}
	{DecalView supply_zone
		{Sprite "supply_zone.ebm"
			{Visibility 0.3}
		}
		{Layer grounddynamic}
		{Visible 0}
	}
)

(define "truck_ammo_art"
	{extender "supply_zone"
		{resupply
;		(mod "mp"		
            {item "smoke" "grenade" 1 {max 3}}
            {item "molotov_coctail" "grenade" 1 {max 3}}
            {item "m24x5" "grenade" 1 {max 3}}	
            {item "pwm1" "grenade" 1 {max 3}}		
            {item "f1_ger" "grenade" 1 {max 3}}
            {item "m24" "grenade" 1 {max 3}}	
            {item "m61" "grenade" 1 {max 3}}
            {item "mk1" "grenade" 1 {max 3}}	
            {item "n73at" "grenade" 1 {max 3}}	
            {item "mk2" "grenade" 1 {max 3}}	
            {item "mk3" "grenade" 1 {max 3}}	
            {item "f1" "grenade" 1 {max 3}}	
            {item "rg42" "grenade" 1 {max 3}}	
            {item "rgd33" "grenade" 1 {max 3}}		
            {item "rgd33r" "grenade" 1 {max 3}}
            {item "rg42x3" "grenade" 1 {max 3}}	
            {item "rpg6" "grenade" 1 {max 3}}		
            {item "rpg40" "grenade" 1 {max 3}}		
            {item "rpg43" "grenade" 1 {max 3}}		
            {item "poland_o33_ger" "grenade" 1 {max 3}}		
            {item "poland_z33" "grenade" 1 {max 3}}	
            {item "OTO_mod35" "grenade" 1 {max 3}}	
            {item "m39" "grenade" 1 {max 3}}
            {item "m32" "grenade" 1 {max 3}}
            {item "m18" "grenade" 1 {max 3}}
            {item "nebel39" "grenade" 1 {max 3}}	
            {item "rdg" "grenade" 1 {max 3}}			
            {item "hungarian_42m" "grenade" 1 {max 3}}		
            {item "hungarian_36m" "grenade" 1 {max 3}}		
            {item "czech_m34" "grenade" 1 {max 3}}
;        )			
			{item "rifle" "ammo" 30 {max 150}}
			{item "pistol" "ammo" 30 {max 200}}
			{item "mgun" "ammo" 100 {max 350}}   
			{item "smkmgun" "ammo" 1000 {max 1000}}
			{item "bandage"	5 {max 5}}
			{item "ptr" "ammo" 5 {max 25}}
			{item "bazooka" "ammo" 4 {max 5}}							
			{item "m18recoilless" "ammo" 4 {max 5}}
			{item "piatrocket" "ammo" 4 {max 5}}
			{item "type_4" "ammo" 4 {max 5}}
			{item "type_4_90" "ammo" 10 {max 5}}
			{item "rifle_grenade" "ammo" 20 {max 10}}
			{item "rifle_grenade_at" "ammo" 20 {max 10}}
			{item "m9" "ammo" 25 {max 10}}
			{item "No68" "ammo" 25 {max 10}}
			{item "type2_grenade" "fg" "ammo" 25 {max 10}}
			{item "type2_grenade" "ap" "ammo" 25 {max 10}}			
			{item "sprenggranate" "ammo" 25 {max 10}}
			{item "smkmgun" "ammo" 25 {max 10}}	
			{item "mosin_grenade" "ap" "ammo" 25 {max 10}}	
			{item "grb39_grenade" "ap" "ammo" 25 {max 10}}	
			{item "grb_grenade" "fg" "ammo" 25 {max 10}}	
			{item "grb_grenade" "ap" "ammo" 25 {max 10}}	
			{item "dyakonov_grenade" "ammo" 25 {max 10}}
			{item "bramit" "ammo" 25 {max 10}}			
			{item "shotgun" "ammo" 50 {max 30}}
			{item "mortar" "fg" "ammo" 500 {max 30}{value 1}}
			{item "hmgun" "ammo" 100 {max 750}{value 1}}
			{item "mortar150" "fg" "ammo" 20 {max 15}{value 1}}		
			;	
			{item "torpedo_mas" "ammo" 1 {max 1}{value 1}}			
			{item "torpedo" "ammo" 1 {max 1}{value 1}}				
			{item "air_bomb" "ammo" 1 {max 8}{value 1}}	
			{item "air_bomb" "small" "ammo" 1 {max 12}{value 1}}	
			{item "air_bomb_250" "ammo" 1 {max 8}{value 1}}				
			{item "air_bomb_il2" "ammo" 1 {max 8}{value 1}}			
			{item "bullet20x138b" "airplane" "ammo" 750 {max 750}{value 2}}	
			{item "bullet20_oerlikon_ger" "airplane" "ammo" 270 {max 270}{value 2}}	
			{item "bullet30mk" "airplane" "ammo" 80 {max 80}{value 2}}			
			{item "bullet37ger" "airplane" "ammo" 12 {max 12}{value 2}}		
			{item "bullet75_pak40" "airplane" "ammo" 16 {max 16}{value 2}}				
			;
			{item "bullet20" "zenite" "ammo" 10 {max 100}{value 2}}   
			{item "bullet25" "zenite" "ammo" 10 {max 100}{value 2}}
			{item "bullet37" "zenite" "ammo" 10 {max 100}{value 2}}
			{item "bullet40" "zenite" "ammo" 10 {max 100}{value 2}}
			{item "bullet40engL" "ap" "ammo" 10 {max 100}{value 2}}			
			{item "bullet37" "ap" "ammo" 3 {max 30}{value 2}}
			{item "bullet37" "fg" "ammo" 3 {max 25}{value 2}}
			{item "bullet40" "ap" "ammo" 3 {max 30}{value 2}}
			{item "bullet40" "fg" "ammo" 3 {max 25}{value 2}}
			{item "bullet45" "ap" "ammo" 3 {max 30}{value 2}}
			{item "bullet45" "fg" "ammo" 3 {max 25}{value 2}}
			{item "bullet47" "ap" "ammo" 3 {max 30}{value 2}}
			{item "bullet47" "fg" "ammo" 3 {max 25}{value 2}}
			{item "bullet50" "ap" "ammo" 3 {max 30}{value 2}}
			{item "bullet50" "fg" "ammo" 3 {max 25}{value 2}}
			{item "bullet57" "ap" "ammo" 3 {max 30}{value 2}}
			{item "bullet57" "fg" "ammo" 3 {max 25}{value 2}}
			{item "bullet75" "ap" "ammo" 2 {max 20}{value 2}}
			{item "bullet75" "fg" "ammo" 2 {max 15}{value 2}}
			{item "bullet76" "ap" "ammo" 2 {max 20}{value 2}}
			{item "bullet76" "fg" "ammo" 2 {max 15}{value 2}}
			{item "bullet77" "ap" "ammo" 2 {max 20}{value 2}}
			{item "bullet77" "fg" "ammo" 2 {max 15}{value 2}}
			{item "bullet85" "ap" "ammo" 2 {max 20}{value 2}}
			{item "bullet85" "fg" "ammo" 2 {max 15}{value 2}}
			{item "bullet88" "ap" "ammo" 2 {max 20}{value 2}}
			{item "bullet88" "fg" "ammo" 2 {max 15}{value 2}}
			{item "bullet89" "ap" "ammo" 2 {max 20}{value 2}}
			{item "bullet89" "fg" "ammo" 2 {max 15}{value 2}}
			{item "bullet90" "ap" "ammo" 2 {max 20}{value 2}}
			{item "bullet90" "fg" "ammo" 2 {max 15}{value 2}}
			{item "bullet93" "ap" "ammo" 2 {max 20}{value 2}}
			{item "bullet93" "fg" "ammo" 2 {max 15}{value 2}}
			{item "bullet95" "ap" "ammo" 2 {max 20}{value 2}}
			{item "bullet95" "fg" "ammo" 2 {max 15}{value 2}}
			{item "bullet100" "ap" "ammo" 2 {max 20}{value 2}}
			{item "bullet100" "fg" "ammo" 2 {max 15}{value 2}}
			{item "bullet105" "ap" "ammo" 2 {max 20}{value 2}}
			{item "bullet120" "ap" "ammo" 2 {max 20}{value 2}}
			{item "bullet122" "ap" "ammo" 2 {max 20}{value 2}}
			{item "bullet128" "ap" "ammo" 2 {max 15}{value 2}}
			;
			{item "bullet105" "fg" "ammo" 1 {max 10}{value 5}}
			{item "bullet120" "fg" "ammo" 1 {max 10}{value 5}}
			{item "bullet122" "fg" "ammo" 1 {max 10}{value 5}}
			{item "bullet128" "fg" "ammo" 1 {max 10}{value 5}}
			{item "bullet150" "fg" "ammo" 1 {max 10}{value 5}}
			{item "bullet152" "fg" "ammo" 1 {max 10}{value 5}}
			{item "bullet155" "fg" "ammo" 1 {max 10}{value 5}}
			;
			{item "bullet203" "ammo" 1 {max 5}{value 5}}
			{item "bullet290" "ammo" 1 {max 5}{value 5}}
			;
			{item "calliope" "ammo" 5 {max 60}{value 5}}
			{item "calliope180" "ammo" 5 {max 60}{value 5}}			
			{item "lm_ammo" "ammo" 5 {max 32}{value 5}}
			{item "bm8" "ammo" 5 {max 24}{value 5}}
			{item "katusha" "ammo" 3 {max 16}{value 5}}
			{item "panzerwerfer42" "ammo" 2 {max 10}{value 5}}
			{item "nebel41" "ammo" 2 {max 12}{value 5}}
			{item "nebel42" "ammo" 2 {max 12}{value 5}}
			{item "20cm_rocket" "ammo" 2 {max 10}{value 5}}
			{item "tulip" "ammo" 2 {max 10}{value 5}}
			;
			{item "30cm_rocket" "ammo" 1 {max 5}{value 10}}
			{item "sturmtiger" "ammo" 1 {max 5}{value 10}}
		}
		{radius 			100}
		{resupplyPeriod 	1}
		{regenerationPeriod 2}
		{limit 				5000}
	}
	{DecalView supply_zone
		{Sprite "supply_zone.ebm"
			{Visibility 0.3}
		}
		{Layer grounddynamic}
		{Visible 0}
	}
)

(define "truck_ammo_art_ger"
	{extender "supply_zone"
		{resupply
;		(mod "mp"
            {item "smoke" "grenade" 1 {max 3}}
            {item "molotov_coctail" "grenade" 1 {max 3}}		
            {item "m24x5" "grenade" 1 {max 3}}	
            {item "pwm1" "grenade" 1 {max 3}}		
            {item "f1_ger" "grenade" 1 {max 3}}
            {item "m24" "grenade" 1 {max 3}}	
            {item "poland_o33_ger" "grenade" 1 {max 3}}		
            {item "poland_z33" "grenade" 1 {max 3}}	
            {item "OTO_mod35" "grenade" 1 {max 3}}	
            {item "m39" "grenade" 1 {max 3}}
            {item "m32" "grenade" 1 {max 3}}			
            {item "hungarian_42m" "grenade" 1 {max 3}}		
            {item "hungarian_36m" "grenade" 1 {max 3}}		
            {item "czech_m34" "grenade" 1 {max 3}}			
            {item "nebel39" "grenade" 1 {max 3}}
;        )			
			{item "rifle" "ammo" 30 {max 150}}
			{item "pistol" "ammo" 30 {max 200}}
			{item "mgun" "ammo" 100 {max 350}}   
			{item "smkmgun" "ammo" 1000 {max 1000}}
			{item "bandage"	5 {max 5}}
			{item "ptr" "ammo" 5 {max 25}}
			{item "bazooka" "ammo" 4 {max 5}}							
			{item "m18recoilless" "ammo" 4 {max 5}}
			{item "piatrocket" "ammo" 4 {max 5}}
			{item "type_4" "ammo" 4 {max 5}}
			{item "type_4_90" "ammo" 10 {max 5}}
			{item "rifle_grenade" "ammo" 20 {max 10}}
			{item "rifle_grenade_at" "ammo" 20 {max 10}}
			{item "m9" "ammo" 25 {max 10}}
			{item "No68" "ammo" 25 {max 10}}
			{item "type2_grenade" "fg" "ammo" 25 {max 10}}
			{item "type2_grenade" "ap" "ammo" 25 {max 10}}			
			{item "sprenggranate" "ammo" 25 {max 10}}
			{item "smkmgun" "ammo" 25 {max 10}}	
			{item "mosin_grenade" "ap" "ammo" 25 {max 10}}	
			{item "grb39_grenade" "ap" "ammo" 25 {max 10}}	
			{item "grb_grenade" "fg" "ammo" 25 {max 10}}	
			{item "grb_grenade" "ap" "ammo" 25 {max 10}}	
			{item "dyakonov_grenade" "ammo" 25 {max 10}} 
			{item "bramit" "ammo" 25 {max 10}}			
			{item "shotgun" "ammo" 50 {max 30}}
			{item "panzershreck" "ammo" 4 {max 6}}			
			{item "hmgun" "ammo" 100 {max 750}{value 1}} 
			;	
			{item "torpedo_mas" "ammo" 1 {max 1}{value 1}}			
			{item "torpedo" "ammo" 1 {max 1}{value 1}}				
			{item "air_bomb" "ammo" 1 {max 8}{value 1}}	
			{item "air_bomb" "small" "ammo" 1 {max 12}{value 1}}	
			{item "air_bomb_250" "ammo" 1 {max 8}{value 1}}				
			{item "air_bomb_il2" "ammo" 1 {max 8}{value 1}}			
			{item "bullet20x138b" "airplane" "ammo" 750 {max 750}{value 2}}	
			{item "bullet20_oerlikon_ger" "airplane" "ammo" 270 {max 270}{value 2}}	
			{item "bullet30mk" "airplane" "ammo" 80 {max 80}{value 2}}			
			{item "bullet37ger" "airplane" "ammo" 12 {max 12}{value 2}}		
			{item "bullet75_pak40" "airplane" "ammo" 16 {max 16}{value 2}}				
			;
			{item "bullet20x105b" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet20x105b" "fg" "ammo" 100 {max 400}{value 2}}
			{item "bullet20x105b" "zenite" "ammo" 100 {max 400}{value 2}}			
			{item "bullet20x105b_hun" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet20x105b_hun" "fg" "ammo" 100 {max 400}{value 2}}	
			{item "bullet20x105b_hun" "zenite" "ammo" 100 {max 400}{value 2}}			
			{item "bullet20x138b" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet20x138b" "fg" "ammo" 100 {max 400}{value 2}}
			{item "bullet20x138b" "zenite" "ammo" 100 {max 400}{value 2}}			
			{item "bullet20x138b_ita" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet20x138b_ita" "fg" "ammo" 100 {max 400}{value 2}}
			{item "bullet20x138b_ita" "zenite" "ammo" 100 {max 400}{value 2}}	
			{item "bullet20x138b_pol" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet20x138b_pol" "fg" "ammo" 100 {max 400}{value 2}}
			{item "bullet20x138b_pol" "zenite" "ammo" 100 {max 400}{value 2}}						
			{item "bullet25_hotchkiss" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet25_hotchkissK" "ap" "ammo" 100 {max 400}{value 2}}			
			{item "bullet25" "zenite" "ammo" 100 {max 400}{value 2}}
			{item "bullet28" "ap" "ammo" 20 {max 100}{value 2}}
			{item "bullet30mk" "ap" "ammo" 100 {max 850}{value 2}}
			{item "bullet30mk" "fg" "ammo" 100 {max 850}{value 2}}
			{item "bullet30mk" "zenite" "ammo" 100 {max 850}{value 2}}			
			{item "bullet37_mle38" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet37_mle38" "fg" "ammo" 100 {max 400}{value 2}}			
			{item "bullet37_hotchkiss" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet37_hotchkiss" "fg" "ammo" 100 {max 400}{value 2}}
			{item "bullet37_bofors" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet37_bofors" "fg" "ammo" 100 {max 400}{value 2}}			
			{item "bullet37_czech" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet37_czech" "fg" "ammo" 10 {max 100}{value 2}}
			{item "bullet37_pak35" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet37_pak35" "fg" "ammo" 10 {max 100}{value 2}}
			{item "bullet37_pak35" "heat" "ammo" 10 {max 100}{value 2}}			
			{item "bullet37_flak36" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet37_flak36" "he" "ammo" 100 {max 400}{value 2}}
			{item "bullet37_flak36" "fg" "ammo" 100 {max 400}{value 2}}			
			{item "bullet37_flak36" "zenite" "ammo" 100 {max 400}{value 2}}	
			{item "bullet40ita_pom" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet40ita_pom" "fg" "ammo" 10 {max 100}{value 2}}	
			{item "bullet40ita_pom" "zenite" "ammo" 10 {max 100}{value 2}}				
			{item "bullet40_bofors" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet40_bofors" "fg" "ammo" 100 {max 400}{value 2}} 
			{item "bullet40_bofors" "zenite" "ammo" 100 {max 400}{value 2}}			
			{item "bullet40_bofors_ger" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet40_bofors_ger" "fg" "ammo" 100 {max 400}{value 2}}
			{item "bullet40_bofors_ger" "zenite" "ammo" 100 {max 400}{value 2}}			
			{item "bullet40_bofors_hun" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet40_bofors_hun" "fg" "ammo" 100 {max 400}{value 2}}	
			{item "bullet40_bofors_hun" "zenite" "ammo" 100 {max 400}{value 2}}			
			{item "bullet42ger" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet42ger" "fg" "ammo" 10 {max 100}{value 2}}
			{item "bullet47_czech" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet47_czech" "fg" "ammo" 10 {max 100}{value 2}}
			{item "bullet47gerI" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet47gerI" "fg" "ammo" 10 {max 100}{value 2}}				
			{item "bullet47ger" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet47ger" "fg" "ammo" 10 {max 100}{value 2}}	
			{item "bullet47gerAT" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet47gerAT" "fg" "ammo" 10 {max 100}{value 2}}			
			{item "bullet50ger" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet50ger" "fg" "ammo" 10 {max 100}{value 2}}
			{item "bullet55ger" "ap" "ammo" 50 {max 400}{value 2}}
			{item "bullet55ger" "fg" "ammo" 50 {max 400}{value 2}}
			{item "bullet55ger" "zenite" "ammo" 50 {max 400}{value 2}}			
			{item "bullet50_pak38" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet50_pak38" "fg" "ammo" 10 {max 100}{value 2}}
			{item "bullet75_leig18" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet75_09" "fg" "ammo" 5 {max 100}{value 2}}			
			{item "bullet75gerat" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet75gerat" "fg" "ammo" 5 {max 100}{value 2}}					
			{item "bullet75_lg40" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet75_lg40" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet75ger" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet75ger" "fg" "ammo" 5 {max 100}{value 2}}	
			{item "bullet75gerF" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet75gerF" "fg" "ammo" 5 {max 100}{value 2}}			
			{item "bullet75gerIT" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet75gerIT" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet75gerIT" "heat" "ammo" 5 {max 100}{value 2}}			
			{item "bullet75gerHU" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet75gerHU" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet75gerHU" "heat" "ammo" 5 {max 100}{value 2}}			
			{item "bullet75gerHUI" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet75gerHUI" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet75gerHUI8" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet75gerHUI8" "fg" "ammo" 5 {max 100}{value 2}}			
			{item "bullet75_pak40" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet75_pak40" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet75_pak41" "ap" "ammo" 5 {max 100}{value 2}}
;			{item "bullet75_pak41" "fg" "ammo" 5 {max 100}{value 2}}						
			{item "bullet75gerl" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet75gerl" "fg" "ammo" 5 {max 100}{value 2}}			
			{item "bullet75gers" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet75gers" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet75gers" "Aheat" "ammo" 5 {max 100}{value 2}}
			{item "bullet75gers" "Bheat" "ammo" 5 {max 100}{value 2}}
			{item "bullet75gers" "Cheat" "ammo" 5 {max 100}{value 2}}			
			{item "bullet75_pak97_38" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet75_pak97_38" "fg" "ammo" 5 {max 100}{value 2}}			
			{item "bullet76ger" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet76ger" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet76_pak36" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet76_pak36" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet88_flak18" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet88_flak18" "fg" "ammo" 5 {max 100}{value 2}}			
			{item "bullet88ger" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet88ger" "ap2" "ammo" 5 {max 100}{value 2}}
			{item "bullet88gerl" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet88gerl" "fg" "ammo" 5 {max 100}{value 2}}  
			{item "bullet88ger" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet105gerro" "heat" "ammo" 1 {max 100}{value 2}}			
			{item "bullet105gerro" "fg" "ammo" 1 {max 100}{value 2}}			
			{item "bullet105_l13" "fg" "ammo" 1 {max 100}{value 2}}			
			{item "bullet105ger" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet105ger" "heat" "ammo" 1 {max 100}{value 2}}			
			{item "bullet105ger" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet105gerK" "fg" "ammo" 1 {max 100}{value 2}}			
			{item "bullet105_lefn18" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet105_lefn18" "heat" "ammo" 1 {max 100}{value 2}}			
			{item "bullet105_lefn18" "fg" "ammo" 1 {max 100}{value 2}}	
			{item "bullet105gerE" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet105gerE" "fg" "ammo" 1 {max 100}{value 2}}			
			{item "bullet105gerl" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet105gerl" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet105gerr" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet105gerr" "fg" "ammo" 1 {max 100}{value 2}}				
			{item "bullet122_m1910_30" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet128ger" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet128ger" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet150" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet150_sig33" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet150ger" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet150ger" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet155ger" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet155ger" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet150ger" "heat" "ammo" 1 {max 100}{value 2}}
			{item "bullet155gerGPF" "fg" "ammo" 1 {max 100}{value 2}}			
			{item "bullet152_m1909_30" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet152_m1909_30" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet150gerLate" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet150gerLate" "ap" "ammo" 1 {max 100}{value 2}}			
			{item "bullet174ger" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet174ger" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet210ger" "fg" "ammo" 1 {max 100}{value 2}}
			{item "mortar" "fg" "ammo" 100 {max 100}{value 1}}			
			{item "mortar45" "fg" "ammo" 100 {max 100}{value 2}}  			
			{item "mortar50_wgr36" "fg" "ammo" 100 {max 100}{value 2}}
			{item "mortar81_wgr34" "fg" "ammo" 100 {max 100}{value 2}}
			{item "mortar105ger" "fg" "ammo" 100 {max 100}{value 2}}			
			{item "mortar120_wgr42" "fg" "ammo" 100 {max 100}{value 2}}
			{item "panzerwerfer42" "ammo" 1 {max 100}{value 2}}
			{item "nebel" "ammo" 1 {max 100}{value 2}}			
			{item "nebel41" "ammo" 1 {max 100}{value 2}}
			{item "nebel42" "ammo" 1 {max 100}{value 2}}
			{item "nebel42_28_30" "ammo" 1 {max 100}{value 2}}
			{item "nebel42_30" "ammo" 1 {max 100}{value 2}}			
			{item "sturmtiger" "ammo" 1 {max 100}{value 2}}
			{item "bullet305" "ammo" 1 {max 100}{value 2}}
			{item "bullet120" "ammo" 1 {max 100}{value 2}}				
		}
		{radius 			100}
		{resupplyPeriod 	1}
		{regenerationPeriod 2}
		{limit 				5000}
	}
	{DecalView supply_zone
		{Sprite "supply_zone.ebm"
			{Visibility 0.3}
		}
		{Layer grounddynamic}
		{Visible 0}
	}
)

(define "truck_ammo_art_eng"
	{extender "supply_zone"
		{resupply
;		(mod "mp"		
            {item "smoke" "grenade" 1 {max 3}}
            {item "molotov_coctail" "grenade" 1 {max 3}}
            {item "m61" "grenade" 1 {max 3}}
            {item "mk1" "grenade" 1 {max 3}}	
            {item "n73at" "grenade" 1 {max 3}}
            {item "m18" "grenade" 1 {max 3}}
;        )			
			{item "rifle" "ammo" 30 {max 150}}
			{item "pistol" "ammo" 30 {max 200}}
			{item "mgun" "ammo" 100 {max 350}}   
			{item "smkmgun" "ammo" 1000 {max 1000}}
			{item "bandage"	5 {max 5}}
			{item "ptr" "ammo" 5 {max 25}}
			{item "bazooka" "ammo" 4 {max 5}}							
			{item "m18recoilless" "ammo" 4 {max 5}}
			{item "piatrocket" "ammo" 4 {max 5}}
			{item "type_4" "ammo" 4 {max 5}}
			{item "type_4_90" "ammo" 10 {max 5}}
			{item "tulip" "ammo" 2 {max 4}}			
			{item "rifle_grenade" "ammo" 20 {max 10}}
			{item "rifle_grenade_at" "ammo" 20 {max 10}}
			{item "m9" "ammo" 25 {max 10}}
			{item "No68" "ammo" 25 {max 10}}
			{item "type2_grenade" "fg" "ammo" 25 {max 10}}
			{item "type2_grenade" "ap" "ammo" 25 {max 10}}			
			{item "sprenggranate" "ammo" 25 {max 10}}
			{item "smkmgun" "ammo" 25 {max 10}}	
			{item "mosin_grenade" "ap" "ammo" 25 {max 10}}	
			{item "grb39_grenade" "ap" "ammo" 25 {max 10}}	
			{item "grb_grenade" "fg" "ammo" 25 {max 10}}	
			{item "grb_grenade" "ap" "ammo" 25 {max 10}}	
			{item "dyakonov_grenade" "ammo" 25 {max 10}}
			{item "bramit" "ammo" 25 {max 10}}			
			{item "shotgun" "ammo" 50 {max 30}}
			{item "hmgun" "ammo" 100 {max 750}{value 1}} 
			;			
			{item "torpedo_mas" "ammo" 1 {max 1}{value 1}}			
			{item "torpedo" "ammo" 1 {max 1}{value 1}}			
			{item "air_bomb" "ammo" 1 {max 8}{value 1}}	
			{item "air_bomb" "small" "ammo" 1 {max 12}{value 1}}	
			{item "air_bomb_250" "ammo" 1 {max 8}{value 1}}				
			{item "air_bomb_il2" "ammo" 1 {max 8}{value 1}}
			{item "arl" "ammo" 8 {max 8}{value 1}}
			{item "T64" "ammo" 6 {max 6}{value 1}}
			{item "bullet20x110hispano" "airplane" "ammo" 240 {max 240}{value 2}}			
			;
			{item "bullet20_oerlikon" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet20_oerlikon" "fg" "ammo" 100 {max 400}{value 2}}	
			{item "bullet20_oerlikon" "zenite" "ammo" 100 {max 400}{value 2}}
			{item "bullet20x138b" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet20x138b" "fg" "ammo" 100 {max 400}{value 2}}	
			{item "bullet20x138b" "zenite" "ammo" 100 {max 400}{value 2}}			
			{item "bullet20x138b_eng" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet20x138b_eng" "fg" "ammo" 100 {max 400}{value 2}}		
			{item "bullet20x138b_eng" "zenite" "ammo" 100 {max 400}{value 2}}			
			{item "bullet25_hotchkiss" "ap" "ammo" 20 {max 400}{value 2}}
			{item "bullet25_hotchkissEN" "ap" "ammo" 100 {max 400}{value 2}}			
			{item "bullet37eng" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet37eng" "fg" "ammo" 10 {max 100}{value 2}}
			{item "bullet37_m3" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet37_m3" "fg" "ammo" 10 {max 100}{value 2}}
			{item "bullet37_m3l" "ap" "ammo" 10 {max 200}{value 2}}
			{item "bullet37_m3l" "fg" "ammo" 20 {max 200}{value 2}}		
			{item "bullet37_bofors" "ap" "ammo" 10 {max 200}{value 2}}
			{item "bullet37_bofors" "fg" "ammo" 20 {max 200}{value 2}}	
			{item "bullet37_bofors" "zenite" "ammo" 20 {max 200}{value 2}}				
			{item "bullet40engL" "ap" "ammo" 10 {max 100}{value 2}}				
			{item "bullet40_bofors" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet40_bofors" "fg" "ammo" 100 {max 400}{value 2}}	
			{item "bullet40_bofors" "zenite" "ammo" 100 {max 400}{value 2}}			
			{item "bullet40ita_pom" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet40ita_pom" "fg" "ammo" 10 {max 100}{value 2}}	
			{item "bullet40ita_pom" "zenite" "ammo" 10 {max 100}{value 2}}				
			{item "bullet40eng" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet40eng" "fg" "ammo" 10 {max 100}{value 2}}
			{item "bullet47eng" "ap" "ammo" 10 {max 100}{value 2}}
;			{item "bullet47eng" "fg" "ammo" 10 {max 100}{value 2}}	
			{item "bullet57eng" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet57eng2" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet57eng3" "ap" "ammo" 10 {max 100}{value 2}}			
			{item "bullet57eng4" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet57eng" "fg" "ammo" 10 {max 100}{value 2}}
			{item "bullet75eng" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet75eng" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet75engz" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet75engz" "fg" "ammo" 5 {max 100}{value 2}}			
			{item "bullet75engcs" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet75usa" "ap" "ammo" 5 {max 100}{value 2}}        
			{item "bullet75usa" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet76usa" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet76usa" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet76eng" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet76eng" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet76engBP" "apcr" "ammo" 5 {max 100}{value 2}}
			{item "bullet76engBP" "fg" "ammo" 5 {max 100}{value 2}}			
			{item "bullet76engl" "fg" "ammo" 5 {max 100}{value 2}}			
			{item "bullet77eng" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet77eng" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet77engHV" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet77engHV" "fg" "ammo" 5 {max 100}{value 2}}			
			{item "bullet83eng" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet83eng" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet84eng" "fg" "ammo" 5 {max 100}{value 2}}			
			{item "bullet89eng" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet89eng" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet93eng" "ap" "ammo" 5 {max 100}{value 2}}
            {item "bullet93eng" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet95eng" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet95eng" "heat" "ammo" 5 {max 100}{value 2}}
			{item "bullet105eng" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet105usa" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet105usaS" "heat" "ammo" 1 {max 100}{value 2}}	
			{item "bullet105usaS" "fg" "ammo" 1 {max 100}{value 2}}			
			{item "bullet114eng" "fg" "ammo" 2 {max 100}{value 2}}				
			{item "bullet120eng" "ap" "ammo" 2 {max 100}{value 2}}
			{item "bullet120eng" "fg" "ammo" 2 {max 100}{value 2}}	
			{item "bullet140eng" "fg" "ammo" 1 {max 100}{value 2}}			
			{item "bullet152eng" "fg" "ammo" 1 {max 100}{value 2}}
		    {item "bullet155eng" "fg" "ammo" 1 {max 100}{value 2}}			
		    {item "bullet183eng" "ap" "ammo" 1 {max 100}{value 2}}
		    {item "bullet183eng" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet203usa" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet240usa" "fg" "ammo" 1 {max 100}{value 2}}				
		    {item "bullet290" "ammo" 1 {max 100}{value 2}}
			{item "mortar" "fg" "ammo" 100 {max 100}{value 1}}			
			{item "mortar50_2inchhe" "fg" 100 {max 100}{value 2}}
			{item "mortar76" "fg" "ammo" 100 {max 100}{value 2}}
			{item "mortar107eng" "fg" "ammo" 100 {max 100}{value 2}}
			{item "lm_ammo" "ammo" 2 {max 100}{value 2}}
			{item "bullet305" "ammo" 1 {max 100}{value 2}}
			{item "bullet120" "ammo" 1 {max 100}{value 2}}				
		}
		{radius 			100}
		{resupplyPeriod 	1}
		{regenerationPeriod 2}
		{limit 				5000}
	}
	{DecalView supply_zone
		{Sprite "supply_zone.ebm"
			{Visibility 0.3}
		}
		{Layer grounddynamic}
		{Visible 0}
	}
)

(define "truck_ammo_art_us"
	{extender "supply_zone"
		{resupply
;		(mod "mp"		
            {item "smoke" "grenade" 1 {max 3}}
            {item "molotov_coctail" "grenade" 1 {max 3}}	
            {item "n73at" "grenade" 1 {max 3}}	
            {item "mk2" "grenade" 1 {max 3}}	
            {item "mk3" "grenade" 1 {max 3}}
            {item "m18" "grenade" 1 {max 3}}
;        )			
			{item "rifle" "ammo" 30 {max 150}}
			{item "pistol" "ammo" 30 {max 200}}
			{item "mgun" "ammo" 100 {max 350}}  
			{item "smkmgun" "ammo" 1000 {max 1000}}
			{item "bandage"	5 {max 5}}
			{item "ptr" "ammo" 5 {max 25}}
			{item "bazooka" "ammo" 4 {max 5}}							
			{item "m18recoilless" "ammo" 4 {max 5}}
			{item "piatrocket" "ammo" 4 {max 5}}
			{item "type_4" "ammo" 4 {max 5}}
			{item "type_4_90" "ammo" 10 {max 5}}
			{item "rifle_grenade" "ammo" 20 {max 10}}
			{item "rifle_grenade_at" "ammo" 20 {max 10}}
			{item "m9" "ammo" 25 {max 10}}
			{item "No68" "ammo" 25 {max 10}}
			{item "type2_grenade" "fg" "ammo" 25 {max 10}}
			{item "type2_grenade" "ap" "ammo" 25 {max 10}}			
			{item "sprenggranate" "ammo" 25 {max 10}}
			{item "smkmgun" "ammo" 25 {max 10}}	
			{item "mosin_grenade" "ap" "ammo" 25 {max 10}}	
			{item "grb39_grenade" "ap" "ammo" 25 {max 10}}	
			{item "grb_grenade" "fg" "ammo" 25 {max 10}}	
			{item "grb_grenade" "ap" "ammo" 25 {max 10}}	
			{item "dyakonov_grenade" "ammo" 25 {max 10}}
			{item "bramit" "ammo" 25 {max 10}}			
			{item "shotgun" "ammo" 50 {max 30}}
			{item "hmgun" "ammo" 100 {max 750}{value 1}}
			;
			{item "torpedo_mas" "ammo" 1 {max 1}{value 1}}			
			{item "torpedo" "ammo" 1 {max 1}{value 1}}			
			{item "air_bomb" "ammo" 1 {max 8}{value 1}}	
			{item "air_bomb" "small" "ammo" 1 {max 12}{value 1}}	
			{item "air_bomb_250" "ammo" 1 {max 8}{value 1}}				
			{item "air_bomb_il2" "ammo" 1 {max 8}{value 1}}
			{item "arl" "ammo" 8 {max 8}{value 1}}
			{item "T64" "ammo" 6 {max 6}{value 1}}
			{item "bullet20x110hispano" "airplane" "ammo" 240 {max 240}{value 2}}	
			{item "bullet37_usaflack" "airplane" "ammo" 30 {max 30}{value 2}}	
			{item "bullet75usa" "airplane" "ammo" 21 {max 21}{value 2}}			
			;			
			{item "bullet20usa" "zenite" "ammo" 100 {max 400}{value 2}}
			{item "bullet20x138b" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet20x138b" "fg" "ammo" 100 {max 400}{value 2}}
			{item "bullet20x138b" "zenite" "ammo" 100 {max 400}{value 2}}			
			{item "bullet20x110hispano" "ap" "ammo" 400 {max 100}{value 2}}
			{item "bullet20x110hispano" "fg" "ammo" 400 {max 100}{value 2}}
            {item "bullet20x110hispano" "zenite" "ammo" 400 {max 100}{value 2}}
			{item "bullet37_m3" "ap" "ammo" 10 {max 200}{value 2}}
			{item "bullet37_m3" "fg" "ammo" 20 {max 200}{value 2}}
			{item "bullet37_m3l" "ap" "ammo" 10 {max 200}{value 2}}
			{item "bullet37_m3l" "fg" "ammo" 20 {max 200}{value 2}}			
			{item "bullet37_usaflack" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet37_usaflack" "fg" "ammo" 100 {max 400}{value 2}}
			{item "bullet37_usaflack" "zenite" "ammo" 100 {max 400}{value 2}}			
			{item "bullet40_bofors" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet40_bofors" "fg" "ammo" 100 {max 400}{value 2}}
			{item "bullet40_bofors" "zenite" "ammo" 100 {max 400}{value 2}}	
			{item "bullet40ita_pom" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet40ita_pom" "fg" "ammo" 10 {max 100}{value 2}}	
			{item "bullet40ita_pom" "zenite" "ammo" 10 {max 100}{value 2}}				
			{item "bullet57usa" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet57usa" "fg" "ammo" 10 {max 100}{value 2}}
			{item "bullet75usa" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet75usa" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet75usaP" "fg" "ammo" 5 {max 100}{value 2}}			
			{item "bullet76usa" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet76usa" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet76usa_hvap" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet76usa_hvap" "ap" "ammo" 5 {max 100}{value 2}}			
			{item "bullet76usaL" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet76usaL" "ap" "ammo" 5 {max 100}{value 2}}			
			{item "bullet90usa" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet90usa" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet90usa" "apcrLATE" "ammo" 5 {max 100}{value 2}}
			{item "bullet90usa" "apLATE" "ammo" 5 {max 100}{value 2}}
			{item "bullet90usa44" "ap" "ammo" 5 {max 100}{value 2}}	
			{item "bullet90usa44" "fg" "ammo" 5 {max 100}{value 2}}			
			{item "bullet90usa46" "ap" "ammo" 5 {max 100}{value 2}}	
			{item "bullet90usa46" "fg" "ammo" 5 {max 100}{value 2}}			
			{item "bullet90usaLON" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet90usaLON" "ap" "ammo" 5 {max 100}{value 2}}			
			{item "bullet105usaS" "heat" "ammo" 1 {max 100}{value 2}}	
			{item "bullet105usaS" "fg" "ammo" 1 {max 100}{value 2}}			
			{item "bullet105usa" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet105usa" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet120usaOLD" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet120usaOLD" "ap" "ammo" 1 {max 100}{value 2}}			
			{item "bullet120usa" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet120usa" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet155usa" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet155usaOLD" "fg" "ammo" 1 {max 100}{value 2}}	
			{item "bullet155usaLT" "fg" "ammo" 1 {max 100}{value 2}}	
			{item "bullet155usaLT" "ap" "ammo" 1 {max 100}{value 2}}			
;			{item "bullet155usa" "heat" "ammo" 1 {max 100}{value 2}}
			{item "bullet203usa" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet240usa" "fg" "ammo" 1 {max 100}{value 2}}			
			{item "mortar" "fg" "ammo" 100 {max 100}{value 1}}
			{item "mortar60" "fg" "ammo" 100 {max 100}{value 2}}
			{item "mortar81usa" "fg" "ammo" 100 {max 100}{value 2}}			
			{item "mortar107usa" "fg" "ammo" 100 {max 100}{value 2}}
			{item "calliope" "ammo" 1 {max 100}{value 2}}
			{item "calliope180" "ammo" 1 {max 100}{value 2}}			
			{item "bullet305" "ammo" 1 {max 100}{value 2}}
			{item "bullet120" "ammo" 1 {max 100}{value 2}}				
		}
		{radius 			100}
		{resupplyPeriod 	1}
		{regenerationPeriod 2}
		{limit 				5000}
	}
	{DecalView supply_zone
		{Sprite "supply_zone.ebm"
			{Visibility 0.3}
		}
		{Layer grounddynamic}
		{Visible 0}
	}
)

(define "truck_ammo_art_sssr"  
	{extender "supply_zone"
		{resupply
;		(mod "mp"		
            {item "smoke" "grenade" 1 {max 3}}
            {item "molotov_coctail" "grenade" 1 {max 3}}		
            {item "f1" "grenade" 1 {max 3}}	
            {item "rg42" "grenade" 1 {max 3}}	
            {item "rgd33" "grenade" 1 {max 3}}		
            {item "rgd33r" "grenade" 1 {max 3}}
            {item "rg42x3" "grenade" 1 {max 3}}	
            {item "rpg6" "grenade" 1 {max 3}}		
            {item "rpg40" "grenade" 1 {max 3}}		
            {item "rpg43" "grenade" 1 {max 3}}
            {item "rdg" "grenade" 1 {max 3}}			
;        ) 			
			{item "rifle" "ammo" 30 {max 150}}
			{item "pistol" "ammo" 30 {max 200}}
			{item "mgun" "ammo" 100 {max 350}} 			
			{item "smkmgun" "ammo" 1000 {max 1000}} 
			{item "bandage"	5 {max 5}}
			{item "ptr" "ammo" 5 {max 25}}
			{item "bazooka" "ammo" 4 {max 5}}	
			{item "bazooka_r" "ammo" 4 {max 5}}			
			{item "pg1" "ammo" 4 {max 5}}			
			{item "m18recoilless" "ammo" 4 {max 5}}
			{item "piatrocket" "ammo" 4 {max 5}}
			{item "type_4" "ammo" 4 {max 5}}
			{item "type_4_90" "ammo" 10 {max 5}}
			{item "rifle_grenade" "ammo" 20 {max 10}}
			{item "rifle_grenade_at" "ammo" 20 {max 10}}
			{item "m9" "ammo" 25 {max 10}}
			{item "No68" "ammo" 25 {max 10}}
			{item "type2_grenade" "fg" "ammo" 25 {max 10}}
			{item "type2_grenade" "ap" "ammo" 25 {max 10}}			
			{item "sprenggranate" "ammo" 25 {max 10}}
			{item "smkmgun" "ammo" 25 {max 10}}	
			{item "mosin_grenade" "ap" "ammo" 25 {max 10}}	
			{item "grb39_grenade" "ap" "ammo" 25 {max 10}}	
			{item "grb_grenade" "fg" "ammo" 25 {max 10}}	
			{item "grb_grenade" "ap" "ammo" 25 {max 10}}	
			{item "bramit" "ammo" 25 {max 10}}			
			{item "shotgun" "ammo" 50 {max 30}}
			{item "hmgun" "ammo" 100 {max 750}{value 1}}
			;
			{item "torpedo_mas" "ammo" 1 {max 1}{value 1}}			
			{item "torpedo" "ammo" 1 {max 1}{value 1}}			
			{item "air_bomb" "ammo" 1 {max 8}{value 1}}	
			{item "air_bomb" "small" "ammo" 1 {max 12}{value 1}}	
			{item "air_bomb_250" "ammo" 1 {max 8}{value 1}}				
			{item "air_bomb_il2" "ammo" 1 {max 8}{value 1}}
			{item "arl" "ammo" 8 {max 8}{value 1}}	
			{item "bullet23" "airplane" "ammo" 300 {max 300}{value 2}}
			{item "bullet20_schvak" "airplane" "ammo" 400 {max 400}{value 2}}
			{item "bullet45_53k" "airplane" "ammo" 29 {max 29}{value 2}}			
			;
			{item "bullet20_schvak" "ap" "ammo" 100 {max 250}{value 2}}
			{item "bullet20_schvak" "fg" "ammo" 100 {max 400}{value 2}}
			{item "bullet20_schvak" "zenite" "ammo" 100 {max 400}{value 2}}					
			{item "bullet25x218sr" "ap" "ammo" 100 {max 250}{value 2}}
			{item "bullet25x218sr" "fg" "ammo" 100 {max 400}{value 2}}	
			{item "bullet25x218sr" "zenite" "ammo" 100 {max 400}{value 2}}				
			{item "bullet37_hotchkiss" "ap" "ammo" 10 {max 400}{value 2}}
			{item "bullet37_hotchkiss" "fg" "ammo" 10 {max 400}{value 2}}       
			{item "bullet37_hotchkissR" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet37_hotchkissR" "fg" "ammo" 100 {max 400}{value 2}}	
			{item "bullet37_pak35_R" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet37_pak35_R" "he" "ammo" 100 {max 400}{value 2}}			
			{item "bullet37_bofors" "ap" "ammo" 10 {max 400}{value 2}}
            {item "bullet37_bofors" "fg" "ammo" 10 {max 400}{value 2}}
			{item "bullet37_61k" "ap" "ammo" 100 {max 400}{value 2}}
            {item "bullet37_61k" "fg" "ammo" 100 {max 400}{value 2}}
            {item "bullet37_61k" "zenite" "ammo" 100 {max 400}{value 2}}			
			{item "bullet37_m3" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet37_m3" "fg" "ammo" 10 {max 100}{value 2}}
			{item "bullet37_m3l" "ap" "ammo" 10 {max 200}{value 2}}
			{item "bullet37_m3l" "fg" "ammo" 20 {max 200}{value 2}}			
			{item "bullet45rus" "ap" "ammo" 10 {max 100}{value 2}}
            {item "bullet45rus" "fg" "ammo" 10 {max 100}{value 2}}
            {item "bullet45rusz" "zenite" "ammo" 10 {max 100}{value 2}}			
			{item "bullet45_53k" "ap" "ammo" 10 {max 100}{value 2}}
            {item "bullet45_53k" "fg" "ammo" 10 {max 100}{value 2}}			
			{item "bullet57rus" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet57rus" "fg" "ammo" 10 {max 100}{value 2}}
			{item "bullet57eng" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet57eng" "fg" "ammo" 10 {max 100}{value 2}}
			{item "bullet75usa" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet75usa" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet75_09" "fg" "ammo" 5 {max 100}{value 2}}			
			{item "bullet76_obr09" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet76_ob25" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet76_obr27" "fg" "ammo" 5 {max 100}{value 2}}			
			{item "bullet76_zen" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet76_zen" "fg" "ammo" 5 {max 100}{value 2}}			
			{item "bullet76rus" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet76rus" "fg" "ammo" 5 {max 100}{value 2}}			
			{item "bullet76usa" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet76usa" "fg" "ammo" 5 {max 100}{value 2}}			
			{item "bullet85rus" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet85rus" "fg" "ammo" 5 {max 100}{value 2}}				
			{item "bullet100rus" "ap" "ammo" 3 {max 100}{value 2}}
			{item "bullet100rus" "fg" "ammo" 3 {max 100}{value 2}}
			{item "bullet100russ" "ap" "ammo" 3 {max 100}{value 2}}
			{item "bullet100russ" "fg" "ammo" 3 {max 100}{value 2}}
			{item "bullet100russ" "apcr" "ammo" 3 {max 100}{value 2}}			
			{item "bullet100_bs3" "ap" "ammo" 3 {max 100}{value 2}}
			{item "bullet100_bs3" "fg" "ammo" 3 {max 100}{value 2}}				
			{item "bullet107" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet107" "fg" "ammo" 1 {max 100}{value 2}}	
			{item "bullet107a" "fg" "ammo" 1 {max 100}{value 2}}				
			{item "bullet122rus" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet122rus" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet122rus_late" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet122rus_late" "apcr" "ammo" 1 {max 100}{value 2}}			
			{item "bullet122rus_late" "fg" "ammo" 1 {max 100}{value 2}}			
			{item "bullet122rus2" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet122rus2" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet122_a19" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet122_a19" "fg" "ammo" 1 {max 100}{value 2}}				
			{item "bullet130rus" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet130rus" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet122_m1910" "fg" "ammo" 1 {max 100}{value 2}}			
			{item "bullet122_m1910_30" "fg" "ammo" 1 {max 100}{value 2}}
;			{item "bullet122_m1910_30" "heat" "ammo" 1 {max 100}{value 2}}			
			{item "bullet122_m30" "fg" "ammo" 1 {max 100}{value 2}}	
;		    {item "bullet122_m30" "heat" "ammo" 1 {max 100}{value 2}}		
			{item "bullet152_m1909_30" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet152_m1909_30" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet152rus" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet152rus" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet152_ml20" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet152_ml20" "fg" "ammo" 1 {max 100}{value 2}}		
			{item "bullet152_ml20" "heat" "ammo" 1 {max 100}{value 2}}
			{item "bullet152_d1" "fg" "ammo" 1 {max 100}{value 2}}				
			{item "bullet152rus51" "ap" "ammo" 1 {max 100}{value 2}}    
			{item "bullet152rus51" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet203" "ammo" 1 {max 100}{value 2}}
			{item "bullet280rus" "ammo" 1 {max 100}{value 2}}			
			{item "dyakonov_grenade" 100 {max 100}{value 2}}
			{item "mortar" "fg" "ammo" 100 {max 100}{value 1}}			
			{item "mortar50_o822" "ammo" "fg" 100 {max 100}{value 2}}  
			{item "mortar81_o832" "fg" "ammo" 100 {max 100}{value 2}}					
			{item "mortar120_of843" "ammo" "fg" 100 {max 100}{value 2}}
			{item "mortar160" "ammo" "fg" 10 {max 10}{value 2}}			
			{item "bm8" "ammo" 1 {max 100}{value 2}}
			{item "katusha" "ammo" 1 {max 100}{value 2}}
			{item "m31" "ammo" 1 {max 100}{value 2}}
			{item "bullet305" "ammo" 1 {max 100}{value 2}}				
		}
		{radius 			100}
		{resupplyPeriod 	1}
		{regenerationPeriod 2}
		{limit 				5000}
	}
	{DecalView supply_zone
		{Sprite "supply_zone.ebm"
			{Visibility 0.3}
		}
		{Layer grounddynamic}
		{Visible 0}
	}
)

(define "truck_ammo_art_jp"  
	{extender "supply_zone"
		{resupply
;		(mod "mp"		
            {item "smoke" "grenade" 1 {max 3}} 
            {item "molotov_coctail" "grenade" 1 {max 3}}	
            {item "jap_type98" "grenade" 1 {max 3}}	
            {item "type97" "grenade" 1 {max 3}}		
            {item "type99" "grenade" 1 {max 3}}	
            {item "type3at" "grenade" 1 {max 3}}	
            {item "type3at_a" "grenade" 1 {max 3}}
;        )			
			{item "rifle" "ammo" 30 {max 150}}
			{item "pistol" "ammo" 30 {max 200}}
			{item "mgun" "ammo" 100 {max 350}}   
			{item "smkmgun" "ammo" 1000 {max 1000}}
			{item "bandage"	5 {max 5}}
			{item "ptr" "ammo" 5 {max 25}}
			{item "bazooka" "ammo" 4 {max 5}}							
			{item "m18recoilless" "ammo" 4 {max 5}}
			{item "piatrocket" "ammo" 4 {max 5}}
			{item "type_4" "ammo" 4 {max 5}}
			{item "type_4_90" "ammo" 10 {max 5}}
			{item "rifle_grenade" "ammo" 20 {max 10}}
			{item "rifle_grenade_at" "ammo" 20 {max 10}}
			{item "m9" "ammo" 25 {max 10}}
			{item "No68" "ammo" 25 {max 10}}
			{item "type2_grenade" "fg" "ammo" 25 {max 10}}
			{item "type2_grenade" "ap" "ammo" 25 {max 10}}			
			{item "sprenggranate" "ammo" 25 {max 10}}
			{item "smkmgun" "ammo" 25 {max 10}}	
			{item "mosin_grenade" "ap" "ammo" 25 {max 10}}	
			{item "grb39_grenade" "ap" "ammo" 25 {max 10}}	
			{item "grb_grenade" "fg" "ammo" 25 {max 10}}	
			{item "grb_grenade" "ap" "ammo" 25 {max 10}}	
			{item "dyakonov_grenade" "ammo" 25 {max 10}}
			{item "bramit" "ammo" 25 {max 10}}			
			{item "shotgun" "ammo" 50 {max 30}}
			{item "hmgun" "ammo" 100 {max 750}{value 1}}
			;			
			{item "torpedo_mas" "ammo" 1 {max 1}{value 1}}			
			{item "torpedo" "ammo" 1 {max 1}{value 1}}			
			{item "air_bomb" "ammo" 1 {max 8}{value 1}}	
			{item "air_bomb" "small" "ammo" 1 {max 12}{value 1}}	
			{item "air_bomb_250" "ammo" 1 {max 8}{value 1}}				
			{item "air_bomb_il2" "ammo" 1 {max 8}{value 1}}
			{item "arl" "ammo" 8 {max 8}{value 1}}
			{item "T64" "ammo" 6 {max 6}{value 1}}	
			{item "bullet20_oerlikon" "airplane" "ammo" 250 {max 250}{value 2}}	
			{item "bullet20x110hispano" "airplane" "ammo" 100 {max 100}{value 2}}
			{item "bullet20x125" "airplane" "ammo" 50 {max 50}{value 2}}
			{item "bullet20x138b" "airplane" "ammo" 500 {max 500}{value 2}}			
			{item "bullet37_type12" "airplane" "ammo" 15 {max 15}{value 2}}				
			;
			{item "bullet20x105b_hun" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet20x105b_hun" "fg" "ammo" 100 {max 400}{value 2}}	
			{item "bullet20x105b_hun" "zenite" "ammo" 100 {max 400}{value 2}}			
			{item "bullet20x125" "ap" "ammo" 100 {max 400}{value 2}}   
			{item "bullet20x125" "fg" "ammo" 100 {max 400}{value 2}}
			{item "bullet20x125" "zenite" "ammo" 100 {max 400}{value 2}}
			{item "bullet20x138b_ita" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet20x138b_ita" "fg" "ammo" 100 {max 400}{value 2}}
			{item "bullet20x138b_ita" "zenite" "ammo" 100 {max 400}{value 2}}				
			{item "bullet25_type96" "ap" "ammo" 10 {max 400}{value 2}}
			{item "bullet25_type96" "fg" "ammo" 10 {max 400}{value 2}}
			{item "bullet25_type96" "zenite" "ammo" 10 {max 400}{value 2}}			
			{item "bullet37_type12" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet37_type12" "fg" "ammo" 10 {max 100}{value 2}}
			{item "bullet37" "ap" "ammo" 10 {max 100}{value 2}}   
			{item "bullet37" "fg" "ammo" 10 {max 100}{value 2}}
			{item "bullet37_type94at" "ap" "ammo" 10 {max 100}{value 2}}   
			{item "bullet37_type94at" "fg" "ammo" 10 {max 100}{value 2}}
			{item "bullet37_type94tank" "ap" "ammo" 10 {max 100}{value 2}}   
			{item "bullet37_type94tank" "fg" "ammo" 10 {max 100}{value 2}}			
			{item "bullet20" "zenite" "ammo" 100 {max 400}{value 2}}
			{item "bullet40_bofors" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet40_bofors" "fg" "ammo" 100 {max 400}{value 2}} 
			{item "bullet40_bofors" "zenite" "ammo" 100 {max 400}{value 2}} 			
			{item "bullet40_bofors_jap" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet40_bofors_jap" "fg" "ammo" 100 {max 400}{value 2}}	
			{item "bullet40_bofors_jap" "zenite" "ammo" 100 {max 400}{value 2}}		
			{item "bullet40_bofors_hun" "ap" "ammo" 100 {max 400}{value 2}}
			{item "bullet40_bofors_hun" "fg" "ammo" 100 {max 400}{value 2}}	
			{item "bullet40_bofors_hun" "zenite" "ammo" 100 {max 400}{value 2}}				
			{item "bullet47" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet47" "fg" "ammo" 10 {max 100}{value 2}}
			{item "bullet47gerI" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet47gerI" "fg" "ammo" 10 {max 100}{value 2}}
			{item "bullet37gerI" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet37gerI" "fg" "ammo" 10 {max 100}{value 2}}			
;			{item "bullet57" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet57" "fg" "ammo" 10 {max 100}{value 2}}
			{item "bullet57" "heat" "ammo" 10 {max 100}{value 2}}
			{item "bullet57j" "ap" "ammo" 10 {max 100}{value 2}}
			{item "bullet57j" "fg" "ammo" 10 {max 100}{value 2}}
			{item "bullet57j" "heat" "ammo" 10 {max 100}{value 2}}	
;			{item "bullet65ita" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet65ita" "fg" "ammo" 5 {max 100}{value 2}}			
;			{item "bullet70jap" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet70jap" "fg" "ammo" 5 {max 100}{value 2}}	
			{item "bullet70jap" "heat" "ammo" 5 {max 100}{value 2}}	
			{item "bullet75itaS" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet75hunS" "fg" "ammo" 5 {max 100}{value 2}}				
;			{item "bullet75japl" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet75japl" "fg" "ammo" 5 {max 100}{value 2}}	
			{item "bullet75japl" "heat" "ammo" 5 {max 100}{value 2}}	
			{item "bullet75gerIT" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet75gerIT" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet75gerIT" "heat" "ammo" 5 {max 100}{value 2}}
			{item "bullet75gerITaa" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet75gerITaa" "fg" "ammo" 5 {max 100}{value 2}}				
			{item "bullet75gerHU" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet75gerHU" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet75gerHU" "heat" "ammo" 5 {max 100}{value 2}}
			{item "bullet75gerHUI" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet75gerHUI" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet75gerHUI8" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet75gerHUI8" "fg" "ammo" 5 {max 100}{value 2}}			
			{item "bullet75" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet75" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet75" "heat" "ammo" 5 {max 100}{value 2}}
			{item "bullet75_pak40" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet75_pak40" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet75_pak40ri" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet75_pak40ri" "fg" "ammo" 5 {max 100}{value 2}}		
			{item "bullet76_pak36" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet76_pak36" "fg" "ammo" 5 {max 100}{value 2}}			
			{item "bullet88" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet88" "fg" "ammo" 5 {max 100}{value 2}}
			{item "bullet88gerl" "ap" "ammo" 5 {max 100}{value 2}}
			{item "bullet88gerl" "fg" "ammo" 5 {max 100}{value 2}}			
			{item "bullet90usa" "apcrLATE" "ammo" 5 {max 100}{value 2}}	
			{item "bullet90usa" "fg" "ammo" 5 {max 100}{value 2}}	
			{item "bullet90ita" "ap" "ammo" 5 {max 100}{value 2}}	
			{item "bullet90ita" "fg" "ammo" 5 {max 100}{value 2}}			
			{item "bullet100" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet100" "fg" "ammo" 1 {max 100}{value 2}}	
;			{item "bullet100ita" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet100ita" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet100hunS" "fg" "ammo" 5 {max 100}{value 2}}			
			{item "bullet105" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet105" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet105j" "ap" "ammo" 1 {max 100}{value 2}}			
			{item "bullet105j" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet105ita" "ap" "ammo" 1 {max 100}{value 2}}			
			{item "bullet105ita" "fg" "ammo" 1 {max 100}{value 2}}	
			{item "bullet105ita" "heat" "ammo" 1 {max 100}{value 2}}			
			{item "bullet105_l13" "fg" "ammo" 1 {max 100}{value 2}}	
			{item "bullet105gerro" "heat" "ammo" 1 {max 100}{value 2}}			
			{item "bullet105gerro" "fg" "ammo" 1 {max 100}{value 2}}			
			{item "bullet120j" "ap" "ammo" 1 {max 100}{value 2}}			
			{item "bullet120j" "fg" "ammo" 1 {max 100}{value 2}}			
			{item "bullet120js" "fg" "ammo" 1 {max 100}{value 2}}			
			{item "bullet127" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet127" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet130j" "ap" "ammo" 1 {max 100}{value 2}}			
			{item "bullet130j" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet140" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet140" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet149ita" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet150hunS" "fg" "ammo" 5 {max 100}{value 2}}			
			{item "bullet150" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet150" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet155j" "fg" "ammo" 1 {max 100}{value 2}}
			{item "bullet155j" "ap" "ammo" 1 {max 100}{value 2}}
			{item "bullet210ita" "ammo" 1 {max 100}{value 2}}			
			{item "bullet240jap" "ammo" 1 {max 100}{value 2}}			
			{item "mortar" "fg" "ammo" 100 {max 100}{value 1}}	
			{item "mortar45" "fg" "ammo" 100 {max 100}{value 2}} 			
			{item "5cm_grenade_type89" "ammo" 100 {max 100}{value 2}}
			{item "mortar81jap" "fg" "ammo" 100 {max 100}{value 2}}			
			{item "mortar120_type2" "fg" "ammo" 100 {max 100}{value 2}}
			{item "mortar150" "ammo" "fg" 10 {max 10}{value 2}}				
			{item "20cm_rocket" "ammo" 1 {max 100}{value 2}}
			{item "30cm_rocket" "ammo" 1 {max 100}{value 2}}
			{item "bullet305" "ammo" 1 {max 100}{value 2}}
			{item "bullet120" "ammo" 1 {max 100}{value 2}}				
		}
		{radius 			100}
		{resupplyPeriod 	1}
		{regenerationPeriod 2}
		{limit 				5000}
	}
	{DecalView supply_zone
		{Sprite "supply_zone.ebm"
			{Visibility 0.3}
		}
		{Layer grounddynamic}
		{Visible 0}
	}
)
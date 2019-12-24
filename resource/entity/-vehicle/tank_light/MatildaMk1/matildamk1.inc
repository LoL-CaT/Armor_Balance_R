(include "/properties/tank.ext")

(include "/properties/h_tank_mobility.ext")	
(include "/properties/selection/vehicle.inc" scale(1.2))
	
{collider "tank.heavy"}
	
{props "l_heavy" "turret_rotator" "vision_vehicle_maximum" "muzzle_zenite" "tank"}

		
("armor_heavy_shit" turret(60 60 60 12) body(60 60 60 12))	
("armor_engine"  t(12 12 12 12))
("wheels_armor" args 5)
("armor_mantlet" t(60))	

	{volume "body"
		{tags "body"}
		{component "body"}
		{thickness 60}
	}
	{volume "body1"
		{tags "body"}
		{component "body"}
		{thickness 60}
	}
	{volume "engine"
		{thickness 12}
	}


("crew_2_human")
	
{sensor
		
	{visor "main"
			
	{vision "tank_main-h"}
			
	{bone "visor1"}
		
	}
	
}
	

{boarder
		
	{anm "left"
			
		{forward	{begin	"board_LowTank_left"}}
			
		{reverse 	{end	"emit_tank_1_hold"}}
		
	}
		
	{anm "right"
			
		{forward	{begin	"board_LowTank_left"}}
			
		{reverse 	{end	"emit_tank_1"}}
		
	}
	
}

	

{extender "inventory"
		
	{box
			
		{item "ammo hmgun" 4000}		
	}
	
}
	

{Weaponry
    ("restore_ik_time")		
	{place "mgun"
        {type "mgun_main"}	
		{RestoreIKAfterAim}		
		{weapon "vickers050" filled}
;		{foresight "foresight3"}		
		{charger "gunner"}			
		("abm_mgun_heavy")		
	}
		
	{place "mgun17"			
			{type "smoke"}
		{weapon "1xsmokegun" filled}
		{gunner "gunner"}
		{foresight "foresight4"}
		{basic}
	}
	{place "mgun18"
			{type "smoke"}
		{weapon "1xsmokegun" filled}
		{gunner "gunner"}
		{foresight "foresight5"}
		{basic}
	}
}

{mass 11200}
	
{Chassis
		
	("tank_trace" fx("tracks_sm2") step(0.15) len(0.80))
		
		("mobility"
			speed(18)
			weight(11.2)
			power(70)
			fuel(190)	
		)
	}	

{Extension "matildamk1.mdl"}

	

{bone "gun_rot"
		
	{limits -20 10}
	
}
	

{bone "turret"
		
	{speed2 12}
	
}
	



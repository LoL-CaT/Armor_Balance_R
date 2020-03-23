	(include "/properties/armoredcar.ext")
	(include "/properties/car_mobility.ext")	
	(include "/properties/selection/vehicle.inc"  scale(1.0))
	{props "vehicle" "armored_car" "tank" "turret" "wheeled" "vision_vehicle_minimum"}
	{targetClass "armoredcar" "ap fg bullet"}
	{targetSelector "tank"}
	{PatherId "vehicle.small"}

	(include "/properties/tank_crew.ext")

	{extender "enumerator"}
	
	{volume "body1"
		{tags "body"}
		{component "body"}
		{thickness 8
		{front 8}
		{top 7}
		{bottom 7}
		} 
	}
	{volume "body2"
		{tags "body"}
		{component "body"}
		{thickness 8}
	}
	{volume "body3"
		{tags "body"}
		{component "body"}
		{thickness 8
		{front 8}
		{top 7}
		{bottom 7}
		} 
	}
	{volume "body4"
		{tags "body"}
		{component "body"}
		{thickness 8
		{front 8}
		{top 7}
		{bottom 7}
		} 
	}
	{volume "body5"
		{tags "body"}
		{component "body"}
		{thickness 8
		{front 8}
		{top 7}
		{bottom 7}
		} 
	}
	{volume "body6"
		{tags "body"}
		{component "body"}
		{thickness 8
		{front 8}
		{top 7}
		{bottom 7}
		} 
	}
	{volume "body7"
		{tags "body"}
		{component "body"}
		{thickness 8
		{front 8}
		{top 7}
		{bottom 7}
		} 
	}
	{volume "turret1"
		{tags "turret"}
		{component "turret"}
		{thickness 8
		{front 8}
		{top 7}
		{bottom 7}
		} 
	}
	{volume "turret2"
		{tags "turret"}
		{component "turret"}
		{thickness 8
		{front 8}
		{top 7}
		{bottom 7}
		} 
	}
	{volume "turret3"
		{tags "turret"}
		{component "turret"}
		{thickness 8
		{front 8}
		{top 7}
		{bottom 7}
		} 
	}
	{volume "turret4"
		{tags "turret"}
		{component "turret"}
		{thickness 8
		{front 8}
		{top 7}
		{bottom 7}
		} 
	}
	{volume "turret5"
		{tags "turret"}
		{component "turret"}
		{thickness 8
		{front 8}
		{top 7}
		{bottom 7}
		} 
	}
	{volume "turret6"
		{tags "turret"}
		{component "turret"}
		{thickness 8
		{front 8}
		{top 7}
		{bottom 7}
		} 
	}
	{volume "roofshield"
		{tags "roofshield"}
		{component "roofshield"}
		{thickness 8}
	}
	{volume "engine"
		{tags "engine"}
		{component "engine"}
		{Thickness 7
			{front 7}
		}
	}
	
	

	("armor_light" args 1.2)
	
	{sensor
		{visor "main1" {bone "visor1"} {vision "moto_crew"}}
	} 	
	
	{component "turret"
		{RepairTime 20}
	}

	{boarder
		{anm "driver"
			{forward	{begin	"board_daimler_gunner"} {end "seat_driver_car"} {base "doorright"}}
			{reverse 	{end	"board_daimler_gunner" -1} {base "doorright" -1}}
		}
		{anm "gunner"
			;{forward	{begin	"board_daimler_gunner"} {end "seat_m7_mgunner"} {base "doorleft"}}
			{forward	{begin	"board_daimler_gunner"} {end "seat_sd223_gunner"} {base "doorleft"}}
			{reverse 	{end	"board_daimler_gunner" -1} {base "doorleft" -1}}
		}
		{anm "charger"
			{forward	{begin	"board_daimler_gunner"} {end "seat_driver_car"} {base "doorright"}}
			{reverse 	{end	"board_daimler_gunner" -1} {base "doorright" -1}}
		}
		{anm "commander"
			{forward	{begin	"board_daimler_gunner"} {end "seat_driver_car"} {base "doorleft"}}
			{reverse 	{end	"board_daimler_gunner" -1} {base "doorleft" -1}}
		}
		
	}

	(define "crew_human"
	{placer
		{place "%place" {group "%group"} {visor "%visor"}}
		{place "gunner"	{LinkBone "gunner"}	{Group "crew"}	{turnoff {sensor} {shadow}} {visor "main"}}	
	}
	{boarder
		{door "%door"}
		{link "%door" "%place" {anm "%animation"} {forward putoff} {reverse puton}}
	}
)
	
	("crew_human" place(driver)		door(emit2)	group(crew)	animation(driver)	visor(driver))
	("crew_human" place(charger)		door(emit2)	group(crew)	animation(charger)	visor(driver))
	("crew_human" place(commander)	door(emit1)	group(crew)	animation(commander)	visor(driver))
	("crew_human" place(gunner) 		door(emit1)	group(crew)	animation(gunner)	visor(main))
	{placer {place "gunner" {openForCrush 0}}}
			
			

	{extender "inventory"
		{box
			{item "ammo mgun" 5800}
			{item "ammo ptr" 400}
;			{item "ammo smoke" 40}			
		}
	}
	
	{Weaponry
		{place "mgun"
			{type "main_gun"}
			{weapon "boyes" filled}
			{foresight "foresight3"}
			{LinkBone "boyes"}
			{LinkAnimation "off"}
			{gunner "gunner"}
			{charger "gunner"}
            ("abm_mgun")
		}
		{place "mgun1"
			{weapon "brenstan" filled}
			{foresight "foresight4"}
			{type "mgun_aa"}
			{gunner "gunner"}
			{charger "gunner"}
			{LinkBone "mgun1"}
			{LinkAnimation "off"}
            ("abm_mgun")
			{basic}
		}
		{place "mgun17"			
			{type "smoke"}
			{weapon "1xsmokegun" filled}
			{gunner "gunner"}
			{foresight "foresight20"}
			{basic}
		}
	}

	("wheel" args "wheelright1")
	("wheel" args "wheelleft1")
	("wheel" args "wheelright2")
	("wheel" args "wheelleft2")

	{Chassis
		("car_trace" fx("tracewheel02") step(0.09) wheell("wlf") wheelr("wrf") bonel("FXtraceL1") boner("FXtraceR1"))
		("car_trace" fx("tracewheel02") step(0.09) wheell("wlr") wheelr("wrr") bonel("FXtraceL2") boner("FXtraceR2"))
		("mobility"
			speed(73)
			weight(4.5)
			power(96)
			fuel(113)	
		)
	}

	{mass 4500}

	{Extension "morriscs9.mdl"}
	{bone "turret"
		{speed 0.010}
	}


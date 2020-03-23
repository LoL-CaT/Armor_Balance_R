(include "/properties/cannon.ext")
{props "vehicle" "cannon" "cannon_small" "truck_mortar" "round_sandbag3" "vision_cannon_minimum"}
{collider "cannon_small"}
{targetSelector "cannon_rocket"}
{patherId "cannon.carried"}

("armor_mortar")

{volume "body"
	{tags "body"}
	{component "body"}
	{thickness 15}
}
{Volume "gun"
	{thickness 15}
	{able {Contact 1}}
}

("wheel" args "wheelright")
("wheel" args "wheelleft")

("crew_gun")

{boarder
	{anm "gunner"
		{forward	{end "pose_pak40_gunlayer" 10}}
	}
	{anm "commander"
		{forward	{end "pose_pak40_charger" 10}}
	}
	{anm "driver1"
		{forward {end "mortar_driver_r" 10}}
	}
	{anm "driver2"
		{forward {end "mortar_driver_l" 10}}
	}
}

{extender "inventory"
	{box
		{item "ammo mortar fg" 12}
	    {item "sandbag_kit2" 25}
        {item "repair_kit" 1}
;       {item "plant" 5}		
	}
}

{extender "cannon"
	{animation
		{switch "close"}
		{move "mortar_driver_r" "mortar_driver_l"}
		{aim "" ""}
		{fire  "Squat_load_mortar_end" ""}
		{reload  "" ""}
	}
	{move {obstacle "close"}}
	{attack {obstacle "open"}}
}

{Chassis "human_carrier"
	{carrierPlace "driver1" "driver2"}
	{carrierBone  "handle1" "handle2"}
	("loco_carrier")
}

{Weaponry
	{place "gun"
		{Barrels 1}
		{weapon "weapon werfer42" filling "ammo mortar fg" 1}
		{Rotate}
	}
}
{mass 150}
{Extension "sgrw42.mdl"}
{bone "turret"
	{limits -20 20}
	{speed 0.004}
}
{sensor
	{visor "main"
		{vision "cannon_main"}
	}
}
(include "/properties/selection/cannon.inc"  scale(0.7))

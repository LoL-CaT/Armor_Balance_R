;SDL
(include "/properties/moto.ext")
(include "/properties/l_car_mobility.ext")	
(include "/properties/selection/vehicle.inc"  scale(0.7))
{props "explosion_throw_crew" "turn_over" "vision_vehicle_minimum"}
{patherId "moto"}		
;	("armor_light" args 1)

{sensor
	{Visor "main"
		{vision "vehicle_main"}
		{bone "visor1"}
	}
	{Visor "crew"
		{vision "moto_crew"}
		{bone "visor2"}
	}
    {visor "view-around"
        {vision "moto_around"}
        {bone "basis"}
    }
}

{Placer
	{place "driver" {Group "driver"} {LinkBone "driver"} {visor "main"} {turnoff {sensor}{shadow}}}
	{place "gunner" {Group "driver"} {LinkBone "gunner"}	{visor "crew"} {turnoff {sensor}{shadow}}}
	{place "passenger" {Group "driver"} {LinkBone "passenger"} {turnoff {sensor}{shadow}}}
}
{boarder
	{door "emit1"}
	{door "emit2"}
	{door "emit3"}

	{anm "driver" {forward  {end "seat_driver_moto"}}}
	{anm "gunner" {forward  {end "seat_gunner_moto"}}}
	{anm "passenger" {forward  {end "seat_passenger"}}}

	{link "emit1" "driver"    {anm "driver"} {forward putoff} {reverse puton}}
	{link "emit2" "passenger" {anm "passenger"} {forward putoff} {reverse puton}}
	{link "emit3" "gunner"	  {anm "gunner"} {forward putoff} {reverse puton}}
}

("wheel" args "wheel1")
("wheel" args "wheel2")
("wheel" args "wheel3")

{extender "inventory"
	{weapon "mgun"
		{mask "weapon mgun"}
	}
	{Box
		{item  "ammo mgun" 500 }
	}
}

	{mass 1000}
	
	{Chassis
		("mobility"
			speed(110)
			weight(1.0)
			power(18)
			fuel(14)	
		)
	}

{Weaponry
	{place "mgun"
		{type "mgun_main"}
		{LinkBone "mgun"}
		{LinkAnimation "off"}
		{charger "gunner"}
		("abm_mgun")
	}
}  	
{Extension "bmw-r12.mdl"}
{bone "gun_rot"
	{limits -20 20}
}
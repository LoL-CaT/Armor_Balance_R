	(include "/properties/building.inc")
	{obstacleid "building"}
	{props "concrete" "cornered" "construction" "parts" "no_destroyed_stamp"}
	("armor_heavy" args 0.8)
	{boarder}
	{mass 1000}
	{Volume "body"
		{Tags  "body"}
		{Thickness 50}
		{able {holed}}
	}
	{Volume "hole01"
		{Tags  "attach" "0"}
		{able clear {hole}{touch 1}}
	}
	{Volume "hole02"
		{Tags  "attach" "1"}
		{able clear {hole}{touch 1}}
	}

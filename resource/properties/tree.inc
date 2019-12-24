game_entity
	(include "seasons.inc")
	{volume "bole"
		{able {touch 0} {visible 0}}
		{thickness 2}
	}
	{volume "crown"
		{able
			{contact 0} {contact_ground 0}
			{bullet 0} {throwing 0} {obstacle 0}
			{overlap 1}
			{touch 0}
		}
		{density 0.007}
	}
	{simulatorId "pillar"}
	{collider 	"tree"}
	{obstacleID "tree"}
	{mass 200}
	{props "tree" "slow_on_crush"}
;	{NoCastShadows}
;	{NoGetShadows}
	{volume defaultmaterial "wood"}
	{lodclass "decor_tree"}

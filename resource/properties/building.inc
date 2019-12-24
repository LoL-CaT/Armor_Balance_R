game_entity
	{collider "construction"}
	{obstacleID "building"}
	{volume "body"
		{thickness hollow 1}
		{tags "body"}
	}
	{volume "body1"
		{thickness hollow 1}
		{tags "body"}
	}
	{mass 3000}
	{props "slow_on_crush"}
;	(include "/properties/shadow/construction.inc" sx(1) sy(0.18))
	(include "construction_generic.inc")

	{lodclass "decor_big"}

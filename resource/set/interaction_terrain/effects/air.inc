;SDL
{"air"
	{on detonate
		{if stuff "molotov_coctail"
			{spawn "ex_molot"}
		else stuff "dynamite"
			{spawn "ex_bomb_big"}
		else stuff "grenade"
			{spawn "ex_air_big"}
		else stuff "big shell fg bomb"
			{spawn "ex_bomb_big"}
		else stuff "size_maximum"
			{spawn "ex_air_big2"}
		}
	}
}

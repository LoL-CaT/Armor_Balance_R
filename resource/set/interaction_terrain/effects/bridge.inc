;SDL
{"bridge"
	{on hit
		{spawn "spheredust_small_short"}
	}
	{on detonate
		{if stuff "molotov_coctail"
			{spawn "ex_molot"}
			{spawn "fire_molot_ground"}
                else stuff "big smoke"
                    {spawn "ex_arm_big"}
                    {spawn "smoke_shell"}
		else stuff "dynamite"
			{spawn "ex_bomb_big"}
		else stuff "grenade big"
			{spawn "ex_grenade_big"}
		else stuff "grenade"
			{spawn "ex_grenade_sm"}
		else stuff "small bullet"
			{spawn "ex_bul_sm"}
		else stuff "zenite"
			{spawn "ex_bul_zenit"}
			{spawn "shellhole_small"}
		else stuff "bullet"
			{spawn "ex_bul_big"}
		else stuff "big mortar"
			{spawn "ex_mort_big"}
		else stuff "mortar"
			{spawn "ex_bomb_big"}
	    else stuff "shell size_minimum fg"
	      {spawn "ex_fg_minimum"}
	    else stuff "shell size_minimum"
			{spawn "ex_ap_minimum"}
			{spawn "shellhole_small"}
	    else stuff "shell size_small fg"
			{spawn "shockwave"}
			{spawn "ex_fg_small"}
	    else stuff "shell size_small"
			{spawn "shockwave"}
			{spawn "ex_ap_small"}
			{spawn "shellhole_small"}
		else stuff "shell size_medium fg"
			{spawn "ex_fg_medium"}
			{spawn "crater_norm" terrain_texmod}
		else stuff "shell size_medium"
			{spawn "ex_ap_medium"}
			{spawn "shellhole_medium"}
		else stuff "shell size_big fg"
			{spawn "ex_fg_big"}
			{spawn "crater_norm" terrain_texmod}
		else stuff "shell size_big"
			{spawn "ex_ap_medium"}
			{spawn "shellhole_medium"}
    	else stuff "shell size_maximum"
			{spawn "shockwave"}
			{spawn "ex_fg_maximum"}
	    else stuff "ap shell"
    		{spawn "ex_grenade_sm"}
		else stuff "big shell extra"
			{spawn "ex_bomb_big"}
		else stuff "big shell fg bomb"
			{spawn "ex_bomb_big"}
		else stuff "mine antipersonnel"
			{spawn "ex_grenade_big"}
		else stuff "mine antitank"
			{spawn "ex_arm_big"}
		else stuff "mine clockwork"
			{spawn "ex_anti_big"}
		else stuff "dynamite_clockwork"
			{spawn "ex_bomb_big"}
		else stuff "tnt_bag"
			{spawn "ex_bomb_big"}
		else stuff "flaerammo"
		{spawn "artillery_explosion_flaer"}
		}
	}
}

{"bridge_wood"
	{on hit
		{spawn "spheredust_small_short"}
	}
	{on detonate
		{if stuff "molotov_coctail"
			{spawn "ex_molot"}
			{spawn "fire_molot_ground"}
		else stuff "grenade big"
			{spawn "ex_grenade_big"}
		else stuff "grenade"
			{spawn "ex_grenade_sm"}
		else stuff "small bullet"
			{spawn "ex_bul_sm"}
		else stuff "zenite"
			{spawn "ex_bul_zenit"}
		else stuff "bullet"
			{spawn "wood_hit_bul"}
		else stuff "big mortar"
			{spawn "ex_mort_big_wood"}
		else stuff "mortar"
			{spawn "ex_bomb_big_wood"}
		else stuff "big shell extra"
			{spawn "ex_bomb_big_wood"}
		else stuff "big shell fg bomb"
			{spawn "ex_bomb_big_wood"}
		else stuff "big shell fg"
			{spawn "shockwave"}
			{spawn "ex_anti_big_wood"}
		else stuff "big shell ap"
			{spawn "ex_mort_big_wood"}
		else stuff "small shell fg"
			{spawn "shockwave"}
			{spawn "ex_mort_sm_wood"}
		else stuff "shell fg"
			{spawn "shockwave"}
			{spawn "ex_anti_big_wood"}
		else stuff "shell ap"
			{spawn "ex_mort_sm_wood"}
		else stuff "mine antipersonnel"
			{spawn "ex_grenade_big"}
		else stuff "mine antitank"
			{spawn "ex_mort_big_wood"}
		else stuff "mine clockwork"
			{spawn "ex_anti_big_wood"}
		else stuff "dynamite"
			{spawn "ex_bomb_big_wood"}
		else stuff "flaerammo"
			{spawn "artillery_explosion_flaer"}
		}
	}
}

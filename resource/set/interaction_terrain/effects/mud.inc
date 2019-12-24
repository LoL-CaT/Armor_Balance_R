;SDL
{"mud"
  {on hit
    {if min_mass 100
      {spawn "spheredust_small"}
    else min_mass 10
      {spawn "spheredust_small_short"}
    }
  }
  {on detonate
    {if stuff "molotov_coctail"
      {spawn "ex_molot"}
    else stuff "big smoke"
	{spawn "ex_arm_big"}
	{spawn "smoke_shell"}
    else stuff "dynamite"
      {spawn "ex_bomb_big"}
      {spawn "shellhole_big"}
    else stuff "grenade big"
      {spawn "ex_grenade_big"}
      {spawn "grenade_at_shellhole" terrain_texmod}
    else stuff "grenade"
      {spawn "ex_grenade_sm"}
      {spawn "grenade_shellhole" terrain_texmod}
    else stuff "small bullet"
      {spawn "ex_bul_sm2"}
    else stuff "zenite"
      {spawn "ex_bul_zenit"}
      {spawn "shellhole_small"}
    else stuff "bullet"
      {spawn "ex_bul_big2"}
    else stuff "mortar"
      {spawn "ex_mort_big"}
      {spawn "shellhole_big"}
    else stuff "big shell extra"
      {spawn "ex_bomb_big"}
      {spawn "crater_norm"}
    else stuff "big shell fg bomb no_crater small"
      {spawn "shockwave"}
      {spawn "ex_anti_big"}
      {spawn "shellhole4d3"}
    else stuff "big shell fg bomb no_crater"
      {spawn "ex_bomb_big"}
      {spawn "shellhole4d2"}
    else stuff "big shell fg bomb"
      {spawn "ex_bomb_big"}
      {spawn "crater_norm"}
    else stuff "big shell fg"
      {spawn "shockwave"}
      {spawn "ex_anti_big"}
      {spawn "crater_norm"}
    else stuff "big shell ap"
      {spawn "ex_arm_big"}
      {spawn "crater_small"}
    else stuff "small shell fg"
      {spawn "shockwave"}
      {spawn "ex_anti_small"}
      {spawn "shellhole_big_ground"}
    else stuff "shell fg"
      {spawn "shockwave"}
      {spawn "ex_anti_big"}
      {spawn "crater_norm"}
    else stuff "shell ap"
      {spawn "ex_arm_sm"}
      {spawn "crater_small"}
    else stuff "mine antipersonnel"
      {spawn "ex_grenade_big"}
      {spawn "shellhole_medium"}
    else stuff "mine antitank"
	  {spawn "ex_arm_big"}
      {spawn "shellhole_big"}
	else stuff "mine clockwork"
		{spawn "ex_anti_big"}
		{spawn "shellhole_big"}
    else stuff "dynamite_clockwork"
      {spawn "ex_bomb_big"}
      {spawn "shellhole_big"}
    else stuff "tnt_bag"
      {spawn "ex_bomb_big"}
      {spawn "shellhole_big"}
    else stuff "flaerammo"
	  {spawn "artillery_explosion_flaer"}
    }
  }
}

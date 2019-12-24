{"ice"
  {on hit
    {if min_mass 100
      {if effector "tree"
        {spawn "tree_crush"}
      else
        {spawn "spheredust_small"}
      }
    else min_mass 10
      {spawn "spheredust_small_short"}
    }
  }
  {on detonate
    {if stuff "molotov_coctail"
      {spawn "ex_molot"}
      {spawn "fire_molot_ground"}
      {spawn "fire_shellhole"}
    else stuff "big smoke"
	{spawn "ex_arm_big"}
	{spawn "smoke_shell"}
    else stuff "dynamite"
      {spawn "ex_bomb_big_snow"}
    else stuff "grenade big"
      {spawn "ex_grenade_big_snow"}
    else stuff "grenade"
      {spawn "ex_grenade_sm_snow"}
    else stuff "small bullet"
      {spawn "ex_bul_sm_snow"}
    else stuff "zenite"
      {spawn "ex_bul_zenit_snow"}
    else stuff "bullet"
      {spawn "ex_bul_big_snow"}
    else stuff "mortar"
      {spawn "ex_mort_big_snow"}
    else stuff "shell size_minimum fg"
      {spawn "ex_fg_minimum"}
    else stuff "shell size_minimum"
      {spawn "ex_ap_minimum"}
	  {spawn "shellhole_small"}
    else stuff "shell size_small fg"
      {spawn "ex_fg_small"}
    else stuff "shell size_small"
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
      {spawn "ex_fg_maximum"}
    else stuff "big shell extra"
      {spawn "ex_bomb_big_snow" offset 0 0 20}
    else stuff "big shell fg bomb no_crater small"
      {spawn "shockwave"}
      {spawn "ex_mort_big_snow"}
    else stuff "big shell fg bomb no_crater"
      {spawn "ex_bomb_big_snow"}
    else stuff "big shell fg bomb"
      {spawn "ex_bomb_big_snow"}
    else stuff "big shell fg"
      {spawn "shockwave"}
      {spawn "ex_mort_big_snow"}
    else stuff "big shell ap"
      {spawn "ex_mort_sm_snow"}
    else stuff "small shell fg"
      {spawn "shockwave"}
      {spawn "ex_anti_small"}
      {spawn "snow_hit_big"}
    else stuff "shell fg"
      {spawn "shockwave"}
      {spawn "ex_mort_big_snow"}
    else stuff "shell ap"
      {spawn "ex_arm_sm"}
      {spawn "snow_hit_big"}
    else stuff "mine antipersonnel"
	  {spawn "ex_mort_sm_snow"}
    else stuff "mine antitank"
      {spawn "ex_mort_big_snow"}
	else stuff "mine clockwork"
		{spawn "ex_anti_big"}
    else stuff "dynamite_clockwork"
      {spawn "ex_bomb_big_snow"}
    else stuff "tnt_bag"
      {spawn "ex_bomb_big_snow"}
    else stuff "flaerammo"
	  {spawn "artillery_explosion_flaer"}
    }
  }
}

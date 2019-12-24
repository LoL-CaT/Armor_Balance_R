;SDL

(define "water_bullets"
  {if stuff "zenite"
    {spawn "ex_bul_big_w"}
  else stuff "bullet"
    {spawn "ex_bul_sm_w"}
  else stuff "big shell extra"
    {spawn "ex_water_extra_big"}
  else stuff "big shell ap"
    {spawn "ex_water_big"}
  else stuff "big shell fg"
    {spawn "ex_water_big"}
  else stuff "shell ap"
    {spawn "ex_water_sm"}
  else stuff "big mortar"
    {spawn "ex_water_extra_big"}
  else stuff "mortar"
    {spawn "ex_water_big"}
  }
)

(define "shallow_water_bullets"
  {if stuff "zenite"
    {spawn "ex_bul_big_w"}
  else stuff "bullet"
    {spawn "ex_bul_sm_w"}
  else stuff "big shell extra"
    {spawn "ex_water_extra_big"}
  else stuff "big shell ap"
    {spawn "ex_watersh_big"}
  else stuff "big shell fg"
    {spawn "ex_watersh_big"}
  else stuff "shell ap"
    {spawn "ex_water_sm"}
  else stuff "big mortar"
    {spawn "ex_water_extra_big"}
  else stuff "mortar"
    {spawn "ex_watersh_big"}
  }
)

(define "water_hits"
  {if min_mass 50
    {spawn "spherewater_big"}
  else min_mass 0.5
    {spawn "spherewater_small"}
  else effector "human"
    {spawn "spherewater_big"}
  else effector "steel"
    {spawn "spherewater_small"}
  }
; {if min_mass 100
;   {spawn "spheredust_small"}
; else min_mass 10
;   {spawn "spheredust_small_short"}
; }
)

(define "water_detonate"
  {if stuff "molotov_coctail"
    {spawn "spherewater_small"}
  else stuff "dynamite"
    {spawn "ex_water_big"}
  else stuff "grenade big"
    {spawn "ex_water_big"}
  else stuff "grenade"
    {spawn "ex_water_sm"}
  else stuff "mine antipersonnel"
    {spawn "ex_water_sm"}
  else stuff "mine antitank"
    {spawn "ex_water_big"}
  else stuff "mine clockwork"
    {spawn "ex_water_big"}
  else stuff "dynamite_clockwork"
    {spawn "ex_water_big"}
  else stuff "tnt_bag"
    {spawn "ex_water_big"}
  else stuff "shell fg"
    {spawn "ex_water_big"}
  }
)

(define "shallow_water_detonate"
  {if stuff "molotov_coctail"
    {spawn "spherewater_small"}
  else stuff "dynamite"
    {spawn "ex_watersh_big"}
  else stuff "grenade big"
    {spawn "ex_watersh_big"}
  else stuff "grenade"
    {spawn "ex_water_sm"}
  else stuff "mine antipersonnel"
    {spawn "ex_water_sm"}
  else stuff "mine antitank"
    {spawn "ex_watersh_big"}
  else stuff "mine clockwork"
    {spawn "ex_watersh_big"}
  else stuff "dynamite_clockwork"
    {spawn "ex_watersh_big"}
  else stuff "tnt_bag"
    {spawn "ex_watersh_big"}
  else stuff "shell fg"
    {spawn "ex_watersh_big"}
  }
)

{"shallow_water"
  {on bullet  ("shallow_water_bullets") }
  {on hit   ("water_hits")    }
  {on detonate
	("shallow_water_detonate")
	("water_bullets")
  }
}
{"water"
  {on bullet  ("water_bullets") }
  {on hit   ("water_hits")    }
  {on detonate("water_detonate")  }
}
{"underwater"
; {on hit   {con "underwater hit"}    }
  {on detonate
    ("water_detonate")
    {if stuff "shell"
      {spawn "shellhole_big_ground"}
    }
  }
}

{"puddle"
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
      {spawn "fire_molot_ground"}
      {spawn "fire_shellhole"}
    else stuff "dynamite"
      {spawn "ex_bomb_big"}
      {spawn "shellhole_big"}
    else stuff "grenade big"
      {spawn "ex_grenade_big"}
      {spawn "grenade_at_shellhole"}
    else stuff "grenade"
      {spawn "ex_grenade_sm"}
      {spawn "grenade_shellhole"}
    else stuff "small bullet"
      {spawn "ex_bul_sm_w"}
    else stuff "zenite"
      {spawn "ex_bul_big_w"}
    else stuff "bullet"
      {spawn "ex_bul_sm_w"}
    else stuff "big mortar"
      {spawn "ex_mort_big"}
      {spawn "shellhole_big"}
    else stuff "mortar"
      {spawn "ex_bomb_big"}
      {spawn "shellhole_medium"}
    else stuff "shell size_minimum fg"
      {spawn "ex_fg_minimum"}
      {spawn "grenade_shellhole" terrain_texmod}
    else stuff "shell size_minimum"
      {spawn "ex_ap_minimum"}
    else stuff "shell size_small fg"
      {spawn "ex_fg_small"}
      {spawn "crater_norm" terrain_texmod}
    else stuff "shell size_small"
      {spawn "ex_ap_small"}
    else stuff "shell size_medium fg"
      {spawn "ex_fg_medium"}
      {spawn "crater_norm" terrain_texmod}
    else stuff "shell size_medium"
      {spawn "ex_ap_medium"}
    else stuff "shell size_big fg"
      {spawn "ex_fg_big"}
      {spawn "crater_norm" terrain_texmod}
    else stuff "shell size_big"
      {spawn "ex_ap_medium"}
    else stuff "shell size_maximum"
      {spawn "ex_fg_maximum"}
      {spawn "crater_big" terrain_texmod}
    else stuff "big shell extra"
      {spawn "ex_bomb_big" offset 0 0 20}
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
      {spawn "shellhole_big_ground"}
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
      {spawn "shellhole_big_ground"}
    else stuff "mine antipersonnel"
      {spawn "ex_grenade_big"}
      {spawn "shellhole_medium"}
    else stuff "mine antitank"
      {spawn "ex_anti_big"}
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
    }
  }
}

(define "swamp_terrain"
  {on hit   ("water_hits")    }
  {on bullet  ("water_bullets") }
  {on detonate("water_detonate")
        ("water_bullets")
    {if stuff "shell"
      {spawn "shellhole_big_ground"}
    }
  }
)

{"swamp"
  ("swamp_terrain")
}


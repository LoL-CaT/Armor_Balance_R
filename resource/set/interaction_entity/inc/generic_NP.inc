{"generic"
	{on bullet_hit
		{if not under_water
;flesh
			{if material "flesh"
				{if stuff "zenite"
					;{spawn "ex_air_norm"}
				else stuff "wp ammo"
     					{spawn "ex_wp"}
				else stuff "mortar"
					{spawn "ex_air_big"}
				else stuff "size4"
					{spawn "ex_air_big2"}
				else stuff "shell fg"
					{spawn "ex_air_big"}
				else stuff "bazooka"
					{spawn "ex_air_big"}
                else stuff "mortar_fg_medium"
                	{spawn "mortar_fg_medium_ground"}
				else stuff "mortar_ab_light"
					{spawn "mortar_ab_light_ground"}  
				else stuff "shell cu" 
					{start_sound "detonation/cu_shell"}
 	     			{spawn "ex_bul_zenit"}
                }
;steel
			else material "steel"
				{if stuff "bullet"
					{spawn "metal_hit_bul"}
                else stuff "wp ammo"
   					{spawn "ex_wp"}
				else stuff "mortar"
					{spawn "metal_hit_br"}
				else stuff "zenite"
					{spawn "metal_hit_bul"}
					{spawn "ex_air_sm"}
				else stuff "rocketlauncher"
					{spawn "metal_hit_bazooka"}
				else stuff "size4"
					{spawn "metal_hit_fg_big"}
				else stuff "heat_small"
					{spawn "metal_hit_heat_small"}
				else stuff "heat_medium"
					{spawn "metal_hit_heat_medium"}
				else stuff "heat_big"
					{spawn "metal_hit_heat_big"}
				else stuff "shell size_minimum fg"
					{spawn "metal_hit_fg_minimum"}
				else stuff "shell size_small fg"
					{spawn "metal_hit_fg_small"}
				else stuff "shell size_medium fg"
					{spawn "metal_hit_fg_medium"}
				else stuff "shell size_big fg"
					{spawn "metal_hit_fg_big"}
				else stuff "shell size_maximum fg"
					{spawn "metal_hit_fg_big"}
				else stuff "shell small fg"
					{spawn "metal_hit_fg"}
				else stuff "shell shell_small_apcr"
					{spawn "metal_hit_br_small_apcr"}
				else stuff "shell shell_small_no_filler"
					{spawn "metal_hit_br_small_ap"}
				else stuff "shell small"
					{spawn "metal_hit_br_small"}
				else stuff "shell fg"
					{spawn "metal_hit_fg"}
				else stuff "shell size_minimum"
					{spawn "metal_hit_br_small_ap"}
					{blastwave c4 1 r0 1.5 r1 3}
				else stuff "shell shell_medium_apcr"
					{spawn "metal_hit_br_apcr"}
					{blastwave c4 1 r0 3 r1 5}
				else stuff "shell shell_medium_no_filler"
					{spawn "metal_hit_br_ap"}
					{blastwave c4 1 r0 3 r1 5}
				else stuff "shell shell_medium"
					{spawn "metal_hit_br"}
					{blastwave c4 1 r0 3 r1 5}
				else stuff "shell shell_big_apcr"
					{spawn "metal_hit_br_big_apcr"}
					{blastwave c4 1 r0 4 r1 6}
				else stuff "shell shell_big"
					{spawn "metal_hit_br_big"}
					{blastwave c4 1 r0 4 r1 6}
				else stuff "shell"
					{spawn "metal_hit_br"}
				else stuff "mortar_ab_light"
					{spawn "mortar_ab_light_ground"}
				else stuff "shell cu" 
					{start_sound "detonation/cu_shell"}
 	     			{spawn "ex_bul_zenit"}
					{spawn "metal_hit_br"}
                }
			else material "steelball"
				{spawn "metal_hit_bul"}
;wood
			else material "wood"
				{if stuff "bullet"
					{spawn "wood_hit_bul"}
				else stuff "wp ammo"
  					{spawn "ex_wp"}
				else stuff "mortar"
					{spawn "wood_hit_fg"}
				else stuff "zenite"
					{spawn "wood_hit_bul"}
				else stuff "heat_small"
					{spawn "metal_hit_heat_small"}
				else stuff "heat_medium"
					{spawn "metal_hit_heat_medium"}
				else stuff "heat_big"
					{spawn "metal_hit_heat_big"}
				else stuff "shell small"
					{spawn "wood_hit_br_small"}
				else stuff "shell fg"
					{spawn "ex_mort_big"}
				else stuff "shell"
					{spawn "wood_hit_br"}
				else stuff "mortar_ab_light"
					{spawn "mortar_ab_light_ground"}  
				else stuff "shell cu" 
					{start_sound "detonation/cu_shell"}
					{spawn "ex_bul_zenit"}
				}
;concrete
			else material "concrete"
				{if stuff "bullet"
					{spawn "stone_hit_bul"}
					{spawn "ex_air_sm"}
				else stuff "wp ammo"
     					{spawn "ex_wp"}
				else stuff "zenite"
					{spawn "stone_hit_bul"}
					{spawn "ex_air_sm"}
				else stuff "big shell fg"
				 	{spawn	"stone_hit_br_big"}
				else stuff "shell small"
				 	{spawn	"stone_hit_br_small"}
				else stuff "mortar_ab_light"
					{spawn "mortar_ab_light_ground"}  
				else stuff "shell cu" 
					{start_sound "detonation/cu_shell"}
 	     				{spawn "ex_bul_zenit"}
				else
				 	{spawn	"stone_hit_br"}
				}
;sand
			else material "sand"
				{if stuff "zenite"
					{spawn "ex_air_sm"}
					{spawn "sand_hit_bul"}
				else stuff "wp ammo"
     					{spawn "ex_wp"}
				else stuff "mortar"
					{spawn "ex_mort_sm"}
				else stuff "shell fg"
					{spawn "ex_mort_big"}
				else stuff "bazooka"
					{spawn "ex_air_big"}
				else stuff "mortar_ab_light"
					{spawn "mortar_ab_light_ground"}  
				else stuff "shell cu" 
					{start_sound "detonation/cu_shell"}
 	     				{spawn "ex_bul_zenit"}
				else
					{spawn "sand_hit_small"}
				}
;ice
			else material "ice"
				{if stuff "shell fg"
					{spawn "ex_mort_sm_snow"}
				else stuff "shell cu" 
					{start_sound "detonation/cu_shell"}
 	     				{spawn "ex_bul_zenit"}
				else
					{spawn "snow_hit_small"}
				}
			}
		}
	}
}
{"bullet"
	{on spawn
		{delay 0
			{volumes disable bullet}
			{volumes enable contact}
							;prevent destroing at spawn moment
		}
		{delay 4
		}
		{impulse up 0 0}
		{link_sound "tracer" "weapon/shot/tracer"}
		{link_sound "whistle" "hit/medium/metal_whistle"}
		{play_sound "tracer"}
	}
	{on contact
		{if effector "tank"
			{play_sound "whistle"}
		}
	}		
}

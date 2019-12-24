{"firewood"
	{inflammation_time 10}
	{on bullet_hit
		{if stuff "shell fg"
			{bullet_detonate}
		}
	}
	{on break_armor
		{call "break"}
	}
	{on contact
		{if can_crush
			{volumes disable contact}
			{call "break"}
		}
	}
	{on "break"
		{spawn "wood_crush_big" "root"}
		{delay 0.2 {delete}}
	}
	{on "burn_volume"
		{if not burned
			{if volume "body"
				{burn volume fx "smoke_dead_tree1" time 15 2 even_law}
				{delay 8 "break_delay" {call "break"}}
			}
		}
	}
}

{"stack"
	{inflammation_time 0.3}
	{on bullet_hit
		{if stuff "shell"
			{spawn "hay_hit_norm"}
		else stuff "bullet"
			{spawn "hay_hit_small2"}
		}
	}
	{on break_armor
		{set "crush" 0}
		{call "crush"}
	}
	{on contact
		{if can_crush
			{set "crush" 1}
			{call "crush"}
		}
	}
	{on "crush"
		{volumes disable visible bullet contact blast}
		{call "crush_fx"}
		{set "fall" 1}
		{tex_morph "crushed" 0.1}
		{ani_play "crush" 10 callback}
	}
	{on "burn_volume"
		{if not burned
			{if volume "fire"
				{call "_burn"}
			}
		}
	}
	{on "_burn"
		{volumes disable visible bullet contact blast}
		{burn volume "fire0" fx "smoke_dead_norm" time 15 even_law}
		{burn volume "fire1" fx "smoke_dead_tree1" time 10 even_law}
		{tex_morph "burned" 8}
		{delay 6.0
			{spawn "burn_grass1"}
			{if not "fall"
				{set "fall" 1}
				{ani_play "crush" callback}
			}
		}
	}
	{on animation_end "crush"
		{update_shadow}
		{update_visibility_patch}
		{area disable}
	}
	{on "crush_fx"
		{spawn "wheat_big" no_position}
		{if "crush"
			{spawn "hay_hit_fall" "fx_hayfall1"}
			{spawn "hay_hit_fall" "fx_hayfall2"}
			{spawn "hay_hit_fall" "fx_hayfall3"}
			{spawn "hay_hit_fall" "fx_hayfall4"}
		else
			{spawn "hay_hit_big" no_position}
			{spawn "hay_hit_big" "FX_haulm1"}
			{spawn "hay_hit_big" "FX_haulm2"}
		}
	}
}

{"stack tent"
	{on "crush_fx" overload}
	{on bullet_hit overload
		{if not under_water
			{if stuff "bullet"
				{spawn "spheredust_small_short"}
			else stuff "zenite"
				{spawn "spheredust_small_short"}
			else stuff "shell"
				{spawn "spheredust_small_short"}
			else stuff "mortar"
				{spawn "spheredust_small_short"}
			}
		}
	}
}

{"gate"
	{on spawn
		{call "update_area"}
	}
	{on "open"
		{if not "user_opened"
			{set "opened" 1}
			{ani_play "open" resume callback}
			{call "update_area"}
		}
	}
	{on "close"
		{if not "user_opened"
			{set "opened" 0}
			{ani_play "open" -1 resume}
			{call "update_area"}
		}
	}
	{on animation_end "open"
		{tags add "opened"}
	}
	{on "update_area"
		{if "opened"
			{area disable	"close"}
			{area enable	"left"}
			{area enable	"right"}
		else
			{area enable	"close"}
			{area disable	"left"}
			{area disable	"right"}
		}
	}
	{on "open_disable"
		{volumes "door_lock" disable touch}
	}
	{on "open_enable"
		{volumes "door_lock" enable touch}
	}
}

{"ferry"
	{on spawn
		{call "update_area"}
	}
	(define "update_area"
		{if "opened%0"
			{area disable	"close%0_%1"}
			{area enable	"left%0_%1"}
			{area enable	"right%0_%1"}

			{area disable	"close%0_%2"}
			{area disable	"left%0_%2"}
			{area disable	"right%0_%2"}
		else
			{area enable	"close%0_%1"}
			{area disable	"left%0_%1"}
			{area disable	"right%0_%1"}

			{area disable	"close%0_%2"}
			{area disable	"left%0_%2"}
			{area disable	"right%0_%2"}
		}
	)
	(define "door"
		{on "open%0"
			{set "opened%0" 1}
			{ani_play "open%0"}
			{call "update_area%0"}
		}
		{on "close%0"
			{set "opened%0" 0}
			{ani_play "close%0"}
			{call "update_area%0"}
		}
		{on "open_fast%0"
			{set "opened%0" 1}
			{ani_wind "open%0" end}
			{call "update_area%0"}
		}
		{on "close_fast%0"
			{set "opened%0" 0}
			{ani_wind "close%0" end}
			{call "update_area%0"}
		}
		{on "update_area%0"
			{if not "moved"
				("update_area" args %0 1 2)
				{area enable	"rectangle01"}
				{area enable	"rectangle02"}
				{area disable	"rectangle03"}
				{area disable	"rectangle04"}
			else
				("update_area" args %0 2 1)
				{area disable	"rectangle01"}
				{area disable	"rectangle02"}
				{area enable	"rectangle03"}
				{area enable	"rectangle04"}
			}
		}
	)
	("door" args 1)
	("door" args 2)
	{on "update_area"
		{call "update_area1"}
		{call "update_area2"}
	}
	{on "move_front"
		{set "moved" 1}
		{call "update_area"}
		{land off}
		{ani_play "move" callback}
	}
	{on "move_back"
		{set "moved" 0}
		{call "update_area"}
		{land off}
		{ani_play "move" -1 callback}
	}
	{on "update_land"
		{land off}
		{land on}
	}
	{on animation_end "move"
		{land on}
	}
}

{"tank_platform"
	{on "close"
		{land off}
		{ani_play "close1"}
		{ani_play "close2"}
	}
	{on "open"
		{land on}
		{ani_play "close1" -1}
		{ani_play "close2" -1}
	}

	{on "move"
		{ani_play "move"}	
	}
}

{"switch"
	{on "switch"
		{tags add "switch"}
	}
}

{"dynamite_fuse"
	{on "switch"
		{tags add "switch"}
		{ani_play "move"}
	}
}


{"gate door_big"
	{on "open"
		{start_sound "vehicle/engine/door"}
	}
	{on "close"
		{start_sound "vehicle/engine/door"}
	}
}

{"gate lock"
	{on "open"
;		{start_sound "vehicle/engine/door"}
		{volumes "attach" enable touch}
	}
	{on bullet_hit
		{if volume "lock"
			{if not "opened"
				{call "open"}
				{set "user_opened" 1}
				{delay_ex 0
					{tear "piece_small_steel" bone "lock"
						{impulse up -1 0.7 dir 2.5 0.3 no_position}
					}
				}
			}
		}
	}
}

{"sandbag"
	{on bullet_hit
		{if stuff "bullet"
			{spawn "ex_air_sm"}
			{bullet_detonate}
		else stuff "shell"
			{spawn "sand_hit_small"}
			{bullet_detonate}
		}
	}
	{on contact
		{if can_crush
			{volumes disable contact}
			{delay 0
				{call "crush"}
			}
		}
	}
	{on "crush"
		{if not "crushed"
			{set "crushed" 1}
			{set_skeleton "_x"}
			{ani_play "crush1" callback}
			{call "update_fx"}
			{call "effects"}
		}
	}
	{on animation_end "crush1"
		{ani_play "crush2"}
	}
}

{"sand_bag_small"
	{on break_armor
		{spawn "sand_hit_small"}
		{delete}
	}
	{on contact
		{if can_crush
			{volumes disable contact}
			{spawn "sand_hit_small"}
			{delete}
		}
	}
}

{"sand_bag_big"
	{on break_armor
		{spawn "wood_crush_big"}
		{delete}
	}
	{on contact
		{if can_crush
			{volumes disable contact}
			{spawn "wood_crush_big"}
			{delete}
		}
	}
}

{"showcase"
	{on "break_window"
		{area disable}
	}
}

{"fountain_small"
	{on spawn
		{add_view "drops_water_fountain" "water" "FX_water"}
		{add_view "drops_water_fountain" "water" "FX_water1"}
		{add_view "drops_water_fountain" "water" "FX_water2"}
		{add_view "drops_water_fountain" "water" "FX_water3"}
		{add_view "fountain_small" "water" "FX_water4"}
		{view start "water"}
	}
}

{"waterfall_big"
	{on spawn
		{add_view "waterfall_sm"	"wfall"	"FX_waterfall1"	}
		{add_view "waterfall_sm"	"wfall"	"FX_waterfall2"	}
		{add_view "waterfall_sm"	"wfall"	"FX_waterfall3"	}
		{add_view "waterfall_sm"	"wfall"	"FX_waterfall4"	}
		{add_view "waterfall_sm"	"wfall"	"FX_waterfall5"	}
		{add_view "waterfall_sm"	"wfall"	"FX_waterfall6"	}
		{add_view "waterfall_sm"	"wfall"	"FX_waterfall7"	}
		{view start "wfall"}
	}
}

{"steam_small"
	{on spawn
		{add_view "steam" "smoke" "FX_steam"}
		{view start "smoke"}
	}
}

{"steam_big"
	{on spawn
		{add_view "smoke_black" "smoke" "FX_steam"}
		{view start "smoke"}
	}
}

{"trench"
	{on blast
		{if volume "body"
			{if min_energy 3
				{call "break"}
			}
		}
	}
	{on "break"
		{if not "broken"
			{set "broken" 1}
			{tags add "crushed"}
			{call "disable_volumes"}
			{delay_ex 0
				{set_skeleton "_x"}
				{call "update_fx"}
				{set "first_stage" 1}
				{set "last_stage" 1}
				{call "effects"}
				{ani_play "crush"}
				{delay 0.1
					{update_visibility_patch}
				}
			}
		}
	}
}

{"sewer"
	{on spawn
		{call "update_area"}
		{ani_play "open"}
	}
	{on "update_area"
		{if "opened"
			{area enable "sewer"}
		else
			{area disable "sewer"}
		}
	}
	{on "open"
		{ani_play "open" +1 resume}
		{set "opened" 1}
		{call "update_area"}
	}
	{on "close"
		{ani_play "open" -1 resume}
		{set "opened" 0}
		{call "update_area"}
	}
}

{"delete_after_crush"
	{on "break"
		{delete}
	}
}

{"boat_trap"
	{on "open"
		{land off}
		{ani_wind "land" end}
		{ani_play "open"}
		{delay 0.1
			{land on}
			{area disable "left"}
			{area disable "right"}
		}
	}
	{on "close"
		{land off}
		{ani_wind "land" begin}
		{ani_play "open" -1}
		{delay 5
			{land on}
			{area enable "left"}
			{area enable "right"}
		}
	}
}

{"dummy"
	{on "stop"	{view stop ""}}
	{on "pause"	{view pause ""}}
	{on "delete"{delete}}
}

{"ps_dummy"
	{on "delete"{hide 3}}
}

{"physics_damping"
;	{friction 1000}
;	{restitution 0.001}
}

(define "throwing_weapon"
	{on contact
		{if effector "human"
			{delay 0
				{constrain_velocity 1}
			}
		}
	}
)

{"knife" ("throwing_weapon")}
{"axe" ("throwing_weapon")}

{"stone"
	{on bullet_hit
		{bullet_detonate}
	}
}

{"part"
	{on "check_delete_part" ; called only inside tear, so with_effector swaps entity&effector for flag check
		{with_effector
			{if "delete_parts"
				{with_effector
					{delay 20
						{hide 3}
					}
				}
			}
		}
	}
}

{"flesh part"
	{on blast  {spawn "bloodsparks_small"}}
	{on bullet_hit {spawn "bloodsparks_small"}}
	{on contact
		{spawn "bloodsparks_small"}
	}
	{on ground_hit
		{if min_speed 10
			{spawn "bloodsparks_small"}
		}
	}
}

{"small part"
	{on spawn
;		{con "spawn small part"}
		{delay 0.1
			{volumes disable bullet contact blast touch}	;prevent destroing at spawn moment
		}
		{delay 2 {volumes enable bullet contact blast}}
		{call "stop_view"}
		{delay 25 15 {hide 10}}
	}
	{on blast_hit
;		{con "blast small part"}
		{if min_energy 0.5
			{hide 1}
		else
			{impulse up 3 1 dir 2 1}
		}
	}
	{on bullet_hit
;		{con "bullet small part"}
		{if stuff "bullet"
			{impulse up 2 1 dir 1 0.5}
		else stuff "shell"
			{hide 1}
		}
	}
	{on contact
;		{con "contact small part"}
		{if effector "vehicle"
			{volumes disable bullet contact blast}	;prevent destroing at spawn moment
			{hide 1}
		}
	}
}

{"small part fx"
	{on "stop_view"
		{delay 0.5 0.3 {view stop ""}}
	}
}

{"medium part"
;	{friction 2}
;	{restitution 0.2}
	{on spawn
		{delay 0.1
			{volumes disable bullet contact blast touch}	;prevent destroing at spawn moment
		}
		{delay 2 {volumes enable bullet contact blast}}
	}
	{on blast_hit
		{if min_energy 1.0
			{hide 1}
		else
			{impulse up 1 1 dir 2 1}
		}
	}
	{on bullet_hit
		{if stuff "bullet"
			{impulse up 0.5 0.5 dir 0.5 0.5}
		else stuff "shell"
			{hide 1}		
		}
	}
	{on contact
		{impulse up 0.1 0.1 dir 0.1 0.1}
	}
}

{"big part"
;	{friction 2}
;	{restitution 0.1}
	{on spawn
		{delay 0.1
			{volumes disable touch}
		}
	}
	{on blast_hit
		{if min_energy 8 
			{impulse up 5 1 dir 5 1}
		  else min_energy 0.5
			{impulse up 1 0.3 dir 1 0.5}
		}
	}
	{on bullet_hit
		{if stuff "big shell extra"
			{impulse up 5 1 dir 5 1}
		 else stuff "shell"
			{impulse up 1 0.3 dir 1 0.5}
		 else stuff "zenite"
			{impulse up 0.2 0.1 dir 0.1 0.05}
		}
	}
}

{"big part delete"
	{on spawn
		{delay 20
			{delete}
		}
	}
}

{"wood part"
	{on spawn
		{delay 2
			{volumes enable float}
		}
	}
;	{on ground_hit
;		{if terrain "water"
;			{call "kick"}
;		else terrain "deep_water"
;			{call "kick"}
;		}
;	}
;	{on "kick"
;		{delay 15
;			{kill_delay "kick_process"}
;		}
;		{call "kick_process"}
;	}
;	{on "kick_process"
;		{delay 0.3 0.1 "kick_process"
;			{impulse up 1}
;			{call "kick_process"}
;		}
;	}
}

{"fx_piece_flame"
	{on spawn
		{volumes "body" disable contact}
		{gravity 10}
		{delay 0
			{add_view "fire_flame_thrower_fly" "fire1" "root"}
			{view start "fire1"}
		}
		{delay 0.2
			{add_view "fire_flame_thrower_fly4" "fire2" "root"}
			{view start "fire2"}
		}
;		{delay 0.3
;			{add_view "fire_flame_thrower_fly5" "fire" "root"}
;			{view start "fire"}
;		}
		{delay 0.05
			{volumes "body" enable contact}
			{fire radius 0.5 time 0.7 heating 1.5 follow}
		}
;		{delay 0.2
;			{fire radius 0.5 time 0.5 heating 0.5 follow}
;		}
;		{delay 0.5
;			{call "end"}
;		}
	}
	{on contact
		{volumes disable contact}
		{call "end_object"}
	}
	{on ground_hit
		{view stop "fire1"}
		{view stop "fire2"}
		{delay 0.1
			{call "end"}
		}
	}
	{on "end_object"
		{if rand 0.2
			{spawn "fire_die"}
		}
		{call "end"}
	}
	{on "end"
		{if rand 0.5
			{fire radius 3 time 4 heating 0.3}
			{fire radius 1.5 time 0.8 heating 0.5}
			
			{if not air
				{if not under_water
					{spawn "fire_flame_thrower" dir_velocity}
					{if rand 0.05
						{spawn "fx_piece_flame_end"}
					}
;					{spawn "fire_shellhole2"}
				}
			}
		}
		{delete}
	}
}



{"fx_piece_flame_end"
	{on spawn
		{add_view "fire_flame_thrower_light" "light" "root"}
		{view start "light"}
		{delay 7
			{delete}
		}
	}
}

{"napalm"
	{on "start"
		{add_view "fire_napalm" "flame" "root"}
		{view start "flame"}
		{fire radius 2 time 1000000 heating 70 follow}
	}
	{on "end"
		{delete}
	}
}

{## "tagged_piece"
	{on spawn
		{tags add "isu_fire"}
		{delay 25
			{delete}
		}
	}
}

{"inventory_box"
	{on "break"
		{explode_inventory
			{5			"ex_arm_sm"		3	}
			{30			"ex_anti_big"	5	}
			{100		"ex_bomb_big"	10	}
			{1000		"train_die"		15	}
			{10000		"train_die"		20	}
			{100000		"train_die"		25	}
			{1000000	"train_die"		30	}
		}
	}
}

{"flag"
	{on spawn
		{call "start"}
	}
	{on "stop"
		{ani_stop "flattern"}
		{ani_play "stop"}
	}
	{on "start"
		{ani_play "flattern" loop}
	}
}

{"flag captureable"
	{on "capture"
		{if tex_mod "1"
			{ani_play "up" resume callback}
		else
			{ani_play "down" resume callback}
		}
	}
	{on "cancel"
		{set "stop" 1}
		{ani_stop "up"}
		{ani_stop "down"}
		{set "stop" 0}
	}
	{on "enable"
		{volumes "activate" enable contact}
	}
	{on "disable"
		{volumes "activate" disable contact}
	}
	{on animation_end "down"
		{if not "stop"
			{tex_mod "1"}
			{call "capture"}
		}
	}
	{on animation_end "up"
		{if not "stop"
			{tags add "captured"}
		}
	}
}

{"map_point"
	{on "start"
		{ani_play "rotate" loop}
	}
}


{"starshell"
	{on spawn
		{add_view "starshell_light"	"light" "root"}
		{delay 0.4
			{view start "light"}
		}
		{impulse up 40 fx 10 20 fy 10 20}
		{delay 4 1
			{delete}
		}
	}
}
{"water"
	{on spawn
		{ani_play "wave" loop}
		{add_view "wash_big_flow" "wash" "FX_wash"}
		{add_view "wash_big_flow" "wash" "FX_wash1"}
		{add_view "wash_big_flow" "wash" "FX_wash2"}
		{add_view "wash_big_flow" "wash" "FX_wash3"}
		{add_view "wash_big_flow" "wash" "FX_wash4"}
		{add_view "wash_big_flow" "wash" "FX_wash5"}
		{add_view "wash_big_flow" "wash" "FX_wash6"}
		{add_view "wash_big_flow" "wash" "FX_wash7"}
		{add_view "wash_big_flow" "wash" "FX_wash8"}
		{add_view "wash_big_flow" "wash" "FX_wash9"}
		{view start "wash"}
	}
}

{"water_animation_pingpong"
	{on spawn
		{set "backward" 0}
		{call "animate"}
	}
	{on animation_end "wave"
		{call "animate"}
	}
	{on "animate"
		{if "backward"
			{ani_play "wave" -1 callback}
			{set "backward" 0}
		else
			{ani_play "wave" 1 callback}
			{set "backward" 1}
		}
	}
}

{"cord_wood"
	{inflammation_time 3}
	(define "burn_start"
		{add_view "smoke_camp_norm" "fire" "fx_light"}
		{set "burning" 1}
		{view start "fire"}
		{burn time %0}
		{fire radius 0.7 time %0 heating 0.3 follow}
		{delay %0
			{view stop "fire"}
			{set "burning" 0}
			{tags remove "burned"}
		}
	)
	{on spawn
		{if "burning"
			{add_view "smoke_camp_norm" "fire" "fx_light"}
			{view start "fire"}
		}
	}
	{on "_burn"
		{if "poured"
			{tags add "burned"}
			("burn_start" args 300)
		}
	}
	{on "burn"
		{if not burned
			{call "_burn"}
		}
	}
	{on contact
		{if effector "vehicle"
			{call "break"}
		}
	}
	{on blast
		{if volume "body"
			{if min_energy 0.5
				{call "break"}
			}
		}
	}
	{on "break"
		{if "burning"
			{spawn "camp_die" no_position offset 0 0 5}
		else
			{spawn "wood_hit_small" no_position}
		}
		{delete}
	}
	{on "pour_over"
		{if name "fuel"
			{tags add "poured"}
			{set "poured" 1}
		}
	}
}

{"camp_fire"
	{on spawn
		{call "burn"}
	}
	{on "_burn" overload
		("burn_start" args 7200)
	}
}

{"camp_fire_o"
	{on "_burn" overload}
}

{"camp_fire2"
	{on contact overload}
}

{"post_way"
	{on "hide"
		{bone hide "root"}
	}
	{on "show"
		{bone show "root"}
	}
}

{"stuff"
	{on "crush_container"
;		{impulse up 2 1 cx 0 1 cy 0 1}
		{impulse dir 2 1 up 2 1 dir 7 2 cx 0 0.5 cy 0 0.5}
	}
	{on "drop_item"
		{impulse dir 2 1 cx 0 1 cy 0 1}
	}
	{on blast_hit
		{if not linked
			{call "blast_physics"}
		}
	}
	{on bullet_hit
		{if not linked
			{impulse up 0.4 0.2 dir 1 0.5}
		}
	}
	{on "blast_physics"
		{if min_energy 0.3
			{impulse up 5 1 dir 7 2}
		}
	}
}
{"stuff no_blast_physics"
	{on "blast_physics" overload}
}

{"paratrooper"
	{on spawn
		{tags add "paratrooper_air"}
		{view hide "parachute_x"}
	}
	{on "start"
		{ani_play "flight" callback}
	}
	{on animation_end "flight"
		{tags add "paratrooper"}
		{ani_play "landing" callback}
	}
	{on animation_end "landing"
		{view show "parachute_x"}
	}
}

{"paratrooper_attach"
	{on "start"
		{animate_place "attach" "paratruper_flight"}
	}
	{on animation_end "flight"
		{with_linked_entity "attach"
			{get_off}
		}
	}
}

{"random_animation"
	{on spawn
		{call "random_animation"}
	}

	(define "random_animation"
		rand 0.1
		{ani_play "animation%0" callback}
	)
	{on "random_animation"
		{if  ("random_animation" args 0)
		else ("random_animation" args 1)
		else ("random_animation" args 2)
		else ("random_animation" args 3)
		else ("random_animation" args 4)
		else ("random_animation" args 5)
		else ("random_animation" args 6)
		else ("random_animation" args 7)
		else ("random_animation" args 8)
		else rand 0.1
			{call "delay"}
		else
			{call "random_animation"}
		}
	}

	(define "random_animation_end"
		{on animation_end "animation%0"
			{call "random_animation"}
		}
	)
	("random_animation_end" args 0)
	("random_animation_end" args 1)
	("random_animation_end" args 2)
	("random_animation_end" args 3)
	("random_animation_end" args 4)
	("random_animation_end" args 5)
	("random_animation_end" args 6)
	("random_animation_end" args 7)
	("random_animation_end" args 8)

	{on "delay"
		{call "random_animation"}
	}
}

{"random_animation with_delay"
	{on "delay" overload
		{delay 12 4
			{call "random_animation"}
		}
	}
}

{"blast_flattern"
	{on blast
		{if volume "flattern"
			{if min_energy 0.3
				{ani_play "flattern"}
			}
		}
	}
}

{"pointer"
	{on spawn
		{tags add "pointer"}
	}
	{on "show"
		{inactive 0}
		{delay 5
			{inactive 1}
		}
	}
}

{"user_guide"
	{on spawn
		{tags add "user_guide"}
		{inactive 0}
		{delay 10
			{hide 5}
		}
	}
}

{"radio_beacon"
	{on spawn
		{add_view "stop_signal" "lamp" "fx_lamp"}
		{view start "lamp"}
	}
}

{"sandstorm"
	{on spawn
		{add_view "desert2_fx" "lamp" "fx_lamp"}
		{view start "super"}
	}
}
{"big_flying_rocket"
	{on spawn
		{link_sound "fly" "weapon/shot/reactive/rocket"}
		{play_sound "fly" 1}
	}
}

{"welding"
	{on spawn
		{add_view "spark_electro02a" "welding" "root"}
		{view start "welding"}
	}
}
{"air_cloud"
	{on spawn
		{add_view "dustrun_snow_big" "air_cloud" "root"}
		{view start "air_cloud"}
	}
}
{"exp_det_dust"
	{on "explode"
		{add_view "ex_det" "detonation" "basis"}
		{view start "detonation"}
	}
}
{"flash_gun_big_entity"
	{on "explode"
		{add_view "flash_gun_big" "detonation" "basis"}
		{view start "detonation"}
	}
}
{"light_plafond_dim_entity"
	{on spawn
		{add_view "light_plafond_dim" "welding" "root"}
		{view start "welding"}
	}
}
{"light_plafond_dim_w_entity"
	{on spawn
		{add_view "light_plafond_dim_w" "welding" "root"}
		{view start "welding"}
	}
}

(define "shellhole_show_with_delay"
	{on spawn
		{view hide "shellhole"}
		{delay %0
			{view show "shellhole"}
		}
	}
)

{"shellhole_dead_moto"
	("shellhole_show_with_delay" args 0.1)
}
{"shellhole_dead_car"
	("shellhole_show_with_delay" args 0.2)
}
{"shellhole_dead_tank"
	("shellhole_show_with_delay" args 0.35)
}
  
{"flare"
	{on spawn
		{gravity 1.3}
		{tags add "flare"}
		{add_view "signal_rocket" "flare" "root"}
		{view start "flare"}
		{delay 15.5
			{delete}
		}
	}
}
{"parachute_signal_fire"
	{on spawn
		{add_view "signal_rocket2" "signal" "fx_signal"}
		{view start "signal"}
		{ani_play "flight" 0.5}
		{delay 3
			{ani_stop "flight"}
			{delay 35
				{ani_play "flight" resume callback}
			}
		}
	}
	{on animation_end "flight"
		{delay 0
			{delete}
		}
	}
}

; register engine-used props
{"steel"}
{"wood"}
{"flesh"}
{"concrete"}
{"sand"}
{"ice"}

{"collectable"}
{"nocover"}
{"shoulderbag"}
{"capacity"}
{"obstacle_ignore_height"}
{"trailer"}
{"tractor"}
{"spread_items"}
{"slow_on_crush"}
{"turn_over"}
{"no_plant"}
{"flag_slave"}

{"vision_cannon_minimum"}
{"vision_cannon_low"}
{"vision_cannon_medium"}
{"vision_cannon_high"}
{"vision_cannon_maximum"}

{"vision_vehicle_minimum"}
{"vision_vehicle_low"}
{"vision_vehicle_medium"}
{"vision_vehicle_high"}
{"vision_vehicle_maximum"}

{"round_sandbag"}
{"round_sandbag2"}
{"round_sandbag3"}
{"sandbag_round"}
{"no_minimap_view"}
{"delete_after_burn"}

{"sturmtiger"}
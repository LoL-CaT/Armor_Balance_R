{"explosion_throw_crew vehicle"
	{on "_explosion"
		{crew_throw_off up 4 1 dir 5 1 turn 0 180 forward 2 rnd_die 0.5}
	}
}

{"turret_rotator"
	{on spawn
		{set "rotate_turret" 0}
	}
	{on ik begin "turret"
		{kill_delay "rotate_turret"}
		{if not "rotate_turret"
			{play_sound "rotate_turret" 1}
			{set "rotate_turret" 1}
		}
	}
	{on ik end "turret"
		{delay 0.5 "rotate_turret"
			{stop_sound "rotate_turret"}
			{set "rotate_turret" 0}
		}
	}
}
{"turret2_rotator"
	{on spawn
		{set "rotate_turret2" 0}
	}
	{on ik begin "turret2"
		{kill_delay "rotate_turret2"}
		{if not "rotate_turret2"
			{play_sound "rotate_turret2" 1}
			{set "rotate_turret2" 1}
		}
	}
	{on ik end "turret2"
		{delay 0.5 "rotate_turret2"
			{stop_sound "rotate_turret2"}
			{set "rotate_turret2" 0}
		}
	}
}

{"turret3_rotator"
	{on spawn
		{set "rotate_turret3" 0}
	}
	{on ik begin "turret3"
		{kill_delay "rotate_turret3"}
		{if not "rotate_turret3"
			{play_sound "rotate_turret3" 1}
			{set "rotate_turret3" 1}
		}
	}
	{on ik end "turret3"
		{delay 0.5 "rotate_turret3"
			{stop_sound "rotate_turret3"}
			{set "rotate_turret3" 0}
		}
	}
}
{"turret4_rotator"
	{on spawn
		{set "rotate_turret4" 0}
	}
	{on ik begin "turret4"
		{kill_delay "rotate_turret4"}
		{if not "rotate_turret4"
			{play_sound "rotate_turret4" 1}
			{set "rotate_turret4" 1}
		}
	}
	{on ik end "turret4"
		{delay 0.5 "rotate_turret4"
			{stop_sound "rotate_turret4"}
			{set "rotate_turret4" 0}
		}
	}
}

{"turret5_rotator"
	{on spawn
		{set "rotate_turret5" 0}
	}
	{on ik begin "turret5"
		{kill_delay "rotate_turret5"}
		{if not "rotate_turret5"
			{play_sound "rotate_turret5" 1}
			{set "rotate_turret5" 1}
		}
	}
	{on ik end "turret5"
		{delay 0.5 "rotate_turret5"
			{stop_sound "rotate_turret5"}
			{set "rotate_turret5" 0}
		}
	}
}

{"vehicle"
	{inflammation_time 20}
	{on spawn
		{add_view	"stop_signal"	"stop_signal"	"FXstop1"}
		{add_view	"stop_signal"	"stop_signal"	"FXstop2"}
		
		{add_view 	"light_plafond_dim"		"redlight"			"FXlight1"}
		{add_view 	"light_plafond_dim"		"redlight"			"FXlight2"}

		{add_view 	"headlight"		"light"			"headlightL"}
		{add_view 	"headlight"		"light"			"headlightR"}
		{add_view 	"light_vehicle"	"light"			"fxlight"}

		{view hide "stop_signal"}
		{view hide "light"}
		{view hide "highlight"}

		{call "init_gun"}
		{call "add_movement_sound"}
		{call "update_moveable"}
		{call "update_lights"}
		{set "burn_fire" 0}
	}
	{on "init_gun"
		{add_view	"flash_gun_big_vehicle"	"flashbarrel3"	"Foresight3"}
		{add_view	"flash_gun_big_vehicle"	"flashbarrel4"	"Foresight4"}
		{add_view	"flash_gun_big_vehicle"	"flashbarrel5"	"Foresight5"}
		{add_view	"flash_gun_big_vehicle"	"flashbarrel6"	"Foresight6"}
		{add_view	"flash_gun_big"	"flashbarrel7"	"Foresight7"}
		{add_view	"flash_gun_big"	"flashbarrel8"	"Foresight8"}
		{add_view	"flash_gun_big"	"flashbarrel9"	"Foresight9"}
		{add_view	"flash_gun_big"	"flashbarrel10"	"Foresight10"}
		{add_view	"flash_gun_big"	"flashbarrel13"	"Foresight13"}
		{add_view	"flash_cannon_small"	"flashbarrel20"	"Foresight20"}
		{add_view	"flash_cannon_small"	"flashbarrel21"	"Foresight21"}
		{add_view	"smoke_cover-up_small"	"smoke1"	"FXsm1"}
		{add_view	"smoke_cover-up_small"	"smoke1"	"FXsm2"}
		{add_view	"smoke_cover-up_norm"	"smoke2"	"FXsm1"}
		{add_view 	"smoke_cover-up_norm"	"smoke2"	"FXsm2"}
		{add_view	"smoke_cover-up_big"	"smoke3"	"FXsm1"}
		{add_view 	"smoke_cover-up_big"	"smoke3"	"FXsm2"}
		{add_view 	"shell_mgun"		"shell3"			"fxshell3"}
		{add_view 	"shell_mgun"		"shell4"			"fxshell4"}		
	}
	
	{on "stop_on"
		{ani_stop "start"}
		{ani_play "stop"}
		{view show "stop_signal"}
		{view start "stop_signal"}
		{delay 1
			{view hide "stop_signal"}
		}
	}
	{on "exhaust_on"
		{play_sound "exhaust"}
		{view start "exhaust"}
	}
	{on "exhaust_off"
		{stop_sound "exhaust"}
		{view pause "exhaust"}
	}
	
	{on turn on
		{call "stop_on"}
		{call "exhaust_on"}
	}
	{on turn off
		{call "exhaust_off"}
	}
	{on move on
		{stop_sound "idle"}
		{stop_sound "move_end"}
		{play_sound "move" 1}
		{call "exhaust_on"}
		{ani_stop "stop"}
		{ani_play "start"}
	}
	{on move off
		{stop_sound "move"}
		{play_sound "move_end"}
		{call "exhaust_off"}
	}
	{on accelerate on
		{call "exhaust_on"}
	}
	{on accelerate off
		{call "exhaust_off"}
	}
	{on brake on
		{call "stop_on"}
	}
	{on engine on
		{kill_delay "engine_stopped"}
		{kill_delay "engine_steam_stopped"}
		{stop_sound "engine_end"}
		{play_sound "engine" 1}
		{view start "engine_steam"}
	}
	{on engine off
		{delay 2 "engine_stopped"
			{stop_sound "engine"}
			{play_sound "idle" 1}
		}
		{delay 60 "engine_stopped"
			{stop_sound "idle"}
			{play_sound "engine_end"}
		}
		{delay 12 "engine_steam_stopped"
			{view pause "engine_steam"}
		}
	}

	{on "engine fullstop"
		{view pause "exhaust"}
		{delay 0 "engine_stopped"
		        {stop_sound "idle"}
			{play_sound "engine_end"}
		}
	}
	
	{on "engine destroyed"
		{view pause "exhaust"}
		{delay 1 "engine_stopped"
			{stop_sound "idle"}
			{play_sound "engine_end"}
		}
	}

	{on break
		{if component "body"
			{call "stat_break"}
			{call "engine fullstop"}
		else component "turret"
;			{stat_notify break}
		}
		{call "update_moveable"}
		{call "break_light"}
	}
	{on repair
		{call "update_moveable"}
		{call "repair_light"}
	}

	{on "break_light"
		{if component "engine"
			{bone cut "headlightL"}
			{bone cut "headlightR"}
			{bone cut "fxlight"}
		}
	}
	{on "repair_light"
		{if component "engine"}
	}
	{on "lights_on"
		{view start "light"}
		{view show "light"}
	}
	{on "lights_off"
		{view stop "light"}
		{view hide "light"}
	}
	{on "update_lights"
		{if not sunlight
			{if operatable
				{call "lights_on"}
			else
				{call "lights_off"}
			}
		}
	}
	
; ---------- Snowman redlights -----------

	{on "redlights_on"
		{view start "redlight"}
		{view show "redlight"}
	}
	{on "redlights_off"
		{view stop "redlight"}
		{view hide "redlight"}
	}
	{on "update_redlights"
		{if operatable
			{call "redlights_on"}
		else
			{call "redlights_off"}
		}
	}
; -----------------------------------------
	
	{on operatable on
		{call "update_lights"}
	}
	{on operatable off
		{call "update_lights"}
	}

	{on "link_weapon"
		{if name "mgun"
			{add_view "flash_gun_big_vehicle"	"flashbarrel3"	"Foresight3"}
			{add_view "shell_mgun"		"shell"			"fxshell"}
		else
			{view hide	"flashbarrel3"}
			{view pause	"flashbarrel3"}
			{view pause "shell"}
		}
		{if name "mgun1"
			{add_view "flash_gun_big"	"flashbarrel4"	"Foresight4"}
			{add_view "shell_mgun"		"shell"			"fxshell"}
		}
			
		{if name "mgun2"
			{add_view "flash_gun_big"	"flashbarrel5"	"Foresight5"}
			{add_view "shell_mgun"		"shell"			"fxshell"}
		}
		{if name "mgun3"
			{add_view "flash_gun_big"	"flashbarrel6"	"Foresight6"}
			{add_view "shell_mgun"		"shell"			"fxshell"}
		}
		{if name "mgun4"
			{add_view "flash_gun_big"	"flashbarrel8"	"Foresight8"}
			{add_view "shell_mgun"		"shell"			"fxshell"}
		}
		{if name "mgun5"
			{add_view "flash_gun_big"	"flashbarrel9"	"Foresight9"}
			{add_view "shell_mgun"		"shell"			"fxshell"}
		}
		{if name "mgun6"
			{add_view "flash_gun_big"	"flashbarrel10"	"Foresight10"}
			{add_view "shell_mgun"		"shell"			"fxshell"}
		}
		{if name "mgun7"
			{add_view "flash_gun_big"	"flashbarrel7"	"Foresight7"}
			{add_view "shell_mgun"		"shell"			"fxshell"}
		}		
	}
	{on fire "mgun"
		{view start "flashbarrel3"}
		{ani_play "fire_mgun"}
		{view start "shell"}
		{delay 0.1 "shell"
			{view pause "shell"}
		}
	}
	{on fire "mgun1"
		{view start "flashbarrel4"}
	}
	{on fire "mgun2"
		{view start "flashbarrel5"}
	}
	{on fire "mgun3"
		{view start "flashbarrel6"}
		{ani_play "fire_mgun3"}
		{view start "shell3"}
		{delay 0.1 "shell3"
			{view pause "shell3"}
		}
	}
	{on fire "mgun4"
		{view start "flashbarrel8"}
		{ani_play "fire_mgun4"}
		{view start "shell4"}
		{delay 0.1 "shell4"
			{view pause "shell4"}
		}
	}
	{on fire "mgun5"
		{view start "flashbarrel9"}
	}
	{on fire "mgun6"
		{view start "flashbarrel10"}
	}
	{on fire "mgun7"
		{view start "flashbarrel7"}
	}	
	{on fire "mgun17"
		{view start "flashbarrel20"}
	}
	{on fire "mgun18"
		{view start "flashbarrel21"}
	}
	{on contact
		{if volume "sticky"
			{if effector "grenade"
				{if not effector "contact"
					{call "grenade_stick"}
				}
			}
		}
		{if not impregnable
			{if effector_velocity 3
				{if effector "airborne"
					{call "contact_airborne"}
				else effector "piece_big_stone"
					{component break}
				}
			}
		}
	}
	{on "grenade_stick"
		{with_effector
			{link_grenade_to_nearest_human}
		}
	}
	{on "contact_airborne"
		{if not "contact_airborne_first"
			{set "contact_airborne_first" 1}
				{if rand 0.4
			        {component break}
				}
			{delay 0.1
				{set "contact_airborne_second" 1}
				{delay 0.1
					{set "contact_airborne_first" 0}
					{set "contact_airborne_second" 0}
				}
			}
		else "contact_airborne_second"
;			{call "explosion"}
		}
	}

	{on "update_moveable"
		{if work "body"
			{view stop "smoke4"}
		else
			{view start "smoke4"}
		}
		{if work "engine"
			{call "check_work_mover"}
		else
			{chassis_work 0}
		}
	}
	{on "check_work_mover"
		{if work "mover"
			{chassis_work 1}
		else
			{chassis_work 0}
		}
	}

	{on "explosion"
		{if not able "exploded"
			{damage_report "body" "component/empty"}			
			{damage_report "engine" "component/empty"}
			{damage_report "trackright" "component/empty"}			
			{damage_report "trackleft" "component/empty"}
			{damage_report "turret" "component/empty"}			
			{damage_report "gun" "component/empty"}
			{able "exploded" 1}
			{call "_explosion"}
			{stop_sound "idle"}
		}
	}
	(define "ammunition_loads2"
		{if explosive_amount (* %ammo 2.00)	;>200%
			{tags add "ammo_overload"}{tags add "instant_explosion"}
		else explosive_amount (* %ammo 1.75)	;>175%
			{tags add "ammo_overload"}{tags add "instant_explosion"}
		else explosive_amount (* %ammo 1.50)	;>150%
			{tags add "ammo_overload"}{tags add "instant_explosion"}
		else explosive_amount (* %ammo 1.25)	;>125%
			{tags add "ammo_overload"}
		else explosive_amount %ammo		;>100%
			{tags add "ammo_overload"}
		else explosive_amount (* %ammo 0.9)	;>90%
			{if rand 0.5{tags add "ammo_overload"}
			else{tags add "ammo_normal_load"}}
		else explosive_amount (* %ammo 0.75)	;>75%
			{tags add "ammo_normal_load"}
		else explosive_amount (* %ammo 0.5)	;>50%
			{tags add "ammo_normal_load"}
		else explosive_amount (* %ammo 0.25)	;>25%
		}
	)
	{on "_explosion"
		{if tagged "light_tank"
			("ammunition_loads2" ammo(250))
		else tagged "medium_tank"
			("ammunition_loads2" ammo(290))
		else tagged "heavy_tank"
			("ammunition_loads2" ammo(340))
		}
;		{call "__explosion"}
;		{call "stat_break"}
		{call "break_all"}
		{stop_sound "move"}
		{stop_sound "move_end"}
		{stop_sound "engine"}
		{stop_sound "engine_end"}
		{stop_sound "exhaust"}
		{stop_sound "idle"}
		{view stop "fire1"}
		{view stop "fire2"}
		{tags add "destroyed"}
		{kick_entity_manager}
		{call "explosion_sound"}

		{if not terrain_fx "bridge"
			{if not under_water
				{call "spawn_shellhole"}
			}
		}

		{delay_ex 0
			{set "no_burn_volumes" 1}
			{set_skeleton "_xx" sync}
			{ani_play "death"}
			{call "cut_parts"}
		}
	}
	{on "destroy_energy_overload"
		{call "break_all"}
		{stop_sound "move"}
		{stop_sound "move_end"}
		{stop_sound "engine"}
		{stop_sound "engine_end"}
		{stop_sound "exhaust"}
		{call "engine fullstop"}
		{view stop "fire1"}
		{view stop "fire2"}
		{tags add "destroyed"}
		{kick_entity_manager}
		{if "crush"
			{start_sound "crush/medium/vehicle"}
		else
			{start_sound "crush/big/vehicle"}
		}
		{if not terrain_fx "bridge"
			{if not under_water
				{call "spawn_shellhole"}
			}
		}
		{delay_ex 0
			{set "no_burn_volumes" 1}
			{set_skeleton "_xx" sync}
			{ani_play "death"}
			{call "cut_parts"}
		}
	}	
	{on "explosion_blastwave"
		{blastwave c4 3 r0 3 r1 8}
	}
	{on "explosion_sound"
		{if "crush"
			{start_sound "crush/medium/vehicle"}
		else
			{call "explosion_blastwave"}
			{start_sound "crush/big/vehicle"}
		}
	}

	{on "break_all"
		{kill_crew}
		{drop_orders}
		{components destroy}
		{reset_manual_control}
		{able select 0}
		{able repaired 0}
		{unlink_trailer}
		{clear_inventory}
		{call "engine fullstop"}		
	}
	
	{on "kill_crew"
		{kill_crew}
	}
	
	{on "_burn"
        {if not tagged "burned"
			{if not able "exploded"
				{damage_report "engine" "component/burn_engine"}
            	{add_view		"smoke_dead_norm"	"burn_fire"		"FXfire1"}
				{view start "burn_fire"}
				{burn time 12}
				{tags add "burned"}
				{add_view "smoke_black" "burn_fire" "FXfire1"}
				{play_sound "flame" 1}
				{view start "burn_fire"}
				{set "burn_fire" 1}
                {call "stat_break"}
				{delay 4 2
                	{call "check_burn_emit"}
                }
                ;{explosive 1}
				{delay 10 2
						{call "mp_destroy"}
						{start_sound "crush/medium/metal"}
				}
				{delay 10 2
					{components "engine" break}
					{start_sound "crush/medium/metal"}
                    	{delay 5 4
						{call "mp_destroy"}
					}
				}
				{delay 12
					{explosive 0}
					{view stop "burn_fire"}
					{stop_sound "flame"}
					{set "burn_fire" 0}
					{call "check_burn_emit"}
					{if rand 0.5
						{call "explosion"}
					else
						{able "burning" 0}
					}
				}
			}
    	}
	}

	{on "burn_emit"
		{if not able "burning"
			{able "burning" 1}
			{set_heater}
            {reset_manual_control}
		}
	}

	{on "burn_volume"
		{log "burn_volume"}
		{if not burned
			{if volume "engine"
				{log "burn_engine"}
				{call "_burn"}
			else volume "engine1"
				{log "burn_engine"}				
				{call "_burn"}
			else
				{burn volume fx "smoke_dead_small" time 5 1 fake even_law}
			}
		}
	}
	{on "stat_break"	
		{if not tagged "body_break"
			{if not "broken"
				{set "broken" 1}
				{if "burn_fire"
					{stat_notify break burned}
			else
					{stat_notify break}
				}
			}
		}		
	}

	{on "leave_unit"
		{if work "body"
			{if not tagged "abandoned"
				{unlink_trailer}
				{reset_manual_control}
				
				{if not tagged "emit_label"		
					{damage_report "body" "component/leave_unit"}
					{tags add "emit_label"}
					{crew_emit}
				}
				{delay 1		
					{crew_emit}
				}
				{delay 2		
					{crew_emit}
				}
				{delay 3		
					{crew_emit}
				}
				;{call "burn_emit"}
				
				{delay 4	{if operatable {tags remove "emit_label"}}}
				{delay 6	{if operatable {tags remove "emit_label"}}}
				{delay 8	{if operatable {tags remove "emit_label"}}}
				{delay 10	{if operatable {tags remove "emit_label"}}}
				{delay 12	{if operatable {tags remove "emit_label"}}}
				{delay 14	{if operatable {tags remove "emit_label"}}}
	
				{delay 15
					{if not operatable
						{tags add "abandoned"}
						{set "broken" 1}
						{able select 0}
						{able repaired 0}
						{explosive 1}
						{player -1}
						{stat_notify leave}
						{kick_entity_manager}
						{explosive 1}
						{damage_report "body" "component/empty"}
						{damage_report "trackright" "component/empty"}
						{damage_report "trackleft" "component/empty"}
						{damage_report "gun" "component/empty"}
						{damage_report "turret" "component/empty"}
						{damage_report "engine" "component/empty"}
						
						{delay 3 1					
							{explosive 0}
							{tags add "destroyed"}
							{call "explosion"}
						}
					}
				}			
			}
		}
	}

	(define "terrain_fx"
		{on terrain_fx %0 enter
			{view start "on_%1"}
			{view start "on_%1_time_short"}
			{delay 0.1
				{view pause "on_%1_time_short"}
			}
		}
		{on terrain_fx %0 leave
			{view pause "on_%1"}
		}
	)
	("terrain_fx" args "ground"			ground)
	("terrain_fx" args "sand"			sand)
	("terrain_fx" args "grass" 			grass)
	("terrain_fx" args "water" 			water)
	("terrain_fx" args "shallow_water" 	puddle)
	("terrain_fx" args "puddle"			puddle)
	("terrain_fx" args "mud"			mud)
	("terrain_fx" args "country_road"	country_road)
	("terrain_fx" args "snow"			snow)

	{on "explosion_delete"
		{set "delete_parts" 1}
		{call "explosion"}
		{delay 20
			{hide 3}
		}
	}
}

{"emit_on_sink vehicle"
	{on operatable on
		{delay 0.3 "start_check_sinking"
			{call "check_sinking"}
		}
	}
	{on operatable off
		{kill_delay "start_check_sinking"}
		{kill_delay "check_sinking"}
	}
	(define "sink_terrain"
		{on terrain_pp "%0" enter
			{reset_manual_control}
			{able "sinking" 1}
		}
		{on terrain_pp "%0" leave
			{reset_manual_control}
;			{able "sinking" 0} ;do not use this because of leaving terrain on stop
		}
	)
;	("sink_terrain" args water)
	("sink_terrain" args swamp)
	{on "check_sinking"
		{call "check_water_level"}
		{if able "sinking"
			{reset_manual_control}
		}
		{delay 0.5 "check_sinking"
			{call "check_sinking"}
		}
	}
	{on "check_water_level"
		{if water_level 1.2
			{able "sinking" 1}
		}
	}
	{on "crew_emit"
		{crew_emit}
	}
}

{"with_gun vehicle"
	{on spawn
		{call "update_gun"}
		{call "update_gun2"}
		{call "update_gun3"}
	}
	{on break
		{if component "gun"
			{call "update_gun"}
            {tags add "gun_brake"}
		}
		{if component "gun2"
			{call "update_gun2"}
		}
		{if component "gun3"
			{call "update_gun3"}
		}
	}
	{on repair
		{if component "gun"
			{call "update_gun"}
            {tags remove "gun_brake"}
		}
		{if component "gun2"
			{call "update_gun2"}
		}
		{if component "gun3"
			{call "update_gun3"}
		}
	}
	{on "update_gun"
		{if work "gun"
			{weapon_work "gun" 1}
		 else
			{weapon_work "gun" 0}
		}
	}
	{on "update_gun2"
		{if work "gun2"
			{weapon_work "gun2" 1}
		 else
			{weapon_work "gun2" 0}
		}
	}
	{on "update_gun3"
		{if work "gun3"
			{weapon_work "gun3" 1}
		 else
			{weapon_work "gun3" 0}
		}
	}
}

{"open_with_land"
	{on "open"
		{ani_stop "drift"}
		{ani_play "dooropen" callback}
		{land on}
		{chassis_work 0}
		{physics_work 0}
		{area enable}
	}
	{on "close"
		{ani_play "dooropen" -1 callback}
		{ani_play "drift" loop}
		{land off}
		{chassis_work 1}
		{physics_work 1}
		{area disable}
	}
	{on animation_end "dooropen"
		{update_visibility_patch}
	}
}

{"open_without_land"
	{on "open"
		{ani_stop "drift"}
		{ani_play "dooropen" callback}
	}
	{on "close"
		{ani_play "dooropen" -1 callback}
		{ani_play "drift" loop}
	}
	{on animation_end "dooropen"
		{update_visibility_patch}
	}
}

{"amphibia vehicle"
	{on spawn
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center1"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center2"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center3"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center4"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center5"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center6"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center7"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center8"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center9"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_small_center10"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_norm_front1"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_norm_front2"}
		{add_view	"wash_ship_stop"	"on_stead"	"FX_bulb_norm_engine1"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center1"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center2"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center3"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center4"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center5"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center6"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center7"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center8"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center9"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_center10"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_back1"}
		{add_view	"wash_ship_motion"	"on_move"	"FX_bulb_small_back2"}
		{add_view	"wash_front_small"	"on_move"	"FX_bulb_small_front1"}
		{add_view	"wash_front_small"	"on_move"	"FX_bulb_small_front2"}
		{add_view	"wash_front_norm"	"on_move"	"FX_bulb_norm_front1"}
		{add_view	"wash_front_norm"	"on_move"	"FX_bulb_norm_front2"}
		{add_view	"wash_ship_motion_norm"	"on_move"	"FX_bulb_norm_front1"}
		{add_view	"wash_ship_motion_norm"	"on_move"	"FX_bulb_norm_front2"}
		{add_view	"wash_engine_small"	"on_move"	"FX_bulb_small_engine1"}
		{add_view	"wash_engine_norm"	"on_move"	"FX_bulb_norm_engine1"}
	}
	{on terrain_pp "deep_water" enter
		{set "in_water" 1}
		{call "update_bulbs"}
	}
	{on terrain_pp "water" enter
		{set "in_water" 1}
		{call "update_bulbs"}
	}
	{on terrain_pp "shallow_water" enter
		{set "in_water" 1}
		{call "update_bulbs"}
	}
	{on terrain_pp "shallow_water" leave
		{set "in_water" 0}
		{call "update_bulbs"}
	}
	{on "update_bulbs"
		{if "in_water"
			{if not velocity 0.001
				{view start "on_stead"}
				{view pause "on_move"}
			else
				{view start "on_move"}
				{view pause "on_stead"}
			}
		else
			{view pause "on_stead"}
			{view pause "on_move"}
		}
	}
	{on "check_water_level" overload}
	{on move on
		{call "update_bulbs"}
	}
	{on move off
		{call "update_bulbs"}
	}
}

;##### Engineer_Den "mnogobashenny zvizdec" #####
{"flamethrower_mgun"
	{on spawn
		{add_view "tankflamer_fire" "flame" "foresight3"}
		{add_view "flamer_fire_barrel" "fire" "foresight3"}
		{view show	"fire"}
	}
	{on operatable on	
		{view start	"fire"}						
	}	
	{on operatable off		
		{view stop	"fire"}		
	}
	{on fire "mgun" overload
		{view start	"flame"}
		{kill_delay "flame"}
		{delay 0.5 "flame"
			{view pause "flame"}
		}
	}
	{on "_explosion"
		{view stop "fire"}
		{view stop "flame"}
		{fire radius 6 time 0.5 heating 100 effector}
	}
}
{"flamethrower_mgun1"
	{on spawn
		{add_view "tankflamer_fire" "flame1" "foresight4"}
		{add_view "flamer_fire_barrel" "fire1" "foresight4"}
		{view show	"fire1"}
	}
	{on operatable on	
		{view start	"fire1"}						
	}	
	{on operatable off		
		{view stop	"fire1"}		
	}
	{on fire "mgun1" overload
		{view start	"flame1"}
		{kill_delay "flame1"}
		{delay 0.5 "flame1"
			{view pause "flame1"}
		}
	}
	{on "_explosion"
		{view stop "fire1"}
		{view stop "flame1"}
		{fire radius 6 time 0.5 heating 100 effector}
	}
}
{"flamethrower_mgun2"
	{on spawn
		{add_view "tankflamer_fire" "flame2" "foresight3"}
		{add_view "flamer_fire_barrel" "fire2" "foresight3"}
		{view show	"fire2"}
	}
	{on operatable on	
		{view start	"fire2"}						
	}	
	{on operatable off		
		{view stop	"fire2"}		
	}
	{on fire "mgun" overload
		{view start	"flame2"}
		{kill_delay "flame2"}
		{delay 0.5 "flame2"
			{view pause "flame2"}
		}
	}
	{on "_explosion"
		{view stop "fire2"}
		{view stop "flame2"}
		{fire radius 6 time 0.5 heating 100 effector}
	}
}
{"dymopusk"
	{on "init_gun"
		{call	"smoke_link"}
		{link_sound "smokecaller" "detonation/grenade_smoke"}
	}
	{on "smoke_link"
		{add_view	"smoke_cover-up_small"	"smoke10"	"FXfire5"}
		{add_view	"smoke_cover-up_small"	"smoke11"	"FXfire6"}
		{add_view	"smoke_cover-up_norm"	"smoke12"	"FXfire5"}
		{add_view	"smoke_cover-up_norm"	"smoke13"	"FXfire6"}
		{add_view	"smoke_cover-up_big"	"smoke14"	"FXfire5"}
		{add_view	"smoke_cover-up_big"	"smoke15"	"FXfire6"}
	}
	{on fire "mgun16"
		{play_sound "smokecaller" 1}
		{tags add "smoke"}
		{view start "smoke10"}
		{view start "smoke11"}
		{volumes "smoke10" enable visible}
		{volumes "smoke11" enable visible}
		{update_visibility_patch}
		{delay 1
			{view stop "smoke10"}
			{view stop "smoke11"}
			{view start "smoke12"}
			{view start "smoke13"}
			{volumes "smoke10" disable visible}
			{volumes "smoke11" disable visible}
			{volumes "smoke12" enable visible}
			{volumes "smoke13" enable visible}
			{update_visibility_patch}
		}
		{delay 3
			{view start "smoke14"}
			{view start "smoke15"}
			{volumes "smoke12" disable visible}
			{volumes "smoke13" disable visible}
			{volumes "smoke14" enable visible}
			{volumes "smoke15" enable visible}
			{update_visibility_patch}
		}
		{delay 35
			{volumes "smoke14" disable visible}
			{volumes "smoke15" disable visible}
			{view stop "smoke12"}
			{view stop "smoke13"}
			{view stop "smoke14"}
			{view stop "smoke15"}
			{update_visibility_patch}
			{stop_sound "smokecaller"}
			{call "smoke_link"}
		}
	}
}
;########################################################

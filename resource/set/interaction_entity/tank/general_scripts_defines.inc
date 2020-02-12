	{on spawn
		{link_sound "flame"			"fire/big"}
		{link_sound "move"			"vehicle/tracks/trackclank"}
		{link_sound "heavy_move"	"vehicle/tracks/heavy"}

		{if not rain
			{add_view	"dustrun_big"			"on_ground"				"FXtraceR1"}
			{add_view	"dustrun_big"			"on_ground"				"FXtraceL1"}
			{add_view	"dustrun_small"			"on_grass"				"FXtraceR1"}
			{add_view	"dustrun_small"			"on_grass"				"FXtraceL1"}
			{add_view	"dustrun_sand_big" 		"on_sand"				"FXtraceR1"}
			{add_view	"dustrun_sand_big" 		"on_sand"				"FXtraceL1"}
			{add_view	"dustrun_snow_big" 		"on_snow"				"FXtraceR1"}
			{add_view	"dustrun_snow_big" 		"on_snow"				"FXtraceL1"}
			{add_view	"dustrun_small"			"on_country_road"		"FXtraceR1"}
			{add_view	"dustrun_small"			"on_country_road"		"FXtraceL1"}
		else
			{add_view	"engine_steam"			"engine_steam"			"FXfire1"}
        }

		{add_view	"tank_grit_small"		"on_ground"				"FXtraceR2"}
		{add_view	"tank_grit_small"		"on_ground"				"FXtraceL2"}
		{add_view	"tank_grit_big"			"on_ground_time_short"	"FXtraceR2"}
		{add_view	"tank_grit_big"			"on_ground_time_short"	"FXtraceL2"}

		{add_view	"tank_grit_small"		"on_grass"				"FXtraceR2"}
		{add_view	"tank_grit_small"		"on_grass"				"FXtraceL2"}
		{add_view	"tank_grit_big"			"on_grass_time_short"	"FXtraceR2"}
		{add_view	"tank_grit_big"			"on_grass_time_short"	"FXtraceL2"}

		{add_view	"drops_water"			"on_water"				"FXtraceR1"}
		{add_view	"drops_water"			"on_water"				"FXtraceL1"}
		{add_view	"tank_grit_big_mud"		"on_mud"				"FXtraceR2"}
		{add_view	"tank_grit_big_mud"		"on_mud"				"FXtraceL2"}
		{add_view	"tank_grit_big_snow"	"on_snow"				"FXtraceR2"}
		{add_view	"tank_grit_big_snow"	"on_snow"				"FXtraceL2"}
		{add_view	"drops_water_moto"		"on_puddle"				"FXtraceR1"}
		{add_view	"drops_water_moto"		"on_puddle"				"FXtraceL1"}
		{add_view	"tank_grit_small_w"		"on_puddle"				"FXtraceR2"}
		{add_view	"tank_grit_small_w"		"on_puddle"				"FXtraceL2"}

		{add_view	"powdersmoke_big"		"flashbarrel1s"			"Foresight1"}
		{add_view 	"flash_zenit"			"flashbarrel2s"			"foresight2"}
		
;///////Engineer_Den + //////////////// для пушек №2 и 3
		{add_view	"flash_cannon_small"		"flashbarrel11"		"Foresight11"}
		{add_view	"powdersmoke_big"		"flashbarrel11s"	"Foresight11"}
		
		{add_view	"flash_cannon_small"		"flashbarrel12"		"Foresight12"}
		{add_view	"powdersmoke_big"		"flashbarrel12s"	"Foresight12"}
;///////Engineer_Den - ////////////////
		{add_view	"smoke_white_steam"		"smoke1"				"FXfire1"}
		{add_view	"smoke_black"			"smoke2"				"FXfire2"}
		{add_view	"smoke_black"			"smoke3"				"FXfire2"}
		{add_view	"smoke_black"			"smoke4"				"FXfire1"}
		{add_view	"smoke_dead_small2"		"smoke4_1"				"FXfire3"}
		{add_view	"smoke_dead_small2a"	"smoke4_2"				"FXfire3"}
;///////Engineer_Den + //////////////// башни 2...5
		{add_view	"smoke_black"			       "smoke5"				"FXfire32"}
		{add_view	"smoke_black"			         		"smoke6"				"FXfire22"}
		{add_view	"smoke_black"					"smoke7"				"FXfire22"}
		{add_view	"smoke_black"			       "smoke8"				"FXfire32"}
		{add_view	"smoke_black"				"smoke9"				"FXfire42"}
		{add_view	"smoke_black"					"smoke10"			"FXfire52"}
		{add_view	"smoke_black"					"smoke11"			"FXfire52"}
		{add_view	"smoke_black"				"smoke12"			"FXfire42"}
;///////Engineer_Den - ////////////////		
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmoke1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmoke2"}
		{set "smoke3" 0}
		{set "smoke4" 0}
;///////Engineer_Den + ////////////////
		{set "smoke5" 0};башня-3-2
		{set "smoke6" 0};башня-2-2
		{set "smoke7" 0};башня-2-3
		{set "smoke8" 0};башня-3-3
		{set "smoke9" 0};башня-4-2
		{set "smoke10" 0};башня-5-2
		{set "smoke11" 0};башня-5-3
		{set "smoke12" 0};башня-4-3
;///////Engineer_Den - ////////////////
		{call "update_hatch_on_spawn"}
	}

	{on "add_movement_sound"
		{link_sound "engine"		"vehicle/engine/tank"}
		{link_sound "engine_end"	"vehicle/engine/tank_end"}
		{link_sound "exhaust"		"vehicle/engine/tank_up"}

	}

	{on "gunner_hatch_open"
		{ani_wind "open" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
			else
				{ani_play "open" +1.0 resume}
			}
		else
			{if crew_in_place "gunner2020"
				{call "gunner_hatch_open"}
			else
				{if %wind
					{ani_wind "open" begin}
				else
					{ani_play "open" -1.0 resume}
				}
			}

		}
	)
	{on "update_hatch_on_spawn"
		("update_hatch" wind(true))
	}
	(define "update_hatch_event"
		{on %event
			("update_hatch" wind(false))
		}
	)
	("update_hatch_event" event(operatable on))
	("update_hatch_event" event(operatable off))
	("update_hatch_event" event(crew in))
	("update_hatch_event" event(crew out))
        
	{on "emit_on_hit"
		{call "burn_emit"}
		{able select 0}
		
		{view start "smoke4_1"}
		{set "smoke4_1" 1}
		
		{delay 8
			{view stop "smoke4_1"}
			{set "smoke4_1" 0} 	
			{if not "burn_fire"
				{able "burning" 0}
				{able repaired 1}			
			}
		}
		{delay 11
			{able select 1}
			{if not "burn_fire"
				{able "burning" 0}
				{able repaired 1}			
			}
		}
		{delay 20
			{if not "burn_fire"
				{able "burning" 0}			
			}		
		}
	}
        
    {on "emit_on_rocketlauncher"
		{if rand 0.5
			{call "burn_emit"}
		else
			{crew_emit}
		}
		{able select 0}	
		{delay 4
			{if not "burn_fire"
				{able select 1}
				{able "burning" 0}
				{able repaired 1}			
			}
		}
		{burn fx "smoke_dead_tank2" fake}
	}
	
	{on "stat_body_break"
		{if not broken
			{stat_notify break}
			{tags add "body_break"}	
		}	
	}
        
    (define "cut_shield_part"
        {if component %0
			{delay_ex 0.11
                {tear "piece_medium_steel" bone %0
					{impulse up 2 1 dir 2 1}
				}
			}
        }
	)
        
    (define "gun_hit"
		{if volume "gun"
			{if rand %rand
                {if work "gun"
					{components "gun" break}
					{damage_report "gun" "component/gun_broken"}
                }
			}
		}
	)
;///////Engineer_Den + ////////////////
	(define "gun2_hit"
		{if volume "gun2"
			{if rand %rand
				{components "gun2" break}
				{damage_report "gun2" "component/gun2_broken"}		
			}
		}
	)
	(define "gun3_hit"
		{if volume "gun3"
			{if rand %rand
				{components "gun3" break}
				{damage_report "gun3" "component/gun3_broken"}		
			}
		}
	)
;///////Engineer_Den - ////////////////
	
	(define "track_hit"
		{if hit_side front
 			{if rand %max_rand
				{if volume "trackleft"
                    {if work "trackleft"
						{components "trackleft" break}	
						{damage_report "trackleft" "component/track_broken"}
                    }				
				else volume "trackright"
                    {if work "trackright"
						{components "trackright" break}	
						{damage_report "trackright" "component/track_broken"}
                    }			
				}
			}
		else hit_side back
				{if rand %max_rand
					{if volume "trackleft"
                        {if work "trackleft"
							{components "trackleft" break}	
							{damage_report "trackleft" "component/track_broken"}
                        }
					else volume "trackright"
                        {if work "trackright"
							{components "trackright" break}	
							{damage_report "trackright" "component/track_broken"}
                        }			
					}				
				}
		else rand %min_rand
			{if volume "trackleft"
                {if work "trackleft"
					{components "trackleft" break}
					{damage_report "trackleft" "component/track_broken"}
                }
			else volume "trackright"
                {if work "trackright"
					{components "trackright" break}	
					{burn fx "smoke_dead_tank2" fake}
					{damage_report "trackright" "component/track_broken"}
                }
			}				
		}
	)
	{on "mp_destroy"
		{if not tagged "destroyed"
			{damage_report "body" "component/body_broken"}
			{if not tagged "body_break"
				{components "body" break}
				{call "stat_break"}
			}
		}
		
		{delay 2
			{tags add "destroyed"}
			{kick_entity_manager}
		}

		{if rand 0.5	
			("cut_shield_part" args "shieldl4")
			("cut_shield_part" args "shieldl5")
			("cut_shield_part" args "shieldr2")
			("cut_shield_part" args "shieldr3")
		}
		{if rand 0.5	
			("cut_shield_part" args "shieldl2")
			("cut_shield_part" args "shieldl3")
			("cut_shield_part" args "shieldr4")
			("cut_shield_part" args "shieldr1")
		}
		{call "check_burn_emit"}
		{delay 2.3
			{view start "smoke4_1"}
		}
		{delay 30
  			{view stop "smoke4_1"}
  		}
											
		{reset_manual_control}
		{able select 0}
		{able repaired 0}
		{unlink_trailer}
	}
	{on "upside_down"
		{reset_manual_control}
		{able select 0}
		{unlink_trailer}
		{if not burned
			{call "_burn"}
			{able repaired 0}
		}
	}

	{on "_explosion"
		{add_view "smoke_dead_norm" "deathfx" "FXfire1"}
		{spawn "tank_die" "Basis"}
	}
	{on "spawn_shellhole"
		{spawn "shellhole_dead_tank2" "Basis"}
	}
	{on "cut_parts"
		{spawn "tank_die" "Basis"}
		{add_view "smoke_black_big2" "deathfx" "basis"}
		{view start "deathfx"}
		(define "cut_part"
			{if rand 0.5
				{tear "piece_medium_steel" bone %0
					{impulse up 8 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
					{delay_effect 20 5 "stop"}
				}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "part5")
		("cut_part" args "part6")
;///////Engineer_Den + ////////////////	
		("cut_part" args "part7")
		("cut_part" args "part8")
		("cut_part" args "part9")
		("cut_part" args "part10")
		("cut_part" args "part11")
		("cut_part" args "part12")
		("cut_part" args "part13")
		("cut_part" args "part14")
		("cut_part" args "part15")
		("cut_part" args "part16")
		("cut_part" args "part17")
		("cut_part" args "part18")
		("cut_part" args "part19")
		("cut_part" args "part20")
;///////Engineer_Den - ////////////////			
		{delay 25 5	{view stop "deathfx"}}
	}

	;ADDED BY TY----------------------------------------------------------
	{on "crew_emit_immobile"
		{if not user_control
			{if not work "trackright"
				{delay 1 	
					{call "crew_emit_3times"}
				}		
			}
			{if not work "trackleft"
				{delay 1 	
					{call "crew_emit_3times"}
				}	
			}
			{if not work "engine"
				{delay 1	
					{call "crew_emit_3times"}
				}		
			}
		}
	}
	;ADDED BY TY----------------------------------------------------------
	{on "crew_emit_turret"
		{if not user_control
			{if not work "turret"
				{delay 1	
					{call "crew_emit_3times"}
				}
			}
			{if not work "gun"
				{delay 1	
					{call "crew_emit_3times"}
				}		
			}
		}
	}
	;ADDED BY TY----------------------------------------------------------
	{on "crew_emit_delayturret"	
		{if not user_control
			{delay 240	
				{if not work "turret"	
					{call "crew_emit_3times"}
				}
			}	
			{delay 240	
				{if not work "gun"	
					{call "crew_emit_3times"}
				}		
			}
		}
	}
	;ADDED BY TY----------------------------------------------------------
	{on "crew_emit_gunturret"	
		{if not user_control
			{delay 1	
				{if not work "turret"	
					{call "crew_emit_3times"}
				}
			}	
		}
	}
	;ADDED BY TY----------------------------------------------------------
	{on "crew_emit_gun"	
		{if not user_control	
			{delay 1	
				{if not work "gun"	
					{call "crew_emit_3times"}
				}		
			}
		}
	}
	;ADDED BY TY----------------------------------------------------------
	{on "crew_emit_delayengine"
		{if not user_control	
			{delay 100 	
				{if not work "engine"
					{call "crew_emit_3times"}
				}
			}
		}			
	}
	;ADDED BY TY----------------------------------------------------------
	{on "crew_emit_3times"
		{crew_emit}
		{delay 3 
			{crew_emit}
		}
		{delay 5 
			{crew_emit}
		}
		{delay 7 
			{crew_emit}
		}
	}
	;---------------------------------------------------------------------

	{on "check_burn_emit"
		{if not "burn_fire"
			{if not "smoke3"
				{if not "smoke4"
					{able "burning" 0}
				else
                    {delay 5
						{call "burn_emit"}
                    }
				}
			else
                {delay 5
					{call "burn_emit"}
                }
			}
		else
            {delay
				{call "burn_emit"}
            }
		}
	}
	{on fire "gun"
        {view start "flashbarrel1"}
		{view start "flashbarrel1s"}
		{ani_play "fire"}
		{delay 0.8
			{view pause "flashbarrel1"}
		}
		{delay 0.2
			{view pause "flashbarrel1s"}
		}
	}
	{on fire "gun2"
        {view start "flashbarrel11"}
		{view start "flashbarrel11s"}
		{ani_play "fire2"}
		{delay 0.8
			{view pause "flashbarrel11"}
		}
		{delay 0.2
			{view pause "flashbarrel11s"}
		}
	}
;///////Engineer_Den + ////////////////	
	{on fire "gun3"
        {view start "flashbarrel12"}
		{view start "flashbarrel12s"}
		{ani_play "fire3"}
		{delay 0.8
			{view pause "flashbarrel12"}
		}
		{delay 0.2
			{view pause "flashbarrel12s"}
		}
	}
;///////Engineer_Den - ////////////////		
    {on "criticalhit" overload
		{if component "body"
			{if not hit_side front
        		{components "engine" break}
        	}
        else component "turret"
			{components "gun" break}
			
;///////Engineer_Den + ////////////////	
		else component "turret4"
			{components "gun2" break}
		else component "turret5"
			{components "gun3" break}
;///////Engineer_Den - ////////////////				
        }
    }
	{on "explosive_broken"
		{if not work "body"
			{delay 0.1 0.1
				{call "explosion"}
				{damage_report "body" "component/empty"}
				{damage_report "engine" "component/empty"}
				{damage_report "trackright" "component/empty"}
				{damage_report "trackleft" "component/empty"}
				{damage_report "turret" "component/empty"}
				{damage_report "gun" "component/empty"}
			}
        }
	}
    {on "burn_hatch"
		{add_view	"smoke_dead_norm2"	"smoke_hatch"	"FXfire3"}
		{view start "smoke_hatch"}
    }
    {on "burn_engine"
		{add_view	"fire_napalm"	"fire_napalm"	"engine"}
		{view start "fire_napalm"}
    }
    {on "rand_burn"
		{if rand 0.2
			{if not burned
				{burn time 17}
				{delay 1
					{call "_burn"}
				}
			}
		}
	}
	{on "burn_crew_mp"
		{if rand 0.6 {kill_crew "gunner"}}
		{if rand 0.6 {kill_crew "charger"}}
		{if rand 0.6 {kill_crew "commander"}}
		{if rand 0.6 {kill_crew "driver"}}
;///////Engineer_Den + ////////////////	
		{if rand 0.6 {kill_crew "radist"}}
		{if rand 0.4 {kill_crew "gunner3"}}
		{if rand 0.4 {kill_crew "gunner4"}}
		{if rand 0.5 {kill_crew "gunner5"}}
		{if rand 0.5 {kill_crew "charger5"}}
		{if rand 0.5 {kill_crew "gunner6"}}
		{if rand 0.5 {kill_crew "charger6"}}
;///////Engineer_Den - ////////////////			
	}
    (define "burn_by_engine"
		{on "burn_by_engine"
        	{if not tagged "burned"
        		{if rand %0
        			{call "_burn"}
        		}
        	}
        }
    )

;============================================================================
    {on break_armor
        {if name "blast"
            {if volume "body"
                {if rand 0.5 {kill_crew "gunner"}}
                {if rand 0.5 {kill_crew "charger"}}
                {if rand 0.5 {kill_crew "commander"}}
                {if rand 0.5 {kill_crew "driver"}}
                {if rand 0.5 {kill_crew "gunner2"}}
;///////Engineer_Den + ////////////////	
		{if rand 0.5 {kill_crew "radist"}}
		{if rand 0.4 {kill_crew "gunner3"}}
		{if rand 0.4 {kill_crew "gunner4"}}
		{if rand 0.5 {kill_crew "gunner5"}}
		{if rand 0.5 {kill_crew "charger5"}}
		{if rand 0.5 {kill_crew "gunner6"}}
		{if rand 0.5 {kill_crew "charger6"}}
;///////Engineer_Den - ////////////////					                     
                {if not tagged "destroyed"
                    {call "mp_destroy"}
                }
            }
            {if volume "explosive"
				{if rand 0.5 {call "explosive_broken"}}
            }
        }
        {if not user_control
            {if volume "body"
                {if rand 0.1 {kill_crew "gunner"}}
                {if rand 0.1 {kill_crew "charger"}}
                {if rand 0.1 {kill_crew "commander"}}
                {if rand 0.1 {kill_crew "driver"}}
;///////Engineer_Den + ////////////////	
{if rand 0.1 {kill_crew "radist"}}
{if rand 0.1 {kill_crew "gunner3"}}
{if rand 0.1 {kill_crew "gunner4"}}
{if rand 0.1 {kill_crew "gunner5"}}
{if rand 0.1 {kill_crew "charger5"}}
{if rand 0.1 {kill_crew "gunner6"}}
{if rand 0.1 {kill_crew "charger6"}}
;///////Engineer_Den - ////////////////				
            }
        }                
        {if not "no_burn_volumes"
            {if name "pierce"
                {if volume "body"
                    {burn fx "smoke_dead_tank1" fake}
                else volume "track"
                {burn fx "smoke_dead_tank1" fake}
				}
            }
        }
    }
 
    {on break_armor_again
        {if component "engine"
            ;{call "burn_by_engine"}
        }
        {if name "blast"
            {if volume "body"
                {if not tagged "destroyed"
                    {call "mp_destroy"}
                }
            }
			{if volume "explosive"
				{if rand 0.8 {call "explosive_broken"}}
			}
        }
    }
    {on break
		{if component "body"
            {tags add "body_brake"}
            {tags add "turret_stopped_by_body"}
			{spawn "tank_die_particle" "Body"}
			{call "emit_crew"}
			{view start "smoke4"}
			{set "smoke4" 1}
			{delay 25
				{view start "smoke4_2"}
				{delay 30
			 		{view stop "smoke4_2"}
				}
			}
			
			{delay 30
				{view stop "smoke4"}
				{set "smoke4" 0}
			}
		else component "engine"
            {tags add "engine_brake"}
			{spawn "tank_die_particle" "engine"}
			{view start "smoke1"}
			{set "smoke1" 1}
			{delay 30
				{view stop "smoke1"}
				{set "smoke1" 0}
			}
			;{call "burn_by_engine"}

        else component "shield"
            ("cut_shield_part" args "shieldr1")
            ("cut_shield_part" args "shieldr2")
            ("cut_shield_part" args "shieldr3")
            ("cut_shield_part" args "shieldr4")
            ("cut_shield_part" args "shieldr5")
            ("cut_shield_part" args "shieldr6")
            ("cut_shield_part" args "shieldr7")
            ("cut_shield_part" args "shieldr8")
            ("cut_shield_part" args "shieldr9")
            ("cut_shield_part" args "shieldl1")
            ("cut_shield_part" args "shieldl2")
            ("cut_shield_part" args "shieldl3")
            ("cut_shield_part" args "shieldl4")
            ("cut_shield_part" args "shieldl5")
            ("cut_shield_part" args "shieldl6")
            ("cut_shield_part" args "shieldl8")

        else component "turret"
            {tags add "turret_brake"}
        }
    }

{"tank"
;   {friction 1}
;   {restitution 0.3}
    (include "tank/general_scripts_defines.inc")

;MEGA BUILDING BEGIN
=============================================================================================================================================================================
    (define "damage_process_pierce" ;by Svoyak  ;define's call's see in tank-armoredcar.inc, tank-light.inc, tank-medium.inc & tank-heavy.inc.
;=================================
                {if stuff "%staff"
                    ("gun_hit" rand(%pierce_gun))
                    ("track_hit" max_rand(%pierce_front_back_track) min_rand(%pierce_left_right_track))
                    {if volume "body"
                        {burn fx "smoke_dead_tank3" fake}

                        {if rand %pierce_body__kill_charger {kill_crew "charger"}}
                        {if rand %pierce_body__kill_driver {kill_crew "driver"}}
                        {if rand %pierce_body__kill_gunner {kill_crew "gunner"}}
                        {if rand %pierce_body__kill_commander {kill_crew "commander"}}
                        {if rand %pierce_body__kill_gunner2 {kill_crew "gunner2"}}

                        {if rand %pierce_body__body_brake
                            {if work "body"
                                {components "body" break}
                                {unlink_trailer}
                                {call "stat_body_break"}
                                {damage_report "body" "component/body_break"}
                                {delay 2
                                    {crew_emit}
                                }
                                {delay 4
                                    {crew_emit}
                                }
                                {delay 6
                                    {crew_emit}
                                }
                                {able "select" 0}
								else
									{delay 2
										{crew_emit}
									}
									{delay 4
										{crew_emit}
									}
									{delay 6
										{crew_emit}
									}
                            }
						else rand %pierce_body__body_destroy
							{call "mp_destroy"}
							{if rand 0.35 
								{call "explosive_broken"}
							}
                            {delay 2
								{able "select" 0}
                            }
                        else operatable 
                            {damage_report "body" "component/shock"}
                        else
                            {damage_report "body" "component/body_pierced"}
                        }

                            ;================симул€ци€ контузии
                            {if operatable
                                {if work "mover"
                                        {chassis_work 0}
                                        {tags add "stopped"}
                                }
                                {if work "turret"
                                    {ik_enable "turret" 0}
                                    {tags add "turr_jummed"}
                                }
                                {weapon_work "gun" 0}{weapon_work "gun2" 0}{weapon_work "mgun" 0}{weapon_work "mgun1" 0}{weapon_work "mgun2" 0}{weapon_work "mgun3" 0}

                                {delay %crew_shock_time
                                    {if not tagged "gun_brake"
                                        {weapon_work "gun" 1}
                                    }
                                    {weapon_work "gun2" 1}{weapon_work "mgun" 1}{weapon_work "mgun1" 1}{weapon_work "mgun2" 1}{weapon_work "mgun3" 1}
                                    {if tagged "stopped"
                                        {tags remove "stopped"}
                                        {if work "mover"
                                            {if not tagged "engine_brake"
                                                {chassis_work 1}
                                            }
                                        }
                                    }
                                    {if tagged "turr_jummed"
                                        {if tagged "turret_brake"
                                            {tags remove "turr_jummed"}
                                        else tagged "turret_stopped_by_body"
                                            {tags remove "turr_jummed"}
                                        else
                                            {tags remove "turr_jummed"}
                                            {ik_enable "turret" 1}
                                        }
                                    }
                                }

                            }

                    else volume "turret"
                        {burn fx "smoke_dead_tank3" fake}

                        {if rand %pierce_turret__explosive
                            {call "stat_break"}
                            {delay 0.5
                                {call "_explosion"}
                            }
                        }
                        {if hit_side front
                           {if rand %pierce_turret_front__gun_brake
                                {if work "gun"
                                    {components "gun" break}
                                    {damage_report "gun" "component/gun_broken"}
                                }
                            }

                            {if rand %pierce_turret_front__turret_brake
                                {components "turret" break}
                                {ik_enable "turret" 0}
                            }

                        else hit_side back
                            {if rand %pierce_turret_back__gun_brake
                                {if work "gun"
                                    {components "gun" break}
                                    {damage_report "gun" "component/gun_broken"}
                                }
                            }

                            {if rand %pierce_turret_back__turret_brake
                                {components "turret" break}
                                {ik_enable "turret" 0}
                            }

                        else
                            {if rand %pierce_turret_left_right__gun_brake
                                {if work "gun"
                                    {components "gun" break}
                                    {damage_report "gun" "component/gun_broken"}
                                }
                            }
                            {if rand %pierce_turret_left_right__turret_brake
                                {components "turret" break}
                                {ik_enable "turret" 0}
                            }
                        }
                        {if rand %pierce_turret__kill_charger {kill_crew "charger"}}
                        {if rand %pierce_turret__kill_driver {kill_crew "driver"}}
                        {if rand %pierce_turret__kill_gunner {kill_crew "gunner"}}
                        {if rand %pierce_turret__kill_commander {kill_crew "commander"}}
                        {if rand %pierce_turret__kill_gunner2 {kill_crew "gunner2"}}

                        ;==============симул€ци€ контузии
                        {if operatable
                                    {ik_enable "turret" 0}
                                    {weapon_work "gun" 0}{weapon_work "gun2" 0}{weapon_work "mgun" 0}{weapon_work "mgun1" 0}{weapon_work "mgun2" 0}{weapon_work "mgun3" 0}
                                    {tags add "turr_jummed"}
                                    {delay %crew_shock_time
                                        {if not tagged "gun_brake"
                                            {weapon_work "gun" 1}
                                        }
                                        {weapon_work "gun2" 1}{weapon_work "mgun" 1}{weapon_work "mgun1" 1}{weapon_work "mgun2" 1}{weapon_work "mgun3" 1}
                                        {if tagged "turr_jummed"
                                                {if tagged "turret_brake"
                                                    {tags remove "turr_jummed"}
                                                else tagged "turret_stopped_by_body"
                                                    {tags remove "turr_jummed"}
                                                else
                                                    {tags remove "turr_jummed"}
                                                    {ik_enable "turret" 1}
                                                }
                                        }
                                    }
                        }


                    else volume "mantlet"
                           {burn fx "smoke_dead_tank3" fake}

                            {if rand (* %pierce_mantlet__gun_brake 0.1)
                                {if work "gun"
                                    {components "gun" break}
                                    {damage_report "gun" "component/gun_broken"}
                                }
                            ;else
                            ;    {call "turret_break"}
                            }
                            ;{if rand %pierce_turret_front__turret_brake
                            ;   {components "turret" break}
                            ;}

                    else volume "explosive"
                        {if rand (* %pierce_inventory__explosive 0.4)
                            {call "explosion"}
                        }
                    else volume "engine"
                        {if rand %pierce_engine__engine_brake
                            {if work "engine"
                                {components "engine" break}
                            }
                            {if rand %pierce_engine__engine_burn
                                {delay 3 2
                                    {call "_burn"}
                                }
                            }
                        }
                    }
                };stuff
    )
    (define "damage_process_bullet_hit" ;by Svoyak
;====================================
                    {if stuff "%staff"
                    {impulse dir %imp}
                    ;{if hit_angle > %angle_hit
                        {if volume "body"
                                {if rand %hit_body__explosive
                                    {call "explosion"}
                                }
                                {if rand %hit_body__engine_brake
                                    {if work "engine"
                                        {components "engine" break}
                                    }
                                }
                                {if rand %hit_body__body_destroy
                                    {call "mp_destroy"}
                                else rand %hit_body__body_brake
                                    {components "body" break}
                                    {damage_report "body" "component/body_break"}
                                }
                            
                        else volume "engine"
                                {if rand %hit_body__explosive
                                    {call "explosion"}
                                }
                                {if rand %hit_engine__engine_brake
                                    {if work "engine"
                                        {components "engine" break}
                                    }
                                }
                                {if rand %hit_body__body_brake
                                    {components "body" break}
                                    {damage_report "body" "component/body_break"}
                                }
                        else volume "turret"
                                {if rand %hit_turret__explosive
                                    {call "explosion"}
                                }
                                {if hit_side front
                                    {if rand %hit_turret_front__gun_brake
                                        {if work "gun"
                                            {components "gun" break}
                                            {damage_report "gun" "component/gun_broken"}
                                        }
                                    }
                                }
                                {if rand %hit_turret__turret_destroy
                                    {components "turret" destroy}
                                else rand %hit_turret__turret_brake
                                    {components "turret" break}
                                }
                        else volume "mantlet"
                                {if rand %hit_turret__explosive
                                    {call "explosion"}
                                }
                                {if rand %hit_turret_front__gun_brake
                                    {if work "gun"
                                        {components "gun" break}
                                        {damage_report "gun" "component/gun_broken"}
                                    }
                                }
                                {if rand %hit_turret__turret_destroy
                                    {components "turret" destroy}
                                else rand %hit_turret__turret_brake
                                    {components "turret" break}
                                }
                        else volume "wheel"
                                {if rand %hit_body__explosive
                                    {call "explosion"}
                                }
                                {if rand %hit_body__engine_brake
                                    {if work "engine"
                                        {components "engine" break}
                                    }
                                }
                                {if rand %hit_body__body_destroy
                                    {call "mp_destroy"}
                                else rand %hit_body__body_brake
                                    {components "body" break}
                                    {damage_report "body" "component/body_break"}
                                }
                        else volume "track"
                                {if rand %hit_body__explosive
                                    {call "explosion"}
                                }
                                {if rand %hit_body__engine_brake
                                    {if work "engine"
                                        {components "engine" break}
                                    }
                                }
                                {if rand %hit_body__body_destroy
                                    {call "mp_destroy"}
                                else rand %hit_body__body_brake
                                    {components "body" break}
                                    {damage_report "body" "component/body_break"}
                                }								
                        }
                    ;};if hit_angle end
                    }; stuff
;=====================================
    )

    (define "blast_damage_contusion" ;by Svoyak
        {if volume "trackleft"
            ;do nothing
        else volume "trackright"
            ;do nothing
        else volume "roller"
            ;do nothing
        else volume "wheel_work"
            ;do nothing
        else volume "wheel"
            ;do nothing
        else
            {if operatable
                {if not "already_blasted"
            
                    {if min_energy %blast_energy
                        {set "already_blasted" 1}
                        {if rand %blast_rand_contusion
                            {delay 0.5
                                {set "already_blasted" 0}
                            }
                            ;{con "%blast_energy"}
                            {damage_report "body" "component/shock"}
                            {chassis_work 0}
                            {tags add "stopped1"}
                            
                            {if work "turret"
                                {ik_enable "turret" 0}
                                {tags add "turr_jummed1"}
                            }
                            {weapon_work "gun" 0}{weapon_work "gun2" 0}{weapon_work "mgun" 0}{weapon_work "mgun1" 0}{weapon_work "mgun2" 0}{weapon_work "mgun3" 0}
                            {delay %blast_crew_shock_time
                                {if not tagged "gun_brake"
                                    {weapon_work "gun" 1}
                                }
                                {weapon_work "gun2" 1}{weapon_work "mgun" 1}{weapon_work "mgun1" 1}{weapon_work "mgun2" 1}{weapon_work "mgun3" 1}
                                {if tagged "stopped1"
                                    {tags remove "stopped1"}
                                    {if work "mover"
                                        {if not tagged "engine_brake"
                                            {chassis_work 1}
                                        }
                                    }
                                }
                                {if tagged "turr_jummed1"
                                        {if tagged "turret_brake"
                                            {tags remove "turr_jummed1"}
                                            
                                        else tagged "turret_stopped_by_body"
                                            {tags remove "turr_jummed1"}
                                        else
                                            {tags remove "turr_jummed1"}
                                            {ik_enable "turret" 1}
                                        }
                                }
                            }
                        else
                            {delay 0.5
                                {set "already_blasted" 0}
                            }
                        }
                    }
                }
            }
        }
        
    )
;MEGA BUILDING END =============================================================================================================================================================================

    {on repair
	    {if component "turret"
    		{view stop "smoke3"}
            {call "update_turret"}
            {tags remove "turret_brake"}		
        else component "body"
            {view stop "smoke4"}
            {call "update_turret"}
            {tags remove "turret_stopped_by_body"}
            {tags remove "body_brake"}
            {able "select" 1}
        else component "engine"
            {tags remove "engine_brake"}
        }
    }
	{on "update_turret"
		{if work "turret"
			{if work "body"
				{ik_enable "turret" 1}
			 else
				{ik_enable "turret" 0}
			}
		 else
			{ik_enable "turret" 0}
		}
    }
}; end of "tank"


{"opened tank"
        {on "explosive_broken" overload
                {call "explosion"}
        }
}

{"m4a3c"
        {on fire "gun2"
                {spawn "startsmoke_cali"}
        }
}

{"m4a4_tulip"
        {on fire "gun2"
                {spawn "startsmoke_cali"}
        }
}

{"bm_8_24"
        {on fire "gun"
                {spawn "startsmoke_cali"}
        }
}

{"m4calliope"	; must be placed before	the props "turret"
	{on break_armor             
		{if volume "guns"           
			{call "tear_guns"}
		}
	}
	{on break_armor_again
		{if volume "guns"           
			{call "tear_guns"}
		}
	}
	{on "tear_turret"
		{if "roof_broken"
			{bone cut "gun"}
		else
			{call "tear_gun"}
		}
	}
	{on "tear_guns"
		{if not "roof_broken"
			{weapon_work "gun2" 0}
			{set "roof_broken" 1}
			{components "guns" destroy}
			{delay 0.5
				{bone cut "gun2"}
			}
			{delay_ex 0
				(define "teargun"
					{tear "piece_large_steel" bone "%gun"
						{impulse up 5 2.3 dir 3 1.5 cx 5 2 cy 5 2 rnd_dir 10 no_position}
						{add_view "smoke_black" "smoke" "basis"}
						{view start "smoke"}
						{delay_effect 20 5 "pause"}
					}
				)
				("teargun" gun(guns1))
				("teargun" gun(guns2))
				("teargun" gun(guns3))
				("teargun" gun(guns4))
				("teargun" gun(guns5))
				("teargun" gun(gun2))
			}
		}
	}
}

{"turret"
	{on spawn
		{call "update_turret"}
	}
	{on "turret_break" overload
		{components "turret" break}
	}
	{on break
		{if component "turret"
			{if not user_control
				{if rand 0.5 {kill_crew "gunner"}}
				{if rand 0.5 {kill_crew "charger"}}
				{if rand 0.5 {kill_crew "commander"}}
;///////Engineer_Den + ////////////////	
{if rand 0.5 {kill_crew "radist"}}
;///////Engineer_Den - ////////////////					
			}
			{call "update_turret"}
			{spawn "tank_die_particle" "Turret"}
			{spawn "circledust_norm" "Turret"}
;			{ani_play "open" -1.0 resume}
			{view start "smoke3"}
            {delay 10
    			{view stop "smoke3"}
    			{set "smoke3" 0}
            }
        else component "body"
			{spawn "circledust_norm" "Turret"}
			{call "update_turret"}
		}
	}
	{on "tear_turret"
		{if not "turret_teared"
			{set "turret_teared" 1}
			{components "turret" destroy}
			{call "mp_destroy"}
			{add_view "smoke_black_big5" "smoke_turret" "basis"}
			{view start "smoke_turret"}
			{delay 60 15
				{view stop "smoke_turret"}
			}
			{delay_ex 0
				{tear "piece_large_steel" bone "turret" id "turret"
					{impulse dir 0.5 1}
					{if rand 0.2
						{add_view "smoke_dead_norm" "smoke" "basis"}
					else
						{add_view "smoke_black" "smoke" "basis"}
					}
					{view start "smoke"}
					{delay_effect 30 5 "pause"}
					{delay 0.1
						{volumes "gun" disable obstacle}
					}
				}
			}
		}
	}
	{on "slice_load"
		{if name "turret"
			{with_effector
				{add_view "smoke_black" "smoke" "basis"}
			}
		}
	}

	{on "cut_parts"
		{if "turret_teared"
			{bone cut "turret"}
		else
                    {call "tear_turret"}
		}
	}
}
;///////Engineer_Den + ////////////////	
{"turret2"
	{on spawn
		{call "update_turret2"}
	}
	{on "turret2_break" overload
		{components "turret2" break}
	}
	{on break
		{if component "turret2"
			{if not user_control
				{if rand 0.5 {kill_crew "gunner3"}}				
			}
			{call "update_turret2"}
			{spawn "tank_die_particle" "Turret2"}
			{spawn "circledust_norm" "Turret2"}
;			{ani_play "open2" -1.0 resume}
			{view start "smoke7"}
		(mod not "mp"
			{set "smoke7" 1}
			{call "check_burn_emit"}
		)
    		{delay 10
    			{view stop "smoke7"}
			{set "smoke7" 0}
			(mod not "mp"
				{call "check_burn_emit"}
			)
    		}		
    	else component "body"
			{spawn "circledust_norm" "Turret2"}			
	;		{call "update_turret2"}			
		}
	}
	
	{on "tear_turret2"
		{if not "turret2_teared"
			{set "turret2_teared" 1}
			{components "turret2" destroy}
			(mod "mp"
				;{call "mp_destroy"}
			)
			{add_view "smoke_black_big5" "smoke_turret" "basis"}
			{view start "smoke_turret"}
			{delay 60 15		
				{view stop "smoke_turret"}
			}
			{delay_ex 0
				{tear "piece_large_steel" bone "turret2" id "turret2"
					{impulse dir 0.5 1}
					{if rand 0.2
						{add_view "smoke_dead_norm" "smoke" "basis"}
					else 
						{add_view "smoke_black" "smoke" "basis"}
					}
					{view start "smoke"}
					{delay_effect 30 5 "pause"}					
				}
			}
		}
	}
		
	{on "slice_load"
		{if name "turret2"
			{with_effector
				{add_view "smoke_black" "smoke" "basis"}
			}
		}		
	}
	{on "cut_parts"
		{if "turret2_teared"
			{bone cut "turret2"}
		else
		    {call "tear_turret2"}
		}		
	}	
}
;------------------------------------------
{"turret3"
	{on spawn
		{call "update_turret3"}
	}
	{on "turret3_break" overload
		{components "turret3" break}
	}
	{on break
		{if component "turret3"
			{if not user_control
				{if rand 0.5 {kill_crew "gunner4"}}				
			}
			{call "update_turret3"}
			{spawn "tank_die_particle" "Turret3"}
			{spawn "circledust_norm" "Turret3"}
;			{ani_play "open3" -1.0 resume}
			{view start "smoke8"}
		(mod not "mp"
			{set "smoke8" 1}
			{call "check_burn_emit"}
		)
    		{delay 10
    			{view stop "smoke8"}
			{set "smoke8" 0}
			(mod not "mp"
				{call "check_burn_emit"}
			)
    		}		
    	else component "body"
			{spawn "circledust_norm" "Turret3"}			
	;		{call "update_turret3"}			
		}
	}
	
	{on "tear_turret3"
		{if not "turret3_teared"
			{set "turret3_teared" 1}
			{components "turret3" destroy}
			(mod "mp"
				;{call "mp_destroy"}
			)
			{add_view "smoke_black_big5" "smoke_turret" "basis"}
			{view start "smoke_turret"}
			{delay 60 15		
				{view stop "smoke_turret"}
			}
			{delay_ex 0
				{tear "piece_large_steel" bone "turret3" id "turret3"
					{impulse dir 0.5 1}
					{if rand 0.2
						{add_view "smoke_dead_norm" "smoke" "basis"}
					else 
						{add_view "smoke_black" "smoke" "basis"}
					}
					{view start "smoke"}
					{delay_effect 30 5 "pause"}					
				}
			}
		}
	}
		
	{on "slice_load"
		{if name "turret3"
			{with_effector
				{add_view "smoke_black" "smoke" "basis"}
			}
		}		
	}
	{on "cut_parts"
		{if "turret3_teared"
			{bone cut "turret3"}
		else
		    {call "tear_turret3"}
		}		
	}	
}
;-------------------------------------------------
{"turret4"
	{on spawn
		{call "update_turret4"}
	}
	{on "turret4_break" overload
		{components "turret4" break}
	}
	{on break
		{if component "turret4"
			{if not user_control
				{if rand 0.5 {kill_crew "gunner5"}}
				{if rand 0.5 {kill_crew "charger5"}}				
			}
			{call "update_turret4"}
			{spawn "tank_die_particle" "Turret4"}
			{spawn "circledust_norm" "Turret4"}
;			{ani_play "open4" -1.0 resume}
			{view start "smoke12"}
		(mod not "mp"
			{set "smoke12" 1}
			{call "check_burn_emit"}
		)
    		{delay 10
    			{view stop "smoke12"}
			{set "smoke12" 0}
			(mod not "mp"
				{call "check_burn_emit"}
			)
    		}		
    	else component "body"
			{spawn "circledust_norm" "Turret4"}			
	;		{call "update_turret4"}			
		}
	}
	
	{on "tear_turret4"
		{if not "turret4_teared"
			{set "turret4_teared" 1}
			{components "turret4" destroy}
			(mod "mp"
				;{call "mp_destroy"}
			)
			{add_view "smoke_black_big5" "smoke_turret" "basis"}
			{view start "smoke_turret"}
			{delay 60 15		
				{view stop "smoke_turret"}
			}
			{delay_ex 0
				{tear "piece_large_steel" bone "turret4" id "turret4"
					{impulse dir 0.5 1}
					{if rand 0.2
						{add_view "smoke_dead_norm" "smoke" "basis"}
					else 
						{add_view "smoke_black" "smoke" "basis"}
					}
					{view start "smoke"}
					{delay_effect 30 5 "pause"}					
				}
			}
		}
	}
		
	{on "slice_load"
		{if name "turret4"
			{with_effector
				{add_view "smoke_black" "smoke" "basis"}
			}
		}		
	}
	{on "cut_parts"
		{if "turret4_teared"
			{bone cut "turret4"}
		else
		    {call "tear_turret4"}
		}		
	}	
}
;---------------------------------------------------------------
{"turret5"
	{on spawn
		{call "update_turret5"}
	}
	{on "turret5_break" overload
		{components "turret5" break}
	}
	{on break
		{if component "turret5"
			{if not user_control
				{if rand 0.5 {kill_crew "gunner6"}}
				{if rand 0.5 {kill_crew "charger6"}}				
			}
			{call "update_turret5"}
			{spawn "tank_die_particle" "Turret5"}
			{spawn "circledust_norm" "Turret5"}
;			{ani_play "open5" -1.0 resume}
			{view start "smoke11"}
		(mod not "mp"
			{set "smoke11" 1}
			{call "check_burn_emit"}
		)
    		{delay 10
    			{view stop "smoke11"}
			{set "smoke11" 0}
			(mod not "mp"
				{call "check_burn_emit"}
			)
    		}		
    	else component "body"
			{spawn "circledust_norm" "Turret5"}			
	;		{call "update_turret5"}			
		}
	}
	
	{on "tear_turret5"
		{if not "turret5_teared"
			{set "turret5_teared" 1}
			{components "turret5" destroy}
			(mod "mp"
				;{call "mp_destroy"}
			)
			{add_view "smoke_black_big5" "smoke_turret" "basis"}
			{view start "smoke_turret"}
			{delay 60 15		
				{view stop "smoke_turret"}
			}
			{delay_ex 0
				{tear "piece_large_steel" bone "turret5" id "turret5"
					{impulse dir 0.5 1}
					{if rand 0.2
						{add_view "smoke_dead_norm" "smoke" "basis"}
					else 
						{add_view "smoke_black" "smoke" "basis"}
					}
					{view start "smoke"}
					{delay_effect 30 5 "pause"}					
				}
			}
		}
	}
		
	{on "slice_load"
		{if name "turret5"
			{with_effector
				{add_view "smoke_black" "smoke" "basis"}
			}
		}		
	}
	{on "cut_parts"
		{if "turret5_teared"
			{bone cut "turret5"}
		else
		    {call "tear_turret5"}
		}		
	}	
}
;///////Engineer_Den - ////////////////
{"light tank turret"
	{on bullet_hit
		{if volume "turret"
			{if stuff "big shell fg"
				{if rand 0.95
					{call "tear_turret"}
				}
			}
		}
	}
}

{"light_turret" ; turret for btr, car, ...
	{on bullet_hit
		{if volume "turret"
			{if stuff "shell"
				{call "tear_turret"}
			}
		}
	}
}

{"armored_car"
	{on blast_hit
		{if min_energy 3
			{impulse up 0.3 0.2 dir 1 0.2}
		 else min_energy 1.9
			{impulse up 0.1 0.05 dir 0.3 0.1}
		 else min_energy 1
		 	{ani_play "hit"}
		}
	}
	{on "_explosion"
		{blastwave c4 3 r0 2.5 r1 10}
		{impulse up 0.7 0.3 dir 0.2 0.1}
	}

(include "tank/tank_armoredcar.inc")

}

{"h_armored_car"
	{on blast_hit
		{if min_energy 3
			{impulse up 0.3 0.2 dir 1 0.2}
		 else min_energy 1.9
			{impulse up 0.1 0.05 dir 0.3 0.1}
		 else min_energy 1
		 	{ani_play "hit"}
		}
	}
	{on "_explosion"
		{blastwave c4 3 r0 2.5 r1 10}
		{impulse up 0.7 0.3 dir 0.2 0.1}
	}

(include "tank/tank_h_armoredcar.inc")

}

{"l_light tank"
	{on blast_hit
		{if min_energy 36
			{impulse up 0.3 0.2 dir 1 0.2}
			{if volume "turret"
				{call "tear_turret"}
			}
		else min_energy 6
			{impulse up 0.15 0.05 dir 0.35 0.1}
			{if volume "turret"
				{call "tear_turret"}
			}
		else min_energy  5.5
			{impulse up 0.15 0.05 dir 0.35 0.1}
			{call "tear_turret"}
		 else min_energy 4.5
			{impulse up 0.1 0.05 dir 0.3 0.1}
			{if rand 0.99 {call "tear_turret"}}
		 else min_energy 1.9
		 	{ani_play "hit"}
		}
	}
	{on "_explosion"
		{blastwave c4 5 r0 2.5 r1 10}
		{impulse up 0.5}
	}
(include "tank/tank_l_light.inc")
}

{"light tank"
	{on blast_hit
		{if min_energy 36
			{impulse up 0.3 0.2 dir 1 0.2}
			{if volume "turret"
				{call "tear_turret"}
			}
		else min_energy 6
			{impulse up 0.15 0.05 dir 0.35 0.1}
			{if volume "turret"
				{call "tear_turret"}
			}
		else min_energy  5.5
			{impulse up 0.15 0.05 dir 0.35 0.1}
			{call "tear_turret"}
		 else min_energy 4.5
			{impulse up 0.1 0.05 dir 0.3 0.1}
			{if rand 0.99 {call "tear_turret"}}
		 else min_energy 1.9
		 	{ani_play "hit"}
		}
	}
	{on "_explosion"
		{blastwave c4 5 r0 2.5 r1 10}
		{impulse up 0.5}
	}
(include "tank/tank_light.inc")
}

{"h_light tank"
	{on blast_hit
		{if min_energy 36
			{impulse up 0.3 0.2 dir 1 0.2}
			{if volume "turret"
				{call "tear_turret"}
			}
		else min_energy 6
			{impulse up 0.15 0.05 dir 0.35 0.1}
			{if volume "turret"
				{call "tear_turret"}
			}			
		else min_energy  5.5
			{impulse up 0.15 0.05 dir 0.35 0.1}
			{call "tear_turret"}
		 else min_energy 4.5
			{impulse up 0.1 0.05 dir 0.3 0.1}
			{if rand 0.99 {call "tear_turret"}}
		 else min_energy 1.9
		 	{ani_play "hit"}
		}
	}
	{on "_explosion"
		{blastwave c4 5 r0 2.5 r1 10}
		{impulse up 0.5}
	}
(include "tank/tank_h_light.inc")
}

{"l_medium tank"
	{inflammation_time 35}
	{on blast_hit
		{if min_energy 36
			{impulse up 0.25 0.05 dir 2.5 0.1}
			{if volume "turret"
				{if rand 0.95
					{call "tear_turret"}
				}
			}
		else min_energy 15
			{impulse up 0.15 0.05 dir 0.35 0.1}
			{if volume "turret"
				{if rand 0.95
					{call "tear_turret"}
				}
			}
		else min_energy 9
			{impulse up 0.15 0.05 dir 0.35 0.1}
			{if volume "turret"
				{if rand 0.7
					{call "tear_turret"}
				}
			}
		 else min_energy 6
			{impulse up 0.1 0.05 dir 0.3 0.1}
		 else min_energy 3
			{impulse up 0.1 0.05 dir 0.3 0.1}
		 else min_energy 1.9
		 	;{ani_play "hit"}
		}
	}
	{on "_explosion"
		{blastwave c4 10 r0 2.5 r1 10}
		{impulse up 2 0.5 dir 0.4 0.2}
	}
	{on "check_water_level" overload
		{if water_level 1.6
			{able "sinking" 1}
		}
	}
(include "tank/tank_l_medium.inc")
}

{"l_medium_spa tank"
	{inflammation_time 35}
	{on blast_hit
		{if min_energy 36
			{impulse up 0.25 0.05 dir 2.5 0.1}
			{if volume "turret"
				{if rand 0
					{call "tear_turret"}
				}
			}
		else min_energy 15
			{impulse up 0.15 0.05 dir 0.35 0.1}
			{if volume "turret"
				{if rand 0
					{call "tear_turret"}
				}
			}
		else min_energy 9
			{impulse up 0.15 0.05 dir 0.35 0.1}
			{if volume "turret"
				{if rand 0
					{call "tear_turret"}
				}
			}
		 else min_energy 6
			{impulse up 0.1 0.05 dir 0.3 0.1}
		 else min_energy 3
			{impulse up 0.1 0.05 dir 0.3 0.1}
		 else min_energy 1.9
		 	;{ani_play "hit"}
		}
	}
	{on "_explosion"
		{blastwave c4 10 r0 2.5 r1 10}
		{impulse up 2 0.5 dir 0.4 0.2}
	}
	{on "check_water_level" overload
		{if water_level 1.6
			{able "sinking" 1}
		}
	}
(include "tank/tank_l_medium_spa.inc")
}

{"medium tank"
	{inflammation_time 35}
	{on blast_hit
		{if min_energy 36
			{impulse up 0.25 0.05 dir 2.5 0.1}
			{if volume "turret"
				{if rand 0.95
					{call "tear_turret"}
				}
			}
		else min_energy 15
			{impulse up 0.15 0.05 dir 0.35 0.1}
			{if volume "turret"
				{if rand 0.95
					{call "tear_turret"}
				}
			}
		else min_energy 9
			{impulse up 0.15 0.05 dir 0.35 0.1}
			{if volume "turret"
				{if rand 0.7
					{call "tear_turret"}
				}
			}
		 else min_energy 6
			{impulse up 0.1 0.05 dir 0.3 0.1}
		 else min_energy 3
			{impulse up 0.1 0.05 dir 0.3 0.1}
		 else min_energy 1.9
		 	;{ani_play "hit"}
		}
	}
	{on "_explosion"
		{blastwave c4 10 r0 2.5 r1 10}
		{impulse up 2 0.5 dir 0.4 0.2}
	}
	{on "check_water_level" overload
		{if water_level 1.6
			{able "sinking" 1}
		}
	}
(include "tank/tank_medium.inc")
}

{"medium_spa tank"
	{inflammation_time 35}
	{on blast_hit
		{if min_energy 36
			{impulse up 0.25 0.05 dir 2.5 0.1}
			{if volume "turret"
				{if rand 0
					{call "tear_turret"}
				}
			}
		else min_energy 15
			{impulse up 0.15 0.05 dir 0.35 0.1}
			{if volume "turret"
				{if rand 0
					{call "tear_turret"}
				}
			}
		else min_energy 9
			{impulse up 0.15 0.05 dir 0.35 0.1}
			{if volume "turret"
				{if rand 0
					{call "tear_turret"}
				}
			}
		 else min_energy 6
			{impulse up 0.1 0.05 dir 0.3 0.1}
		 else min_energy 3
			{impulse up 0.1 0.05 dir 0.3 0.1}
		 else min_energy 1.9
		 	;{ani_play "hit"}
		}
	}
	{on "_explosion"
		{blastwave c4 10 r0 2.5 r1 10}
		{impulse up 2 0.5 dir 0.4 0.2}
	}
	{on "check_water_level" overload
		{if water_level 1.6
			{able "sinking" 1}
		}
	}
(include "tank/tank_medium_spa.inc")
}

{"h_medium tank"
	{inflammation_time 35}
	{on blast_hit
		{if min_energy 36
			{impulse up 0.25 0.05 dir 2.5 0.1}
			{if volume "turret"
				{if rand 0.95
					{call "tear_turret"}
				}
			}
		else min_energy 15
			{impulse up 0.15 0.05 dir 0.35 0.1}
			{if volume "turret"
				{if rand 0.95
					{call "tear_turret"}
				}
			}			
		else min_energy 9
			{impulse up 0.15 0.05 dir 0.35 0.1}
			{if volume "turret"
				{if rand 0.7
					{call "tear_turret"}
				}
			}
		 else min_energy 6
			{impulse up 0.1 0.05 dir 0.3 0.1}
		 else min_energy 3
			{impulse up 0.1 0.05 dir 0.3 0.1}
		 else min_energy 1.9
		 	;{ani_play "hit"}
		}
	}
	{on "_explosion"
		{blastwave c4 10 r0 2.5 r1 10}
		{impulse up 2 0.5 dir 0.4 0.2}
	}
	{on "check_water_level" overload
		{if water_level 1.6
			{able "sinking" 1}
		}
	}
(include "tank/tank_h_medium.inc")
}

{"h_medium_spa tank"
	{inflammation_time 35}
	{on blast_hit
		{if min_energy 36
			{impulse up 0.25 0.05 dir 2.5 0.1}
			{if volume "turret"
				{if rand 0
					{call "tear_turret"}
				}
			}
		else min_energy 15
			{impulse up 0.15 0.05 dir 0.35 0.1}
			{if volume "turret"
				{if rand 0
					{call "tear_turret"}
				}
			}			
		else min_energy 9
			{impulse up 0.15 0.05 dir 0.35 0.1}
			{if volume "turret"
				{if rand 0
					{call "tear_turret"}
				}
			}
		 else min_energy 6
			{impulse up 0.1 0.05 dir 0.3 0.1}
		 else min_energy 3
			{impulse up 0.1 0.05 dir 0.3 0.1}
		 else min_energy 1.9
		 	;{ani_play "hit"}
		}
	}
	{on "_explosion"
		{blastwave c4 10 r0 2.5 r1 10}
		{impulse up 2 0.5 dir 0.4 0.2}
	}
	{on "check_water_level" overload
		{if water_level 1.6
			{able "sinking" 1}
		}
	}
(include "tank/tank_h_medium_spa.inc")
}

{"r_heavy tank"
	{inflammation_time 35}
	{on blast_hit
		{if min_energy 36
			{impulse up 0.3 0.05 dir 2.5 0.1}
			{if volume "turret"
				{if rand 0.95
					{call "tear_turret"}
				}
			}
		else min_energy 24
			{impulse up 0.2 0.05 dir 0.35 0.1}
			{if volume "turret"
				{if rand 0.7
					{call "tear_turret"}
				}
			}
		 else min_energy 15
			{impulse up 0.1 0.05 dir 0.3 0.1}
			{if volume "turret"
				{if rand 0.2
					{call "tear_turret"}
				}
			}
		 else min_energy 6
		 	;{ani_play "hit"}
		}
	}
	{on "_explosion"
        {blastwave c4 15 r0 2.5 r1 10}
		{impulse up 1 1 dir 0.2 0.2}
	}
	{on "check_water_level" overload
		{if water_level 1.8
			{able "sinking" 1}
		}
	}
(include "tank/tank_r_heavy.inc")
}

{"r_heavy_spa tank"
	{inflammation_time 35}
	{on blast_hit
		{if min_energy 36
			{impulse up 0.15 0.05 dir 2.5 0.1}
			{if volume "turret"
				{if rand 0
					{call "tear_turret"}
				}
			}
		else min_energy 24
			{impulse up 0.10 0.05 dir 0.35 0.1}
			{if volume "turret"
				{if rand 0
					{call "tear_turret"}
				}
			}
		 else min_energy 15
			{impulse up 0.1 0.05 dir 0.3 0.1}
			{if volume "turret"
				{if rand 0
					{call "tear_turret"}
				}
			}
		 else min_energy 6
		 	;{ani_play "hit"}
		}
	}
	{on "_explosion"
        {blastwave c4 15 r0 2.5 r1 10}
		{impulse up 1 1 dir 0.2 0.2}
	}
	{on "check_water_level" overload
		{if water_level 1.8
			{able "sinking" 1}
		}
	}
(include "tank/tank_r_heavy_spa.inc")
}

{"l_heavy tank"
	{inflammation_time 35}
	{on blast_hit
		{if min_energy 36
			{impulse up 0.3 0.05 dir 2.5 0.1}
			{if volume "turret"
				{if rand 0.95
					{call "tear_turret"}
				}
			}
		else min_energy 24
			{impulse up 0.2 0.05 dir 0.35 0.1}
			{if volume "turret"
				{if rand 0.7
					{call "tear_turret"}
				}
			}
		 else min_energy 15
			{impulse up 0.1 0.05 dir 0.3 0.1}
			{if volume "turret"
				{if rand 0.2
					{call "tear_turret"}
				}
			}
		 else min_energy 6
		 	;{ani_play "hit"}
		}
	}
	{on "_explosion"
        {blastwave c4 15 r0 2.5 r1 10}
		{impulse up 1 1 dir 0.2 0.2}
	}
	{on "check_water_level" overload
		{if water_level 1.8
			{able "sinking" 1}
		}
	}
(include "tank/tank_l_heavy.inc")
}

{"l_heavy_spa tank"
	{inflammation_time 35}
	{on blast_hit
		{if min_energy 36
			{impulse up 0.25 0.05 dir 2.5 0.1}
			{if volume "turret"
				{if rand 0
					{call "tear_turret"}
				}
			}
		else min_energy 24
			{impulse up 0.15 0.05 dir 0.35 0.1}
			{if volume "turret"
				{if rand 0
					{call "tear_turret"}
				}
			}
		 else min_energy 15
			{impulse up 0.1 0.05 dir 0.3 0.1}
			{if volume "turret"
				{if rand 0
					{call "tear_turret"}
				}
			}
		 else min_energy 6
		 	;{ani_play "hit"}
		}
	}
	{on "_explosion"
        {blastwave c4 15 r0 2.5 r1 10}
		{impulse up 1 1 dir 0.2 0.2}
	}
	{on "check_water_level" overload
		{if water_level 1.8
			{able "sinking" 1}
		}
	}
(include "tank/tank_l_heavy_spa.inc")
}

{"heavy tank"
	{inflammation_time 35}
	{on blast_hit
		{if min_energy 36
			{impulse up 0.3 0.05 dir 2.5 0.1}
			{if volume "turret"
				{if rand 0.95
					{call "tear_turret"}
				}
			}
		else min_energy 24
			{impulse up 0.2 0.05 dir 0.35 0.1}
			{if volume "turret"
				{if rand 0.7
					{call "tear_turret"}
				}
			}
		 else min_energy 15
			{impulse up 0.1 0.05 dir 0.3 0.1}
			{if volume "turret"
				{if rand 0.2
					{call "tear_turret"}
				}
			}
		 else min_energy 6
		 	;{ani_play "hit"}
		}
	}
	{on "_explosion"
        {blastwave c4 15 r0 2.5 r1 10}
		{impulse up 1 1 dir 0.2 0.2}
	}
	{on "check_water_level" overload
		{if water_level 1.8
			{able "sinking" 1}
		}
	}
(include "tank/tank_heavy.inc")
}

{"heavy_spa tank"
	{inflammation_time 35}
	{on blast_hit
		{if min_energy 36
			{impulse up 0.15 0.05 dir 2.5 0.1}
			{if volume "turret"
				{if rand 0
					{call "tear_turret"}
				}
			}
		else min_energy 24
			{impulse up 0.10 0.05 dir 0.35 0.1}
			{if volume "turret"
				{if rand 0
					{call "tear_turret"}
				}
			}
		 else min_energy 15
			{impulse up 0.1 0.05 dir 0.3 0.1}
			{if volume "turret"
				{if rand 0
					{call "tear_turret"}
				}
			}
		 else min_energy 6
		 	;{ani_play "hit"}
		}
	}
	{on "_explosion"
        {blastwave c4 15 r0 2.5 r1 10}
		{impulse up 1 1 dir 0.2 0.2}
	}
	{on "check_water_level" overload
		{if water_level 1.8
			{able "sinking" 1}
		}
	}
(include "tank/tank_heavy_spa.inc")
}

{"h_heavy tank"
	{inflammation_time 35}
	{on blast_hit
		{if min_energy 36
			{impulse up 0.3 0.05 dir 2.5 0.1}
			{if volume "turret"
				{if rand 0.95
					{call "tear_turret"}
				}
			}
		else min_energy 24
			{impulse up 0.2 0.05 dir 0.35 0.1}
			{if volume "turret"
				{if rand 0.7
					{call "tear_turret"}
				}
			}
		 else min_energy 15
			{impulse up 0.1 0.05 dir 0.3 0.1}
			{if volume "turret"
				{if rand 0.2
					{call "tear_turret"}
				}
			}
		 else min_energy 6
		 	;{ani_play "hit"}
		}
	}
	{on "_explosion"
        {blastwave c4 15 r0 2.5 r1 10}
		{impulse up 1 1 dir 0.2 0.2}
	}
	{on "check_water_level" overload
		{if water_level 1.8
			{able "sinking" 1}
		}
	}
(include "tank/tank_h_heavy.inc")
}

{"h_heavy_spa tank"
	{inflammation_time 35}
	{on blast_hit
		{if min_energy 36
			{impulse up 0.15 0.05 dir 2.5 0.1}
			{if volume "turret"
				{if rand 0
					{call "tear_turret"}
				}
			}
		else min_energy 24
			{impulse up 0.10 0.05 dir 0.35 0.1}
			{if volume "turret"
				{if rand 0
					{call "tear_turret"}
				}
			}
		 else min_energy 15
			{impulse up 0.1 0.05 dir 0.3 0.1}
			{if volume "turret"
				{if rand 0
					{call "tear_turret"}
				}
			}
		 else min_energy 6
		 	;{ani_play "hit"}
		}
	}
	{on "_explosion"
        {blastwave c4 15 r0 2.5 r1 10}
		{impulse up 1 1 dir 0.2 0.2}
	}
	{on "check_water_level" overload
		{if water_level 1.8
			{able "sinking" 1}
		}
	}
(include "tank/tank_h_heavy_spa.inc")
}

{"sheavy tank"
	{inflammation_time 35}
	{on blast_hit
		{if min_energy 38
			{impulse up 0.01 0.01 dir 0.3 0.1}
			{if volume "turret"
				{if rand 0.9
					{call "tear_turret"}
				}
			}
		else min_energy 36
			{impulse up 0.01 0.01 dir 0.3 0.1}
			{if volume "turret"
				{if rand 0.5
					{call "tear_turret"}
				}
			}
		 else min_energy 24
			{impulse up 0.01 0.01 dir 0.3 0.1}
			{if volume "turret"
				{if rand 0.05
					{call "tear_turret"}
				}
			}
		 else min_energy 15
		 	;{ani_play "hit"}
		}
	}
	{on "_explosion"
        {blastwave c4 15 r0 2.5 r1 10}
		{impulse up 1 1 dir 0.2 0.2}
	}
	{on "check_water_level" overload
		{if water_level 2.3
			{able "sinking" 1}
		}
	}
(include "tank/tank_sheavy.inc")
}

{"sheavy_spa tank"
	{inflammation_time 35}
	{on blast_hit
		{if min_energy 38
			{impulse up 0.01 0.01 dir 0.3 0.1}
			{if volume "turret"
				{if rand 0
					{call "tear_turret"}
				}
			}
		else min_energy 36
			{impulse up 0.01 0.01 dir 0.3 0.1}
			{if volume "turret"
				{if rand 0
					{call "tear_turret"}
				}
			}
		 else min_energy 24
			{impulse up 0.01 0.01 dir 0.3 0.1}
			{if volume "turret"
				{if rand 0
					{call "tear_turret"}
				}
			}
		 else min_energy 15
		 	;{ani_play "hit"}
		}
	}
	{on "_explosion"
        {blastwave c4 15 r0 2.5 r1 10}
		{impulse up 1 1 dir 0.2 0.2}
	}
	{on "check_water_level" overload
		{if water_level 2.3
			{able "sinking" 1}
		}
	}
(include "tank/tank_sheavy_spa.inc")
}

{"fighter_av"
(include "tank/fighter_av.inc")
}

{"attacker_av"
(include "tank/attacker_av.inc")
}

{"transport_av"
(include "tank/transport_av.inc")
}

{"car_ddd"
(include "tank/car_ddd.inc")
}

{"marin_ddd"
(include "tank/marin_ddd.inc")
}

{"tank" ;//переопредел€ем дл€ 5-башенных
;   {friction 1}
;   {restitution 0.3}
   (include "tank/general_scripts_defines.inc")

;MEGA BUILDING BEGIN
=============================================================================================================================================================================
    (define "damage_process_pierce" ;by Svoyak  ;define's call's see in tank_heavy_t35.inc.
;=================================
                {if stuff "%staff"
                    ("gun_hit" rand(%pierce_gun))
;///////Engineer_Den + ////////////////	
		    ("gun2_hit" rand(%pierce_gun2))
		    ("gun3_hit" rand(%pierce_gun3))
;///////Engineer_Den - ////////////////	
                    ("track_hit" max_rand(%pierce_front_back_track) min_rand(%pierce_left_right_track))
                        ;(mod "mp"
                                {if volume "body"
                                    {burn fx "smoke_dead_tank3" fake}

                                    {if rand %pierce_body__kill_charger {kill_crew "charger"}}
                                    {if rand %pierce_body__kill_driver {kill_crew "driver"}}
                                    {if rand %pierce_body__kill_gunner {kill_crew "gunner"}}
                                    {if rand %pierce_body__kill_commander {kill_crew "commander"}}
                                    {if rand %pierce_body__kill_gunner2 {kill_crew "gunner2"}}
;///////Engineer_Den + ////////////////	
{if rand %pierce_body__kill_radist {kill_crew "radist"}}

{if rand %pierce_body__kill_gunner3 {kill_crew "gunner3"}}
{if rand %pierce_body__kill_gunner4 {kill_crew "gunner4"}}
{if rand %pierce_body__kill_gunner5 {kill_crew "gunner5"}}
{if rand %pierce_body__kill_gunner6 {kill_crew "gunner6"}}
{if rand %pierce_body__kill_charger5 {kill_crew "charger5"}}
{if rand %pierce_body__kill_charger6 {kill_crew "charger6"}}        

;///////Engineer_Den - ////////////////	
                                    {if not tagged "destroyed"
                                        {if rand %pierce_body__body_brake
                                                {if work "body"
                                                        {components "body" break}
														{unlink_trailer}
                                                        {call "stat_body_break"}
                                                        {damage_report "body" "component/body_break"}
                                                        ;{if work "turret"
                                                            ;{ik_enable "turret" 0}
                                                        ;}
                                                        {delay 2
                                                            {crew_emit}
                                                        }
                                                        {delay 4
                                                            {crew_emit}
                                                        }
                                                        {delay 6
                                                            {crew_emit}
                                                        }
                                                        {able "select" 0}
                                                }
                                        else rand %pierce_body__body_destroy
                                                {call "mp_destroy"}
                                        else operatable 
                                            {damage_report "body" "component/shock"}
                                        else
                                            {damage_report "body" "component/body_pierced"}
                                        }

                                        ;================симул€ци€ контузии
                                        {if operatable
                                            {if work "mover"
                                                    {chassis_work 0}
                                                    {tags add "stopped"}
                                            }
                                            {if work "turret"
                                                {ik_enable "turret" 0}
                                                {tags add "turr_jummed"}
                                            }
  ;///////Engineer_Den + ////////////////	
		{if work "turret2"
                                                {ik_enable "turret2" 0}
                                                {tags add "turr2_jummed"}
                                }
				{if work "turret3"
                                                {ik_enable "turret3" 0}
                                                {tags add "turr3_jummed"}
                                }
				{if work "turret4"
                                                {ik_enable "turret4" 0}
                                                {tags add "turr4_jummed"}
                                }
				{if work "turret5"
                                                {ik_enable "turret5" 0}
                                                {tags add "turr5_jummed"}
                                }	
                                ;{weapon_work "gun" 0}{weapon_work "gun2" 0}{weapon_work "mgun" 0}{weapon_work "mgun1" 0}{weapon_work "mgun2" 0}{weapon_work "mgun3" 0}
{weapon_work "gun" 0}{weapon_work "gun2" 0}{weapon_work "gun3" 0}{weapon_work "mgun" 0}{weapon_work "mgun1" 0}{weapon_work "mgun2" 0}{weapon_work "mgun3" 0}{weapon_work "mgun4" 0}{weapon_work "mgun5" 0}{weapon_work "mgun6" 0}
;///////Engineer_Den - ////////////////	
                                            {delay %crew_shock_time
                                                {if not tagged "gun_brake"
                                                    {weapon_work "gun" 1}
                                                }
;///////Engineer_Den + ////////////////	
;{weapon_work "gun2" 1}{weapon_work "mgun" 1}{weapon_work "mgun1" 1}{weapon_work "mgun2" 1}{weapon_work "mgun3" 1}
{weapon_work "gun" 1}{weapon_work "gun2" 1}{weapon_work "gun3" 1}{weapon_work "mgun" 1}{weapon_work "mgun1" 1}{weapon_work "mgun2" 1}{weapon_work "mgun3" 1}{weapon_work "mgun4" 1}{weapon_work "mgun5" 1}{weapon_work "mgun6" 1}                                    
;///////Engineer_Den - ////////////////	
                                               {if tagged "stopped"
                                                    {tags remove "stopped"}
                                                    {if work "mover"
                                                        {if not tagged "engine_brake"
                                                            {chassis_work 1}
                                                        }
                                                    }
                                                }
                                                {if tagged "turr_jummed"
                                                    {if tagged "turret_brake"
                                                        {tags remove "turr_jummed"}
                                                    else tagged "turret_stopped_by_body"
                                                        {tags remove "turr_jummed"}
                                                    else
                                                        {tags remove "turr_jummed"}
                                                        {ik_enable "turret" 1}
                                                    }
                                                }
 ;///////Engineer_Den + ////////////////	
			{if tagged "turr2_jummed"
                                                    {if tagged "turret2_brake"
                                                        {tags remove "turr2_jummed"}
                                                    else tagged "turret2_stopped_by_body"
                                                        {tags remove "turr2_jummed"}
                                                    else
                                                        {tags remove "turr2_jummed"}
                                                        {ik_enable "turret2" 1}
                                                    }
                                                }
						{if tagged "turr3_jummed"
                                                    {if tagged "turret3_brake"
                                                        {tags remove "turr3_jummed"}
                                                    else tagged "turret3_stopped_by_body"
                                                        {tags remove "turr3_jummed"}
                                                    else
                                                        {tags remove "turr3_jummed"}
                                                        {ik_enable "turret3" 1}
                                                    }
                                                }
						{if tagged "turr4_jummed"
                                                    {if tagged "turret4_brake"
                                                        {tags remove "turr4_jummed"}
                                                    else tagged "turret4_stopped_by_body"
                                                        {tags remove "turr4_jummed"}
                                                    else
                                                        {tags remove "turr4_jummed"}
                                                        {ik_enable "turret4" 1}
                                                    }
                                                }
						{if tagged "turr5_jummed"
                                                    {if tagged "turret5_brake"
                                                        {tags remove "turr5_jummed"}
                                                    else tagged "turret5_stopped_by_body"
                                                        {tags remove "turr5_jummed"}
                                                    else
                                                        {tags remove "turr5_jummed"}
                                                        {ik_enable "turret5" 1}
                                                    }
                                                }
;///////Engineer_Den - ////////////////		
                                            }

                                        }
                                    }

                                else volume "turret"
                                    {burn fx "smoke_dead_tank3" fake}

                                    {if rand %pierce_turret__explosive
										{call "stat_break"}
                                        {delay 0.5
                                            {call "_explosion"}
                                        }
                                    }
                                    {if hit_side front
                                       {if rand %pierce_turret_front__gun_brake
                                            {if work "gun"
                                                {components "gun" break}
                                                {damage_report "gun" "component/gun_broken"}
                                            }
                                        }

                                        {if rand %pierce_turret_front__turret_brake
                                            {components "turret" break}
                                            {ik_enable "turret" 0}
                                        }

                                    else hit_side back
                                        {if rand %pierce_turret_back__gun_brake
                                            {if work "gun"
                                                {components "gun" break}
                                                {damage_report "gun" "component/gun_broken"}
                                            }
                                        }

                                        {if rand %pierce_turret_back__turret_brake
                                            {components "turret" break}
                                            {ik_enable "turret" 0}
                                        }

                                    else
                                        {if rand %pierce_turret_left_right__gun_brake
                                            {if work "gun"
                                                {components "gun" break}
                                                {damage_report "gun" "component/gun_broken"}
                                            }
                                        }
                                        {if rand %pierce_turret_left_right__turret_brake
                                            {components "turret" break}
                                            {ik_enable "turret" 0}
                                        }
                                    }
                                    {if rand %pierce_turret__kill_charger {kill_crew "charger"}}
                                    {if rand %pierce_turret__kill_driver {kill_crew "driver"}}
                                    {if rand %pierce_turret__kill_gunner {kill_crew "gunner"}}
                                    {if rand %pierce_turret__kill_commander {kill_crew "commander"}}
                                    {if rand %pierce_turret__kill_gunner2 {kill_crew "gunner2"}}

                                    ;==============симул€ци€ контузии
                                    {if operatable
                                                {ik_enable "turret" 0}
                                                {weapon_work "gun" 0}{weapon_work "gun2" 0}{weapon_work "mgun" 0}{weapon_work "mgun1" 0}{weapon_work "mgun2" 0}{weapon_work "mgun3" 0}
                                                {tags add "turr_jummed"}
                                                {delay %crew_shock_time
                                                    {if not tagged "gun_brake"
                                                        {weapon_work "gun" 1}
                                                    }
                                                    {weapon_work "gun2" 1}{weapon_work "mgun" 1}{weapon_work "mgun1" 1}{weapon_work "mgun2" 1}{weapon_work "mgun3" 1}
                                                    {if tagged "turr_jummed"
                                                            {if tagged "turret_brake"
                                                                {tags remove "turr_jummed"}
                                                            else tagged "turret_stopped_by_body"
                                                                {tags remove "turr_jummed"}
                                                            else
                                                                {tags remove "turr_jummed"}
                                                                {ik_enable "turret" 1}
                                                            }
                                                    }
                                                }
                                    }
;///////Engineer_Den + ////////////////	башни 2..5
				 else volume "turret2"
                                    {burn fx "smoke_dead_tank3" fake}

                                    ;{if rand %pierce_turret__explosive
		;{call "stat_break"}
                                       ; {delay 0.5
                                          ;  {call "_explosion"}
                                        ;}
                                    ;}башни 2,3 - пулемЄтные
                                    {if hit_side front                                       

                                        {if rand %pierce_turret2_front__turret2_brake
                                            {components "turret2" break}
                                            {ik_enable "turret2" 0}
                                        }

                                    else hit_side back
                                        
                                        {if rand %pierce_turret2_back__turret2_brake
                                            {components "turret2" break}
                                            {ik_enable "turret2" 0}
                                        }

                                    else
                                        
                                        {if rand %pierce_turret2_left_right__turret2_brake
                                            {components "turret2" break}
                                            {ik_enable "turret2" 0}
                                        }
                                    }
                                    
                                    {if rand %pierce_turret2__kill_gunner3 {kill_crew "gunner3"}}
                                    

                                    ;==============симул€ци€ контузии
                                    {if operatable
                                                {ik_enable "turret2" 0}
                                                {weapon_work "mgun3" 0}
                                                {tags add "turr2_jummed"}
                                                {delay %crew_shock_time                                                    
                                                    {weapon_work "mgun3" 1}
                                                    {if tagged "turr2_jummed"
                                                            {if tagged "turret2_brake"
                                                                {tags remove "turr2_jummed"}
                                                            else tagged "turret2_stopped_by_body"
                                                                {tags remove "turr2_jummed"}
                                                            else
                                                                {tags remove "turr2_jummed"}
                                                                {ik_enable "turret2" 1}
                                                            }
                                                    }
                                                }
                                    }
;----------------------------------------------------------------------
				else volume "turret3"
                                    {burn fx "smoke_dead_tank3" fake}

                                    ;{if rand %pierce_turret__explosive
		;{call "stat_break"}
                                       ; {delay 0.5
                                          ;  {call "_explosion"}
                                        ;}
                                    ;}башни 2,3 - пулемЄтные
                                    {if hit_side front                                       

                                        {if rand %pierce_turret3_front__turret3_brake
                                            {components "turret3" break}
                                            {ik_enable "turret3" 0}
                                        }

                                    else hit_side back
                                        
                                        {if rand %pierce_turret3_back__turret3_brake
                                            {components "turret3" break}
                                            {ik_enable "turret3" 0}
                                        }

                                    else
                                        
                                        {if rand %pierce_turret3_left_right__turret3_brake
                                            {components "turret3" break}
                                            {ik_enable "turret3" 0}
                                        }
                                    }
                                    
                                    {if rand %pierce_turret3__kill_gunner4 {kill_crew "gunner4"}}
                                    

                                    ;==============симул€ци€ контузии
                                    {if operatable
                                                {ik_enable "turret3" 0}
                                                {weapon_work "mgun4" 0}
                                                {tags add "turr2_jummed"}
                                                {delay %crew_shock_time                                                    
                                                    {weapon_work "mgun4" 1}
                                                    {if tagged "turr3_jummed"
                                                            {if tagged "turret3_brake"
                                                                {tags remove "turr3_jummed"}
                                                            else tagged "turret3_stopped_by_body"
                                                                {tags remove "turr3_jummed"}
                                                            else
                                                                {tags remove "turr3_jummed"}
                                                                {ik_enable "turret3" 1}
                                                            }
                                                    }
                                                }
                                    }
;---------------------------------------------------------------------
			else volume "turret4"
                                    {burn fx "smoke_dead_tank3" fake}

                                    {if rand %pierce_turret4__explosive
		{call "stat_break"}
                                        {delay 0.5
                                            {call "_explosion"}
                                        }
                                    }
                                    {if hit_side front
                                       {if rand %pierce_turret4_front__gun2_brake
                                            {if work "gun2"
                                                {components "gun2" break}
                                                {damage_report "gun2" "component/gun2_broken"}
                                            }
                                        }

                                        {if rand %pierce_turret4_front__turret4_brake
                                            {components "turret4" break}
                                            {ik_enable "turret4" 0}
                                        }

                                    else hit_side back
                                        {if rand %pierce_turret4_back__gun2_brake
                                            {if work "gun2"
                                                {components "gun2" break}
                                                {damage_report "gun2" "component/gun2_broken"}
                                            }
                                        }

                                        {if rand %pierce_turret4_back__turret4_brake
                                            {components "turret4" break}
                                            {ik_enable "turret4" 0}
                                        }

                                    else
                                        {if rand %pierce_turret4_left_right__gun2_brake
                                            {if work "gun2"
                                                {components "gun2" break}
                                                {damage_report "gun2" "component/gun2_broken"}
                                            }
                                        }
                                        {if rand %pierce_turret4_left_right__turret4_brake
                                            {components "turret4" break}
                                            {ik_enable "turret4" 0}
                                        }
                                    }
                                    {if rand %pierce_turret4__kill_charger5 {kill_crew "charger5"}}                                    
                                    {if rand %pierce_turret4__kill_gunner5 {kill_crew "gunner5"}}                                    

                                    ;==============симул€ци€ контузии
                                    {if operatable
                                                {ik_enable "turret4" 0}
                                                {weapon_work "gun2" 0}{weapon_work "mgun5" 0} {tags add "turr_jummed"}
                                                {delay %crew_shock_time
                                                    {if not tagged "gun2_brake"
                                                        {weapon_work "gun2" 1}
                                                    }
                                                    {weapon_work "mgun5" 1}
                                                    {if tagged "turr4_jummed"
                                                            {if tagged "turret4_brake"
                                                                {tags remove "turr4_jummed"}
                                                            else tagged "turret4_stopped_by_body"
                                                                {tags remove "turr4_jummed"}
                                                            else
                                                                {tags remove "turr4_jummed"}
                                                                {ik_enable "turret4" 1}
                                                            }
                                                    }
                                                }
                                    }
;-----------------------------------------------------------
				else volume "turret5"
                                    {burn fx "smoke_dead_tank3" fake}

                                    {if rand %pierce_turret5__explosive
		{call "stat_break"}
                                        {delay 0.5
                                            {call "_explosion"}
                                        }
                                    }
                                    {if hit_side front
                                       {if rand %pierce_turret5_front__gun3_brake
                                            {if work "gun3"
                                                {components "gun3" break}
                                                {damage_report "gun3" "component/gun3_broken"}
                                            }
                                        }

                                        {if rand %pierce_turret5_front__turret5_brake
                                            {components "turret5" break}
                                            {ik_enable "turret5" 0}
                                        }

                                    else hit_side back
                                        {if rand %pierce_turret5_back__gun3_brake
                                            {if work "gun3"
                                                {components "gun3" break}
                                                {damage_report "gun3" "component/gun3_broken"}
                                            }
                                        }

                                        {if rand %pierce_turret5_back__turret5_brake
                                            {components "turret5" break}
                                            {ik_enable "turret5" 0}
                                        }

                                    else
                                        {if rand %pierce_turret5_left_right__gun3_brake
                                            {if work "gun3"
                                                {components "gun3" break}
                                                {damage_report "gun3" "component/gun3_broken"}
                                            }
                                        }
                                        {if rand %pierce_turret5_left_right__turret5_brake
                                            {components "turret5" break}
                                            {ik_enable "turret5" 0}
                                        }
                                    }
                                    {if rand %pierce_turret5__kill_charger6 {kill_crew "charger6"}}                                    
                                    {if rand %pierce_turret5__kill_gunner6 {kill_crew "gunner6"}}                                    

                                    ;==============симул€ци€ контузии
                                    {if operatable
                                                {ik_enable "turret5" 0}
                                                {weapon_work "gun3" 0}{weapon_work "mgun6" 0}                                               {tags add "turr_jummed"}
                                                {delay %crew_shock_time
                                                    {if not tagged "gun3_brake"
                                                        {weapon_work "gun3" 1}
                                                    }
                                                    {weapon_work "mgun6" 1}
                                                    {if tagged "turr5_jummed"
                                                            {if tagged "turret5_brake"
                                                                {tags remove "turr5_jummed"}
                                                            else tagged "turret5_stopped_by_body"
                                                                {tags remove "turr5_jummed"}
                                                            else
                                                                {tags remove "turr5_jummed"}
                                                                {ik_enable "turret5" 1}
                                                            }
                                                    }
                                                }
                                    }
;///////Engineer_Den - ////////////////	башни 2..5

                                else volume "mantlet"
                                       {burn fx "smoke_dead_tank3" fake}

                                        {if rand (* %pierce_mantlet__gun_brake 0.1)
                                            {if work "gun"
                                                {components "gun" break}
                                                {damage_report "gun" "component/gun_broken"}
                                            }
										;else
										;	{call "turret_break"}
										}
                                        ;{if rand %pierce_turret_front__turret_brake
                                        ;   {components "turret" break}
                                        ;}

                                else volume "explosive"
                                    {if rand (* %pierce_inventory__explosive 0.4)
                                        {call "explosion"}
                                    }
                                else volume "engine"
                                    {if rand %pierce_engine__engine_brake
                                        {if work "engine"
                                            {components "engine" break}
                                        }
                                        {if rand %pierce_engine__engine_burn
                                            {delay 3 2
                                                {call "_burn"}
                                            }
                                        }
                                    }
                                }
                        ;)
                };stuff
    )
    (define "damage_process_bullet_hit" ;by Svoyak
;====================================
                    {if stuff "%staff"
                    {impulse dir %imp}
                    ;{if hit_angle > %angle_hit
                        {if volume "body"
                                {if rand %hit_body__explosive
                                    {call "explosion"}
                                }
                                {if rand %hit_body__engine_brake
                                    {if work "engine"
                                        {components "engine" break}
                                    }
                                }
                                {if rand %hit_body__body_destroy
                                    {call "mp_destroy"}
                                else rand %hit_body__body_brake
                                    {components "body" break}
                                    {damage_report "body" "component/body_break"}
                                }
                            
                        else volume "engine"
                                {if rand %hit_body__explosive
                                    {call "explosion"}
                                }
                                {if rand %hit_engine__engine_brake
                                    {if work "engine"
                                        {components "engine" break}
                                    }
                                }
                                {if rand %hit_body__body_brake
                                    {components "body" break}
                                    {damage_report "body" "component/body_break"}
                                }
                        else volume "turret"
                                {if rand %hit_turret__explosive
                                    {call "explosion"}
                                }
                                {if hit_side front
                                    {if rand %hit_turret_front__gun_brake
                                        {if work "gun"
                                            {components "gun" break}
                                            {damage_report "gun" "component/gun_broken"}
                                        }
                                    }
                                }
                                {if rand %hit_turret__turret_destroy
                                    {components "turret" destroy}
                                else rand %hit_turret__turret_brake
                                    {components "turret" break}
                                }
                        else volume "wheel"
                                {if rand %hit_body__explosive
                                    {call "explosion"}
                                }
                                {if rand %hit_body__engine_brake
                                    {if work "engine"
                                        {components "engine" break}
                                    }
                                }
                                {if rand %hit_body__body_destroy
                                    {call "mp_destroy"}
                                else rand %hit_body__body_brake
                                    {components "body" break}
                                    {damage_report "body" "component/body_break"}
                                }
                        else volume "track"
                                {if rand %hit_body__explosive
                                    {call "explosion"}
                                }
                                {if rand %hit_body__engine_brake
                                    {if work "engine"
                                        {components "engine" break}
                                    }
                                }
                                {if rand %hit_body__body_destroy
                                    {call "mp_destroy"}
                                else rand %hit_body__body_brake
                                    {components "body" break}
                                    {damage_report "body" "component/body_break"}
                                }								
;///////Engineer_Den + ////////////////	
 			else volume "turret2"                               
                                {if rand %hit_turret2__turret2_destroy
                                    {components "turret2" destroy}
                                else rand %hit_turret2__turret2_brake
                                    {components "turret2" break}
                                }
;----------------------------------------------
			else volume "turret3"                               
                                {if rand %hit_turret3__turret3_destroy
                                    {components "turret3" destroy}
                                else rand %hit_turret3__turret3_brake
                                    {components "turret3" break}
                                }
;-----------------------------------------------
			else volume "turret4"
                                {if rand %hit_turret4__explosive
                                    {call "explosion"}
                                }
                                {if hit_side front
                                    {if rand %hit_turret4_front__gun2_brake
                                        {if work "gun2"
                                            {components "gun2" break}
                                            {damage_report "gun2" "component/gun2_broken"}
                                        }
                                    }
                                }
                                {if rand %hit_turret4__turret4_destroy
                                    {components "turret4" destroy}
                                else rand %hit_turret4__turret4_brake
                                    {components "turret4" break}
                                }
;-------------------------------------------------
			else volume "turret5"
                                {if rand %hit_turret5__explosive
                                    {call "explosion"}
                                }
                                {if hit_side front
                                    {if rand %hit_turret5_front__gun3_brake
                                        {if work "gun3"
                                            {components "gun3" break}
                                            {damage_report "gun3" "component/gun3_broken"}
                                        }
                                    }
                                }
                                {if rand %hit_turret5__turret5_destroy
                                    {components "turret5" destroy}
                                else rand %hit_turret5__turret5_brake
                                    {components "turret5" break}
                                }
;///////Engineer_Den - ////////////////	
                        else volume "mantlet"
                                {if rand %hit_turret__explosive
                                    {call "explosion"}
                                }
                                {if rand %hit_turret_front__gun_brake
                                    {if work "gun"
                                        {components "gun" break}
                                        {damage_report "gun" "component/gun_broken"}
                                    }
                                }
                                {if rand %hit_turret__turret_destroy
                                    {components "turret" destroy}
                                else rand %hit_turret__turret_brake
                                    {components "turret" break}
                                }
                        }
                    ;};if hit_angle end
                    }; stuff
;=====================================
    )

    (define "blast_damage_contusion" ;by Svoyak
        {if volume "trackleft"
            ;do nothing
        else volume "trackright"
            ;do nothing
        else volume "roller"
            ;do nothing
        else volume "wheel_work"
            ;do nothing
        else volume "wheel"
            ;do nothing
        else
            {if operatable
                {if not "already_blasted"
            
                    {if min_energy %blast_energy
                        {set "already_blasted" 1}
                        {if rand %blast_rand_contusion
                            {delay 0.5
                                {set "already_blasted" 0}
                            }
                            ;{con "%blast_energy"}
                            {damage_report "body" "component/shock"}
                            {chassis_work 0}
                            {tags add "stopped1"}
                            
                            {if work "turret"
                                {ik_enable "turret" 0}
                                {tags add "turr_jummed1"}
                            }
;///////Engineer_Den + ////////////////
			    {if work "turret2"
                                {ik_enable "turret2" 0}
                                {tags add "turr2_jummed1"}
                            } 
			    {if work "turret3"
                                {ik_enable "turret3" 0}
                                {tags add "turr3_jummed1"}
                            } 
			    {if work "turret4"
                                {ik_enable "turret4" 0}
                                {tags add "turr4_jummed1"}
                            } 
			    {if work "turret5"
                                {ik_enable "turret5" 0}
                                {tags add "turr5_jummed1"}
                            }	 	
                            ;{weapon_work "gun" 0}{weapon_work "gun2" 0}{weapon_work "mgun" 0}{weapon_work "mgun1" 0}{weapon_work "mgun2" 0}{weapon_work "mgun3" 0}
{weapon_work "gun" 0}{weapon_work "gun2" 0}{weapon_work "gun3" 0}{weapon_work "mgun" 0}{weapon_work "mgun1" 0}{weapon_work "mgun2" 0}{weapon_work "mgun3" 0}{weapon_work "mgun4" 0}{weapon_work "mgun5" 0}{weapon_work "mgun6" 0}

;///////Engineer_Den - ////////////////
                                  {delay %blast_crew_shock_time
                                {if not tagged "gun_brake"
                                    {weapon_work "gun" 1}
                                }
                              ;///////Engineer_Den + ////////////////
				{if not tagged "gun2_brake"
                                    {weapon_work "gun2" 1}
                                }
				{if not tagged "gun3_brake"
                                    {weapon_work "gun3" 1}
                                }
                                ;{weapon_work "gun2" 1}{weapon_work "mgun" 1}{weapon_work "mgun1" 1}{weapon_work "mgun2" 1}{weapon_work "mgun3" 1}
		{weapon_work "mgun" 1}{weapon_work "mgun1" 1}{weapon_work "mgun2" 1}{weapon_work "mgun3" 1}{weapon_work "mgun4" 1}{weapon_work "mgun5" 1}{weapon_work "mgun6" 1}
                                
;///////Engineer_Den - ////////////////
  	  {if tagged "stopped1"
                                    {tags remove "stopped1"}
                                    {if work "mover"
                                        {if not tagged "engine_brake"
                                            {chassis_work 1}
                                        }
                                    }
                                }
                                {if tagged "turr_jummed1"
                                        {if tagged "turret_brake"
                                            {tags remove "turr_jummed1"}
                                            
                                        else tagged "turret_stopped_by_body"
                                            {tags remove "turr_jummed1"}
                                        else
                                            {tags remove "turr_jummed1"}
                                            {ik_enable "turret" 1}
                                        }
                                }
;///////Engineer_Den + ////////////////
				{if tagged "turr2_jummed1"
                                        {if tagged "turret2_brake"
                                            {tags remove "turr2_jummed1"}
                                            
                                        else tagged "turret2_stopped_by_body"
                                            {tags remove "turr2_jummed1"}
                                        else
                                            {tags remove "turr2_jummed1"}
                                            {ik_enable "turret2" 1}
                                        }
                                }							
				{if tagged "turr3_jummed1"
                                        {if tagged "turret3_brake"
                                            {tags remove "turr3_jummed1"}
                                            
                                        else tagged "turret3_stopped_by_body"
                                            {tags remove "turr3_jummed1"}
                                        else
                                            {tags remove "turr3_jummed1"}
                                            {ik_enable "turret3" 1}
                                        }
                                }
				{if tagged "turr4_jummed1"
                                        {if tagged "turret4_brake"
                                            {tags remove "turr4_jummed1"}
                                            
                                        else tagged "turret4_stopped_by_body"
                                            {tags remove "turr4_jummed1"}
                                        else
                                            {tags remove "turr4_jummed1"}
                                            {ik_enable "turret4" 1}
                                        }
                                }							
				{if tagged "turr5_jummed1"
                                        {if tagged "turret5_brake"
                                            {tags remove "turr5_jummed1"}
                                            
                                        else tagged "turret5_stopped_by_body"
                                            {tags remove "turr5_jummed1"}
                                        else
                                            {tags remove "turr5_jummed1"}
                                            {ik_enable "turret5" 1}
                                        }
                                }
				
;///////Engineer_Den - ////////////////
                            }
                        else
                            {delay 0.5
                                {set "already_blasted" 0}
                            }
                        }
                    }
                }
            }
        }
        
    )
;MEGA BUILDING END ======= инженер ƒен очень рад окончанию этого звиздеца======================================================================================================================================================================

    {on repair
	    {if component "turret"
    		{view stop "smoke3"}
            {call "update_turret"}
            {tags remove "turret_brake"}
;///////Engineer_Den + ////////////////
	else component "turret2"
    		{view stop "smoke7"}
            {call "update_turret2"}
            {tags remove "turret2_brake"}
	else component "turret3"
    		{view stop "smoke8"}
            {call "update_turret3"}
            {tags remove "turret3_brake"}
	else component "turret4"
    		{view stop "smoke12"}
            {call "update_turret4"}
            {tags remove "turret4_brake"}
	else component "turret5"
    		{view stop "smoke11"}
            {call "update_turret5"}
            {tags remove "turret5_brake"}
;///////Engineer_Den - ////////////////
        else component "body"
            {view stop "smoke4"}
            {call "update_turret"}
            {tags remove "turret_stopped_by_body"}
            {tags remove "body_brake"}
            {able "select" 1}
        else component "engine"
            {tags remove "engine_brake"}
        }
    }
	{on "update_turret"
		{if work "turret"
			{if work "body"
				{ik_enable "turret" 1}
			 else
				{ik_enable "turret" 0}
			}
		 else
			{ik_enable "turret" 0}
		}
    }
;///////Engineer_Den + ////////////////башни є2...5 не бокируютс€ при повреждении корпуса
	{on "update_turret2"
		{if work "turret2"
			{if work "body"
				{ik_enable "turret2" 1}
			 else
				{ik_enable "turret2" 1}
			}
		 else
			{ik_enable "turret2" 0}
		}
    	}
	{on "update_turret3"
		{if work "turret3"
			{if work "body"
				{ik_enable "turret3" 1}
			 else
				{ik_enable "turret3" 1}
			}
		 else
			{ik_enable "turret3" 0}
		}
    	}
	{on "update_turret4"
		{if work "turret4"
			{if work "body"
				{ik_enable "turret4" 1}
			 else
				{ik_enable "turret4" 1}
			}
		 else
			{ik_enable "turret4" 0}
		}
    	}
	{on "update_turret5"
		{if work "turret5"
			{if work "body"
				{ik_enable "turret5" 1}
			 else
				{ik_enable "turret5" 1}
			}
		 else
			{ik_enable "turret5" 0}
		}
    	}
;///////Engineer_Den - ////////////////
}; end of "tank" //переопредел€ем дл€ 5-башенных


{"heavy_t35 tank"
	{inflammation_time 20}
	{on fire "gun"
      		{spawn "dust_shot_big" "basis"}
     		 {spawn "tank_canon_fire" "Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone "Foresight1"}
	}	
	
	{on blast_hit
		{if min_energy 36
			{impulse up 0.25 0.05 dir 2.5 0.1}
			{if volume "turret"
				{if rand 0.95
					{call "tear_turret"}
				}
			}
		else min_energy 24
			{impulse up 0.15 0.05 dir 0.35 0.1}
			{if volume "turret"
				{if rand 0.7
					{call "tear_turret"}
				}
			}
		 else min_energy 15
			{impulse up 0.1 0.05 dir 0.3 0.1}
			{if volume "turret"
				{if rand 0.2
					{call "tear_turret"}
				}
			}
		 else min_energy 6
		 	;{ani_play "hit"}
		}
	}
	{on "_explosion"
        {blastwave c4 15 r0 2.5 r1 10}
		{impulse up 1 1 dir 0.2 0.2}
	}
	{on "check_water_level" overload
		{if water_level 1.8
			{able "sinking" 1}
		}
	}
(include "tank/tank_heavy_t35.inc")
}

{"tank"; перегружаем функцию дл€ применени€ в 3-башенных танках
;   {friction 1}
;   {restitution 0.3}
   (include "tank/general_scripts_defines.inc")

;MEGA BUILDING BEGIN
=============================================================================================================================================================================
    (define "damage_process_pierce" ;by Svoyak  ;define's call's see in  tank_medium_t28.inc.
;=================================
                {if stuff "%staff"
                    ("gun_hit" rand(%pierce_gun))
                    ("track_hit" max_rand(%pierce_front_back_track) min_rand(%pierce_left_right_track))
                        ;(mod "mp"
                                {if volume "body"
                                    {burn fx "smoke_dead_tank3" fake}

                                    {if rand %pierce_body__kill_charger {kill_crew "charger"}}
                                    {if rand %pierce_body__kill_driver {kill_crew "driver"}}
                                    {if rand %pierce_body__kill_gunner {kill_crew "gunner"}}
                                    {if rand %pierce_body__kill_commander {kill_crew "commander"}}
                                    {if rand %pierce_body__kill_gunner2 {kill_crew "gunner2"}}
;///////Engineer_Den + ////////////////	
{if rand %pierce_body__kill_radist {kill_crew "radist"}}

{if rand %pierce_body__kill_gunner3 {kill_crew "gunner3"}}
{if rand %pierce_body__kill_gunner4 {kill_crew "gunner4"}}      

;///////Engineer_Den - ////////////////	
                                    {if not tagged "destroyed"
                                        {if rand %pierce_body__body_brake
                                                {if work "body"
                                                        {components "body" break}
														{unlink_trailer}
                                                        {call "stat_body_break"}
                                                        {damage_report "body" "component/body_break"}
                                                        ;{if work "turret"
                                                            ;{ik_enable "turret" 0}
                                                        ;}
                                                        {delay 2
                                                            {crew_emit}
                                                        }
                                                        {delay 4
                                                            {crew_emit}
                                                        }
                                                        {delay 6
                                                            {crew_emit}
                                                        }
                                                        {able "select" 0}
                                                }
                                        else rand %pierce_body__body_destroy
                                                {call "mp_destroy"}
                                        else operatable 
                                            {damage_report "body" "component/shock"}
                                        else
                                            {damage_report "body" "component/body_pierced"}
                                        }

                                        ;================симул€ци€ контузии
                                        {if operatable
                                            {if work "mover"
                                                    {chassis_work 0}
                                                    {tags add "stopped"}
                                            }
                                            {if work "turret"
                                                {ik_enable "turret" 0}
                                                {tags add "turr_jummed"}
                                            }
  ;///////Engineer_Den + ////////////////	
		{if work "turret2"
                                                {ik_enable "turret2" 0}
                                                {tags add "turr2_jummed"}
                                     }
				{if work "turret3"
                                                {ik_enable "turret3" 0}
                                                {tags add "turr3_jummed"}
                                      }
				
                                ;{weapon_work "gun" 0}{weapon_work "gun2" 0}{weapon_work "mgun" 0}{weapon_work "mgun1" 0}{weapon_work "mgun2" 0}{weapon_work "mgun3" 0}
{weapon_work "gun" 0}{weapon_work "mgun" 0}{weapon_work "mgun1" 0}{weapon_work "mgun2" 0}{weapon_work "mgun3" 0}{weapon_work "mgun4" 0}
;///////Engineer_Den - ////////////////	
                                            {delay %crew_shock_time
                                                {if not tagged "gun_brake"
                                                    {weapon_work "gun" 1}
                                                }
;///////Engineer_Den + ////////////////	
;{weapon_work "gun2" 1}{weapon_work "mgun" 1}{weapon_work "mgun1" 1}{weapon_work "mgun2" 1}{weapon_work "mgun3" 1}
{weapon_work "gun" 1}{weapon_work "mgun" 1}{weapon_work "mgun1" 1}{weapon_work "mgun2" 1}{weapon_work "mgun3" 1}{weapon_work "mgun4" 1}                                    
;///////Engineer_Den - ////////////////	
                                               {if tagged "stopped"
                                                    {tags remove "stopped"}
                                                    {if work "mover"
                                                        {if not tagged "engine_brake"
                                                            {chassis_work 1}
                                                        }
                                                    }
                                                }
                                                {if tagged "turr_jummed"
                                                    {if tagged "turret_brake"
                                                        {tags remove "turr_jummed"}
                                                    else tagged "turret_stopped_by_body"
                                                        {tags remove "turr_jummed"}
                                                    else
                                                        {tags remove "turr_jummed"}
                                                        {ik_enable "turret" 1}
                                                    }
                                                }
 ;///////Engineer_Den + ////////////////	
			{if tagged "turr2_jummed"
                                                    {if tagged "turret2_brake"
                                                        {tags remove "turr2_jummed"}
                                                    else tagged "turret2_stopped_by_body"
                                                        {tags remove "turr2_jummed"}
                                                    else
                                                        {tags remove "turr2_jummed"}
                                                        {ik_enable "turret2" 1}
                                                    }
                                                }
						{if tagged "turr3_jummed"
                                                    {if tagged "turret3_brake"
                                                        {tags remove "turr3_jummed"}
                                                    else tagged "turret3_stopped_by_body"
                                                        {tags remove "turr3_jummed"}
                                                    else
                                                        {tags remove "turr3_jummed"}
                                                        {ik_enable "turret3" 1}
                                                    }
                                                }
						
;///////Engineer_Den - ////////////////		
                                            }

                                        }
                                    }

                                else volume "turret"
                                    {burn fx "smoke_dead_tank3" fake}

                                    {if rand %pierce_turret__explosive
		     {call "stat_break"}
                                        {delay 0.5
                                            {call "_explosion"}
                                        }
                                    }
                                    {if hit_side front
                                       {if rand %pierce_turret_front__gun_brake
                                            {if work "gun"
                                                {components "gun" break}
                                                {damage_report "gun" "component/gun_broken"}
                                            }
                                        }

                                        {if rand %pierce_turret_front__turret_brake
                                            {components "turret" break}
                                            {ik_enable "turret" 0}
                                        }

                                    else hit_side back
                                        {if rand %pierce_turret_back__gun_brake
                                            {if work "gun"
                                                {components "gun" break}
                                                {damage_report "gun" "component/gun_broken"}
                                            }
                                        }

                                        {if rand %pierce_turret_back__turret_brake
                                            {components "turret" break}
                                            {ik_enable "turret" 0}
                                        }

                                    else
                                        {if rand %pierce_turret_left_right__gun_brake
                                            {if work "gun"
                                                {components "gun" break}
                                                {damage_report "gun" "component/gun_broken"}
                                            }
                                        }
                                        {if rand %pierce_turret_left_right__turret_brake
                                            {components "turret" break}
                                            {ik_enable "turret" 0}
                                        }
                                    }
                                    {if rand %pierce_turret__kill_charger {kill_crew "charger"}}
                                    {if rand %pierce_turret__kill_driver {kill_crew "driver"}}
                                    {if rand %pierce_turret__kill_gunner {kill_crew "gunner"}}
                                    {if rand %pierce_turret__kill_commander {kill_crew "commander"}}
                                    {if rand %pierce_turret__kill_gunner2 {kill_crew "gunner2"}}

                                    ;==============симул€ци€ контузии
                                    {if operatable
                                                {ik_enable "turret" 0}
                                                {weapon_work "gun" 0}{weapon_work "gun2" 0}{weapon_work "mgun" 0}{weapon_work "mgun1" 0}{weapon_work "mgun2" 0}{weapon_work "mgun3" 0}
                                                {tags add "turr_jummed"}
                                                {delay %crew_shock_time
                                                    {if not tagged "gun_brake"
                                                        {weapon_work "gun" 1}
                                                    }
                                                    {weapon_work "gun2" 1}{weapon_work "mgun" 1}{weapon_work "mgun1" 1}{weapon_work "mgun2" 1}{weapon_work "mgun3" 1}
                                                    {if tagged "turr_jummed"
                                                            {if tagged "turret_brake"
                                                                {tags remove "turr_jummed"}
                                                            else tagged "turret_stopped_by_body"
                                                                {tags remove "turr_jummed"}
                                                            else
                                                                {tags remove "turr_jummed"}
                                                                {ik_enable "turret" 1}
                                                            }
                                                    }
                                                }
                                    }
;///////Engineer_Den + ////////////////	башни 2..3
		 else volume "turret2"
                                    {burn fx "smoke_dead_tank3" fake}

                                    ;{if rand %pierce_turret__explosive
		;{call "stat_break"}
                                       ; {delay 0.5
                                          ;  {call "_explosion"}
                                        ;}
                                    ;}башни 2,3 - пулемЄтные
                                    {if hit_side front                                       

                                        {if rand %pierce_turret2_front__turret2_brake
                                            {components "turret2" break}
                                            {ik_enable "turret2" 0}
                                        }

                                    else hit_side back
                                        
                                        {if rand %pierce_turret2_back__turret2_brake
                                            {components "turret2" break}
                                            {ik_enable "turret2" 0}
                                        }

                                    else
                                        
                                        {if rand %pierce_turret2_left_right__turret2_brake
                                            {components "turret2" break}
                                            {ik_enable "turret2" 0}
                                        }
                                    }
                                    
                                    {if rand %pierce_turret2__kill_gunner3 {kill_crew "gunner3"}}
                                    

                                    ;==============симул€ци€ контузии
                                    {if operatable
                                                {ik_enable "turret2" 0}
                                                {weapon_work "mgun3" 0}
                                                {tags add "turr2_jummed"}
                                                {delay %crew_shock_time                                                    
                                                    {weapon_work "mgun3" 1}
                                                    {if tagged "turr2_jummed"
                                                            {if tagged "turret2_brake"
                                                                {tags remove "turr2_jummed"}
                                                            else tagged "turret2_stopped_by_body"
                                                                {tags remove "turr2_jummed"}
                                                            else
                                                                {tags remove "turr2_jummed"}
                                                                {ik_enable "turret2" 1}
                                                            }
                                                    }
                                                }
                                    }
;----------------------------------------------------------------------
				else volume "turret3"
                                    {burn fx "smoke_dead_tank3" fake}

                                    ;{if rand %pierce_turret__explosive
		;{call "stat_break"}
                                       ; {delay 0.5
                                          ;  {call "_explosion"}
                                        ;}
                                    ;}башни 2,3 - пулемЄтные
                                    {if hit_side front                                       

                                        {if rand %pierce_turret3_front__turret3_brake
                                            {components "turret3" break}
                                            {ik_enable "turret3" 0}
                                        }

                                    else hit_side back
                                        
                                        {if rand %pierce_turret3_back__turret3_brake
                                            {components "turret3" break}
                                            {ik_enable "turret3" 0}
                                        }

                                    else
                                        
                                        {if rand %pierce_turret3_left_right__turret3_brake
                                            {components "turret3" break}
                                            {ik_enable "turret3" 0}
                                        }
                                    }
                                    
                                    {if rand %pierce_turret3__kill_gunner4 {kill_crew "gunner4"}}
                                    

                                    ;==============симул€ци€ контузии
                                    {if operatable
                                                {ik_enable "turret3" 0}
                                                {weapon_work "mgun4" 0}
                                                {tags add "turr2_jummed"}
                                                {delay %crew_shock_time                                                    
                                                    {weapon_work "mgun4" 1}
                                                    {if tagged "turr3_jummed"
                                                            {if tagged "turret3_brake"
                                                                {tags remove "turr3_jummed"}
                                                            else tagged "turret3_stopped_by_body"
                                                                {tags remove "turr3_jummed"}
                                                            else
                                                                {tags remove "turr3_jummed"}
                                                                {ik_enable "turret3" 1}
                                                            }
                                                    }
                                                }
                                    }
;---------------------------------------------------------------------
	
;///////Engineer_Den - ////////////////	башни 2..3

                                else volume "mantlet"
                                       {burn fx "smoke_dead_tank3" fake}

                                        {if rand (* %pierce_mantlet__gun_brake 0.1)
                                            {if work "gun"
                                                {components "gun" break}
                                                {damage_report "gun" "component/gun_broken"}
                                            }
										;else
										;	{call "turret_break"}
										}
                                        ;{if rand %pierce_turret_front__turret_brake
                                        ;   {components "turret" break}
                                        ;}

                                else volume "explosive"
                                    {if rand (* %pierce_inventory__explosive 0.4)
                                        {call "explosion"}
                                    }
                                else volume "engine"
                                    {if rand %pierce_engine__engine_brake
                                        {if work "engine"
                                            {components "engine" break}
                                        }
                                        {if rand %pierce_engine__engine_burn
                                            {delay 3 2
                                                {call "_burn"}
                                            }
                                        }
                                    }
                                }
                        ;)
                };stuff
    )
    (define "damage_process_bullet_hit" ;by Svoyak
;====================================
                    {if stuff "%staff"
                    {impulse dir %imp}
                    ;{if hit_angle > %angle_hit
                        {if volume "body"
                                {if rand %hit_body__explosive
                                    {call "explosion"}
                                }
                                {if rand %hit_body__engine_brake
                                    {if work "engine"
                                        {components "engine" break}
                                    }
                                }
                                {if rand %hit_body__body_destroy
                                    {call "mp_destroy"}
                                else rand %hit_body__body_brake
                                    {components "body" break}
                                    {damage_report "body" "component/body_break"}
                                }
                            
                        else volume "engine"
                                {if rand %hit_body__explosive
                                    {call "explosion"}
                                }
                                {if rand %hit_engine__engine_brake
                                    {if work "engine"
                                        {components "engine" break}
                                    }
                                }
                                {if rand %hit_body__body_brake
                                    {components "body" break}
                                    {damage_report "body" "component/body_break"}
                                }
                        else volume "turret"
                                {if rand %hit_turret__explosive
                                    {call "explosion"}
                                }
                                {if hit_side front
                                    {if rand %hit_turret_front__gun_brake
                                        {if work "gun"
                                            {components "gun" break}
                                            {damage_report "gun" "component/gun_broken"}
                                        }
                                    }
                                }
                                {if rand %hit_turret__turret_destroy
                                    {components "turret" destroy}
                                else rand %hit_turret__turret_brake
                                    {components "turret" break}
                                }
                        else volume "wheel"
                                {if rand %hit_body__explosive
                                    {call "explosion"}
                                }
                                {if rand %hit_body__engine_brake
                                    {if work "engine"
                                        {components "engine" break}
                                    }
                                }
                                {if rand %hit_body__body_destroy
                                    {call "mp_destroy"}
                                else rand %hit_body__body_brake
                                    {components "body" break}
                                    {damage_report "body" "component/body_break"}
                                }
                        else volume "track"
                                {if rand %hit_body__explosive
                                    {call "explosion"}
                                }
                                {if rand %hit_body__engine_brake
                                    {if work "engine"
                                        {components "engine" break}
                                    }
                                }
                                {if rand %hit_body__body_destroy
                                    {call "mp_destroy"}
                                else rand %hit_body__body_brake
                                    {components "body" break}
                                    {damage_report "body" "component/body_break"}
                                }								
;///////Engineer_Den + ////////////////	
 			else volume "turret2"                               
                                {if rand %hit_turret2__turret2_destroy
                                    {components "turret2" destroy}
                                else rand %hit_turret2__turret2_brake
                                    {components "turret2" break}
                                }
;----------------------------------------------
			else volume "turret3"                               
                                {if rand %hit_turret3__turret3_destroy
                                    {components "turret3" destroy}
                                else rand %hit_turret3__turret3_brake
                                    {components "turret3" break}
                                }
;-----------------------------------------------			
		
;///////Engineer_Den - ////////////////	
                        else volume "mantlet"
                                {if rand %hit_turret__explosive
                                    {call "explosion"}
                                }
                                {if rand %hit_turret_front__gun_brake
                                    {if work "gun"
                                        {components "gun" break}
                                        {damage_report "gun" "component/gun_broken"}
                                    }
                                }
                                {if rand %hit_turret__turret_destroy
                                    {components "turret" destroy}
                                else rand %hit_turret__turret_brake
                                    {components "turret" break}
                                }
                        }
                    ;};if hit_angle end
                    }; stuff
;=====================================
    )

    (define "blast_damage_contusion" ;by Svoyak
        {if volume "trackleft"
            ;do nothing
        else volume "trackright"
            ;do nothing
        else volume "roller"
            ;do nothing
        else volume "wheel_work"
            ;do nothing
        else volume "wheel"
            ;do nothing
        else
            {if operatable
                {if not "already_blasted"
            
                    {if min_energy %blast_energy
                        {set "already_blasted" 1}
                        {if rand %blast_rand_contusion
                            {delay 0.5
                                {set "already_blasted" 0}
                            }
                            ;{con "%blast_energy"}
                            {damage_report "body" "component/shock"}
                            {chassis_work 0}
                            {tags add "stopped1"}
                            
                            {if work "turret"
                                {ik_enable "turret" 0}
                                {tags add "turr_jummed1"}
                            }
;///////Engineer_Den + ////////////////
			    {if work "turret2"
                                {ik_enable "turret2" 0}
                                {tags add "turr2_jummed1"}
                            } 
			    {if work "turret3"
                                {ik_enable "turret3" 0}
                                {tags add "turr3_jummed1"}
                            } 	    
                            ;{weapon_work "gun" 0}{weapon_work "gun2" 0}{weapon_work "mgun" 0}{weapon_work "mgun1" 0}{weapon_work "mgun2" 0}{weapon_work "mgun3" 0}
{weapon_work "gun" 0}{weapon_work "mgun" 0}{weapon_work "mgun1" 0}{weapon_work "mgun2" 0}{weapon_work "mgun3" 0}{weapon_work "mgun4" 0}

;///////Engineer_Den - ////////////////
                                  {delay %blast_crew_shock_time
                                {if not tagged "gun_brake"
                                    {weapon_work "gun" 1}
                                }
;///////Engineer_Den + ////////////////
		 ;{weapon_work "gun2" 1}{weapon_work "mgun" 1}{weapon_work "mgun1" 1}{weapon_work "mgun2" 1}{weapon_work "mgun3" 1}
		{weapon_work "mgun" 1}{weapon_work "mgun1" 1}{weapon_work "mgun2" 1}{weapon_work "mgun3" 1}{weapon_work "mgun4" 1}
                                
;///////Engineer_Den - ////////////////
  	  {if tagged "stopped1"
                                    {tags remove "stopped1"}
                                    {if work "mover"
                                        {if not tagged "engine_brake"
                                            {chassis_work 1}
                                        }
                                    }
                                }
                                {if tagged "turr_jummed1"
                                        {if tagged "turret_brake"
                                            {tags remove "turr_jummed1"}
                                            
                                        else tagged "turret_stopped_by_body"
                                            {tags remove "turr_jummed1"}
                                        else
                                            {tags remove "turr_jummed1"}
                                            {ik_enable "turret" 1}
                                        }
                                }
;///////Engineer_Den + ////////////////
				{if tagged "turr2_jummed1"
                                        {if tagged "turret2_brake"
                                            {tags remove "turr2_jummed1"}
                                            
                                        else tagged "turret2_stopped_by_body"
                                            {tags remove "turr2_jummed1"}
                                        else
                                            {tags remove "turr2_jummed1"}
                                            {ik_enable "turret2" 1}
                                        }
                                }							
				{if tagged "turr3_jummed1"
                                        {if tagged "turret3_brake"
                                            {tags remove "turr3_jummed1"}
                                            
                                        else tagged "turret3_stopped_by_body"
                                            {tags remove "turr3_jummed1"}
                                        else
                                            {tags remove "turr3_jummed1"}
                                            {ik_enable "turret3" 1}
                                        }
                                }		
;///////Engineer_Den - ////////////////
                            }
                        else
                            {delay 0.5
                                {set "already_blasted" 0}
                            }
                        }
                    }
                }
            }
        }
        
    )
;MEGA BUILDING END ======= инженер ƒен очень рад окончанию этого звиздеца======================================================================================================================================================================

    {on repair
	    {if component "turret"
    		{view stop "smoke3"}
            {call "update_turret"}
            {tags remove "turret_brake"}
;///////Engineer_Den + ////////////////
	else component "turret2"
    		{view stop "smoke7"}
            {call "update_turret2"}
            {tags remove "turret2_brake"}
	else component "turret3"
    		{view stop "smoke8"}
            {call "update_turret3"}
            {tags remove "turret3_brake"}	
;///////Engineer_Den - ////////////////
        else component "body"
            {view stop "smoke4"}
            {call "update_turret"}
            {tags remove "turret_stopped_by_body"}
            {tags remove "body_brake"}
            {able "select" 1}
        else component "engine"
            {tags remove "engine_brake"}
        }
    }
	{on "update_turret"
		{if work "turret"
			{if work "body"
				{ik_enable "turret" 1}
			 else
				{ik_enable "turret" 0}
			}
		 else
			{ik_enable "turret" 0}
		}
    }
;///////Engineer_Den + ////////////////башни є2...3 не бокируютс€ при повреждении корпуса
	{on "update_turret2"
		{if work "turret2"
			{if work "body"
				{ik_enable "turret2" 1}
			 else
				{ik_enable "turret2" 1}
			}
		 else
			{ik_enable "turret2" 0}
		}
    	}
	{on "update_turret3"
		{if work "turret3"
			{if work "body"
				{ik_enable "turret3" 1}
			 else
				{ik_enable "turret3" 1}
			}
		 else
			{ik_enable "turret3" 0}
		}
    	}	
;///////Engineer_Den - ////////////////
}; end of "medium_t28 tank"


{"medium_t28 tank"
	{inflammation_time 15}
	{on spawn                                                                                            
		{add_view	"flash_cannon_medium"		"flashbarrel1"			"Foresight1"}
		{add_view	"flash_cannon_medium"		"flashbarrel2"			"Foresight2"}
	}
	{on fire "gun"
       	{spawn "dust_shot_norm" "basis"}
        {spawn "tank_canon_fire" "Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone "Foresight1"}
	}
	
	{on blast_hit
		{if min_energy 15
			{impulse up 0.3 0.2 dir 1 0.2}
			{if volume "turret"
				{if rand 0.95
					{call "tear_turret"}
				}
			}
		else min_energy 9
			{impulse up 0.15 0.05 dir 0.35 0.1}
			{if volume "turret"
				{if rand 0.7
					{call "tear_turret"}
				}
			}
		 else min_energy 6
			{impulse up 0.1 0.05 dir 0.3 0.1}
		 else min_energy 3
			{impulse up 0.1 0.05 dir 0.3 0.1}
		 else min_energy 1.9
		 	;{ani_play "hit"}
		}
	}
	{on "_explosion"
		{blastwave c4 10 r0 2.5 r1 10}
		{impulse up 2 0.5 dir 0.4 0.2}
	}
	{on "check_water_level" overload
		{if water_level 1.6
			{able "sinking" 1}
		}
	}
(include "tank/tank_medium_t28.inc")
}

(define "l335_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/bt"		}
		{link_sound "rotate_turret" 		"vehicle/turret/light"		}
		{link_sound "engine"			"vehicle/engine/cv33"		}
		{link_sound "engine_end"		"vehicle/engine/cv33_end"	}
		{link_sound "exhaust"			"vehicle/engine/cv33_up"	}
		{link_sound "idle"			"vehicle/engine/cv33"		}
	}
)
(define "semovente_sound"
	{on "add_movement_sound" overload
		{link_sound "move" 			"vehicle/tracks/bt"	}
		{link_sound "engine"			"vehicle/engine/sem7518"	}
		{link_sound "engine_end"		"vehicle/engine/sem7518_end"	}
		{link_sound "exhaust"			"vehicle/engine/sem7518_up"}
		{link_sound "idle"			"vehicle/engine/sem7518"	}
	}
)
(define "m1441_sound"
	{on "add_movement_sound" overload
		{link_sound "move" 			"vehicle/tracks/bt"	}
		{link_sound "engine"			"vehicle/engine/m14"	}
		{link_sound "engine_end"		"vehicle/engine/m14_end"	}
		{link_sound "exhaust"			"vehicle/engine/m14_up"	}
		{link_sound "idle"			"vehicle/engine/m14"	}
	}
)
(define "l640_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/l6-40"		}
		{link_sound "engine"			"vehicle/engine/l6-40"		}
		{link_sound "engine_end"		"vehicle/engine/l6-40_end"	}
		{link_sound "rotate_turret" 		"vehicle/turret/light1"		}
		{link_sound "exhaust"			"vehicle/engine/l6-40_up" 	}
		{link_sound "idle"			"vehicle/engine/l6-40"		}
	}

)
(define "l6a_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/l6-40"		}
		{link_sound "engine"			"vehicle/engine/l6-40"		}
		{link_sound "engine_end"		"vehicle/engine/l6-40_end"	}
		{link_sound "exhaust"			"vehicle/engine/l6-40_up" 	}
		{link_sound "idle"			"vehicle/engine/l6-40"		}
	}

)
(define "as37_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/wheels/m8grayhound"	}
		{link_sound "engine"			"vehicle/engine/as37"		}
		{link_sound "engine_end"		"vehicle/engine/as37_end"	}
		{link_sound "rotate_turret" 		"vehicle/turret/mk7_turret"	}
		{link_sound "exhaust"			"vehicle/engine/as37_up" 	}
		{link_sound "idle"			"vehicle/engine/as37"		}
	}
)
(define "m4_sound"
	{on "add_movement_sound" overload
		{link_sound "move"					"vehicle/tracks/m4"			}
		{link_sound "engine"				"vehicle/engine/m4"			}
		{link_sound "engine_end"			"vehicle/engine/m4_end"		}
		{link_sound "exhaust"				"vehicle/engine/m4a2_up"		}
		{link_sound "rotate_turret"     	"vehicle/turret/sherman"   	}
		{link_sound "idle"			        "vehicle/engine/Sherman_Idle"	}
	}
)
(define "m4hst_sound"
	{on "add_movement_sound" overload
		{link_sound "move"					"vehicle/tracks/m4"			}
		{link_sound "engine"				"vehicle/engine/m4"			}
		{link_sound "engine_end"			"vehicle/engine/m4_end"		}
		{link_sound "exhaust"				"vehicle/engine/m4a2_up"		}
		{link_sound "rotate_turret"     	"vehicle/turret/sherman"   	}
		{link_sound "idle"			        "vehicle/engine/Sherman_Idle"	}
	}
)
(define "t34_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/t34"	}
		{link_sound "rotate_turret" 	"vehicle/turret/t34"		}
		{link_sound "engine"			"vehicle/engine/t34"		}
		{link_sound "engine_end"		"vehicle/engine/t34_end"	}
		{link_sound "exhaust"			"vehicle/engine/t34_up"		}
		{link_sound "idle"			"vehicle/engine/t60"	}
	}
)
(define "t26_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/bt"			}
		{link_sound "rotate_turret" 	"vehicle/turret/light"		}
		{link_sound "engine"			"vehicle/engine/t26"		}
		{link_sound "engine_end"		"vehicle/engine/t26_end"	}
		{link_sound "exhaust"			"vehicle/engine/t26_up"	}
		{link_sound "idle"			"vehicle/engine/t-38"	}		
	}
)
(define "mk6_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/crusader"	}
		{link_sound "engine"			"vehicle/engine/crusader"		}
		{link_sound "engine_end"		"vehicle/engine/crusader_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium1"		}
		{link_sound "exhaust"			"vehicle/engine/crusader_up" 	}
		{link_sound "idle"			"vehicle/engine/Crusader_Idle"	}		
	}
)
(define "stug_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/stug"	}
		{link_sound "engine"			"vehicle/engine/stugiii"		}
		{link_sound "engine_end"		"vehicle/engine/stug_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy1"	}
		{link_sound "exhaust"			"vehicle/engine/stug_up"	}
		{link_sound "idle"			"vehicle/engine/stugiii"	}
	}
)
(define "csaba_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/wheels"			}
		{link_sound "engine"			"vehicle/engine/sdkfz232"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz232_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"			}
		{link_sound "exhaust"			"vehicle/engine/sdkfz232_up"	}
		{link_sound "idle"			"vehicle/engine/sdkfz_idle"		}
	}
)
(define "bt7_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/bt"	}
		{link_sound "engine"			"vehicle/engine/bt"	}
		{link_sound "engine_end"		"vehicle/engine/bt_end"	}
		{link_sound "exhaust"			"vehicle/engine/bt_up"	}
		{link_sound "rotate_turret" 		"vehicle/turret/light"	}
		{link_sound "idle"			"vehicle/engine/t-38"	}
	}
)
{"np_su14 tank"
	("bt7_sound")
	("burn_by_engine" args 0.3)
}
{"autoblinda_fiat_611 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/sdkfz234"			}
		{link_sound "engine"			"vehicle/engine/sdkfz234"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz234_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz234_up"	}
	}
	("burn_by_engine" args 0.3)
}
(define "m8grayhound_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/m8grayhound"	}
		{link_sound "engine"			"vehicle/engine/m8grayhound"		}
		{link_sound "engine_end"		"vehicle/engine/m8grayhound_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine/m8grayhound_up"	}
	}
)

{"mine_exploder"
	{on spawn
		{bone hide "wheel_work"}
		{add_view "dustrun_sand_big"	"wheel_work_dust"	"FXWheel_Work1"}
		{add_view "dustrun_sand_big"	"wheel_work_dust"	"FXWheel_Work2"}
		{volumes "wheel_work" disable all}
		{ani_play "wheel_stop"}
	}
	{on move on
		{bone hide "wheel"}
		{bone show "wheel_work"}
		{view start "wheel_work_dust"}
		{volumes "wheel_work" enable all}
		{volumes "wheel" disable all}
	}
	{on move off
		{bone hide "wheel_work"}
		{bone show "wheel"}
		{ani_play "wheel_stop"}
		{view pause "wheel_work_dust"}
		{volumes "wheel_work" disable all}
		{volumes "wheel" enable all}
	}
	{on blast overload
		{if not volume "wheel_work"
			{inherited}
		else
			{ani_play "explosion"}
		}
	}
}
{"maginot75"
{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel2"			"Foresight12"}
		{add_view	"flash_cannon_small"		"flashbarrel1"			"Foresight1"}
	}
	{on fire "gun2"
       	{spawn "dust_shot_norm" "basis"}
        {spawn "tank_canon_fire" "Foresight12" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone "Foresight12"}
	}
}
{"pz7_174"
{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel2"			"Foresight12"}
		{add_view	"flash_cannon_small"		"flashbarrel1"			"Foresight14"}
	}
	{on fire "gun2"
       	{spawn "dust_shot_norm" "basis"}
        {spawn "tank_canon_fire" "Foresight12" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone "Foresight12"}
	}
}

{"pz1b tank"
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"	}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"	}
		{link_sound "move"				"vehicle/tracks/pz1"	}
		{link_sound "engine"			"vehicle/engine/pz1"	}
		{link_sound "engine_end"		"vehicle/engine/pz1_end"}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine/pz1_up"	}
		{link_sound "idle"			"vehicle/engine/pz2c"	}
	}
	{on fire "mgun" overload
		{if  name "00"
			{view start "flashbarrel00"}
		else name "01"
			{view start "flashbarrel01"}
		}
	}
	("burn_by_engine" args 0.3)
}
(define "pz1_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz1"}
		{link_sound "engine"			"vehicle/engine/pz1"		}
		{link_sound "engine_end"		"vehicle/engine/pz1_end"	}
		{link_sound "exhaust"			"vehicle/engine/pz1_up"	}
		{link_sound "idle"			"vehicle/engine/pz2c"	}	
	}
)
{"pz1 tank"
	("pz1_sound")
	("burn_by_engine" args 0.3)
}
{"panzerjager tank"
	("pz1_sound")
	("burn_by_engine" args 0.3)
}
{"sdkfz303 tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/engine/dodge_move_new"	}
		{link_sound "engine"			"vehicle/wheels/valami"	}
		{link_sound "engine_end"		"vehicle/engine/pz1_end"}
		{link_sound "exhaust"			"vehicle/engine/Dodge_end"}
	}
	{on fire "charge"
		{call "explosion"}
	}
	{on "explosion"
		{delete}
	}
	("burn_by_engine" args 0.3)
}
(define "lt_turret_sound"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"		}
	}
)
{"sturmpz1 tank"
	("pz1_sound")
	("burn_by_engine" args 0.3)
}
{"t26 tank"
	("t26_sound")
	("burn_by_engine" args 0.3)
}
{"t26e39 tank"
	("t26_sound")
	("burn_by_engine" args 0.3)
}
{"7tp tank"
	("t26_sound")
	("burn_by_engine" args 0.3)
}
{"toldi1 tank"
	("t26_sound")
	("burn_by_engine" args 0.3)
}
{"toldi2 tank"
	("t26_sound")
	("burn_by_engine" args 0.3)
}
{"toldi3 tank"
	("t26_sound")
	("burn_by_engine" args 0.3)
}
{"csaba39m tank"
	("csaba_sound")
	("burn_by_engine" args 0.3)
}
{"csaba40m tank"
	("csaba_sound")
	("burn_by_engine" args 0.3)
	{on move on
		{ani_play "antennadown" 1}
	}
	{on move off
		{ani_play "antennaup" 1}
	}
}
{"vickersedw tank"
	("t26_sound")
	("burn_by_engine" args 0.3)
}
{"vickersejw tank"
	("t26_sound")
	("burn_by_engine" args 0.3)
}
{"at-1 tank"
	("t26_sound")
	("burn_by_engine" args 0.3)
}
{"su5 tank"
	("t26_sound")
	("burn_by_engine" args 0.3)
}
{"t35a1939 tank"
("t26_sound")
{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel2"			"Foresight12"}
		{add_view	"flash_cannon_small"		"flashbarrel1"			"Foresight14"}
	}
	{on fire "gun2"
       	{spawn "dust_shot_norm" "basis"}
        {spawn "tank_canon_fire" "Foresight12" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone "Foresight12"}
	}
	{on fire "gun3"
	       	{spawn "dust_shot_norm" "basis"}
	        {spawn "tank_canon_fire" "Foresight14" x}
			{blastwave c4 0.2 r0 1 r1 2.5 bone "Foresight14"}
	}
	{on move on
	{ani_play "fan" loop}
	}
	{on move off
	{ani_stop "fan"}
	{ani_play "fan_stop"}
	}


}
(define "su76_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/su76"}
		{link_sound "engine"			"vehicle/engine/t26"		}
		{link_sound "engine_end"		"vehicle/engine/bt_end"	}
		{link_sound "exhaust"			"vehicle/engine/bt_up"	}
		{link_sound "idle"			"vehicle/engine/t60"	}
	}
)
{"su76 tank"
	("su76_sound")
	("burn_by_engine" args 0.3)
}
{"zis_30 tank"
	("su76_sound")
	("burn_by_engine" args 0.3)
}
{"zis30 tank"
	("burn_by_engine" args 0.3)
}
{"t20 tank"
	("su76_sound")
	("burn_by_engine" args 0.3)
}
{"t20_nw tank"
	("su76_sound")
	("burn_by_engine" args 0.3)
}
{"voroshilovets tank"
	("su76_sound")
	("burn_by_engine" args 0.3)
}
(define "t70_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/t-70"}
		{link_sound "rotate_turret" 	"vehicle/turret/light"		}
		{link_sound "engine"			"vehicle/engine/t26"		}
		{link_sound "engine_end"		"vehicle/engine/bt_end"	}
		{link_sound "exhaust"			"vehicle/engine/bt_up"	}
	}
)
{"t70 tank"
	("t70_sound")
	("burn_by_engine" args 0.3)
}
{"t60 tank"
	("t70_sound")
	("burn_by_engine" args 0.3)
}
{"tacam_t60 tank"
	("t70_sound")
	("burn_by_engine" args 0.3)
}
{"tks-20mm tank"
	("t70_sound")
	("burn_by_engine" args 0.3)
}
{"tks-mg tank"
	("t70_sound")
	("burn_by_engine" args 0.3)
}
{"bm_8_24 tank"
	("t70_sound")
	("burn_by_engine" args 0.3)
}
{"zsu37 tank"
	("t70_sound")
	("burn_by_engine" args 0.3)
}
{"bt7a tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/bt"		}
		{link_sound "engine"			"vehicle/engine/bt"		}
		{link_sound "engine_end"		"vehicle/engine/bt_end"	}
		{link_sound "exhaust"			"vehicle/engine/bt_up"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "idle"			"vehicle/engine/t-38"	}
	}
	("burn_by_engine" args 0.3)
}

(define "kv_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/kv"}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy"	}
		{link_sound "engine"			"vehicle/engine/kv"			}
		{link_sound "engine_end"		"vehicle/engine/kv_end"		}
		{link_sound "exhaust"			"vehicle/engine/kv_up"		}
		{link_sound "idle"			"vehicle/engine/kv"	}
	}
)
(define "su152_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/kv"}
		{link_sound "engine"			"vehicle/engine/kv"			}
		{link_sound "engine_end"		"vehicle/engine/kv_end"		}
		{link_sound "exhaust"			"vehicle/engine/kv_up"		}
		{link_sound "idle"			"vehicle/engine/kv"	}
	}
)
(define "is_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/is"		}
		{link_sound "rotate_turret" 		"vehicle/turret/heavy1"		}
		{link_sound "engine"			"vehicle/engine/is"		}
		{link_sound "engine_end"		"vehicle/engine/is_end"		}
		{link_sound "exhaust"			"vehicle/engine/is_up"	}
		{link_sound "idle"			"vehicle/engine/isu"	}
	}
)
{"np_su152 tank"
	("su152_sound")
	("burn_by_engine" args 0.2)
}
{"kv1 tank"
	("kv_sound")
	("burn_by_engine" args 0.2)
}
{"kv1_39 tank"
	("kv_sound")
	("burn_by_engine" args 0.2)
}
{"kv1_zis5_41 tank"
	("kv_sound")
	("burn_by_engine" args 0.2)
}
{"kv1e tank"
	("kv_sound")
	("burn_by_engine" args 0.2)
}
{"kv1s tank"
	("kv_sound")
	("burn_by_engine" args 0.2)
}
{"kv9 tank"
	("kv_sound")
	("burn_by_engine" args 0.2)
}
{"kv-220 tank"
	("kv_sound")
	("burn_by_engine" args 0.2)
}
{"kv2 tank"
	("kv_sound")
	("burn_by_engine" args 0.2)
}
{"kv85 tank"
	("kv_sound")
	("burn_by_engine" args 0.2) 
}
{"kv85100 tank"
	("kv_sound")
	("burn_by_engine" args 0.2) 
}
{"kv85122 tank"
	("kv_sound")
	("burn_by_engine" args 0.2) 
}
{"is1 tank"
	("is_sound")
	("burn_by_engine" args 0.2)
}
{"is2 tank"
	("is_sound")
	("burn_by_engine" args 0.2)
}
{"is-122 tank"
	("is_sound")
	("burn_by_engine" args 0.2)
}
{"is2120 tank"
	("is_sound")
	("burn_by_engine" args 0.2)
}
{"is2_44 tank"
	("is_sound")
	("burn_by_engine" args 0.2)
}
{"is2_100 tank"
	("is_sound")
	("burn_by_engine" args 0.2)
}
{"is3 tank"
	("is_sound")
	("burn_by_engine" args 0.2)
}
{"is4 tank"
	("is_sound")
	("burn_by_engine" args 0.2)
}
{"t-10m tank"
	("is_sound")
	("burn_by_engine" args 0.2)
}
{"is7 tank"
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"	}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"	}
	}
	("is_sound")
	("burn_by_engine" args 0.2)
	{on fire "mgun2" overload
		{if  name "00"
			{view start "flashbarrel00"}
		else name "01"
			{view start "flashbarrel01"}
		}
	}	
}
{"is705a tank"
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"	}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"	}
	}
	("is_sound")
	("burn_by_engine" args 0.2)
	{on fire "mgun2" overload
		{if  name "00"
			{view start "flashbarrel00"}
		else name "01"
			{view start "flashbarrel01"}
		}
	}	
}
{"m26_pershing tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m26"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pershing"		}
		{link_sound "engine"			"vehicle/engine/m26"		}
		{link_sound "engine_end"		"vehicle/engine/m4a2_end"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
		{link_sound "idle"			"vehicle/engine/stuart_idle"	}
	}
	("burn_by_engine" args 0.3)
}
{"m26e4 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m26"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pershing"		}
		{link_sound "engine"			"vehicle/engine/m26"		}
		{link_sound "engine_end"		"vehicle/engine/m4a2_end"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
		{link_sound "idle"			"vehicle/engine/stuart_idle"	}
	}
	("burn_by_engine" args 0.3)
}
{"m26e44 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m26"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pershing"		}
		{link_sound "engine"			"vehicle/engine/m26"		}
		{link_sound "engine_end"		"vehicle/engine/m4a2_end"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
		{link_sound "idle"			"vehicle/engine/stuart_idle"	}
	}
	("burn_by_engine" args 0.3)
}
{"m48a1 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m26"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pershing"		}
		{link_sound "engine"			"vehicle/engine/m26"		}
		{link_sound "engine_end"		"vehicle/engine/m4a2_end"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
		{link_sound "idle"			"vehicle/engine/stuart_idle"	}
	}
	("burn_by_engine" args 0.3)
}
{"sta1 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m26"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pershing"		}
		{link_sound "engine"			"vehicle/engine/m26"		}
		{link_sound "engine_end"		"vehicle/engine/m4a2_end"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
		{link_sound "idle"			"vehicle/engine/stuart_idle"	}
	}
	("burn_by_engine" args 0.3)
}
{"m103 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m26"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pershing"		}
		{link_sound "engine"			"vehicle/engine/m26"		}
		{link_sound "engine_end"		"vehicle/engine/m4a2_end"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
		{link_sound "idle"			"vehicle/engine/stuart_idle"	}
	}
	("burn_by_engine" args 0.3)
}
{"isu152 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/is"		}
		{link_sound "engine"			"vehicle/engine/isu"		}
		{link_sound "engine_end"		"vehicle/engine/isu_end"	}
		{link_sound "exhaust"			"vehicle/engine/isu_up"		}
		{link_sound "idle"			"vehicle/engine/isu"	}
	}
	{on "gunner_hatch_open" overload
		{ani_play "open2"}
	}
	("burn_by_engine" args 0.3)
}
{"isu122 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/is"		}
		{link_sound "engine"			"vehicle/engine/isu"		}
		{link_sound "engine_end"		"vehicle/engine/isu_end"	}
		{link_sound "exhaust"			"vehicle/engine/isu_up"		}
		{link_sound "idle"			"vehicle/engine/isu"	}
	}
	("burn_by_engine" args 0.3)
}
{"isu122s tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/is"		}
		{link_sound "engine"			"vehicle/engine/isu"		}
		{link_sound "engine_end"		"vehicle/engine/isu_end"	}
		{link_sound "exhaust"			"vehicle/engine/isu_up"		}
		{link_sound "idle"			"vehicle/engine/isu"	}
	}
;	{on fire "gun"
;		{spawn "tagged_piece"}
;	}
	("burn_by_engine" args 0.2)
}
{"0bj_268 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/is"		}
		{link_sound "engine"			"vehicle/engine/isu"		}
		{link_sound "engine_end"		"vehicle/engine/isu_end"	}
		{link_sound "exhaust"			"vehicle/engine/isu_up"		}
		{link_sound "idle"			"vehicle/engine/isu"	}
	}
	("burn_by_engine" args 0.3)
}
{"t34_0 tank"
	("t34_sound")
	("burn_by_engine" args 0.3)
}
{"t34_0_hd tank"
	("t34_sound")
	("burn_by_engine" args 0.3)
}
{"t34_1 tank"
	("t34_sound")
	("burn_by_engine" args 0.3)
}
{"t34_1_42 tank"
	("t34_sound")
	("burn_by_engine" args 0.3)
}
{"t34_1_hd tank"
	("t34_sound")
	("burn_by_engine" args 0.3)
}
{"t34_2 tank"
	("t34_sound")
	("burn_by_engine" args 0.3)
}
{"t34_2_hd tank"
	("t34_sound")
	("burn_by_engine" args 0.3)
}
{"su85 tank"
	("t34_sound")
	("burn_by_engine" args 0.3)
}
{"su85m tank"
	("t34_sound")
	("burn_by_engine" args 0.3)
}
{"su122 tank"
	("t34_sound")
	("burn_by_engine" args 0.3)
}
{"su100 tank"
	("t34_sound")
	("burn_by_engine" args 0.3)
}
{"su-122-44 tank"
	("t34_sound")
	("burn_by_engine" args 0.3)
}
{"su-122-54 tank"
	("t34_sound")
	("burn_by_engine" args 0.3)   
}
{"t34_3 tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/t34"	}
		{link_sound "rotate_turret" 	"vehicle/turret/t34"		}
		{link_sound "engine"			"vehicle/engine/t3485"		}
		{link_sound "engine_end"		"vehicle/engine/t3485_end"	}
		{link_sound "exhaust"			"vehicle/engine/m3a1_up"	}
		{link_sound "idle"			"vehicle/engine/t60"	}		
	}
	("burn_by_engine" args 0.3)
}
{"t34_3_hd tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/t34"	}
		{link_sound "rotate_turret" 	"vehicle/turret/t34"		}
		{link_sound "engine"			"vehicle/engine/t3485"		}
		{link_sound "engine_end"		"vehicle/engine/t3485_end"	}
		{link_sound "exhaust"			"vehicle/engine/m3a1_up"	}
		{link_sound "idle"			"vehicle/engine/t60"	}		
	}
	("burn_by_engine" args 0.3)
}
{"t34_d5t_hd tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/t34"	}
		{link_sound "rotate_turret" 	"vehicle/turret/t34"		}
		{link_sound "engine"			"vehicle/engine/t3485"		}
		{link_sound "engine_end"		"vehicle/engine/t3485_end"	}
		{link_sound "exhaust"			"vehicle/engine/m3a1_up"	}
		{link_sound "idle"			"vehicle/engine/t60"	}		
	}
	("burn_by_engine" args 0.3)
}
{"t44 tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/t34"	}
		{link_sound "rotate_turret" 	"vehicle/turret/t34"		}
		{link_sound "engine"			"vehicle/engine/t3485"		}
		{link_sound "engine_end"		"vehicle/engine/t3485_end"	}
		{link_sound "exhaust"			"vehicle/engine/m3a1_up"	}
		{link_sound "idle"			"vehicle/engine/t60"	}		
	}
	("burn_by_engine" args 0.3)
}
{"t44_1 tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/t34"	}
		{link_sound "rotate_turret" 	"vehicle/turret/t34"		}
		{link_sound "engine"			"vehicle/engine/t3485"		}
		{link_sound "engine_end"		"vehicle/engine/t3485_end"	}
		{link_sound "exhaust"			"vehicle/engine/m3a1_up"	}
		{link_sound "idle"			"vehicle/engine/t60"	}		
	}
	("burn_by_engine" args 0.3)
}
{"t44_l85 tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/t34"	}
		{link_sound "rotate_turret" 	"vehicle/turret/t34"		}
		{link_sound "engine"			"vehicle/engine/t3485"		}
		{link_sound "engine_end"		"vehicle/engine/t3485_end"	}
		{link_sound "exhaust"			"vehicle/engine/m3a1_up"	}
		{link_sound "idle"			"vehicle/engine/t60"	}		
	}
	("burn_by_engine" args 0.3)
}
{"t44_2 tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/t34"	}
		{link_sound "rotate_turret" 	"vehicle/turret/t34"		}
		{link_sound "engine"			"vehicle/engine/t3485"		}
		{link_sound "engine_end"		"vehicle/engine/t3485_end"	}
		{link_sound "exhaust"			"vehicle/engine/m3a1_up"	}
		{link_sound "idle"			"vehicle/engine/t60"	}		
	}
	("burn_by_engine" args 0.3)
}
{"t-54a tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/t34"	}
		{link_sound "rotate_turret" 	"vehicle/turret/t34"		}
		{link_sound "engine"			"vehicle/engine/t3485"		}
		{link_sound "engine_end"		"vehicle/engine/t3485_end"	}
		{link_sound "exhaust"			"vehicle/engine/m3a1_up"	}
		{link_sound "idle"			"vehicle/engine/t60"	}		
	}
	("burn_by_engine" args 0.3)
}
(define "pz5g_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/jugdpanther"		}
		{link_sound "engine"			"vehicle/engine/jugdpanther"		}
		{link_sound "engine_end"		"vehicle/engine/jugdpanther_end"	}
		{link_sound "rotate_turret" 		"vehicle/turret/heavy"	}
		{link_sound "exhaust"			"vehicle/engine/jugdpanther_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}		
	}
)
(define "ho-ri_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/is"		}
		{link_sound "engine"			"vehicle/engine/jugdpanther"		}
		{link_sound "engine_end"		"vehicle/engine/jugdpanther_end"	}
		{link_sound "rotate_turret" 		"vehicle/turret/heavy"	}
		{link_sound "exhaust"			"vehicle/engine/jugdpanther_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}	
	}
)

{"pz5d tank"
	("pz5g_sound")
	("burn_by_engine" args 0.3)
}

{"pz5a tank"
	("pz5g_sound")
	("burn_by_engine" args 0.3)
}

{"pz5g tank"
	("pz5g_sound")
	("burn_by_engine" args 0.3)
}

{"panther_ii_88mm tank"
	("pz5g_sound")
	("burn_by_engine" args 0.3)
}

{"vk1602 tank"
	("pz5g_sound")
	("burn_by_engine" args 0.3)
}

{"jugdpanther tank"
	("pz5g_sound")
	("burn_by_engine" args 0.3)
}

{"ho-ri tank"
	("ho-ri_sound")
	("burn_by_engine" args 0.3)
}

{"type5_ho-ri_production"
	("ho-ri_sound")
	("burn_by_engine" args 0.3)
}

{"chi-ru tank"
	("ho-ri_sound")
	("burn_by_engine" args 0.3)
}

{"ho-ri_1_120 tank"
	("ho-ri_sound")
	("burn_by_engine" args 0.3)
}

{"ho-ri_2_150 tank"
	("ho-ri_sound")
	("burn_by_engine" args 0.3)
}

{"ho-ri_1 tank"
	("ho-ri_sound")
	("burn_by_engine" args 0.3)
}

(define "m8_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/wheels/m8grayhound"		}
		{link_sound "engine"			"vehicle/engine/m8grayhound"		}
		{link_sound "engine_end"		"vehicle/engine/m8grayhound_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "exhaust"			"vehicle/engine/m8grayhound_up" 	}
	}
)
{"m8 tank"
	;("m8_sound")
	("burn_by_engine" args 0.3)
}
{"m3stuart tank"
	("m8_sound")
	("burn_by_engine" args 0.3)
}
{"mk2 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/mk2"	}
		{link_sound "engine"			"vehicle/engine/pz2"		}
		{link_sound "engine_end"		"vehicle/engine/pz2_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium1"		}
		{link_sound "exhaust"			"vehicle/engine/pz2_up" 	}
		{link_sound "idle"			"vehicle/engine/pz2c"	}		
	}
	("burn_by_engine" args 0.3)
}
(define "mk7_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/mk7"	}
		{link_sound "engine"			"vehicle/engine/mk7"		}
		{link_sound "engine_end"		"vehicle/engine/mk7_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/mk7_turret"		}
		{link_sound "exhaust"			"vehicle/engine/mk7_up" 	}
	}
)
{"mk7 tank"
	("mk7_sound")
	("burn_by_engine" args 0.3)
}
{"mk7_42 tank"
	("mk7_sound")
	("burn_by_engine" args 0.3)
}
{"mk7_Late tank"
	("mk7_sound")
	("burn_by_engine" args 0.3)
}
{"mk2a tank"
	("mk7_sound")
	("burn_by_engine" args 0.3)
}
{"mk2a_43 tank"
	("mk7_sound")
	("burn_by_engine" args 0.3)
}
{"mk2a_75 tank"
	("mk7_sound")
	("burn_by_engine" args 0.3)
}
{"universal_carrier tank"
	("mk7_sound")
	("burn_by_engine" args 0.3)
}
{"gun_carrier tank"
	("mk7_sound")
	("burn_by_engine" args 0.3)
}
{"gun_carrier_3_inch tank"
	("mk7_sound")
	("burn_by_engine" args 0.3)
}
{"medium_mg_carrier tank"
	("mk7_sound")
	("burn_by_engine" args 0.3)
}
{"boyes_gun_carrier tank"
	("mk7_sound")
	("burn_by_engine" args 0.3)
}
{"medium_hmg_carrier tank"
	("mk7_sound")
	("burn_by_engine" args 0.3)
}
(define "bishop_sound"
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/light"}
		{link_sound "move"		    	"vehicle/tracks/cromwell"	}
		{link_sound "engine"			"vehicle/engine/cromwell"		}
		{link_sound "engine_end"		"vehicle/engine/cromwell_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/cromwell_up"	}
	}
)
{"bishop tank"
	("bishop_sound")
	("burn_by_engine" args 0.3)  
}	
{"mk3 tank"
	("bishop_sound")
	("burn_by_engine" args 0.3)
}
{"mk3cs tank"
	("bishop_sound")
	("burn_by_engine" args 0.3)
}
{"mk3_57_41 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0001"			"Foresight1"}
		{add_view       "smoke_zenit"		        "smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0002"	                "Foresight2"}
		{add_view	"exhaust_dark_big"		"exhaust"				"fxsmock1"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/light"}
		{link_sound "move"		    	"vehicle/tracks/cromwell"	}
		{link_sound "engine"			"vehicle/engine/cromwell"		}
		{link_sound "engine_end"		"vehicle/engine/cromwell_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/cromwell_up"	}
	}
	{on fire "gun" overload
			{ani_play "fire"}
       	{spawn "dust_shot_norm" 				"basis"}
        {spawn "tank_canon_fire_medium" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 1.5 bone 		"Foresight1"}
	} 
	{on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	} 
	{on fire "mgun" overload
                                {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}
        }
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
				{ani_wind "open2" end}
				{ani_wind "open3" end}
                                {ani_wind "open4" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open" begin}
					{ani_wind "open2" begin}
					{ani_wind "open3" begin}
                                        {ani_wind "open4" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
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
("burn_by_engine" args 0.3)
}
{"mk3_57 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0001"			"Foresight1"}
		{add_view       "smoke_zenit"		        "smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0002"	                "Foresight2"}
		{add_view	"exhaust_dark_big"		"exhaust"				"fxsmock1"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/light"}
		{link_sound "move"		    	"vehicle/tracks/cromwell"	}
		{link_sound "engine"			"vehicle/engine/cromwell"		}
		{link_sound "engine_end"		"vehicle/engine/cromwell_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/cromwell_up"	}
	}
	{on fire "gun" overload
			{ani_play "fire"}
       	{spawn "dust_shot_norm" 				"basis"}
        {spawn "tank_canon_fire_medium" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 1.5 bone 		"Foresight1"}
	} 
	{on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	} 
	{on fire "mgun" overload
                                {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}
        }
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
				{ani_wind "open2" end}
				{ani_wind "open3" end}
                                {ani_wind "open4" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open" begin}
					{ani_wind "open2" begin}
					{ani_wind "open3" begin}
                                        {ani_wind "open4" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
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
("burn_by_engine" args 0.3)
}
{"mk3_57_43 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0001"			"Foresight1"}
		{add_view       "smoke_zenit"		        "smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0002"	                "Foresight2"}
		{add_view	"exhaust_dark_big"		"exhaust"				"fxsmock1"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/light"}
		{link_sound "move"		    	"vehicle/tracks/cromwell"	}
		{link_sound "engine"			"vehicle/engine/cromwell"		}
		{link_sound "engine_end"		"vehicle/engine/cromwell_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/cromwell_up"	}
	}
	{on fire "gun" overload
			{ani_play "fire"}
       	{spawn "dust_shot_norm" 				"basis"}
        {spawn "tank_canon_fire_medium" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 1.5 bone 		"Foresight1"}
	} 
	{on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	} 
	{on fire "mgun" overload
                                {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}
        }
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
				{ani_wind "open2" end}
				{ani_wind "open3" end}
                                {ani_wind "open4" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open" begin}
					{ani_wind "open2" begin}
					{ani_wind "open3" begin}
                                        {ani_wind "open4" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
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
("burn_by_engine" args 0.3)
}
{"mk3_75 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0001"			"Foresight1"}
		{add_view       "smoke_zenit"		        "smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0002"	                "Foresight2"}
		{add_view	"exhaust_dark_big"		"exhaust"				"fxsmock1"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/light"}
		{link_sound "move"		    	"vehicle/tracks/cromwell"	}
		{link_sound "engine"			"vehicle/engine/cromwell"		}
		{link_sound "engine_end"		"vehicle/engine/cromwell_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/cromwell_up"	}
	}
	{on fire "gun" overload
			{ani_play "fire"}
       	{spawn "dust_shot_norm" 				"basis"}
        {spawn "tank_canon_fire_medium" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 1.5 bone 		"Foresight1"}
	} 
	{on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	} 
	{on fire "mgun" overload
                                {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}
        }
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
				{ani_wind "open2" end}
				{ani_wind "open3" end}
                                {ani_wind "open4" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open" begin}
					{ani_wind "open2" begin}
					{ani_wind "open3" begin}
                                        {ani_wind "open4" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
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
("burn_by_engine" args 0.3)
}
{"mk_9 tank"
	("bishop_sound")
	("burn_by_engine" args 0.3)
}
{"crusaderi tank"
	("mk6_sound")
	("burn_by_engine" args 0.3)
}
{"crusaderics tank"
	("mk6_sound")
	("burn_by_engine" args 0.3)
}
{"crusaderii tank"
	("mk6_sound")
	("burn_by_engine" args 0.3)
}
{"mk6 tank"
	("mk6_sound")
	("burn_by_engine" args 0.3)
}
{"mk6_42 tank"
	("mk6_sound")
	("burn_by_engine" args 0.3)
}
{"crusaderaa2 tank"
	("mk6_sound")
	("burn_by_engine" args 0.3)
}
{"crusaderaa1 tank"
	("mk6_sound")
	("burn_by_engine" args 0.3)
}
{"mk4 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/churchill"		}
		{link_sound "engine"			"vehicle/engine/churchill"		}
		{link_sound "engine_end"		"vehicle/engine/churchill_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/churchill_up" 	}
	}
	("burn_by_engine" args 0.3)
}
{"mk4_75 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/churchill"		}
		{link_sound "engine"			"vehicle/engine/churchill"		}
		{link_sound "engine_end"		"vehicle/engine/churchill_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/churchill_up" 	}
	}
	("burn_by_engine" args 0.3)
}
{"churchill_mk_vii_57 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/churchill"		}
		{link_sound "engine"			"vehicle/engine/churchill"		}        
		{link_sound "engine_end"		"vehicle/engine/churchill_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/churchill_up" 	}
	}
	("burn_by_engine" args 0.3)
}
{"mk4_75_M3 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/churchill"		}
		{link_sound "engine"			"vehicle/engine/churchill"		}
		{link_sound "engine_end"		"vehicle/engine/churchill_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/churchill_up" 	}
	}
	("burn_by_engine" args 0.3)
}
{"tortez tank"
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"	}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"	}
	}
	{on "add_movement_sound" overload
		{link_sound "move"		    	"vehicle/tracks/turtoise.wav"	}
		{link_sound "engine"			"vehicle/engine/turtoise"		}
		{link_sound "engine_end"		"vehicle/engine/turtoise_end"	}
		{link_sound "exhaust"			"vehicle/engine/turtoise_up"	}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy"	}
	}
	{on fire "mgun"
		{if  name "00"
			{view start "flashbarrel00"}
		else name "01"
			{view start "flashbarrel01"}
		}
	}	
	("burn_by_engine" args 0.3)
}
{"mk8 tank"
	{on "add_movement_sound" overload
		{link_sound "move"		    	"vehicle/tracks/cromwell"	}
		{link_sound "engine"			"vehicle/engine/cromwell"		}
		{link_sound "engine_end"		"vehicle/engine/cromwell_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/cromwell_up"	}
		{link_sound "idle"			    "vehicle/engine/cromwell_idle"	}
	}
	("burn_by_engine" args 0.3)
}
{"m4a3m tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m4a2"  }
		{link_sound "engine"			"vehicle/engine/m4a2"		}
		{link_sound "engine_end"		"vehicle/engine/m4a2_end"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy"	}
		{link_sound "idle"			        "vehicle/engine/Sherman_Idle"	}		
	}
	("burn_by_engine" args 0.3)
}
(define "m4_turret_sound"
	{on "add_movement_sound"
		{link_sound "rotate_turret"     	"vehicle/turret/sherman"   	}
	}
)
{"m4a3_75 tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m4a4 tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m4a41 tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m4a4_tulip tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m4a3_105 tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m4a3e8 tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m4a3c tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m4_105 tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m4a1_eng tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m4sherman tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m4a2-hd tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m4a3_90 tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m4a1_76w tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m4a2_76w tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m4a2_76w_rus tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m12gmc tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m4a1 tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m4a4_firefly tank"
	{on "add_movement_sound" overload
		{link_sound "move"					"vehicle/tracks/m4a2"		}
		{link_sound "engine"				"vehicle/engine/m4"		}
		{link_sound "engine_end"			"vehicle/engine/m4_end"	}
		{link_sound "exhaust"				"vehicle/engine/m4a2_up"	}
		{link_sound "rotate_turret" 	    "vehicle/turret/sherman"	}
		{link_sound "idle"			        "vehicle/engine/Sherman_Idle"	}		
	}
	("burn_by_engine" args 0.3)
}
{"m4a4_firefly1 tank"
	{on "add_movement_sound" overload
		{link_sound "move"					"vehicle/tracks/m4a2"		}
		{link_sound "engine"				"vehicle/engine/m4"		}
		{link_sound "engine_end"			"vehicle/engine/m4_end"	}
		{link_sound "exhaust"				"vehicle/engine/m4a2_up"	}
		{link_sound "rotate_turret" 	    "vehicle/turret/sherman"	}
		{link_sound "idle"			        "vehicle/engine/Sherman_Idle"	}		
	}
	("burn_by_engine" args 0.3)
}
{"m4a3e2_jumbo tank"
	{on "add_movement_sound" overload
		{link_sound "move"					"vehicle/tracks/m4a2"		}
		{link_sound "engine"				"vehicle/engine/m4"		}
		{link_sound "engine_end"			"vehicle/engine/m4_end"	}
		{link_sound "exhaust"				"vehicle/engine/m4a2_up"	}
		{link_sound "rotate_turret" 	    "vehicle/turret/sherman"	}
		{link_sound "idle"			        "vehicle/engine/Sherman_Idle"	}		
	}
	("burn_by_engine" args 0.3)
}
{"m4a3e2_jumbo_76 tank"
	{on "add_movement_sound" overload
		{link_sound "move"					"vehicle/tracks/m4a2"		}
		{link_sound "engine"				"vehicle/engine/m4"		}
		{link_sound "engine_end"			"vehicle/engine/m4_end"	}
		{link_sound "exhaust"				"vehicle/engine/m4a2_up"	}
		{link_sound "rotate_turret" 	    "vehicle/turret/sherman"	}
		{link_sound "idle"			        "vehicle/engine/Sherman_Idle"	}		
	}
	("burn_by_engine" args 0.3)
}
{"lvt4 tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m4a3vc tank"
	{on "add_movement_sound" overload
		{link_sound "move"					"vehicle/tracks/m4a2"		}
		{link_sound "engine"				"vehicle/engine/m4"		}
		{link_sound "engine_end"			"vehicle/engine/m4_end"	}
		{link_sound "exhaust"				"vehicle/engine/m4a2_up"	}
		{link_sound "rotate_turret" 	    "vehicle/turret/sherman"	}
		{link_sound "idle"			        "vehicle/engine/Sherman_Idle"	}		
	}
	("burn_by_engine" args 0.3)
}
(define "m7_sound"
	{on "add_movement_sound" overload
		{link_sound "move"					"vehicle/tracks/m7"		}
		{link_sound "engine"				"vehicle/engine/m7"		}
		{link_sound "engine_end"			"vehicle/engine/m7_end"	}
		{link_sound "exhaust"				"vehicle/engine/m4a2_up"	}
		{link_sound "rotate_turret" 	    "vehicle/turret/sherman"	}
		{link_sound "idle"			        "vehicle/engine/Sherman_Idle"	}		
	}
)
{"m10achilles tank"
	{on "add_movement_sound" overload
		{link_sound "move"					"vehicle/tracks/m4a2"		}
		{link_sound "engine"				"vehicle/engine/m4"		}
		{link_sound "engine_end"			"vehicle/engine/m7_end"	}
		{link_sound "exhaust"				"vehicle/engine/m4a2_up"	}
		{link_sound "rotate_turret" 	    "vehicle/turret/sherman"	}
		{link_sound "idle"			        "vehicle/engine/Sherman_Idle"	}		
	}
	("burn_by_engine" args 0.3)
}
{"m7 tank"
	("m7_sound")
	("burn_by_engine" args 0.3)
}
{"m7_eng tank"
	("m7_sound")
	("burn_by_engine" args 0.3)
}
{"m19 tank"
	("m7_sound")
	("burn_by_engine" args 0.3)
}
{"m8 tank"
	("m7_sound")
	("burn_by_engine" args 0.3)
}
{"jagdpanther tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/jugdpanther"  		}
		{link_sound "engine"			"vehicle/engine/jugdpanther"		}
		{link_sound "engine_end"		"vehicle/engine/jugdpanther_end"	}
		{link_sound "exhaust"			"vehicle/engine/jugdpanther_up" 	}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy1"	}
	}
	("burn_by_engine" args 0.3)
}
{"jagdpz_e100a tank"
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}	
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sheavy"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}
	}
	("burn_by_engine" args 0.3)
}
{"Stag_Hound"
	{on "add_movement_sound" overload
		{link_sound "move"		"vehicle/wheels/wheels"		}
		{link_sound "engine"		"vehicle/engine/Panhard_178"	}
		{link_sound "engine_end"	"vehicle/engine/Panhard_178_end"}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"		}
		{link_sound "exhaust"		"vehicle/engine/Panhard_178_up"	}
		{link_sound "idle"			"vehicle/engine/dorchie"	}
	}
	("burn_by_engine" args 0.3)
}
{"staghound"
	{on "add_movement_sound" overload
		{link_sound "move"		"vehicle/wheels/wheels"		}
		{link_sound "engine"		"vehicle/engine/Panhard_178"	}
		{link_sound "engine_end"	"vehicle/engine/Panhard_178_end"}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"		}
		{link_sound "exhaust"		"vehicle/engine/Panhard_178_up"	}
		{link_sound "idle"			"vehicle/engine/dorchie"	}
	}
	("burn_by_engine" args 0.3)
}
{"staghound_e1"
	{on "add_movement_sound" overload
		{link_sound "move"		"vehicle/wheels/wheels"		}
		{link_sound "engine"		"vehicle/engine/Panhard_178"	}
		{link_sound "engine_end"	"vehicle/engine/Panhard_178_end"}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"		}
		{link_sound "exhaust"		"vehicle/engine/Panhard_178_up"	}
		{link_sound "idle"			"vehicle/engine/dorchie"	}
	}
	("burn_by_engine" args 0.3)
}
{"Stag_Hound_US"
	{on "add_movement_sound" overload
		{link_sound "move"		"vehicle/wheels/wheels"		}
		{link_sound "engine"		"vehicle/engine/Panhard_178"	}
		{link_sound "engine_end"	"vehicle/engine/Panhard_178_end"}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"		}
		{link_sound "exhaust"		"vehicle/engine/Panhard_178_up"	}
		{link_sound "idle"			"vehicle/engine/dorchie"	}
	}
	("burn_by_engine" args 0.3)
}

{"dingo"
	{on "add_movement_sound" overload
		{link_sound "move"		"vehicle/wheels/wheels"		}
		{link_sound "engine"		"vehicle/engine/Panhard_178"	}
		{link_sound "engine_end"	"vehicle/engine/Panhard_178_end"}
		{link_sound "exhaust"		"vehicle/engine/Panhard_178_up"	}
		{link_sound "idle"			"vehicle/engine/dorchie"	}
	}
	("burn_by_engine" args 0.3)
}

{"sws_flak tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/sdkfz10"	}
		{link_sound "engine"			"vehicle/engine/blitz"		}
		{link_sound "engine_end"		"vehicle/engine/blitz_end"	}
		{link_sound "rotate_turret" 		"vehicle/turret/flak38"		}
		{link_sound "exhaust"			"vehicle/engine/blitz_up"	}
		{link_sound "idle"			"vehicle/engine/sdkfz_Idle"	}
	}
	("burn_by_engine" args 0.3)
}
{"m3a1uk tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/wheels/m8grayhound"	}
		{link_sound "engine"			"vehicle/engine/m3a1"		}
		{link_sound "engine_end"		"vehicle/engine/m3a1_end"	}
		{link_sound "exhaust"			"vehicle/engine/m3a1_up"	}
		{link_sound "idle"			"vehicle/engine/Crusader_Idle"	}
	}
	("burn_by_engine" args 0.3)
}

{"t34_41 tank"
	("t34_sound")
	("burn_by_engine" args 0.2)
}
(define "m3stuart_sound"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/m3a1_stuart"	}
		{link_sound "engine"			"vehicle/engine/m3a1_stuart"	}
		{link_sound "engine_end"		"vehicle/engine/m3a1_stuart_end"}
		{link_sound "rotate_turret" 		"vehicle/turret/light"		}
		{link_sound "exhaust"			"vehicle/engine/m3a1_stuart_up"	}
		{link_sound "idle"			"vehicle/engine/Crusader_Idle"	}
	}
)
(define "french_heavy_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/b1bis"}
		{link_sound "engine"			"vehicle/engine/french_engine"		}
		{link_sound "engine_end"		"vehicle/engine/french_engine_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pershing"		}
		{link_sound "exhaust"			"vehicle/engine/b1bis_up"	}
	}
)
{"fcm2c tank"
	("french_heavy_sound")
	("burn_by_engine" args 0.3)
}
{"fcm2c_bis tank"
	("french_heavy_sound")
	("burn_by_engine" args 0.3)
}
{"m3stuartUS tank"
	("m3stuart_sound")
	("burn_by_engine" args 0.3)
}
{"m3stuartUK tank"
	("m3stuart_sound")
	("burn_by_engine" args 0.3)
}
{"m2T tank"
	("m3stuart_sound")
	("burn_by_engine" args 0.3)
}
{"m2a1T tank"
	("m3stuart_sound")
	("burn_by_engine" args 0.3)
}
{"m2a4LT tank"
	("m3stuart_sound")
	("burn_by_engine" args 0.3)
}
{"m2LT tank"
	("m3stuart_sound")
	("burn_by_engine" args 0.3)
}
{"m3a1 tank"
	("m3stuart_sound")
	("burn_by_engine" args 0.3)
}
{"mkvib tank"
	("t26_sound")
	("burn_by_engine" args 0.3)
}
{"mkVibAA tank"
	("t26_sound")
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"	}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"	}
		{add_view	"flash_gun_big"	"flashbarrel02"	"shooter02"	}
		{add_view	"flash_gun_big"	"flashbarrel03"	"shooter03"	}		
	}
	{on fire "gun" overload
		{if  name "00"
			{view start "flashbarrel00"}
		else name "01"
			{view start "flashbarrel01"}
		else name "02"
			{view start "flashbarrel03"}
		else name "03"
			{view start "flashbarrel04"}			
		}
	}	
	("burn_by_engine" args 0.3)
}
{"cruisermk1 tank"
	("mk6_sound")
	("burn_by_engine" args 0.3)
}
{"cruisermk3 tank"
	("mk6_sound")
	("burn_by_engine" args 0.3)
}
(define "pz6b_sound"
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}	
		{link_sound "move"				"vehicle/tracks/heavy_tracks"	}
		{link_sound "engine"			"vehicle/engine/KT_run2"		}
		{link_sound "engine_end"		"vehicle/engine/KT_stop"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sheavy"	}
		{link_sound "exhaust"			"vehicle/engine/KT_start"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}
	}
)

{"sdkfz182h tank"
	("pz6b_sound")
	("burn_by_engine" args 0.3)
}
{"sdkfz182b tank"
	("pz6b_sound")
	("burn_by_engine" args 0.3)
}

(define "tiger_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/cadenas_tiger"	}
		{link_sound "engine"			"vehicle/engine/tiger_eng"		}
		{link_sound "engine_end"		"vehicle/engine/tiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pz6"	}
		{link_sound "exhaust"			"vehicle/engine/tiger_up"	}
		{link_sound "idle"			"vehicle/engine/tiger_idle3"	}
	}
)
{"pz6 tank"
	("tiger_sound")
	("burn_by_engine" args 0.3)
}
{"pz6b tank"
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}	
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sheavy"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}
	}
	("burn_by_engine" args 0.3)
}
{"pz6bh tank"
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}	
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sheavy"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}
	}
	{on "gunner_hatch_open" overload
		{ani_play "open2"}
	}
	("burn_by_engine" args 0.3)
}
{"pz6h tank"
	("tiger_sound")
	{on "gunner_hatch_open" overload
		{ani_play "open2"}
	}
	("burn_by_engine" args 0.3)
}
{"pz6e tank"
	("tiger_sound")
	{on "gunner_hatch_open" overload
		{ani_play "open2"}
	}
	("burn_by_engine" args 0.3)
}
(define "pz6_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/cadenas_tiger"	}
		{link_sound "engine"			"vehicle/engine/tiger_eng"		}
		{link_sound "engine_end"		"vehicle/engine/tiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pz6"	}
		{link_sound "exhaust"			"vehicle/engine/tiger_up"	}
		{link_sound "idle"			"vehicle/engine/tiger_idle3"	}
	}
)
{"veteran_tiger tank"
	("pz6_sound")
	{on "gunner_hatch_open" overload
		{ani_play "open2"}
	}
	("burn_by_engine" args 0.3)
}
(define "pz7_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
				{link_sound "engine"			"vehicle/engine/pz7_run"		}
				{link_sound "engine_end"		"vehicle/engine/pz7_end"	}
				{link_sound "rotate_turret" 	"vehicle/turret/pz7_rot"	}
		{link_sound "exhaust"			"vehicle/engine/pz7_up"	}
	}
)
{"pz7_174 tank"
	("pz7_sound")
	("burn_by_engine" args 0.3)
}
{"pz7_174 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/pz7_run"		}
		{link_sound "engine_end"		"vehicle/engine/pz7_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/turret_rot"	}
		{link_sound "exhaust"			"vehicle/engine/pz7_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"elefant tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/ferdi_engine"		}
		{link_sound "engine_end"		"vehicle/engine/ferdi_engine_end"	}
		{link_sound "exhaust"			"vehicle/engine/ferdi_engine_up"	}
		{link_sound "idle"			"vehicle/engine/ferdi_engine"	}
		}
	("burn_by_engine" args 0.3)
}
{"maus tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/ferdi_engine"		}
		{link_sound "engine_end"		"vehicle/engine/ferdi_engine_end"	}
		{link_sound "exhaust"			"vehicle/engine/ferdi_engine_up"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pz6"	}		
		{link_sound "idle"			"vehicle/engine/ferdi_engine"	}
		}
	("burn_by_engine" args 0.3)
}
{"jagdtiger tank"
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}	
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sheavy"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}
	}
	("burn_by_engine" args 0.3)
}
{"hetzer tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/hetzer"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"	}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"np_ba20 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/wheels"	}
		{link_sound "engine"			"vehicle/engine/ba11"		}
		{link_sound "engine_end"		"vehicle/engine/ba11_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine/ba11_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"ba64 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/wheels"	}
		{link_sound "engine"			"vehicle/engine/ba11"		}
		{link_sound "engine_end"		"vehicle/engine/ba11_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine/ba11_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"ba64d tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/wheels"	}
		{link_sound "engine"			"vehicle/engine/ba11"		}
		{link_sound "engine_end"		"vehicle/engine/ba11_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine/ba11_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"lancia_iz tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/wheels"	}
		{link_sound "engine"			"vehicle/engine/ba11"		}
		{link_sound "engine_end"		"vehicle/engine/ba11_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine/ba11_up"	}
	}
}
{"pz2l tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz2"	}
		{link_sound "engine"			"vehicle/engine/pz2"		}
		{link_sound "engine_end"		"vehicle/engine/pz2_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine/pz2_up" 	}
		{link_sound "idle"			"vehicle/engine/pz2c"	}		
	}
	("burn_by_engine" args 0.3)
}
{"pz2f tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz2"	}
		{link_sound "engine"			"vehicle/engine/pz2"		}
		{link_sound "engine_end"		"vehicle/engine/pz2_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine/pz2_up" 	}
		{link_sound "idle"			"vehicle/engine/pz2c"	}		
	}
	("burn_by_engine" args 0.3)
}
{"pz2j tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz2"	}
		{link_sound "engine"			"vehicle/engine/pz2"		}
		{link_sound "engine_end"		"vehicle/engine/pz2_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine/pz2_up" 	}
		{link_sound "idle"			"vehicle/engine/pz2c"	}		
	}
	("burn_by_engine" args 0.3)
}
{"pz2g1 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz2"	}
		{link_sound "engine"			"vehicle/engine/pz2"		}
		{link_sound "engine_end"		"vehicle/engine/pz2_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine/pz2_up" 	}
		{link_sound "idle"			"vehicle/engine/pz2c"	}		
	}
	("burn_by_engine" args 0.3)
}
{"pz2-50 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz2"	}
		{link_sound "engine"			"vehicle/engine/pz2"		}
		{link_sound "engine_end"		"vehicle/engine/pz2_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine/pz2_up" 	}
		{link_sound "idle"			"vehicle/engine/pz2c"	}		
	}
	("burn_by_engine" args 0.3)
}
(define "pz3_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz3"	}
		{link_sound "engine"			"vehicle/engine/pz3"		}
		{link_sound "engine_end"		"vehicle/engine/pz3_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "exhaust"			"vehicle/engine/pz3_up"	}
		{link_sound "idle"			"vehicle/engine/stug"	}	
	}
)
(define "pz4_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz4"	}
		{link_sound "engine"			"vehicle/engine/pz4"		}
		{link_sound "engine_end"		"vehicle/engine/pz4_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy1"	}
		{link_sound "exhaust"			"vehicle/engine/pz4_up"	  	}
		{link_sound "idle"			"vehicle/engine/stug"	}		
	}
)
{"steyr_rso tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz2"	}
		{link_sound "engine"			"vehicle/engine/pz1"		}
		{link_sound "engine_end"		"vehicle/engine/pz2_end"	}
		{link_sound "exhaust"			"vehicle/engine/pz2_up" 	}
		{link_sound "idle"			"vehicle/engine/pz2c"	}		
	}
	("burn_by_engine" args 0.3)
}
{"pz3e tank"
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"	}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"	}
	}	
	{on fire "mgun2" overload
		{if  name "00"
			{view start "flashbarrel00"}
		else name "01"
			{view start "flashbarrel01"}
		}
	}
	("pz3_sound")	
	("burn_by_engine" args 0.3)
}
{"pz3e_39 tank"
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"	}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"	}	
	}	
	{on fire "mgun2" overload
		{if  name "00"
			{view start "flashbarrel00"}
		else name "01"
			{view start "flashbarrel01"}
		}
	}
	("pz3_sound")	
	("burn_by_engine" args 0.3)
}
{"pz3f tank"
	("pz3_sound")
	("burn_by_engine" args 0.3)
}
{"pz3g tank"
	("pz3_sound")
	("burn_by_engine" args 0.3)
}
{"pz3j tank"
	("pz3_sound")
	("burn_by_engine" args 0.3)
}
{"pz3 tank"
	("pz3_sound")
	("burn_by_engine" args 0.3)
}
{"pz3n tank"
	("pz3_sound")
	("burn_by_engine" args 0.3)
}
{"pz3l tank"
	("pz3_sound")
	("burn_by_engine" args 0.3)
}
{"pz3_m tank"
	("pz3_sound")
	("burn_by_engine" args 0.3)
}
{"pz3_m_flamer tank"
	("pz3_sound")
	("burn_by_engine" args 0.3)
}
{"pz3m tank"
	("pz3_sound")
	("burn_by_engine" args 0.3)
}
{"stug3g tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz3"	}
		{link_sound "engine"			"vehicle/engine/pz3"		}
		{link_sound "engine_end"		"vehicle/engine/pz3_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy2"	}
		{link_sound "exhaust"			"vehicle/engine/pz3_up" 	}
		{link_sound "idle"			"vehicle/engine/stugiii"	}			
	}
	{on "gunner_hatch_open" overload
		{ani_play "close"}
	}
	("burn_by_engine" args 0.3)
}
{"stug4g tank"
	("pz4_sound")
	("burn_by_engine" args 0.3)  
}
{"karlthor tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/churchill"		}
		{link_sound "engine"			"vehicle/engine/churchill"		}
		{link_sound "engine_end"		"vehicle/engine/churchill_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/churchill_up" 	}
	}
	("burn_by_engine" args 0.3)
}
{"s35 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/churchill"		}
		{link_sound "engine"			"vehicle/engine/churchill"		}
		{link_sound "engine_end"		"vehicle/engine/churchill_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/churchill_up" 	}
	}
	("burn_by_engine" args 0.3)
}
{"d2 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/churchill"		}
		{link_sound "engine"			"vehicle/engine/churchill"		}
		{link_sound "engine_end"		"vehicle/engine/churchill_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/churchill_up" 	}
	}
	("burn_by_engine" args 0.3)
}
{"b1 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/churchill"		}
		{link_sound "engine"			"vehicle/engine/churchill"		}
		{link_sound "engine_end"		"vehicle/engine/churchill_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/churchill_up" 	}
	}
	("burn_by_engine" args 0.3)
}
{"b1bis tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/churchill"		}
		{link_sound "engine"			"vehicle/engine/churchill"		}
		{link_sound "engine_end"		"vehicle/engine/churchill_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/churchill_up" 	}
	}
	("burn_by_engine" args 0.3)
}
{"b1ter tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/churchill"		}
		{link_sound "engine"			"vehicle/engine/churchill"		}
		{link_sound "engine_end"		"vehicle/engine/churchill_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/churchill_up" 	}
	}
	("burn_by_engine" args 0.3)
}
{"b40 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/churchill"		}
		{link_sound "engine"			"vehicle/engine/churchill"		}
		{link_sound "engine_end"		"vehicle/engine/churchill_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/churchill_up" 	}
	}
	("burn_by_engine" args 0.3)
}
{"tog2 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/churchill"		}
		{link_sound "engine"			"vehicle/engine/churchill"		}
		{link_sound "engine_end"		"vehicle/engine/churchill_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/churchill_up" 	}
	}
	("burn_by_engine" args 0.3)
}
{"pz4c tank"
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
{"pz4e tank"
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
{"pz4f_1 tank"
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
{"pz4f_U tank"
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
{"pz4f_2 tank"
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
{"pz3m tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz3"	}
		{link_sound "engine"			"vehicle/engine/pz3"		}
		{link_sound "engine_end"		"vehicle/engine/pz3_end"	}
		{link_sound "exhaust"			"vehicle/engine/pz3_up" 	}
	}
	("burn_by_engine" args 0.3)
}
(define "wespe_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz3"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/pz2_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy1"	}
		{link_sound "exhaust"			"vehicle/engine/pz2_up"	  	}
		{link_sound "idle"			"vehicle/engine/pz2c"	}		
	}
)
{"ger_trailer tank"  
	("pz3_sound")
	("burn_by_engine" args 0.3)
}
{"wespe tank"
	("wespe_sound")
	("burn_by_engine" args 0.3)
}
{"pz4d tank"
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
{"jagdpanzer_iv tank"
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
{"welberwind tank"
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
{"ostwind tank"
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
{"pz4g tank"
	("pz4_sound")
	("burn_by_engine" args 0.3)    		
}
{"pz4h tank"
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
{"pz4j tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz4"	}
		{link_sound "engine"			"vehicle/engine/pz4"		}
		{link_sound "engine_end"		"vehicle/engine/pz4_end"	}
        {link_sound "rotate_turret" 	"vehicle/turret/medium3"	}	
		{link_sound "exhaust"			"vehicle/engine/pz4_up"	  	}
		{link_sound "idle"			"vehicle/engine/stug"	}		
	}	
	("burn_by_engine" args 0.3)
}
{"hummel tank"
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
{"nashorn tank"
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
(define "sdkfz_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/wheels"			}
		{link_sound "engine"			"vehicle/engine/sdkfz232"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz232_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"			}
		{link_sound "exhaust"			"vehicle/engine/sdkfz232_up"	}
	}
)
{"sdkfz222 tank"
	("sdkfz_sound")
	("burn_by_engine" args 0.3)
}
{"sdkfz222_42 tank"
	("sdkfz_sound")
}
{"sdkfz231 tank"
	("sdkfz_sound")
}
{"sdkfz231_41 tank"
	("sdkfz_sound")
}
{"sdkfz223 tank"
	("sdkfz_sound")
	("burn_by_engine" args 0.3)
}
{"sdkfz232 tank"
	("sdkfz_sound")
	("burn_by_engine" args 0.3)
}
(define "sdkfz234_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz234"		}
		{link_sound "engine"			"vehicle/engine/sdkfz234"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz234_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy1"			}
		{link_sound "exhaust"			"vehicle/engine/sdkfz234_up"	}
	}
)
{"sdkfz234 tank"
	("sdkfz234_sound")
	("burn_by_engine" args 0.3)
}
{"sdkfz234_ger2 tank"
	("sdkfz234_sound")
	("burn_by_engine" args 0.3)
}
{"ba10 tank"
	("sdkfz234_sound")
	("burn_by_engine" args 0.3)
}
{"ba10_ger tank"
	("sdkfz234_sound")
	("burn_by_engine" args 0.3)
}
{"ba11 tank"
	("sdkfz234_sound")
	("burn_by_engine" args 0.3)
}
{"type87 tank"
	("sdkfz234_sound")
	("burn_by_engine" args 0.3)
}
{"type93scout tank"
	("sdkfz234_sound")
	("burn_by_engine" args 0.3)
}
{"m8grayhound tank"
	("m8grayhound_sound")
	("burn_by_engine" args 0.3)
}
{"ab40 tank"
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"	}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"	}
	}
	{on fire "mgun" overload
		{if  name "00"
			{view start "flashbarrel00"}
			{delay 0.8
				{view pause "flashbarrel00"}
			}
		else name "01"
			{view start "flashbarrel01"}
			{delay 0.8
				{view pause "flashbarrel01"}
			}
		}
	}
	("as37_sound")
	("burn_by_engine" args 0.3)
}
{"ab41 tank"
	("as37_sound")
	("burn_by_engine" args 0.3)
}
{"ab43 tank"
	("as37_sound")
	("burn_by_engine" args 0.3)
}
{"panhard tank"
	("m8grayhound_sound")
	("burn_by_engine" args 0.3)
}
{"m20 tank"
	("m8grayhound_sound")
	("burn_by_engine" args 0.3)
}
{"mk2daimler"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/wheels"			}
		{link_sound "engine"			"vehicle/engine/sdkfz234"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz234_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"			}
		{link_sound "exhaust"			"vehicle/engine/sdkfz234_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"mk2daimler_42"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/wheels"			}
		{link_sound "engine"			"vehicle/engine/sdkfz234"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz234_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"			}
		{link_sound "exhaust"			"vehicle/engine/sdkfz234_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"mk2daimler_Late"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/wheels"			}
		{link_sound "engine"			"vehicle/engine/sdkfz234"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz234_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"			}
		{link_sound "exhaust"			"vehicle/engine/sdkfz234_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"Humber"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/wheels"			}
		{link_sound "engine"			"vehicle/engine/sdkfz234"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz234_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"			}
		{link_sound "exhaust"			"vehicle/engine/sdkfz234_up"	}
	}
	("burn_by_engine" args 0.3)
}
(define "hanomag_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz251"	}
		{link_sound "engine"			"vehicle/engine/sdkfz251"	}
		{link_sound "engine_end"		"vehicle/engine/sdkfz251_end"}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"		}
		{link_sound "exhaust"			"vehicle/engine/sdkfz251_up"	}
	}
)
{"sdkfz4 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz10"	 }
		{link_sound "engine"			"vehicle/engine/sdkfz250"	 }
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"}
		{link_sound "rotate_turret" 	"vehicle/turret/light"		 }
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up" }
	}
	("burn_by_engine" args 0.3)
}
{"sdkfz251_1 tank"
	("hanomag_sound")
	("burn_by_engine" args 0.3)
}
{"SdKfz251 tank"
	("hanomag_sound")
	("burn_by_engine" args 0.3)
}
{"np_sdKfz251_2 tank"
	("hanomag_sound")
	("burn_by_engine" args 0.3)
}
{"sdKfz251_2 tank"
	("hanomag_sound")
	("burn_by_engine" args 0.3)
}
{"sdKfz251_2 tank"
	("hanomag_sound")
	("burn_by_engine" args 0.3)
}
{"SdKfz251_10 tank"
	("hanomag_sound")
	("burn_by_engine" args 0.3)
}
{"SdKfz251_10c tank"
	("hanomag_sound")
	{on "gunner_hatch_open" overload}
	("burn_by_engine" args 0.3)
}
{"SdKfz251m tank"
	("hanomag_sound")
	{on "gunner_hatch_open" overload}
	("burn_by_engine" args 0.3)
}
{"ho-ha3mgun tank"
	("hanomag_sound")
	("burn_by_engine" args 0.3)
}
{"ho-ha3_nw tank"
	("hanomag_sound")
	("burn_by_engine" args 0.3)
}
(define "m3_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m3a1"	}
		{link_sound "engine"			"vehicle/engine/m3a1"		}
		{link_sound "engine_end"		"vehicle/engine/m3a1_end"	}
;		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "exhaust"			"vehicle/engine/m3a1_up"	}
	}
)
{"m3 tank"
	("m3_sound")
	("burn_by_engine" args 0.3)
}
{"m3_usa tank"
	("m3_sound")
	("burn_by_engine" args 0.3)
}
{"m3_eng tank"
	("m3_sound")
	("burn_by_engine" args 0.3)
}
{"m16 tank"
	("m3_sound")
	("burn_by_engine" args 0.3)
}
{"m2_ally tank"
	("m3_sound")
	("burn_by_engine" args 0.3)
}
{"m2 tank"
	("m3_sound")
	("burn_by_engine" args 0.3)
}
{"grant_m3 tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
	{on spawn
		{add_view	"flash_cannon_small"		"flashbarrel2"			"Foresight2"}
		{add_view	"smoke_zenite"			"smoke_gun2" 			"Foresight2"}
		{add_view	"flash_gun_big"			"flashbarrel01"	"shooter00"}
		{add_view	"flash_gun_big"			"flashbarrel00"	"shooter01"} 
	}
	{on fire "gun1"
	       	{spawn "dust_shot_small" 				"basis"}
        	{spawn "tank_canon_fire_verysmall" 		"Foresight2" x}
		{ani_play "fire1"}
		{view start "smoke_gun2"}
		{delay 2 0.5
			{view stop "smoke_gun2"}
			{add_view	"smoke_zenite"			"smoke_gun2" 			"Foresight2"}
		}
	}
	{on fire "mgun1" overload
		{if  name "00"
			{view start "flashbarrel00"}
		else name "01"
			{view start "flashbarrel01"}
		}
	}
} 
{"t5p tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
	{on spawn
		{add_view	"flash_cannon_small"		"flashbarrel2"			"Foresight2"}
		{add_view	"smoke_zenite"			"smoke_gun2" 			"Foresight2"}
		{add_view	"flash_gun_big"			"flashbarrel01"	"shooter00"}
		{add_view	"flash_gun_big"			"flashbarrel00"	"shooter01"} 
	}
	{on fire "gun1"
	       	{spawn "dust_shot_small" 				"basis"}
        	{spawn "tank_canon_fire_verysmall" 		"Foresight2" x}
		{ani_play "fire1"}
		{view start "smoke_gun2"}
		{delay 2 0.5
			{view stop "smoke_gun2"}
			{add_view	"smoke_zenite"			"smoke_gun2" 			"Foresight2"}
		}
	}
	{on fire "mgun1" overload
		{if  name "00"
			{view start "flashbarrel00"}
		else name "01"
			{view start "flashbarrel01"}
		}
	} 
}
{"m3grant tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
	{on spawn
		{add_view	"flash_cannon_small"		"flashbarrel2"			"Foresight2"}
		{add_view	"smoke_zenite"			"smoke_gun2" 			"Foresight2"}
		{add_view	"flash_gun_big"			"flashbarrel01"	"shooter00"}
		{add_view	"flash_gun_big"			"flashbarrel00"	"shooter01"} 
	}
	{on fire "gun1"
	       	{spawn "dust_shot_small" 				"basis"}
        	{spawn "tank_canon_fire_verysmall" 		"Foresight2" x}
		{ani_play "fire1"}
		{view start "smoke_gun2"}
		{delay 2 0.5
			{view stop "smoke_gun2"}
			{add_view	"smoke_zenite"			"smoke_gun2" 			"Foresight2"}
		}
	}
	{on fire "mgun" overload
		{if  name "00"
			{view start "flashbarrel00"}
		else name "01"
			{view start "flashbarrel01"}
		}
	} 
}  
(define "cometa34_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/kv"	}
		{link_sound "engine"			"vehicle/engine/m7"		}
		{link_sound "engine_end"		"vehicle/engine/m7_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/t34"	}
		{link_sound "exhaust"			"vehicle/engine/t26_up"	}
	}
)
{"sdkfz7_1 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz10"	}
		{link_sound "engine"			"vehicle/engine/blitz"	}
		{link_sound "engine_end"		"vehicle/engine/blitz_end"}
		{link_sound "rotate_turret" 	"vehicle/turret/flak38"		}
		{link_sound "exhaust"			"vehicle/engine/blitz_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"sdkfz7 tank"
	(define "break_glass_sdkfz8"
 	{volumes "glass%1" disable bullet contact blast}
 	{spawn "glass_hit2" "glass%1" x}
 	{delay 0.1
 	{bone cut "glass%1"}
	}
	)
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
	{on bullet_hit
 		{if volume "glass_front"
 			("break_glass_sdkfz8" args 1 _front)
 		}
 	}
}
{"sws_flak"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
}
{"cometa34 tank"
	("cometa34_sound")
	("burn_by_engine" args 0.3)
}
{"centurion tank"
	("cometa34_sound")
	("burn_by_engine" args 0.3)
}
{"mkvii"
	("cometa34_sound")
	("burn_by_engine" args 0.3)
}
{"conqueror"
	("cometa34_sound")
	("burn_by_engine" args 0.3)
}
{"fv215b"
	("cometa34_sound")
	("burn_by_engine" args 0.3)
}
{"fv215b_183"
	("cometa34_sound")
	("burn_by_engine" args 0.3)
}
{"daimler tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/wheels"			}
		{link_sound "engine"			"vehicle/engine/sdkfz234"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz234_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium"			}
		{link_sound "exhaust"			"vehicle/engine/sdkfz234_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"mkdaimler tank"
	("m3_sound")
	("burn_by_engine" args 0.3)
}
(define "m10wolverine_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/mk2"	}
		{link_sound "engine"			"vehicle/engine/m10wolverine"		}
		{link_sound "engine_end"		"vehicle/engine/m4_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sherman"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
		{link_sound "idle"			        "vehicle/engine/Sherman_Idle"	}		
	}
)
{"m10wolverine tank"
	("m10wolverine_sound")
	{on "gunner_hatch_open" overload
		{ani_play "close"}
	}
	("burn_by_engine" args 0.3)
}
{"m36 tank"
	("m10wolverine_sound")
	{on "gunner_hatch_open" overload
		{ani_play "close"}
	}
	("burn_by_engine" args 0.3)
}
{"m36b1 tank"
	("m10wolverine_sound")
	{on "gunner_hatch_open" overload
		{ani_play "close"}
	}
	("burn_by_engine" args 0.3)
}
{"m4a2 tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m4a3dd tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m4a3e2 tank"
	("m4_sound")
	("burn_by_engine" args 0.3)
}
{"m18 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/mk2"	}
		{link_sound "engine"			"vehicle/engine/m18hellcat"		}
		{link_sound "engine_end"		"vehicle/engine/m4_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sherman"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
		{link_sound "idle"			        "vehicle/engine/Sherman_Idle"	}		
	}
	("burn_by_engine" args 0.3)
}
{"achilles tank"
	("m10wolverine_sound")
	{on "gunner_hatch_open" overload
		{ani_play "close"}
	}
	("burn_by_engine" args 0.3)
}
{"archer tank"
	("bishop_sound")
	("burn_by_engine" args 0.3)
}
{"203b4 tank"
	("bishop_sound")
	("burn_by_engine" args 0.3)
}
{"m24 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m3stuart"	}
		{link_sound "engine"			"vehicle/engine/m18hellcat"		}
		{link_sound "engine_end"		"vehicle/engine/m4_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sherman"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
		{link_sound "idle"			        "vehicle/engine/Sherman_Idle"	}		
	}
	("burn_by_engine" args 0.3)
}
{"m41 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m3stuart"	}
		{link_sound "engine"			"vehicle/engine/m18hellcat"		}
		{link_sound "engine_end"		"vehicle/engine/m4_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sherman"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
		{link_sound "idle"			        "vehicle/engine/Sherman_Idle"	}		
	}
	("burn_by_engine" args 0.3)
}
{"m5a1 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m3stuart"	}
		{link_sound "engine"			"vehicle/engine/m3stuart"		}
		{link_sound "engine_end"		"vehicle/engine/tankengine_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "exhaust"			"vehicle/engine/tankengine_up"	}
		{link_sound "idle"			"vehicle/engine/Crusader_Idle"	}		
	}
	("burn_by_engine" args 0.3)
}
{"sturmtiger tank"
    {on spawn
        {bone hide "mask_ammo"}
    }
	("tiger_sound")
	("burn_by_engine" args 0.3)
    {on "_explosion" overload
            {delay_ex 0
                    {set "no_burn_volumes" 1}
                    {set_skeleton "_xx"}
                    {ani_play "death"}
                    {call "cut_parts"}
            {set "big_explosion" 0}
            {spawn "fuel_die"}
            {blastwave c4 5 r0 4 r1 15}
            {fire radius 8 time 15 heating 10}

            {if explosive_amount 50         
                {blastwave c4 30 r0 8 r1 16}     
                {blastwave c4 3 r0 20 r1 30}
                {spawn "train_die" "basis"}
                {set "big_explosion" 1}
            }
        }
    }
    {on fire "gun"
        {spawn "sturmtiger_fire" inv_normal}
        {delay 0.1
            {ani_play "reload"}
            {bone hide "rocket_shell00"}
        }
        {delay 32
            {bone show "mask_ammo"}
        }
        {delay 81
            {bone hide "mask_ammo"}
        }
        {delay 120
            {bone show "rocket_shell00"}
        }
    }
	{on "__explosion"
		{set "big_explosion" 0}
		{if explosive_amount 50         
			{blastwave c4 30 r0 8 r1 16}     
			{blastwave c4 3 r0 20 r1 30}
			{spawn "train_die" "basis"}
			{set "big_explosion" 1}
		}
	}
	{on "spawn_shellhole"
		{if "big_explosion"
			{spawn "crater_extra_big" "basis" terrain_texmod}
			{spawn "shellhole_big_dead" "basis"}
		}
	}
	{on pierce	
		
		;{stop_sound "hit"}
		{if volume "module"
			{if stuff "shell fg" 	{bullet_detonate}}
				
		}
		{if stuff "shell huge"
				{spawn "pierce_large"}
			else stuff "shell large"
				{spawn "pierce_large"}
			else stuff "shell"
				{spawn "pierce"}
		}

		{if component "main"
			{bullet_detonate}
			{if stuff "rocketlauncher"
				{burn fx "smoke_dead_tank2_fast" fake}
			else stuff "heat"
				{burn fx "smoke_dead_tank2_fast" fake}
			else
				
			}
		}
		{if volume "explosive"
			{if rand 0.1 {call "explosive_broken"}}
		}
								
		{if component "gun"
			{if rand 0.15 {components "gun" break}}
		}
		{if component "engine"
			{if rand 0.15 {components "engine" break}}
			{if rand 0.10 {call "engine_on_fire"}}
		
		}	
	}
    {on break
        {if  component "shield"
             ("cut_shield_part" args "shieldr1")
             ("cut_shield_part" args "shieldr2")
             ("cut_shield_part" args "shieldr3")
             ("cut_shield_part" args "shieldr4")
             ("cut_shield_part" args "shieldr5")
             ("cut_shield_part" args "shieldr6")
             ("cut_shield_part" args "shieldl1")
             ("cut_shield_part" args "shieldl2")
             ("cut_shield_part" args "shieldl3")
             ("cut_shield_part" args "shieldl4")
             ("cut_shield_part" args "shieldl5")
             ("cut_shield_part" args "shieldl6")
        }
    }	
}
{"chi-ha120 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}			
	}
	("burn_by_engine" args 0.3)
}
{"chi-ha47 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}			
	}
	("burn_by_engine" args 0.3)
}
{"chi-ha57 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}			
	}
	("burn_by_engine" args 0.3)
}
{"chi-ha57 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}			
	}
	("burn_by_engine" args 0.3)
}
{"chi_ni tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/pz1"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/mb_end"}
		{link_sound "exhaust"			"vehicle/engine/mb_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}			
	}
	("burn_by_engine" args 0.3)
}
{"ha-go tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/pz1"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/mb_end"}
		{link_sound "exhaust"			"vehicle/engine/mb_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}			
	}
	("burn_by_engine" args 0.3)
}
{"ha-go_kai tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/pz1"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/mb_end"}
		{link_sound "exhaust"			"vehicle/engine/mb_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}			
	}
	("burn_by_engine" args 0.3)
}
{"t18 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/pz1"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/mb_end"}
		{link_sound "exhaust"			"vehicle/engine/mb_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}			
	}
	("burn_by_engine" args 0.3)
}
{"t-38 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/pz1"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/mb_end"}
		{link_sound "exhaust"			"vehicle/engine/mb_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}			
	}
	("burn_by_engine" args 0.3)
}
{"t40 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/pz1"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/mb_end"}
		{link_sound "exhaust"			"vehicle/engine/mb_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}			
	}
	("burn_by_engine" args 0.3)
}
{"te-ke tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/pz1"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/mb_end"}
		{link_sound "exhaust"			"vehicle/engine/mb_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}			
	}
	("burn_by_engine" args 0.3)
}
{"ke-ni tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/pz1"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/mb_end"}
		{link_sound "exhaust"			"vehicle/engine/mb_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}			
	}
	("burn_by_engine" args 0.3)
}
{"ke-to tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/pz1"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/mb_end"}
		{link_sound "exhaust"			"vehicle/engine/mb_up"	}
	}
}
{"ke-ri tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/pz1"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/mb_end"}
		{link_sound "exhaust"			"vehicle/engine/mb_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}			
	}
	("burn_by_engine" args 0.3)
}
{"ke-nu tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/mb_end"}
		{link_sound "exhaust"			"vehicle/engine/mb_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}			
	}
	("burn_by_engine" args 0.3)
}
{"ke-nu-kai tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/mb_end"}
		{link_sound "exhaust"			"vehicle/engine/mb_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}			
	}
	("burn_by_engine" args 0.3)
}
{"ka-ho tank"
	{on spawn
		{add_view "flamer_fire" "flame1" "foresight9"}
		{add_view "flamer_fire_barrel" "fire1" "foresight9"}
		{view show	"fire1"}

		{view start	"fire1"}
	}
	{on operatable on	
		{view start	"fire1"}
	}	
	{on operatable off		
		{view stop	"fire1"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	{on fire "flamer1"
		{view start	"flame1"}
		{kill_delay "fire1"}
		{delay 0.5 "fire1"
			{view pause	"flame1"}
		}
	}
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/mb_end"}
		{link_sound "exhaust"			"vehicle/engine/mb_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}			
	}
	("burn_by_engine" args 0.3)
}
{"ke_ho tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/mb_end"}
		{link_sound "exhaust"			"vehicle/engine/mb_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}			
	}
	("burn_by_engine" args 0.3)
}
{"chi-he tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/tank_end"}
		{link_sound "exhaust"			"vehicle/engine/tank_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}		
	}
	("burn_by_engine" args 0.3)
}
{"chi-he1 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/tank_end"}
		{link_sound "exhaust"			"vehicle/engine/tank_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}		
	}
	("burn_by_engine" args 0.3)
}
{"chi-nu tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium1"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/mb_end"}
		{link_sound "exhaust"			"vehicle/engine/mb_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}		
	}
	("burn_by_engine" args 0.3)
}
{"chi-nu_2 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium1"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/mb_end"}
		{link_sound "exhaust"			"vehicle/engine/mb_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}		
	}
	("burn_by_engine" args 0.3)
}
{"ka-chi tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium1"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/mb_end"}
		{link_sound "exhaust"			"vehicle/engine/mb_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}		
	}
	("burn_by_engine" args 0.3)
}
{"chi-to tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium1"	}
		{link_sound "move"				"vehicle/tracks/mk7"	}
		{link_sound "engine"			"vehicle/engine/mk7"	}
		{link_sound "engine_end"		"vehicle/engine/mk7_end"}
		{link_sound "exhaust"			"vehicle/engine/mk7_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}		
	}
	("burn_by_engine" args 0.3)
}
{"ho-i tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}	
	}
	("burn_by_engine" args 0.3)
}
{"ho-ni1 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}		
	}
	("burn_by_engine" args 0.3)
}
{"ho-ni2 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}			
	}
	("burn_by_engine" args 0.3)
}
{"ho-ni_3_105 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}			
	}
	("burn_by_engine" args 0.3)
}
{"ho-ni_3 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}			
	}
	("burn_by_engine" args 0.3)
}
{"ho-ro tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}			
	}
	("burn_by_engine" args 0.3)
}
{"churchill_avre tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/churchill"		}
		{link_sound "engine"			"vehicle/engine/churchill"		}
		{link_sound "engine_end"		"vehicle/engine/churchill_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/churchill_up" 	}
	}
	("burn_by_engine" args 0.3)
}
{"churchill_mk_vii tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/churchill"		}
		{link_sound "engine"			"vehicle/engine/churchill"		}
		{link_sound "engine_end"		"vehicle/engine/churchill_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}  
		{link_sound "exhaust"			"vehicle/engine/churchill_up" 	}
	}
	("burn_by_engine" args 0.3)
}
{"churchill_mk_vii tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/churchill"		}
		{link_sound "engine"			"vehicle/engine/churchill"		}
		{link_sound "engine_end"		"vehicle/engine/churchill_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/churchill_up" 	}
	}
	("burn_by_engine" args 0.3)
}
{"churchill_mk_vii_95 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/churchill"		}
		{link_sound "engine"			"vehicle/engine/churchill"		}
		{link_sound "engine_end"		"vehicle/engine/churchill_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/churchill_up" 	}
	}
	("burn_by_engine" args 0.3)
}
{"churchill_mk_vii_952 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/churchill"		}
		{link_sound "engine"			"vehicle/engine/churchill"		}
		{link_sound "engine_end"		"vehicle/engine/churchill_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/churchill_up" 	}
	}
	("burn_by_engine" args 0.3)
}
{"black_prince tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/churchill"		}
		{link_sound "engine"			"vehicle/engine/churchill"		}
		{link_sound "engine_end"		"vehicle/engine/churchill_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/t34"	}
		{link_sound "exhaust"			"vehicle/engine/churchill_up" 	}
	}
	("burn_by_engine" args 0.3)
}
{"nimrod tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz2"	}
		{link_sound "engine"			"vehicle/engine/pz2"		}
		{link_sound "engine_end"		"vehicle/engine/pz2_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine/pz2_up" 	}
		{link_sound "idle"			"vehicle/engine/pz2c"	}
	}
	("burn_by_engine" args 0.3)
}
{"turan3 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/hetzer"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/hetzer"	}
	}
	("burn_by_engine" args 0.3)
}
{"turan2 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/hetzer"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/hetzer"	}
	}
	("burn_by_engine" args 0.3)
}
{"turan1 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/hetzer"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/hetzer"	}
	}
	("burn_by_engine" args 0.3)
}
{"zrinyi1 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/hetzer"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/hetzer"	}
	}
	("burn_by_engine" args 0.3)
}
{"zrinyi2 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/hetzer"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/hetzer"	}
	}
	("burn_by_engine" args 0.3)
}
{"tas_44td tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/hetzer"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/hetzer"	}
	}
	("burn_by_engine" args 0.3)
}
{"tas_44m_75 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/hetzer"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/hetzer"	}
	}
	("burn_by_engine" args 0.3)
}
{"tas_44m tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/hetzer"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/hetzer"	}
	}
	("burn_by_engine" args 0.3)
}
{"P40_3 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/hetzer"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/hetzer"	}
	}
	("burn_by_engine" args 0.3)
}
{"P40_2 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/hetzer"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/hetzer"	}
	}
	("burn_by_engine" args 0.3)
}
{"P40 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/hetzer"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/hetzer"	}
	}
	("burn_by_engine" args 0.3)
}
{"carro15 tank"
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"	}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"	}
	}
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/hetzer"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/hetzer"	}
	}
	{on fire "mgun1"
		{if  name "00"
			{view start "flashbarrel00"}
		else name "01"
			{view start "flashbarrel01"}
		}
	}	
	("burn_by_engine" args 0.3)
}
{"carro14_41 tank"
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"	}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"	}
	}
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/hetzer"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/hetzer"	}
	}
	{on fire "mgun1"
		{if  name "00"
			{view start "flashbarrel00"}
		else name "01"
			{view start "flashbarrel01"}
		}
	}	
	("burn_by_engine" args 0.3)
}
{"carro13_40 tank"
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"	}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"	}
	}
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/hetzer"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/hetzer"	}
	}
	{on fire "mgun1"
		{if  name "00"
			{view start "flashbarrel00"}
		else name "01"
			{view start "flashbarrel01"}
		}
	}	
	("burn_by_engine" args 0.3)
}
{"m1139 tank"
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"	}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"	}
	}
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/hetzer"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/hetzer"	}
	}
	{on fire "mgun1"
		{if  name "00"
			{view start "flashbarrel00"}
		else name "01"
			{view start "flashbarrel01"}
		}
	}	
	("burn_by_engine" args 0.3)
}
{"as37 tank"
	("as37_sound")
	("burn_by_engine" args 0.3)
}
{"fiat611 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 		"vehicle/turret/light1"		}
		{link_sound "move"			"vehicle/wheels/dodge"		}
		{link_sound "engine"			"vehicle/engine/m3a1"		}
		{link_sound "engine_end"		"vehicle/engine/m3a1_end"	}
		{link_sound "exhaust"			"vehicle/engine/m3a1_up"	}
		{link_sound "idle"			"vehicle/engine/m3a1"		}
	}
	("burn_by_engine" args 0.3)
}
{"Lancia1ZM tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 		"vehicle/turret/light1"		}
		{link_sound "move"			"vehicle/wheels/dodge"		}
		{link_sound "engine"			"vehicle/engine/m3a1"		}
		{link_sound "engine_end"		"vehicle/engine/m3a1_end"	}
		{link_sound "exhaust"			"vehicle/engine/m3a1_up"	}
		{link_sound "idle"			"vehicle/engine/m3a1"		}
	}
	("burn_by_engine" args 0.3)
}
{"lince tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/wheels/wheels"		}
		{link_sound "engine"			"vehicle/engine/daimler"	}
		{link_sound "engine_end"		"vehicle/engine/daimler_end"	}
		{link_sound "rotate_turret" 		"vehicle/turret/light1"		}
		{link_sound "exhaust"			"vehicle/engine/daimler_up"	}
		{link_sound "idle"			"vehicle/engine/daimler"	}
	}
	("burn_by_engine" args 0.3)
}
{"l640 tank"
	("l640_sound")
	("burn_by_engine" args 0.3)
}
{"l640fl tank"
	("l640_sound")
	{on spawn
		{add_view "flamer_fire" "flame1" "foresight9"}
		{add_view "flamer_fire_barrel" "fire1" "foresight9"}
		{view show	"fire1"}

		{view start	"fire1"}

	}
	{on operatable on	
		{view start	"fire1"}
	}	
	{on operatable off		
		{view stop	"fire1"}
	}
	{on break_armor
		{if name "blast"
			{if volume "body"
				{call "explosion"}
			}
                		}
	}
	{on bullet_hit
		{if volume "body"
			{if  tagged "isbodypierced"
				{if rand 0.3
					{call "_explosion"}
					{tags remove "isbodypierced"}
				}
			}
		}
	}
	{on "_explosion"
		{call "__explosion"}
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	{on "__explosion"
		{set "big_explosion" 0}
		{if explosive_amount 50         
			{blastwave c4 30 r0 8 r1 16}     
			{blastwave c4 3 r0 20 r1 30}
			{spawn "train_die" "basis"}
			{set "big_explosion" 1}
		}
	}
	{on fire "flamer1"
		{view start	"flame1"}
		{kill_delay "fire1"}
		{delay 0.5 "fire1"
			{view pause	"flame1"}
		}
	}
	("burn_by_engine" args 0.3)	
}
{"l6a tank"
	("l640_sound")
	("burn_by_engine" args 0.3)
}
{"l335c tank"
	("l335_sound")
	("burn_by_engine" args 0.3)
}
{"l35lf tank"
	("l335_sound")
	{on spawn
		{add_view "flamer_fire" "flame1" "foresight9"}
		{add_view "flamer_fire_barrel" "fire1" "foresight9"}
		{view show	"fire1"}

		{view start	"fire1"}

	}
	{on operatable on	
		{view start	"fire1"}
	}	
	{on operatable off		
		{view stop	"fire1"}
	}
	{on break_armor
		{if name "blast"
			{if volume "body"
				{call "explosion"}
			}
                		}
	}
	{on bullet_hit
		{if volume "body"
			{if  tagged "isbodypierced"
				{if rand 0.3
					{call "_explosion"}
					{tags remove "isbodypierced"}
				}
			}
		}
	}
	{on "_explosion"
		{call "__explosion"}
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	{on "__explosion"
		{set "big_explosion" 0}
		{if explosive_amount 50         
			{blastwave c4 30 r0 8 r1 16}     
			{blastwave c4 3 r0 20 r1 30}
			{spawn "train_die" "basis"}
			{set "big_explosion" 1}
		}
	}
	{on fire "flamer1"
		{view start	"flame1"}
		{kill_delay "fire1"}
		{delay 0.5 "fire1"
			{view pause	"flame1"}
		}
	}
	("burn_by_engine" args 0.3)	
}
{"l335 tank"
	("l335_sound")
	("burn_by_engine" args 0.3)
}
{"m4732 tank"
	("l640_sound")
	("burn_by_engine" args 0.3)
}
{"m40c tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/hetzer"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"	}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/hetzer"	}
	}	
	("burn_by_engine" args 0.3)
}
{"m41c tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/hetzer"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"	}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/hetzer"	}
	}
	("burn_by_engine" args 0.3)
}
{"m7518 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/hetzer"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"	}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/hetzer"	}
	}
	("burn_by_engine" args 0.3)
}
{"m7532 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/hetzer"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"	}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/hetzer"	}
	}
	("burn_by_engine" args 0.3)
}
{"m7534 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/hetzer"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"	}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/hetzer"	}
	}
	("burn_by_engine" args 0.3)
}
{"m7546 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/hetzer"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"	}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/hetzer"	}
	}
	("burn_by_engine" args 0.3)
}
{"m10525 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/hetzer"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"	}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/hetzer"	}
	}
	("burn_by_engine" args 0.3)
}
{"m9053 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/hetzer"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/hetzer"	}
	}
	("burn_by_engine" args 0.3)
}
{"m149 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/hetzer"	}
		{link_sound "engine"			"vehicle/engine/hetzer"		}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
		{link_sound "idle"			"vehicle/engine/hetzer"	}
	}
	("burn_by_engine" args 0.3)
}
{"t34_43 tank"
	("t34_sound")
	("burn_by_engine" args 0.2)
}
{"sdkfz135_1 tank"
	("wespe_sound")
	("burn_by_engine" args 0.3)
}
{"ss-d tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/pz1"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/mb_end"}
		{link_sound "exhaust"			"vehicle/engine/mb_up"	}
		{link_sound "idle"			"vehicle/engine/chi-ha"	}			
	}
	{on spawn
		{link_sound "move"				"vehicle/tracks/pz38t"	}
		{link_sound "engine"			"vehicle/engine/Pz38"		}
		{link_sound "engine_end"		"vehicle/engine/Pz38_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pz38t_turret"	}
		{link_sound "exhaust"			"vehicle/engine/Pz38_up" 	}
		{link_sound "idle"			"vehicle/engine/t-38"	}
		
		{add_view "flamer_fire" "flame1" "foresight9"}
		{add_view "flamer_fire" "flame2" "foresight10"}
		{add_view "flamer_fire" "flame3" "foresight13"}
		{add_view "flamer_fire" "flame4" "foresight12"}
		{add_view "flamer_fire" "flame5" "foresight11"}
		
		{add_view "flamer_fire_barrel" "fire1" "foresight9"}
		{add_view "flamer_fire_barrel" "fire2" "foresight10"}
		{add_view "flamer_fire_barrel" "fire3" "foresight13"}
		{add_view "flamer_fire_barrel" "fire4" "foresight12"}
		{add_view "flamer_fire_barrel" "fire5" "foresight11"}
	
		{view show	"fire1"}
		{view show	"fire2"}
		{view show	"fire3"}
		{view show	"fire4"}
		{view show	"fire5"}
		
		{view start	"fire1"}
		{view start	"fire2"}
		{view start	"fire3"}
		{view start	"fire4"}
		{view start	"fire5"}
	}
	{on break_armor
		{if name "pierce"
			{if rand 0.3
				{if volume "body"
					{call "explosion"}
				}
                        }
                else name "blast"
			{if volume "body"
				{call "explosion"}
			}
                }
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 8 time 15 heating 10}
	}
	
	{on fire "flamer1"
		{view start	"flame1"}
		{kill_delay "fire1"}
		{delay 0.5 "fire1"
			{view pause	"flame1"}
		}
	}
	{on fire "flamer2"
		{view start	"flame2"}
		{kill_delay "fire2"}
		{delay 0.5 "fire2"
			{view pause	"flame2"}
		}
	}
	{on fire "flamer3"
		{view start	"flame3"}
		{kill_delay "fire3"}
		{delay 0.5 "fire3"
			{view pause	"flame3"}
		}
	}
	{on fire "flamer4"
		{view start	"flame4"}
		{kill_delay "fire4"}
		{delay 0.5 "fire4"
			{view pause	"flame4"}
		}
	}
	{on fire "flamer5"
		{view start	"flame5"}
		{kill_delay "fire5"}
		{delay 0.5 "fire5"
			{view pause	"flame5"}
		}
	}
		
}
{"churchill_crocodile tank"
	{on spawn
		{add_view "flamer_fire" "flame1" "foresight4"}
		{add_view "flamer_fire_barrel" "fire1" "foresight4"}
		{view show	"fire1"}

		{view start	"fire1"}
	}
	{on operatable on	
		{view start	"fire1"}
	}	
	{on operatable off		
		{view stop	"fire1"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	{on fire "flamer1"
		{view start	"flame1"}
		{kill_delay "fire1"}
		{delay 0.5 "fire1"
			{view pause	"flame1"}
		}
	}
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/churchill"		}
		{link_sound "engine"			"vehicle/engine/churchill"		}
		{link_sound "engine_end"		"vehicle/engine/churchill_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/churchill_up" 	}
	}
	("burn_by_engine" args 0.3)	
}
{"pz3_m_flamer"
	{on spawn
		{add_view "flamer_fire" "flame1" "foresight1"}
		{add_view "flamer_fire_barrel" "fire1" "foresight1"}
		{view show	"fire1"}

		{view start	"fire1"}
	}
	{on operatable on	
		{view start	"fire1"}
	}	
	{on operatable off		
		{view stop	"fire1"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	{on fire "flamer1"
		{view start	"flame1"}
		{kill_delay "fire1"}
		{delay 0.5 "fire1"
			{view pause	"flame1"}
		}
	}
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz3"	}
		{link_sound "engine"			"vehicle/engine/pz3"		}
		{link_sound "engine_end"		"vehicle/engine/pz3_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy1"	}
		{link_sound "exhaust"			"vehicle/engine/pz3_up"	}
		{link_sound "idle"			"vehicle/engine/stug"	}
	}
	("burn_by_engine" args 0.3)	
}
{"t34_43 tank"
	{on spawn
		{add_view "flamer_fire" "flame1" "foresight4"}
		{add_view "flamer_fire_barrel" "fire1" "foresight4"}
		{view show	"fire1"}

		{view start	"fire1"}
	}
	{on operatable on	
		{view start	"fire1"}
	}	
	{on operatable off		
		{view stop	"fire1"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	{on fire "flamer1"
		{view start	"flame1"}
		{kill_delay "fire1"}
		{delay 0.5 "fire1"
			{view pause	"flame1"}
		}
	}
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/t34"	}
		{link_sound "rotate_turret" 	"vehicle/turret/t34"		}
		{link_sound "engine"			"vehicle/engine/t34"		}
		{link_sound "engine_end"		"vehicle/engine/t34_end"	}
		{link_sound "exhaust"			"vehicle/engine/t34_up"		}
		{link_sound "idle"			"vehicle/engine/t60"	}
	}
	("burn_by_engine" args 0.3)	  
}
{"cromwell_mk_vi tank"
	{on "add_movement_sound" overload
		{link_sound "move"		    	"vehicle/tracks/cromwell"	}
		{link_sound "engine"			"vehicle/engine/cromwell"		}
		{link_sound "engine_end"		"vehicle/engine/cromwell_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/cromwell_up"	}
		{link_sound "idle"			"vehicle/engine/cromwell_idle"	}
	}
	("burn_by_engine" args 0.3)
}
{"cromwell_mk_vii_57 tank"
	{on "add_movement_sound" overload
		{link_sound "move"		    	"vehicle/tracks/cromwell"	}
		{link_sound "engine"			"vehicle/engine/cromwell"		}
		{link_sound "engine_end"		"vehicle/engine/cromwell_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	} 
		{link_sound "exhaust"			"vehicle/engine/cromwell_up"	}
		{link_sound "idle"			"vehicle/engine/cromwell_idle"	}
	}
	("burn_by_engine" args 0.3)
}
{"cromwell_mk_vii_k tank"
	{on "add_movement_sound" overload
		{link_sound "move"		    	"vehicle/tracks/cromwell"	}
		{link_sound "engine"			"vehicle/engine/cromwell"		}
		{link_sound "engine_end"		"vehicle/engine/cromwell_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/cromwell_up"	}
		{link_sound "idle"			"vehicle/engine/cromwell_idle"	}
	}
	("burn_by_engine" args 0.3)
}
{"cromwell_mk_vii_e tank"
	{on "add_movement_sound" overload
		{link_sound "move"		    	"vehicle/tracks/cromwell"	}
		{link_sound "engine"			"vehicle/engine/cromwell"		}
		{link_sound "engine_end"		"vehicle/engine/cromwell_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/cromwell_up"	}
		{link_sound "idle"			"vehicle/engine/cromwell_idle"	}
	}
	("burn_by_engine" args 0.3)
}
{"challenger_a30"
	{on "add_movement_sound" overload
		{link_sound "move"		    	"vehicle/tracks/cromwell"	}
		{link_sound "engine"			"vehicle/engine/cromwell"		}
		{link_sound "engine_end"		"vehicle/engine/cromwell_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/cromwell_up"	}
		{link_sound "idle"			"vehicle/engine/cromwell_idle"	}
	}
	("burn_by_engine" args 0.3)
}
{"charioteer"
	{on "add_movement_sound" overload
		{link_sound "move"		    	"vehicle/tracks/cromwell"	}
		{link_sound "engine"			"vehicle/engine/cromwell"		}
		{link_sound "engine_end"		"vehicle/engine/cromwell_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/cromwell_up"	}
		{link_sound "idle"			"vehicle/engine/cromwell_idle"	}
	}
	("burn_by_engine" args 0.3)
}
{"cromwell_mk_vii tank"
	{on "add_movement_sound" overload
		{link_sound "move"		    	"vehicle/tracks/cromwell"	}
		{link_sound "engine"			"vehicle/engine/cromwell"		}
		{link_sound "engine_end"		"vehicle/engine/cromwell_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/cromwell_up"	}
		{link_sound "idle"			"vehicle/engine/cromwell_idle"	}
	}
	("burn_by_engine" args 0.3)
}
{"brummbar tank"
	("stug_sound")
	("burn_by_engine" args 0.3)
}
{"sturer_emil tank"
	("stug_sound")
	("burn_by_engine" args 0.3)
}
{"jpz4l48 tank"
	("stug_sound")
	("burn_by_engine" args 0.3)
}
{"jpz4l70 tank"
	("stug_sound")
	("burn_by_engine" args 0.3)
}
{"jpz4l70A tank"
	("stug_sound")
	("burn_by_engine" args 0.3)
}
{"bt5 tank"
	("bt7_sound")
	("burn_by_engine" args 0.2)
}
{"bt7 tank"
	("bt7_sound")
	("burn_by_engine" args 0.2)
}
{"bt7e tank"
	("bt7_sound")
	("burn_by_engine" args 0.2)
}
{"t30hmc tank"
	("m3_sound")
	("burn_by_engine" args 0.3)
}
{"m4a3_zippo tank"
	{on spawn
		{add_view "flamer_fire" "flame1" "foresight5"}
		{add_view "flamer_fire_barrel" "fire1" "foresight5"}
		{view show	"fire1"}

		{view start	"fire1"}
	}
	{on operatable on	
		{view start	"fire1"}
	}	
	{on operatable off		
		{view stop	"fire1"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	{on fire "flamer1"
		{view start	"flame1"}
		{kill_delay "fire1"}
		{delay 0.5 "fire1"
			{view pause	"flame1"}
		}
	}
	{on "add_movement_sound" overload
		{link_sound "move"					"vehicle/tracks/m4"			}
		{link_sound "engine"				"vehicle/engine/m4"			}
		{link_sound "engine_end"			"vehicle/engine/m4_end"		}
		{link_sound "exhaust"				"vehicle/engine/m4a2_up"		}
		{link_sound "rotate_turret"     	"vehicle/turret/sherman"   	}
		{link_sound "idle"			        "vehicle/engine/Sherman_Idle"	}		
	}
	("burn_by_engine" args 0.3)	
}


;================	special
(define "snowman"
	{on "add_movement_sound" overload
		{link_sound "move"			    "vehicle/engine/dodge_move_new"	}
		{link_sound "engine"			"vehicle/wheels/valami"	}
		{link_sound "engine_end"		"vehicle/engine/pz1_end"}
		{link_sound "exhaust"			"vehicle/engine/Dodge_end"}
	}
	{on pierce overload
		{if volume "body"
			{if rand 0.125
				{call "stat_break"}
				{call "__explosion"}
			}
		}
	}
	{on "__explosion"
		{spawn "tank_die" "basis"}
		{delete}
	}
	{on "explosion"
		{delete}
	}
	("burn_by_engine" args 0.3)
)

{"evil_snowman_1 tank"
	("snowman")
}
{"evil_snowman_2 tank"
	("snowman")
}
{"evil_snowman_3 tank"
	("snowman")
}
{"evil_snowman_4 tank"
	("snowman")
}
{"m26 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m26"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pershing"		}
		{link_sound "engine"			"vehicle/engine/m26"		}
		{link_sound "engine_end"		"vehicle/engine/m4a2_end"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
		{link_sound "idle"			        "vehicle/engine/Sherman_Idle"	}		
	}
	("burn_by_engine" args 0.3)
}
{"t29 tank"
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"	}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"	}
	}
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m26"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pershing"		}
		{link_sound "engine"			"vehicle/engine/m26"		}
		{link_sound "engine_end"		"vehicle/engine/m4a2_end"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
		{link_sound "idle"			"vehicle/engine/stuart_idle"	}
	}
	{on fire "mgun2"
		{if  name "00"
			{view start "flashbarrel00"}
		else name "01"
			{view start "flashbarrel01"}
		}
	}
	{on "gunner_hatch_open" overload
		{ani_wind "open2" end}
	}
	{on "tear_turret" overload
		{if not "turret_teared"
			{set "turret_teared" 1}
			{components "turret" destroy}
			{add_view "smoke_black_big5" "smoke_turret" "basis"}
			{view start "smoke_turret"}
			{delay 60 15		
				{view stop "smoke_turret"}
			}
			{delay_ex 0
				{tear "piece_medium_steel" bone "part3" id "turret"
					{impulse up 3 5 rnd_dir 3}
				}
				{tear "piece_medium_steel" bone "part4" id "turret"
					{impulse up 3 5 rnd_dir 3}
				}
				{tear "piece_large_steel" bone "turret" id "turret"
					{impulse up 5 2.3 dir 3 1.5 cx 5 2 cy 5 2 rnd_dir 10 no_position}
					{if rand 0.2
						{add_view "smoke_dead_norm" "smoke" "basis"}
					else 
						{add_view "smoke_black" "smoke" "basis"}
					}
					{view start "smoke"}
					{delay_effect 30 5 "pause"}
					{delay 0.1
						{volumes "gun" disable obstacle}
					}
				}
			}
		}
	}
	("burn_by_engine" args 0.3)
}
{"t-34 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m26"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pershing"		}
		{link_sound "engine"			"vehicle/engine/m26"		}
		{link_sound "engine_end"		"vehicle/engine/m4a2_end"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
		{link_sound "idle"			"vehicle/engine/stuart_idle"	}
	}
}	
{"coelian_i tank"
	{on spawn
		{add_view	"flash_cannon_small"	"flashbarrel00"	"shooter00"	}
		{add_view	"flash_cannon_small"	"flashbarrel01"	"shooter01"	}
                {add_view	"flash_gun_big"	"flashbarrel02"	"foresight2"	}
		{add_view "smoke_zenit"			"smoke00"		"shooter00"}
		{add_view "smoke_zenit"			"smoke01"		"shooter01"}
		{add_view "flash_zenit"			"flashbarrel000"	"shooter00"}
		{add_view "flash_zenit"			"flashbarrel001"	"shooter01"}
		{add_view "light_flash_zenit"	"flashbarrel1"	"shooter01"}
                {add_view "light_flash_zenit"	"flashbarrel0"	"shooter00"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun"                       "vehicle/turret/mk7_turret"}
		{link_sound "move"			"vehicle/tracks/jugdpanther"		}
		{link_sound "engine"			"vehicle/engine/jugdpanther"		}
		{link_sound "engine_end"		"vehicle/engine/jugdpanther_end"	}
		{link_sound "rotate_turret" 		"vehicle/turret/medium1"	}
		{link_sound "exhaust"			"vehicle/engine/jugdpanther_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}			
	}
	{on fire "gun" overload
		{if  name "00"
                        {view start "flashbarrel0"}
			{view start "flashbarrel00"}
                        {view start "flashbarrel000"}
                        {ani_play "fire00"}
                        	{delay 0.42
					{view pause "flashbarrel000"}
				}
                        {spawn "tank_canon_fire_verysmall" "shooter00" x}
				{delay 0.12 
					{view start "smoke00"}
					{delay 5
						{view pause "smoke00"}
					}
				}
		else name "01"
                        {view start "flashbarrel1"}
			{view start "flashbarrel01"}
                        {view start "flashbarrel001"}
                        {ani_play "fire01"}
                        	{delay 0.42
					{view pause "flashbarrel001"}
				}
                        {spawn "tank_canon_fire_verysmall" "shooter01" x}
				{delay 0.12 
					{view start "smoke01"}
					{delay 5
						{view pause "smoke01"}
					}
				}
		}
	}
        {on fire "mgun" overload
           {view start "flashbarrel02"}

        } 
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
("burn_by_engine" args 0.3) 
}
{"t1hvy_early tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m26"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pershing"		}
		{link_sound "engine"			"vehicle/engine/m26"		}
		{link_sound "engine_end"		"vehicle/engine/m4a2_end"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
                {link_sound "rotate_gun"                       "vehicle/turret/mk7_turret"}
		{link_sound "idle"			        "vehicle/engine/Sherman_Idle"	}				
	}
	{on spawn                                                                                            
		{add_view	"flash_cannon_medium"		"flashbarrel0001"			"Foresight1"}
		{add_view	"flash_cannon_medium"		"flashbarrel0006"			"Foresight6"}
		{add_view	"flash_cannon_small"		"flashbarrel0002"			"Foresight2"}
		{add_view	"flash_cannon_small"		"flashbarrel0004"			"Foresight4"}
                {add_view	"flash_gun_big"	                "flashbarrel006"	                "foresight3"}
                {add_view	"flash_gun_big"	                "flashbarrel004"	                "shooter00"}
                {add_view	"flash_gun_big"	                "flashbarrel003"	                "shooter01"}
		{add_view	"exhaust_dark_big"		"exhaust"				"fxsmoke1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"fxsmoke2"}
		{add_view	"exhaust_dark_big"		"exhaust"				"fxsmoke3"}
	}
	{on fire "gun"
			{ani_play "fire1"}
                        {view start "flashbarrel0001"}
                        	{delay 0.42
					{view pause "flashbarrel0001"}
				}
        	{spawn "dust_shot_norm" 				"basis"}
                {spawn "tank_canon_fire_medium" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 1.5 bone 		"Foresight1"}
	}
	{on fire "gun2"
			{ani_play "fire2"}
                        {view start "flashbarrel0006"}
                        	{delay 0.42
					{view pause "flashbarrel0006"}
				}
        	{spawn "dust_shot_norm" 				"basis"}
                {spawn "tank_canon_fire_medium" 		"Foresight6" x}
		{blastwave c4 0.2 r0 1 r1 1.5 bone 		"Foresight6"}
	}
	{on fire "gun3"
			{ani_play "fire3"}
                        {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
       	{spawn "dust_shot_small" 				"basis"}
        {spawn "tank_canon_fire_verysmall" 		"Foresight2" x}
	}
	{on fire "gun4"
			{ani_play "fire4"}
                        {view start "flashbarrel0004"}
                        	{delay 0.42
					{view pause "flashbarrel0004"}
				}
        {spawn "tank_canon_fire_verysmall" 		"Foresight4" x}
	}
	{on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on fire "mgun" overload
			{view start "flashbarrel006"}
	}
	{on fire "mgun1" overload
		{if  name "00"
			{view start "flashbarrel004"}
		else name "01"
			{view start "flashbarrel003"}
		}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
                                        {ani_wind "open3" begin}
                                        {ani_wind "open4" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
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
	("burn_by_engine" args 0.3)
}
{"t14 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m26"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pershing"		}
		{link_sound "engine"			"vehicle/engine/m26"		}
		{link_sound "engine_end"		"vehicle/engine/m4a2_end"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
                {link_sound "rotate_gun"                       "vehicle/turret/mk7_turret"}
		{link_sound "idle"			        "vehicle/engine/Sherman_Idle"	}				
	}
}
{"t28prot tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m26"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pershing"		}
		{link_sound "engine"			"vehicle/engine/m26"		}
		{link_sound "engine_end"		"vehicle/engine/m4a2_end"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
                {link_sound "rotate_gun"                       "vehicle/turret/mk7_turret"}
		{link_sound "idle"			        "vehicle/engine/Sherman_Idle"	}				
	}
}
{"t95 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m26"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pershing"		}
		{link_sound "engine"			"vehicle/engine/m26"		}
		{link_sound "engine_end"		"vehicle/engine/m4a2_end"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
                {link_sound "rotate_gun"                       "vehicle/turret/mk7_turret"}
		{link_sound "idle"			        "vehicle/engine/Sherman_Idle"	}				
	}
}	
{"m6_m3 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m26"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pershing"		}
		{link_sound "engine"			"vehicle/engine/m26"		}
		{link_sound "engine_end"		"vehicle/engine/m4a2_end"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
        {link_sound "rotate_gun"        "vehicle/turret/mk7_turret"}
		{link_sound "idle"			    "vehicle/engine/Sherman_Idle"	}				
	}
	{on spawn                                                                                            
		{add_view	"flash_cannon_medium"		"flashbarrel0001"			"Foresight1"}
		{add_view	"flash_cannon_small"		"flashbarrel0002"			"Foresight2"}
		{add_view       "light_flash_zenit"	        "flashbarrel003"	                "foresight3"}
		{add_view       "flash_zenit"			"flashbarrel004"	                "foresight3"}
                {add_view       "smoke_zenit"			"smoke0001"		                "foresight3"}
		{add_view       "light_flash_zenit"	        "flashbarrel005"	                "shooter00"}
		{add_view       "flash_zenit"			"flashbarrel006"	                "shooter00"}
                {add_view       "smoke_zenit"			"smoke0002"		                "shooter00"}
		{add_view       "light_flash_zenit"	        "flashbarrel007"	                "shooter01"}
		{add_view       "flash_zenit"			"flashbarrel008"	                "shooter01"}
                {add_view       "smoke_zenit"			"smoke0003"		                "shooter01"}
		{add_view	"exhaust_dark_big"		"exhaust"				"fxsmoke1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"fxsmoke2"}
		{add_view	"exhaust_dark_big"		"exhaust"				"fxsmoke3"}
		{call "update_hatch_on_spawn_r"}
                {call "vibros_on_spawn"}
	}
	(define "update_vibros"
			{if %wind
				{ani_wind "open2" begin}
			else
				{ani_play "open2" +1.0 resume}
			}
	)
	{on "vibros_on_spawn"
		("update_vibros" wind(true))
	}
	{on "spawn_shell"
		{start_sound "weapon/shot/shell"}
		{spawn "shell_cannon" "fxshell" x  scale 0.014
			{impulse up -1.35 0 dir -4.5 0 cz 0 0 com}
			{add_view "smoke_zenit" "smoke_shell" "fx_shellsmoke"}
			{view start "smoke_shell"}
			{delay_effect 3 1 "stop"}
			{delay 3 0.5
				{hide 3}
			}
                }
	}
	{on fire "gun"
			{ani_play "fire1_90mm"}
                        {view start "flashbarrel0001"}
                        	{delay 0.42
					{view pause "flashbarrel0001"}
				}
                        {ani_play "open2" +1.0}
                        {delay 1
                        {ani_play "open2" -1.0}
                        }
                        {call "spawn_shell"}
      	        {spawn "dust_shot_big" 					"basis"}
      	        {spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on fire "gun2"
			{ani_play "fire2"}
                        {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
                        {ani_play "open2" +1.0}
                        {delay 1 
                        {ani_play "open2" -1.0}
                        }
                        {call "spawn_shell"}
       	                {spawn "dust_shot_small" 				"basis"}
                        {spawn "tank_canon_fire_verysmall" 		"Foresight2" x}
	}
	{on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on fire "mgun" overload
		{view start "flashbarrel004"}
		{delay 0.42
			{view pause "flashbarrel004"}
		}
		{delay 0.12 
			{view start "smoke0001"}
			{delay 5
				{view pause "smoke0001"}
			}
		}
	}
	{on fire "mgun1" overload
		{if  name "00"
	        {view start "flashbarrel006"}
		{delay 0.42
			{view pause "flashbarrel006"}
		}
		{delay 0.12 
			{view start "smoke0002"}
			{delay 5
				{view pause "smoke0002"}
			}
		}
		else name "01"
		{view start "flashbarrel008"}
		{delay 0.42
			{view pause "flashbarrel008"}
		}
		{delay 0.12 
			{view start "smoke0003"}
			{delay 5
				{view pause "smoke0003"}
			}
		}
		}
	}
	{on "gunner_hatch_open"
		{ani_wind "open" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
                                {ani_wind "open5" begin}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
				{ani_play "open5" -1.0 resume}
			}
		else
			{if crew_in_place "gunner21"
				{call "gunner_hatch_open"}
			else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open3" begin}
                                        {ani_wind "open4" begin}
                                        {ani_wind "open5" end}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
					{ani_play "open5" +1.0 resume}
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
	("burn_by_engine" args 0.3)
}
{"m6_m7 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m26"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pershing"		}
		{link_sound "engine"			"vehicle/engine/m26"		}
		{link_sound "engine_end"		"vehicle/engine/m4a2_end"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
                {link_sound "rotate_gun"                       "vehicle/turret/mk7_turret"}
		{link_sound "idle"			        "vehicle/engine/Sherman_Idle"	}				
	}
	{on spawn                                                                                            
		{add_view	"flash_cannon_medium"		"flashbarrel0001"			"Foresight1"}
		{add_view	"flash_cannon_small"		"flashbarrel0002"			"Foresight2"}
		{add_view       "light_flash_zenit"	        "flashbarrel003"	                "foresight3"}
		{add_view       "flash_zenit"			"flashbarrel004"	                "foresight3"}
                {add_view       "smoke_zenit"			"smoke0001"		                "foresight3"}
		{add_view       "light_flash_zenit"	        "flashbarrel005"	                "shooter00"}
		{add_view       "flash_zenit"			"flashbarrel006"	                "shooter00"}
                {add_view       "smoke_zenit"			"smoke0002"		                "shooter00"}
		{add_view       "light_flash_zenit"	        "flashbarrel007"	                "shooter01"}
		{add_view       "flash_zenit"			"flashbarrel008"	                "shooter01"}
                {add_view       "smoke_zenit"			"smoke0003"		                "shooter01"}
		{add_view	"exhaust_dark_big"		"exhaust"				"fxsmoke1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"fxsmoke2"}
		{add_view	"exhaust_dark_big"		"exhaust"				"fxsmoke3"}
		{call "update_hatch_on_spawn_r"}
                {call "vibros_on_spawn"}
	}
	(define "update_vibros"
			{if %wind
				{ani_wind "open2" begin}
			else
				{ani_play "open2" +1.0 resume}
			}
	)
	{on "vibros_on_spawn"
		("update_vibros" wind(true))
	}
	{on "spawn_shell"
		{start_sound "weapon/shot/shell"}
		{spawn "shell_cannon" "fxshell" x  scale 0.014
			{impulse up -1.35 0 dir -4.5 0 cz 0 0 com}
			{add_view "smoke_zenit" "smoke_shell" "fx_shellsmoke"}
			{view start "smoke_shell"}
			{delay_effect 3 1 "stop"}
			{delay 3 0.5
				{hide 3}
			}
                }
	}
	{on fire "gun"
			{ani_play "fire1"}
                        {view start "flashbarrel0001"}
                        	{delay 0.42
					{view pause "flashbarrel0001"}
				}
                        {ani_play "open2" +1.0}
                        {delay 1
                        {ani_play "open2" -1.0}
                        }
                        {call "spawn_shell"}
        	{spawn "dust_shot_norm" 				"basis"}
                {spawn "tank_canon_fire_medium" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 1.5 bone 		"Foresight1"}
	}
	{on fire "gun2"
			{ani_play "fire2"}
                        {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
                        {ani_play "open2" +1.0}
                        {delay 1 
                        {ani_play "open2" -1.0}
                        }
                        {call "spawn_shell"}
       	                {spawn "dust_shot_small" 				"basis"}
                        {spawn "tank_canon_fire_verysmall" 		"Foresight2" x}
	}
	{on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on fire "mgun" overload
		{view start "flashbarrel004"}
		{delay 0.42
			{view pause "flashbarrel004"}
		}
		{delay 0.12 
			{view start "smoke0001"}
			{delay 5
				{view pause "smoke0001"}
			}
		}
	}
	{on fire "mgun1" overload
		{if  name "00"
	        {view start "flashbarrel006"}
		{delay 0.42
			{view pause "flashbarrel006"}
		}
		{delay 0.12 
			{view start "smoke0002"}
			{delay 5
				{view pause "smoke0002"}
			}
		}
		else name "01"
		{view start "flashbarrel008"}
		{delay 0.42
			{view pause "flashbarrel008"}
		}
		{delay 0.12 
			{view start "smoke0003"}
			{delay 5
				{view pause "smoke0003"}
			}
		}
		}
	}
	{on "gunner_hatch_open"
		{ani_wind "open" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
                                {ani_wind "open5" begin}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
				{ani_play "open5" -1.0 resume}
			}
		else
			{if crew_in_place "gunner21"
				{call "gunner_hatch_open"}
			else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open3" begin}
                                        {ani_wind "open4" begin}
                                        {ani_wind "open5" end}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
					{ani_play "open5" +1.0 resume}
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
	("burn_by_engine" args 0.3)
}
{"m6a2e1 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m26"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pershing"		}
		{link_sound "engine"			"vehicle/engine/m26"		}
		{link_sound "engine_end"		"vehicle/engine/m4a2_end"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
        {link_sound "rotate_gun"        "vehicle/turret/mk7_turret"}
		{link_sound "idle"			    "vehicle/engine/Sherman_Idle"	}				
	}
    {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}	
}
{"t-35 tank"		
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/mk7"	}
		{link_sound "engine"			"vehicle/engine/mk7"		}
		{link_sound "engine_end"		"vehicle/engine/mk7_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/mk7_turret"		}
		{link_sound "rotate_turret2" 	"vehicle/turret/light"		}
		{link_sound "rotate_turret3" 	"vehicle/turret/light"		}
		{link_sound "rotate_turret4" 	"vehicle/turret/light1"		}
		{link_sound "rotate_turret5" 	"vehicle/turret/light1"		}
		{link_sound "exhaust"			"vehicle/engine/mk7_up" 	}
	}
	("burn_by_engine" args 0.3)
}
{"kv-1s-152 tank"
	{on spawn
		{add_view	"flash_cannon_big"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"			"smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0001"	                "Foresight2"}
                {add_view	"flash_gun_big"			"flashbarrel0002"			"Foresight3"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/is"}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy"	}
		{link_sound "engine"			"vehicle/engine/kv"			}
		{link_sound "engine_end"		"vehicle/engine/kv_end"		}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"		}
	}
	{on fire "gun"
			{ani_play "fire_s-41"}
	        {spawn "dust_shot_big" 						"basis"}
                {spawn "tank_canon_fire_verylarge" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone 		"Foresight1"}
	}
	{on fire "mgun" overload
				{view start "flashbarrel0001"}
				{delay 0.42
					{view pause "flashbarrel0001"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun2" overload
				{view start "flashbarrel0004"}
				{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
	{on fire "mgun3" overload
				{view start "flashbarrel0002"}
				{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}

	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"kv-1s-122 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"			"smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0001"	                "Foresight2"}
                {add_view	"flash_gun_big"			"flashbarrel0002"			"Foresight3"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/is"}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy"	}
		{link_sound "engine"			"vehicle/engine/kv"			}
		{link_sound "engine_end"		"vehicle/engine/kv_end"		}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"		}
	}
	{on fire "gun"
			{ani_play "fire_s-41"}
	        {spawn "dust_shot_big" 						"basis"}
                {spawn "tank_canon_fire_verylarge" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone 		"Foresight1"}
	}
	{on fire "mgun" overload
				{view start "flashbarrel0001"}
				{delay 0.42
					{view pause "flashbarrel0001"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun2" overload
				{view start "flashbarrel0004"}
				{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
	{on fire "mgun3" overload
				{view start "flashbarrel0002"}
				{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}

	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"kv-122 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"			"smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0001"	                "Foresight2"}
                {add_view	"flash_gun_big"			"flashbarrel0002"			"Foresight3"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/is"}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy"	}
		{link_sound "engine"			"vehicle/engine/kv"			}
		{link_sound "engine_end"		"vehicle/engine/kv_end"		}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"		}
	}
	{on fire "gun"
			{ani_play "fire_d-25t"}
	        {spawn "dust_shot_big" 						"basis"}
                {spawn "tank_canon_fire_verylarge" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone 		"Foresight1"}
	}
	{on fire "mgun" overload
				{view start "flashbarrel0001"}
				{delay 0.42
					{view pause "flashbarrel0001"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun2" overload
				{view start "flashbarrel0004"}
				{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
	{on fire "mgun3" overload
				{view start "flashbarrel0002"}
				{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}

	}
    {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open_kv-85" end}
                                {ani_wind "open2_kv-85" end}
			else
				{ani_play "open_kv-85" +1.0 resume}
				{ani_play "open2_kv-85" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open_kv-85" begin}
                                        {ani_wind "open2_kv-85" begin}
				else
					{ani_play "open_kv-85" -1.0 resume}
					{ani_play "open2_kv-85" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"kv-100 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"			"smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0001"	                "Foresight2"}
                {add_view	"flash_gun_big"			"flashbarrel0002"			"Foresight3"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/is"}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy"	}
		{link_sound "engine"			"vehicle/engine/kv"			}
		{link_sound "engine_end"		"vehicle/engine/kv_end"		}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"		}
	}
	{on fire "gun"
			{ani_play "fire_s-34"}
	        {spawn "dust_shot_big" 						"basis"}
                {spawn "tank_canon_fire_verylarge" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone 		"Foresight1"}
	}
	{on fire "mgun" overload
				{view start "flashbarrel0001"}
				{delay 0.42
					{view pause "flashbarrel0001"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun2" overload
				{view start "flashbarrel0004"}
				{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
	{on fire "mgun3" overload
				{view start "flashbarrel0002"}
				{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}

	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open_kv-85" end}
                                {ani_wind "open2_kv-85" end}
			else
				{ani_play "open_kv-85" +1.0 resume}
				{ani_play "open2_kv-85" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open_kv-85" begin}
                                        {ani_wind "open2_kv-85" begin}
				else
					{ani_play "open_kv-85" -1.0 resume}
					{ani_play "open2_kv-85" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"kv-85 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"			"smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0001"	                "Foresight2"}
                {add_view	"flash_gun_big"			"flashbarrel0002"			"Foresight3"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/is"}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy"	}
		{link_sound "engine"			"vehicle/engine/kv"			}
		{link_sound "engine_end"		"vehicle/engine/kv_end"		}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"		}
	}
	{on fire "gun"
			{ani_play "fire_d-5t"}
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on fire "mgun" overload
				{view start "flashbarrel0001"}
				{delay 0.42
					{view pause "flashbarrel0001"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun2" overload
				{view start "flashbarrel0004"}
				{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
	{on fire "mgun3" overload
				{view start "flashbarrel0002"}
				{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}

	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open_kv-85" end}
                                {ani_wind "open2_kv-85" end}
			else
				{ani_play "open_kv-85" +1.0 resume}
				{ani_play "open2_kv-85" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open_kv-85" begin}
                                        {ani_wind "open2_kv-85" begin}
				else
					{ani_play "open_kv-85" -1.0 resume}
					{ani_play "open2_kv-85" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"kv-85g tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"			"smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0001"	                "Foresight2"}
                {add_view	"flash_gun_big"			"flashbarrel0002"			"Foresight3"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/is"}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy"	}
		{link_sound "engine"			"vehicle/engine/kv"			}
		{link_sound "engine_end"		"vehicle/engine/kv_end"		}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"		}
	}
	{on fire "gun"
			{ani_play "fire_s-31"}
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on fire "mgun" overload
				{view start "flashbarrel0001"}
				{delay 0.42
					{view pause "flashbarrel0001"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun2" overload
				{view start "flashbarrel0004"}
				{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
	{on fire "mgun3" overload
				{view start "flashbarrel0002"}
				{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}

	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"kv-1sm tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"			"smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0001"	                "Foresight2"}
                {add_view	"flash_gun_big"			"flashbarrel0002"			"Foresight3"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/is"}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy"	}
		{link_sound "engine"			"vehicle/engine/kv"			}
		{link_sound "engine_end"		"vehicle/engine/kv_end"		}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"		}
	}
	{on fire "gun"
			{ani_play "fire"}
       	{spawn "dust_shot_norm" 				"basis"}
        {spawn "tank_canon_fire_medium" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 1.5 bone 		"Foresight1"}
	}
	{on fire "mgun" overload
				{view start "flashbarrel0001"}
				{delay 0.42
					{view pause "flashbarrel0001"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun2" overload
				{view start "flashbarrel0004"}
				{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
	{on fire "mgun3" overload
				{view start "flashbarrel0002"}
				{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}

	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"kv-1s tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"			"smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0001"	                "Foresight2"}
                {add_view	"flash_gun_big"			"flashbarrel0002"			"Foresight3"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/is"}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy"	}
		{link_sound "engine"			"vehicle/engine/kv"			}
		{link_sound "engine_end"		"vehicle/engine/kv_end"		}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"		}
	}
	{on fire "gun"
			{ani_play "fire"}
       	{spawn "dust_shot_norm" 				"basis"}
        {spawn "tank_canon_fire_medium" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 1.5 bone 		"Foresight1"}
	}
	{on fire "mgun" overload
				{view start "flashbarrel0001"}
				{delay 0.42
					{view pause "flashbarrel0001"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun2" overload
				{view start "flashbarrel0004"}
				{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
	{on fire "mgun3" overload
				{view start "flashbarrel0002"}
				{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}

	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"e-100b tank"
	{on spawn
		{add_view	"flash_cannon_big"		"flashbarrel0000"			"Foresight1"}
		{add_view	"flash_cannon_small"	        "flashbarrel0001"	                "Foresight3"}
		{add_view       "smoke_zenit"		        "smoke0001"		                "Foresight3"}
		{add_view       "flash_zenit"		        "flashbarrel0002"	                "Foresight3"}
		{add_view       "light_flash_zenit"	        "flashbarrel0003"	                "Foresight3"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sheavy"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}
	}
	{on fire "gun"
			{ani_play "fire1"}
	{spawn "dust_shot_big" 						"basis"}
        {spawn "tank_canon_fire_verylarge" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone 		"Foresight1"}
	}
	{on fire "gun1" overload
                        {view start "flashbarrel0003"}
			{view start "flashbarrel0001"}
                        {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun"
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}
	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on "gunner_hatch_open"
		{ani_wind "open" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
			}
		else
                            {if crew_in_place "gunner21"
				{call "gunner_hatch_open"}
                            else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"e-75 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view	"flash_cannon_small"	        "flashbarrel0001"	                "Foresight2"}
		{add_view       "smoke_zenit"		        "smoke0001"		                "Foresight2"}
		{add_view       "flash_zenit"		        "flashbarrel0002"	                "Foresight2"}
		{add_view       "light_flash_zenit"	        "flashbarrel0003"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sheavy"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}
	}
	{on fire "gun"
			{ani_play "fire1"}
	{spawn "dust_shot_big" 						"basis"}
        {spawn "tank_canon_fire_verylarge" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone 		"Foresight1"}
	}
	{on fire "gun1" overload
                        {view start "flashbarrel0003"}
			{view start "flashbarrel0001"}
                        {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun"
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}
	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on "gunner_hatch_open"
		{ani_wind "open" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
			}
		else
                            {if crew_in_place "gunner21"
				{call "gunner_hatch_open"}
                            else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"e-75_105l68 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view	"flash_cannon_small"	        "flashbarrel0001"	                "Foresight2"}
		{add_view       "smoke_zenit"		        "smoke0001"		                "Foresight2"}
		{add_view       "flash_zenit"		        "flashbarrel0002"	                "Foresight2"}
		{add_view       "light_flash_zenit"	        "flashbarrel0003"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sheavy"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}
	}
	{on fire "gun"
			{ani_play "fire_105l68"}
	{spawn "dust_shot_big" 						"basis"}
        {spawn "tank_canon_fire_verylarge" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone 		"Foresight1"}
	}
	{on fire "gun1" overload
                        {view start "flashbarrel0003"}
			{view start "flashbarrel0001"}
                        {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun"
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}
	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on "gunner_hatch_open"
		{ani_wind "open" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
			}
		else
                            {if crew_in_place "gunner21"
				{call "gunner_hatch_open"}
                            else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"e-75_88l100 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view	"flash_cannon_small"	        "flashbarrel0001"	                "Foresight2"}
		{add_view       "smoke_zenit"		        "smoke0001"		                "Foresight2"}
		{add_view       "flash_zenit"		        "flashbarrel0002"	                "Foresight2"}
		{add_view       "light_flash_zenit"	        "flashbarrel0003"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sheavy"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}
	}
	{on fire "gun"
			{ani_play "fire_88l100"}
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on fire "gun1" overload
                        {view start "flashbarrel0003"}
			{view start "flashbarrel0001"}
                        {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun"
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}
	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on "gunner_hatch_open"
		{ani_wind "open" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
			}
		else
                            {if crew_in_place "gunner21"
				{call "gunner_hatch_open"}
                            else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"e-75_88l71 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"			"smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sheavy"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}
	}
	{on fire "gun"
			{ani_play "fire_88l71"}
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on fire "mgun1" overload
				{view start "flashbarrel0004"}
				{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun"
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}
	}
    {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on "gunner_hatch_open"
		{ani_wind "open" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
			}
		else
                            {if crew_in_place "gunner21"
				{call "gunner_hatch_open"}
                            else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"e-50_75l70_0 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"			"smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sheavy"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}
	}
	{on fire "gun"
			{ani_play "fire_75l70_0"}
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on fire "mgun1" overload
				{view start "flashbarrel0004"}
				{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun"
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}
	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on "gunner_hatch_open"
		{ani_wind "open_75l70_0" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open_75l70_0" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
			else
				{ani_play "open_75l70_0" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
			}
		else
                            {if crew_in_place "gunner21"
				{call "gunner_hatch_open"}
                            else
				{if %wind
					{ani_wind "open_75l70_0" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
				else
					{ani_play "open_75l70_0" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"e-50_75l70 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"			"smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sheavy"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}
	}
	{on fire "gun"
			{ani_play "fire_75l70"}
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on fire "mgun1" overload
				{view start "flashbarrel0004"}
				{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun"
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}
	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on "gunner_hatch_open"
		{ani_wind "open_75l70" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open_75l70" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
			else
				{ani_play "open_75l70" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
			}
		else
                            {if crew_in_place "gunner21"
				{call "gunner_hatch_open"}
                            else
				{if %wind
					{ani_wind "open_75l70" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
				else
					{ani_play "open_75l70" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"e-50_75l100 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"			"smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sheavy"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}
	}
	{on fire "gun"
			{ani_play "fire_75l100"}
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on fire "mgun1" overload
				{view start "flashbarrel0004"}
				{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun"
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}
	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on "gunner_hatch_open"
		{ani_wind "open_75l70" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open_75l70" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
			else
				{ani_play "open_75l70" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
			}
		else
                            {if crew_in_place "gunner21"
				{call "gunner_hatch_open"}
                            else
				{if %wind
					{ani_wind "open_75l70" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
				else
					{ani_play "open_75l70" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"e-50_88l71 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"			"smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sheavy"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}
	}
	{on fire "gun"
			{ani_play "fire_88l71_e-50"}
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on fire "mgun1" overload
				{view start "flashbarrel0004"}
				{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun"
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}
	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on "gunner_hatch_open"
		{ani_wind "open_75l70" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open_75l70" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
			else
				{ani_play "open_75l70" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
			}
		else
                            {if crew_in_place "gunner21"
				{call "gunner_hatch_open"}
                            else
				{if %wind
					{ani_wind "open_75l70" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
				else
					{ani_play "open_75l70" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"type89 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"ro-go tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"o-i tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/t34"	}
		{link_sound "engine_end"		"vehicle/engine/t34_end"}
		{link_sound "exhaust"			"vehicle/engine/t34_up"	}
		{link_sound "idle"			"vehicle/engine/t60"	}		
	}
	("burn_by_engine" args 0.3)
}
{"mi-to tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/t34"	}
		{link_sound "engine_end"		"vehicle/engine/t34_end"}
		{link_sound "exhaust"			"vehicle/engine/t34_up"	}
		{link_sound "idle"			"vehicle/engine/t60"	}		
	}
	("burn_by_engine" args 0.3)
}
{"ho-i tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/t34"	}
		{link_sound "engine_end"		"vehicle/engine/t34_end"}
		{link_sound "exhaust"			"vehicle/engine/t34_up"	}
		{link_sound "idle"			"vehicle/engine/t60"	}		
	}
	("burn_by_engine" args 0.3)
}
{"o-ho tank"
	{on spawn
		{add_view       "light_flash_zenit"	    "flashbarrel005"	            "shooter00"}
		{add_view       "flash_zenit"			"flashbarrel006"	            "shooter00"}
        {add_view       "smoke_zenit"			"smoke0002"		                "shooter00"}
		{add_view       "light_flash_zenit"	    "flashbarrel007"	            "shooter01"}
		{add_view       "flash_zenit"			"flashbarrel008"	            "shooter01"}
        {add_view       "smoke_zenit"			"smoke0003"		                "shooter01"}
	}
	{on fire "mgun1" overload
		{if  name "00"
	        {view start "flashbarrel006"}
		{delay 0.42
			{view pause "flashbarrel006"}
		}
		{delay 0.12 
			{view start "smoke0002"}
			{delay 5
				{view pause "smoke0002"}
			}
		}
		else name "01"
		{view start "flashbarrel008"}
		{delay 0.42
			{view pause "flashbarrel008"}
		}
		{delay 0.12 
			{view start "smoke0003"}
			{delay 5
				{view pause "smoke0003"}
			}
		}
		}
	}		
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/t34"	}
		{link_sound "engine_end"		"vehicle/engine/t34_end"}
		{link_sound "exhaust"			"vehicle/engine/t34_up"	}
		{link_sound "idle"			"vehicle/engine/t60"	}		
	}
	("burn_by_engine" args 0.3)
}
{"o_ni_2 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/t34"	}
		{link_sound "engine_end"		"vehicle/engine/t34_end"}
		{link_sound "exhaust"			"vehicle/engine/t34_up"	}
		{link_sound "idle"			"vehicle/engine/t60"	}		
	}
	("burn_by_engine" args 0.3)
}
{"type5h tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/t34"	}
		{link_sound "engine_end"		"vehicle/engine/t34_end"}
		{link_sound "exhaust"			"vehicle/engine/t34_up"	}
		{link_sound "idle"			"vehicle/engine/t60"	}		
	}
	("burn_by_engine" args 0.3)
}
{"type5hs tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/t34"	}
		{link_sound "engine_end"		"vehicle/engine/t34_end"}
		{link_sound "exhaust"			"vehicle/engine/t34_up"	}
		{link_sound "idle"			"vehicle/engine/t60"	}		
	}
	("burn_by_engine" args 0.3)
}
{"type_4 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/t34"	}
		{link_sound "engine_end"		"vehicle/engine/t34_end"}
		{link_sound "exhaust"			"vehicle/engine/t34_up"	}
		{link_sound "idle"			"vehicle/engine/t60"	}		
	}
	("burn_by_engine" args 0.3)
}
{"chi-ri tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/is"		}
		{link_sound "engine"			"vehicle/engine/jugdpanther"		}
		{link_sound "engine_end"		"vehicle/engine/jugdpanther_end"	}
		{link_sound "rotate_turret" 		"vehicle/turret/heavy"	}
		{link_sound "exhaust"			"vehicle/engine/jugdpanther_up"	}	
		{link_sound "idle"			"vehicle/engine/KT_idle"	}			
	}
	("burn_by_engine" args 0.3)
}
{"chi-ri_75auto tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/is"		}
		{link_sound "engine"			"vehicle/engine/jugdpanther"		}
		{link_sound "engine_end"		"vehicle/engine/jugdpanther_end"	}
		{link_sound "rotate_turret" 		"vehicle/turret/heavy"	}
		{link_sound "exhaust"			"vehicle/engine/jugdpanther_up"	}	
		{link_sound "idle"			"vehicle/engine/KT_idle"	}			
	}
	("burn_by_engine" args 0.3)
}
{"chi-ha120 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"chi-ha47 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"chi-ha57 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"chi-ha57 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"na-to tank"
	("sdkfz_sound")
	("burn_by_engine" args 0.3)
}
{"chi-nu_2 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium1"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/mb_end"}
		{link_sound "exhaust"			"vehicle/engine/mb_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"chi-nu_vet tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium1"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/mb_end"}
		{link_sound "exhaust"			"vehicle/engine/mb_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"chi-to tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium1"	}
		{link_sound "move"				"vehicle/tracks/mk7"	}
		{link_sound "engine"			"vehicle/engine/mk7"	}
		{link_sound "engine_end"		"vehicle/engine/mk7_end"}
		{link_sound "exhaust"			"vehicle/engine/mk7_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"ho-i tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/t34"	}
		{link_sound "engine_end"		"vehicle/engine/t34_end"}
		{link_sound "exhaust"			"vehicle/engine/t34_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"ho-i_kou_td tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/t34"	}
		{link_sound "engine_end"		"vehicle/engine/t34_end"}
		{link_sound "exhaust"			"vehicle/engine/t34_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"ta-se tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"ho-ni1 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"ho-ni1_120 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"ho-ni2 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"ho-ni_3 tank"
	{on "add_movement_sound" overload
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "move"				"vehicle/tracks/chi-ha"	}
		{link_sound "engine"			"vehicle/engine/chi-ha"	}
		{link_sound "engine_end"		"vehicle/engine/hetzer_end"}
		{link_sound "exhaust"			"vehicle/engine/hetzer_up"	}
	}
	("burn_by_engine" args 0.3)
}
{"t30 tank"

	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m26"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pershing"		}
		{link_sound "engine"			"vehicle/engine/m26"		}
		{link_sound "engine_end"		"vehicle/engine/m4a2_end"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
		{link_sound "idle"			"vehicle/engine/stuart_idle"	}		
	}
{on fire "gun"
	{spawn "proj_probe" "Foresight1" x}{spawn "dust_shot_big_3" "basis"}{spawn "bk_smoke_turret" "Foresight1"}{spawn "spbe-d_fire" "Foresight1" x}{spawn "tank_canon_fire_large" "Foresight1" x}{spawn "spbe_d_fire" "Foresight1" x}{view start "flashbarrel_gun"}
	{blastwave c4 2.5 r0 1.7 r1 5 bone "Foresight1"}{view start "smoke_add"}
	{delay 0.16 "shell_off"	{view start "zenite_smoke"}{view pause "smoke_add"}{view pause "flashbarrel_gun"}
	{delay 2 {start_sound "weapon/shot/shell"}
{delay 0.8 {start_sound "detonation/cannons"}}{delay 1.5 {start_sound "detonation/cannons"}}{delay 2 {start_sound "detonation/cannons"}}{delay 3 {start_sound "detonation/cannons"}}{delay 3.5 {start_sound "detonation/cannons"}}
	{spawn "shell_cannons" "fx_invers" x scale 1.5 {impulse up 1.6 0.7 dir 1.2 0.7 cz 0.2 0.1 forward 3 0.5 com}{delay 180 0.5{hide 3}}
	{add_view "smoke_zenit" "smoke_shell" "fx_shellsmoke"}{view start "smoke_shell"}{delay_effect 5 1 "stop"}}}
	{delay 5 {view pause "zenite_smoke"}}}
	{delay 0.12 {view start "smokea00"}{delay 2 1 {view pause "smokea00"}}}
	{delay 0.12 {view start "smokea000"}{delay 6 1 {view pause "smokea000"}}}
}


{on "init_gun" overload
	{add_view "we_smoke"		"smokea00"		"Foresight1"}
	{add_view "smoke_cannon400"		"smokea000"		"Foresight1"}
	{add_view "smoke_zenit"			"smoke00"		"Foresight3"}
	{add_view "smoke_zenit"			"smoke01"		"Foresight4"}
	{add_view "smoke_zenit"			"smoke02"		"Foresight5"}
	{add_view "flash_gun_big"	"smoke00"	"Foresight3"}
	{add_view "flash_gun_big"	"smoke01"	"Foresight4"}
	{add_view "flash_gun_big"	"smoke02"	"Foresight5"}
	{call "update_gun"}
}
	{on operatable on
		{call "update_lights"}
		{ani_play "open0" -1}

	}
	{on operatable off
		{ani_play "open0" 1}
		{call "update_lights"}


	}
	{on fire "mgun"  overload {ani_play "fire_mgun"}
		{view start "smoke00"}
		{delay 3 "smoke00"
			{view pause "smoke00"}
		}
		{delay 0.002
 			{delay 0.06 {start_sound "detonation/cases"}}
				{spawn "shell_cases" "box00" x scale 0.2
				{impulse up 0.01 0.01 dir 0.0 0.0 cz 1.2 1.1 forward 2 0.5 com}{delay 180 0.5{hide 3}}
			}
		}
		{delay 0.12 {view start "smoke00"}{delay 2 1 {view pause "smoke00"}}}
	}
	{on fire "mgun1"  overload
		{view start "smoke01"}
		{delay 3 "smoke01"
			{view pause "smoke01"}
		}
		{delay 0.12 {view start "smoke01"}{delay 2 1 {view pause "smoke01"}}}
	}

	{on fire "mgun2"  overload
		{view start "smoke02"}
		{delay 3 "smoke02"
			{view pause "smoke02"}
		}
		{delay 0.12 {view start "smoke02"}{delay 2 1 {view pause "smoke02"}}}
	}
}
{"kt_15cm tank"
	{on spawn
		{add_view	"flash_cannon_big"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"			"smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel00005"	                "Foresight3"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0006"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sheavy"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}
	}
	{on fire "gun"
			{ani_play "fire_15cm"}
	{spawn "dust_shot_big" 						"basis"}
        {spawn "tank_canon_fire_verylarge" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone 		"Foresight1"}
	}
	{on fire "mgun" overload
				{view start "flashbarrel0004"}
				{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun3"
				{view start "flashbarrel0006"}
				{delay 0.42
					{view pause "flashbarrel0006"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}
	}
	{on fire "mgun2"
				{view start "flashbarrel00005"}
				{delay 0.42
					{view pause "flashbarrel00005"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}
	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on "gunner_hatch_open"
		{ani_wind "open" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
			}
		else
                            {if crew_in_place "gunner21"
				{call "gunner_hatch_open"}
                            else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"kt_105mm_p tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"			"smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0006"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sheavy"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}
	}
	{on fire "gun"
			{ani_play "fire_p_105mm"}
	{spawn "dust_shot_big" 						"basis"}
        {spawn "tank_canon_fire_verylarge" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone 		"Foresight1"}
	}
	{on fire "mgun" overload
				{view start "flashbarrel0004"}
				{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun2"
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}
	}
	{on fire "mgun3"
				{view start "flashbarrel0006"}
				{delay 0.42
					{view pause "flashbarrel0006"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}
	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on "gunner_hatch_open"
		{ani_wind "open" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
			}
		else
                            {if crew_in_place "gunner21"
				{call "gunner_hatch_open"}
                            else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"kt tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"			"smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0006"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sheavy"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}
	}
	{on fire "gun"
			{ani_play "fire"}
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on fire "mgun" overload
				{view start "flashbarrel0004"}
				{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun2"
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}
	}
	{on fire "mgun3"
				{view start "flashbarrel0006"}
				{delay 0.42
					{view pause "flashbarrel0006"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}
	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on "gunner_hatch_open"
		{ani_wind "open" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
			}
		else
                            {if crew_in_place "gunner21"
				{call "gunner_hatch_open"}
                            else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"kt_h tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"			"smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0006"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sheavy"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}
	}
	{on fire "gun"
			{ani_play "fire_kt_h"}
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on fire "mgun" overload
				{view start "flashbarrel0004"}
				{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun2"
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}
	}
	{on fire "mgun3"
				{view start "flashbarrel0006"}
				{delay 0.42
					{view pause "flashbarrel0006"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}
	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on "gunner_hatch_open"
		{ani_wind "open_kt_h" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open_kt_h" end}
                                {ani_wind "open2_kt_h" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
			else
				{ani_play "open_kt_h" +1.0 resume}
				{ani_play "open2_kt_h" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
			}
		else
                            {if crew_in_place "gunner21"
				{call "gunner_hatch_open"}
                            else
				{if %wind
					{ani_wind "open_kt_h" begin}
                                        {ani_wind "open2_kt_h" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
				else
					{ani_play "open_kt_h" -1.0 resume}
					{ani_play "open2_kt_h" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"kt_h_105mm tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"			"smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0006"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sheavy"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}
	}
	{on fire "gun"
			{ani_play "fire_kt_h_105mm"}
	{spawn "dust_shot_big" 						"basis"}
        {spawn "tank_canon_fire_verylarge" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone 		"Foresight1"}
	}
	{on fire "mgun" overload
				{view start "flashbarrel0004"}
				{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun2"
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}
	}
	{on fire "mgun3"
				{view start "flashbarrel0006"}
				{delay 0.42
					{view pause "flashbarrel0006"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}
	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on "gunner_hatch_open"
		{ani_wind "open_kt_h" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open_kt_h" end}
                                {ani_wind "open2_kt_h" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
			else
				{ani_play "open_kt_h" +1.0 resume}
				{ani_play "open2_kt_h" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
			}
		else
                            {if crew_in_place "gunner21"
				{call "gunner_hatch_open"}
                            else
				{if %wind
					{ani_wind "open_kt_h" begin}
                                        {ani_wind "open2_kt_h" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
				else
					{ani_play "open_kt_h" -1.0 resume}
					{ani_play "open2_kt_h" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"tiger_i_h2 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"		        "smoke0001"		                "Foresight2"}
		{add_view       "flash_gun_big"		        "flashbarrel0002"	                "Foresight2"}
		{add_view       "smoke_zenit"		        "smoke0002"		                "Foresight3"}
		{add_view       "flash_gun_big"		        "flashbarrel0003"	                "Foresight3"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/cadenas_tiger"	}
		{link_sound "engine"			"vehicle/engine/tiger_eng"		}
		{link_sound "engine_end"		"vehicle/engine/tiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pz6"	}
		{link_sound "exhaust"			"vehicle/engine/tiger_up"	}
		{link_sound "idle"			"vehicle/engine/tiger_idle3"	}
	}
	{on fire "gun"
			{ani_play "fire_h2"}
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on "stop_on"
		{ani_stop "start_early"}
		{ani_play "stop_early"}
		{view show "stop_signal"}
		{view start "stop_signal"}
		{delay 1
			{view hide "stop_signal"}
		}
	}
	{on move on
		{stop_sound "move_end"}
		{play_sound "move" 1}
		{call "exhaust_on"}
		{ani_stop "stop_early"}
		{ani_play "start_early"}
	}
	{on fire "mgun2" overload
                        {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun1" overload
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
	{on fire "mgun" overload
				{view start "flashbarrel0003"}
				{delay 0.42
					{view pause "flashbarrel0003"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}

	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open_h2" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
			else
				{ani_play "open_h2" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open_h2" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
				else
					{ani_play "open_h2" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"tiger_i_h1 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"		        "smoke0001"		                "Foresight2"}
		{add_view       "flash_gun_big"		        "flashbarrel0002"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/cadenas_tiger"	}
		{link_sound "engine"			"vehicle/engine/tiger_eng"		}
		{link_sound "engine_end"		"vehicle/engine/tiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pz6"	}
		{link_sound "exhaust"			"vehicle/engine/tiger_up"	}
		{link_sound "idle"			"vehicle/engine/tiger_idle3"	}
	}
	{on fire "gun"
			{ani_play "fire_l56_h1"}
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on "stop_on"
		{ani_stop "start_early"}
		{ani_play "stop_early"}
		{view show "stop_signal"}
		{view start "stop_signal"}
		{delay 1
			{view hide "stop_signal"}
		}
	}
	{on move on
		{stop_sound "move_end"}
		{play_sound "move" 1}
		{call "exhaust_on"}
		{ani_stop "stop_early"}
		{ani_play "start_early"}
	}
	{on fire "mgun2" overload
                        {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun1" overload
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open_h1" end}
                                {ani_wind "open2_h1" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
			else
				{ani_play "open_h1" +1.0 resume}
				{ani_play "open2_h1" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open_h1" begin}
                                        {ani_wind "open2_h1" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
				else
					{ani_play "open_h1" -1.0 resume}
					{ani_play "open2_h1" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"tiger_i tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"		        "smoke0001"		                "Foresight2"}
		{add_view       "flash_gun_big"		        "flashbarrel0002"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight3"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/cadenas_tiger"	}
		{link_sound "engine"			"vehicle/engine/tiger_eng"		}
		{link_sound "engine_end"		"vehicle/engine/tiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pz6"	}
		{link_sound "exhaust"			"vehicle/engine/tiger_up"	}
		{link_sound "idle"			"vehicle/engine/tiger_idle3"	}
	}
	{on fire "gun"
			{ani_play "fire_l56"}
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on "stop_on"
		{ani_stop "start_early"}
		{ani_play "stop_early"}
		{view show "stop_signal"}
		{view start "stop_signal"}
		{delay 1
			{view hide "stop_signal"}
		}
	}
	{on move on
		{stop_sound "move_end"}
		{play_sound "move" 1}
		{call "exhaust_on"}
		{ani_stop "stop_early"}
		{ani_play "start_early"}
	}
	{on fire "mgun2" overload
                        {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun" overload
				{view start "flashbarrel0004"}
				{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}

	}
	{on fire "mgun1" overload
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on "gunner_hatch_open"
		{ani_wind "open" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
			}
		else
                            {if crew_in_place "gunner21"
				{call "gunner_hatch_open"}
                            else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"tiger_i_e tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"		        "smoke0001"		                "Foresight2"}
		{add_view       "flash_gun_big"		        "flashbarrel0002"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight3"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/cadenas_tiger"	}
		{link_sound "engine"			"vehicle/engine/tiger_eng"		}
		{link_sound "engine_end"		"vehicle/engine/tiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pz6"	}
		{link_sound "exhaust"			"vehicle/engine/tiger_up"	}
		{link_sound "idle"			"vehicle/engine/tiger_idle3"	}
	}
	{on fire "gun"
			{ani_play "fire_l56"}
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on "stop_on"
		{ani_stop "start_early"}
		{ani_play "stop_early"}
		{view show "stop_signal"}
		{view start "stop_signal"}
		{delay 1
			{view hide "stop_signal"}
		}
	}
	{on move on
		{stop_sound "move_end"}
		{play_sound "move" 1}
		{call "exhaust_on"}
		{ani_stop "stop_early"}
		{ani_play "start_early"}
	}
	{on fire "mgun2" overload
                        {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun" overload
				{view start "flashbarrel0004"}
				{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}

	}
	{on fire "mgun1" overload
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on "gunner_hatch_open"
		{ani_wind "open" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
			}
		else
                            {if crew_in_place "gunner21"
				{call "gunner_hatch_open"}
                            else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"tiger_i_f1 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"		        "smoke0001"		                "Foresight2"}
		{add_view       "flash_gun_big"		        "flashbarrel0002"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/cadenas_tiger"	}
		{link_sound "engine"			"vehicle/engine/tiger_eng"		}
		{link_sound "engine_end"		"vehicle/engine/tiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pz6"	}
		{link_sound "exhaust"			"vehicle/engine/tiger_up"	}
		{link_sound "idle"			"vehicle/engine/tiger_idle3"	}
	}
	{on fire "gun"
			{ani_play "fire_l56"}
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on "stop_on"
		{ani_stop "start_early"}
		{ani_play "stop_early"}
		{view show "stop_signal"}
		{view start "stop_signal"}
		{delay 1
			{view hide "stop_signal"}
		}
	}
	{on move on
		{stop_sound "move_end"}
		{play_sound "move" 1}
		{call "exhaust_on"}
		{ani_stop "stop_early"}
		{ani_play "start_early"}
	}
	{on fire "mgun2" overload
                        {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun" overload
				{view start "flashbarrel0004"}
				{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}

	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on "gunner_hatch_open"
		{ani_wind "open" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
			}
		else
                            {if crew_in_place "gunner21"
				{call "gunner_hatch_open"}
                            else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"tiger_i_f2 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"		        "smoke0001"		                "Foresight2"}
		{add_view       "flash_gun_big"		        "flashbarrel0002"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/cadenas_tiger"	}
		{link_sound "engine"			"vehicle/engine/tiger_eng"		}
		{link_sound "engine_end"		"vehicle/engine/tiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pz6"	}
		{link_sound "exhaust"			"vehicle/engine/tiger_up"	}
		{link_sound "idle"			"vehicle/engine/tiger_idle3"	}
	}
	{on fire "gun"
			{ani_play "fire_early"}
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on "stop_on"
		{ani_stop "start_early"}
		{ani_play "stop_early"}
		{view show "stop_signal"}
		{view start "stop_signal"}
		{delay 1
			{view hide "stop_signal"}
		}
	}
	{on move on
		{stop_sound "move_end"}
		{play_sound "move" 1}
		{call "exhaust_on"}
		{ani_stop "stop_early"}
		{ani_play "start_early"}
	}
	{on fire "mgun2" overload
                        {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun" overload
				{view start "flashbarrel0004"}
				{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}

	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on "gunner_hatch_open"
		{ani_wind "open" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
			}
		else
                            {if crew_in_place "gunner21"
				{call "gunner_hatch_open"}
                            else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"tiger_i_g tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view	"flash_cannon_small"	        "flashbarrel0001"	                "Foresight2"}
		{add_view       "smoke_zenit"		        "smoke0001"		                "Foresight2"}
		{add_view       "flash_zenit"		        "flashbarrel0002"	                "Foresight2"}
		{add_view       "light_flash_zenit"	        "flashbarrel0003"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight3"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/cadenas_tiger"	}
		{link_sound "engine"			"vehicle/engine/tiger_eng"		}
		{link_sound "engine_end"		"vehicle/engine/tiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pz6"	}
		{link_sound "exhaust"			"vehicle/engine/tiger_up"	}
		{link_sound "idle"			"vehicle/engine/tiger_idle3"	}
	}
	{on fire "gun"
			{ani_play "fire"}
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on fire "gun1" overload
                        {view start "flashbarrel0003"}
			{view start "flashbarrel0001"}
                        {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun" overload
				{view start "flashbarrel0004"}
				{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}

	}
	{on fire "mgun1"
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}
	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on "gunner_hatch_open"
		{ani_wind "open" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
			}
		else
                            {if crew_in_place "gunner21"
				{call "gunner_hatch_open"}
                            else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"vk3601h_jagd tank"
	{on spawn
		{add_view	"flash_cannon_big"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"		        "smoke0001"		                "Foresight2"}
		{add_view       "flash_gun_big"		        "flashbarrel0002"	                "Foresight2"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/cadenas_tiger"	}
		{link_sound "engine"			"vehicle/engine/tiger_eng"		}
		{link_sound "engine_end"		"vehicle/engine/tiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pz6"	}
		{link_sound "exhaust"			"vehicle/engine/tiger_up"	}
		{link_sound "idle"			"vehicle/engine/tiger_idle3"	}
	}
	{on fire "gun"
			{ani_play "fire_jagd"}
	{spawn "dust_shot_big" 						"basis"}
        {spawn "tank_canon_fire_verylarge" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone 		"Foresight1"}
	}
	{on fire "mgun" overload
                        {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open_jagd" end}
                                {ani_wind "open2_jagd" end}
                                {ani_wind "open3_jagd" end}
			else
				{ani_play "open_jagd" +1.0 resume}
				{ani_play "open2_jagd" +1.0 resume}
				{ani_play "open3_jagd" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open_jagd" begin}
                                        {ani_wind "open2_jagd" begin}
					{ani_wind "open3_jagd" begin}
				else
					{ani_play "open_jagd" -1.0 resume}
					{ani_play "open2_jagd" -1.0 resume}
					{ani_play "open3_jagd" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"vk3601h2v2 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"		        "smoke0001"		                "Foresight2"}
		{add_view       "flash_gun_big"		        "flashbarrel0002"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/cadenas_tiger"	}
		{link_sound "engine"			"vehicle/engine/tiger_eng"		}
		{link_sound "engine_end"		"vehicle/engine/tiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pz6"	}
		{link_sound "exhaust"			"vehicle/engine/tiger_up"	}
		{link_sound "idle"			"vehicle/engine/tiger_idle3"	}
	}
	{on fire "gun"
			{ani_play "fire"}
       	{spawn "dust_shot_norm" 				"basis"}
        {spawn "tank_canon_fire_medium" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 1.5 bone 		"Foresight1"}
	}
	{on fire "mgun" overload
                        {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun2" overload
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
                                {ani_wind "open5" end}
                                {ani_wind "open6" end}
                                {ani_wind "open7" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
				{ani_play "open5" +1.0 resume}
				{ani_play "open6" +1.0 resume}
				{ani_play "open7" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
					{ani_wind "open5" begin}
					{ani_wind "open6" begin}
					{ani_wind "open7" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
					{ani_play "open5" -1.0 resume}
					{ani_play "open6" -1.0 resume}
					{ani_play "open7" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"vk3601h2v1 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"		        "smoke0001"		                "Foresight2"}
		{add_view       "flash_gun_big"		        "flashbarrel0002"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/cadenas_tiger"	}
		{link_sound "engine"			"vehicle/engine/tiger_eng"		}
		{link_sound "engine_end"		"vehicle/engine/tiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pz6"	}
		{link_sound "exhaust"			"vehicle/engine/tiger_up"	}
		{link_sound "idle"			"vehicle/engine/tiger_idle3"	}
	}
	{on fire "gun"
			{ani_play "fire"}
       	{spawn "dust_shot_norm" 				"basis"}
        {spawn "tank_canon_fire_medium" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 1.5 bone 		"Foresight1"}
	}
	{on fire "mgun" overload
                        {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun2" overload
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
                                {ani_wind "open5" end}
                                {ani_wind "open6" end}
                                {ani_wind "open7" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
				{ani_play "open5" +1.0 resume}
				{ani_play "open6" +1.0 resume}
				{ani_play "open7" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
					{ani_wind "open5" begin}
					{ani_wind "open6" begin}
					{ani_wind "open7" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
					{ani_play "open5" -1.0 resume}
					{ani_play "open6" -1.0 resume}
					{ani_play "open7" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"kv-3 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"			"smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0001"	                "Foresight2"}
                {add_view	"flash_gun_big"			"flashbarrel0002"			"Foresight5"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight5"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/is"}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy"	}
		{link_sound "engine"			"vehicle/engine/kv"			}
		{link_sound "engine_end"		"vehicle/engine/kv_end"		}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"		}
	}
	{on fire "gun"
			{ani_play "fire_zis6_kv-3"}
      	                {spawn "dust_shot_big" 					"basis"}
      	                {spawn "tank_canon_fire_large" 			"Foresight1" x}
		        {blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on fire "mgun" overload
				{view start "flashbarrel0001"}
				{delay 0.42
					{view pause "flashbarrel0001"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun2" overload
				{view start "flashbarrel0002"}
				{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}

	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open_kv-3" end}
                                {ani_wind "open2_kv-1" end}
			else
				{ani_play "open_kv-3" +1.0 resume}
				{ani_play "open2_kv-1" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open_kv-3" begin}
                                        {ani_wind "open2_kv-1" begin}
				else
					{ani_play "open_kv-3" -1.0 resume}
					{ani_play "open2_kv-1" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"kv-220 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"			"smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0001"	                "Foresight2"}
                {add_view	"flash_gun_big"			"flashbarrel0002"			"Foresight3"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/is"}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy"	}
		{link_sound "engine"			"vehicle/engine/kv"			}
		{link_sound "engine_end"		"vehicle/engine/kv_end"		}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"		}
	}
	{on fire "gun"
			{ani_play "fire"}
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on fire "mgun" overload
				{view start "flashbarrel0001"}
				{delay 0.42
					{view pause "flashbarrel0001"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun2" overload
				{view start "flashbarrel0004"}
				{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
	{on fire "mgun3" overload
				{view start "flashbarrel0002"}
				{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}

	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2_kv-1" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2_kv-1" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2_kv-1" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2_kv-1" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"vk3601h1v1 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"		        "smoke0001"		                "Foresight2"}
		{add_view       "flash_gun_big"		        "flashbarrel0002"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/cadenas_tiger"	}
		{link_sound "engine"			"vehicle/engine/tiger_eng"		}
		{link_sound "engine_end"		"vehicle/engine/tiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pz6"	}
		{link_sound "exhaust"			"vehicle/engine/tiger_up"	}
		{link_sound "idle"			"vehicle/engine/tiger_idle3"	}
	}
	{on fire "gun"
			{ani_play "fire"}
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on fire "mgun" overload
                        {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun2" overload
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
                                {ani_wind "open5" end}
                                {ani_wind "open6" end}
                                {ani_wind "open7" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
				{ani_play "open5" +1.0 resume}
				{ani_play "open6" +1.0 resume}
				{ani_play "open7" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
					{ani_wind "open5" begin}
					{ani_wind "open6" begin}
					{ani_wind "open7" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
					{ani_play "open5" -1.0 resume}
					{ani_play "open6" -1.0 resume}
					{ani_play "open7" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"vk3601h1v2 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"		        "smoke0001"		                "Foresight2"}
		{add_view       "flash_gun_big"		        "flashbarrel0002"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/cadenas_tiger"	}
		{link_sound "engine"			"vehicle/engine/tiger_eng"		}
		{link_sound "engine_end"		"vehicle/engine/tiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pz6"	}
		{link_sound "exhaust"			"vehicle/engine/tiger_up"	}
		{link_sound "idle"			"vehicle/engine/tiger_idle3"	}
	}
	{on fire "gun"
			{ani_play "fire"}
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on fire "mgun" overload
                        {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun2" overload
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
                                {ani_wind "open5" end}
                                {ani_wind "open6" end}
                                {ani_wind "open7" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
				{ani_play "open5" +1.0 resume}
				{ani_play "open6" +1.0 resume}
				{ani_play "open7" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
					{ani_wind "open5" begin}
					{ani_wind "open6" begin}
					{ani_wind "open7" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
					{ani_play "open5" -1.0 resume}
					{ani_play "open6" -1.0 resume}
					{ani_play "open7" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"vk3601h1v3 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"		        "smoke0001"		                "Foresight2"}
		{add_view       "flash_gun_big"		        "flashbarrel0002"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/cadenas_tiger"	}
		{link_sound "engine"			"vehicle/engine/tiger_eng"		}
		{link_sound "engine_end"		"vehicle/engine/tiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pz6"	}
		{link_sound "exhaust"			"vehicle/engine/tiger_up"	}
		{link_sound "idle"			"vehicle/engine/tiger_idle3"	}
	}
	{on fire "gun"
			{ani_play "fire"}
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on fire "mgun" overload
                        {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun2" overload
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
                                {ani_wind "open5" end}
                                {ani_wind "open6" end}
                                {ani_wind "open7" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
				{ani_play "open5" +1.0 resume}
				{ani_play "open6" +1.0 resume}
				{ani_play "open7" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
					{ani_wind "open5" begin}
					{ani_wind "open6" begin}
					{ani_wind "open7" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
					{ani_play "open5" -1.0 resume}
					{ani_play "open6" -1.0 resume}
					{ani_play "open7" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"vk3001h2 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"		        "smoke0001"		                "Foresight2"}
		{add_view       "flash_gun_big"		        "flashbarrel0002"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/cadenas_tiger"	}
		{link_sound "engine"			"vehicle/engine/tiger_eng"		}
		{link_sound "engine_end"		"vehicle/engine/tiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pz6"	}
		{link_sound "exhaust"			"vehicle/engine/tiger_up"	}
		{link_sound "idle"			"vehicle/engine/tiger_idle3"	}
	}
	{on fire "gun"
			{ani_play "fire"}
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on fire "mgun" overload
                        {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun2" overload
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
                                {ani_wind "open3" end}
                                {ani_wind "open4" end}
                                {ani_wind "open5" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
				{ani_play "open3" +1.0 resume}
				{ani_play "open4" +1.0 resume}
				{ani_play "open5" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
					{ani_wind "open3" begin}
					{ani_wind "open4" begin}
					{ani_wind "open5" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
					{ani_play "open3" -1.0 resume}
					{ani_play "open4" -1.0 resume}
					{ani_play "open5" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"vk3001h1 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"		        "smoke0001"		                "Foresight2"}
		{add_view       "flash_gun_big"		        "flashbarrel0002"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/cadenas_tiger"	}
		{link_sound "engine"			"vehicle/engine/tiger_eng"		}
		{link_sound "engine_end"		"vehicle/engine/tiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pz6"	}
		{link_sound "exhaust"			"vehicle/engine/tiger_up"	}
		{link_sound "idle"			"vehicle/engine/tiger_idle3"	}
	}
	{on fire "gun"
			{ani_play "fire_75l35"}
       	{spawn "dust_shot_norm" 				"basis"}
        {spawn "tank_canon_fire_medium" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 1.5 bone 		"Foresight1"}
	}
	{on fire "mgun" overload
                        {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun2" overload
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open_h1" end}
                                {ani_wind "open2_h1" end}
                                {ani_wind "open3_h1" end}
                                {ani_wind "open4" end}
                                {ani_wind "open5" end}
			else
				{ani_play "open_h1" +1.0 resume}
				{ani_play "open2_h1" +1.0 resume}
				{ani_play "open3_h1" +1.0 resume}
				{ani_play "open4" +1.0 resume}
				{ani_play "open5" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open_h1" begin}
                                        {ani_wind "open2_h1" begin}
					{ani_wind "open3_h1" begin}
					{ani_wind "open4" begin}
					{ani_wind "open5" begin}
				else
					{ani_play "open_h1" -1.0 resume}
					{ani_play "open2_h1" -1.0 resume}
					{ani_play "open3_h1" -1.0 resume}
					{ani_play "open4" -1.0 resume}
					{ani_play "open5" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"Porsche_Type_130_105l47_late tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"			"smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0006"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock5"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock6"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock7"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock8"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sheavy"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}
	}
	{on fire "gun"
			{ani_play "fire_105l47"}
	{spawn "dust_shot_big" 						"basis"}
        {spawn "tank_canon_fire_verylarge" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone 		"Foresight1"}
	}
	{on fire "mgun2" overload
                        {view start "flashbarrel0004"}
                        	{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun1" overload
				{view start "flashbarrel0006"}
				{delay 0.42
					{view pause "flashbarrel0006"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
	{on fire "mgun3"
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}
	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on "gunner_hatch_open"
		{ani_wind "open_type_130" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open_type_130" end}
                                {ani_wind "open2_type_130" end}
			else
				{ani_play "open_type_130" +1.0 resume}
				{ani_play "open2_type_130" +1.0 resume}
			}
		else
                            {if crew_in_place "gunner3"
				{call "gunner_hatch_open"}
		        else
				{if %wind
					{ani_wind "open_type_130" begin}
                                        {ani_wind "open2_type_130" begin}
				else
					{ani_play "open_type_130" -1.0 resume}
					{ani_play "open2_type_130" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"Porsche_Type_130_105l47 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"			"smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0006"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock5"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock6"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock7"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock8"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sheavy"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}
	}
	{on fire "gun"
			{ani_play "fire_105l47"}
	{spawn "dust_shot_big" 						"basis"}
        {spawn "tank_canon_fire_verylarge" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone 		"Foresight1"}
	}
	{on fire "mgun2" overload
                        {view start "flashbarrel0004"}
                        	{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun1" overload
				{view start "flashbarrel0006"}
				{delay 0.42
					{view pause "flashbarrel0006"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
	{on fire "mgun3"
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}
	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on "gunner_hatch_open"
		{ani_wind "open_type_130" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open_type_130" end}
                                {ani_wind "open2_type_130" end}
			else
				{ani_play "open_type_130" +1.0 resume}
				{ani_play "open2_type_130" +1.0 resume}
			}
		else
                            {if crew_in_place "gunner3"
				{call "gunner_hatch_open"}
		        else
				{if %wind
					{ani_wind "open_type_130" begin}
                                        {ani_wind "open2_type_130" begin}
				else
					{ani_play "open_type_130" -1.0 resume}
					{ani_play "open2_type_130" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"Porsche_Type_130_88l71_late tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"			"smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0006"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock5"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock6"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock7"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock8"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sheavy"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}
	}
	{on fire "gun"
			{ani_play "fire_88l71"}
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on fire "mgun2" overload
                        {view start "flashbarrel0004"}
                        	{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun1" overload
				{view start "flashbarrel0006"}
				{delay 0.42
					{view pause "flashbarrel0006"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
	{on fire "mgun3"
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}
	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on "gunner_hatch_open"
		{ani_wind "open_type_130" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open_type_130" end}
                                {ani_wind "open2_type_130" end}
			else
				{ani_play "open_type_130" +1.0 resume}
				{ani_play "open2_type_130" +1.0 resume}
			}
		else
                            {if crew_in_place "gunner3"
				{call "gunner_hatch_open"}
		        else
				{if %wind
					{ani_wind "open_type_130" begin}
                                        {ani_wind "open2_type_130" begin}
				else
					{ani_play "open_type_130" -1.0 resume}
					{ani_play "open2_type_130" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"Porsche_Type_130_88l71 tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"			"smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0006"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock5"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock6"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock7"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock8"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sheavy"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}
	}
	{on fire "gun"
			{ani_play "fire_88l71"}
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on fire "mgun2" overload
                        {view start "flashbarrel0004"}
                        	{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun1" overload
				{view start "flashbarrel0006"}
				{delay 0.42
					{view pause "flashbarrel0006"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
	{on fire "mgun3"
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}
	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on "gunner_hatch_open"
		{ani_wind "open_type_130" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open_type_130" end}
                                {ani_wind "open2_type_130" end}
			else
				{ani_play "open_type_130" +1.0 resume}
				{ani_play "open2_type_130" +1.0 resume}
			}
		else
                            {if crew_in_place "gunner3"
				{call "gunner_hatch_open"}
		        else
				{if %wind
					{ani_wind "open_type_130" begin}
                                        {ani_wind "open2_type_130" begin}
				else
					{ani_play "open_type_130" -1.0 resume}
					{ani_play "open2_type_130" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"Porsche_Type_130_late tank"
	{on spawn
		{add_view	"flash_cannon_big"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"			"smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0006"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock5"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock6"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock7"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock8"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sheavy"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}
	}
	{on fire "gun"
			{ani_play "fire_15cm"}
	{spawn "dust_shot_big" 						"basis"}
        {spawn "tank_canon_fire_verylarge" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone 		"Foresight1"}
	}
	{on fire "mgun2" overload
                        {view start "flashbarrel0004"}
                        	{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun1" overload
				{view start "flashbarrel0006"}
				{delay 0.42
					{view pause "flashbarrel0006"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
	{on fire "mgun3"
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}
	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on "gunner_hatch_open"
		{ani_wind "open_type_130" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open_type_130" end}
                                {ani_wind "open2_type_130" end}
			else
				{ani_play "open_type_130" +1.0 resume}
				{ani_play "open2_type_130" +1.0 resume}
			}
		else
                            {if crew_in_place "gunner3"
				{call "gunner_hatch_open"}
		        else
				{if %wind
					{ani_wind "open_type_130" begin}
                                        {ani_wind "open2_type_130" begin}
				else
					{ani_play "open_type_130" -1.0 resume}
					{ani_play "open2_type_130" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"Porsche_Type_130 tank"
	{on spawn
		{add_view	"flash_cannon_big"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"			"smoke0001"		                "Foresight2"}
		{add_view	"flash_gun_big"	                "flashbarrel0004"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0002"		                "Foresight3"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight3"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0006"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock5"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock6"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock7"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock8"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sheavy"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}
	}
	{on fire "gun"
			{ani_play "fire_15cm"}
	{spawn "dust_shot_big" 						"basis"}
        {spawn "tank_canon_fire_verylarge" 		"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.5 bone 		"Foresight1"}
	}
	{on fire "mgun2" overload
                        {view start "flashbarrel0004"}
                        	{delay 0.42
					{view pause "flashbarrel0004"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun1" overload
				{view start "flashbarrel0006"}
				{delay 0.42
					{view pause "flashbarrel0006"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
	{on fire "mgun3"
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0002"}
					{delay 5
						{view pause "smoke0002"}
					}
				}
	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	{on "gunner_hatch_open"
		{ani_wind "open_type_130" end}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open_type_130" end}
                                {ani_wind "open2_type_130" end}
			else
				{ani_play "open_type_130" +1.0 resume}
				{ani_play "open2_type_130" +1.0 resume}
			}
		else
                            {if crew_in_place "gunner3"
				{call "gunner_hatch_open"}
		        else
				{if %wind
					{ani_wind "open_type_130" begin}
                                        {ani_wind "open2_type_130" begin}
				else
					{ani_play "open_type_130" -1.0 resume}
					{ani_play "open2_type_130" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"Tiger_P tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"		        "smoke0001"		                "Foresight2"}
		{add_view       "flash_gun_big"		        "flashbarrel0002"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock5"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock6"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock7"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock8"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/ferdi_engine"		}
		{link_sound "engine_end"		"vehicle/engine/ferdi_engine_end"	}
		{link_sound "exhaust"			"vehicle/engine/ferdi_engine_up"	}
		{link_sound "idle"			"vehicle/engine/ferdi_engine"	}
	}
	{on fire "gun"
			{ani_play "fire"}
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on fire "mgun2" overload
                        {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun1" overload
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"vk4501p tank"
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel0000"			"Foresight1"}
		{add_view       "smoke_zenit"		        "smoke0001"		                "Foresight2"}
		{add_view       "flash_gun_big"		        "flashbarrel0002"	                "Foresight2"}
		{add_view       "smoke_zenit"			"smoke0003"		                "Foresight4"}
		{add_view	"flash_gun_big"	                "flashbarrel0005"	                "Foresight4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock1"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock2"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock3"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock4"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock5"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock6"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock7"}
		{add_view	"exhaust_dark_big"		"exhaust"				"FXsmock8"}
	}
	{on "add_movement_sound" overload
                {link_sound "rotate_gun" "vehicle/turret/medium4"}
		{link_sound "move"				"vehicle/tracks/jugdpanther"	}
		{link_sound "engine"			"vehicle/engine/jagdtiger"		}
		{link_sound "engine_end"		"vehicle/engine/jagdtiger_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/sheavy"	}
		{link_sound "exhaust"			"vehicle/engine/pz6_up"	}
		{link_sound "idle"			"vehicle/engine/KT_idle"	}
	}
	{on fire "gun"
			{ani_play "fire"}
      	{spawn "dust_shot_big" 					"basis"}
      	{spawn "tank_canon_fire_large" 			"Foresight1" x}
		{blastwave c4 0.2 r0 1 r1 2.0 bone 		"Foresight1"}
	}
	{on fire "mgun2" overload
                        {view start "flashbarrel0002"}
                        	{delay 0.42
					{view pause "flashbarrel0002"}
				}
				{delay 0.12 
					{view start "smoke0001"}
					{delay 5
						{view pause "smoke0001"}
					}
				}

	}
	{on fire "mgun1" overload
				{view start "flashbarrel0005"}
				{delay 0.42
					{view pause "flashbarrel0005"}
				}
				{delay 0.12 
					{view start "smoke0003"}
					{delay 5
						{view pause "smoke0003"}
					}
				}

	}
        {on ik begin "gun_rot"
		{play_sound "rotate_gun" 1}
	}
	{on ik end "gun_rot"
		{stop_sound "rotate_gun"}
	}
	(define "update_hatch"
		{if not operatable
			{if %wind
				{ani_wind "open" end}
                                {ani_wind "open2" end}
			else
				{ani_play "open" +1.0 resume}
				{ani_play "open2" +1.0 resume}
			}
		else
				{if %wind
					{ani_wind "open" begin}
                                        {ani_wind "open2" begin}
				else
					{ani_play "open" -1.0 resume}
					{ani_play "open2" -1.0 resume}
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
       ("burn_by_engine" args 0.3)
}
{"churchill_i tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/churchill"		}
		{link_sound "engine"			"vehicle/engine/churchill"		}
		{link_sound "engine_end"		"vehicle/engine/churchill_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/churchill_up" 	}
	}
{on fire "gun2"
	{spawn "proj_probe" "Foresight2" x}{spawn "dust_shot_big_3" "basis"}{spawn "tank_canon_fire_3" "Foresight2" x}{view start "flashbarrel_gun"}
	{blastwave c4 2.5 r0 1.7 r1 5 bone "Foresight2"}{view start "smoke_add"}
	{delay 0.16 "shell_off"	{view start "zenite_smoke"}{view pause "smoke_add"}{view pause "flashbarrel_gun"}
	{delay 0.5 {start_sound "weapon/shot/shell"}
{delay 0.8 {start_sound "detonation/cannons"}}{delay 1.5 {start_sound "detonation/cannons"}}{delay 2 {start_sound "detonation/cannons"}}{delay 3 {start_sound "detonation/cannons"}}{delay 3.5 {start_sound "detonation/cannons"}}
	{spawn "shell_cannon" "box00" x scale 1.2 {impulse up 1.6 0.7 dir 1.2 0.7 cz 0.2 0.1 forward 3 0.5 com}{delay 180 0.5{hide 3}}
	{add_view "smoke_zenit" "smoke_shell" "fx_shellsmoke"}{view start "smoke_shell"}{delay_effect 5 1 "stop"}}}
	{delay 5 {view pause "zenite_smoke"}}}
	{delay 0.12 {view start "smoke00"}{delay 2 1 {view pause "smoke00"}}}
	{delay 0.12 {view start "smoke000"}{delay 6 1 {view pause "smoke000"}}}
}
	{on fire "gun"  overload {ani_play "fire1"}
		{view start "smoke01"}
		{delay 3 "smoke01"
			{view pause "smoke01"}
		}{spawn "tank_canon_fire_small" "Foresight1" x}{spawn "dust_shot_big_3" "basis"}
		{delay 0.12 {view start "smoke01"}{delay 5 1 {view pause "smoke01"}}}
	}

{on "init_gun" overload
	{add_view "we_smoke"		"smoke00"		"Foresight2"}
	{add_view "smoke_cannon400"		"smoke000"		"Foresight2"}

	{add_view "we_smoke"		"smoke01"		"Foresight1"}
	{add_view "smoke_cannon400"		"smoke001"		"Foresight1"}

	{add_view "smoke_zenit"			"smoke02"		"Foresight5"}
	{add_view "flash_gun_big"	"smoke02"	"Foresight5"}
	{call "update_gun"}
}


	{on fire "mgun2"  overload
		{view start "smoke02"}
		{delay 3 "smoke02"
			{view pause "smoke02"}
		}
		{delay 0.12 {view start "smoke02"}{delay 2 1 {view pause "smoke02"}}}
	}


	("burn_by_engine" args 0.3)
}
{"churchill_iii tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/churchill"		}
		{link_sound "engine"			"vehicle/engine/churchill"		}
		{link_sound "engine_end"		"vehicle/engine/churchill_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/churchill_turret"	}
		{link_sound "exhaust"			"vehicle/engine/churchill_up" 	}
	}
{on fire "gun2"
	{spawn "proj_probe" "Foresight2" x}{spawn "dust_shot_big_3" "basis"}{spawn "tank_canon_fire_3" "Foresight2" x}{view start "flashbarrel_gun"}
	{blastwave c4 2.5 r0 1.7 r1 5 bone "Foresight2"}{view start "smoke_add"}
	{delay 0.16 "shell_off"	{view start "zenite_smoke"}{view pause "smoke_add"}{view pause "flashbarrel_gun"}
	{delay 0.5 {start_sound "weapon/shot/shell"}
{delay 0.8 {start_sound "detonation/cannons"}}{delay 1.5 {start_sound "detonation/cannons"}}{delay 2 {start_sound "detonation/cannons"}}{delay 3 {start_sound "detonation/cannons"}}{delay 3.5 {start_sound "detonation/cannons"}}
	{spawn "shell_cannon" "box00" x scale 1.2 {impulse up 1.6 0.7 dir 1.2 0.7 cz 0.2 0.1 forward 3 0.5 com}{delay 180 0.5{hide 3}}
	{add_view "smoke_zenit" "smoke_shell" "fx_shellsmoke"}{view start "smoke_shell"}{delay_effect 5 1 "stop"}}}
	{delay 5 {view pause "zenite_smoke"}}}
	{delay 0.12 {view start "smoke00"}{delay 2 1 {view pause "smoke00"}}}
	{delay 0.12 {view start "smoke000"}{delay 6 1 {view pause "smoke000"}}}
}
	{on fire "gun"  overload {ani_play "fire1"}
		{view start "smoke01"}
		{delay 3 "smoke01"
			{view pause "smoke01"}
		}{spawn "tank_canon_fire_small" "Foresight1" x}{spawn "dust_shot_big_3" "basis"}
		{delay 0.12 {view start "smoke01"}{delay 5 1 {view pause "smoke01"}}}
	}

{on "init_gun" overload
	{add_view "we_smoke"		"smoke00"		"Foresight2"}
	{add_view "smoke_cannon400"		"smoke000"		"Foresight2"}

	{add_view "we_smoke"		"smoke01"		"Foresight1"}
	{add_view "smoke_cannon400"		"smoke001"		"Foresight1"}

	{add_view "smoke_zenit"			"smoke02"		"Foresight5"}
	{add_view "flash_gun_big"	"smoke02"	"Foresight5"}
	{call "update_gun"}
}


	{on fire "mgun2"  overload
		{view start "smoke02"}
		{delay 3 "smoke02"
			{view pause "smoke02"}
		}
		{delay 0.12 {view start "smoke02"}{delay 2 1 {view pause "smoke02"}}}
	}


	("burn_by_engine" args 0.3)
}
;-----------------Zeke Wolff Unit Pack
{"m3stuartuk tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/tracks/m3a1_stuart"	}
		{link_sound "engine"			"vehicle/engine/m3a1_stuart"	}
		{link_sound "engine_end"		"vehicle/engine/m3a1_stuart_end"}
		{link_sound "rotate_turret" 		"vehicle/turret/light"		}
		{link_sound "exhaust"			"vehicle/engine/m3a1_stuart_up"	}
		{link_sound "idle"			"vehicle/engine/Crusader_Idle"	}
	}
}
{"m3stuartus tank"
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"	}	
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"	}
		{link_sound "move"			"vehicle/tracks/m3a1_stuart"	}
		{link_sound "engine"			"vehicle/engine/m3a1_stuart"	}
		{link_sound "engine_end"		"vehicle/engine/m3a1_stuart_end"}
		{link_sound "rotate_turret" 		"vehicle/turret/light"		}
		{link_sound "exhaust"			"vehicle/engine/m3a1_stuart_up"	}
		{link_sound "idle"			"vehicle/engine/Crusader_Idle"	}
	}
	{on fire "mgun2" overload
		{if  name "00"
			{view start "flashbarrel00"}
		else name "01"
			{view start "flashbarrel01"}
		}
	}
}
(define "m3a1_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/wheels"}
		;{link_sound "move_end"		"wheels.move_end"		}
		{link_sound "engine"			"vehicle/engine/m3a1"		}
		{link_sound "engine_end"		"vehicle/engine/m3a1_end"	}
		{link_sound "exhaust"			"vehicle/engine/m3a1_up"	}
	}
)
{"m3a1us tank"
	("m3a1_sound")
}
{"m3a1uk tank"
	("m3a1_sound")
}
{"m3a1ru tank"
	("m3a1_sound")
}
(define "mkvib_sound"
	{on "add_movement_sound" overload
		{link_sound "move"		    	"vehicle/tracks/pz2"	}
		{link_sound "engine"			"vehicle/engine/crusader"		}
		{link_sound "engine_end"		"vehicle/engine/crusader_end"	}
		{link_sound "exhaust"			"vehicle/engine/crusader_up"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium3"		}
		{link_sound "idle"			"vehicle/engine/pz2c"	}		
	}
)
{"mkvib tank"
	("mkvib_sound")
}
{"mkvibaa tank"
	("mkvib_sound")
	("burn_by_engine" args 0.3)
}
{"dorchie tank"
	{on "add_movement_sound" overload
		{link_sound "move" 			"wheels.move"			}
		{link_sound "move_end"		"wheels.move_end"			}
		{link_sound "engine"			"vehicle/engine/pz2"			}
		{link_sound "engine_end"		"vehicle/engine/pz2_end"		}
		{link_sound "exhaust"		"vehicle/engine/pz2_up"		}
		{link_sound "idle"			"vehicle/engine/pz2c"	}		
	}
}
{"india tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/wheels/gmc"		}
		{link_sound "move_end"			"vehicle/wheels/gmc_end"	}
		{link_sound "engine"			"vehicle/engine/m3a1" 		}
		{link_sound "engine_end"		"vehicle/engine/m3a1_end" 	}
		{link_sound "exhaust"			"vehicle/engine/m3a1_up"	}
	}
}
{"morriscs9 tank"
	{on "add_movement_sound" overload
		{link_sound "move"			"vehicle/wheels/wheels"		}
		{link_sound "move_end"			"vehicle/wheels/car_end"	}
		{link_sound "engine"			"vehicle/engine/dodge_move" 		}
		{link_sound "engine_end"		"vehicle/engine/dodge_end" 	}
		{link_sound "exhaust"			"vehicle/engine/dodge_up"	}
	}
}
{"sdkfz2511d tank"
	("hanomag_sound")
}
{"pz2fa tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz2"	}
		{link_sound "engine"			"vehicle/engine/pz2"		}
		{link_sound "engine_end"		"vehicle/engine/pz2_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine/pz2_up" 	}
		{link_sound "idle"			"vehicle/engine/pz2c"	}			
	}
}
{"jpz4l48 tank"
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
{"jpz4l70 tank"
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
{"jpz4l70a tank"
	("pz4_sound")
	("burn_by_engine" args 0.3)   
}
{"kugelblitz"
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
{"brummbar_late"
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
{"sig33b tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/stug"	}
		{link_sound "engine"			"vehicle/engine/stugiii"		}
		{link_sound "engine_end"		"vehicle/engine/stug_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy1"	}
		{link_sound "exhaust"			"vehicle/engine/stug_up"	}
		{link_sound "idle"			"vehicle/engine/stugiii"	}	
	}
	("burn_by_engine" args 0.3)
}
{"stug3b tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/stug"	}
		{link_sound "engine"			"vehicle/engine/stugiii"		}
		{link_sound "engine_end"		"vehicle/engine/stug_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy1"	}
		{link_sound "exhaust"			"vehicle/engine/stug_up"	}
		{link_sound "idle"			"vehicle/engine/stugiii"	}		
	}
	("burn_by_engine" args 0.3)
}
{"stug3c tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/stug"	}
		{link_sound "engine"			"vehicle/engine/stugiii"		}
		{link_sound "engine_end"		"vehicle/engine/stug_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy1"	}
		{link_sound "exhaust"			"vehicle/engine/stug_up"	}
		{link_sound "idle"			"vehicle/engine/stugiii"	}	
	}
	("burn_by_engine" args 0.3)
}
{"stug3e tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/stug"	}
		{link_sound "engine"			"vehicle/engine/stugiii"		}
		{link_sound "engine_end"		"vehicle/engine/stug_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy1"	}
		{link_sound "exhaust"			"vehicle/engine/stug_up"	}
		{link_sound "idle"			"vehicle/engine/stugiii"	}	
	}
	("burn_by_engine" args 0.3)
}
{"stug3f tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/stug"	}
		{link_sound "engine"			"vehicle/engine/stugiii"		}
		{link_sound "engine_end"		"vehicle/engine/stug_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy1"	}
		{link_sound "exhaust"			"vehicle/engine/stug_up"	}
		{link_sound "idle"			"vehicle/engine/stugiii"	}		
	}
	("burn_by_engine" args 0.3)
}
{"stug3f1 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/stug"	}
		{link_sound "engine"			"vehicle/engine/stugiii"		}
		{link_sound "engine_end"		"vehicle/engine/stug_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy1"	}
		{link_sound "exhaust"			"vehicle/engine/stug_up"	}
		{link_sound "idle"			"vehicle/engine/stugiii"	}		
	}
	("burn_by_engine" args 0.3)
}
{"stug3f_8 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/stug"	}
		{link_sound "engine"			"vehicle/engine/stugiii"		}
		{link_sound "engine_end"		"vehicle/engine/stug_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy1"	}
		{link_sound "exhaust"			"vehicle/engine/stug_up"	}
		{link_sound "idle"			"vehicle/engine/stugiii"	}		
	}
	("burn_by_engine" args 0.3)
}
{"stug_3g tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/stug"	}
		{link_sound "engine"			"vehicle/engine/stugiii"		}
		{link_sound "engine_end"		"vehicle/engine/stug_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy1"	}
		{link_sound "exhaust"			"vehicle/engine/stug_up"	}
		{link_sound "idle"			"vehicle/engine/stugiii"	}			
	}
	{on "gunner_hatch_open" overload
		{ani_play "close"}
	}
	("burn_by_engine" args 0.3)
}
{"Stuh42f tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/stug"	}
		{link_sound "engine"			"vehicle/engine/stugiii"		}
		{link_sound "engine_end"		"vehicle/engine/stug_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy1"	}
		{link_sound "exhaust"			"vehicle/engine/stug_up"	}
		{link_sound "idle"			"vehicle/engine/stugiii"	}			
	}
	("burn_by_engine" args 0.3)
}
{"stuh42 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/stug"	}
		{link_sound "engine"			"vehicle/engine/stugiii"		}
		{link_sound "engine_end"		"vehicle/engine/stug_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/heavy1"	}
		{link_sound "exhaust"			"vehicle/engine/stug_up"	}
		{link_sound "idle"			"vehicle/engine/stugiii"	}			
	}
	{on "gunner_hatch_open" overload
		{ani_play "open2"}
	}	
	("burn_by_engine" args 0.3)
}
{"comet tank"
	("cometa34_sound")
	("burn_by_engine" args 0.3)
}

{"cruisermk1 tank"
	{on "add_movement_sound" overload
		{link_sound "move"		    	"vehicle/tracks/cromwell"	}
		{link_sound "engine"			"vehicle/engine/pz2"		}
		{link_sound "engine_end"		"vehicle/engine/pz2_end"	}
		{link_sound "exhaust"			"vehicle/engine/pz2_up" 	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium1"		}
		{link_sound "idle"			"vehicle/engine/pz2c"	}		
	}
}
{"cruisermk3 tank"
	{on "add_movement_sound" overload
		{link_sound "move"		    	"vehicle/tracks/cromwell"	}
		{link_sound "engine"			"vehicle/engine/cromwell"		}
		{link_sound "engine_end"		"vehicle/engine/cromwell_end"	}
		{link_sound "exhaust"			"vehicle/engine/cromwell_up"	}
		{link_sound "rotate_turret" 	"vehicle/turret/medium1"		}
		{link_sound "idle"			"vehicle/engine/pz2c"	}		
	}
}
{"MatildaMk1 tank"
	("bishop_sound")
	("burn_by_engine" args 0.3)
}
{"india tank"
	("m8grayhound_sound")
	("burn_by_engine" args 0.3)
}
{"dickermax tank"
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
;-----------------Zeke Wolff Unit Pack
;-----------------Normand Unit Pack
{"np_pz5a tank"
	("pz5g_sound")
	("burn_by_engine" args 0.3)
}
{"np_t50 tank"
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"	}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"	}
	}
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/t-70"		}
		{link_sound "engine"			"vehicle/engine/bt"		}
		{link_sound "engine_end"		"vehicle/engine/bt_end"	}
		{link_sound "exhaust"			"vehicle/engine/bt_up"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
	}
	("burn_by_engine" args 0.2)
	{on fire "mgun" overload
		{if  name "00"
			{view start "flashbarrel00"}
		else name "01"
			{view start "flashbarrel01"}
		}
	}
}
{"np_t34_43 tank"
	("t34_sound")
	("burn_by_engine" args 0.2)
}

{"np_kv85 tank"
	("kv_sound")
	("burn_by_engine" args 0.2)
}
{"np_su152 tank"
	("kv_sound")
	("burn_by_engine" args 0.2)
}
(define "break_glass"
 	{volumes "glass%1" disable bullet contact blast}
 	{spawn "glass_hit2" "glass%1" x}
 	{delay 0.1
 	{bone cut "glass%1"}
	}
)
(define "m3_break_glass"
	{on bullet_hit
 		{if volume "glass_front1"
 			("break_glass" args 3 _front1)
 		else volume "glass_front2"
 			("break_glass" args 3 _front2)
 		}
 	}
)
{"np_m3 tank"
	("m3_sound")
	("m3_break_glass")
	("burn_by_engine" args 0.3)
}
{"np_m5 tank"
	("m3_sound")
	("m3_break_glass")
	("burn_by_engine" args 0.3)
}
{"np_m15a1 tank"
	("m3_sound")
	("m3_break_glass")
	("burn_by_engine" args 0.3)
}
{"np_m17 tank"
	("m3_sound")
	("m3_break_glass")
	("burn_by_engine" args 0.3)
}
{"np_m21 tank"
	("m3_sound")
	("m3_break_glass")
	("burn_by_engine" args 0.3)
}
{"np_t48 tank"
	("m3_sound")
	("burn_by_engine" args 0.3)
}
{"np_t19 tank"
	("m3_sound")
	("burn_by_engine" args 0.3)
}
{"np_m3_us tank"
	("m3_sound")
	("m3_break_glass")
	("burn_by_engine" args 0.3)
}
{"np_m3_en tank"
	("m3_sound")
	("m3_break_glass")
	("burn_by_engine" args 0.3)
}
{"np_m15a1 tank"
	("m3_sound")
	("m3_break_glass")
	("burn_by_engine" args 0.3)
}
{"np_m17_us tank"
	("m3_sound")
	("m3_break_glass")
	("burn_by_engine" args 0.3)
}
{"np_m17_en tank"
	("m3_sound")
	("m3_break_glass")
	("burn_by_engine" args 0.3)
}
{"np_m21_us tank"
	("m3_sound")
	("m3_break_glass")
	("burn_by_engine" args 0.3)
}
{"np_t48_us tank"
	("m3_sound")
	("burn_by_engine" args 0.3)
}
{"np_t48_en tank"
	("m3_sound")
	("burn_by_engine" args 0.3)
}
{"np_t19_us tank"
	("m3_sound")
	("burn_by_engine" args 0.3)
}
{"np_t15 tank"
	("m3_sound")
	("burn_by_engine" args 0.3)
}
{"np_m2_us tank"
	("m3_sound")
	("m3_break_glass")
	("burn_by_engine" args 0.3)
}
{"np_m2_tr tank"
	("m3_sound")
	("m3_break_glass")
	("burn_by_engine" args 0.3)
}
{"np_m2 tank"
	("m3_sound")
	("m3_break_glass")
	("burn_by_engine" args 0.3)
}
{"np_sdkfz234 tank"
	("sdkfz234_sound")
	("burn_by_engine" args 0.3)
}	
{"np_sdkfz234_1 tank"
	("sdkfz234_sound")
	("burn_by_engine" args 0.3)
}
{"sdkfz234_1 tank"
	("sdkfz234_sound")
	("burn_by_engine" args 0.3)
}
{"np_sdkfz234_3 tank"
	("sdkfz234_sound")
	("burn_by_engine" args 0.3)
}
{"sdkfz234_3 tank"
	("sdkfz234_sound")
	("burn_by_engine" args 0.3)
}
{"np_ho_ki tank"
	("hanomag_sound")
	("burn_by_engine" args 0.3)
}
(define "lorraine_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz3"}
		{link_sound "engine"			"vehicle/engine/lorraine"		}
		{link_sound "engine_end"		"vehicle/engine/lorraine_end"	}
		{link_sound "exhaust"			"vehicle/engine/lorraine_up"	}
	}
)
{"np_marder135 tank"
	("lorraine_sound")
	("burn_by_engine" args 0.3)
}
{"marder135 tank"
	("lorraine_sound")
	("burn_by_engine" args 0.3)
}
{"np_sdkfz135_1 tank"
	("lorraine_sound")
	("burn_by_engine" args 0.3)
}
{"np_lorraine tank"
	("lorraine_sound")
	("burn_by_engine" args 0.3)
}
{"np_lorrai_37 tank"
	("lorraine_sound")
	("burn_by_engine" args 0.3)
}
{"np_lorrai_37_47 tank"
	("lorraine_sound")
	("burn_by_engine" args 0.3)
}
{"np_sdkfz234_4 tank"
	("sdkfz234_sound")
	("burn_by_engine" args 0.3)
}
{"sdkfz234_4 tank"
	("sdkfz234_sound")
	("burn_by_engine" args 0.3)
}
{"np_kv1s tank"
	("kv_sound")
	("burn_by_engine" args 0.2)
}
{"np_sdkfz221 tank"
	("sdkfz_sound")
}
;-----------------Normand Unit Pack
;-----------------Skr Unit Pack
(define "bt7_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/bt"		}
		{link_sound "engine"			"vehicle/engine/bt"		}
		{link_sound "engine_end"		"vehicle/engine/bt_end"	}
		{link_sound "exhaust"			"vehicle/engine/bt_up"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "idle"			"vehicle/engine/t-38"	}		
	}
)
(define "t-60_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/t-38"	}
		{link_sound "engine"			"vehicle/engine/t-38"	}
		{link_sound "engine_end"		"vehicle/engine/t-38_end"}
		{link_sound "exhaust"			"vehicle/engine/t-38_up"}
		{link_sound "rotate_turret" 	"vehicle/turret/light2"	}
		{link_sound "idle"			"vehicle/engine/t-38"	}		
	}
)
(define "pz38_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz38t"	}
		{link_sound "engine"			"vehicle/engine/Pz38"		}
		{link_sound "engine_end"		"vehicle/engine/Pz38_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pz38t_turret"	}
		{link_sound "exhaust"			"vehicle/engine/Pz38_up" 	}
		{link_sound "idle"			"vehicle/engine/t-38"	}		
	}
)
{"t-60 tank"
	("t-60_sound")
	("burn_by_engine" args 0.3)
}
{"na_ispyg tank"
	("t-60_sound")
	("burn_by_engine" args 0.3)
}
{"bm_8_24 tank"
	("t-60_sound")
	("burn_by_engine" args 0.3)
}

;--- јддон „Єрные Ѕушлаты ----------------------------------------------------------
{"t-38 tank"
	("t-60_sound")
	("burn_by_engine" args 0.2)
}

{"t-38_ger tank"
	("t-60_sound")
	("burn_by_engine" args 0.2)
}
{"t26_ger tank"
	("t26_sound")
	("burn_by_engine" args 0.3)
}
{"t26_rom tank"
	("t26_sound")
	("burn_by_engine" args 0.3)
}
{"t26_fin tank"
	("t26_sound")
	("burn_by_engine" args 0.3)
}
{"pz2c tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz2"	}
		{link_sound "engine"			"vehicle/engine/pz2"		}
		{link_sound "engine_end"		"vehicle/engine/pz2_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine/pz2_up" 	}
		{link_sound "idle"			"vehicle/engine/pz2c"	}			
	}
	("burn_by_engine" args 0.3)
}
{"pz38t tank"
	("pz38_sound")
	("burn_by_engine" args 0.3)
}
{"marder139 tank"
	("pz38_sound")
	("burn_by_engine" args 0.3)
}
{"pz35t tank"
	("pz38_sound")
	("burn_by_engine" args 0.3)
}
{"r1_prague tank"
	("pz38_sound")
	("burn_by_engine" args 0.3)
}
{"marder_3h tank"
	("pz38_sound")
	("burn_by_engine" args 0.3)
}
{"grille tank"
	("pz38_sound")
	("burn_by_engine" args 0.3)
}
{"ft17m31 tank"
	("pz38_sound")
	("burn_by_engine" args 0.3)
}
{"ft17 tank"
	("pz38_sound")
	("burn_by_engine" args 0.3)
}
{"h39 tank"
	("pz38_sound")
	("burn_by_engine" args 0.3)
}
{"r35 tank"
	("pz38_sound")
	("burn_by_engine" args 0.3)
}
;-----------------------------------------------------------END (јддон „Єрные Ѕушлаты) ---


;--- by volchonok ----------------------------------------------------------
{"bt-7_1935 tank"
	("bt7_sound")
	("burn_by_engine" args 0.3)
}
{"bt-7_1935r tank"
	("bt7_sound")
	("burn_by_engine" args 0.3)
}
{"bt-7a tank"
	("bt7_sound")
	("burn_by_engine" args 0.3)
}
{"bt-7_1937 tank"
	("bt7_sound")
	("burn_by_engine" args 0.3)
}
{"bt-7m tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/bt"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light"		}
		{link_sound "engine"			"vehicle/engine/t34"		}
		{link_sound "engine_end"		"vehicle/engine/t34_end"	}
		{link_sound "exhaust"			"vehicle/engine/m3a1_up"		}
	}
	("burn_by_engine" args 0.3)
}
;-----------------------------------------------------------END (by volchonok) ---

;--- работы Engineer Den ----------------------------------------------------------

{"t-28_33 tank"		
	("mk7_sound")
	("burn_by_engine" args 0.3)
}
{"t-28_36 tank"		
	("mk7_sound")
	("burn_by_engine" args 0.3)
}
{"t-28_l10 tank"		
	("mk7_sound")
	("burn_by_engine" args 0.3)
}
{"t-28_E_10 tank"		
	("mk7_sound")
	("burn_by_engine" args 0.3)
}
{"t-28_E_28 tank"		
	("mk7_sound")
	("burn_by_engine" args 0.3)
}
{"t-28_38_10 tank"		
	("mk7_sound")
	("burn_by_engine" args 0.3)
}
{"t-28_39_10 tank"		
	("mk7_sound")
	("burn_by_engine" args 0.3)
}
{"t-35_33 tank"		
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/mk7"	}
		{link_sound "engine"			"vehicle/engine/mk7"		}
		{link_sound "engine_end"		"vehicle/engine/mk7_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/mk7_turret"		}
		{link_sound "rotate_turret2" 	"vehicle/turret/light"		}
		{link_sound "rotate_turret3" 	"vehicle/turret/light"		}
		{link_sound "rotate_turret4" 	"vehicle/turret/light1"		}
		{link_sound "rotate_turret5" 	"vehicle/turret/light1"		}
		{link_sound "exhaust"			"vehicle/engine/mk7_up" 	}
	}
	("burn_by_engine" args 0.3)
}
{"t-30 tank"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/m26"	}
		{link_sound "rotate_turret" 	"vehicle/turret/pershing"		}
		{link_sound "engine"			"vehicle/engine/m26"		}
		{link_sound "engine_end"		"vehicle/engine/m4a2_end"	}
		{link_sound "exhaust"			"vehicle/engine/m4a2_up"	}
		{link_sound "idle"			"vehicle/engine/stuart_idle"	}
	}
	{on spawn
		{add_view "light_flash_zenit"	"zenite_flash"	"foresight1"}
		{add_view "flash_zenit"			"zenite_flash"	"foresight1"}
		{add_view "smoke_zenit"			"zenite_smoke"	"foresight1"}
		{add_view "circledust_norm2"	"zenite_dust"	"turret"}
	}
	{on fire "gun" overload
		{view start "zenite_flash"}
		{ani_play "fire"}
		{kill_delay "shell_off"}
		{view start "zenite_dust"}
		{delay 0.12 "shell_off"
			{view pause "zenite_dust"}
			{view pause "zenite_dust"}
			{view start "zenite_smoke"}
			{delay 0.3
				{view pause "zenite_flash"}
			}
			{delay 5
				{view pause "zenite_smoke"}
			}
		}
	}
;	("t-60_sound")
	("burn_by_engine" args 0.2)
}
{"t-40 tank"
	("t-60_sound")
	("burn_by_engine" args 0.2)
}
{"t-40S tank"
	("t-60_sound")
	("burn_by_engine" args 0.2)
}
{"bm-8-24(40) tank"
	("t-60_sound")
	("burn_by_engine" args 0.2)
}
{"pz2flamm tank"
	{on spawn
		{add_view "flamer_fire"			"flame" 	"foresight4"}
		{add_view "flamer_fire_barrel" 	"fire"		"foresight4"}
		{add_view "flamer_fire"			"flame2"	"foresight5"}
		{add_view "flamer_fire_barrel"	"fire2"		"foresight5"}
		{view show	"fire"}
		{view show	"fire2"}
	}

	{on operatable on	
		{if work "turret2"
			{view start	"fire"}
		}
		{if work "turret3"
			{view start	"fire2"}
		}
	}	
	{on operatable off		
		{view stop	"fire"}	
		{view stop	"fire2"}
	}
	{on fire "mgun1" overload
		{view start	"flame"}
		{kill_delay "flame"}
		{delay 0.5 "flame"
			{view pause "flame"}
		}
	}
	{on fire "mgun2" overload
		{view start	"flame2"}
		{kill_delay "flame2"}
		{delay 0.5 "flame2"
			{view pause "flame2"}
		}
	}

	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/pz2"	}
		{link_sound "engine"			"vehicle/engine/pz2"		}
		{link_sound "engine_end"		"vehicle/engine/pz2_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine/pz2_up" 	}
		{link_sound "idle"			"vehicle/engine/pz2c"	}			
	}
	{on "_explosion"
		{view stop "fire"}
		{view stop "flame"}
		{view stop "fire2"}
		{view stop "flame2"}
		{fire radius 6 time 0.5 heating 100 effector}
	}
	;----------------------- дл€ дыма - не работает????
	{on "init_gun"
		{add_view "light_flash_zenit"	"flashbarrel"	"foresight20"}
		{add_view "flash_zenit"			"flashbarrel00"	"shooter00"}
		{add_view "flash_zenit"			"flashbarrel01"	"shooter01"}
		{add_view "flash_zenit"			"flashbarrel02"	"shooter02"}
		{add_view "flash_zenit"			"flashbarrel03"	"shooter03"}
		{add_view "flash_zenit"			"flashbarrel04"	"shooter04"}
		{add_view "flash_zenit"			"flashbarrel05"	"shooter05"}
		{add_view "smoke_zenit"			"smoke00"		"shooter00"}
		{add_view "smoke_zenit"			"smoke01"		"shooter01"}
		{add_view "smoke_zenit"			"smoke02"		"shooter02"}
		{add_view "smoke_zenit"			"smoke03"		"shooter03"}
		{add_view "smoke_zenit"			"smoke04"		"shooter04"}
		{add_view "smoke_zenit"			"smoke05"		"shooter05"}
		{call "update_gun"}
	}	
	{on fire "mgun17" overload
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{delay 0.42
					{view pause "flashbarrel%0"}
				}
				{ani_play "fire%0"}
				{delay 0.12 
					{view start "smoke%0"}
					{delay 5
						{view pause "smoke%0"}
					}
				}
		)
		{spawn "startsmoke" inv_normal}
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		else ("fire_barrel" args 03)
		  else ("fire_barrel" args 04)
		 else ("fire_barrel" args 05)	
		}
		{if name "00"
			{call "fire_gun_common"}
		}
	}
	{on "fire_gun_common"
		{view start "flashbarrel"}				
	}
	;------------------------

}
;-----------------------------------------------------------END (работы Engineer Den) ---

;--- работы World in War team ----------------------------------------------------------
{"t-26_1933"
	("t26_sound")
	("burn_by_engine" args 0.3)
}
{"t-26_1931"
	("t26_sound")
	("burn_by_engine" args 0.3)
}
{"t-26_1931a"
	("t26_sound")
	("burn_by_engine" args 0.3)
}
{"ot-26 tank"
	{on spawn
		{add_view "flamer_fire" 		"flame1"	"foresight1"}
		{add_view "flamer_fire_barrel"	"fire1"		"foresight1"}
		{view show	"fire1"}
		{view start	"fire1"}
	}
	{on operatable on	
		{view start	"fire1"}
	}	
	{on operatable off		
		{view stop	"fire1"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	{on fire "flamer1"
		{view start	"flame1"}
		{kill_delay "fire1"}
		{delay 0.5 "fire1"
			{view pause	"flame1"}
		}
	}
	("t26_sound")
	("burn_by_engine" args 0.3)
}
{"ot-130 tank"
	{on spawn
		{add_view "flamer_fire" "flame1" "foresight1"}
		{add_view "flamer_fire_barrel" "fire1" "foresight1"}
		{view show	"fire1"}

		{view start	"fire1"}
	}
	{on operatable on	
		{view start	"fire1"}
	}	
	{on operatable off		
		{view stop	"fire1"}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 5 time 15 heating 10}
	}
	{on fire "flamer1"
		{view start	"flame1"}
		{kill_delay "fire1"}
		{delay 0.5 "fire1"
			{view pause	"flame1"}
		}
	}
	("t26_sound")
	("burn_by_engine" args 0.3)
}
;-----------------------------------------------------------END (работы World in War team) ---

;--- из мода German Soldiers Mod (GSM) Fields of Honor IX ------------------------------------
{"t34_41 tank"
	("t34_sound")
	("burn_by_engine" args 0.2)
}
{"t34_42 tank"
	("t34_sound")
	("burn_by_engine" args 0.2)
}
{"ot34_2 tank"
	("t34_sound")
	("burn_by_engine" args 0.2)

   {on spawn   
      {add_view "flamer_fire" "flame1" "foresight4"}
      
      {add_view "flamer_fire_barrel" "fire1" "foresight4"}
   
      {view show   "fire1"}
      
      {view start   "fire1"}
   }
   {on break_armor
      {if name "pierce"
         {if rand 0.3
            {if volume "body"
               {call "explosion"}
            }
                        }
                else name "blast"
         {if volume "body"
            {call "explosion"}
         }
                }
   }
   {on "_explosion"
      {spawn "fuel_die"}
      {blastwave c4 5 r0 4 r1 15}
      {fire radius 8 time 15 heating 10}
   }
   
   {on fire "mgun1"
      {view start   "flame1"}
      {kill_delay "fire1"}
      {delay 0.5 "fire1"
         {view pause   "flame1"}
      }
   }
}
{"pz3-n tank"
	("pz3_sound")
	("burn_by_engine" args 0.3)
}
{"pz3 tank"
	("pz3_sound")
	("burn_by_engine" args 0.3)
}
;-----------------------------------------------------------END (GSM Fields of Honor IX) ---

{"sdkfz251_16"
	("hanomag_sound")
	("burn_by_engine" args 0.3)
   {on spawn   
      {add_view "flamer_fire" "flame1" "foresight9"}
      {add_view "flamer_fire" "flame2" "foresight10"}
      
      {add_view "flamer_fire_barrel" "fire1" "foresight9"}
      {add_view "flamer_fire_barrel" "fire2" "foresight10"}
   
      {view show   "fire1"}
      {view show   "fire2"}
      
      {view start   "fire1"}
      {view start   "fire2"}
   }
   {on break_armor
      {if name "pierce"
         {if rand 0.3
            {if volume "body"
               {call "explosion"}
            }
                        }
                else name "blast"
         {if volume "body"
            {call "explosion"}
         }
                }
   }
   {on "_explosion"
      {spawn "fuel_die"}
      {blastwave c4 5 r0 4 r1 15}
      {fire radius 8 time 15 heating 10}
   }
   
   {on fire "flamer1"
      {view start   "flame1"}
      {kill_delay "fire1"}
      {delay 0.5 "fire1"
         {view pause   "flame1"}
      }
   }
   {on fire "flamer2"
      {view start   "flame2"}
      {kill_delay "fire2"}
      {delay 0.5 "fire2"
         {view pause   "flame2"}
      }
   }
}

;--- из мода Chronicles of WW2 1.1 BETA ------------------------------------
{"pziv_h tank"
	("pz4_sound")
	("burn_by_engine" args 0.3)
}
;----------------------------------------END (Chronicles of WW2 1.1 BETA) ---
;-----------------Skr Inf Wpn Unit Pack
{"carrier_mk2 tank"
	("mk7_sound")
	("burn_by_engine" args 0.3)
}
{"m4a1_mmc tank"
	("m3_sound")
	("burn_by_engine" args 0.3)
}
{"m21_mmc tank"
	("m3_sound")
	("burn_by_engine" args 0.3)
}
;-----------------Skr Inf Wpn Unit Pack
;-----------------Skr Unit Pack
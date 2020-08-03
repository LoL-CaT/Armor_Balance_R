{"car"
	{on spawn
		{link_sound "flame" "fire/big"}

		{if not rain
			{add_view	"dustrun_small"			"on_grass"			"FXtraceR1"}
			{add_view	"dustrun_small"			"on_grass"			"FXtraceL1"}
			{add_view	"dustrun_sand_small"	"on_sand"			"FXtraceR1"}
			{add_view	"dustrun_sand_small"	"on_sand"			"FXtraceL1"}
			{add_view	"dustrun_snow_small"	"on_snow"			"FXtraceR1"}
			{add_view	"dustrun_snow_small"	"on_snow"			"FXtraceL1"}
			{add_view	"dustrun_small"			"on_country_road"	"FXtraceR1"}
			{add_view	"dustrun_small"			"on_country_road"	"FXtraceL1"}
			{add_view	"dustrun_small"			"on_ground"			"FXtraceR1"}
			{add_view	"dustrun_small"			"on_ground"			"FXtraceL1"}
		else
			{add_view	"engine_steam"			"engine_steam"		"FXfire1"}
		}
		{add_view	"drops_water"			"on_water"			"FXtraceR1"}
		{add_view	"drops_water"			"on_water"			"FXtraceL1"}
;		{add_view	"drops_water"			"on_mud"			"FXtraceR1"}
;		{add_view	"drops_water"			"on_mud"			"FXtraceL1"}
		{add_view	"drops_water_moto"		"on_puddle"			"FXtraceR1"}
		{add_view	"drops_water_moto"		"on_puddle"			"FXtraceL1"}

		{add_view	"smoke_black"			"smoke1"			"FXfire1"}
		{add_view	"smoke_black"			"smoke2"			"engine"}
		{add_view	"steam"					"steam"				"FXsteam"}
		{add_view	"exhaust_dark_small"	"exhaust"			"FXsmoke1"}
		{add_view	"exhaust_dark_small"	"exhaust"			"FXsmoke2"}
	}

	{on "add_movement_sound"
		{link_sound "move"			"vehicle/wheels/car"}
		{link_sound "move_end"		"vehicle/wheels/car_end"}
		{link_sound "engine"		"vehicle/engine/car"}
		{link_sound "engine_end"	"vehicle/engine/car_end"}
		{link_sound "exhaust"		"vehicle/engine/car_up"}
		{link_sound "idle"		"vehicle/engine/kubel_idle"}
	}
	{on pierce
		{if volume "body"
			{if rand 0.99
				{components "body" break}
;				{call "_burn"}
            else volume "body"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}
            else volume "body1"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}						
			else volume "inventory"
				{components "body" break}
			else volume "engine"
				{if min_energy 1.6
					{call "blast_body"} 
				else
					{if rand 0.05 
					{call "burn"}
					}
				}
			else volume "cabin"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "bodyback"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "bodyback1"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}						
			else volume "bodyback2"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "bodyback3"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "bodyback4"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "fuel"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}						
			else volume "glass"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "gun_rot"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "gun"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "inventory"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "sticky"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "turret"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "turret1"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "turret2"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "turret3"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}	
			else volume "fenderl"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "fenderf"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "detail1"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}
			else volume "detailf"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}											
			else volume "shield"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}
			else volume "motor"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}
			else stuff "shell"
					{call "blast_body"}
				{if rand 0.99
					{call "blast_body"}
			else stuff "heat"
				{call "blast_body"}
				}
			}
		}
	}
	
{on blast
		{if volume "body"
			{if rand 0.99
				{components "body" break}
;				{call "_burn"}
            else volume "body"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}
            else volume "body1"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}						
			else volume "inventory"
				{components "body" break}
			else volume "engine"
				{if min_energy 1.6
					{call "blast_body"} 
				else
					{if rand 0.05 
					{call "burn"}
					}
				}
			else volume "cabin"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "bodyback"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "bodyback1"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}						
			else volume "bodyback2"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "bodyback3"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "bodyback4"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "fuel"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}						
			else volume "glass"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "gun_rot"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "gun"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "inventory"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "sticky"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "turret"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "turret1"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "turret2"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "turret3"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}	
			else volume "fenderl"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "fenderf"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "detail1"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}
			else volume "detailf"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}											
			else volume "shield"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}
			else volume "motor"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}
			else stuff "shell"
					{call "blast_body"}
				{if rand 0.99
					{call "blast_body"}
			else stuff "heat"
				{call "blast_body"}
				}
			}
		}
	}	
	
	{on break_armor
		{if name "pierce"
			{if volume "fuel"
				{call "pierce_fuel"}
			}
            else volume "body1"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}						
			else volume "inventory"
				{components "body" break}
			else volume "engine"
				{if min_energy 1.6
					{call "blast_body"} 
				else
					{if rand 0.05 
					{call "burn"}
					}
				}
			else volume "cabin"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "bodyback"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "bodyback1"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}						
			else volume "bodyback2"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "bodyback3"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "bodyback4"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "fuel"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}						
			else volume "glass"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "gun_rot"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "gun"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "inventory"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "sticky"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "turret"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "turret1"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "turret2"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "turret3"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}	
			else volume "fenderl"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "fenderf"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "detail1"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}
			else volume "detailf"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}											
			else volume "shield"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}
			else volume "motor"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}			
		else name "blast"        ;---------------           
			{if volume "body"
				{if min_energy 1.6
					{call "blast_body"}
					}	
			else volume "body1"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}						
			else volume "inventory"
				{components "body" break}
			else volume "engine"
				{if min_energy 1.6
					{call "blast_body"} 
				else
					{if rand 0.05 
					{call "burn"}
					}
				}
			else volume "cabin"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "bodyback"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "bodyback1"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}						
			else volume "bodyback2"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "bodyback3"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "bodyback4"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "fuel"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}						
			else volume "glass"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "gun_rot"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "gun"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "inventory"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "sticky"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "turret"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "turret1"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "turret2"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "turret3"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}	
			else volume "fenderl"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "fenderf"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "detail1"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}
			else volume "detailf"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}											
			else volume "shield"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}
			else volume "motor"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}						
			}			
		}
	}
	{on break_armor_again
		{if name "blast"
			{if volume "body"
;					{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}
			else volume "inventory"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}
			else volume "engine"
;					{components "engine" break}
				{if min_energy 1.6
					{call "blast_body"}
					}
			else volume "cabin"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}
			else volume "bodyback"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}
			else stuff "shell"
				{if rand 0.99
					{call "blast_body"}
				}
			}
		}
	}
	{on blast_hit
		{if stuff "shell"
			{if volume "cabin"
				{if rand 0.99	 	
					{call "blast_body"}
				else
					{call "blast_body"}
				}
			 else volume "body"	
			 	{if rand 0.99	 	
					{call "blast_body"}
				else
					{call "blast_body"}
				}
			 else volume "engine"
			 	{if rand 0.99
					{call "blast_body"}
				else
					{call "blast_body"}
				}
			else volume "body1"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}						
			else volume "inventory"
				{components "body" break}
			else volume "engine"
				{if min_energy 1.6
					{call "blast_body"} 
				else
					{if rand 0.05 
					{call "burn"}
					}
				}
			else volume "cabin"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "bodyback"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "bodyback1"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}						
			else volume "bodyback2"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "bodyback3"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "bodyback4"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "fuel"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}						
			else volume "glass"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "gun_rot"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "gun"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "inventory"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "sticky"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "turret"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "turret1"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "turret2"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "turret3"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}	
			else volume "fenderl"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "fenderf"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "detail1"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}
			else volume "detailf"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}											
			else volume "shield"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}
			else volume "motor"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}				
			}
		}
		{if volume "glass"
		 	{call "break_glass"}
		 else volume "cabin"
;		 	{call "break_glass"}
				{if min_energy 1.6
					{call "blast_body"}
					}
		}
	}
	{on bullet_hit
		{if stuff "rocketlauncher"
			{if volume "cabin"
				{if rand 0.99	 				
					{components "body" break}
				}
			 else volume "body"	
				{if rand 0.99	 				
					{components "body" break}
				}
			 else volume "engine"
			 	{if rand 0.99
					{components "engine" break}
				}
			}
		}
		{if volume "glass"
		 	{call "break_glass"}
		 else volume "cabin"
		 	{call "break_glass"}
		}
	}
	{on "blast_body"
		{if min_energy 2.5
			{impulse up 1.5 0.5 dir 1.5 0.5}
		 else min_energy 1.7
			{impulse up 0.8 0.3 dir 0.8 0.3}
		}
		{call "explosion"}
	}
	{on "pierce_fuel"
		{if rand 0.1
			{volumes "fuel" disable bullet contact blast}
			{spawn "tank_die_particle"}
			{call "burn"}
			else stuff "shell"
			     {if rand 0.99
			     {volumes "fuel" disable bullet contact blast}
			     {spawn "tank_die_particle"}
			     {call "burn"}
		}
	}
	}
	{on "break_glass"
		{volumes "glass" disable bullet contact}
	 	{spawn "glass_hit2" "glass" x}
	 	{delay 0.1
;	 		{con "cut glass"}
		 	{bone cut "glass"}
	 	}
	}
	{on contact
		{if not impregnable
			{if effector_velocity 5
				{if effector "tank"
					{call "crush"}
				else effector "railway"
					{call "crush"}
				}
			else effector_velocity 3
				{if effector "big part"
					{component break}
				}
			}
		}
	}
	{on break
		{if component "cabin"
			{spawn "car_die_particle"}
			{volumes "cabin" disable bullet}
			{volumes "glass" disable bullet contact}
			{crew_enable group "crew" 0}
			{view start "smoke3"}
    		{delay 10 {view stop "smoke3"}}
    	else component "body"
			{spawn "car_die_particle"}
		else component "engine"
                        {spawn "car_die_particle"}
			{view start "smoke2"}
			{delay 40 {view stop "smoke2"}}
			{view start "steam"}
			{delay 2  {view stop "steam"}}
		}
	}
	{on repair
		{if component "cabin"
			{crew_enable group "crew" 1}
			{view stop "smoke2"}
		}
	}

	{on "burn"
		{if not burned
			{call "_burn"}
		}
	}
	{on "check_burn_emit"
		{call "burn_emit"}
	}
	{on "_explosion"
		{add_view "smoke_dead_norm" "deathfx" "fxfire1"}
		{if not "crush"
			{spawn "tank_die" "Basis"}
			{spawn "tank_die_particle"}
			{impulse up 2.5 1.5 dir 2 1}
		}
	}
	{on "spawn_shellhole"
;		{spawn "crater_big" "Basis" no_normal terrain_texmod}
		{spawn "shellhole_dead_car2" "Basis"}
	}
	{on "tear"
		{spawn	"spheredust_small"}
		{component destroy}
		{if volume "bodyback"
			{volume disable visible bullet contact}
		}
		{tear "piece_medium_steel" bone from_volume
			{impulse up 2 1 dir 2 1}
;			{burn first_volume fx "smoke_black" time 10 5}
			{add_view "smoke_black" "smoke" "basis"}
			{view start "smoke"}
			{delay_effect 10 5 "pause"}
		}
	}
	{on "slice_load"
		{if name "car_part"
			{with_effector
				{add_view "smoke_black" "smoke" "basis"}
			}
		}
	}
	{on "cut_parts"
		{add_view "smoke_dead_norm" "deathfx" "fxfire1"}
		{view start "deathfx"}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 4 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 6 no_position}
;				{burn first_volume fx "smoke_dead_wheel" time 20 5}
;				{add_view "smoke_dead_wheel" "smoke" "basis"}
;				{view start "smoke"}
				{delay_effect 20 5 "stop"}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "part5")
		("cut_part" args "part6")
		;cut teared bones after SetSkeleton
		{if "cabine_teared"
			{bone cut "cabin"}
		}
		{if "engine_teared"
			{bone cut "engine"}
		}
		{delay 14 5 {view stop "deathfx"}}
	}
	{on "crush"
    	{component destroy}
    	{if volume "body"
    		{set "crush" 1}
    		{call "explosion"}
    	}
	}
}

{"wheeled vehicle"
	{on blast
		{if volume "wheel"
			{if stuff "mine"
				{if min_energy 1
					{call "tear_wheel"}
				}
			else min_energy 4.1
				{call "tear_wheel"}
			else min_energy 1.6
				{call "blast_body"}				
			else min_energy 0.8
				{component break}
            else volume "body"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}
            else volume "body1"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}						
			else volume "inventory"
				{components "body" break}
			else volume "engine"
				{if min_energy 1.6
					{call "blast_body"} 
				else
					{if rand 0.05 
					{call "burn"}
					}
				}
			else volume "cabin"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "bodyback"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "bodyback1"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}						
			else volume "bodyback2"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "bodyback3"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "bodyback4"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "fuel"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}						
			else volume "glass"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "gun_rot"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "gun"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "inventory"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "sticky"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "turret"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "turret1"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "turret2"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "turret3"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}	
			else volume "fenderl"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "fenderf"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}					
			else volume "detail1"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}
			else volume "detailf"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}											
			else volume "shield"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}
			else volume "motor"
;				{components "body" break}
				{if min_energy 1.6
					{call "blast_body"}
					}
			else stuff "shell"
					{call "blast_body"}
				{if rand 0.99
					{call "blast_body"}
			else stuff "heat"
				{call "blast_body"}
				}			
			}			
		}
	}
	{on break_armor
;		{con "break_armor"}
		{if component "wheel"
			{if name "pierce"
				{component break}
			}
		}
	}
	{on "dont_move"
		{set "wheel_teared" 1}
		{call "check_work_mover"}
		{crew_enable place "driver" 0}
	}
	{on "tear_wheel"
		{set "wheel_teared" 1}
		{spawn	"spheredust_small"}
		{component destroy}
;		{con "effect tear wheel"}
		{tear "piece_medium_steel" bone from_volume id "wheel"
			{volumes disable bullet contact blast}	;prevent destroing at spawn moment
			{impulse up 6 4 dir 7 3}
;			{burn first_volume fx "smoke_dead_wheel" time 10 5}
			{add_view "smoke_dead_wheel" "smoke" "basis"}
			{fire radius 0.5 time 12 follow}
			{view start "smoke"}
			{delay_effect 10 5 "pause"}
		}
		{impulse up 0.3}
	}
	{on break
		{if component "wheel"
			{if not linked
		 		{if not velocity 0.5
		 			{impulse up 0.05}
		 		}
			}
		}
	}
	{on "check_work_mover" overload
		{if "wheel_teared"
			{chassis_work 0}
		else
			{if not work "mover"
				{chassis_work 0}
			else not work "track"
				{chassis_work 0}
			else work "wheel" 1
				{chassis_work 1}
				{if broken "wheel" 3
					{chassis_work 0}
				else broken "wheel" 2
					{movement_limit normal}
				else broken "wheel" 1
					{movement_limit normal}					
				else
					{movement_limit fast}
				}
			else
				;{chassis_work 0}
				{movement_limit slow}
			}
		}
	}
	{on "_explosion"
		(define "rand_tear_wheel"
			{if rand 0.8
;				{con "rnd tear wheel"}
				{components %0 destroy}
				{tear "piece_medium_steel" bone %0 id "wheel"
					{volumes disable bullet contact blast}	;prevent destroing at spawn moment
					{impulse up 7 4 dir 7 4}
;					{burn first_volume fx "smoke_dead_wheel" time 10 5}
					{add_view "smoke_dead_wheel" "smoke" "basis"}
					{view start "smoke"}
					{delay_effect 10 5 "pause"}
				}
			}
		)
;		("rand_tear_wheel" args "wheelleft1")
;		("rand_tear_wheel" args "wheelleft2")
;		("rand_tear_wheel" args "wheelright1")
;		("rand_tear_wheel" args "wheelright2")
	}
}

{"truck"
	{on blast overload	
		{if volume "body"
			{if min_energy 1
					{components "body" break}
				{con "truck 3"}
			else min_energy 1.6
				{if rand 0.99
				{call "blast_body"}
				{con "truck 1.1"}
				}
			else stuff "grenade"
				{if rand 0.05
					{call "blast_body"}
					{con "truck 0.5"}
				}
			}
		}
	}
}

{"katusha car"
	{on fire "gun"
		{spawn "startsmoke_big"}
		{spawn "startdust_big" "FXdust"}
	}
	{on "__explosion"
		{set "big_explosion" 0}
		{if explosive_amount 50
			{blastwave c4 20 r0 10 r1 25}
			{spawn "train_die" "basis"}
			{set "big_explosion" 1}
			{con "big explosive"}
		}
	}
	{on "spawn_shellhole"
		{if "big_explosion"                                        
			{spawn "crater_extra_big" "basis" terrain_texmod}
                        {spawn "shellhole_big_dead" "basis"}
		}
	}
	{on blast
		{if volume "body"
			{if min_energy 1
				{call "blast_body"}
			else min_energy 0.5
				{if rand 0.7
					{call "blast_body"}
				}			
			else stuff "grenade"
				{if rand 0.5
					{call "blast_body"}
				}
			}	
		}
	}
}

{"fuel_tank"
	{on blast_hit
		{if min_energy 1
			{call "explosion"}
		else min_energy 0.1
			{if rand 0.6
				{call "explosion"}
			}
		}
	}
	{on break_armor
		{call "pierce_bodyback"}
	}
	{on break_armor_again
		{call "pierce_bodyback"}
	}
	{on "pierce_bodyback"
		{if name "pierce"
			{if not able "exploded"
				{if volume "bodyback"
					{if stuff "bullet"
						{burn fx "drops_water_small_short" fake}
					}
				}
			}
		}
	}
	{on "_explosion"
		{spawn "fuel_die"}
		{blastwave c4 5 r0 4 r1 15}
		{fire radius 8 time 15 heating 10}
	}
}

{"dead_vehicle"
	{on blast
		{if volume "body"
			{if min_energy 1.6
				{call "explosion"}
			}
		}
	}
	{on "explosion"
		{if not "exploded"
			{set "exploded" 1}
			{call "_explosion"}
		}
	}
	{on "_explosion"
		{start_sound "crush/big/vehicle"}
		{delay_ex 0
			{set_skeleton "_x" sync}
			{ani_play "death"}
			{call "cut_parts"}
		}
	}
	{on "cut_parts"
		{add_view "smoke_dead_wheel" "smoke" "basis"}
		{view start "smoke"}
		{delay 20 10
			{view stop "smoke"}
		}
		(define "cut_part"
			{tear "piece_medium_steel" bone %0
				{impulse up 4 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 6 no_position}
;				{add_view "smoke_dead_wheel" "smoke" "basis"}
;				{view start "smoke"}
				{delay_effect 20 5 "stop"}
			}
		)
		("cut_part" args "part1")
		("cut_part" args "part2")
		("cut_part" args "part3")
		("cut_part" args "part4")
		("cut_part" args "part5")
		("cut_part" args "part6")
	}
}

{"buldozer"
	{on move on
		{ani_play "liftup" +1}
	}
	{on move off
		{ani_play "liftup" -1 resume}
	}
}


{"mittlever car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light1"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
}

{"sdkfz251"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
		{link_sound "idle"		"vehicle/engine/sdkfz_Idle"}
	}
}

{"zis5 car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/blitz"	}
		{link_sound "engine"			"vehicle/engine/zis"   	}
		{link_sound "engine_end"		"vehicle/engine/zis_end"	}
		{link_sound "exhaust"			"vehicle/engine/zis_up"	}
		{link_sound "idle"		"vehicle/engine/truck_idle"}
	}
}
{"bm13 car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/blitz"	}
		{link_sound "engine"			"vehicle/engine/zis"   	}
		{link_sound "engine_end"		"vehicle/engine/zis_end"	}
		{link_sound "rotate_turret" 	"vehicle/turret/light"	}
		{link_sound "exhaust"			"vehicle/engine/zis_up"	}
		{link_sound "idle"		"vehicle/engine/truck_idle"}
	}
}
{"zis5eng car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/blitz"	}
		{link_sound "engine"			"vehicle/engine/zis"   	}
		{link_sound "engine_end"		"vehicle/engine/zis_end"	}
		{link_sound "exhaust"			"vehicle/engine/zis_up"	}
		{link_sound "idle"		"vehicle/engine/truck_idle"}
	}
}
{"zis42 car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/t34"	}
		{link_sound "engine"			"vehicle/engine/zis"   	}
		{link_sound "engine_end"		"vehicle/engine/zis_end"	}
		{link_sound "exhaust"			"vehicle/engine/zis_up"	}
		{link_sound "idle"		"vehicle/engine/truck_idle"}
	}
}
{"dodgewc56 car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/dodge"		}
		{link_sound "engine"			"vehicle/engine/dodge" 		}
		{link_sound "engine_end"		"vehicle/engine/dodge_end" 	}
		{link_sound "exhaust"			"vehicle/engine/dodge_up"	}
		{link_sound "idle"		"vehicle/engine/truck_idle"}
	}
}
(define "kubel_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/kubel"	}
		{link_sound "engine"			"vehicle/engine/kubel"   	}
		{link_sound "engine_end"		"vehicle/engine/kubel_end"	}
		{link_sound "exhaust"			"vehicle/engine/kubel_up"	}
		{link_sound "idle"		"vehicle/engine/kubel_idle"}
	}
)
{"kubel car"
	("kubel_sound")
}
{"willysmb car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/MB"	}
		{link_sound "engine"			"vehicle/engine/MB" 		}
		{link_sound "engine_end"		"vehicle/engine/MB_end" 	}
		{link_sound "exhaust"			"vehicle/engine/MB_up"		}
		{link_sound "idle"		"vehicle/engine/kubel_idle"}
	}
}
(define "horch_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/horch"	}
		{link_sound "engine"			"vehicle/engine/horch" 		}
		{link_sound "engine_end"		"vehicle/engine/horch_end" 	}
		{link_sound "exhaust"			"vehicle/engine/horch_up"	}
		{link_sound "idle"		"vehicle/engine/kubel_idle"}
	}
)
{"horch car"
	("horch_sound")
}
(define "gmc_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/gmc"		}
		{link_sound "move_end"			"vehicle/wheels/gmc_end"	}
		{link_sound "engine"			"vehicle/engine/m3a1" 		}
		{link_sound "engine_end"		"vehicle/engine/m3a1_end" 	}
		{link_sound "exhaust"			"vehicle/engine/m3a1_up"	}
		{link_sound "idle"		"vehicle/engine/truck_idle"}
	}
)
{"gmc_cckw car"
	("gmc_sound")
}
{"gmc_inf car"
	("gmc_sound")
}
{"gmc_art car"
	("gmc_sound")
}
{"gmc car"
	("gmc_sound")
}
{"gmc_eng car"
	("gmc_sound")
}
(define "opel_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/blitz"	}
		{link_sound "engine"			"vehicle/engine/Blitz"   	}
		{link_sound "engine_end"		"vehicle/engine/Blitz_end"	}
		{link_sound "exhaust"			"vehicle/engine/Blitz_up"	}
		{link_sound "idle"		"vehicle/engine/truck_idle"}
	}
)
{"blitz3_6"
	("opel_sound")
}
{"blitz3_6inf"
	("opel_sound")
}
{"blitz3_6art"
	("opel_sound")
}
{"blitz3_6eng"
	("opel_sound")
}
{"blitz3_6f"
	("opel_sound")
}
{"blitz3_6m"
	("opel_sound")
}
{"isuzutx40"
	("opel_sound")
}
{"sdkfz10_5 car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz10"	 }
		{link_sound "engine"			"vehicle/engine/sdkfz10"	 }
		{link_sound "engine_end"		"vehicle/engine/sdkfz234_end" }
		{link_sound "rotate_turret" 	"vehicle/turret/light1"		 }
		{link_sound "exhaust"			"vehicle/engine/sdkfz234_up" }
		{link_sound "idle"		"vehicle/engine/sdkfz_Idle"}
	}
}

{"car_with_dust"
	{on spawn
		{add_view	"dustrun_small"			"on_ground"			"FXtraceR1"}
		{add_view	"dustrun_small"			"on_ground"			"FXtraceL1"}
	}
	{on "start_fx_ground"
		{view start "on_ground"}
	}
	{on "stop_fx_ground"
		{view pause "on_ground"}
	}
}

{"soldier_us_afr_palmer_dodge"
	{on "lights_on"
		{add_view 	"headlight"		"light"		"headlightL"}
		{add_view 	"headlight"		"light"		"headlightR"}
		{add_view 	"light_vehicle"	"light"		"fxlight"}
		{view start "light"}
		{view show "light"}
	}
}
{"truck_mortar"
	{on fire "gun"
		{spawn "startsmoke" inv_normal}
	}
}
;-----------------Normand Unit Pack
(define "break_glass2"
 	{volumes "glass%1" disable bullet contact blast}
 	{spawn "glass_hit2" "glass%1" x}
 	{delay 0.1
 	{bone cut "glass%1"}
	}
)
(define "sdkfz250_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
)
(define "zis5_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/blitz"	}
		{link_sound "engine"			"vehicle/engine/zis"   	}
		{link_sound "engine_end"		"vehicle/engine/zis_end"	}
		{link_sound "exhaust"			"vehicle/engine/zis_up"	}
	}
)
(define "zis42_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/t34"	}
		{link_sound "engine"			"vehicle/engine/zis"   	}
		{link_sound "engine_end"		"vehicle/engine/zis_end"	}
		{link_sound "exhaust"			"vehicle/engine/zis_up"	}
	}
)
(define "willys_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/MB"	}
		{link_sound "engine"			"vehicle/engine/MB" 		}
		{link_sound "engine_end"		"vehicle/engine/MB_end" 	}
		{link_sound "exhaust"			"vehicle/engine/MB_up"		}
	}
)
(define "break_glass_zis"
 	{volumes "glass%1" disable bullet contact blast}
 	{spawn "glass_hit2" "glass%1" x}
 	{delay 0.1
 	{bone cut "glass%1"}
	}
	)
(define "break_glass_us6"
 	{volumes "glass%1" disable bullet contact blast}
 	{spawn "glass_hit2" "glass%1" x}
 	{delay 0.1
 	{bone cut "glass%1"}
	}
	)
{"np_zis42 car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/t34"	}
		{link_sound "engine"			"vehicle/engine/zis"   	}
		{link_sound "engine_end"		"vehicle/engine/zis_end"	}
		{link_sound "exhaust"			"vehicle/engine/zis_up"	}
	}
	{on move on
		{ani_play "move1" +1}
	}
	{on move off
		{ani_play "move1" -1}
	}
	{on bullet_hit
 		{if volume "glass_front"
 			("break_glass_zis" args 1 _front)
 		else volume "glass_doorleft"
 			("break_glass_zis" args 3 _doorleft)
 		else volume "glass_doorright"
 			("break_glass_zis" args 3 _doorright)
 		else volume "glass_back"
 			("break_glass_zis" args 3 _back)
		}
 	}
}
{"np_zis42_61k car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/t34"	}
		{link_sound "engine"			"vehicle/engine/zis"   	}
		{link_sound "engine_end"		"vehicle/engine/zis_end"	}
		{link_sound "exhaust"			"vehicle/engine/zis_up"	}
	}
	{on move on
		{ani_play "move1" +1}
	}
	{on move off
		{ani_play "move1" -1}
	}
	{on bullet_hit
 		{if volume "glass_front"
 			("break_glass_zis" args 1 _front)
 		else volume "glass_doorleft"
 			("break_glass_zis" args 3 _doorleft)
 		else volume "glass_doorright"
 			("break_glass_zis" args 3 _doorright)
 		else volume "glass_back"
 			("break_glass_zis" args 3 _back)
		}
 	}
}

{"np_studebakerus6  car" 
	("gmc_sound")

	
 	{on bullet_hit
 		{if volume "glass_front"
 			("break_glass_us6" args 1 _front)
 		else volume "glass_doorleft"
 			("break_glass_us6" args 3 _doorleft)
 		else volume "glass_doorright"
 			("break_glass_us6" args 3 _doorright)
 		else volume "glass_back"
 			("break_glass_us6" args 3 _back)
		else volume "glass_lightr"
 			("break_glass_us6" args 3 _lightr)
 		else volume "glass_lightl"
 			("break_glass_us6" args 3 _lightl)
		}
 	}
}
{"np_sdkfz8 car"
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

{"np_bm31" 
	("gmc_sound")

	
 	{on bullet_hit
 		{if volume "glass_front"
 			("break_glass_us6" args 1 _front)
 		else volume "glass_doorleft"
 			("break_glass_us6" args 3 _doorleft)
 		else volume "glass_doorright"
 			("break_glass_us6" args 3 _doorright)
 		else volume "glass_back"
 			("break_glass_us6" args 3 _back)
		else volume "glass_lightr"
 			("break_glass_us6" args 3 _lightr)
 		else volume "glass_lightl"
 			("break_glass_us6" args 3 _lightl)
		}
 	}
} 
{"np_sdkfz250_1"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
}
{"sdkfz250_1"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
}
{"np_sdkfz250_10"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
}
{"np_sdkfz250_11"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
}
{"np_sdkfz250_3"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
}
{"np_sdkfz250_7_1"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
}
{"np_sdkfz250_9"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
}
{"np_sdkfz250_1"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
}
{"np_sdkfz250_10"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
}
(define "break_glass_ml3000"
 	{volumes "glass%1" disable bullet contact blast}
 	{spawn "glass_hit2" "glass%1" x}
 	{delay 0.1
 	{bone cut "glass%1"}
	}
)
{"np_mercedesl3000" 
	("opel_sound")

	{on bullet_hit
 		{if volume "glass_front"
 			("break_glass_ml3000" args 1 _front)
 		else volume "glass_doorl"
 			("break_glass_ml3000" args 3 _doorl)
 		else volume "glass_doorr"
 			("break_glass_ml3000" args 3 _doorr)
 		else volume "glass_back"
 			("break_glass_ml3000" args 3 _back)
		}
 	}
} 
{"np_mercedesl3000_art" 
	("opel_sound")

	{on bullet_hit
 		{if volume "glass_front"
 			("break_glass_ml3000" args 1 _front)
 		else volume "glass_doorl"
 			("break_glass_ml3000" args 3 _doorl)
 		else volume "glass_doorr"
 			("break_glass_ml3000" args 3 _doorr)
 		else volume "glass_back"
 			("break_glass_ml3000" args 3 _back)
		}
 	}
} 
{"np_sdkfz251_1"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
}
{"sdkfz251_6"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
}
{"np_sdkfz251_9"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
}
{"np_sdkfz251_10"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
}
{"sdkfz251_10"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
}
{"np_sdkfz251_17"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
}
{"sdkfz251_17"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
}
{"sdkfz251_22"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
}
{"sdkfz301wanze"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
}
{"sdkfz7_1"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
}
{"sdkfz7_2a"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
}
{"sdkfz7_2a_41"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
}
{"sdkfz7_2"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
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
{"sdkfz7_flak18"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
}
{"sdkfz7_flak18_1940"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
}
{"sdkfz8"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	} 
	}
}
{"sdkfz251_1_stuka"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	} 
	}
}
{"sdkfz251_1_stuka"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	} 
	}
}
{"np_sdkfz251_1w"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
	}
	{on fire "gun"
		{spawn "startsmoke_big"}
		{spawn "startdust_big" "FXdust"}
	}
	{on fire "gun2"
		{ani_play "fire"}
		{spawn "startsmoke_big"}
		{spawn "startdust_big" "FXdust"}
	}
	{on fire "gun3"
		{ani_play "fire"}
		{spawn "startsmoke_big"}
		{spawn "startdust_big" "FXdust"}
	}
	{on "__explosion"
		{set "big_explosion" 0}
		{if explosive_amount 50
			{blastwave c4 20 r0 10 r1 25}
			{spawn "train_die" "basis"}
			{set "big_explosion" 1}
			{con "big explosive"}
		}
	}
	{on "spawn_shellhole"
		{if "big_explosion"                                        
			{spawn "crater_extra_big" "basis" terrain_texmod}
                        {spawn "shellhole_big_dead" "basis"}
		}
	}
	{on blast
		{if volume "body"
			{if min_energy 3
				{call "blast_body"}
			else min_energy 1
				{if rand 0.6
					{call "blast_body"}
				}			
			else stuff "grenade"
				{if rand 0.4
					{call "blast_body"}
				}
			}	
		}
	}
}
{"np_gaz61" 
	("horch_sound")

	(define "break_glass_gaz61"
 	{volumes "glass%1" disable bullet contact blast}
 	{spawn "glass_hit2" "glass%1" x}
 	{delay 0.1
 	{bone cut "glass%1"}
	}
	)
 	{on bullet_hit
 		{if volume "glass_front"
 			("break_glass_gaz61" args 1 _front)
 		else volume "glass_doorl1"
 			("break_glass_gaz61" args 3 _doorl1)
 		else volume "glass_doorr1"
 			("break_glass_gaz61" args 3 _doorr1)
 		else volume "glass_doorl2"
 			("break_glass_gaz61" args 3 _doorl2)
 		else volume "glass_doorr2"
 			("break_glass_gaz61" args 3 _doorr2)
		else volume "glass_r"
 			("break_glass_gaz61" args 3 _r)
		else volume "glass_l"
 			("break_glass_gaz61" args 3 _l)
		else volume "glass_back"
 			("break_glass_gaz61" args 3 _back)
		}
 	}
} 
{"np_willysmb car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/MB"	}
		{link_sound "engine"			"vehicle/engine/MB" 		}
		{link_sound "engine_end"		"vehicle/engine/MB_end" 	}
		{link_sound "exhaust"			"vehicle/engine/MB_up"		}
	}
	(define "break_glass_2"
 	{volumes "glass%1" disable bullet contact blast}
 	{spawn "glass_hit2" "glass%1" x}
 	{delay 0.1
 	{bone cut "glass%1"}
	}
	)
 	{on bullet_hit
 		{if volume "glass_front1"
 			("break_glass_2" args 1 _front1)
 		else volume "glass_front2"
 			("break_glass_2" args 1 _front2)
 		}
 	}
}
{"np_willys50 car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/MB"	}
		{link_sound "engine"			"vehicle/engine/MB" 		}
		{link_sound "engine_end"		"vehicle/engine/MB_end" 	}
		{link_sound "exhaust"			"vehicle/engine/MB_up"		}
	}
}
{"np_willysat car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/MB"	}
		{link_sound "engine"			"vehicle/engine/MB" 		}
		{link_sound "engine_end"		"vehicle/engine/MB_end" 	}
		{link_sound "exhaust"			"vehicle/engine/MB_up"		}
	}
}
{"np_zis5 car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/blitz"	}
		{link_sound "engine"			"vehicle/engine/zis"   	}
		{link_sound "engine_end"		"vehicle/engine/zis_end"	}
		{link_sound "exhaust"			"vehicle/engine/zis_up"	}
	}
	{on bullet_hit
 		{if volume "glass_front"
 			("break_glass_zis" args 1 _front)
 		else volume "glass_doorleft"
 			("break_glass_zis" args 1 _doorleft)
 		else volume "glass_doorright"
 			("break_glass_zis" args 1 _doorright)
 		else volume "glass_back"
 			("break_glass_zis" args 1 _back)
		}
 	}
}
{"np_zis5_en car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/blitz"	}
		{link_sound "engine"			"vehicle/engine/zis"   	}
		{link_sound "engine_end"		"vehicle/engine/zis_end"	}
		{link_sound "exhaust"			"vehicle/engine/zis_up"	}
	}
	{on bullet_hit
 		{if volume "glass_front"
 			("break_glass_zis" args 1 _front)
 		else volume "glass_doorleft"
 			("break_glass_zis" args 1 _doorleft)
 		else volume "glass_doorright"
 			("break_glass_zis" args 1 _doorright)
 		else volume "glass_back"
 			("break_glass_zis" args 1 _back)
		else volume "glass_1"
 			("break_glass_zis" args 1 _1)
		else volume "glass_2"
 			("break_glass_zis" args 1 _2)
		else volume "glass_3"
 			("break_glass_zis" args 1 _3)
		else volume "glass_4"
 			("break_glass_zis" args 1 _4)
		else volume "glass_5"
 			("break_glass_zis" args 1 _5)
		else volume "glass_6"
 			("break_glass_zis" args 1 _6)
		}
 	}
}

{"np_zis5_fuel car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/blitz"	}
		{link_sound "engine"			"vehicle/engine/zis"   	}
		{link_sound "engine_end"		"vehicle/engine/zis_end"	}
		{link_sound "exhaust"			"vehicle/engine/zis_up"	}
	}
	{on bullet_hit
 		{if volume "glass_front"
 			("break_glass_zis" args 1 _front)
 		else volume "glass_doorleft"
 			("break_glass_zis" args 1 _doorleft)
 		else volume "glass_doorright"
 			("break_glass_zis" args 1 _doorright)
 		else volume "glass_back"
 			("break_glass_zis" args 1 _back)
		}
 	}
}
{"np_zis5_inf car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/blitz"	}
		{link_sound "engine"			"vehicle/engine/zis"   	}
		{link_sound "engine_end"		"vehicle/engine/zis_end"	}
		{link_sound "exhaust"			"vehicle/engine/zis_up"	}
	}
	{on bullet_hit
 		{if volume "glass_front"
 			("break_glass_zis" args 1 _front)
 		else volume "glass_doorleft"
 			("break_glass_zis" args 1 _doorleft)
 		else volume "glass_doorright"
 			("break_glass_zis" args 1 _doorright)
 		else volume "glass_back"
 			("break_glass_zis" args 1 _back)
		}
 	}
}
{"np_zis5_art car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/blitz"	}
		{link_sound "engine"			"vehicle/engine/zis"   	}
		{link_sound "engine_end"		"vehicle/engine/zis_end"	}
		{link_sound "exhaust"			"vehicle/engine/zis_up"	}
	}
	{on bullet_hit
 		{if volume "glass_front"
 			("break_glass_zis" args 1 _front)
 		else volume "glass_doorleft"
 			("break_glass_zis" args 1 _doorleft)
 		else volume "glass_doorright"
 			("break_glass_zis" args 1 _doorright)
 		else volume "glass_back"
 			("break_glass_zis" args 1 _back)
		}
 	}
}
{"np_yag10 car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/blitz"	}
		{link_sound "engine"			"vehicle/engine/zis"   	}
		{link_sound "engine_end"		"vehicle/engine/zis_end"	}
		{link_sound "exhaust"			"vehicle/engine/zis_up"	}
	}
	{on bullet_hit
 		{if volume "glass_front1"
 			("break_glass_zis" args 1 _front1)
 		else volume "glass_front2"
 			("break_glass_zis" args 1 _front2)
		else volume "glass_doorl"
			("break_glass_zis" args 1 _doorl)
 		else volume "glass_doorr"
 			("break_glass_zis" args 1 _doorr)
 		else volume "glass_back"
 			("break_glass_zis" args 1 _back)
		}
 	}
}
{"np_29k car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/blitz"	}
		{link_sound "engine"			"vehicle/engine/zis"   	}
		{link_sound "engine_end"		"vehicle/engine/zis_end"	}
		{link_sound "exhaust"			"vehicle/engine/zis_up"	}
	}
	{on fire "gun"
		{ani_play "fire"}
	}
	{on bullet_hit
 		{if volume "glass_front1"
 			("break_glass_zis" args 1 _front1)
 		else volume "glass_front2"
 			("break_glass_zis" args 1 _front2)
		else volume "glass_doorl"
			("break_glass_zis" args 1 _doorl)
 		else volume "glass_doorr"
 			("break_glass_zis" args 1 _doorr)
 		else volume "glass_back"
 			("break_glass_zis" args 1 _back)
		}
 	}
}
{"np_opel" 
	("opel_sound")
 	{on bullet_hit
 		{if volume "glass_front"
 			("break_glass_ml3000" args 1 _front)
 		else volume "glass_doorl"
 			("break_glass_ml3000" args 3 _doorl)
 		else volume "glass_doorr"
 			("break_glass_ml3000" args 3 _doorr)
 		else volume "glass_back"
 			("break_glass_ml3000" args 3 _back)
		}
 	}
} 
{"np_opel_f" 
	("opel_sound")
 	{on bullet_hit
 		{if volume "glass_front"
 			("break_glass_ml3000" args 1 _front)
 		else volume "glass_doorl"
 			("break_glass_ml3000" args 3 _doorl)
 		else volume "glass_doorr"
 			("break_glass_ml3000" args 3 _doorr)
 		else volume "glass_back"
 			("break_glass_ml3000" args 3 _back)
		}
 	}
} 
{"np_opel_eng" 
	("opel_sound")
 	{on bullet_hit
 		{if volume "glass_front"
 			("break_glass_ml3000" args 1 _front)
 		else volume "glass_doorl"
 			("break_glass_ml3000" args 3 _doorl)
 		else volume "glass_doorr"
 			("break_glass_ml3000" args 3 _doorr)
 		else volume "glass_back"
 			("break_glass_ml3000" args 3 _back)
		}
 	}
} 
{"np_opel_inf" 
	("opel_sound")
 	{on bullet_hit
 		{if volume "glass_front"
 			("break_glass_ml3000" args 1 _front)
 		else volume "glass_doorl"
 			("break_glass_ml3000" args 3 _doorl)
 		else volume "glass_doorr"
 			("break_glass_ml3000" args 3 _doorr)
 		else volume "glass_back"
 			("break_glass_ml3000" args 3 _back)
		}
 	}
} 
{"np_opel_art" 
	("opel_sound")
 	{on bullet_hit
 		{if volume "glass_front"
 			("break_glass_ml3000" args 1 _front)
 		else volume "glass_doorl"
 			("break_glass_ml3000" args 3 _doorl)
 		else volume "glass_doorr"
 			("break_glass_ml3000" args 3 _doorr)
 		else volume "glass_back"
 			("break_glass_ml3000" args 3 _back)
		}
 	}
} 
{"morris_cs8  car" 
	("gmc_sound")
}
{"m3a1scout"
	("gmc_sound")
}
{"m3a1scout_us"
	("gmc_sound")
}
{"np_t14_us"
	("gmc_sound")
}
{"np_m4_us"
	("gmc_sound")
}
{"np_m3b_us"
	("gmc_sound")
}
{"np_matador" 
	("gmc_sound")
 	{on bullet_hit
 		{if volume "glass_front1"
 			("break_glass2" args 1 _front1)
		else volume "glass_front2"
 			("break_glass2" args 1 _front2)
 		else volume "glass_right"
 			("break_glass2" args 3 _right)
 		else volume "glass_left"
 			("break_glass2" args 3 _left)
		else volume "glass_doorl"
 			("break_glass2" args 3 _doorl)
 		else volume "glass_doorr"
 			("break_glass2" args 3 _doorr)
 		}
 	}
}
{"np_type94" 
	("opel_sound")
 	{on bullet_hit
 		{if volume "glass_front"
 			("break_glass2" args 1 _front)
 		else volume "glass_right"
 			("break_glass2" args 3 _right)
 		else volume "glass_left"
 			("break_glass2" args 3 _left)
		else volume "glass_doorl"
 			("break_glass2" args 3 _doorl)
 		else volume "glass_doorr"
 			("break_glass2" args 3 _doorr)
 		}
 	}
} 
;-----------------Normand Unit Pack
;-----------------Zeke Wolff Unit Pack
{"quad car"
		{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/dodge"		}
;		{link_sound "move_end"			"wheels.d3_move_end"}
		{link_sound "engine"			"vehicle/engine/dodge" 		}
		{link_sound "engine_end"		"vehicle/engine/dodge_end" 	}
		{link_sound "exhaust"			"vehicle/engine/dodge_up"	}
	}
}
{"ketten car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz10"	 }
		{link_sound "engine"			"vehicle/engine/horch"	 }
		{link_sound "engine_end"		"vehicle/engine/horch_end" }
		{link_sound "exhaust"			"vehicle/engine/sdkfz234_up" }
	}
}
;-----------------Zeke Wolff Unit Pack
;-----------------Skr Unit Pack
;----- БЛОК ОБЪЯВЛЕНИЯ ОБЩИХ ФУНКЦИЙ -----

;--- функция разбивания стекла при попадании пули (из Normand Pack 6.3) ---
(define "break_glass2"
 	{volumes "glass%1" disable bullet contact blast}
 	{spawn "glass_hit2" "glass%1" x}
 	{delay 0.1
 	{bone cut "glass%1"}
	}
)

(define "burn_by_engine"
	{on "burn_by_engine"
    	{if not tagged "burned"
    		{if rand %0
    			{call "_burn"}
				{delay 3 1
					{view stop "smoke1"}
					{set "smoke1" 0}
				}
    		}
    	}
    }
)

(define "zis5_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/blitz"	}
		{link_sound "engine"			"vehicle/engine/zis"   	}
		{link_sound "engine_end"		"vehicle/engine/zis_end"	}
		{link_sound "exhaust"			"vehicle/engine/zis_up"	}
		{link_sound "idle"				"vehicle/engine/zis"	}
	}
)
(define "zis42_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/t34"	}
		{link_sound "engine"			"vehicle/engine/zis"   	}
		{link_sound "engine_end"		"vehicle/engine/zis_end"	}
		{link_sound "exhaust"			"vehicle/engine/zis_up"	}
		{link_sound "idle"				"vehicle/engine/zis"	}
	}
)
(define "gazmm_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/engine/t-38"	}
		{link_sound "move_end"			"vehicle/engine/t-38_end"}
		{link_sound "engine"			"vehicle/engine/t-38"   	}
		{link_sound "engine_end"		"vehicle/engine/t-38_end"	}
		{link_sound "exhaust"			"vehicle/engine/t-38_up"	}
;		{link_sound "idle"				"vehicle/engine/t-38"	}
	}
	("burn_by_engine" args 0.5)
)
(define "voroshilovets_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/t34"		}
		{link_sound "engine_end"		"vehicle/engine/t34_end"	}
		{link_sound "exhaust"			"vehicle/engine/m3a1_up"		}
		{link_sound "rotate_turret" 	"vehicle/turret/light"		}
		{link_sound "idle"			"vehicle/engine/t34_idle"	}
	}
)
(define "sdkfz250_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/tracks/sdkfz250"	}
		{link_sound "engine"			"vehicle/engine/sdkfz250"		}
		{link_sound "engine_end"		"vehicle/engine/sdkfz250_end"	}
		{link_sound "exhaust"			"vehicle/engine/sdkfz250_up"	}
		{link_sound "idle"				"vehicle/engine/sdkfz_idle"	}
	}
)
(define "willys_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/MB"	}
		{link_sound "engine"			"vehicle/engine/MB" 		}
		{link_sound "engine_end"		"vehicle/engine/MB_end" 	}
		{link_sound "exhaust"			"vehicle/engine/MB_up"		}
		{link_sound "idle"			"vehicle/engine/willys_idle"	}
	}
)

;----- БЛОК ОПИСАНИЯ АВТОМОБИЛЕЙ -----
{"stoewer_r200_kfz1 car" 
	("kubel_sound")
 	{on bullet_hit
 		{if volume "glass_front1"
 			("break_glass2" args 1 _front1)
 		}
 		{if volume "glass_front2"
 			("break_glass2" args 1 _front2)
 		}
 		{if volume "glass_right1"
 			("break_glass2" args 1 _right1)
 		}
 		{if volume "glass_right2"
 			("break_glass2" args 1 _right2)
 		}
 		{if volume "glass_left1"
 			("break_glass2" args 1 _left1)
 		}
 		{if volume "glass_left2"
 			("break_glass2" args 1 _left2)
 		}
 	}
}

;--- окна автомобилей ГАЗ ---
(define "gazavto_glass"
 	{on bullet_hit
 		{if volume "glass_front1"
 			("break_glass2" args 1 _front1)
 		}
 		{if volume "glass_front2"
 			("break_glass2" args 1 _front2)
 		}
 		{if volume "glass_right1"
 			("break_glass2" args 1 _right1)
 		}
 		{if volume "glass_right2"
 			("break_glass2" args 1 _right2)
 		}
 		{if volume "glass_right3"
 			("break_glass2" args 1 _right3)
 		}
 		{if volume "glass_right4"
 			("break_glass2" args 1 _right4)
 		}
  		{if volume "glass_right5"
 			("break_glass2" args 1 _right5)
 		}
 		{if volume "glass_right6"
 			("break_glass2" args 1 _right6)
 		}
 		{if volume "glass_right7"
 			("break_glass2" args 1 _right7)
 		}
 		{if volume "glass_right8"
 			("break_glass2" args 1 _right8)
 		}
 		{if volume "glass_right9"
 			("break_glass2" args 1 _right9)
 		}
 		{if volume "glass_left1"
 			("break_glass2" args 1 _left1)
 		}
 		{if volume "glass_left2"
 			("break_glass2" args 1 _left2)
 		}
		{if volume "glass_left3"
 			("break_glass2" args 1 _left3)
 		}
 		{if volume "glass_left4"
 			("break_glass2" args 1 _left4)
 		}
		{if volume "glass_left5"
 			("break_glass2" args 1 _left5)
 		}
 		{if volume "glass_left6"
 			("break_glass2" args 1 _left6)
 		}
		{if volume "glass_left7"
 			("break_glass2" args 1 _left7)
 		}
		{if volume "glass_left8"
 			("break_glass2" args 1 _left8)
 		}
		{if volume "glass_left9"
 			("break_glass2" args 1 _left9)
 		}
 		{if volume "glass_back1"
 			("break_glass2" args 1 _back1)
 		}
 		{if volume "glass_back2"
 			("break_glass2" args 1 _back2)
 		}
 		{if volume "glass_back3"
 			("break_glass2" args 1 _back3)
 		}
 		{if volume "glass_back4"
 			("break_glass2" args 1 _back4)
 		}
 		{if volume "glass_back5"
 			("break_glass2" args 1 _back5)
 		}
 		{if volume "glass_back6"
 			("break_glass2" args 1 _back6)
 		}
 		{if volume "glass_back7"
 			("break_glass2" args 1 _back7)
 		}
 		{if volume "glass_light1"
 			("break_glass2" args 1 _light1)
 		}
 		{if volume "glass_light2"
 			("break_glass2" args 1 _light2)
 		}
 		{if volume "glass_light3"
 			("break_glass2" args 1 _light3)
 		}
 		{if volume "glass_mirror1"
 			("break_glass2" args 1 _mirror1)
 		}
 	}
)

{"stoewer_r200_kfz2 car" 
	{on spawn
		{ani_play "close_anten"}
		{set "radar_up" 0}
		{link_sound "radio" "vehicle/entourage/morze" }
	}
	{on "uprise_anten" 
		{if not "radar_up" 
			{ani_play "close_anten" -0.3} 
			{set "radar_up" 1}
			{play_sound "radio" 1}
		}
	}
	{on "lower_anten" 
		{if "radar_up" 
			{ani_play "close_anten" 0.5}
			{set "radar_up" 0}
			{stop_sound "radio"}
		}
	}
	{on move on {kill_delay "anten"} {call "lower_anten"}}
	{on move off {delay 30 "anten" {call "uprise_anten"}}}
	{on operatable off {kill_delay "anten"} {call "lower_anten"}}
	{on operatable on {call "uprise_anten"}}
	("kubel_sound")
 	{on bullet_hit
 		{if volume "glass_front1"
 			("break_glass2" args 1 _front1)
 		}
 		{if volume "glass_front2"
 			("break_glass2" args 1 _front2)
 		}
 		{if volume "glass_right1"
 			("break_glass2" args 1 _right1)
 		}
 		{if volume "glass_right2"
 			("break_glass2" args 1 _right2)
 		}
 		{if volume "glass_left1"
 			("break_glass2" args 1 _left1)
 		}
 		{if volume "glass_left2"
 			("break_glass2" args 1 _left2)
 		}
 	}
}
{"gaz_aaa_1942 car" 
	("gazavto_glass")
	("gazmm_sound")
}
{"gaz_mm_72k car"
	{on spawn
		{ani_play "open"}
		{set "bort_up" 0}
	}
	{on "bort_open" 
		{if not "bort_up" 
			{ani_play "open" 1.0}
			{set "bort_up" 1}
		}
	}
	{on "bort_close" 
		{if "bort_up" 
			{ani_play "open" -1.5}
			{set "bort_up" 0}
		}
	}
	{on move on {kill_delay "parm"} {call "bort_close"}}
	{on move off {delay 5 "parm" {call "bort_open"}}}
	{on operatable off {kill_delay "parm"} {call "bort_close"}}
	{on operatable on {call "bort_open"}}
	{on fire "gun"
		{spawn "startdust_big" "FXdust"}
	}
	("gazavto_glass")
	("gazmm_sound")
}
{"stoewer_r200_kfz2_40 car" 
	("kubel_sound")
 	{on bullet_hit
 		{if volume "glass_front1"
 			("break_glass2" args 1 _front1)
 		}
 		{if volume "glass_front2"
 			("break_glass2" args 1 _front2)
 		}
 		{if volume "glass_right1"
 			("break_glass2" args 1 _right1)
 		}
 		{if volume "glass_right2"
 			("break_glass2" args 1 _right2)
 		}
 		{if volume "glass_left1"
 			("break_glass2" args 1 _left1)
 		}
 		{if volume "glass_left2"
 			("break_glass2" args 1 _left2)
 		}
 	}
}
{"stoewer_r200_kfz3 car" 
	("kubel_sound")
 	{on bullet_hit
 		{if volume "glass_front1"
 			("break_glass2" args 1 _front1)
 		}
 		{if volume "glass_front2"
 			("break_glass2" args 1 _front2)
 		}
 		{if volume "glass_right1"
 			("break_glass2" args 1 _right1)
 		}
 		{if volume "glass_right2"
 			("break_glass2" args 1 _right2)
 		}
 		{if volume "glass_left1"
 			("break_glass2" args 1 _left1)
 		}
 		{if volume "glass_left2"
 			("break_glass2" args 1 _left2) 
 		}
 	}
}
{"stoewer_r200_kfz4 car" 
	("kubel_sound")
 	{on bullet_hit
 		{if volume "glass_front1"
 			("break_glass2" args 1 _front1)
 		}
 		{if volume "glass_front2"
 			("break_glass2" args 1 _front2)
 		}
 	}
}
{"kfz_4 car" 
	("kubel_sound")
 	{on bullet_hit
 		{if volume "glass_front1"
 			("break_glass2" args 1 _front1)
 		}
 		{if volume "glass_front2"
 			("break_glass2" args 1 _front2)
 		}
 	}
}
{"stoewer_t40_kfz1 car" 
	("kubel_sound")
 	{on bullet_hit
 		{if volume "glass_front1"
 			("break_glass2" args 1 _front1)
 		}
 		{if volume "glass_front2"
 			("break_glass2" args 1 _front2)
 		}
 		{if volume "glass_right1"
 			("break_glass2" args 1 _right1)
 		}
 		{if volume "glass_right2"
 			("break_glass2" args 1 _right2)
 		}
 		{if volume "glass_left1"
 			("break_glass2" args 1 _left1)
 		}
 		{if volume "glass_left2"
 			("break_glass2" args 1 _left2)
 		}
 	}
}
{"stoewer_t40_kfz2 car" 
	{on spawn
		{ani_play "close_anten"}
		{set "radar_up" 0}
		{link_sound "radio" "vehicle/entourage/morze" }
	}
	{on "uprise_anten" 
		{if not "radar_up" 
			{ani_play "close_anten" -0.3} 
			{set "radar_up" 1}
			{play_sound "radio" 1}
		}
	}
	{on "lower_anten" 
		{if "radar_up" 
			{ani_play "close_anten" 0.5}
			{set "radar_up" 0}
			{stop_sound "radio"}
		}
	}
	{on move on {kill_delay "anten"} {call "lower_anten"}}
	{on move off {delay 30 "anten" {call "uprise_anten"}}}
	{on operatable off {kill_delay "anten"} {call "lower_anten"}}
	{on operatable on {call "uprise_anten"}}
	("kubel_sound")
 	{on bullet_hit
 		{if volume "glass_front1"
 			("break_glass2" args 1 _front1)
 		}
 		{if volume "glass_front2"
 			("break_glass2" args 1 _front2)
 		}
 		{if volume "glass_right1"
 			("break_glass2" args 1 _right1)
 		}
 		{if volume "glass_right2"
 			("break_glass2" args 1 _right2)
 		}
 		{if volume "glass_left1"
 			("break_glass2" args 1 _left1)
 		}
 		{if volume "glass_left2"
 			("break_glass2" args 1 _left2)
 		}
 	}
}
{"stoewer_t40_kfz2_40 car" 
	("kubel_sound")
 	{on bullet_hit
 		{if volume "glass_front1"
 			("break_glass2" args 1 _front1)
 		}
 		{if volume "glass_front2"
 			("break_glass2" args 1 _front2)
 		}
 		{if volume "glass_right1"
 			("break_glass2" args 1 _right1)
 		}
 		{if volume "glass_right2"
 			("break_glass2" args 1 _right2)
 		}
 		{if volume "glass_left1"
 			("break_glass2" args 1 _left1)
 		}
 		{if volume "glass_left2"
 			("break_glass2" args 1 _left2)
 		}
 	}
}
{"stoewer_t40_kfz3 car" 
	("kubel_sound")
 	{on bullet_hit
 		{if volume "glass_front1"
 			("break_glass2" args 1 _front1)
 		}
 		{if volume "glass_front2"
 			("break_glass2" args 1 _front2)
 		}
 		{if volume "glass_right1"
 			("break_glass2" args 1 _right1)
 		}
 		{if volume "glass_right2"
 			("break_glass2" args 1 _right2)
 		}
 		{if volume "glass_left1"
 			("break_glass2" args 1 _left1)
 		}
 		{if volume "glass_left2"
 			("break_glass2" args 1 _left2)
 		}
 	}
}
{"stoewer_t40_kfz4 car" 
	("kubel_sound")
 	{on bullet_hit
 		{if volume "glass_front1"
 			("break_glass2" args 1 _front1)
 		}
 		{if volume "glass_front2"
 			("break_glass2" args 1 _front2)
 		}
 	}
}
(define "as_sound"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/dodge"	}
		{link_sound "engine"			"vehicle/engine/as37"	}
		{link_sound	"engine_end"		"vehicle/engine/as37_end"	}
		{link_sound "exhaust"			"vehicle/engine/as37_up"	}
		{link_sound "idle"			"vehicle/engine/as37"   	}
	}
)
(define "fiat_sound"
	{on "add_movement_sound" overload
		{link_sound	"move"				"vehicle/wheels/blitz"	}
		{link_sound "engine"			"vehicle/engine/horch"	}
		{link_sound	"engine_end"		"vehicle/engine/blitz_end"	}
		{link_sound "exhaust"			"vehicle/engine/blitz_up"	}
		{link_sound "idle"			"vehicle/engine/truck_idle"   	}
	}
)
{"fiat35"
	("fiat_sound")
}
{"fiat35_art"
	("fiat_sound")
}
{"fiat35_bomb"
	("fiat_sound")
}
{"fiataa35"
	("fiat_sound")
}
{"fiat508cm car"
	{on "add_movement_sound" overload
		{link_sound "move"		"vehicle/wheels/blitz"	}
		{link_sound "engine"		"vehicle/engine/Fiat508cm"	}
		{link_sound "engine_end"	"vehicle/engine/Fiat508cm_end"	}
		{link_sound "exhaust"		"vehicle/engine/fiat508cm_up"	}
		{link_sound "idle"			"vehicle/engine/horch"	}
	}
}
{"mototri car"
	{on "add_movement_sound" overload
		{link_sound "move"		"vehicle/wheels/blitz"	}
		{link_sound "engine"		"vehicle/engine/bmw"	}
		{link_sound "engine_end"	"vehicle/car_end"	}
		{link_sound "exhaust"		"vehicle(bmw_up"	}
	}
}
{"3ro"
	{on spawn
		{set "rotate_turret_3ro" 0}
		{set "chassis_work_turret" 1}
		{set "chassis_work" 1}
	}
	("fiat_sound")
;	("shell_ejection")
	{on ik begin "turret"
		{kill_delay "rotate_turret"}
		{if not "rotate_turret_3ro"
			{set "rotate_turret_3ro" 1}
			{If "chassis_work"
				{set "chassis_work" 0}
				{ani_play "close"}
				{play_sound "rotate_turret" 1}
				{set  "chassis_work_turret" 1}
			else
				{set  "chassis_work_turret" 0}
				
			}	
		}
	}
	{on ik end "turret"
		{if "rotate_turret_3ro"
			;{If  "chassis_work_turret"
				{set "chassis_work" 1}
			;}
		}
		{delay 0.5 "rotate_turret"
			{stop_sound "rotate_turret"}
			
		}
	}
	{on move on
		{if "rotate_turret_3ro"
			{set "rotate_turret_3ro" 0}
			{if work "turret"
				{ik_enable "turret" 0}
				{ani_play "close" -1}
				
			}
		}
		{set "engine_on" 1}
		{stop_sound "idle"}
		{stop_sound "move_end"}
		{play_sound "move" 1}
		{play_sound "exhaust"}
		{call "exhaust_on"}
		{ani_stop "stop"}
		{ani_play "start"}
		{view pause "exhaust2"}
	}
	{on move off
		{If not "rotate_turret_3ro"
			{if work "turret"
				{ik_enable "turret" 1}
				{set "chassis_work_turret" 1}
			}
		}
		{stop_sound "move"}
		{play_sound "move_end"}
		{call "exhaust_off"}
	}
	{on bullet_hit
 		{if volume "glass_1"
 			("break_glass2" args 1 _1)
 		else volume "glass_doorl"
 			("break_glass2" args 1 _2)
 		}
 	}
}
{"autocannone10017"
	("fiat_sound")
;	("shell_ejection")
}
{"morris_cs8_6517  car" 
	("gmc_sound")
;	("shell_ejection")
}
{"c50cma"	
	("fiat_sound")
;	("shell_ejection")
}
{"as421  car"
	("as_sound")
}
{"as422  car"
	("as_sound")
}
{"as423  car" 
	("as_sound")
;	("shell_ejection")
}



























{"np_mercedesl3000art" 
	("opel_sound")

	{on bullet_hit
 		{if volume "glass_front"
 			("break_glass_ml3000" args 1 _front)
 		else volume "glass_doorl"
 			("break_glass_ml3000" args 3 _doorl)
 		else volume "glass_doorr"
 			("break_glass_ml3000" args 3 _doorr)
 		else volume "glass_back"
 			("break_glass_ml3000" args 3 _back)
		}
 	}
} 
{"np_willys_mb car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/MB"	}
		{link_sound "engine"			"vehicle/engine/MB" 		}
		{link_sound "engine_end"		"vehicle/engine/MB_end" 	}
		{link_sound "exhaust"			"vehicle/engine/MB_up"		}
	}
	(define "break_glass_2"
 		{volumes "glass%1" disable bullet contact blast}
 		{spawn "glass_hit2" "glass%1" x}
 		{delay 0.1
 			{bone cut "glass%1"}
		}
	)
 	{on bullet_hit
 		{if volume "glass_front1"
 			("break_glass_2" args 1 _front1)
 		else volume "glass_front2"
 			("break_glass_2" args 1 _front2)
 		}
 	}
}
{"np_zis44 car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/blitz"	}
		{link_sound "engine"			"vehicle/engine/zis"   	}
		{link_sound "engine_end"		"vehicle/engine/zis_end"	}
		{link_sound "exhaust"			"vehicle/engine/zis_up"	}
	}
	{on bullet_hit
 		{if volume "glass_front"
 			("break_glass_zis" args 1 _front)
 		else volume "glass_doorleft"
 			("break_glass_zis" args 1 _doorleft)
 		else volume "glass_doorright"
 			("break_glass_zis" args 1 _doorright)
 		else volume "glass_back"
 			("break_glass_zis" args 1 _back)
		else volume "glass_1"
 			("break_glass_zis" args 1 _1)
		else volume "glass_2"
 			("break_glass_zis" args 1 _2)
		else volume "glass_3"
 			("break_glass_zis" args 1 _3)
		else volume "glass_4"
 			("break_glass_zis" args 1 _4)
		else volume "glass_5"
 			("break_glass_zis" args 1 _5)
		else volume "glass_6"
 			("break_glass_zis" args 1 _6)
		}
 	}
}
{"np_zis5_33 car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/blitz"	}
		{link_sound "engine"			"vehicle/engine/zis"   	}
		{link_sound "engine_end"		"vehicle/engine/zis_end"	}
		{link_sound "exhaust"			"vehicle/engine/zis_up"	}
	}
	{on bullet_hit
 		{if volume "glass_front"
 			("break_glass_zis" args 1 _front)
 		else volume "glass_doorleft"
 			("break_glass_zis" args 1 _doorleft)
 		else volume "glass_doorright"
 			("break_glass_zis" args 1 _doorright)
 		else volume "glass_back"
 			("break_glass_zis" args 1 _back)
		}
 	}
}
{"horch901_kfz12 car" 
	("horch_sound")
	(define "break_glass_2"
 		{volumes "glass%1" disable bullet contact blast}
 		{spawn "glass_hit2" "glass%1" x}
 		{delay 0.1
 			{bone cut "glass%1"}
		}
	)
 	{on bullet_hit
 		{if volume "glass_front1"
 			("break_glass_2" args 1 _front1)
 		}
 	}
} 
{"horch901_kfz15 car" 
	("horch_sound")
	(define "break_glass_2"
 		{volumes "glass%1" disable bullet contact blast}
 		{spawn "glass_hit2" "glass%1" x}
 		{delay 0.1
 			{bone cut "glass%1"}
		}
	)
 	{on bullet_hit
 		{if volume "glass_front1"
 			("break_glass_2" args 1 _front1)
 		}
 	}
} 
{"horch901_kfz16 car" 
	("horch_sound")
	(define "break_glass_2"
 		{volumes "glass%1" disable bullet contact blast}
 		{spawn "glass_hit2" "glass%1" x}
 		{delay 0.1
 			{bone cut "glass%1"}
		}
	)
 	{on bullet_hit
 		{if volume "glass_front1"
 			("break_glass_2" args 1 _front1)
 		}
 	}
} 
{"horch901_kfz17 car"
	{on spawn
		{ani_play "close_anten"}
		{set "radar_up" 0}
		{link_sound "radio" "vehicle/entourage/morze" }
	}
	{on "uprise_anten" 
		{if not "radar_up" 
			{ani_play "open_anten" 0.3} 
			{set "radar_up" 1}
			{play_sound "radio" 1}
		}
	}
	{on "lower_anten" 
		{if "radar_up" 
			{ani_play "close_anten" 0.5}
			{set "radar_up" 0}
			{stop_sound "radio"}
		}
	}
	{on move on {kill_delay "anten"} {call "lower_anten"}}
	{on move off {delay 30 "anten" {call "uprise_anten"}}}
	{on operatable off {kill_delay "anten"} {call "lower_anten"}}
	{on operatable on {call "uprise_anten"}}
	("horch_sound")
 	{on bullet_hit
 		{if volume "glass_front1"
 			("break_glass2" args 1 _front1)
 		}
 	}
}
{"horch901_kfz17_1 car"
	{on spawn
		{ani_play "close_anten"}
		{set "radar_up" 0}
		{link_sound "radio" "vehicle/entourage/morze" }
	}
	{on "uprise_anten" 
		{if not "radar_up" 
			{ani_play "close_anten" -0.3} 
			{set "radar_up" 1}
			{play_sound "radio" 1}
		}
	}
	{on "lower_anten" 
		{if "radar_up" 
			{ani_play "close_anten" 0.5}
			{set "radar_up" 0}
			{stop_sound "radio"}
		}
	}
	{on move on {kill_delay "anten"} {call "lower_anten"}}
	{on move off {delay 30 "anten" {call "uprise_anten"}}}
	{on operatable off {kill_delay "anten"} {call "lower_anten"}}
	{on operatable on {call "uprise_anten"}}
	("horch_sound")
	(define "break_glass_2"
 		{volumes "glass%1" disable bullet contact blast}
 		{spawn "glass_hit2" "glass%1" x}
 		{delay 0.1
 			{bone cut "glass%1"}
		}
	)
 	{on bullet_hit
 		{if volume "glass_front1"
 			("break_glass_2" args 1 _front1)
 		}
 	}
}






















{"np_mercedesl3000art car" 
	("opel_sound")

	(define "break_glass_ml3000"
 	{volumes "glass%1" disable bullet contact blast}
 	{spawn "glass_hit2" "glass%1" x}
 	{delay 0.1
 	{bone cut "glass%1"}
	}
	)
 	{on bullet_hit
 		{if volume "glass_front"
 			("break_glass_ml3000" args 1 _front)
 		else volume "glass_doorl"
 			("break_glass_ml3000" args 3 _doorl)
 		else volume "glass_doorr"
 			("break_glass_ml3000" args 3 _doorr)
 		else volume "glass_back"
 			("break_glass_ml3000" args 3 _back)
		}
 	}
} 

{"np_willys_mb car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/MB"	}
		{link_sound "engine"			"vehicle/engine/MB" 		}
		{link_sound "engine_end"		"vehicle/engine/MB_end" 	}
		{link_sound "exhaust"			"vehicle/engine/MB_up"		}
	}
	(define "break_glass_2"
 		{volumes "glass%1" disable bullet contact blast}
 		{spawn "glass_hit2" "glass%1" x}
 		{delay 0.1
 			{bone cut "glass%1"}
		}
	)
 	{on bullet_hit
 		{if volume "glass_front1"
 			("break_glass_2" args 1 _front1)
 		else volume "glass_front2"
 			("break_glass_2" args 1 _front2)
 		}
 	}
}

{"np_zis5art car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/blitz"	}
		{link_sound "engine"			"vehicle/engine/zis"   	}
		{link_sound "engine_end"		"vehicle/engine/zis_end"	}
		{link_sound "exhaust"			"vehicle/engine/zis_up"	}
	}
	(define "break_glass_zis"
	 	{volumes "glass%1" disable bullet contact blast}
	 	{spawn "glass_hit2" "glass%1" x}
	 	{delay 0.1
	 		{bone cut "glass%1"}
		}
	)
	{on bullet_hit
 		{if volume "glass_front"
 			("break_glass_zis" args 1 _front)
 		else volume "glass_doorleft"
 			("break_glass_zis" args 1 _doorleft)
 		else volume "glass_doorright"
 			("break_glass_zis" args 1 _doorright)
 		else volume "glass_back"
 			("break_glass_zis" args 1 _back)
		}
 	}
}
;-----------------Inf Wpn Unit Pack
{"gaz-aaa_4m car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/blitz"	}
		{link_sound "engine"			"vehicle/engine/zis"   	}
		{link_sound "engine_end"		"vehicle/engine/zis_end"	}
		{link_sound "exhaust"			"vehicle/engine/zis_up"	}
	}
}
{"gaz-mm_4m car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/blitz"	}
		{link_sound "engine"			"vehicle/engine/zis"   	}
		{link_sound "engine_end"		"vehicle/engine/zis_end"	}
		{link_sound "exhaust"			"vehicle/engine/zis_up"	}
	}
}
{"zis5_4m car"
	{on "add_movement_sound" overload
		{link_sound "move"				"vehicle/wheels/blitz"	}
		{link_sound "engine"			"vehicle/engine/zis"   	}
		{link_sound "engine_end"		"vehicle/engine/zis_end"	}
		{link_sound "exhaust"			"vehicle/engine/zis_up"	}
	}
}
;-----------------Inf Wpn Unit Pack
;-----------------Skr Unit Pack
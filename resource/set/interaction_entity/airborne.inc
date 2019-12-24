{"airborne"
;	{friction 0.2}
;	{restitution 0.01}
	{on spawn
		{link_sound "fall"				"vehicle/airborne/fw_deep"			}

		{add_view	"exhaust_dark_big"	"engine_exhaust"		"FXsmoke1"	}
		{add_view	"exhaust_dark_big"	"engine_exhaust" 		"FXsmoke2"	}
		{add_view	"exhaust_dark_big"	"engine_exhaust"		"FXsmoke3"	}
		{add_view	"exhaust_dark_big"	"engine_exhaust" 		"FXsmoke4"	}
		{add_view	"exhaust_dark_big"	"engine_exhaust"		"FXsmoke5"	}
		{add_view	"exhaust_dark_big"	"engine_exhaust" 		"FXsmoke6"	}
		{add_view	"exhaust_dark_big"	"engine_exhaust"		"FXsmoke7"	}
		{add_view	"exhaust_dark_big"	"engine_exhaust" 		"FXsmoke8"	}
		{call "init_gun"}
		{call "contact_watcher"}
		(mod "mp"
			{tags add "teamnone"}
		)
	}
	{on "usercontrol_onoff"
        {if not tagged "usercontrol"
        	{delay 0.5
        		{tags add "usercontrol"}
        	}
			{if tagged "cas"
				{tags remove "cas"}
				{tags add "ncas"}
			}
			{if tagged "ars"
				{tags remove "ars"}
				{tags add "nars"}
			}
			{if tagged "mtp"
				{tags remove "mtp"}
				{tags add "nmtp"}
			}
			{if tagged "tbb"
				{tags remove "tbb"}
				{tags add "ntbb"}
			}
        }
        {if tagged "usercontrol" 
        	{tags remove "usercontrol"}
			{delay 0.5
        		{tags add "delete_usercontrol"}
        	}
			{if tagged "ncas"
				{tags remove "ncas"}
				{tags add "cas"}
			}
			{if tagged "nars"
				{tags remove "nars"}
				{tags add "ars"}
			}
			{if tagged "nmtp"
				{tags remove "nmtp"}
				{tags add "mtp"}
			}
			{if tagged "ntbb"
				{tags remove "ntbb"}
				{tags add "tbb"}
			}
        		}
    	}
	{on "contact_watcher"
		{if operatable
			{if altitude 159
				{if not tagged "150m"
					{volumes disable contact} 
					{tags add "150m"}
					{tags remove "10m"}{tags remove "20m"}{tags remove "30m"}{tags remove "40m"}{tags remove "50m"}
					{tags remove "60m"}{tags remove "70m"}{tags remove "80m"}{tags remove "90m"}{tags remove "100m"}
					{tags remove "110m"}{tags remove "120m"}
					{tags remove "below10m"}					
				}
			else altitude 119
				{if not tagged "120m"
					{volumes disable contact} 
					{tags add "120m"}
					{tags remove "10m"}{tags remove "20m"}{tags remove "30m"}{tags remove "40m"}{tags remove "50m"}
					{tags remove "60m"}{tags remove "70m"}{tags remove "80m"}{tags remove "90m"}{tags remove "150m"}
					{tags remove "110m"}{tags remove "100m"}
					{tags remove "below10m"}
				}
			else altitude 109
				{if not tagged "110m"
					{volumes disable contact} 
					{tags add "110m"}
					{tags remove "10m"}{tags remove "20m"}{tags remove "30m"}{tags remove "40m"}{tags remove "50m"}
					{tags remove "60m"}{tags remove "70m"}{tags remove "80m"}{tags remove "90m"}{tags remove "150m"}
					{tags remove "100m"}{tags remove "120m"}
					{tags remove "below10m"}
				}
			else altitude 99
				{if not tagged "100m"
					{volumes disable contact} 
					{tags add "100m"}
					{tags remove "10m"}{tags remove "20m"}{tags remove "30m"}{tags remove "40m"}{tags remove "50m"}
					{tags remove "60m"}{tags remove "70m"}{tags remove "80m"}{tags remove "90m"}{tags remove "150m"}
					{tags remove "110m"}{tags remove "120m"}
					{tags remove "below10m"}
				}
			else altitude 89
				{if not tagged "90m"
					{volumes disable contact} 
					{tags add "90m"}
					{tags remove "10m"}{tags remove "20m"}{tags remove "30m"}{tags remove "40m"}{tags remove "50m"}
					{tags remove "60m"}{tags remove "70m"}{tags remove "80m"}{tags remove "150m"}{tags remove "100m"}
					{tags remove "110m"}{tags remove "120m"}
					{tags remove "below10m"}
				}
			else altitude 79
				{if not tagged "80m"
					{volumes disable contact} 
					{tags add "80m"}
					{tags remove "10m"}{tags remove "20m"}{tags remove "30m"}{tags remove "40m"}{tags remove "50m"}
					{tags remove "60m"}{tags remove "70m"}{tags remove "150m"}{tags remove "90m"}{tags remove "100m"}
					{tags remove "110m"}{tags remove "120m"}
					{tags remove "below10m"}
				}			
			else altitude 69
				{if not tagged "70m"
					{volumes disable contact} 
					{tags add "70m"}
					{tags remove "10m"}{tags remove "20m"}{tags remove "30m"}{tags remove "40m"}{tags remove "50m"}
					{tags remove "60m"}{tags remove "150m"}{tags remove "80m"}{tags remove "90m"}{tags remove "100m"}
					{tags remove "110m"}{tags remove "120m"}
					{tags remove "below10m"}
				}
			else altitude 59
				{if not tagged "60m"
					{volumes disable contact} 
					{tags add "60m"}
					{tags remove "10m"}{tags remove "20m"}{tags remove "30m"}{tags remove "40m"}{tags remove "50m"}
					{tags remove "150m"}{tags remove "70m"}{tags remove "80m"}{tags remove "90m"}{tags remove "100m"}
					{tags remove "110m"}{tags remove "120m"}
					{tags remove "below10m"}
				}
			else altitude 49
				{if not tagged "50m"
					{volumes disable contact} 
					{tags add "50m"}
					{tags remove "10m"}{tags remove "20m"}{tags remove "30m"}{tags remove "40m"}{tags remove "150m"}
					{tags remove "60m"}{tags remove "70m"}{tags remove "80m"}{tags remove "90m"}{tags remove "100m"}
					{tags remove "110m"}{tags remove "120m"}
					{tags remove "below10m"}
				}
			else altitude 39
				{if not tagged "40m"
					{volumes disable contact} 
					{tags add "40m"}
					{tags remove "10m"}{tags remove "20m"}{tags remove "30m"}{tags remove "150m"}{tags remove "50m"}
					{tags remove "60m"}{tags remove "70m"}{tags remove "80m"}{tags remove "90m"}{tags remove "100m"}
					{tags remove "110m"}{tags remove "120m"}
					{tags remove "below10m"}
				}
			else altitude 29
				{if not tagged "30m"
					{volumes disable contact} 
					{tags add "30m"}
					{tags remove "10m"}{tags remove "20m"}{tags remove "150m"}{tags remove "40m"}{tags remove "50m"}
					{tags remove "60m"}{tags remove "70m"}{tags remove "80m"}{tags remove "90m"}{tags remove "100m"}
					{tags remove "110m"}{tags remove "120m"}
					{tags remove "below10m"}
				}
			else altitude 19
				{if not tagged "20m"
					{volumes disable contact} 
					{tags add "20m"}
					{tags remove "10m"}{tags remove "150m"}{tags remove "30m"}{tags remove "40m"}{tags remove "50m"}
					{tags remove "60m"}{tags remove "70m"}{tags remove "80m"}{tags remove "90m"}{tags remove "100m"}
					{tags remove "110m"}{tags remove "120m"}
					{tags remove "below10m"}
				}						
			else altitude 5
				{if not tagged "10m"
					{volumes enable contact}
					{tags add "10m"}
					{tags remove "150m"}{tags remove "20m"}{tags remove "30m"}{tags remove "40m"}{tags remove "50m"}
					{tags remove "60m"}{tags remove "70m"}{tags remove "80m"}{tags remove "90m"}{tags remove "100m"}
					{tags remove "110m"}{tags remove "120m"}
					{tags remove "below10m"}
				}
			else
				{if not tagged "below10m"
					{volumes enable contact}
					{tags add "below10m"}
					{tags remove "10m"}{tags remove "20m"}{tags remove "30m"}{tags remove "40m"}{tags remove "50m"}
					{tags remove "60m"}{tags remove "70m"}{tags remove "80m"}{tags remove "90m"}{tags remove "100m"}
					{tags remove "110m"}{tags remove "120m"}
					{tags remove "150m"}
				}
			}
		else
			{volumes enable contact} 
		}
		{delay 0.01
			{call "contact_watcher"}
		}
	}
	{on "add_movement_sound"
		{link_sound "fly"				"vehicle/airborne/fw_move"			}
		{link_sound "engine_start"		"vehicle/airborne/fw_start"			}
		{link_sound "engine_work"		"vehicle/airborne/fw_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
	}
	{on "takeoff"
		{if not dead
			{ani_play "wheels" 0.2}
			{play_sound "fly" 1}
		}
	}
	{on "takeoff_load"
		{ani_wind "wheels" end}
	}
	{on "landing"
		{ani_play "wheels" -0.2}
		{stop_sound "fly"}
	}
	{on engine on overload
		{call "engine_on"}
	}
	{on animation_end "engine_start"
		{ani_play "engine_work" loop}
		{play_sound "engine_work" 1}
	}
	{on engine off overload
		{call "engine_stop"}
		{play_sound "engine_stop"}
	}
	{on "engine_on"
		{if not "engine_started"
			{set "engine_started" 1}
			{play_sound "engine_start"}
			{ani_play "engine_start" callback}
			{view start "engine_exhaust"}
			{delay 1
				{view pause "engine_exhaust"}
			}
		}
	}
	{on "update_moveable" overload
		{if not chassis "airborne"
			{inherited}
		}
	}
	{on "engine_stop"
		{kill_delay "engine_stopped"}
		{if "engine_started"
			{set "engine_started" 0}
			{ani_stop "engine_start"}
			{ani_stop "engine_work"}
			{ani_play "engine_stop"}
			{stop_sound "engine_start"}
			{stop_sound "engine_work"}
			{stop_sound "fly"}
		}
	}
	{on break_armor
		{if name "pierce"
			{if stuff "shell"
				{call "pierce"}
			else stuff "zenite"
				{if rand 0.8
					{call "pierce"}
				}
			}
		else name "blast"
			{if volume "body"
				{impulse up 1 0.5 dir 0.3 0.2}
				{call "explosion"}
			}
		}
	}
	{on "pierce"
		{if work
			{component break}
			{spawn "aero_die_particle"}
			{if volume "engine"
				{burn fx "smoke_aero_big" fake}
			else volume "body"
				{burn fx "smoke_aero_big" fake}
			else;volume "inflammable"
				{burn fx "smoke_aero_small" fake}
			}
		}
	}
	{on break
		{if chassis "airborne"
			{if component "body"
				{if tagged "fighter_aircraft"
					{delay 1
                        {crew_emit}
                    }
                    {delay 3
						{call "fall"}
					}
				else
					{call "fall"}
				}
			else component "engine"
				{if tagged "fighter_aircraft"
					{delay 1
                        {crew_emit}
                    }
                    {delay 3
						{call "fall"}
					}
				else
					{call "fall"}
				}
			}
		}
	}
	{on "fall"
		{if not "fall"
			{bone hide "engine_work"}
			{stop_sound "engine_work"}
			{stop_sound "fly"}
			{set "fall" 1}
			{impulse up 0.1 com}
			{explosive 1}
			{play_sound "fall"}
			{call "fall_fx"}
		}
	}
	{on "fall_fx"
		{delay 2
			{add_view "smoke_aero_dead_big" "fire" "body"}
			{view start "fire"}
			{delay 10
				{view stop "fire"}
			}
			{burn volume "body" fx "smoke_aero_big" time 10 fake}
			{burn volume "engine" fx "smoke_aero_big" time 10 fake}
			{delay 10.1
				{burn volume "body" fx "smoke_black" time 40 10 fake}
			}
;			{burn volume "wingr1" fx "smoke_aero_big" time 5 fake}
;			{burn volume "wingl1" fx "smoke_aero_big" time 5 fake}
		}
	}
	{on ground_hit
		{call "collide"}
		{delay 2.5 1
			{call "explosion"}
		}
	}
	{on contact overload
		{if effector "vehicle"
			{call "collide"}
		else effector "construction"
			{call "collide"}
		else effector "tree"
			{call "collide"}
		else effector "fence"
			{if volume "part"
				{call "tear_part"}
			}
		}
	}
	{on "collide"
		{if volume "body"
			{call "explosion"}
		else volume "part"
			{call "tear_part"}
		}
	}
	{on "tear_part"
		{spawn "spheredust_big_short"}
		{component destroy}
		{components "engine" destroy}
		{volume disable contact contact_ground}
		{chassis_work 0}
		{tear "piece_big_airborne_wing" bone from_volume
			{impulse up 2 1 dir 2 1}
		}
		{impulse up 0.1 com}
	}

	(define "burn_part"
		{on "burn_%0_start"
			{add_view "smoke_aero_big"		"fire%0" "fx_fire%0_1"}
			{add_view "smoke_aero_big"		"fire%0" "fx_fire%0_2"}
			{add_view "smoke_aero_big"		"fire%0" "fx_fire%0_3"}
			{add_view "smoke_aero_small"	"fire%0" "fx_smoke%0_1"}
			{add_view "smoke_aero_small"	"fire%0" "fx_smoke%0_2"}
			{add_view "smoke_aero_small"	"fire%0" "fx_smoke%0_3"}
			{view start "fire%0"}
		}
		{on "burn_%0_stop"
			{view stop "fire%0"}
		}
	)
	("burn_part" args 1)
	("burn_part" args 2)
	("burn_part" args 3)
	("burn_part" args 4)

	{on "die"
		{chassis_work 0}
		{drop_orders}
		{components destroy}
		{call "engine_stop"}
		{stop_sound "fall"}
		{stop_sound "engine_stop"}
		{explosive 0}
		{burn stop}
		{bone hide "engine_work"}
	}
	{on "_explosion" overload
		{kill_crew}
		{able select 0}
		{clear_inventory}
		{call "die"}
		{spawn "tank_die" "basis"}
		{add_view "aero_die" "fire" "body"}
		{add_view "aero_die_fire" "fire" "body"}
		{view start "fire"}
		{spawn "aero_die_particle"}
		{start_sound "crush/big/airborne"}
		{tags add "destroyed"}
		{tags remove "air"}

		{impulse up 0.1 com}
		{delay 0.1
			(define "cut_part"
				{if rand %1
					{tear "piece_big_airborne_wing" bone %0
						{impulse up 2 1 dir 2 1}
					}
				}
			)
			("cut_part" args "wingr1"		0.5)
			("cut_part" args "wingl1"		0.5)
			("cut_part" args "wingr2"		0.5)
			("cut_part" args "wingl2"		0.5)
			("cut_part" args "body_back"	0.5)
			("cut_part" args "propeller"	1.0)
			{volumes disable obstacle}
			{volumes "body" enable obstacle}
			{volumes "body_back" disable obstacle}
			{area rebuild}
		}
		{blastwave c4 7 r0 5 r1 8}
	}
	{on "spawn_bomb"
		{spawn "air_bomb_small"}
	}
	{on "kick"
		{impulse up 0.1 com}
	}
	{on "area_disable"
		{area disable}
	}
	{on "area_enable"
		{area enable}
	}
	{on "air_attack"
		{start_sound "vehicle/airborne/air_attack" ambient}
	}

	{on "init_gun"
		{add_view "flash_zenit"	"flashbarrel00"	"barrel00"}
		{add_view "flash_zenit"	"flashbarrel01"	"barrel01"}
		{add_view "flash_zenit"	"flashbarrel02"	"barrel02"}
		{add_view "flash_zenit"	"flashbarrel03"	"barrel03"}
		{add_view "flash_zenit"	"flashbarrel04"	"barrel04"}
	}
	{on fire "zenite"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{delay 0.42
					{view pause "flashbarrel%0"}
				}
		)
		
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		  else ("fire_barrel" args 04)
		}
	}

	{on fire "gun"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{delay 0.42
					{view pause "flashbarrel%0"}
				}
		)
		
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		  else ("fire_barrel" args 04)
		}
	}	
}

{"airborne no_explosion"
	{on contact
;		{components "wingleft" destroy}
;		{components "wingright" destroy}
	}
	{on ground_hit
		{call "die"}
		{impulse up 0.1 com}
	}
	{on "_explosion" overload
		{call "die"}
		{impulse up 0.1 com}
		("cut_part" args "wingr2"		0.5)
		("cut_part" args "wingl2"		0.5)
	}
	{on "fall_fx" overload
	}
}

{"air_part"
	{on spawn
		{delay 0.1
			{volumes enable contact contact_ground}
		}
		{view stop ""}
		{add_view "smoke_black" "smoke" "root"}
		{view start "smoke"}
		{delay 180 30
			{view stop "smoke"}
		}
	}
	{on ground_hit
		{if min_speed 5
			{spawn "spheredust_big_short"}
		}
	}
}

{"air_part wing"
	{on ground_hit
		{if volume "part"
			{if volume_bone_level 3
				{call "tear_part"}
			}
		}
	}
	{on "tear_part"
		{tear "piece_big_airborne_wing" bone from_volume
			{impulse up 0.1 0.05}
		}
	}
}

{"airborne P-51Mustang"
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/p51_move"			}
		{link_sound "engine_start"		"vehicle/airborne/p51_start"		}
		{link_sound "engine_work"		"vehicle/airborne/p51_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
	}
	{on "update_lights" overload}
}

{"airborne cg-4a"
	{on spawn
		{add_view	"smoke_plane"	"smoke01"		"fx_smoke01"}
		{add_view	"smoke_plane"	"smoke02"		"fx_smoke02"}
		{add_view	"smoke_plane"	"smoke03"		"fx_smoke03"}
		{add_view	"smoke_plane"	"smoke04"		"fx_smoke04"}
		{add_view	"smoke_plane"	"smoke05"		"fx_smoke05"}
		{add_view	"smoke_plane"	"smoke06"		"fx_smoke06"}
		{add_view	"smoke_plane"	"smoke07"		"fx_smoke07"}
		{add_view	"smoke_plane"	"smoke08"		"fx_smoke08"}
		{add_view	"smoke_plane"	"smoke09"		"fx_smoke09"}
		{add_view	"smoke_plane"	"smoke10"		"fx_smoke10"}
		{add_view	"smoke_plane"	"smoke11"		"fx_smoke11"}
		{add_view	"smoke_plane"	"smoke12"		"fx_smoke12"}
	}
	{on "tear_part"
		{view start "smoke01"}
		{view start "smoke02"}
		{view start "smoke03"}
		{view start "smoke04"}
		{view start "smoke05"}
		{view start "smoke06"}
		{view start "smoke07"}
		{view start "smoke08"}
		{view start "smoke09"}
		{view start "smoke10"}
		{view start "smoke11"}
		{view start "smoke12"}
	}
	{on "add_movement_sound" overload
;		{link_sound "fly"				"vehicle/airborne/cg_move"			}
		{link_sound "engine_start"		"vehicle/airborne/cg_start"			}
		{link_sound "engine_work"		"vehicle/airborne/cg"			}
;		{link_sound "engine_stop"		"vehicle/airborne/cg_stop"			}
	}
}

{"hamilcar"
	{on spawn
		{add_view	"smoke_plane"	"smoke01"		"fx_smoke01"}
		{add_view	"smoke_plane"	"smoke02"		"fx_smoke02"}
		{add_view	"smoke_plane"	"smoke03"		"fx_smoke03"}
		{add_view	"smoke_plane"	"smoke04"		"fx_smoke04"}
		{add_view	"smoke_plane"	"smoke05"		"fx_smoke05"}
		{add_view	"smoke_plane"	"smoke06"		"fx_smoke06"}
		{add_view	"smoke_plane"	"smoke07"		"fx_smoke07"}
		{add_view	"smoke_plane"	"smoke08"		"fx_smoke08"}
		{add_view	"smoke_plane"	"smoke09"		"fx_smoke09"}
		{add_view	"smoke_plane"	"smoke10"		"fx_smoke10"}
		{add_view	"smoke_plane"	"smoke11"		"fx_smoke11"}
		{add_view	"smoke_plane"	"smoke12"		"fx_smoke12"}
	}
	{on "tear_part"
		{view start "smoke01"}
		{view start "smoke02"}
		{view start "smoke03"}
		{view start "smoke04"}
		{view start "smoke05"}
		{view start "smoke06"}
		{view start "smoke07"}
		{view start "smoke08"}
		{view start "smoke09"}
		{view start "smoke10"}
		{view start "smoke11"}
		{view start "smoke12"}
	}
	{on "add_movement_sound" overload
;		{link_sound "fly"				"vehicle/airborne/cg_move"			}
		{link_sound "engine_start"		"vehicle/airborne/cg_start"			}
		{link_sound "engine_work"		"vehicle/airborne/cg"			}
;		{link_sound "engine_stop"		"vehicle/airborne/cg_stop"			}
	}
	{on "cut_wheels"
		{ani_play "drift"}
		("cut_part" args "wheell"		1.0)
		("cut_part" args "wheelr"		1.0)
		("cut_part" args "wheel_back"	1.0)
;		("cut_part" args "part2"		0.7)
		("cut_part" args "part3"		1.0)
		{add_view "spheredust_big" "ground_dust" "support1"}
		{add_view "spheredust_big" "ground_dust" "support2"}
		{view start "ground_dust"}
		{delay 4
			{view stop "ground_dust"}
		}
	}
}

{"il-2"
	{on "die"
		{bone hide "rocket00"}
		{bone hide "rocket01"}
		{bone hide "rocket02"}
		{bone hide "rocket03"}
		{bone hide "rocket04"}
		{bone hide "rocket05"}
		{bone hide "rocket06"}
		{bone hide "rocket07"}
		{bone hide "bomb00"}
		{bone hide "bomb01"}
	}
}

{"ju-87"
	{on "die"
		{bone hide "bomb00"}
		{bone hide "bomb01"}
		{bone hide "bomb02"}
		{bone hide "bomb03"}
	}
}

{"ju-52"
	{on "wheels_fx"
		{add_view "spheredust_big" "ground_dust" "support1"}
		{add_view "spheredust_big" "ground_dust" "support2"}
		{view start "ground_dust"}
		{delay 4
			{view stop "ground_dust"}
		}
	}
}


{"bomber"
	{on "init_gun" overload
		{add_view "flash_gun_big_vehicle" "shooter1_00" "shooter1_00"}
		{add_view "flash_gun_big_vehicle" "shooter1_01" "shooter1_01"}
		{add_view "flash_gun_big_vehicle" "shooter2_00" "shooter2_00"}
		{add_view "flash_gun_big_vehicle" "shooter2_01" "shooter2_01"}
		{add_view "flash_gun_big_vehicle" "shooter3_00" "shooter3_00"}
		{add_view "flash_gun_big_vehicle" "shooter3_01" "shooter3_01"}
		{add_view "flash_gun_big_vehicle" "shooter4_00" "shooter4_00"}
		{add_view "flash_gun_big_vehicle" "shooter4_01" "shooter4_01"}
	}
	(define "link_flash"
		{if name "mgun_linked%0"
			{if stuff "mgun"
				{add_view "flash_gun_big_vehicle" "flashbarrel%1" "Foresight%1"}
			}
		}
	)
	{on "link_weapon" overload
		("link_flash" args 1 5)
		("link_flash" args 2 6)
		("link_flash" args 3 7)
		("link_flash" args 4 8)
	}
	{on fire "mgun_linked1" {view start "flashbarrel5"} 
			{delay 0.5
				{view pause "flashbarrel5"}
			}
	}
	{on fire "mgun_linked2" {view start "flashbarrel6"}
			{delay 0.5
				{view pause "flashbarrel6"}
			}
	}
	{on fire "mgun_linked3" {view start "flashbarrel7"}
			{delay 0.5
				{view pause "flashbarrel7"}
			}
	}
	{on fire "mgun_linked4" {view start "flashbarrel8"}
			{delay 0.5
				{view pause "flashbarrel8"}
			}
	}

	(define "start_shooter_flash"
		{on fire "mgun_own%0"
			{if name "00"
				{view start "shooter%0_00"}
			}
			{if name "01"
				{view start "shooter%0_01"}
			}
		}
	)
	("start_shooter_flash" args 1)
	("start_shooter_flash" args 2)
	("start_shooter_flash" args 3)
	("start_shooter_flash" args 4)

	{on "_explosion" overload}

	{on "break_part"
		{if work
			{component break}
			{burn fx "smoke_aero_small" fake}
		else broken
			{component destroy}
			{spawn "aero_die_particle"}
			{if volume "engine"
				{tear "piece_medium_steel" bone from_volume
					{impulse up 1 0.5 dir 5 2 rnd_dir 3 no_position}
					{add_view "smoke_dead_wheel" "smoke" "basis"}
					{view start "smoke"}
					{delay_effect 20 5 "stop"}
				}
			}
		else destroyed
			{spawn "aero_die_particle"}
		}
	}

	{on "pierce" overload
		{if volume "engine"
			{call "break_part"}
		else volume "wing"
			{call "break_part"}
		else volume "body"
			{call "break_part"}
		else
			{inherited}
		}
	}
}
;----------------------------Normand Pack
{"ju-87_2"
	{on spawn
		{add_view	"flash_gun_big"	"flashbarrel00"	"shooter00"}
		{add_view	"flash_gun_big"	"flashbarrel01"	"shooter01"}
		{tags add "bomber_aircraft"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		)
	}
	{on fire "gun"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{delay 0.42
					{view pause "flashbarrel%0"}
				}
		)
		
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		 }
	}
}
{"ca101"
	{on spawn
		{tags add "transport_aircraft"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "die"
		{bone hide "bomb00"}
		{bone hide "bomb01"}
	}
}
{"li2"
	{on spawn
		{tags add "transport_aircraft"}
		{add_view	"smoke_plane"	"smoke01"		"fx_smoke01"}
		{add_view	"smoke_plane"	"smoke02"		"fx_smoke02"}
		{add_view	"smoke_plane"	"smoke03"		"fx_smoke03"}
		{add_view	"smoke_plane"	"smoke04"		"fx_smoke04"}
		{add_view	"smoke_plane"	"smoke05"		"fx_smoke05"}
		{add_view	"smoke_plane"	"smoke06"		"fx_smoke06"}
		{add_view	"smoke_plane"	"smoke07"		"fx_smoke07"}
		{add_view	"smoke_plane"	"smoke08"		"fx_smoke08"}
		{add_view	"smoke_plane"	"smoke09"		"fx_smoke09"}
		{add_view	"smoke_plane"	"smoke10"		"fx_smoke10"}
		{add_view	"smoke_plane"	"smoke11"		"fx_smoke11"}
		{add_view	"smoke_plane"	"smoke12"		"fx_smoke12"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}

	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/c47_move"	}
		{link_sound "engine_start"		"vehicle/airborne/c47_start"	}
		{link_sound "engine_work"		"vehicle/airborne/c47_work"	}
		{link_sound "engine_stop"		"vehicle/airborne/c47_stop"	}
	}
}
{"c-47"
	{on spawn
		{tags add "transport_aircraft"}
		{add_view	"smoke_plane"	"smoke01"		"fx_smoke01"}
		{add_view	"smoke_plane"	"smoke02"		"fx_smoke02"}
		{add_view	"smoke_plane"	"smoke03"		"fx_smoke03"}
		{add_view	"smoke_plane"	"smoke04"		"fx_smoke04"}
		{add_view	"smoke_plane"	"smoke05"		"fx_smoke05"}
		{add_view	"smoke_plane"	"smoke06"		"fx_smoke06"}
		{add_view	"smoke_plane"	"smoke07"		"fx_smoke07"}
		{add_view	"smoke_plane"	"smoke08"		"fx_smoke08"}
		{add_view	"smoke_plane"	"smoke09"		"fx_smoke09"}
		{add_view	"smoke_plane"	"smoke10"		"fx_smoke10"}
		{add_view	"smoke_plane"	"smoke11"		"fx_smoke11"}
		{add_view	"smoke_plane"	"smoke12"		"fx_smoke12"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "tear_part"
		{view start "smoke01"}
		{view start "smoke02"}
		{view start "smoke03"}
		{view start "smoke04"}
		{view start "smoke05"}
		{view start "smoke06"}
		{view start "smoke07"}
		{view start "smoke08"}
		{view start "smoke09"}
		{view start "smoke10"}
		{view start "smoke11"}
		{view start "smoke12"}
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/c47_move"	}
		{link_sound "engine_start"		"vehicle/airborne/c47_start"	}
		{link_sound "engine_work"		"vehicle/airborne/c47_work"	}
		{link_sound "engine_stop"		"vehicle/airborne/c47_stop"	}
	}
}
{"c-47e"
	{on spawn
		{tags add "transport_aircraft"}
		{add_view	"smoke_plane"	"smoke01"		"fx_smoke01"}
		{add_view	"smoke_plane"	"smoke02"		"fx_smoke02"}
		{add_view	"smoke_plane"	"smoke03"		"fx_smoke03"}
		{add_view	"smoke_plane"	"smoke04"		"fx_smoke04"}
		{add_view	"smoke_plane"	"smoke05"		"fx_smoke05"}
		{add_view	"smoke_plane"	"smoke06"		"fx_smoke06"}
		{add_view	"smoke_plane"	"smoke07"		"fx_smoke07"}
		{add_view	"smoke_plane"	"smoke08"		"fx_smoke08"}
		{add_view	"smoke_plane"	"smoke09"		"fx_smoke09"}
		{add_view	"smoke_plane"	"smoke10"		"fx_smoke10"}
		{add_view	"smoke_plane"	"smoke11"		"fx_smoke11"}
		{add_view	"smoke_plane"	"smoke12"		"fx_smoke12"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "tear_part"
		{view start "smoke01"}
		{view start "smoke02"}
		{view start "smoke03"}
		{view start "smoke04"}
		{view start "smoke05"}
		{view start "smoke06"}
		{view start "smoke07"}
		{view start "smoke08"}
		{view start "smoke09"}
		{view start "smoke10"}
		{view start "smoke11"}
		{view start "smoke12"}
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/c47_move"	}
		{link_sound "engine_start"		"vehicle/airborne/c47_start"	}
		{link_sound "engine_work"		"vehicle/airborne/c47_work"	}
		{link_sound "engine_stop"		"vehicle/airborne/c47_stop"	}
	}
}
{"l2d3"
	{on spawn
		{tags add "transport_aircraft"}
		{add_view	"smoke_plane"	"smoke01"		"fx_smoke01"}
		{add_view	"smoke_plane"	"smoke02"		"fx_smoke02"}
		{add_view	"smoke_plane"	"smoke03"		"fx_smoke03"}
		{add_view	"smoke_plane"	"smoke04"		"fx_smoke04"}
		{add_view	"smoke_plane"	"smoke05"		"fx_smoke05"}
		{add_view	"smoke_plane"	"smoke06"		"fx_smoke06"}
		{add_view	"smoke_plane"	"smoke07"		"fx_smoke07"}
		{add_view	"smoke_plane"	"smoke08"		"fx_smoke08"}
		{add_view	"smoke_plane"	"smoke09"		"fx_smoke09"}
		{add_view	"smoke_plane"	"smoke10"		"fx_smoke10"}
		{add_view	"smoke_plane"	"smoke11"		"fx_smoke11"}
		{add_view	"smoke_plane"	"smoke12"		"fx_smoke12"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "tear_part"
		{view start "smoke01"}
		{view start "smoke02"}
		{view start "smoke03"}
		{view start "smoke04"}
		{view start "smoke05"}
		{view start "smoke06"}
		{view start "smoke07"}
		{view start "smoke08"}
		{view start "smoke09"}
		{view start "smoke10"}
		{view start "smoke11"}
		{view start "smoke12"}
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/c47_move"	}
		{link_sound "engine_start"		"vehicle/airborne/c47_start"	}
		{link_sound "engine_work"		"vehicle/airborne/c47_work"	}
		{link_sound "engine_stop"		"vehicle/airborne/c47_stop"	}
	}
}
{"ju-52g"
	{on spawn
		{tags add "transport_aircraft"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "wheels_fx"
		{add_view "spheredust_big" "ground_dust" "support1"}
		{add_view "spheredust_big" "ground_dust" "support2"}
		{view start "ground_dust"}
		{delay 4
			{view stop "ground_dust"}
		}
	}
}
{"ju-52f"
	{on spawn
		{tags add "transport_aircraft"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "wheels_fx"
		{add_view "spheredust_big" "ground_dust" "support1"}
		{add_view "spheredust_big" "ground_dust" "support2"}
		{view start "ground_dust"}
		{delay 4
			{view stop "ground_dust"}
		}
	}
}
{"ju-52i"
	{on spawn
		{tags add "transport_aircraft"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "wheels_fx"
		{add_view "spheredust_big" "ground_dust" "support1"}
		{add_view "spheredust_big" "ground_dust" "support2"}
		{view start "ground_dust"}
		{delay 4
			{view stop "ground_dust"}
		}
	}
}
{"tb-3"
	{on spawn
		{tags add "transport_aircraft"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/c47_move"	}
		{link_sound "engine_start"		"vehicle/airborne/c47_start"	}
		{link_sound "engine_work"		"vehicle/airborne/c47_work"	}
		{link_sound "engine_stop"		"vehicle/airborne/c47_stop"	}
	}
	{on "update_lights" overload}
}
{"fw190f8"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "ars"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/fw190/fw190_move"		}
		{link_sound "engine_start"		"vehicle/airborne/fw190/fw190_start"		}
		{link_sound "engine_work"		"vehicle/airborne/fw190/fw190_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/fw190/fw190_stop"		}
		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on "update_lights" overload}
	{on fire "mgun"
		{play_sound "rocket_ambience"}
	}
}
{"fw190f8_hun"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "ars"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/fw190/fw190_move"		}
		{link_sound "engine_start"		"vehicle/airborne/fw190/fw190_start"		}
		{link_sound "engine_work"		"vehicle/airborne/fw190/fw190_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/fw190/fw190_stop"		}
		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on "update_lights" overload}
	{on fire "mgun"
		{play_sound "rocket_ambience"}
	}
}
{"i-16"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "ars"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/i16_work"			}
		{link_sound "engine_start"		"vehicle/airborne/i16_start"		}
		{link_sound "engine_work"		"vehicle/airborne/i16_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/i16_stop"			}
		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on "update_lights" overload}
}
{"i-16_ru"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "mtp"}
		{tags add "hasATR"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/i16_work"			}
		{link_sound "engine_start"		"vehicle/airborne/i16_start"		}
		{link_sound "engine_work"		"vehicle/airborne/i16_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/i16_stop"			}
		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on fire "atr" 
		{if not tagged "atrrunout"
			{if not tagged "atrfire1"
				{tags add "atrfire1"}
				{bone hide "rocket00"}
			else not tagged "atrfire2"
				{tags add "atrfire2"}
				{bone hide "rocket01"}
			else not tagged "atrfire3"
				{tags add "atrfire3"}
				{bone hide "rocket02"}
			else not tagged "atrfire4"
				{tags add "atrfire4"}
				{bone hide "rocket03"}
			else not tagged "atrfire5"
				{tags add "atrfire5"}
				{bone hide "rocket04"}
			else not tagged "atrfire6"
				{tags add "atrfire6"}
			else not tagged "atrfire7"
				{tags add "atrfire7"}
			else 
				{tags add "atrrunout"} 
				{tags remove "atrfire1"}
				{tags remove "atrfire2"}
				{tags remove "atrfire3"}
				{tags remove "atrfire4"}
				{tags remove "atrfire5"}
				{tags remove "atrfire6"}
				{tags remove "atrfire7"}
				{tags remove "hasATR"}
				{bone hide "rocket05"}
				{tear "missionwp" bone "sp_rot" 
					{delete}
				}
			}
		}
	}
	{on "update_lights" overload}
}
{"mk3mustang"
	{on spawn
		{tags add  "cas"}
		{tags add "bomber_aircraft"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		)
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/p51_move"			}
		{link_sound "engine_start"		"vehicle/airborne/p51_start"		}
		{link_sound "engine_work"		"vehicle/airborne/p51_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
	}
	{on "update_lights" overload}
}
{"a6m5"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "mtp"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "init_gun"
		{add_view "flash_zenit"	"shooter00" "placement"}
		{add_view "flash_zenit"	"shooter01" "placement"}
		{add_view "flash_gun_big" "shooter02" "gearl"}
		{add_view "flash_gun_big" "shooter03" "gearr"}
	}
	{on fire "gun"
		(define "fire_barrel"
			name "%0"
				{view start "placement%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "placement%0"}
				}
		)

		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		}
	}
}
{"la5fn"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "ars"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/p51_move"			}
		{link_sound "engine_start"		"vehicle/airborne/p51_start"		}
		{link_sound "engine_work"		"vehicle/airborne/p51_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
	}
	{on "update_lights" overload}
	
}
{"bf109"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "ars"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/bf109d_move"			}
		{link_sound "engine_start"		"vehicle/airborne/bf109d_start"		}
		{link_sound "engine_work"		"vehicle/airborne/bf109d_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
	}
	{on "update_lights" overload}
	
}
{"bf109g_fin"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "ars"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/bf109d_move"			}
		{link_sound "engine_start"		"vehicle/airborne/bf109d_start"		}
		{link_sound "engine_work"		"vehicle/airborne/bf109d_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
	}
	{on "update_lights" overload}
	
}
{"p51mustang"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "ars"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/p51_move"			}
		{link_sound "engine_start"		"vehicle/airborne/p51_start"		}
		{link_sound "engine_work"		"vehicle/airborne/p51_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
	}
	{on "update_lights" overload}
}
{"mc_205"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "ars"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/p51_move"			}
		{link_sound "engine_start"		"vehicle/airborne/p51_start"		}
		{link_sound "engine_work"		"vehicle/airborne/p51_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
	}
	{on "update_lights" overload}
}
{"spitfiremk1a"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "ars"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/spitfire/spitfire_move"		}
		{link_sound "engine_start"		"vehicle/airborne/spitfire/spitfire_start"		}
		{link_sound "engine_work"		"vehicle/airborne/spitfire/spitfire_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/spitfire/spitfire_stop"		}
	}
	{on "update_lights" overload}
}
{"spitfiremk1a_fra"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "ars"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/spitfire/spitfire_move"		}
		{link_sound "engine_start"		"vehicle/airborne/spitfire/spitfire_start"		}
		{link_sound "engine_work"		"vehicle/airborne/spitfire/spitfire_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/spitfire/spitfire_stop"		}
	}
	{on "update_lights" overload}
}
{"bf109g_rom"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "ars"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/bf109d_move"			}
		{link_sound "engine_start"		"vehicle/airborne/bf109d_start"		}
		{link_sound "engine_work"		"vehicle/airborne/bf109d_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
	}
	{on "update_lights" overload}
	
}
{"pzlp11"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "ars"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "init_gun"
		{add_view "flash_zenit"	"shooter00" "placement"}
		{add_view "flash_zenit"	"shooter01" "placement"}
		{add_view "flash_zenit" 	"shooter02" "gearl"}
		{add_view "flash_zenit" 	"shooter03" "gearr"}
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/i16_work"			}
		{link_sound "engine_start"		"vehicle/airborne/i16_start"		}
		{link_sound "engine_work"		"vehicle/airborne/i16_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/i16_stop"			}
		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on "update_lights" overload}
	{on fire "gun"
		(define "fire_barrel"
			name "%0"
				{view start "placement%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "placement%0"}
				}
		)

		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		}
	}
}
{"pzlp11_grc"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "ars"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "init_gun"
		{add_view "flash_zenit"	"shooter00" "placement"}
		{add_view "flash_zenit"	"shooter01" "placement"}
		{add_view "flash_zenit" 	"shooter02" "gearl"}
		{add_view "flash_zenit" 	"shooter03" "gearr"}
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/i16_work"			}
		{link_sound "engine_start"		"vehicle/airborne/i16_start"		}
		{link_sound "engine_work"		"vehicle/airborne/i16_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/i16_stop"			}
		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on "update_lights" overload}
	{on fire "gun"
		(define "fire_barrel"
			name "%0"
				{view start "placement%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "placement%0"}
				}
		)

		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		}
	}
}
{"airborne p-51mustang_b"
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/p51_move"			}
		{link_sound "engine_start"		"vehicle/airborne/p51_start"		}
		{link_sound "engine_work"		"vehicle/airborne/p51_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
	}
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		(mod "mp"
			{tags add "aircraft"}
			
			{call "engine_on"}
		)
	}
	{on "update_lights" overload}
}
{"il-2_b"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		(mod "mp"
			{tags add "aircraft"}
			
			{call "engine_on"}
		)
	}
	{on "die"
		{bone hide "rocket00"}
		{bone hide "rocket01"}
		{bone hide "rocket02"}
		{bone hide "rocket03"}
		{bone hide "rocket04"}
		{bone hide "rocket05"}
		{bone hide "rocket06"}
		{bone hide "rocket07"}
		{bone hide "bomb00"}
		{bone hide "bomb01"}
	}
}
{"ju-87_b"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		)
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/ju-87_w"		}
		{link_sound "engine_start"		"vehicle/airborne/ju87g2/ju87g2_start"		}
		{link_sound "engine_work"		"vehicle/airborne/ju87g2/ju87g2_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/ju87g2/ju87g2_stop"		}
		{link_sound "diving"		"vehicle/airborne/ju87g2/ju87d/ju87d"		}
	}
	{on "die"
		{bone hide "bomb00"}
		{bone hide "bomb01"}
		{bone hide "bomb02"}
		{bone hide "bomb03"}
	}
}
{"ju-87_hun"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		)
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/ju-87_w"		}
		{link_sound "engine_start"		"vehicle/airborne/ju87g2/ju87g2_start"		}
		{link_sound "engine_work"		"vehicle/airborne/ju87g2/ju87g2_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/ju87g2/ju87g2_stop"		}
		{link_sound "diving"		"vehicle/airborne/ju87g2/ju87d/ju87d"		}
	}
	{on "die"
		{bone hide "bomb00"}
		{bone hide "bomb01"}
		{bone hide "bomb02"}
		{bone hide "bomb03"}
	}
}
{"ju-87_rom"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		)
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/ju-87_w"		}
		{link_sound "engine_start"		"vehicle/airborne/ju87g2/ju87g2_start"		}
		{link_sound "engine_work"		"vehicle/airborne/ju87g2/ju87g2_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/ju87g2/ju87g2_stop"		}
		{link_sound "diving"		"vehicle/airborne/ju87g2/ju87d/ju87d"		}
	}
	{on "die"
		{bone hide "bomb00"}
		{bone hide "bomb01"}
		{bone hide "bomb02"}
		{bone hide "bomb03"}
	}
}
{"ju-87_ita"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		)
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/ju-87_w"		}
		{link_sound "engine_start"		"vehicle/airborne/ju87g2/ju87g2_start"		}
		{link_sound "engine_work"		"vehicle/airborne/ju87g2/ju87g2_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/ju87g2/ju87g2_stop"		}
		{link_sound "diving"		"vehicle/airborne/ju87g2/ju87d/ju87d"		}
	}
	{on "die"
		{bone hide "bomb00"}
		{bone hide "bomb01"}
		{bone hide "bomb02"}
		{bone hide "bomb03"}
	}
}
{"a6m_m21_86_b"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		)
	}
	{on "init_gun"
		{add_view "flash_zenit"	"shooter00" "placement"}
		{add_view "flash_zenit"	"shooter01" "placement"}
		{add_view "flash_gun_big" "shooter02" "gearl"}
		{add_view "flash_gun_big" "shooter03" "gearr"}
	}
	{on fire "gun"
		(define "fire_barrel"
			name "%0"
				{view start "placement%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "placement%0"}
				}
		)

		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		}
	}
}
{"bf109g_bul"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "ars"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/bf109d_move"			}
		{link_sound "engine_start"		"vehicle/airborne/bf109d_start"		}
		{link_sound "engine_work"		"vehicle/airborne/bf109d_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
	}
	{on "update_lights" overload}
	
}
{"bf109g_b"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "ars"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/bf109d_move"			}
		{link_sound "engine_start"		"vehicle/airborne/bf109d_start"		}
		{link_sound "engine_work"		"vehicle/airborne/bf109d_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
	}
	{on "update_lights" overload}
	
}
{"ju-87_bul"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		)
	}
	{on "die"
		{bone hide "bomb00"}
		{bone hide "bomb01"}
		{bone hide "bomb02"}
		{bone hide "bomb03"}
	}
}
{"il-2_nkr"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		)
	}
	{on "die"
		{bone hide "rocket00"}
		{bone hide "rocket01"}
		{bone hide "rocket02"}
		{bone hide "rocket03"}
		{bone hide "rocket04"}
		{bone hide "rocket05"}
		{bone hide "rocket06"}
		{bone hide "rocket07"}
		{bone hide "bomb00"}
		{bone hide "bomb01"}
	}
}
{"ground_target_flaer"
	{on spawn
		{add_view "smoke_yellow_small"	"smoke1" "basis"}
		{add_view "smoke_yellow_norm"	"smoke2" "basis"}
		{add_view "smoke_yellow_big"	"smoke3" "basis"}
		{delay 0.01
			{tags add "smoketarget"}
			{view start "smoke1"}
		}
		{delay 0.1
			{view start "smoke2"}
		}
		{delay 1
			{view start "smoke3"}
		}
		{delay 40
			{hide 8}
			{delay 8
				{delete}
			}
		}
	}
	{on "wait3sdelete"
		{delay 20
			{hide 4}
			{delay 4
				{delete}
			}
		}
	}
}
{"airborne hurricane23"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/p51_move"			}
		{link_sound "engine_start"		"vehicle/airborne/p51_start"		}
		{link_sound "engine_work"		"vehicle/airborne/p51_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
		{tags add "bomber_aircraft"}
	}
	{on "update_lights" overload}
	{on fire "atr" 
		{if not tagged "atrrunout"
			{if not tagged "atrfire1"
				{tags add "atrfire1"}
				{bone hide "rocket00"}
			else not tagged "atrfire2"
				{tags add "atrfire2"}
				{bone hide "rocket01"}
			else not tagged "atrfire3"
				{tags add "atrfire3"}
				{bone hide "rocket02"}
			else not tagged "atrfire4"
				{tags add "atrfire4"}
				{bone hide "rocket03"}
			else not tagged "atrfire5"
				{tags add "atrfire5"}
				{bone hide "rocket04"}
			else 
				{tags add "atrrunout"} ;6 rnds
				{tags remove "atrfire1"}
				{tags remove "atrfire2"}
				{tags remove "atrfire3"}
				{tags remove "atrfire4"}
				{tags remove "atrfire5"}
				{tags remove "atrfire6"}
				{tags remove "hasATR"}
				{bone hide "rocket05"}
				;{weapon_work "atr" 0}
				;{bone hide "sp_rot"}
				{tear "missionwp" bone "sp_rot" ;delete Rocketlanucher
					{delete}
				}
			}
		}
	}

}
{"pzlp23"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add "cas"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/i16_work"			}
		{link_sound "engine_start"		"vehicle/airborne/i16_start"		}
		{link_sound "engine_work"		"vehicle/airborne/i16_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/i16_stop"			}
		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on "update_lights" overload}
}
{"pzlp23_rom"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add "mtp"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/i16_work"			}
		{link_sound "engine_start"		"vehicle/airborne/i16_start"		}
		{link_sound "engine_work"		"vehicle/airborne/i16_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/i16_stop"			}
		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on "update_lights" overload}
}
{"potez633"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/fw190/fw190_move"		}
		{link_sound "engine_start"		"vehicle/airborne/fw190/fw190_start"		}
		{link_sound "engine_work"		"vehicle/airborne/fw190/fw190_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/fw190/fw190_stop"		}
		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on "update_lights" overload}
}
{"potez633_grc"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/fw190/fw190_move"		}
		{link_sound "engine_start"		"vehicle/airborne/fw190/fw190_start"		}
		{link_sound "engine_work"		"vehicle/airborne/fw190/fw190_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/fw190/fw190_stop"		}
		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on "update_lights" overload}
}
{"cr42"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "mtp"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/i16_work"			}
		{link_sound "engine_start"		"vehicle/airborne/i16_start"		}
		{link_sound "engine_work"		"vehicle/airborne/i16_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/i16_stop"			}
		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on "update_lights" overload}
}
{"ju87g2"
;		{add_view "flash_zenit"	"flashbarrel00"	"shooter00"}
;		{add_view "flash_zenit"	"flashbarrel01"	"shooter01"}
	{on spawn
		{add_view	"flash_zenite"	"flashbarrel_m00"	"shooter_m00"} 
		{add_view	"flash_zenite"	"flashbarrel_m01"	"shooter_m01"}
		{add_view	"flash_zenite"	"flashbarrel_z00"	"shooter_z00"}
		{add_view	"flash_zenite"	"flashbarrel_z01"	"shooter_z01"}
		{add_view	"flash_gun_big"	"flashbarrel_g00"	"shooter_g00"}
		{add_view	"flash_gun_big"	"flashbarrel_g01"	"shooter_g01"}
		{add_view	"powdersmoke_big"	"flashbarrel0s"	"shooter_m00"}
		{add_view	"powdersmoke_big"	"flashbarrel1s"	"shooter_m01"}
		{tags add "bomber_aircraft"}
		{tags add "mtp"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		)
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/ju87g2/ju87g2_move"		}
		{link_sound "engine_start"		"vehicle/airborne/ju87g2/ju87g2_start"		}
		{link_sound "engine_work"		"vehicle/airborne/ju87g2/ju87g2_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/ju87g2/ju87g2_stop"		}
		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on fire "mgun"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel_z%0"}
				{delay 0.42
					{view pause "flashbarrel_z%0"}
				}
		)
		
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun_hull"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel_m0%0"}
				{view start "flashbarrel%0s"}
				{delay 0.42
					{view pause "flashbarrel_m0%0"}
				}
				{delay 0.5
					{view pause "flashbarrel%0s"}
				}
		)
		
		{if    ("fire_barrel" args 0)
		  else ("fire_barrel" args 1)
		}
	}
	{on fire "gun"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel_g%0"}
				{delay 0.42
					{view pause "flashbarrel_g%0"}
				}
		)
		
		{if    ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		}
	}
}
{"p-39"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "ars"}
		{add_view "flash_zenit"	"flashbarrel00"	"shooter00"}
		{add_view "flash_zenit"	"flashbarrel01"	"shooter01"}
		{add_view "light_flash_zenit"	"flashbarrel02"	"shooter02"}
		{add_view "light_flash_zenit"	"flashbarrel03"	"shooter03"}
		{add_view "light_flash_zenit"	"flashbarrel04"	"shooter04"}
		{add_view "light_flash_zenit"	"flashbarrel05"	"shooter05"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/p39_move"			}
		{link_sound "engine_start"		"vehicle/airborne/bf109d_start"		}
		{link_sound "engine_work"		"vehicle/airborne/p39_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
	}
	{on animation_end "engine_start"
		{bone hide "propeller"}
		{ani_play "engine_work" loop}
		{play_sound "engine_work" 1}
	}
	{on "engine_stop"
		{kill_delay "engine_stopped"}
		{if "engine_started"
			{set "engine_started" 0}
			{ani_stop "engine_start"}
			{ani_stop "engine_work"}
			{bone show "propeller"}
			{ani_play "engine_stop"}
			{stop_sound "engine_start"}
			{stop_sound "engine_work"}
			{stop_sound "fly"}
		}
	}
	{on "update_lights" overload}
	{on fire "mgun"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun1"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		  else ("fire_barrel" args 04)
		  else ("fire_barrel" args 05)
		}
	}
}
{"p-39_ru"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "ars"}
		{add_view "flash_zenit"	"flashbarrel00"	"shooter00"}
		{add_view "flash_zenit"	"flashbarrel01"	"shooter01"}
		{add_view "light_flash_zenit"	"flashbarrel02"	"shooter02"}
		{add_view "light_flash_zenit"	"flashbarrel03"	"shooter03"}
		{add_view "light_flash_zenit"	"flashbarrel04"	"shooter04"}
		{add_view "light_flash_zenit"	"flashbarrel05"	"shooter05"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/p39_move"			}
		{link_sound "engine_start"		"vehicle/airborne/bf109d_start"		}
		{link_sound "engine_work"		"vehicle/airborne/p39_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
	}
	{on animation_end "engine_start"
		{ani_play "engine_work" loop}
		{bone hide "propeller"}
		{play_sound "engine_work" 1}
	}
	{on "engine_stop"
		{kill_delay "engine_stopped"}
		{if "engine_started"
			{set "engine_started" 0}
			{ani_stop "engine_start"}
			{ani_stop "engine_work"}
			{bone show "propeller"}
			{ani_play "engine_stop"}
			{stop_sound "engine_start"}
			{stop_sound "engine_work"}
			{stop_sound "fly"}
		}
	}
	{on "update_lights" overload}
	{on fire "mgun"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun1"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		  else ("fire_barrel" args 04)
		  else ("fire_barrel" args 05)
		}
	}
	
}
{"pe2"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/fw190/fw190_move"		}
		{link_sound "engine_start"		"vehicle/airborne/fw190/fw190_start"		}
		{link_sound "engine_work"		"vehicle/airborne/fw190/fw190_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/fw190/fw190_stop"		}
		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on "update_lights" overload}
	
	{on "init_gun"
		{add_view "flash_zenit"	"flashbarrel00"	"shooter00"}
		{add_view "flash_zenit"	"flashbarrel01"	"shooter01"}
	}
	{on fire "gun"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
}
{"db-3"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/fw190/fw190_move"		}
		{link_sound "engine_start"		"vehicle/airborne/fw190/fw190_start"		}
		{link_sound "engine_work"		"vehicle/airborne/fw190/fw190_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/fw190/fw190_stop"		}
		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on "update_lights" overload}
}
{"bf110"
	{on spawn
		{tags add "bomber_aircraft"}
		{add_view "flash_zenit"	"flashbarrel00"	"shooter00"}
		{add_view "flash_zenit"	"flashbarrel01"	"shooter01"}
		{tags add  "cas"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/fw190/fw190_move"		}
		{link_sound "engine_start"		"vehicle/airborne/fw190/fw190_start"		}
		{link_sound "engine_work"		"vehicle/airborne/fw190/fw190_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/fw190/fw190_stop"		}
;		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on "update_lights" overload}
	{on fire "mgun"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
}
{"j2m_rs"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "mtp"}
		{add_view "flash_zenit"	"flashbarrel00"	"shooter00"}
		{add_view "flash_zenit"	"flashbarrel01"	"shooter01"}
		{add_view "flash_zenit"	"flashbarrel02"	"shooter02"}
		{add_view "flash_zenit"	"flashbarrel03"	"shooter03"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on fire "gun"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		}
	}
	{on fire "bomb" 
		{if not tagged "bombrunout"
			{if not tagged "bomb1"
				{tags add "bomb1"}
				{bone hide "rocket00"}
			else not tagged "bomb2"
				{tags add "bomb2"}
				{bone hide "rocket01"}
			else not tagged "bomb3"
				{tags add "bomb3"}
				{bone hide "rocket02"}
			else not tagged "bomb4"
				{tags add "bomb4"}
				{bone hide "rocket03"}
			else not tagged "bomb5"
				{tags add "bomb5"}
				{bone hide "rocket04"}
			else not tagged "bomb6"
				{tags add "bomb6"}
				{bone hide "rocket05"}
			else not tagged "bomb7"
				{tags add "bomb7"}
				{bone hide "rocket06"}
			else 
				{tags add "bombrunout"} ;8 
				{tags remove "bomb1"}
				{tags remove "bomb2"}
				{tags remove "bomb3"}
				{tags remove "bomb4"}
				{tags remove "bomb5"}
				{tags remove "bomb6"}
				{tags remove "bomb7"}
				{bone hide "rocket07"}
			}
		}
	}
	{on "die"
		{bone hide "rocket00"}
		{bone hide "rocket01"}
		{bone hide "rocket02"}
		{bone hide "rocket03"}
		{bone hide "rocket04"}
		{bone hide "rocket05"}
		{bone hide "rocket06"}
		{bone hide "rocket07"}
	}
}
{"he111"
	{on spawn
		{tags add "bomber_aircraft"}
		{add_view "flash_zenit"	"flashbarrel00"	"shooter00"}
		{add_view "flash_zenit"	"flashbarrel01"	"shooter01"}
		{tags add  "cas"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/he111/he111_move"		}
		{link_sound "engine_start"		"vehicle/airborne/he111/he111_start"		}
		{link_sound "engine_work"		"vehicle/airborne/he111/he111_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/he111/he111_stop"		}
		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on "update_lights" overload}
	{on move off overload
		{bone hide "propeller_work1"}
		{bone hide "propeller_work2"}
	}
	{on move on overload
		{bone show "propeller_work1"}
		{bone show "propeller_work2"}
	}
	{on fire "mgun"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
}
{"f4f"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "ars"}
		{add_view "flash_zenit"	"flashbarrel00"	"shooter00"}
		{add_view "flash_zenit"	"flashbarrel01"	"shooter01"}
		{add_view "flash_zenit"	"flashbarrel02"	"shooter02"}
		{add_view "flash_zenit"	"flashbarrel03"	"shooter03"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		)
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/p51_move"			}
		{link_sound "engine_start"		"vehicle/airborne/p51_start"		}
		{link_sound "engine_work"		"vehicle/airborne/p51_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
	}
	{on "update_lights" overload}
	{on move off overload
		{bone hide "propeller_work"}
	}
	{on move on overload
		{bone show "propeller_work"}
	}
	{on fire "gun"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		}
	}
}
{"b25"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		{add_view "flash_zenit"	"flashbarrel1m00"	"shooter1m00"}
		{add_view "flash_zenit"	"flashbarrel1m01"	"shooter1m01"}
		{add_view "flash_zenit"	"flashbarrel1m02"	"shooter1m02"}
		{add_view "flash_zenit"	"flashbarrel1m03"	"shooter1m03"}
		{add_view "flash_zenit"	"flashbarrel2m00"	"shooter2m00"}
		{add_view "flash_zenit"	"flashbarrel2m01"	"shooter2m01"}
		{add_view "flash_zenit"	"flashbarrel3m00"	"shooter3m00"}
		{add_view "flash_zenit"	"flashbarrel3m01"	"shooter3m01"}
		{add_view "flash_zenit"	"flashbarrel54"	"foresight54"}
		{add_view "flash_zenit"	"flashbarrel55"	"foresight55"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/fw190/fw190_move"		}
		{link_sound "engine_start"		"vehicle/airborne/fw190/fw190_start"		}
		{link_sound "engine_work"		"vehicle/airborne/fw190/fw190_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/fw190/fw190_stop"		}
		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on fire "gun"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel1m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel1m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
          else ("fire_barrel" args 03)
		}
	}
	{on fire "mgun50"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel2m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel2m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun51"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel3m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel3m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun52"
		{view start "flashbarrel54"}
		{delay 0.5
			{view pause "flashbarrel54"}
		}
	}
	{on fire "mgun53"
		{view start "flashbarrel55"}
		{delay 0.5
			{view pause "flashbarrel55"}
		}
	}
	{on "update_lights" overload}
}
{"b25_eng"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		{add_view "flash_zenit"	"flashbarrel1m00"	"shooter1m_00"}
		{add_view "flash_zenit"	"flashbarrel1m01"	"shooter1m_01"}
		{add_view "flash_zenit"	"flashbarrel1m02"	"shooter1m_02"}
		{add_view "flash_zenit"	"flashbarrel1m03"	"shooter1m_03"}
		{add_view "flash_zenit"	"flashbarrel2m00"	"shooter2m_00"}
		{add_view "flash_zenit"	"flashbarrel2m01"	"shooter2m_01"}
		{add_view "flash_zenit"	"flashbarrel3m00"	"shooter3m_00"}
		{add_view "flash_zenit"	"flashbarrel3m01"	"shooter3m_01"}
		{add_view "flash_zenit"	"flashbarrel4"	"foresight7"}
		{add_view "flash_zenit"	"flashbarrel5"	"foresight8"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/fw190/fw190_move"		}
		{link_sound "engine_start"		"vehicle/airborne/fw190/fw190_start"		}
		{link_sound "engine_work"		"vehicle/airborne/fw190/fw190_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/fw190/fw190_stop"		}
		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on fire "mgun1"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel1m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel1m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
                                      else ("fire_barrel" args 03)
		}
	}
	{on fire "mgun2"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel2m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel2m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun3"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel3m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel3m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun4"
		{view start "flashbarrel4"}
		{delay 0.5
			{view pause "flashbarrel4"}
		}
	}
	{on fire "mgun5"
		{view start "flashbarrel5"}
		{delay 0.5
			{view pause "flashbarrel5"}
		}
	}
	{on "update_lights" overload}
}
{"hs129"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add  "cas"}
		{add_view "flash_zenit"	"flashbarrelg_00"	"shooter00"}
		{add_view "flash_zenit"	"flashbarrelg_01"	"shooter01"}
		{add_view "light_flash_zenit"	"flashbarrelm_00"	"shooter02"}
		{add_view "light_flash_zenit"	"flashbarrelm_01"	"shooter03"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/fw190/fw190_move"		}
		{link_sound "engine_start"		"vehicle/airborne/fw190/fw190_start"		}
		{link_sound "engine_work"		"vehicle/airborne/fw190/fw190_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/fw190/fw190_stop"		}
;		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on fire "mgun"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrelm%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrelm%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "gun2"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrelg%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrelg%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on "update_lights" overload}
}
{"hs129_75"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add  "cas"}
		{add_view "flash_zenit"	"flashbarrelg_00"	"shooter00"}
		{add_view "flash_zenit"	"flashbarrelg_01"	"shooter01"}
		{add_view "light_flash_zenit"	"flashbarrelm_00"	"shooter02"}
		{add_view "light_flash_zenit"	"flashbarrelm_01"	"shooter03"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/fw190/fw190_move"		}
		{link_sound "engine_start"		"vehicle/airborne/fw190/fw190_start"		}
		{link_sound "engine_work"		"vehicle/airborne/fw190/fw190_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/fw190/fw190_stop"		}
;		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on fire "gun"
        		{ani_play "fire"}
		{start_sound "weapon/shot/shell"}
		{add_view "smoke_zenit" "smoke_shell" "fx_invers"}
		{view start "smoke_shell"}
		{delay 2.5 0.5
			{view stop "smoke_shell"}
		}
		{spawn "shell_cannon" "fx_invers" x scale 0.014
			{impulse up 1.5 0.5 dir -4.5 0.7 cz 0.2 0.1 com}
			{add_view "smoke_zenit" "smoke_shell" "fx_shellsmoke"}
			{view start "smoke_shell"}
			{delay_effect 3 1 "stop"}
			{delay 3 0.5
				{hide 15}
			}
		}
	}
	{on fire "mgun"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrelm%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrelm%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "gun2"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrelg%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrelg%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on "update_lights" overload}
}
{"ki45"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/fw190/fw190_move"		}
		{link_sound "engine_start"		"vehicle/airborne/fw190/fw190_start"		}
		{link_sound "engine_work"		"vehicle/airborne/fw190/fw190_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/fw190/fw190_stop"		}
		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on "update_lights" overload}
}
{"sm79"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/fw190/fw190_move"		}
		{link_sound "engine_start"		"vehicle/airborne/fw190/fw190_start"		}
		{link_sound "engine_work"		"vehicle/airborne/fw190/fw190_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/fw190/fw190_stop"		}
		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on "update_lights" overload}
}
{"ca101_b"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "die"
		{bone hide "bomb00"}
		{bone hide "bomb01"}
	}
	{on fire "bomb" 
		{if not tagged "bombrunout"
			{if not tagged "bomb1"
				{tags add "bomb1"}
				{bone hide "bomb00"}
			else 
				{tags add "bombrunout"} 
				{tags remove "bomb1"}
				{bone hide "bomb01"}
			}
		}
	}
}
{"sm79_torpedo"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/fw190/fw190_move"		}
		{link_sound "engine_start"		"vehicle/airborne/fw190/fw190_start"		}
		{link_sound "engine_work"		"vehicle/airborne/fw190/fw190_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/fw190/fw190_stop"		}
		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on "update_lights" overload}
	{on fire "bomb" 
		{if not tagged "bombrunout"
			{if not tagged "bomb1"
				{tags add "bomb1"}
				{bone hide "torpedo1"}
			else 
				{tags add "bombrunout"} 
				{tags remove "bomb1"}
				{bone hide "torpedo2"}
			}
		}
	}
}
{"b25_torpedo"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		{add_view "flash_zenit"	"flashbarrel1m00"	"shooter1m00"}
		{add_view "flash_zenit"	"flashbarrel1m01"	"shooter1m01"}
		{add_view "flash_zenit"	"flashbarrel1m02"	"shooter1m02"}
		{add_view "flash_zenit"	"flashbarrel1m03"	"shooter1m03"}
		{add_view "flash_zenit"	"flashbarrel2m00"	"shooter2m00"}
		{add_view "flash_zenit"	"flashbarrel2m01"	"shooter2m01"}
		{add_view "flash_zenit"	"flashbarrel3m00"	"shooter3m00"}
		{add_view "flash_zenit"	"flashbarrel3m01"	"shooter3m01"}
		{add_view "flash_zenit"	"flashbarrel54"	"foresight54"}
		{add_view "flash_zenit"	"flashbarrel55"	"foresight55"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/fw190/fw190_move"		}
		{link_sound "engine_start"		"vehicle/airborne/fw190/fw190_start"		}
		{link_sound "engine_work"		"vehicle/airborne/fw190/fw190_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/fw190/fw190_stop"		}
		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on fire "gun"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel1m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel1m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
          else ("fire_barrel" args 03)
		}
	}
	{on fire "mgun50"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel2m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel2m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun51"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel3m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel3m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun52"
		{view start "flashbarrel54"}
		{delay 0.5
			{view pause "flashbarrel54"}
		}
	}
	{on fire "mgun53"
		{view start "flashbarrel55"}
		{delay 0.5
			{view pause "flashbarrel55"}
		}
	}
	{on fire "bomb" 
		{if not tagged "bombrunout"
			{tags add "bombrunout"} 
			{bone hide "torpedo1"}
		}
	}
	{on "update_lights" overload}
}
{"b25_torpedo_eng"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		{add_view "flash_zenit"	"flashbarrel1m00"	"shooter1m_00"}
		{add_view "flash_zenit"	"flashbarrel1m01"	"shooter1m_01"}
		{add_view "flash_zenit"	"flashbarrel1m02"	"shooter1m_02"}
		{add_view "flash_zenit"	"flashbarrel1m03"	"shooter1m_03"}
		{add_view "flash_zenit"	"flashbarrel2m00"	"shooter2m_00"}
		{add_view "flash_zenit"	"flashbarrel2m01"	"shooter2m_01"}
		{add_view "flash_zenit"	"flashbarrel3m00"	"shooter3m_00"}
		{add_view "flash_zenit"	"flashbarrel3m01"	"shooter3m_01"}
		{add_view "flash_zenit"	"flashbarrel4"	"foresight7"}
		{add_view "flash_zenit"	"flashbarrel5"	"foresight8"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/fw190/fw190_move"		}
		{link_sound "engine_start"		"vehicle/airborne/fw190/fw190_start"		}
		{link_sound "engine_work"		"vehicle/airborne/fw190/fw190_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/fw190/fw190_stop"		}
		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on fire "mgun1"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel1m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel1m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
                                      else ("fire_barrel" args 03)
		}
	}
	{on fire "mgun2"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel2m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel2m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun3"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel3m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel3m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun4"
		{view start "flashbarrel4"}
		{delay 0.5
			{view pause "flashbarrel4"}
		}
	}
	{on fire "mgun5"
		{view start "flashbarrel5"}
		{delay 0.5
			{view pause "flashbarrel5"}
		}
	}
	{on fire "bomb" 
		{if not tagged "bombrunout"
			{tags add "bombrunout"} 
			{bone hide "torpedo1"}
		}
	}
	{on "update_lights" overload}
}
{"db-3_torpedo"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/fw190/fw190_move"		}
		{link_sound "engine_start"		"vehicle/airborne/fw190/fw190_start"		}
		{link_sound "engine_work"		"vehicle/airborne/fw190/fw190_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/fw190/fw190_stop"		}
		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on "update_lights" overload}
	{on fire "bomb" 
		{if not tagged "bombrunout"
			{tags add "bombrunout"} 
			{bone hide "torpedo1"}
		}
	}
}
{"fw190f8_torpedo"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "ars"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/fw190/fw190_move"		}
		{link_sound "engine_start"		"vehicle/airborne/fw190/fw190_start"		}
		{link_sound "engine_work"		"vehicle/airborne/fw190/fw190_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/fw190/fw190_stop"		}
;		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on "update_lights" overload}
	{on fire "mgun"
		{play_sound "rocket_ambience"}
	}
	{on fire "bomb" 
		{if not tagged "bombrunout"
			{tags add "bombrunout"} 
			{bone hide "torpedo1"}
		}
	}
}
{"a6m5_torpedo"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "mtp"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "init_gun"
		{add_view "flash_zenit"	"shooter00" "placement"}
		{add_view "flash_zenit"	"shooter01" "placement"}
		{add_view "flash_gun_big" "shooter02" "gearl"}
		{add_view "flash_gun_big" "shooter03" "gearr"}
	}
	{on fire "gun"
		(define "fire_barrel"
			name "%0"
				{view start "placement%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "placement%0"}
				}
		)

		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		}
	}
	{on fire "bomb" 
		{if not tagged "bombrunout"
			{tags add "bombrunout"} 
			{bone hide "torpedo1"}
		}
	}
}
{"p-40"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "mtp"}
		{add_view "flash_zenit"	"flashbarrel00"	"shooter00"}
		{add_view "flash_zenit"	"flashbarrel01"	"shooter01"}
		{add_view "flash_zenit"	"flashbarrel02"	"shooter02"}
		{add_view "flash_zenit"	"flashbarrel03"	"shooter03"}
		{add_view "flash_zenit"	"flashbarrel04"	"shooter04"}
		{add_view "flash_zenit"	"flashbarrel05"	"shooter05"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/p39_move"			}
		{link_sound "engine_start"		"vehicle/airborne/bf109d_start"		}
		{link_sound "engine_work"		"vehicle/airborne/p39_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
	}
	{on "update_lights" overload}
	{on fire "mgun"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		  else ("fire_barrel" args 04)
		  else ("fire_barrel" args 05)
		}
	}
}
{"b5n2_torpedo"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
;	{on fire "bomb" 
;		{if not tagged "bombrunout"
;			{tags add "bombrunout"} 
;			{bone hide "torpedo"}
;		}
;	}
}
{"beaufighter"
	{on spawn
		{add_view	 "flash_zenit"	"flashbarrel_g00"	"shooter_g00"}
		{add_view	 "flash_zenit"	"flashbarrel_g01"	"shooter_g01"}
		{add_view	 "flash_zenit"	"flashbarrel_g02"	"shooter_g02"}
		{add_view	 "flash_zenit"	"flashbarrel_g03"	"shooter_g03"}
		{add_view "light_flash_zenit"	"flashbarrel_m00"	"shooter_m00"}
		{add_view "light_flash_zenit"	"flashbarrel_m01"	"shooter_m01"}
		{add_view "light_flash_zenit"	"flashbarrel_m02"	"shooter_m02"}
		{add_view "light_flash_zenit"	"flashbarrel_m03"	"shooter_m03"}
		{add_view "light_flash_zenit"	"flashbarrel_m04"	"shooter_m04"}
		{add_view "light_flash_zenit"	"flashbarrel_m05"	"shooter_m05"}
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/fw190/fw190_move"		}
		{link_sound "engine_start"		"vehicle/airborne/fw190/fw190_start"		}
		{link_sound "engine_work"		"vehicle/airborne/fw190/fw190_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/fw190/fw190_stop"		}
		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on "update_lights" overload}
	{on fire "gun"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel_g%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel_g%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		}
	}
	{on fire "mgun1"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel_m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel_m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		  else ("fire_barrel" args 04)
  		  else ("fire_barrel" args 05)
		}
	}
}
{"beaufighter_torpedo"
	{on spawn
		{add_view	 "flash_zenit"	"flashbarrel_g00"	"shooter_g00"}
		{add_view	 "flash_zenit"	"flashbarrel_g01"	"shooter_g01"}
		{add_view	 "flash_zenit"	"flashbarrel_g02"	"shooter_g02"}
		{add_view	 "flash_zenit"	"flashbarrel_g03"	"shooter_g03"}
		{add_view "light_flash_zenit"	"flashbarrel_m00"	"shooter_m00"}
		{add_view "light_flash_zenit"	"flashbarrel_m01"	"shooter_m01"}
		{add_view "light_flash_zenit"	"flashbarrel_m02"	"shooter_m02"}
		{add_view "light_flash_zenit"	"flashbarrel_m03"	"shooter_m03"}
		{add_view "light_flash_zenit"	"flashbarrel_m04"	"shooter_m04"}
		{add_view "light_flash_zenit"	"flashbarrel_m05"	"shooter_m05"}
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"			"vehicle/airborne/fw190/fw190_move"		}
		{link_sound "engine_start"		"vehicle/airborne/fw190/fw190_start"		}
		{link_sound "engine_work"		"vehicle/airborne/fw190/fw190_work"		}
		{link_sound "engine_stop"		"vehicle/airborne/fw190/fw190_stop"		}
		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on "update_lights" overload}
	{on fire "gun"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel_g%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel_g%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		}
	}
	{on fire "mgun1"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel_m%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel_m%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		  else ("fire_barrel" args 04)
  		  else ("fire_barrel" args 05)
		}
	}
	{on fire "bomb" 
		{if not tagged "bombrunout"
			{tags add "bombrunout"} 
			{bone hide "torpedo"}
		}
	}
}
{"p-39_fr"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "ars"}
		{add_view "flash_zenit"	"flashbarrel00"	"shooter00"}
		{add_view "flash_zenit"	"flashbarrel01"	"shooter01"}
		{add_view "light_flash_zenit"	"flashbarrel02"	"shooter02"}
		{add_view "light_flash_zenit"	"flashbarrel03"	"shooter03"}
		{add_view "light_flash_zenit"	"flashbarrel04"	"shooter04"}
		{add_view "light_flash_zenit"	"flashbarrel05"	"shooter05"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/p39_move"			}
		{link_sound "engine_start"		"vehicle/airborne/bf109d_start"		}
		{link_sound "engine_work"		"vehicle/airborne/p39_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
	}
	{on animation_end "engine_start"
		{ani_play "engine_work" loop}
		{bone hide "propeller"}
		{play_sound "engine_work" 1}
	}
	{on "engine_stop"
		{kill_delay "engine_stopped"}
		{if "engine_started"
			{set "engine_started" 0}
			{ani_stop "engine_start"}
			{ani_stop "engine_work"}
			{bone show "propeller"}
			{ani_play "engine_stop"}
			{stop_sound "engine_start"}
			{stop_sound "engine_work"}
			{stop_sound "fly"}
		}
	}
	{on "update_lights" overload}
	{on fire "mgun"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		}
	}
	{on fire "mgun1"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		  else ("fire_barrel" args 04)
		  else ("fire_barrel" args 05)
		}
	}
}
{"p-40_fr"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "mtp"}
		{add_view "flash_zenit"	"flashbarrel00"	"shooter00"}
		{add_view "flash_zenit"	"flashbarrel01"	"shooter01"}
		{add_view "flash_zenit"	"flashbarrel02"	"shooter02"}
		{add_view "flash_zenit"	"flashbarrel03"	"shooter03"}
		{add_view "flash_zenit"	"flashbarrel04"	"shooter04"}
		{add_view "flash_zenit"	"flashbarrel05"	"shooter05"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/p39_move"			}
		{link_sound "engine_start"		"vehicle/airborne/bf109d_start"		}
		{link_sound "engine_work"		"vehicle/airborne/p39_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
	}
	{on "update_lights" overload}
	{on fire "mgun"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    ("fire_barrel" args 00)
		  else ("fire_barrel" args 01)
		  else ("fire_barrel" args 02)
		  else ("fire_barrel" args 03)
		  else ("fire_barrel" args 04)
		  else ("fire_barrel" args 05)
		}
	}
}
{"il-2_pol"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		)
	}
	{on "die"
		{bone hide "rocket00"}
		{bone hide "rocket01"}
		{bone hide "rocket02"}
		{bone hide "rocket03"}
		{bone hide "rocket04"}
		{bone hide "rocket05"}
		{bone hide "rocket06"}
		{bone hide "rocket07"}
		{bone hide "bomb00"}
		{bone hide "bomb01"}
	}
}
{"la5fn_pol"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "ars"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/p51_move"			}
		{link_sound "engine_start"		"vehicle/airborne/p51_start"		}
		{link_sound "engine_work"		"vehicle/airborne/p51_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
	}
	{on "update_lights" overload}
	
}
{"yak3"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "ars"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/p51_move"			}
		{link_sound "engine_start"		"vehicle/airborne/p51_start"		}
		{link_sound "engine_work"		"vehicle/airborne/p51_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
	}
	{on "update_lights" overload}
	
}
{"fokker"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "ars"}
		{add_view "light_flash_zenit"	"flashbarrel00"	"shooter00"}
		{add_view "light_flash_zenit"	"flashbarrel01"	"shooter01"}
		{add_view "light_flash_zenit"	"flashbarrel02"	"shooter02"}
		{add_view "light_flash_zenit"	"flashbarrel03"	"shooter03"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/p51_move"			}
		{link_sound "engine_start"		"vehicle/airborne/p51_start"		}
		{link_sound "engine_work"		"vehicle/airborne/p51_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
	}
	{on "update_lights" overload}
	{on fire "mgun"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    
			("fire_barrel" args 00)
		else 
			("fire_barrel" args 01)
		else 
			("fire_barrel" args 02)
		else 
			("fire_barrel" args 03)
		}
	}
}
{"fokker_fin"
	{on spawn
		{tags add "fighter_aircraft"}
		{tags add "ars"}
		{add_view "light_flash_zenit"	"flashbarrel00"	"shooter00"}
		{add_view "light_flash_zenit"	"flashbarrel01"	"shooter01"}
		{add_view "light_flash_zenit"	"flashbarrel02"	"shooter02"}
		{add_view "light_flash_zenit"	"flashbarrel03"	"shooter03"}
		(mod "mp"
			{tags add "aircraft"}
			{call "engine_on"}
		) 
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/p51_move"			}
		{link_sound "engine_start"		"vehicle/airborne/p51_start"		}
		{link_sound "engine_work"		"vehicle/airborne/p51_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/fw_stop"			}
	}
	{on "update_lights" overload}
	{on fire "mgun"
		(define "fire_barrel"
			name "%0"
				{view start "flashbarrel%0"}
				{call "spawn_shell"}
				{delay 0.5
					{view pause "flashbarrel%0"}
				}
		)
		{if    
			("fire_barrel" args 00)
		else 
			("fire_barrel" args 01)
		else 
			("fire_barrel" args 02)
		else 
			("fire_barrel" args 03)
		}
	}
}
{"po2_fin"
	{on spawn
		{tags add "bomber_aircraft"}
		{tags add  "cas"}
		(mod "mp"
			{tags add "aircraft"}
			
			{call "engine_on"}
		)
	}
	{on "add_movement_sound" overload
		{link_sound "fly"				"vehicle/airborne/i16_work"			}
		{link_sound "engine_start"		"vehicle/airborne/i16_start"		}
		{link_sound "engine_work"		"vehicle/airborne/i16_work"			}
		{link_sound "engine_stop"		"vehicle/airborne/i16_stop"			}
		{link_sound "distant"		"vehicle/airborne/distant/aeroplane_distant_light"			}
	}
	{on "update_lights" overload}
}
;----------------------------Normand Pack
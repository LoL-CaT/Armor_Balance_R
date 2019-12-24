(define "cut_pieces"
	("cut_piece" args 0)	("cut_piece" args 1)
	("cut_piece" args 2)	("cut_piece" args 3)
	("cut_piece" args 4)	("cut_piece" args 5)
	("cut_piece" args 6)	("cut_piece" args 7)
	("cut_piece" args 8)	("cut_piece" args 9)
	("cut_piece" args 00)	("cut_piece" args 01)
	("cut_piece" args 02)	("cut_piece" args 03)
	("cut_piece" args 04)	("cut_piece" args 05)
	("cut_piece" args 06)	("cut_piece" args 07)
	("cut_piece" args 08)	("cut_piece" args 09)
	("cut_piece" args 10)	("cut_piece" args 11)
	("cut_piece" args 12)	("cut_piece" args 13)
	("cut_piece" args 14)	("cut_piece" args 15)
)

(define "cut_subpieces"
	("cut_subpiece" args 0)	("cut_subpiece" args 1)
	("cut_subpiece" args 2)	("cut_subpiece" args 3)
	("cut_subpiece" args 4)	("cut_subpiece" args 5)
	("cut_subpiece" args 6)	("cut_subpiece" args 7)
	("cut_subpiece" args 8)	("cut_subpiece" args 9)
	("cut_subpiece" args 00)("cut_subpiece" args 01)
	("cut_subpiece" args 02)("cut_subpiece" args 03)
	("cut_subpiece" args 04)("cut_subpiece" args 05)
	("cut_subpiece" args 06)("cut_subpiece" args 07)
	("cut_subpiece" args 08)("cut_subpiece" args 09)
	("cut_subpiece" args 10)("cut_subpiece" args 11)
	("cut_subpiece" args 12)("cut_subpiece" args 13)
	("cut_subpiece" args 14)("cut_subpiece" args 15)
	("cut_subpiece" args 16)("cut_subpiece" args 17)
)

{"parts construction"
	{on break_armor
		{if volume "body"
			{if name "blast"
				{set "blast" 1}
				{if not "blast_disable"
					{if min_energy 350
						{set "blast_one" 0}
					else
						{set "blast_one" 1}
					}
					{call "change_model"}
				}
			else
				{set "blast" 0}
				{call "change_model"}
			}
		}
	}
	{on bullet_hit
		{if volume "body"
			{if stuff "shell"
				{call "break_windows"}
			}
		}
	}
	{on contact
		{set "blast" 0}
		{if effector "airborne"
			{call "change_model"}
		else effector "air_part"
			{if min_speed 5
				{call "change_model"}
			}
		}
	}
	{on "change_model"
		{if not "sliced"
			{tags add "crushed"}
			{set "sliced" 1}
			{call "disable_volumes"}
			{call "check_structure"}
			{delay_ex 0.1
				{set_skeleton "_x"}
				{call "disable_volumes"}
				{call "update_fx"}
				{set "first_stage" 1}
				{set "last_stage" 1}
				{call "effects"}
				{use_blend_tex 1}
				{call "cut_pieces"}
				{ani_play "crush"}
				{delay 0.1
					{volumes "body" enable contact bullet blast visible}
					{update_visibility_patch}
				}
			}
		}
	}
	{on "break"
		{call "change_model"}
	}
	{on "burn_end"
		{bone hide "roof_hide"}
		{tex_mod "burned"}
	}
}

{"break_on_burn parts construction"
	{on "burn_end"
		{call "break"}
	}
}

{"small parts construction"
	{on contact
		{set "blast" 0}
		{if can_crush
			{call "change_model"}
		}
	}
}

{"entanglement parts construction"
	{on contact
		{set "blast" 0}
		{if can_crush
			{call "change_model"}
		}
	}
}


{"concrete small parts construction"
	{on "cut_pieces"
		{volumes disable contact}
		(define "cut_piece"
			{tear "piece_small_concrete" bone "piece%0"
				{volumes enable contact}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
			}
		)
		("cut_pieces")
	}
}


{"concrete small parts construction big_impulse"
	{on "cut_pieces" overload
		{if "blast"
			{volumes disable contact}
			(define "cut_piece"
				{tear "piece_small_concrete" bone "piece%0"
					{volumes enable contact}
					{impulse up 5 2 dir 3.5 2.5 rnd_dir 5 no_position}
				}
			)
			("cut_pieces")
		else
			{inherited}
		}
	}
}


{"big steel parts construction"
	{on "cut_pieces"
		(define "cut_piece"
			{tear "piece_large_steel" bone "piece%0"
				{volumes enable contact}
				{impulse up 2.5 1.7 dir 3.5 1.3 no_position}
			}
		)
		("cut_pieces")
		(define "cut_subpiece"
			{tear "piece_medium_steel" bone "sub_piece%0"
				{volumes enable contact}
				{spawn "spheredust_norm" "sub_piece%0"}
				{impulse up 2.5 1.7 dir 3.5 1.3 no_position}
			}
		)
		("cut_subpieces")
	}
}

{"small steel parts construction"
	{on "cut_pieces"
		{volumes disable contact}
		(define "cut_piece"
			{tear "piece_medium_steel_construction" bone "piece%0"
				{volumes enable contact}
				{if "blast"
					{impulse up 4 2 dir 2.5 1.3 no_position}
				else
					{impulse up 1 0.7 dir -4.5 0.3 no_position}
				}
			}
		)
		("cut_pieces")
	}
}

{"wood parts construction"
	{on bullet_hit
		{if volume "body"
			{if stuff "shell"
				{set "blast" 0}
				{call "change_model"}
			}
		}
	}
	{on "cut_pieces"
		(define "cut_piece"
			{tear "building_part_wood" bone "piece%0"
				{volumes enable contact float}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
			}
		)
		("cut_pieces")
	}
}

{"small wood parts construction"
	{on "cut_pieces" overload
		{volumes disable contact blast}
		(define "cut_piece"
			{tear "piece_small_wood" bone "piece%0"
				{volumes enable float}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
			}
		)
		("cut_pieces")
	}
}

{"small wood parts construction big_impulse"
	{on "cut_pieces" overload
		{if "blast"
			{volumes disable contact blast}
			(define "cut_piece"
				{tear "piece_small_wood" bone "piece%0"
					{volumes enable float}
					{impulse up 5 2 dir 3.5 2.5 rnd_dir 5 no_position}
				}
			)
			("cut_pieces")
		else
			{inherited}
		}
	}
}

{"small sand parts construction"
	{on "cut_pieces" overload
		{volumes disable contact blast}
		(define "cut_piece"
			{tear "piece_medium_sand" bone "piece%0"
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
			}
		)
		("cut_pieces")
	}
}

{"piece_large_concrete"
	{on spawn
		{if rand 0.5
			{set "crush" 1}
		}
	}
	{on ground_hit
		{if "crush"
			{spawn "piece_crush"}
			{delete}
		}
	}
	{on contact
		{if can_crush
			{spawn "piece_crush"}
			{delete}
		}
	}
}

{"building_part"
	{on spawn
		{if rand 0.5
			{set "crush" 1}
		}
	}
	{on ground_hit
		{if not "sliced"
			{spawn "spheredust_big_short"}
			{call "cut_subpieces"}
		}
	}
	{on contact
		{if not "sliced"
			{spawn "spheredust_big_short"}
			{call "cut_subpieces"}
		}
	}
}


{"building_part concrete"
	{on ground_hit
		{if "crush"
			{spawn "piece_crush_big"}
			{delete}
		}
	}
	{on contact
		{if can_crush
			{spawn "piece_crush_big"}
			{delete}
		}
	}
	{on "cut_subpieces"
		{set "sliced" 1}
		(define "cut_subpiece"
			{tear "piece_large_concrete" bone "sub_piece%0" id "building_part_concrete_subpiece"
				{volumes enable contact}
				{spawn "spheredust_norm" "sub_piece%0"}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
				{add_view "smoke_black" "smoke" "root"}
				{view start "smoke"}
				{delay_effect 1 0.5 "stop"}
			}
		)
		("cut_subpieces")
	}
	{on "slice_load"
		{if name "building_part_concrete_subpiece"
			{with_effector
				{add_view "smoke_black" "smoke" "root"}
			}
		}
	}
}

{"building_part wood"
	{on "cut_subpieces"
		{set "sliced" 1}
		(define "cut_subpiece"
			{tear "piece_big_wood" bone "sub_piece%0" id "building_part_wood_subpiece"
				{volumes enable contact}
				{spawn "spheredust_norm" "sub_piece%0"}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
				{add_view "smoke_black" "smoke" "root"}
				{view start "smoke"}
				{delay_effect 5 3 "stop"}
			}
		)
		("cut_subpieces")	
	}
	{on contact
		{if can_crush
			{spawn "wood_hit_small"}
			{delete}
		}
	}
	{on "slice_load"
		{if name "building_part_wood_subpiece"
			{with_effector
				{add_view "smoke_black" "smoke" "root"}
			}
		}
	}
}

{"cornered parts construction"
	{on bullet_hit
		{if not under_water
			{if stuff "shell small"
			 	{spawn	"stone_hit_br_small" inv_normal}
			else stuff "big shell fg"
			 	{spawn	"stone_hit_br_big" inv_normal}
			else stuff "shell"
			 	{spawn	"stone_hit_br" inv_normal}
			}
		}
	}
	{on "cut_pieces"
		(define "cut_piece"
			{tear "building_part_concrete" bone "piece%0"
				{volumes enable contact}
				{impulse up 1 0.7 dir -5 1.3 no_position}
				{spawn "spheredust_norm" "piece%0"}
			}
		)
		("cut_pieces")
		(define "cut_subpiece"
			{tear "piece_large_concrete" bone "sub_piece%0" id "cornered_parts_construction_piece"
				{volumes enable contact}
				{spawn "spheredust_norm" "sub_piece%0"}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
			}
		)
		("cut_subpieces")
	}
	{on "slice_load"
		{if name "cornered_parts_construction_piece"
			{with_effector
				{add_view "smoke_black" "smoke" "root"}
			}
		}
	}
	{on "destroyed_stamp" overload
		{if rand 0.25
			{spawn "crash_brick3"		no_position}
		else rand 0.25
			{spawn "stonechip1"		no_position}
		else rand 0.25
			{spawn "crash_stone2"		no_position}
		else
			{spawn "crash_brick3a"		no_position}
		}
	}
	{on "effects"
		{start_sound "crush/big/concrete"}
	}
}

{"cornered wall parts construction"
	{on contact
		{if can_crush
			{set "blast" 0}
			{call "change_model"}
		}
	}
}

{"concrete dot parts construction"
}

{"unbreakable parts construction"
	{on break_armor overload}
	{on "destroyed_stamp" overload}
}

{"ice parts construction"
	{on overlap begin
		{if not tagged "strong"
			{set "blast" 0}
			{if effector "tank"
				{call "delayed_change_model"}
			else effector "car"
				{call "delayed_change_model"}
			}
		}
	}
	{on "delayed_change_model"
		{if not "delayed_change_model"
			{set "delayed_change_model" 1}
			{delay 2
				{call "change_model"}
			}
		}
	}
	{on contact overload}
	{on "cut_pieces"
		{volumes "body" disable overlap blast}
		{spawn "iceblock_hit01"}
		{delay 0.5
			{spawn "ex_water_sm"}
		}
		(define "cut_piece"
			{tear "piece_medium_ice" bone "piece%0"
				{volumes enable contact}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
			}
		)
		("cut_pieces")
	}
}

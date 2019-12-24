{"massive_building_wall"
	{on spawn
		{set "broken" 0}
	}
	{on break_armor
		{if name "blast"
			{if min_energy 24
				{call "use_tex"}
			}
			{if volume "piece"
				{if min_energy 100
					{set "broken" 1}
					{call "try_break"}
				else min_energy 100
					{call "check_piece"}
					{call "try_break"}
				}
			}
		}
	}
	{on bullet_hit
		{if stuff "shell"
			{call "use_tex"}
			{if volume "piece"
				{if stuff "fg"
					{bullet_detonate}
				else stuff "ap big"
					{set "broken" 1}
					{call "try_break"}
				else stuff "ap"
					{call "check_piece"}
					{call "try_break"}
				}
			}
		}
	}
	{on "use_tex"
		{if not "use_tex"
			{set "use_tex" 1}
			{use_blend_tex 1}
		}
	}
	{on "try_break"
		{impulse up 0.1 0.05 dir 0.1 0.05}
		{if "broken"
			{call "effects"}
			{call "cut_piece"}
		else volume "door"
			{call "cut_piece"}
		}
	}
	{on "cut_piece"
		{if volume "door"
			{tear "piece_big_wood" bone from_volume
				{impulse up 1 0.7 dir 1 0.3 no_position}
			}
		else
			{tear "piece_large_concrete" bone from_volume
				{impulse up 1 0.7 dir 1 0.3 no_position}
			}
		}
	}
	{on "check_piece"
		{if not "broken_3"
			{set "broken_3" 1}
		else
			{if not "broken_2"
				{set "broken_2" 1}
			else
				{if not "broken_1"
					{set "broken_1" 1}
				else
					{if not "broken"
						{set "broken" 1}
					}
				}
			}
		}
	}
}

{"massive_building"
	{on spawn
		{set "first_stage" 1}		;for effects spawn in "construction"
		{set "destroyed_stamp" 1}   ;
	}
	{on bullet_hit
		{if stuff "shell"
			{if "sliced_end"
				{if stuff "big shell"
					{if volume "roof"
						{call "use_tex"}
					}
				}
			}
			{if stuff "fg"
				{bullet_detonate}
			else stuff "ap"
				{if not "sliced"
					{call "change_model"}
					{delay_ex 0.15
						{blastwave c4 0.79 r0 1 r1 2 position}
					}
				}
			}
		}
	}
	{on "use_tex"
		{if not "use_tex"
			{set "use_tex" 1}
			{call "effects"}
			{use_blend_tex 1}
		}
	}
	{on blast
		{if "sliced_end"
			{if volume "roof"
				{if min_energy 24
					{call "use_tex"}
				}
			}
		}
	}
	{on break_armor
		{if name "blast"
			{if min_energy 24
				{if not "sliced"
					{call "change_model"}
					{call "effects"}
					{delay_ex 0.15
						{blastwave c4 1.5 r0 1 r1 2 position}
					}
				else
					{call "try_roof_break"}
				}
			}
		}
	}
	{on "change_model"
		{set "sliced" 1}
		{delay 0 ; prevent trace bullet into freed volumes after SetSkeleton
			{call "break_windows"}
			{set_skeleton "_x"}
			{ani_play "crush1"}
			{call "update_fx"}
			{set "first_stage" 1}
			(define "cut_wall"
				{tear "temple_wall_concrete" bone "wall%0"}
			)
			("cut_wall" args 0	)	("cut_wall" args 1	)
			("cut_wall" args 2	)	("cut_wall" args 3	)
			("cut_wall" args 4	)	("cut_wall" args 5	)
			("cut_wall" args 6	)	("cut_wall" args 7	)
			("cut_wall" args 8	)	("cut_wall" args 9	)
			("cut_wall" args 10	)	("cut_wall" args 11	)
			{set "sliced_end" 1}
		}
	}
	{on "try_roof_break"
		{if "sliced_end"
			{call "check_roof"}
			{if "roof_broken"
				{set "last_stage" 1}
				{call "effects"}
				{call "use_tex"}
				{call "cut_big_pieces"}
				{ani_play "crush2"}
				{volumes disable bullet contact blast visible}
			}
		}
	}
	{on "check_roof"
		{if not "roof_broken_3"
			{set "roof_broken_3" 1}
		else
			{if not "roof_broken_2"
				{set "roof_broken_2" 1}
			else
				{if not "roof_broken_1"
					{set "roof_broken_1" 1}
				else
					{if not "roof_broken"
						{set "roof_broken" 1}
					}
				}
			}
		}
	}
	{on "cut_big_pieces"
		(define "cut_big_piece"
			{tear "piece_large_concrete" bone "piece_big%0"
				{impulse up 1 0.7 dir 1 0.3 no_position}
			}
		)
		("cut_big_piece" args 1)
		("cut_big_piece" args 2)
		("cut_big_piece" args 3)
	}
}

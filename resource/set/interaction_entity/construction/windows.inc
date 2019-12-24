{"windowed"
	(define "break_window"
		{if bone "window%0" visible
			{if bone "fx_glass%0"
				{spawn "glass_hit" "fx_glass%0" x}
			}
			{if bone "fx_glass0%0"
				{spawn "glass_hit" "fx_glass0%0" x}
			}
			{if not bone "fx_glass%0"
				{if not bone "fx_glass0%0"
					{spawn "glass_hit" "window%0" x}
				}
			}
			{volumes "window%0" disable all}
			{delay 0.1
				{bone hide	"window%0"}
				{bone show	"window%0_x"}
			}
		}
	)
	(define "try_break_window"
		{if volume "window%0"
			("break_window" args %0)
		}
	)
	{on spawn
		{if not sunlight
			{add_view "light_house" "light" "fx_light1"}
			{add_view "light_house" "light" "fx_light2"}
			{add_view "light_house" "light" "fx_light3"}
			{add_view "light_house" "light" "fx_light4"}
			{add_view "light_house" "light" "fx_light5"}
			{add_view "light_house" "light" "fx_light6"}
			{add_view "light_house2" "light" "fx_light_high1"}
			{add_view "light_house2" "light" "fx_light_high2"}
			{add_view "light_house2" "light" "fx_light_high3"}
			{add_view "light_house2" "light" "fx_light_high4"}
			{add_view "light_house2" "light" "fx_light_high5"}
			{add_view "light_house2" "light" "fx_light_high6"}
			{view start "light"}
		else
			{bone cut "fx_light1"}
			{bone cut "fx_light2"}
			{bone cut "fx_light3"}
			{bone cut "fx_light4"}
			{bone cut "fx_light5"}
			{bone cut "fx_light6"}
			{bone cut "fx_light_high1"}
			{bone cut "fx_light_high2"}
			{bone cut "fx_light_high3"}
			{bone cut "fx_light_high4"}
			{bone cut "fx_light_high5"}
			{bone cut "fx_light_high6"}
		}
	}
	{on bullet_hit
		{call "break_window"}
	}
	{on contact
		{call "break_window"}
	}
	{on blast 
		{if min_energy 0.2
			{call "break_window"}
		}
	}
	{on "break_window"
		{if not "windows_broken"
			("try_break_window" args 0)		("try_break_window" args 1)
			("try_break_window" args 2)		("try_break_window" args 3)
			("try_break_window" args 4)		("try_break_window" args 5)
			("try_break_window" args 6)		("try_break_window" args 7)
			("try_break_window" args 8)		("try_break_window" args 9)
			("try_break_window" args 10)	("try_break_window" args 11)
			("try_break_window" args 12)	("try_break_window" args 13)
			("try_break_window" args 14)	("try_break_window" args 15)
			("try_break_window" args 16)	("try_break_window" args 17)
			("try_break_window" args 18)	("try_break_window" args 19)
			("try_break_window" args 20)	("try_break_window" args 21)
			("try_break_window" args 22)	("try_break_window" args 23)
		}
	}
	{on "break_windows"
		{if not "windows_broken"
			{set "windows_broken" 1}
			("break_window" args 0)		("break_window" args 1)
			("break_window" args 2)		("break_window" args 3)
			("break_window" args 4)		("break_window" args 5)
			("break_window" args 6)		("break_window" args 7)
			("break_window" args 8)		("break_window" args 9)
			("break_window" args 10)	("break_window" args 11)
			("break_window" args 12)	("break_window" args 13)
			("break_window" args 14)	("break_window" args 15)
			("break_window" args 16)	("break_window" args 17)
			("break_window" args 18)	("break_window" args 19)
			("break_window" args 20)	("break_window" args 21)
			("break_window" args 22)	("break_window" args 23)
		}
	}
	{on "next_stage"
		{call "break_windows"}
	}
	{on "last_stage"
		{call "break_windows"}
	}
	{on "break_windows_delayed"
		{delay 0.2
			{call "break_windows"}
		}
	}
}

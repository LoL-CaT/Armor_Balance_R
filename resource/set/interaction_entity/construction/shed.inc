{"shed"
	{inflammation_time 4}
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
			{call "break"}
		else effector "air_part"
			{call "break"}
		else effector "big part"
			{call "break"}
		}
	}
	{on "break"
		{call "disable_volumes"}
		{call "crush_fx"}
		{call "check_structure"}
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
	{on "disable_volumes"
		{volumes disable visible bullet contact blast touch}
	}
}

{"wood shed"
	{on "crush_fx"
		{spawn "wood_crush_big" "root"}
	}
}

{"wood shed small"
	{on "crush_fx" overload
		{spawn "wood_crush_small" "root"}
	}
}

{"concrete shed"
	{inflammation_time 10000}
	{on "crush_fx"
		{spawn "stone_crush_big" "root"}
	}
}

{"steel shed"
	{inflammation_time 10000}
	{on "crush_fx"
		{spawn "spheredust_norm" "root"}
	}
}

{"shed cellar1"
	{on "crush_fx"
		{spawn "trash_1" "root"}
	}
}

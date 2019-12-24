{"construction"
	{on spawn
		{call "update_fx"}
	}
	{on "update_fx"
		{add_view "smoke_grey"			"smoke"	"FX_smoke1"	}
		{add_view "smoke_grey"			"smoke"	"FX_smoke1a"}
		{add_view "smoke_grey"			"smoke"	"FX_smoke1b"}
		{add_view "smoke_grey"			"smoke"	"FX_smoke1c"}
		{add_view "smoke_black"			"smoke"	"FX_smoke2"	}
		{add_view "smoke_black"			"smoke"	"FX_smoke2a"}
		{add_view "smoke_black"			"smoke"	"FX_smoke2b"}
		{add_view "smoke_black"			"smoke"	"FX_smoke2c"}

		{add_view "smoke_dead_small"	"fire"	"FX_fire1"  }
		{add_view "smoke_dead_small"	"fire"	"FX_fire1a" }
		{add_view "smoke_dead_small"	"fire"	"FX_fire1b" }
		{add_view "smoke_dead_small"	"fire"	"FX_fire1c" }
		{add_view "smoke_dead_norm"		"fire"	"FX_fire2"  }
		{add_view "smoke_dead_norm"		"fire"	"FX_fire2a" }
		{add_view "smoke_dead_norm"		"fire"	"FX_fire2b" }
		{add_view "smoke_dead_norm"		"fire"	"FX_fire2c" }

		{add_view "smoke_grey"			"flue"	"FX_flue"	}
	}
	{on "effects"
		{if "first_stage"
			{set "first_stage" 0}
			{call "destroyed_stamp"}
			{view start "smoke"}
			{view start "fire"}
			{ani_play "effector" loop}
			{delay 13 3 {view stop "fire"}}
			{delay 20 3 {view stop "smoke"}}
			{delay 30   {ani_stop "effector"}}
		}
		{if "last_stage"
			{spawn "circledust_norm"	"FX_dust1"	}
			{spawn "circledust_norm"	"FX_dust1a"	}
			{spawn "spheredust_big"		"FX_dust2"	}
			{spawn "spheredust_big"		"FX_dust2a"	}
		}
		{spawn "wood_hit_small"			"FX_wood1"	}
		{spawn "wood_hit_small"			"FX_wood1a"	}
		{spawn "wood_hit_small"			"FX_wood1b"	}
		{spawn "wood_hit_small"			"FX_wood1c"	}
		{spawn "wood_hit_big"			"FX_wood2"	}
		{spawn "wood_hit_big"			"FX_wood2a"	}

		{spawn "stone_hit_small"		"FX_stone1"	}	; @todo : what to do with this?
		{spawn "stone_hit_small"		"FX_stone1a"}
		{spawn "stone_hit_small"		"FX_stone1b"}
		{spawn "stone_hit_small"		"FX_stone1c"}
		{spawn "stone_hit_small"		"FX_stone1d"}
		{spawn "stone_hit_small"		"FX_stone1e"}
		{spawn "stone_hit_small"		"FX_stone1f"}
		{spawn "stone_hit_small"		"FX_stone1g"}
		{spawn "stone_hit_small"		"FX_stone1h"}
		{spawn "stone_hit_small"		"FX_stone1i"}
		{spawn "stone_hit_small"		"FX_stone1j"}
		{spawn "stone_hit_small"		"FX_stone1k"}
		{spawn "stone_hit_small"		"FX_stone1l"}
		{spawn "stone_hit_small"		"FX_stone1m"}

		{spawn "stone_hit_big"			"FX_stone2"	}
		{spawn "stone_hit_big"			"FX_stone2a"}
		{spawn "hay_hit_norm"			"FX_haulm1"	}
		{spawn "hay_hit_norm"			"FX_haulm1a"}
		{spawn "hay_hit_norm"			"FX_haulm1b"}
		{spawn "hay_hit_norm"			"FX_haulm1c"}
		{spawn "hay_hit_big"			"FX_haulm2"	}
		{spawn "hay_hit_big"			"FX_haulm2a"}
		{spawn "hay_hit_fall"			"FX_hayfall1"}
		{spawn "hay_hit_fall"			"FX_hayfall2"}
		{spawn "hay_hit_fall"			"FX_hayfall3"}
		{spawn "hay_hit_fall"			"FX_hayfall4"}

		{spawn "tank_die"				"FX_exp1"   }
		{spawn "barrel_die"				"FX_exp1a"	}
		{spawn "barrel_die_big"			"FX_exp2"	}
		{spawn "barrel_die_big"			"FX_exp2a"	}
		{spawn "fuel_die"				"FX_expfuel" }
		{spawn "ex_bomb_big"			"FX_exptnt" }

		{spawn "car_die_particle"			"FX_metall1"	}
		{spawn "car_die_particle"			"FX_metall1a"	}

		{spawn "sand_hit_small"			"FX_sand1"	}
		{spawn "sand_hit_small"			"FX_sand1a"	}
		{spawn "sand_hit_big"			"FX_sand2"	}
		{spawn "sand_hit_big"			"FX_sand2a"	}
	}
	{on "destroyed_stamp"
		{spawn "shellhole_dead_car2"	no_position	}
	}
	{on "disable_volumes"
		{volumes disable visible bullet contact blast touch}
	}
	{on "check_structure"} ; handled in StructureBone extender
	{on "crush_structure"  ; called from StructureBone extender
		{delay 0.1
			{call "break"}
		}
	}
}

{"flue"
	{on spawn
		{call "flue_process"}
	}
	{on "flue_process"
		{if rand 0.5
			{view start "flue"}
		else
			{view pause "flue"}
		}
		{delay 50
			{call "flue_process"}
		}
	}
}

{"flue_always"
	{on spawn
		{call "flue_process"}
	}
	{on "flue_process"
		{view start "flue"}
	}
}

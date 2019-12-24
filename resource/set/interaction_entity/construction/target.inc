{"target"
	{on spawn
		{if tagged "up"
			{volumes enable contact bullet blast visible touch}
			{area enable}
			{ani_wind "crush" begin}
			{set "broken" 0}
			{auto_operatable 1}
		else
			{volumes disable contact bullet blast visible touch}
			{area disable}
			{ani_wind "crush" end}
			{set "broken" 1}
			{auto_operatable 0}
		}
	}
	(define "pierce_check"
		{if tagged %0 {if stuff %1 {call "break"}}}
	) 
	{on bullet_hit
		("pierce_check" args "smg"   "pistol")
		("pierce_check" args "rifle" "rifle")
		("pierce_check" args "mgun"  "mgun")
		("pierce_check" args "zenite"  "zenite")
	}
	{on "break"
		{tags add "crushed"}
		{set "broken" 1}
		{auto_operatable 0}
	}
	{on "up"
		{tags remove "crushed"}
		{tags add "up"}
		{set "broken" 0}
		{volumes enable contact bullet blast visible touch}
		{area enable}
		{ani_play "crush" -1}
		{auto_operatable 1}
	}
	{on "down"
		{if not "broken"
			{call "break"}
		}
		{tags remove "crushed"}
	}
	{on break_armor overload
		{if tagged "grenade"
			{call "break"}
		}
	}
}

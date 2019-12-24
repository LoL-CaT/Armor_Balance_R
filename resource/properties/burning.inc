(define "declare_fire_volume"
	{Volume "fire%0"
		{able clear}
		{tags "fire"}
	}
	{Volume "smoke%0"
		{able clear}
		{tags "fire"}
	}
)
(define "declare_fire_volumes"
	{props "burning_old"}
	("declare_fire_volume" args 0)	("declare_fire_volume" args 1)
	("declare_fire_volume" args 2)	("declare_fire_volume" args 3)
	("declare_fire_volume" args 4)	("declare_fire_volume" args 5)
	("declare_fire_volume" args 6)	("declare_fire_volume" args 7)
	("declare_fire_volume" args 8)	("declare_fire_volume" args 9)
)

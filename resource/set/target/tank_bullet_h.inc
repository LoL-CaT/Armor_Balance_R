{selector
 	{type "tank_bullet_h"}

	{group
		{ignore {class airborne}}
		{ignore {class attacker}}
		{ignore {class fighter}}		
;		{sort {class human} {weapon "fg"}}
		{sort {class human} {weapon}}
		{sort {class human}}
		{sort distance}
	}
}

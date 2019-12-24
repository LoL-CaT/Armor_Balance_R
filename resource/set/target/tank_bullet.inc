{selector
 	{type "tank_bullet"}

	{group
		{ignore {class airborne}}
		{ignore {class attacker}}
		{ignore {class fighter}}
		{sort {class human} {weapon}}
		{sort {class car}}		
		{sort {class human}}
		{sort distance}
	}
}

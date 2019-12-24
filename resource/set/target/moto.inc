{selector
	{type "moto"}

	{group
		{ignore {class airborne}}
		{ignore {class attacker}}
		{ignore {class fighter}}
		{sort {class human} {weapon "ap"}}
		{sort {class human} {weapon}}
		{sort {class car}}
		{sort time_to_aim}
	}
	{group
		{sort distance}
	}
}
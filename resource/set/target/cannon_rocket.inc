{selector
	{type "cannon_rocket"}

	{group
		{ignore {class airborne}}
		{ignore {class attacker}}
		{ignore {class fighter}}
		{sort {class tank}}
		{sort {class armoredcar}}
		{sort {class car}}
		{sort {weapon "fg"}}
		{sort {weapon}}
		{sort distance}
	}

	{group
		{sort {attacking}}
		{sort distance}
	}
}

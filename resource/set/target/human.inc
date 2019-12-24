{selector
	{unit "human"}

	{group
		{ignore {class airborne}}
		{ignore {class attacker}}
		{ignore {class fighter}}
		{sort {in_range 20}}
		{sort {attacking}}
		{sort {class human} {weapon "bullet"}}
		{sort {class human} {weapon}}
		{sort {class tank}}
		{sort {class armoredcar}}
		{sort {weapon}}
		{sort {class human}}
		{sort distance}
	}
	{group
		{sort distance}
	}
}
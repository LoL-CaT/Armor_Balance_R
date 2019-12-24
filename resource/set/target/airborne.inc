{selector
	{type "airborne"}
	{group
		{select {weapon "airplane"}}
		{select {weapon "zenite"}}
		{select {weapon "ap"}}
		{select {weapon "hmgun"}}
		{select {weapon "bullet"}}
		{sort {weapon "airplane"}}
		{sort {weapon "zenite"}}
		{sort {weapon "ap"} {attacking} {class tank}}
		{sort {weapon "ap"} {attacking}}
		{sort {weapon "ap"} {threating} {class tank}}
		{sort {weapon "ap"} {threating}}
		{sort {weapon "ap"} {class tank}}
		{sort {weapon "ap"}}
		{sort {weapon "hmgun"}}
		{sort {weapon "bullet"}}
		{sort {weapon "bomb"}}
		{sort {weapon "torpedo"}}
		{sort {weapon}}
		{sort distance}
  	}
	{group
		{sort {class attacker}}
		{sort {class fighter}}
		{sort {class transport}}
		{sort {class airborne}}
		{sort {class armoredcar}}
		{sort {class car}}
		{sort {class human}}
		{sort {class tank}}
		{sort {attacking}}
		{sort distance}
	}
}

{selector
	{type "tank"}
	{group
		{ignore {class airborne}}
		{ignore {class attacker}}
		{ignore {class fighter}}
		{select {weapon "ap"}}
		{select {weapon "heat"}}		
		{select {weapon "apcr"}}
		{select {weapon "apds"}}
		{select {weapon "fg"}}
		{select {weapon "he"}}
		{select {weapon "znite"}}


		{sort {weapon "ap"} {attacking} {class tank}}
		{sort {weapon "heat"} {attacking} {class tank}}		
		{sort {weapon "ap"} {attacking}}
		{sort {weapon "heat"} {attacking}}
		{sort {weapon "ap"} {threating} {class tank}}
		{sort {weapon "heat"} {threating} {class tank}}
		{sort {weapon "ap"} {threating}}
		{sort {weapon "heat"} {threating}}
		{sort {weapon "ap"} {class tank}}
		{sort {weapon "heat"} {class tank}}
		{sort {weapon "zenite"} {attacking} {class tank}}
		{sort {weapon "zenite"} {attacking}}
		{sort {weapon "zenite"} {threating} {class tank}}
		{sort {weapon "zenite"} {threating}}
		{sort {weapon "zenite"} {class tank}}
		{sort {weapon "zenite"}}
		{sort {weapon "ap"}}
		{sort {weapon "heat"}}		
		{sort {weapon "apcr"}}
		{sort {weapon "apds"}}
		{sort {weapon "fg"} {attacking}}
		{sort {weapon "fg"} {threating}}
		{sort {weapon "fg"}}
		{sort {weapon "he"} {attacking}}
		{sort {weapon "he"} {threating}}
		{sort {weapon "he"}}
		{sort time_to_aim}
	}
	{group
		{sort {class tank}}
		{sort {class armoredcar}}		
    	{sort {attacking}}		
		{sort time_to_aim}
	}

}

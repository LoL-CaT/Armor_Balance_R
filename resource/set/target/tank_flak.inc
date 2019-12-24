{selector
	{type "tank_flak"}
	{group
		{select {class airborne}}	
		{select {weapon "hmgun"}}
		{select {weapon "bullet"}}
		{select {weapon "ap"}}
		{select {weapon "fg"}}	
		{select {weapon "he"}}		
		{select {weapon "znite"}}		
		
		{sort {weapon "ap"} {attacking} {class tank}}
		{sort {weapon "ap"} {attacking}}
		{sort {weapon "ap"} {threating} {class tank}}
		{sort {weapon "ap"} {threating}}
		{sort {weapon "ap"} {class tank}}
		{sort {weapon "ap"}}
		{sort {weapon "zenite"} {attacking} {class tank}}
		{sort {weapon "zenite"} {attacking}}
		{sort {weapon "zenite"} {threating} {class tank}}
		{sort {weapon "zenite"} {threating}}
		{sort {weapon "zenite"} {class tank}}
		{sort {weapon "zenite"}}		
		{sort {weapon "hmgun"}}
		{sort {weapon "bullet"}}
		{sort {weapon "he"} {attacking}}
		{sort {weapon "he"} {threating}}
		{sort {weapon "he"}}
		{sort {weapon "he"} {attacking}}
		{sort {weapon "he"} {threating}}
		{sort {weapon "he"}}		
		{sort {weapon}}
		{sort time_to_aim}
	}
	{group
		{sort {class tank}}
		{sort {class armoredcar}}
		{sort {class car}}
		{sort {class attacker}}
		{sort {class fighter}}
		{sort {class transport}}		
		{sort time_to_aim}
	}
}

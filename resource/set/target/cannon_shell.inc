{selector
 	{type "cannon_shell"}
	{group
		{ignore {class airborne}}
		{ignore {class attacker}}
		{ignore {class fighter}}	
;		{select {in_range 300}}	
    	{select {class car} {weapon "fg"}}		
    	{select {class human} {weapon "fg"}}
    	{select {class amoredcar}}		
		{select {class tank} {weapon "ap"}}
    	{select {class amoredcar}}
		{select {weapon "ap"}}
		{select {weapon "heat"}}		
		{select {weapon "fg"}}
		{select {weapon "he"}}
		{select {weapon "hmgun"}}		
		{sort distance}
	}
	{group
;		{sort {in_range 300}}		
		{sort {class tank} {weapon "ap"}}
		{sort {class armoredcar}}
		{sort {class car}}
    	{sort {attacking}}
    	{sort distance}
	}
}


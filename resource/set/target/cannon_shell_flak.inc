{selector
 	{type "cannon_shell_flak"}
	{group
   		{select {class airborne}}
		{select	{class human} {weapon "bullet"}}		
    	{select {class human} {weapon}}		
    	{select {class human}}	

		{sort {weapon "zenite"} {attacking} {class tank}}
		{sort {weapon "zenite"} {attacking}}
		{sort {weapon "zenite"} {threating} {class tank}}
		{sort {weapon "zenite"} {threating}}
		{sort {weapon "zenite"} {class tank}}
		{sort {weapon "zenite"}}		
		{sort {weapon} {attacking} {class human}}	
		{sort {weapon} {attacking}}	
		{sort {weapon} {threating} {class human}}
		{sort {weapon} {threating}}		
		{sort {weapon} {class human}}			
		{sort distance}
	}
	{group	
		{sort {class human} {weapon}}
		{sort {class human}}
		{sort {class attacker}}
		{sort {class fighter}}
		{sort {class transport}}		
    	{sort {attacking}}		
		{sort distance}
	}
}


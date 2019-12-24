{selector
  	{type "cannon_bullet_h_flak"}
	
	{group
   		{select {class airborne}}		
		{select	{class human} {weapon "bullet"}}		
    	{select {class human} {weapon}}		
    	{select {class human}}			
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

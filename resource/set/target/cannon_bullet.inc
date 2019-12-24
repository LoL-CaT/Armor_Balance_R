{selector
  	{type "cannon_bullet"}
  	{group
		{ignore {class airborne}}
		{ignore {class attacker}}
		{ignore {class fighter}}
    		{select {class human}}
    		{select {class car}}			
    		{sort {weapon}}
                {sort distance}
  	}

  	{group
    		{sort {class car}}	
    		{sort {class human}}	
    		{sort {attacking}}
                {sort distance}
  	}
}

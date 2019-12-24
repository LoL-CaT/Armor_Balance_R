{selector
  	{type "cannon_bullet_h"}
  	{group
		{ignore {class airborne}}
		{ignore {class attacker}}
		{ignore {class fighter}}
    		{select {class human}}
    		{select {class car}}			
;    		{sort {weapon "fg"}}
;    		{sort {weapon "he"}}
;    		{sort {weapon "ap"}}
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

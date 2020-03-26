; == STANDARD ==
(define "standard_all"
	{common
		{unitset
			{value "all"}
		}
		{commandPoints "*=%cp"}
;		{unitLimits "flamer=999;sniper_only=999;officer=999;heavyaa=999;single=999"}
		{balancingFactorBonus {cp 1.0} {mp 1.6} }
		{chargeFactors
			{value "*=1"}
		}
		{budgets
			{vehicle
				{mode "standard"}
				{resource 
					{start 		%start}
					{finish 	%finish}
					{growTime	8100}		; round time when money growing 
					{growTable 	"0.80 0.65 0.60 0.55 0.40 0.30 0.20"}
					{payback
						{cp 		"0		25		50 		70		100		130		160"}  
						{restore 	"4.5	3.2	    1.3	    1.2	    1.1	    0.4	    0.2"}
					}
				} 
				{buttons "squad1 squad2 v1 v2 v3 v4 v5 v6 v7 v8 v9 v10"}
			}
			{hero
				{resource 
					{start 		100}
				} 
				{buttons "hero"}
				{tag "special"}
			}
		}
	}
	{bots
		(include "bots_generic.inc")
	}
)


; == CUSTOM ==
(define "custom_all"
	{common
		{unitset
			{value "all"}
		}
		{commandPoints "*=%cp"}
;		{unitLimits "flamer=999;sniper_only=999;officer=1;heavyaa=999;single=999"}
		{balancingFactorBonus {cp 1.0} {mp 1.6} }
		{chargeFactors
			{value "*=1"}
		}
		{budgets
			{vehicle
				{mode "custom"}
				{resource 
					{start 		%start}
					{finish 	%finish}
					{growTime	8100}		; round time when money growing 
					{growTable 	"0.80 0.65 0.60 0.55 0.40 0.30 0.20"}
					{payback
						{cp 		"0		25		50 		70		100		130		160"}   
						{restore 	"4.5	3.2	    1.3	    1.2	    1.1	    0.4	    0.2"}
					}
					{limitmin	1000}
					{limitmax	50000}
					{speedset 	"2500 3000 3500 4000 4500 5000 9000 10000 20000 50000"}
				} 
				{buttons "squad1 squad2 v1 v2 v3 v4 v5 v6 v7 v8 v9 v10"}
			}
			{hero
				{resource 
					{start 		100}
				} 
				{buttons "hero"}
				{tag "special"}
			}
		} 
	}
	{bots
		(include "bots_generic.inc")
	}
)


;------------------------------------------------------------------------------------------------------------
{presets
	{"s:standard_100_all"	
		{gameMode "standard"}
		{unitMode "all"}
		{specMode "all_normal"}
		("standard_all" 		start(160) finish(6000) cp(180))
	}
	{"s:standard_160_all"	
		{gameMode "standard"}
		{unitMode "all"}
		{specMode "all_high"}
		("standard_all" 		start(1500) finish(6000) cp(260))
	}
	
;------------------------------------------------------------------------------------------------------------
	{"c:custom_50_all"
		{gameMode "custom"}
		{unitMode "all"}
		{specMode "cp_50"}
		("custom_all" 			start(160) finish(7000) cp(40))
	}
	{"c:custom_60_all"
		{gameMode "custom"}
		{unitMode "all"}
		{specMode "cp_60"}
		("custom_all" 			start(160) finish(7000) cp(50))
	}
	{"c:custom_80_all"
		{gameMode "custom"}
		{unitMode "all"}
		{specMode "cp_80"}
		("custom_all" 			start(160) finish(7000) cp(60)) 
	}
	{"c:custom_100_all"
		{gameMode "custom"}
		{unitMode "all"}
		{specMode "cp_100"}
		("custom_all" 			start(160) finish(7000) cp(70))
	}
	{"c:custom_120_all"
		{gameMode "custom"}
		{unitMode "all"}
		{specMode "cp_120"}
		("custom_all"  			start(160) finish(7000) cp(80))
	}
	{"c:custom_140_all"
		{gameMode "custom"}
		{unitMode "all"}
		{specMode "cp_140"}
		("custom_all"  			start(160) finish(7000) cp(90))
	}
	{"c:custom_160_all"
		{gameMode "custom"}
		{unitMode "all"}
		{specMode "cp_160"}
		("custom_all"  			start(160) finish(7000) cp(100))
	}
	{"c:custom_180_all"
		{gameMode "custom"}
		{unitMode "all"}
		{specMode "cp_180"}
		("custom_all"  			start(160) finish(7000) cp(120))
	}
	{"c:custom_200_all"
		{gameMode "custom"}
		{unitMode "all"}
		{specMode "cp_200"}
		("custom_all"  			start(160) finish(7000) cp(140))
	}
;------------------------------------------------------------------------------------------------------------
}
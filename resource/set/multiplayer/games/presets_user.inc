; == STANDARD ==
(define "standard_user"
	{common
		{unitset
			{value "all"}
			{available "all artillery heavyart cannon mediumcan heavycan arcade light medium heavy sheavy hero inf_only sniper_only supply"}
		}
		{commandPoints "*=%cp"}
		{unitLimits ""}
		{balancingFactorBonus {cp 1.0} {mp 1.0} }
		{chargeFactors
			{value "*=1.0"}
			{available "*=0 *=0.5 *=1.0 *=1.5 *=2.0 *=2.5 *=5.0 *=10.0"}
		}
		{budgets
			{vehicle
				{mode "standard"}
				{resource 
					{start 		%start}
					{finish 	%finish}
					{growTime	11000}		; round time when money growing 
					{growTable 	"1.50 1.51 1.52 1.53 1.54 1.55 1.56 1.57 1.58 1.59 1.60 1.61 1.62 1.63 1.64 1.65 1.66 1.67 1.68 1.69 1.70 1.71 1.72 1.73 1.74"}
					{payback
						{cp 		"0		25		50 		70		100		130		160"}  
						{restore 	"3.2	3.1	3.0	2.9	1.9	0.3	0.1"}
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
(define "custom_user"
	{common
		{unitset
			{value "all"}
			{available "all artillery heavyart cannon mediumcan heavycan arcade light medium heavy sheavy hero inf_only sniper_only supply"}
		}
		{commandPoints "*=%cp"}
		{unitLimits ""}
		{balancingFactorBonus {cp 1.0} {mp 1.0} }
		{chargeFactors
			{value "*=1"}
			{available "*=0 *=0.5 *=1.0 *=1.5 *=2.0 *=2.5 *=5.0 *=10.0"}
		}
		{budgets
			{vehicle
				{mode "custom"}
				{resource 
					{start 		%start}
					{finish 	%finish}
					{growTime	11000}		; round time when money growing 
					{growTable 	"1.50 1.51 1.52 1.53 1.54 1.55 1.56 1.57 1.58 1.59 1.60 1.61 1.62 1.63 1.64 1.65 1.66 1.67 1.68 1.69 1.70 1.71 1.72 1.73 1.74"}
					{payback
						{cp 		"0		25		50 		70		100		130		160"}   
						{restore 	"3.2	3.1	3.0	2.9	1.9	0.5	0.1"}
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
	{"s:standard_100_user"	
		{gameMode "standard"}
		{unitMode "user"}
		{specMode "all_normal"}
		("standard_user" 		start(160) finish(9000) cp(180))
	}
	{"s:standard_160_user"	
		{gameMode "standard"}
		{unitMode "user"}
		{specMode "all_high"}
		("standard_user" 		start(1500) finish(9000) cp(260))
	}
	
;------------------------------------------------------------------------------------------------------------
	{"c:custom_50_user"
		{gameMode "custom"}
		{unitMode "user"}
		{specMode "cp_50"}
		("custom_user" 			start(160) finish(3000) cp(50)) 
	}
	{"c:custom_60_user"
		{gameMode "custom"}
		{unitMode "user"}
		{specMode "cp_60"}
		("custom_user" 			start(160) finish(3000) cp(60)) 
	}
	{"c:custom_80_user"
		{gameMode "custom"}
		{unitMode "user"}
		{specMode "cp_80"}
		("custom_user" 			start(160) finish(3000) cp(80)) 
	}
	{"c:custom_100_user"
		{gameMode "custom"}
		{unitMode "user"}
		{specMode "cp_100"}
		("custom_user" 			start(160) finish(3000) cp(100))
	}
	{"c:custom_120_user"
		{gameMode "custom"}
		{unitMode "user"}
		{specMode "cp_120"}
		("custom_user"  		start(160) finish(3000) cp(120))
	}
	{"c:custom_140_user"
		{gameMode "custom"}
		{unitMode "user"}
		{specMode "cp_140"}
		("custom_user"  		start(160) finish(3000) cp(140))
	}
	{"c:custom_160_user"
		{gameMode "custom"}
		{unitMode "user"}
		{specMode "cp_160"}
		("custom_user"  		start(160) finish(3000) cp(160))
	}
	{"c:custom_180_user"
		{gameMode "custom"}
		{unitMode "user"}
		{specMode "cp_180"}
		("custom_user"  		start(160) finish(3000) cp(180))
	}
	{"c:custom_200_user"
		{gameMode "custom"}
		{unitMode "user"}
		{specMode "cp_200"}
		("custom_user"  		start(160) finish(3000) cp(200))
	}
;------------------------------------------------------------------------------------------------------------
}
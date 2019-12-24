; == STANDARD ==
(define "standard_all_8v8"
	{common
		{unitset
			{value "all"}
		}
		{commandPoints "*=%cp"}
;		{unitLimits "flamer=999;sniper_only=999;officer=999;heavyaa=999;single=999"}
		{balancingFactorBonus {cp 1.0} {mp 1.6} }
		{chargeFactors
			{value "*=2.0"}
		}
		{budgets
			{vehicle
				{mode "standard"}
				{resource 
					{start 		%start}
					{finish 	%finish}
					{growTime	18000}		; round time when money growing 
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


;------------------------------------------------------------------------------------------------------------
{presets
	{"s:standard_50_all_8v8"	
		{gameMode "standard"}
		{unitMode "all_8v8"}
		{specMode "all_8v8_normal"}
		("standard_all_8v8" 		start(160) finish(2500) cp(50))
		{ranked}
	}
;------------------------------------------------------------------------------------------------------------
}
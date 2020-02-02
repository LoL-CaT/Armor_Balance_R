	{any
		{translate_damage 450}		; damage multiplier for landmines
		{cover_hitchance 0.75}   	; the probability of hitting a soldier behind cover
		{crawl_hitchance 0.50}  	; the probabiltiy of hitting a soldier in crawl position
		{cover_damage 0.50}  		; damage when protected by cover

		{vehicle_burst 1.5}			; increase timeout between bursts for all vehicles
		{cover_mgun_burst 1}		; increase bullet count in 1 burst of soldier with mgun in horizontal cover
		{cover_mgun_delay 1}		; decrease timeout between bursts of soldier with mgun in horizontal cover

		{cover_efficiency			; how cover efficiency will drop with distance
			0		0
			1		0.15
			2		0.75
			3		1.00
		}
		{blast_crawl 2.00}			; simply lying on the ground
		{blast_cover 5.50}          ; in cover from protected side
		{blast_crawl_prepared 6.75}	; lying on the ground & waiting for explosion
		{blast_cover_prepared 9.00}	; in cover not from protected side, but waiting for explosion
		{blast_squat 1.50}			; on the knees
		
		;{mounted_mgun 3}
		{death_delay_min 45}		; min bleeding out time in seconds
		{death_delay_max 120}		; max bleeding out time in seconds
	}
;{levelofdetail
;	{"test"
;		{distance 700}		; LOD1
;		{distance 1000		; LOD2
;			{NoFog}
;			{NoGetShadow}
;			{NoCastShadow}
;			{off}
;		}
;	}
	(define "scale"
		(* 1.0 %d)
	)
	(mod "mp"
		(define "scale"
			(* 0.75 %d)
		)
	)
	(mod "coop"
		(define "scale"
			(* 0.70 %d)
		)
	)
	{"human"
		{distance ("scale" d(750))
			; LOD1
		}
		{distance ("scale" d(1400))
			; LOD2
		}
		{distance ("scale" d(2500))
			; LOD3
		}
		{distance ("scale" d(3000))
			{NoGetShadow}
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(4000))
			("off")
		}
	}
	{"vehicle_civilian"
		{distance ("scale" d(2500))
			; LOD1
		}
		{distance ("scale" d(3500))
			{NoGetShadow}
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(4000))
			("off")
		}
	}
	{"vehicle_small"
		{distance ("scale" d(2500))
			; LOD1
		}
		{distance ("scale" d(3500))
			{NoGetShadow}
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(5000))
			("off")
		}
	}
	{"vehicle_big"
		{distance ("scale" d(3000))
			; LOD1
		}
		{distance ("scale" d(4000))
			{NoGetShadow}
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(7000))
			("off")
		}
	}
	{"stuff_small"
		{distance ("scale" d(180))
			; LOD1
		}
		{distance ("scale" d(600))
			; LOD2
		}
		{distance ("scale" d(1000))
			{NoGetShadow}
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(1200))
			("off_small")
		}
	}
	{"part_small"
		{distance ("scale" d(400))
			; LOD1
		}
		{distance ("scale" d(800))
			; LOD2
		}
		{distance ("scale" d(1200))
			{NoGetShadow}
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(1500))
			("off_small")
		}
	}
	{"part_big"
		{distance ("scale" d(800))
			; LOD1
		}
		{distance ("scale" d(1200))
			; LOD2
		}
		{distance ("scale" d(1800))
			{NoGetShadow}
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(2000))
			("off")
		}
	}
	{"decor_tiny"
		{distance ("scale" d(200))
			; LOD1
		}
		{distance ("scale" d(600))
			; LOD2
		}
		{distance ("scale" d(900))
			{NoGetShadow}
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(1200))
			("off_small")
		}
	}
	{"decor_small"
		{distance ("scale" d(500))
			; LOD1
		}
		{distance ("scale" d(1200))
			; LOD2
		}
		{distance ("scale" d(1500))
			{NoGetShadow}
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(2000))
			("off_small")
		}
	}
	{"decor_medium"
		{distance ("scale" d(800))
			; LOD1
		}
		{distance ("scale" d(1600))
			; LOD2
		}
		{distance ("scale" d(2400))
			{NoGetShadow}
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(3000))
			("off")
		}
	}
	{"decor_big"
		{distance ("scale" d(800))
			; LOD1
		}
		{distance ("scale" d(1600))
			; LOD2
		}
		{distance ("scale" d(2400))
			{NoGetShadow}
			{NoFog}
			{NoCastShadow}
		}
	}
	{"decor_tree"
		{distance ("scale" d(500))
			; LOD1
		}
		{distance ("scale" d(800))
			; LOD2
		}
		{distance ("scale" d(1000))
			; LOD3
		}
		{distance ("scale" d(1500))
			{NoGetShadow}
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(2000))
			; LOD5
		}
	}
	{GrassDistance ("scale" d(2400))}
	{GrassFadeDepth ("scale" d(800))}
;}
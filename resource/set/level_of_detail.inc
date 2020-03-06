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
			(* 1.75 %d)
		)
	)
	(mod "coop"
		(define "scale"
			(* 1.70 %d)
		)
	)
	{"human"
		{distance ("scale" d(300))
			; LOD1
		}
		{distance ("scale" d(800))
			; LOD2
		}
		{distance ("scale" d(1500))
			; LOD3
		}
		{distance ("scale" d(2000))
			{NoGetShadow}
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(3500))
			("off")
		}
	}
	{"vehicle_civilian"
		{distance ("scale" d(1000))
			; LOD1
		}
		{distance ("scale" d(1500))
			{NoGetShadow}
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(2000))
			("off")
		}
	}
	{"vehicle_small"
		{distance ("scale" d(1500))
			; LOD1
		}
		{distance ("scale" d(2500))
			{NoGetShadow}
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(5000))
			("off")
		}
	}
	{"vehicle_big"
		{distance ("scale" d(2000))
			; LOD1
		}
		{distance ("scale" d(3000))
			{NoGetShadow}
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(6000))
			("off")
		}
	}
	{"stuff_small"
		{distance ("scale" d(180))
			; LOD1
		}
		{distance ("scale" d(300))
			; LOD2
		}
		{distance ("scale" d(600))
			{NoGetShadow}
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(800))
			("off_small")
		}
	}
	{"part_small"
		{distance ("scale" d(40))
			; LOD1
		}
		{distance ("scale" d(80))
			; LOD2
		}
		{distance ("scale" d(120))
			{NoGetShadow}
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(150))
			("off_small")
		}
	}
	{"part_big"
		{distance ("scale" d(80))
			; LOD1
		}
		{distance ("scale" d(120))
			; LOD2
		}
		{distance ("scale" d(180))
			{NoGetShadow}
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(200))
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
	{"decor_small"                   ; ежи и пр.
		{distance ("scale" d(750))
			; LOD1
		}
		{distance ("scale" d(1500))
			; LOD2
		}
		{distance ("scale" d(2000))
			{NoGetShadow}
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(3000))
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
		{distance ("scale" d(2500))
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
		{distance ("scale" d(2500))
			{NoGetShadow}
			{NoFog}
			{NoCastShadow}
		}
	}
	{"decor_tree"
		{distance ("scale" d(50))
			; LOD1
		}
		{distance ("scale" d(100))
			; LOD2
		}
		{distance ("scale" d(250))
			; LOD3
		}
		{distance ("scale" d(400))
			{NoGetShadow}
			{NoFog}
			{NoCastShadow}
		}
		{distance ("scale" d(600))
			; LOD5
		}
	}
	{GrassDistance ("scale" d(300))}
	{GrassFadeDepth ("scale" d(40))}
;}
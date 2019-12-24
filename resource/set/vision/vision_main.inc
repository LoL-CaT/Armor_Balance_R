;= HUMAN =====================================

{"human"
    ("uncover" u(44))
    ("h_fov" h(100))
    ("v_fov" v(100))
    ("vision_human")
}
{"mp_soldier"
    ("uncover" u(45))
    ("h_fov" h(100))
    ("v_fov" v(100))
    ("vision_human")
}
{"mp_officer"
    ("uncover" u(9999))
    ("h_fov" h(360))
    ("v_fov" v(360))
    ("visor_huizor")
}
{"mp_sniper"
    ("uncover" u(55))
    ("h_fov" h(150))
    ("v_fov" v(200))
    ("vision_human")
}

;= SPECIAL ===================================

{"soldier_focused"
    ("uncover" u(41))
    ("h_fov" h(100))
    ("v_fov" v(100))
    ("vision_human")
}
{"rifle_telescope"
    ("uncover" u(43))
    ("h_fov" h(360))
    ("v_fov" v(180))
    ("glass" args 7)
}
{"field_glass"
    ("uncover" u(43))
    ("h_fov" h(360))
    ("v_fov" v(180))
    ("glass" args 15)
}

;= CANNON ========================================

{"cannon_main"
    ("uncover" u())
    ("h_fov" h(45))
    ("v_fov" v(90))
    ("vision_optic" args 60)
}
{"cannon_main-far"
    ("uncover" u())
    ("h_fov" h(40))
    ("v_fov" v(90))
    ("vision_optic" args 60)
}
{"cannon_main_wide"
    ("uncover" u())
    ("h_fov" h(45))
    ("v_fov" v(90))
    ("vision_human")
}
{"cannon_mortar"
    ("uncover" u())
    ("h_fov" h(45))
    ("v_fov" v(90))
    ("vision_human")
}
{"cannon_mgun"
    ("uncover" u())
    ("h_fov" h(35))
    ("v_fov" v(100))
    ("vision_human")
}
{"cannon_crew"
    ("uncover" u())
    ("h_fov" h(250))
    ("v_fov" v(60))
    ("vision_humancrew")
}

;= VEHICLE & MOTO ============================

{"vehicle_main"
    ("uncover" u())
    ("h_fov" h(35))
    ("v_fov" v(75))
    ("vision_human")
}
{"vehicle_air"
   ("uncover" u(180))	
    ("h_fov" h(70))
    ("v_fov" v(85))
   ("vision_human_air")
}
{"vehicle_top_mgun"
    ("uncover" u(1))
    ("h_fov" h(70))
    ("v_fov" v(70))
    ("vision_human_air")
}
{"vehicle_top_turret"
    ("uncover" u())
    ("h_fov" h(25))
    ("v_fov" v(75))
    ("vision_turret" args 40)
}
{"moto"
    ("uncover" u())
    ("h_fov" h(30))
    ("v_fov" v(140))
    ("vision_human")
}
{"vehicle_around"
    ("uncover" u())
    ("h_fov" h(30))
    ("v_fov" v(90))
    ("vision_human")
}
{"moto_crew"
    ("uncover" u(180))
    ("h_fov" h(180))
    ("v_fov" v(100))
    ("vision_human")
}
{"moto_crew_h"
    ("uncover" u(220))
    ("h_fov" h(220))
    ("v_fov" v(100))
    ("vision_human")
}
{"moto_around"
    ("uncover" u(180))
    ("h_fov" h(180))
    ("v_fov" v(60))
    ("vision_human")
}

;= TANK ======================================

{"mg_remote"
    ("uncover" u())
    ("h_fov" h(5))
    ("v_fov" v(90))
    ("vision_optic")
}
{"mg_hull"
    ("uncover" u())
    ("h_fov" h(5))
    ("v_fov" v(90))
    ("vision_gunner" args 40)
}
{"tank_around-l"
	("vision_optic" args 1)
	{h_fov 360}
	{v_fov 40}
}
{"tank_around-m"
	("vision_optic" args 1.5)
	{h_fov 360}
	{v_fov 40}
}
{"tank_around-h"
	("vision_optic" args 2.0)
	{h_fov 360}
	{v_fov 40}
}
{"tank_main-l"
    ("uncover" u())
    ("h_fov" h(7))
    ("v_fov" v(25))
    ("vision_optic" args 40)
}
{"tank_main-m"
    ("uncover" u())
    ("h_fov" h(6))
    ("v_fov" v(25))
    ("vision_optic" args 40)
}
{"tank_main-h"
    ("uncover" u())
    ("h_fov" h(5))
    ("v_fov" v(25))
    ("vision_optic" args 40)
}
{"tank_driver"
    ("uncover" u())
    ("h_fov" h(60))
    ("v_fov" v(25))
    ("vision_gunner" args 40)
}
{"tank_driver_2"
    ("uncover" u())
    ("h_fov" h(12))
    ("v_fov" v(5))
    ("vision_gunner" args 40)
}
{"tank_back"
    ("uncover" u())
    ("h_fov" h(20))
    ("v_fov" v(20))
    ("vision_gunner" args 40)
}
{"tank_pr"
    ("uncover" u())
    ("h_fov" h(12))
    ("v_fov" v(30))
    ("vision_turret" args 40)
}
{"tank_gunner"		; gunner optics, should be a cone
    ("vision_optic" args 60) 			; detect tank/vehicle in 120m
	("h_fov" h(5))
	("v_fov" v(5))
}
{"tank_commander"	; commander optics, should be a circle
	("vision_optic" args 40) 			; detect tank/vehicle in 80m
	("h_fov" h(10))
	("v_fov" v(5))
}
{"none"
}

;--- работы Zeke Wolff и BTRH2ww ---
{"l_tank_unc"
    ("uncover" u(70))
    ("h_fov" h(12))
    ("v_fov" v(180))
    ("vision_optic")
}
{"tank_around-l"

}

{"tank_around-m"

}

{"tank_around-h"

}



{"Visor_Artil"
	    
}

{"Visor_BTR"
	    
}


{"Visor_CAY"
	   
}

{"sau_unc" ; данный визор наложен на основной и на дистанции до указанной_в_анковер не дает прятать танки за кустами и деревьями. Начиная с актор "average" значение должны быть идентичные значениям в визоре  "Visor_CAY"
 
 }

{"Visor_Tank_Long"
		
}

{"Visor_Tank"
	   
}

{"tank_unc" ; Начиная с актор "average" значение должны быть идентичные значениям в визоре  "Visor_Tank_Long" и "Visor_Tank"

}

{"Visor_cannon"
	   
}
	
{"cann_unc"
	   
}

;= OTHER ======================================

{"vehicle_airborne"
    ("uncover" u(5))
    ("h_fov" h(110))
    ("v_fov" v(180))
    ("vision_humancrew")
}
{"vehicle_airborne_3x"
    ("uncover" u(5))
    ("h_fov" h(110))
    ("v_fov" v(180))
    ("vision_optic")
}
{"air_around"       ;
    ("uncover" u(7))
    ("h_fov" h(360))
    ("v_fov" v(360))
    ("vision_seeair_around")
}
{"air"
    ("uncover" u(5))   
    ("h_fov" h(50))
    ("v_fov" v(50))
    ("vision_human_air")
}
{"vehicle_top_mgun_air"
    ("h_fov" h(90))
    ("v_fov" v(70))
    ("vision_human_air")
}
{"cannon_marine"
    ("uncover" u(5))
    ("h_fov" h(110))
    ("v_fov" v(110))
    ("vision_humancrew")
}
{"cover-detector"
	{uncover 45}
	{h_fov 60}
	{v_fov 120}
	("vision_optic" args 60)
}
{"animal"
	{uncover 42}
	{h_fov 360}
	{v_fov 120}
}
{"searchlight"
	{h_fov 20}
	{v_fov 90}
	("vision_optic" args 70)
}
{"watchtower"
	{h_fov 60}
	{v_fov 90}
    ("vision_optic" args 60)
}
{"marine_main"
	{h_fov 50}
	{v_fov 120}
    ("vision_optic" args 24)
}
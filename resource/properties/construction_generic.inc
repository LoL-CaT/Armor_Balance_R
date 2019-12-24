(define "declare_fire_volume"
	{Volume "fire%0"
		{able clear}
		{tags "fire"}
	}
	{Volume "smoke%0"
		{able clear}
		{tags "fire"}
	}
)
(define "declare_fire_volumes"
	{props "burning_old"}
	("declare_fire_volume" args 0)	("declare_fire_volume" args 1)
	("declare_fire_volume" args 2)	("declare_fire_volume" args 3)
	("declare_fire_volume" args 4)	("declare_fire_volume" args 5)
	("declare_fire_volume" args 6)	("declare_fire_volume" args 7)
	("declare_fire_volume" args 8)	("declare_fire_volume" args 9)
)
(define "armor_construction"
	{armor
		{setting "body"
			{threshold {pierce {calibre %calibre}}}
			{ray_cast_thickness 0}
			{volumes "body*"}
		}
		{setting "roof"
			{threshold {pierce {calibre %calibre}}}
			{ray_cast_thickness 0}
			{volumes "roof*"}
		}
	}
)

(define "blast_protection"
	{armor
		{setting "body"
			{threshold {blast {value %dmg}}}
		}
		{setting "roof"
			{threshold {blast {value %dmg}}}
		}
	}
)

(define "frag_grenade_protection"
	("blast_protection" dmg(11)) ; от 1.6 (было 9)
)

(define "armor_light"
	("armor_construction" calibre(19))   ; от 20мм   
)
(define "armor_medium"
	("armor_construction" calibre(58))	; до 57мм
	{armor
		{setting "body"
			{threshold  
				{blast {value 11}}	; не рушат автопушки
			}
			{durability 
				{blast {value 165}}	; 2 - 3 попадания 122мм
				{pierce {value 1000000}} ; практически не разрушить при пробитии			
			}
		}		
		{setting "roof"
			{threshold 
				{blast {value 11}} ; ; не рушат автопушки
			}
			{durability 
				{blast {value 25}}	; урон 75мм фугаса
				{pierce {value 1000000}} ; практически не разрушить при пробитии			
			}
		}	
	}
)
(define "armor_heavy"
	("armor_construction" calibre(139))	; пробой от калибра 140мм
	{armor
		{setting "body"
			{threshold  
				{blast {value 11}}	; не рушат автопушки
			}
			{durability 
				{blast {value 230}}	; 2 - 3 выстра 152мм
				{pierce {value 2000000}} ; практически не разрушить при пробитии			
			}
		}
		{setting "roof"
			{threshold 
				{blast {value 11}}
			}
			{durability 
				{blast {value 250}}	; урон 100мм фугса
				{pierce {value 2000000}} ; практически не разрушить при пробитии			
			}
		}
	}
)

(define "light_concrete"
	{armor
		{setting "body"
			{durability {pierce {koef 100000}}}
		}
		{setting "roof"
			{durability {pierce {koef 50000}}}
		}
	}
)

(define "armor_adjustable"
	{armor
		{setting "body"
			{threshold  {blast 	{value %thresh_fg}}
						{pierce {value %thresh_ap} {calibre %calibre}}}	
						
			{durability {blast 	{value %dur_fg}}
				 		{pierce {value %dur_ap}}}	
		}	
		{setting "roof"
			{threshold {blast {value 15}}}
			{durability {blast {value 100}}}	
		}
	}
)

(define "armor_house_wood"
	("armor_light")
	("frag_grenade_protection")
)

(define "armor_house_wood_heavy"
	("armor_light")
	("frag_grenade_protection")
)

(define "armor_house_concrete_light"
	("armor_medium")
	("frag_grenade_protection")
	("light_concrete")
)

(define "armor_house_concrete"
	("armor_heavy")
	("frag_grenade_protection")
	("light_concrete")
)


(define "armor_hedgehog"
	("armor_adjustable" thresh_fg(20) thresh_ap(45) dur_fg(30) dur_ap(500) calibre(70))
)

(define "armor_fabric"
	("armor_adjustable" thresh_fg(9) thresh_ap(0.5) dur_fg(5) dur_ap(10) calibre(0))
)

(define "armor_stack"
	("armor_adjustable" thresh_fg(9) thresh_ap(0.5) dur_fg(8) dur_ap(30) calibre(0))
)

(define "armor_glass"
	("armor_adjustable" thresh_fg(3) thresh_ap(0.2) dur_fg(4) dur_ap(30) calibre(0))
)

(define "armor_sandbag"
	("armor_adjustable" thresh_fg(10) thresh_ap(10) dur_fg(40) dur_ap(70) calibre(9))
)
(define "armor_sandbag_woodbeam"
	("armor_adjustable" thresh_fg(10) thresh_ap(10) dur_fg(40) dur_ap(80) calibre(9))
)
(define "armor_post"
	("armor_adjustable" thresh_fg(9) thresh_ap(2) dur_fg(2) dur_ap(2) calibre(0))
)
(define "armor_wires"
	("armor_adjustable" thresh_fg(9) thresh_ap(2) dur_fg(2) dur_ap(2) calibre(0))
)
(define "armor_fence_wood"
	("armor_adjustable" thresh_fg(9) thresh_ap(3) dur_fg(3) dur_ap(3) calibre(0))
)

(define "armor_use_volume_thickness"
	{armor
		{setting "body"
			{ray_cast_thickness 0}
		}
		{setting "roof"
			{ray_cast_thickness 0}
		}
	}
)

(define "armor_disable_damage_acc"
	{armor
		{setting "body"
			{disable_damage_acc}
		}
		{setting "roof"
			{disable_damage_acc}
		}
	}
)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(include "texmod.inc")

("armor_medium" args(1.0))

(define "firing"
	{welrod 0}
	{nagan_pb 0}	
	{nagan_pb_ger 0}	
	{mosin_m1938_bramit 0}
	{mosin_m1891_30s_bramit 0}	
	{mosin_s_bramit 0}	
	{delisle 0}
	{hdm 0}
	{sten_v_silencer 0}
	{sten_v_silencer_ger 0}
	{mp40_Hub 0}	
	
	{knife_ger 0}
	{knife_rus 0}
	{knife_union 0}
	{knife_japan 0}
	{axe 0}	
	{crow_bar 0} 
	{type_95 0}	
	
	{smoke 0.1}
	{rdg 0.1}
	{nebel39 0.1}
	{m18 0.1}	
	
	{smoke_paradrop_ammo 0.2}
	{smoke_paradrop_ammo_heavy 0.3}
	{eng_smoke_paradrop_ammo 0.2}
	{eng_smoke_paradrop_ammo_heavy 0.3}	
	{ger_smoke_paradrop_ammo 0.2}
	{ger_smoke_paradrop_ammo_heavy 0.3}
	{jap_smoke_paradrop_ammo 0.2}
	{jap_smoke_paradrop_ammo_heavy 0.3}	
	{rus_smoke_paradrop_ammo 0.2}
	{rus_smoke_paradrop_ammo_heavy 0.3}	
	{usa_smoke_paradrop_ammo 0.2}
	{usa_smoke_paradrop_ammo_heavy 0.3}	
	
	{czech_m34 0.4}
	{f1 0.4}
	{hungarian_36m 0.4}
	{hungarian_42m 0.4}
	{jap_type98 0.4}
	{m24 0.4}
	{m32 0.4}
	{m32mortar_shell 0.4}
	{m32mortar_shell2 0.4}
	{m39 0.3}
	{m61 0.4}
	{mk1 0.4}
	{mk2 0.4}
	{mk3 0.4}
	{n69 0.4}
	{OTO_mod35 0.4}
	{poland_o33 0.4}
	{poland_z33 0.4}
	{rg42 0.4}
	{rgd33 0.4}
	{rgd33r 0.4}
	{satchel 0.4}
	{type97 0.4}
	{type99 0.4}	
	
	{m24x5 0.6}
	{molotov_coctail 0.3}
	{n73at 0.6}
	{pwm1 0.6}
	{rg42x3 0.6}
	{rpg6  0.6}
	{rpg40 0.6}
	{rpg43 0.6}
	{type3at 0.6}
	{type3at_a 0.6}
	{type99at 0.6}	
	
	{incendiary 0.4}	
)
(define "vision"
	{cover 0.90
		{stand 0.90
			{stealth 0.75}		; 50%
		}
		{squat 0.85
			{stealth 0.35}		; 50%
		}
		{crawl 0.75
			{stealth 0.20}		; 50%
		}
    }
    {squat 0.85
        {stealth 0.60}			; 50%
	}
    {crawl 0.60
        {stealth 0.30}			; 50%
        {still 0.40
            {stealth 0.20}		; 50%
        }
    }
    {still 0.9}
    {visible 2.2}
)

(define "cannon"
        {cannon_01 1                     ; незаметность при движении
            {firing 1.6}
            {visible 1}                  ; дистанция того когда обнарженый остаёться видимым до разрыва зрения
            {still 1.2}                     ; дистанция на котрой остаёшься заметен всегда СТОЯ
        }
        {cannon_02 1.1
            {firing 1.6}
            {visible 1}
            {still 1.2}
        }
        {cannon_03 1.2
            {firing 1.6}
            {visible 1}
            {still 1.2}
        }
        {cannon_04 1.3
            {firing 2}
            {visible 1.1}
            {still 1.7}
        }
        {cannon_05 1.4
            {firing 2}
            {visible 1.1}
            {still 1.7}
        }
)
(define "tank"
        {vehicle_01 2.4
            {firing 2.9}
            {visible 2.2}
            {still 2.6}
        }
        {vehicle_02 2.6
            {firing 3.0}
            {visible 2.3}
            {still 2.7}
        }
        {vehicle_03 2.7
            {firing 3.0}
            {visible 2.4}
            {still 2.7}
        }
        {vehicle_04 2.8
            {firing 3.1}
            {visible 2.5}
            {still 2.8}
        }
        {vehicle_05 2.9
            {firing 3.2}
            {visible 2.6}
            {still 3.0}
        }
        {air 2.5
            {firing 3.4}
            {visible 2.7}
            {still 3.2}
        }		
)
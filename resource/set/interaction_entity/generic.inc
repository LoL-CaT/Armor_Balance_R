{"generic"
	{on bullet_hit
		{if not under_water
;flesh
			{if material "flesh"
				{if stuff "zenite"
					;{spawn "ex_air_norm"}
				else stuff "mortar"
					{spawn "ex_air_big"}
				else stuff "size4"
					{spawn "ex_air_big2"}
				else stuff "shell fg"
					{spawn "ex_air_big"}
				else stuff "bazooka"
					{spawn "ex_air_big"}
                                else stuff "mortar_fg_medium"
                                       {spawn "mortar_fg_medium_ground"}
                               
					;---------FG

				else stuff "mortar_fg_light"
				{spawn "mortar_fg_light_ground"}

				else stuff "mortar_fg_medium"
				{spawn "mortar_fg_medium_ground"}

				else stuff "mortar_fg_heavy"
				{spawn "mortar_fg_heavy_ground"}

					;---------AB

				else stuff "mortar_ab_light"
				{spawn "mortar_ab_light_ground"}  


				else stuff "mortar_ab_medium"
				{spawn "mortar_ab_medium_ground"} 

				else stuff "mortar_ab_heavy"
				{spawn "mortar_ab_heavy_ground"}  


					;---------IC 


				else stuff "mortar_ic_light"
				{spawn "mortar_ic_light_ground"}


				else stuff "mortar_ic_medium"
				{spawn "mortar_ic_medium_ground"}


				else stuff "mortar_ic_heavy"
				{spawn "mortar_ic_heavy_ground"}


					;---------SM

				else stuff "big smoke"
				{spawn "mortar_sm_light_ground"}


					;---------FL


				else stuff "mortar_flare_small"
				{spawn "mortar_fl_light_ground"}


				else stuff "mortar_flare_medium"
				{spawn "mortar_fl_medium_ground"}


				else stuff "mortar_flare_heavy"
				{spawn "mortar_fl_medium_ground"}



					;---------AR

				else stuff "flaerammo"
				{spawn "artillery_explosion_flaer"}





                                }
;steel
			else material "steel"
				{if stuff "bullet"
					{spawn "metal_hit_bul"}
                                        
				else stuff "mortar"
					{spawn "metal_hit_br"}
				else stuff "zenite"
					{spawn "metal_hit_bul"}
					{spawn "ex_air_sm"}
				else stuff "size4"
					{spawn "metal_hit_fg_big"}
				else stuff "shell small fg"
					{spawn "metal_hit_fg"}
				else stuff "shell small"
					{spawn "metal_hit_br_small"}
				else stuff "shell fg"
					{spawn "metal_hit_fg"}
				else stuff "shell"
					{spawn "metal_hit_br"}
					;{spawn "shellhole_custom_medium"}
				
			
					;---------FG

				else stuff "mortar_fg_light"
				{spawn "mortar_fg_light_ground"}

				else stuff "mortar_fg_medium"
				{spawn "mortar_fg_medium_ground"}

				else stuff "mortar_fg_heavy"
				{spawn "mortar_fg_heavy_ground"}

					;---------AB

				else stuff "mortar_ab_light"
				{spawn "mortar_ab_light_ground"}  


				else stuff "mortar_ab_medium"
				{spawn "mortar_ab_medium_ground"} 

				else stuff "mortar_ab_heavy"
				{spawn "mortar_ab_heavy_ground"}  


					;---------IC 


				else stuff "mortar_ic_light"
				{spawn "mortar_ic_light_ground"}


				else stuff "mortar_ic_medium"
				{spawn "mortar_ic_medium_ground"}


				else stuff "mortar_ic_heavy"
				{spawn "mortar_ic_heavy_ground"}


					;---------SM

				else stuff "big smoke"
				{spawn "mortar_sm_light_ground"}


					;---------FL


				else stuff "mortar_flare_small"
				{spawn "mortar_fl_light_ground"}


				else stuff "mortar_flare_medium"
				{spawn "mortar_fl_medium_ground"}


				else stuff "mortar_flare_heavy"
				{spawn "mortar_fl_medium_ground"}



					;---------AR

				else stuff "flaerammo"
				{spawn "artillery_explosion_flaer"}


                                }



else material "steelball"
				{spawn "metal_hit_bul"}
;wood
			else material "wood"
				{if stuff "bullet"
					{spawn "wood_hit_bul"}
				else stuff "mortar"
					{spawn "wood_hit_fg"}
				else stuff "zenite"
					{spawn "wood_hit_bul"}
				else stuff "shell small"
					{spawn "wood_hit_br_small"}
				else stuff "shell fg"
					{spawn "ex_mort_big"}
				else stuff "shell"
					{spawn "wood_hit_br"}

                                
					;---------FG

				else stuff "mortar_fg_light"
				{spawn "mortar_fg_light_ground"}

				else stuff "mortar_fg_medium"
				{spawn "mortar_fg_medium_ground"}

				else stuff "mortar_fg_heavy"
				{spawn "mortar_fg_heavy_ground"}

					;---------AB

				else stuff "mortar_ab_light"
				{spawn "mortar_ab_light_ground"}  


				else stuff "mortar_ab_medium"
				{spawn "mortar_ab_medium_ground"} 

				else stuff "mortar_ab_heavy"
				{spawn "mortar_ab_heavy_ground"}  


					;---------IC 


				else stuff "mortar_ic_light"
				{spawn "mortar_ic_light_ground"}


				else stuff "mortar_ic_medium"
				{spawn "mortar_ic_medium_ground"}


				else stuff "mortar_ic_heavy"
				{spawn "mortar_ic_heavy_ground"}


					;---------SM

				else stuff "big smoke"
				{spawn "mortar_sm_light_ground"}


					;---------FL


				else stuff "mortar_flare_small"
				{spawn "mortar_fl_light_ground"}


				else stuff "mortar_flare_medium"
				{spawn "mortar_fl_medium_ground"}


				else stuff "mortar_flare_heavy"
				{spawn "mortar_fl_medium_ground"}



					;---------AR

				else stuff "flaerammo"
				{spawn "artillery_explosion_flaer"}





				}
;concrete
			else material "concrete"
				{if stuff "bullet"
					{spawn "stone_hit_bul"}
					{spawn "ex_air_sm"}
				else stuff "zenite"
					{spawn "stone_hit_bul"}
					{spawn "ex_air_sm"}
				else stuff "big shell fg"
				 	{spawn	"stone_hit_br_big"}
				else stuff "shell small"
				 	{spawn	"stone_hit_br_small"}
				else
				 	{spawn	"stone_hit_br"}
                                
					;---------FG

				else stuff "mortar_fg_light"
				{spawn "mortar_fg_light_ground"}

				else stuff "mortar_fg_medium"
				{spawn "mortar_fg_medium_ground"}

				else stuff "mortar_fg_heavy"
				{spawn "mortar_fg_heavy_ground"}

					;---------AB

				else stuff "mortar_ab_light"
				{spawn "mortar_ab_light_ground"}  


				else stuff "mortar_ab_medium"
				{spawn "mortar_ab_medium_ground"} 

				else stuff "mortar_ab_heavy"
				{spawn "mortar_ab_heavy_ground"}  


					;---------IC 


				else stuff "mortar_ic_light"
				{spawn "mortar_ic_light_ground"}


				else stuff "mortar_ic_medium"
				{spawn "mortar_ic_medium_ground"}


				else stuff "mortar_ic_heavy"
				{spawn "mortar_ic_heavy_ground"}


					;---------SM

				else stuff "big smoke"
				{spawn "mortar_sm_light_ground"}


					;---------FL


				else stuff "mortar_flare_small"
				{spawn "mortar_fl_light_ground"}


				else stuff "mortar_flare_medium"
				{spawn "mortar_fl_medium_ground"}


				else stuff "mortar_flare_heavy"
				{spawn "mortar_fl_medium_ground"}



					;---------AR

				else stuff "flaerammo"
				{spawn "artillery_explosion_flaer"}


                                
				}
;sand
			else material "sand"
				{if stuff "zenite"
					{spawn "ex_air_sm"}
					{spawn "sand_hit_bul"}
				else stuff "mortar"
					{spawn "ex_mort_sm"}
				else stuff "shell fg"
					{spawn "ex_mort_big"}
				else stuff "bazooka"
					{spawn "ex_air_big"}
				else
					{spawn "sand_hit_small"}

                                
					;---------FG

				else stuff "mortar_fg_light"
				{spawn "mortar_fg_light_ground"}

				else stuff "mortar_fg_medium"
				{spawn "mortar_fg_medium_ground"}

				else stuff "mortar_fg_heavy"
				{spawn "mortar_fg_heavy_ground"}

					;---------AB

				else stuff "mortar_ab_light"
				{spawn "mortar_ab_light_ground"}  


				else stuff "mortar_ab_medium"
				{spawn "mortar_ab_medium_ground"} 

				else stuff "mortar_ab_heavy"
				{spawn "mortar_ab_heavy_ground"}  


					;---------IC 


				else stuff "mortar_ic_light"
				{spawn "mortar_ic_light_ground"}


				else stuff "mortar_ic_medium"
				{spawn "mortar_ic_medium_ground"}


				else stuff "mortar_ic_heavy"
				{spawn "mortar_ic_heavy_ground"}


					;---------SM

				else stuff "big smoke"
				{spawn "mortar_sm_light_ground"}


					;---------FL


				else stuff "mortar_flare_small"
				{spawn "mortar_fl_light_ground"}


				else stuff "mortar_flare_medium"
				{spawn "mortar_fl_medium_ground"}


				else stuff "mortar_flare_heavy"
				{spawn "mortar_fl_medium_ground"}



					;---------AR

				else stuff "flaerammo"
				{spawn "artillery_explosion_flaer"}


                                
				}
;ice
			else material "ice"
				{if stuff "shell fg"
					{spawn "ex_mort_sm_snow"}
				else
					{spawn "snow_hit_small"}
				}
			}
		}
	}
}
(include "inc/generic_NP.inc")
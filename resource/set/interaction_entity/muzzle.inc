{"muzzle_zenite"; 12 - 20
	{on spawn
		{add_view	"flash_cannon_small"		"flashbarrel1"			"Foresight1"}
		{add_view	"flash_cannon_small"		"flashbarrel2"			"Foresight2"}	
		{add_view	"flash_cannon_small"		"flashbarrel3"			"Foresight3"}
		{add_view	"flash_cannon_small"		"flashbarrel4"			"Foresight4"}		
		{add_view	"smoke_zenite"			"smoke_gun1" 			"Foresight1"}
		{add_view	"smoke_zenite"			"smoke_gun2" 			"Foresight2"}
		{add_view	"smoke_zenite"			"smoke_gun3" 			"Foresight3"}
		{add_view	"smoke_zenite"			"smoke_gun4" 			"Foresight4"}		
	}
	{on fire "gun"
	        {spawn "tank_canon_fire_verysmall" 		"Foresight1" x}
	        {spawn "tank_canon_fire_verysmall" 		"Foresight2" x}
	        {spawn "tank_canon_fire_verysmall" 		"Foresight3" x}
	        {spawn "tank_canon_fire_verysmall" 		"Foresight4" x}			
		{view start "smoke_gun1"}
		{view start "smoke_gun2"}
		{view start "smoke_gun3"}
		{view start "smoke_gun4"}		
		{delay 1 0.5
			{view stop "smoke_gun1"}
			{view stop "smoke_gun2"}
			{view stop "smoke_gun3"}
			{view stop "smoke_gun4"}			
			{add_view	"smoke_zenite"			"smoke_gun1" 			"Foresight1"}
			{add_view	"smoke_zenite"			"smoke_gun2" 			"Foresight2"}
			{add_view	"smoke_zenite"			"smoke_gun3" 			"Foresight3"}
			{add_view	"smoke_zenite"			"smoke_gun4" 			"Foresight4"}			
		}
	}
}

{"muzzle_minimum" ; 35 - 45
	{on spawn
		{add_view	"flash_cannon_small"		"flashbarrel1"			"Foresight1"}
		{add_view	"smoke_zenite"			"smoke_gun1" 			"Foresight1"}
		{add_view	"smoke_zenite"			"smoke_gun2" 			"Foresight2"}
	}
	{on fire "gun"
	       	{spawn "dust_shot_small" 				"basis"}
        	{spawn "tank_canon_fire_verysmall" 		"Foresight1" x}
		{view start "smoke_gun1"}
		{view start "smoke_gun2"}
		{delay 2 0.5
			{view stop "smoke_gun1"}
			{view stop "smoke_gun2"}
			{add_view	"smoke_zenite"			"smoke_gun1" 			"Foresight1"}
			{add_view	"smoke_zenite"			"smoke_gun2" 			"Foresight2"}
		}
	}
}	

{"muzzle_minimum2" ; 35 - 45 & 75 
	{on spawn
		{add_view	"flash_cannon_small"		"flashbarrel1"			"Foresight1"}		
		{add_view	"flash_cannon_medium"		"flashbarrel2"			"Foresight2"}
		{add_view	"smoke_zenite"			"smoke_gun1" 			"Foresight1"}		
		{add_view	"smoke_grey_storeable"		"smoke_gun2" 			"Foresight2"}		
	}
	{on fire "gun"
	       	{spawn "dust_shot_small" 				"basis"}
        	{spawn "tank_canon_fire_verysmall" 		"Foresight1" x}
		{view start "smoke_gun1"}
		{delay 2 0.5
			{view stop "smoke_gun1"}
			{add_view	"smoke_zenite"			"smoke_gun1" 			"Foresight1"}
		}
	}
	{on fire "gun2"
       		{spawn "dust_shot_norm" 				"basis"}
        	{spawn "tank_canon_fire_medium" 		"Foresight2" x}
		{blastwave c4 0 r0 0 r1 0 bone 		"Foresight1"}
		{view start "smoke_gun2"}
		{delay 3 1
			{view stop "smoke_gun2"}
			{add_view	"smoke_grey_storeable"			"smoke_gun2" 			"Foresight2"}
		}	
	}	
}

{"muzzle_small2" ; 47 - 57 & 75 
	{on spawn
		{add_view	"flash_cannon_small"		"flashbarrel1"			"Foresight1"}		
		{add_view	"flash_cannon_medium"		"flashbarrel2"			"Foresight2"}
		{add_view	"smoke_grey"			"smoke_gun1" 			"Foresight1"}		
		{add_view	"smoke_grey_storeable"		"smoke_gun2" 			"Foresight2"}		
	}
	{on fire "gun"
       		{spawn "dust_shot_small" 				"basis"}
        	{spawn "tank_canon_fire_medium" 			"Foresight1" x}
		{view start "smoke_gun1"}
		{delay 2 0.5
			{view stop "smoke_gun1"}
			{add_view	"smoke_grey"			"smoke_gun1" 			"Foresight1"}
		}
	}
	{on fire "gun2"
       		{spawn "dust_shot_norm" 				"basis"}
        	{spawn "tank_canon_fire_medium" 		"Foresight2" x}
		{blastwave c4 0 r0 0 r1 0 bone 		"Foresight1"}
		{view start "smoke_gun2"}
		{delay 3 1
			{view stop "smoke_gun2"}
			{add_view	"smoke_grey_storeable"			"smoke_gun2" 			"Foresight2"}
		}	
	}	
}

{"muzzle_small" ; 47 - 57
	{on spawn
		{add_view	"flash_cannon_small"		"flashbarrel1"			"Foresight1"}
		{add_view	"smoke_grey"			"smoke_gun1" 			"Foresight1"}
		{add_view	"smoke_grey"			"smoke_gun2" 			"Foresight2"}
	}
	{on fire "gun"
       		{spawn "dust_shot_small" 				"basis"}
        	{spawn "tank_canon_fire_medium" 			"Foresight1" x}
		{view start "smoke_gun1"}
		{view start "smoke_gun2"}
		{delay 2 0.5
			{view stop "smoke_gun1"}
			{view stop "smoke_gun2"}
			{add_view	"smoke_grey"			"smoke_gun1" 			"Foresight1"}
			{add_view	"smoke_grey"			"smoke_gun2" 			"Foresight2"}
		}
	}
}		
	
{"muzzle_medium" ; 70 - 94
	{on spawn                                                                                            
		{add_view	"flash_cannon_medium"		"flashbarrel1"			"Foresight1"}
		{add_view	"flash_cannon_medium"		"flashbarrel2"			"Foresight2"}
		{add_view	"smoke_grey_storeable"		"smoke_gun1" 			"Foresight1"}
		{add_view	"smoke_grey_storeable"		"smoke_gun2" 			"Foresight2"}
	}
	{on fire "gun"
       		{spawn "dust_shot_norm" 				"basis"}
        	{spawn "tank_canon_fire_large" 		"Foresight1" x}
		{blastwave c4 0 r0 0 r1 0 bone 		"Foresight1"}
		{view start "smoke_gun1"}
		{view start "smoke_gun2"}
		{delay 3 1
			{view stop "smoke_gun1"}
			{view stop "smoke_gun2"}
			{add_view	"smoke_grey_storeable"			"smoke_gun1" 			"Foresight1"}
			{add_view	"smoke_grey_storeable"			"smoke_gun2" 			"Foresight2"}
		}
	}
}

{"muzzle_medium2" ; 70 - 94 & 37
	{on spawn
		{add_view	"flash_cannon_medium"		"flashbarrel1"			"Foresight1"}
		{add_view	"flash_cannon_small"		"flashbarrel2"			"Foresight2"}
		{add_view	"smoke_grey_storeable"		"smoke_gun1" 			"Foresight1"}
		{add_view	"smoke_zenite"			"smoke_gun2" 			"Foresight2"}		
	}
	{on fire "gun"
       		{spawn "dust_shot_norm" 				"basis"}
        	{spawn "tank_canon_fire_large" 		"Foresight1" x}
		{blastwave c4 0 r0 0 r1 0 bone 		"Foresight1"}
		{view start "smoke_gun1"}
		{delay 3 1
			{view stop "smoke_gun1"}
			{add_view	"smoke_grey_storeable"			"smoke_gun1" 			"Foresight1"}
		}
	}
	{on fire "gun2"
	       	{spawn "dust_shot_small" 				"basis"}
        	{spawn "tank_canon_fire_verysmall" 		"Foresight2" x}
		{view start "smoke_gun2"}
		{delay 2 0.5
			{view stop "smoke_gun2"}
			{add_view	"smoke_zenite"			"smoke_gun2" 			"Foresight2"}
	    }	
	}	
}
	
{"muzzle_large" ; 100 - 128
	{on spawn                                                                                            
		{add_view	"flash_cannon_medium"		"flashbarrel1"			"Foresight1"}
		{add_view	"flash_cannon_medium"		"flashbarrel2"			"Foresight2"}
		{add_view	"smoke_white"			"smoke_gun1" 			"Foresight1"}
		{add_view	"smoke_white"			"smoke_gun2" 			"Foresight2"}
	}
	{on fire "gun"
      		{spawn "dust_shot_big" 					"basis"}
      		{spawn "tank_canon_fire_verylarge" 			"Foresight1" x}
		{blastwave c4 0 r0 0 r1 0 bone 		"Foresight1"}
		{view start "smoke_gun1"}
		{view start "smoke_gun2"}
		{delay 5 1.5
			{view stop "smoke_gun1"}
			{view stop "smoke_gun2"}
			{add_view	"smoke_white"			"smoke_gun1" 			"Foresight1"}
			{add_view	"smoke_white"			"smoke_gun2" 			"Foresight2"}
		}
	}
}
 
{"muzzle_large2" ; 100 - 128 & 75
	{on spawn                                                                                            
		{add_view	"flash_cannon_medium"		"flashbarrel1"			"Foresight1"}
		{add_view	"flash_cannon_medium"		"flashbarrel2"			"Foresight2"}
		{add_view	"smoke_white"			"smoke_gun1" 			"Foresight1"}		
		{add_view	"smoke_grey_storeable"		"smoke_gun2" 			"Foresight2"}		
	}
	{on fire "gun"
      		{spawn "dust_shot_big" 					"basis"}
      		{spawn "tank_canon_fire_verylarge" 			"Foresight1" x}
		{blastwave c4 0 r0 0 r1 0 bone 		"Foresight1"}
		{view start "smoke_gun1"}
		{delay 5 1.5
			{view stop "smoke_gun1"}
			{add_view	"smoke_white"			"smoke_gun1" 			"Foresight1"}
		}
	}
	{on fire "gun2"
       		{spawn "dust_shot_norm" 				"basis"}
        	{spawn "tank_canon_fire_medium" 		"Foresight2" x}
		{blastwave c4 0 r0 0 r1 0 bone 		"Foresight1"}
		{view start "smoke_gun2"}
		{delay 3 1
			{view stop "smoke_gun2"}
			{add_view	"smoke_grey_storeable"			"smoke_gun2" 			"Foresight2"}
		}
	}	
}
	
{"muzzle_maximum2" ; 150 + & 75
	{on spawn
		{add_view	"flash_cannon_big"		"flashbarrel1"			"Foresight1"}
		{add_view	"flash_cannon_medium"		"flashbarrel2"			"Foresight2"}		
		{add_view	"smoke_white"			"smoke_gun1" 			"Foresight1"}
		{add_view	"smoke_grey"			"smoke_gun1" 			"Foresight1"}
		{add_view	"smoke_grey_storeable"		"smoke_gun2" 			"Foresight2"}			
	}
	{on fire "gun"
		{spawn "dust_shot_big" 						"basis"}
        	{spawn "tank_canon_fire_small" 		"Foresight1" x}
		{blastwave c4 0 r0 0 r1 0 bone 		"Foresight1"}
		{view start "smoke_gun1"}
		{delay 7 2
			{view stop "smoke_gun1"}
			{add_view	"smoke_white"			"smoke_gun1" 			"Foresight1"}
			{add_view	"smoke_grey"			"smoke_gun1" 			"Foresight1"}
		}
	}
	{on fire "gun2"
       		{spawn "dust_shot_norm" 				"basis"}
        	{spawn "tank_canon_fire_medium" 		"Foresight2" x}
		{blastwave c4 0 r0 0 r1 0 bone 		"Foresight1"}
		{view start "smoke_gun2"}
		{delay 3 1
			{view stop "smoke_gun2"}
			{add_view	"smoke_grey_storeable"			"smoke_gun2" 			"Foresight2"}
		}
	}	
}

{"muzzle_maximum3" ; 150 + & 20
	{on spawn
		{add_view	"flash_cannon_big"	     "flashbarrel1"	        "Foresight1"}
		{add_view	"flash_cannon_small"		"flashbarrel2"			"Foresight2"}
		{add_view	"smoke_white"			"smoke_gun1" 			"Foresight1"}
		{add_view	"smoke_grey"			"smoke_gun1" 			"Foresight1"}		
		{add_view	"smoke_zenite"			"smoke_gun2" 			"Foresight2"}		
	}
	{on fire "gun"
		{spawn "dust_shot_big" 						"basis"}
        	{spawn "tank_canon_fire_small" 		"Foresight1" x}
		{blastwave c4 0 r0 0 r1 0 bone 		"Foresight1"}
		{view start "smoke_gun1"}
		{delay 7 2
			{view stop "smoke_gun1"}
			{add_view	"smoke_white"			"smoke_gun1" 			"Foresight1"}
			{add_view	"smoke_grey"			"smoke_gun1" 			"Foresight1"}
		}
	}			
	{on fire "gun2"
        {spawn "tank_canon_fire_verysmall" 		"Foresight2" x}
	}	
}

{"muzzle_maximum3_mg" ; 150 + & 37 MG
	{on spawn
		{add_view	"flash_cannon_big"	     "flashbarrel1"	        "Foresight1"}
		{add_view	"flash_cannon_small"		"flashbarrel2"			"Foresight30"}
		{add_view	"flash_cannon_small"		"flashbarrel2"			"Foresight31"}		
		{add_view	"smoke_white"			"smoke_gun1" 			"Foresight1"}
		{add_view	"smoke_grey"			"smoke_gun1" 			"Foresight1"}	
		{add_view	"smoke_zenite"			"smoke_gun2" 			"Foresight30"}			
		{add_view	"smoke_zenite"			"smoke_gun2" 			"Foresight31"}	
	}
	{on fire "gun"
		{spawn "dust_shot_big" 						"basis"}
        	{spawn "tank_canon_fire_small" 		"Foresight1" x}
		{blastwave c4 0 r0 0 r1 0 bone 		"Foresight1"}
		{view start "smoke_gun1"}
		{delay 7 2
			{view stop "smoke_gun1"}
			{add_view	"smoke_white"			"smoke_gun1" 			"Foresight1"}
			{add_view	"smoke_grey"			"smoke_gun1" 			"Foresight1"}
		}
	}			
	{on fire "mgun30"
	       	{spawn "dust_shot_small" 				"basis"}
        	{spawn "tank_canon_fire_verysmall" 		"Foresight30" x}
		{view start "smoke_gun2"}
		{delay 2 0.5
			{view stop "smoke_gun2"}
			{add_view	"smoke_zenite"			"smoke_gun2" 			"Foresight30"}
	    }	
	}
	{on fire "mgun31"
	       	{spawn "dust_shot_small" 				"basis"}
        	{spawn "tank_canon_fire_verysmall" 		"Foresight31" x}
		{view start "smoke_gun2"}
		{delay 2 0.5
			{view stop "smoke_gun2"}
			{add_view	"smoke_zenite"			"smoke_gun2" 			"Foresight31"}
	    }	
	}	
}	

{"muzzle_maximum" ; 150 +
	{on spawn
		{add_view	"flash_cannon_big"		"flashbarrel1"			"Foresight1"}
		{add_view	"flash_cannon_big"		"flashbarrel2"			"Foresight2"} 
		{add_view	"smoke_white"			"smoke_gun1" 			"Foresight1"}
		{add_view	"smoke_white"			"smoke_gun2" 			"Foresight2"}
		{add_view	"smoke_grey"			"smoke_gun1" 			"Foresight1"}
		{add_view	"smoke_grey"			"smoke_gun2" 			"Foresight2"}
	}
	{on fire "gun"
		{spawn "dust_shot_big" 						"basis"}
        	{spawn "tank_canon_fire_small" 		"Foresight1" x}
		{blastwave c4 0 r0 0 r1 0 bone 		"Foresight1"}
		{view start "smoke_gun1"}
		{view start "smoke_gun2"}
		{delay 7 2
			{view stop "smoke_gun1"}
			{view stop "smoke_gun2"}
			{add_view	"smoke_white"			"smoke_gun1" 			"Foresight1"}
			{add_view	"smoke_white"			"smoke_gun2" 			"Foresight2"}
			{add_view	"smoke_grey"			"smoke_gun1" 			"Foresight1"}
			{add_view	"smoke_grey"			"smoke_gun2" 			"Foresight2"}
		}		
	}
} 
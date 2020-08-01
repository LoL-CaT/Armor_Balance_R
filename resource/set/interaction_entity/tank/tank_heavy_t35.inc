; T-35
{on pierce
   ;///////////////////////////////////////////////////////// Bullet
    ("damage_process_pierce"
        staff(bullet)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0)
;///////Engineer_Den + ////////////////	
        pierce_gun2(0)
        pierce_gun3(0)
;///////Engineer_Den - ////////////////		
        pierce_front_back_track(0)
        pierce_left_right_track(0)
        pierce_inventory__explosive(0)
    ;--------------------------
        pierce_body__burn(0)
        pierce_body__body_brake(0.10)
        pierce_body__body_destroy(0)
    ;--------------------------
		  crew_shock_time(0)
    ;--------------------------
        pierce_turret__explosive(0)
;///////Engineer_Den + ////////////////
         pierce_turret4__explosive(0)
         pierce_turret5__explosive(0)	
;///////Engineer_Den - ////////////////		

        pierce_turret_front__turret_brake(0)
        pierce_turret_back__turret_brake(0)
        pierce_turret_left_right__turret_brake(0)
		
;///////Engineer_Den + ////////////////
        pierce_turret2_front__turret2_brake(0)
        pierce_turret2_back__turret2_brake(0)
        pierce_turret2_left_right__turret2_brake(0)
        pierce_turret3_front__turret3_brake(0)
        pierce_turret3_back__turret3_brake(0)
        pierce_turret3_left_right__turret3_brake(0)
        pierce_turret4_front__turret4_brake(0)
        pierce_turret4_back__turret4_brake(0)
        pierce_turret4_left_right__turret4_brake(0)
        pierce_turret5_front__turret5_brake(0)
        pierce_turret5_back__turret5_brake(0)
        pierce_turret5_left_right__turret5_brake(0)
        pierce_turret4_front__gun2_brake(0)   pierce_mantlet2__gun2_brake(0)
        pierce_turret4_back__gun2_brake(0)
        pierce_turret4_left_right__gun2_brake(0.10)
        pierce_turret5_front__gun3_brake(0)   pierce_mantlet3__gun3_brake(0)
        pierce_turret5_back__gun3_brake(0)
        pierce_turret5_left_right__gun3_brake(0)
;///////Engineer_Den - ////////////////
		
        pierce_turret_back__turret_brake(0)
        pierce_turret_left_right__turret_brake(0)

        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(0)
        pierce_engine__engine_burn(0)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.10)
        pierce_body__kill_gunner(0.10)
        pierce_body__kill_driver(0.10)
        pierce_body__kill_commander(0.10)
        pierce_body__kill_gunner2(0.10)
		
;///////Engineer_Den+ ////////////////
        pierce_body__kill_radist(0.10)
        pierce_turret__kill_radist(0.10)

        pierce_body__kill_gunner3(0.10)
        pierce_turret2__kill_gunner3(0.10)
        pierce_body__kill_gunner4(0.10)
        pierce_turret3__kill_gunner4(0.10)
        pierce_body__kill_gunner5(0.10)
        pierce_turret4__kill_gunner5(0.10)
        pierce_body__kill_charger5(0.10)
        pierce_turret4__kill_charger5(0.10)
        pierce_body__kill_gunner6(0.10)
        pierce_turret5__kill_gunner6(0.10)
        pierce_body__kill_charger6(0.10)
        pierce_turret5__kill_charger6(0.10)
;///////Engineer_Den - ////////////////			
    ;--------------------------
        pierce_turret__kill_charger(0.10)
        pierce_turret__kill_gunner(0.10)
        pierce_turret__kill_driver(0.10)
        pierce_turret__kill_commander(0.10)
        pierce_turret__kill_gunner2(0.10)
    )
	;///////////////////////////////////////////////////////// Heavy bullet
    ("damage_process_pierce"
        staff(hbullet)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0)
;///////Engineer_Den + ////////////////	
        pierce_gun2(0)
        pierce_gun3(0)
;///////Engineer_Den - ////////////////		
        pierce_front_back_track(0)
        pierce_left_right_track(0)
        pierce_inventory__explosive(0)
    ;--------------------------
        pierce_body__burn(0.1)
        pierce_body__body_brake(0.4)
        pierce_body__body_destroy(0.1)
    ;--------------------------
		  crew_shock_time(0)
    ;--------------------------
        pierce_turret__explosive(0.1)
;///////Engineer_Den + ////////////////
         pierce_turret4__explosive(0.1)
         pierce_turret5__explosive(0.1)	
;///////Engineer_Den - ////////////////		

        pierce_turret_front__turret_brake(0)
        pierce_turret_back__turret_brake(0)
        pierce_turret_left_right__turret_brake(0)

;///////Engineer_Den + ////////////////
        pierce_turret2_front__turret2_brake(0)
        pierce_turret2_back__turret2_brake(0)
        pierce_turret2_left_right__turret2_brake(0)
        pierce_turret3_front__turret3_brake(0)
        pierce_turret3_back__turret3_brake(0)
        pierce_turret3_left_right__turret3_brake(0)
        pierce_turret4_front__turret4_brake(0)
        pierce_turret4_back__turret4_brake(0)
        pierce_turret4_left_right__turret4_brake(0)
        pierce_turret5_front__turret5_brake(0)
        pierce_turret5_back__turret5_brake(0)
        pierce_turret5_left_right__turret5_brake(0)
        pierce_turret4_front__gun2_brake(0)   pierce_mantlet2__gun2_brake(0)
        pierce_turret4_back__gun2_brake(0)
        pierce_turret4_left_right__gun2_brake(0)
        pierce_turret5_front__gun3_brake(0)   pierce_mantlet3__gun3_brake(0)
        pierce_turret5_back__gun3_brake(0)
        pierce_turret5_left_right__gun3_brake(0)
;///////Engineer_Den - ////////////////		

        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(0)
        pierce_engine__engine_burn(0)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.10)
        pierce_body__kill_gunner(0.10)
        pierce_body__kill_driver(0.10)
        pierce_body__kill_commander(0.10)
        pierce_body__kill_gunner2(0.10)
;///////Engineer_Den+ ////////////////
        pierce_body__kill_radist(0.10)
        pierce_turret__kill_radist(0.10)

        pierce_body__kill_gunner3(0.10)
        pierce_turret2__kill_gunner3(0.10)
        pierce_body__kill_gunner4(0.10)
        pierce_turret3__kill_gunner4(0.10)
        pierce_body__kill_gunner5(0)
        pierce_turret4__kill_gunner5(0.10)
        pierce_body__kill_charger5(0.10)
        pierce_turret4__kill_charger5(0.10)
        pierce_body__kill_gunner6(0.10)
        pierce_turret5__kill_gunner6(0.10)
        pierce_body__kill_charger6(0.10)
        pierce_turret5__kill_charger6(0.10)
;///////Engineer_Den - ////////////////			
    ;--------------------------
        pierce_turret__kill_charger(0.10)
        pierce_turret__kill_gunner(0.10)
        pierce_turret__kill_driver(0.10)
        pierce_turret__kill_commander(0.10)
        pierce_turret__kill_gunner2(0.10)
    )	
    ;///////////////////////////////////////////////////////// Ptr bullet
   ("damage_process_pierce"
        staff(ptr)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.01)	
;///////Engineer_Den + ////////////////	
        pierce_gun2(0.01)
        pierce_gun3(0.01)
;///////Engineer_Den - ////////////////		
        pierce_front_back_track(0.1)
        pierce_left_right_track(0)
        pierce_inventory__explosive(0)
    ;--------------------------
        pierce_body__burn(0.1)
        pierce_body__body_brake(0)
        pierce_body__body_destroy(0)
    ;--------------------------
		  crew_shock_time(0)
    ;--------------------------
        pierce_turret__explosive(0)

;///////Engineer_Den + ////////////////
         pierce_turret4__explosive(0)
         pierce_turret5__explosive(0)	
;///////Engineer_Den - ////////////////		

        pierce_turret_front__turret_brake(0.1)
        pierce_turret_back__turret_brake(0.1)
        pierce_turret_left_right__turret_brake(0.1)
		
;///////Engineer_Den + ////////////////
        pierce_turret2_front__turret2_brake(0.1)
        pierce_turret2_back__turret2_brake(0.1)
        pierce_turret2_left_right__turret2_brake(0.1)
        pierce_turret3_front__turret3_brake(0.1)
        pierce_turret3_back__turret3_brake(0.1)
        pierce_turret3_left_right__turret3_brake(0.1)
        pierce_turret4_front__turret4_brake(0.1)
        pierce_turret4_back__turret4_brake(0.1)
        pierce_turret4_left_right__turret4_brake(0.1)
        pierce_turret5_front__turret5_brake(0.1)
        pierce_turret5_back__turret5_brake(0.1)
        pierce_turret5_left_right__turret5_brake(0.1)
        pierce_turret4_front__gun2_brake(0)   pierce_mantlet2__gun2_brake(0)
        pierce_turret4_back__gun2_brake(0)
        pierce_turret4_left_right__gun2_brake(0)
        pierce_turret5_front__gun3_brake(0)   pierce_mantlet3__gun3_brake(0)
        pierce_turret5_back__gun3_brake(0)
        pierce_turret5_left_right__gun3_brake(0)
;///////Engineer_Den - ////////////////		

        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(0)
        pierce_engine__engine_burn(0)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.10)
        pierce_body__kill_gunner(0.10)
        pierce_body__kill_driver(0.10)
        pierce_body__kill_commander(0.10)
        pierce_body__kill_gunner2(0.10)
;///////Engineer_Den+ ////////////////
        pierce_body__kill_radist(0.10)
        pierce_turret__kill_radist(0.10)

        pierce_body__kill_gunner3(0.10)
        pierce_turret2__kill_gunner3(0.10)
        pierce_body__kill_gunner4(0.10)
        pierce_turret3__kill_gunner4(0.10)
        pierce_body__kill_gunner5(0.10)
        pierce_turret4__kill_gunner5(0.10)
        pierce_body__kill_charger5(0.10)
        pierce_turret4__kill_charger5(0.10)
        pierce_body__kill_gunner6(0.10)
        pierce_turret5__kill_gunner6(0.10)
        pierce_body__kill_charger6(0.10)
        pierce_turret5__kill_charger6(0.10)
;///////Engineer_Den - ////////////////			
    ;--------------------------
        pierce_turret__kill_charger(0.10)
        pierce_turret__kill_gunner(0.10)
        pierce_turret__kill_driver(0.10)
        pierce_turret__kill_commander(0.10)
        pierce_turret__kill_gunner2(0.10)
    )
    ;///////////////////////////////////////////////////////// Gun shells AP 14 - 19
   ("damage_process_pierce"
        staff(ap_14_19aa)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.01)
;///////Engineer_Den + ////////////////	
        pierce_gun2(0.01)
        pierce_gun3(0.01)
;///////Engineer_Den - ////////////////		
        pierce_front_back_track(0.1)
        pierce_left_right_track(0)
        pierce_inventory__explosive(0)
    ;--------------------------
        pierce_body__burn(0.1)
        pierce_body__body_brake(0)
        pierce_body__body_destroy(0)
    ;--------------------------
		  crew_shock_time(0)
    ;--------------------------
        pierce_turret__explosive(0)
;///////Engineer_Den + ////////////////
         pierce_turret4__explosive(0)
         pierce_turret5__explosive(0)	
;///////Engineer_Den - ////////////////		

        pierce_turret_front__turret_brake(0.1)
        pierce_turret_back__turret_brake(0.1)
        pierce_turret_left_right__turret_brake(0.1)

;///////Engineer_Den + ////////////////
        pierce_turret2_front__turret2_brake(0.1)
        pierce_turret2_back__turret2_brake(0.1)
        pierce_turret2_left_right__turret2_brake(0.1)
        pierce_turret3_front__turret3_brake(0.1)
        pierce_turret3_back__turret3_brake(0.1)
        pierce_turret3_left_right__turret3_brake(0.1)
        pierce_turret4_front__turret4_brake(0.1)
        pierce_turret4_back__turret4_brake(0.1)
        pierce_turret4_left_right__turret4_brake(0.1)
        pierce_turret5_front__turret5_brake(0.1)
        pierce_turret5_back__turret5_brake(0.1)
        pierce_turret5_left_right__turret5_brake(0.1)
        pierce_turret4_front__gun2_brake(0)   pierce_mantlet2__gun2_brake(0)
        pierce_turret4_back__gun2_brake(0)
        pierce_turret4_left_right__gun2_brake(0)
        pierce_turret5_front__gun3_brake(0)   pierce_mantlet3__gun3_brake(0)
        pierce_turret5_back__gun3_brake(0)
        pierce_turret5_left_right__gun3_brake(0)
;///////Engineer_Den - ////////////////		
		
        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(0)
        pierce_engine__engine_burn(0)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.10)
        pierce_body__kill_gunner(0.10)
        pierce_body__kill_driver(0.10)
        pierce_body__kill_commander(0.10)
        pierce_body__kill_gunner2(0.10)
;///////Engineer_Den+ ////////////////
        pierce_body__kill_radist(0.10)
        pierce_turret__kill_radist(0.10)

        pierce_body__kill_gunner3(0.10)
        pierce_turret2__kill_gunner3(0.10)
        pierce_body__kill_gunner4(0.10)
        pierce_turret3__kill_gunner4(0.10)
        pierce_body__kill_gunner5(0.10)
        pierce_turret4__kill_gunner5(0.10)
        pierce_body__kill_charger5(0.10)
        pierce_turret4__kill_charger5(0.10)
        pierce_body__kill_gunner6(0.10)
        pierce_turret5__kill_gunner6(0.10)
        pierce_body__kill_charger6(0.10)
        pierce_turret5__kill_charger6(0.10)
;///////Engineer_Den - ////////////////			
    ;--------------------------
        pierce_turret__kill_charger(0.10)
        pierce_turret__kill_gunner(0.10)
        pierce_turret__kill_driver(0.10)
        pierce_turret__kill_commander(0.10)
        pierce_turret__kill_gunner2(0.10)
    )
    ;///////////////////////////////////////////////////////// Gun shells AP 20 - 28	
   ("damage_process_pierce"
        staff(ap_20_28aa)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.01)
;///////Engineer_Den + ////////////////	
        pierce_gun2(0.01)
        pierce_gun3(0.01)
;///////Engineer_Den - ////////////////		
        pierce_front_back_track(0)
        pierce_left_right_track(0)
        pierce_inventory__explosive(0.1)
    ;--------------------------
        pierce_body__burn(0.2)
        pierce_body__body_brake(0.10)
        pierce_body__body_destroy(0.1)
    ;--------------------------
		  crew_shock_time(0)
    ;--------------------------
        pierce_turret__explosive(0)
;///////Engineer_Den + ////////////////
         pierce_turret4__explosive(0)
         pierce_turret5__explosive(0)	
;///////Engineer_Den - ////////////////			

        pierce_turret_front__turret_brake(0.50)
        pierce_turret_back__turret_brake(0.50)
        pierce_turret_left_right__turret_brake(0.50)
		
;///////Engineer_Den + ////////////////
        pierce_turret2_front__turret2_brake(0.50)
        pierce_turret2_back__turret2_brake(0.50)
        pierce_turret2_left_right__turret2_brake(0.50)
        pierce_turret3_front__turret3_brake(0.50)
        pierce_turret3_back__turret3_brake(0.50)
        pierce_turret3_left_right__turret3_brake(0.50)
        pierce_turret4_front__turret4_brake(0.50)
        pierce_turret4_back__turret4_brake(0.50)
        pierce_turret4_left_right__turret4_brake(0.50)
        pierce_turret5_front__turret5_brake(0.50)
        pierce_turret5_back__turret5_brake(0.50)
        pierce_turret5_left_right__turret5_brake(0.50)
        pierce_turret4_front__gun2_brake(0)   pierce_mantlet2__gun2_brake(0)
        pierce_turret4_back__gun2_brake(0)
        pierce_turret4_left_right__gun2_brake(0)
        pierce_turret5_front__gun3_brake(0)   pierce_mantlet3__gun3_brake(0)
        pierce_turret5_back__gun3_brake(0)
        pierce_turret5_left_right__gun3_brake(0)
;///////Engineer_Den - ////////////////			

        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(0)
        pierce_engine__engine_burn(0)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.10)
        pierce_body__kill_gunner(0.10)
        pierce_body__kill_driver(0.10)
        pierce_body__kill_commander(0.10)
        pierce_body__kill_gunner2(0.10)
;///////Engineer_Den+ ////////////////
        pierce_body__kill_radist(0.10)
        pierce_turret__kill_radist(0.10)

        pierce_body__kill_gunner3(0.10)
        pierce_turret2__kill_gunner3(0.10)
        pierce_body__kill_gunner4(0.10)
        pierce_turret3__kill_gunner4(0.10)
        pierce_body__kill_gunner5(0.10)
        pierce_turret4__kill_gunner5(0.10)
        pierce_body__kill_charger5(0.10)
        pierce_turret4__kill_charger5(0.10)
        pierce_body__kill_gunner6(0.10)
        pierce_turret5__kill_gunner6(0.10)
        pierce_body__kill_charger6(0.10)
        pierce_turret5__kill_charger6(0.10)
;///////Engineer_Den - ////////////////			
    ;--------------------------
        pierce_turret__kill_charger(0.10)
        pierce_turret__kill_gunner(0.10)
        pierce_turret__kill_driver(0.10)
        pierce_turret__kill_commander(0.10)
        pierce_turret__kill_gunner2(0.10)
    )
    ;///////////////////////////////////////////////////////// Gun shells AP 30 - 37	
   ("damage_process_pierce"
        staff(ap_30_37aa)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.01)
;///////Engineer_Den + ////////////////	
        pierce_gun2(0.01)
        pierce_gun3(0.01)
;///////Engineer_Den - ////////////////		
        pierce_front_back_track(0)
        pierce_left_right_track(0)
        pierce_inventory__explosive(0.1)
    ;--------------------------
        pierce_body__burn(0.2)
        pierce_body__body_brake(0.50)
        pierce_body__body_destroy(0.1)
    ;--------------------------
		  crew_shock_time(0)
    ;--------------------------
        pierce_turret__explosive(0)
;///////Engineer_Den + ////////////////
         pierce_turret4__explosive(0)
         pierce_turret5__explosive(0)	
;///////Engineer_Den - ////////////////			

        pierce_turret_front__turret_brake(0.50)
        pierce_turret_back__turret_brake(0.50)
        pierce_turret_left_right__turret_brake(0.50)
		
;///////Engineer_Den + ////////////////
        pierce_turret2_front__turret2_brake(0.50)
        pierce_turret2_back__turret2_brake(0.50)
        pierce_turret2_left_right__turret2_brake(0.50)
        pierce_turret3_front__turret3_brake(0.50)
        pierce_turret3_back__turret3_brake(0.50)
        pierce_turret3_left_right__turret3_brake(0.50)
        pierce_turret4_front__turret4_brake(0.50)
        pierce_turret4_back__turret4_brake(0.50)
        pierce_turret4_left_right__turret4_brake(0.50)
        pierce_turret5_front__turret5_brake(0.50)
        pierce_turret5_back__turret5_brake(0.50)
        pierce_turret5_left_right__turret5_brake(0.50)
        pierce_turret4_front__gun2_brake(0)   pierce_mantlet2__gun2_brake(0)
        pierce_turret4_back__gun2_brake(0)
        pierce_turret4_left_right__gun2_brake(0)
        pierce_turret5_front__gun3_brake(0)   pierce_mantlet3__gun3_brake(0)
        pierce_turret5_back__gun3_brake(0)
        pierce_turret5_left_right__gun3_brake(0)
;///////Engineer_Den - ////////////////			

        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(0)
        pierce_engine__engine_burn(0)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.10)
        pierce_body__kill_gunner(0.10)
        pierce_body__kill_driver(0.10)
        pierce_body__kill_commander(0.10)
        pierce_body__kill_gunner2(0.10)
;///////Engineer_Den+ ////////////////
        pierce_body__kill_radist(0.10)
        pierce_turret__kill_radist(0.10)

        pierce_body__kill_gunner3(0.10)
        pierce_turret2__kill_gunner3(0.10)
        pierce_body__kill_gunner4(0.10)
        pierce_turret3__kill_gunner4(0.10)
        pierce_body__kill_gunner5(0.10)
        pierce_turret4__kill_gunner5(0.10)
        pierce_body__kill_charger5(0.10)
        pierce_turret4__kill_charger5(0.10)
        pierce_body__kill_gunner6(0.10)
        pierce_turret5__kill_gunner6(0.10)
        pierce_body__kill_charger6(0.10)
        pierce_turret5__kill_charger6(0.10)
;///////Engineer_Den - ////////////////			
    ;--------------------------
        pierce_turret__kill_charger(0.10)
        pierce_turret__kill_gunner(0.10)
        pierce_turret__kill_driver(0.10)
        pierce_turret__kill_commander(0.10)
        pierce_turret__kill_gunner2(0.10)
    )	
    ;///////////////////////////////////////////////////////// Gun shells AP 40 - 57
   ("damage_process_pierce"	
        staff(ap_40_57aa)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.01)
;///////Engineer_Den + ////////////////	
        pierce_gun2(0.01)
        pierce_gun3(0.01)
;///////Engineer_Den - ////////////////		
        pierce_front_back_track(0.01)
        pierce_left_right_track(0)
        pierce_inventory__explosive(0.1)
    ;--------------------------
        pierce_body__burn(0.2)
        pierce_body__body_brake(0.65)
        pierce_body__body_destroy(0.40)
    ;--------------------------
		  crew_shock_time(0)
    ;--------------------------
        pierce_turret__explosive(0)
;///////Engineer_Den + ////////////////
         pierce_turret4__explosive(0)
         pierce_turret5__explosive(0)	
;///////Engineer_Den - ////////////////			

        pierce_turret_front__turret_brake(0.65)
        pierce_turret_back__turret_brake(0.50)
        pierce_turret_left_right__turret_brake(0.50)
		
;///////Engineer_Den + ////////////////
        pierce_turret2_front__turret2_brake(0.50)
        pierce_turret2_back__turret2_brake(0.50)
        pierce_turret2_left_right__turret2_brake(0.50)
        pierce_turret3_front__turret3_brake(0.50)
        pierce_turret3_back__turret3_brake(0.50)
        pierce_turret3_left_right__turret3_brake(0.50)
        pierce_turret4_front__turret4_brake(0.50)
        pierce_turret4_back__turret4_brake(0.50)
        pierce_turret4_left_right__turret4_brake(0.50)
        pierce_turret5_front__turret5_brake(0.50)
        pierce_turret5_back__turret5_brake(0.50)
        pierce_turret5_left_right__turret5_brake(0.50)
        pierce_turret4_front__gun2_brake(0)   pierce_mantlet2__gun2_brake(0)
        pierce_turret4_back__gun2_brake(0)
        pierce_turret4_left_right__gun2_brake(0)
        pierce_turret5_front__gun3_brake(0)   pierce_mantlet3__gun3_brake(0)
        pierce_turret5_back__gun3_brake(0)
        pierce_turret5_left_right__gun3_brake(0)
;///////Engineer_Den - ////////////////		

        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(0)
        pierce_engine__engine_burn(0)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.10)
        pierce_body__kill_gunner(0.10)
        pierce_body__kill_driver(0.10)
        pierce_body__kill_commander(0.10)
        pierce_body__kill_gunner2(0.10)
;///////Engineer_Den+ ////////////////
        pierce_body__kill_radist(0.10)
        pierce_turret__kill_radist(0.10)

        pierce_body__kill_gunner3(0.10)
        pierce_turret2__kill_gunner3(0.10)
        pierce_body__kill_gunner4(0.10)
        pierce_turret3__kill_gunner4(0.10)
        pierce_body__kill_gunner5(0.10)
        pierce_turret4__kill_gunner5(0.10)
        pierce_body__kill_charger5(0.10)
        pierce_turret4__kill_charger5(0.10)
        pierce_body__kill_gunner6(0.10)
        pierce_turret5__kill_gunner6(0.10)
        pierce_body__kill_charger6(0.10)
        pierce_turret5__kill_charger6(0.10)
;///////Engineer_Den - ////////////////			
    ;--------------------------
        pierce_turret__kill_charger(0.10)
        pierce_turret__kill_gunner(0.10)
        pierce_turret__kill_driver(0.10)
        pierce_turret__kill_commander(0.10)
        pierce_turret__kill_gunner2(0.10)
    )
    ;///////////////////////////////////////////////////////// Gun shells AP 70 - 77
   ("damage_process_pierce"	
        staff(ap_70_77aa)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.1)
;///////Engineer_Den + ////////////////	
        pierce_gun2(0.1)
        pierce_gun3(0.1)
;///////Engineer_Den - ////////////////		
        pierce_front_back_track(0.1)
        pierce_left_right_track(0.01)
        pierce_inventory__explosive(0.1)
    ;--------------------------
        pierce_body__burn(0.5)
        pierce_body__body_brake(0.55)
        pierce_body__body_destroy(0.75)
    ;--------------------------
		  crew_shock_time(0.30)
    ;--------------------------
        pierce_turret__explosive(0.2)
;///////Engineer_Den + ////////////////
         pierce_turret4__explosive(0.2)
         pierce_turret5__explosive(0.2)	
;///////Engineer_Den - ////////////////			

        pierce_turret_front__turret_brake(0.50)
        pierce_turret_back__turret_brake(0.50)
        pierce_turret_left_right__turret_brake(0.50)
		
;///////Engineer_Den + ////////////////
        pierce_turret2_front__turret2_brake(0.50)
        pierce_turret2_back__turret2_brake(0.50)
        pierce_turret2_left_right__turret2_brake(0.50)
        pierce_turret3_front__turret3_brake(0.50)
        pierce_turret3_back__turret3_brake(0.50)
        pierce_turret3_left_right__turret3_brake(0.50)
        pierce_turret4_front__turret4_brake(0.50)
        pierce_turret4_back__turret4_brake(0.50)
        pierce_turret4_left_right__turret4_brake(0.50)
        pierce_turret5_front__turret5_brake(0.50)
        pierce_turret5_back__turret5_brake(0.50)
        pierce_turret5_left_right__turret5_brake(0.50)
        pierce_turret4_front__gun2_brake(0)   pierce_mantlet2__gun2_brake(0)
        pierce_turret4_back__gun2_brake(0)
        pierce_turret4_left_right__gun2_brake(0)
        pierce_turret5_front__gun3_brake(0)   pierce_mantlet3__gun3_brake(0)
        pierce_turret5_back__gun3_brake(0)
        pierce_turret5_left_right__gun3_brake(0)
;///////Engineer_Den - ////////////////			

        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(0)
        pierce_engine__engine_burn(0)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.40)
        pierce_body__kill_gunner(0.40)
        pierce_body__kill_driver(0.40)
        pierce_body__kill_commander(0.40)
        pierce_body__kill_gunner2(0.40)
;///////Engineer_Den+ ////////////////
        pierce_body__kill_radist(0.40)
        pierce_turret__kill_radist(0.40)

        pierce_body__kill_gunner3(0.40)
        pierce_turret2__kill_gunner3(0.40)
        pierce_body__kill_gunner4(0.40)
        pierce_turret3__kill_gunner4(0.40)
        pierce_body__kill_gunner5(0.40)
        pierce_turret4__kill_gunner5(0.40)
        pierce_body__kill_charger5(0.40)
        pierce_turret4__kill_charger5(0.40)
        pierce_body__kill_gunner6(0.40)
        pierce_turret5__kill_gunner6(0.40)
        pierce_body__kill_charger6(0.40)
        pierce_turret5__kill_charger6(0.40)
;///////Engineer_Den - ////////////////			
    ;--------------------------
        pierce_turret__kill_charger(0.40)
        pierce_turret__kill_gunner(0.40)
        pierce_turret__kill_driver(0.40)
        pierce_turret__kill_commander(0.40)
        pierce_turret__kill_gunner2(0.40)
    )	
    ;///////////////////////////////////////////////////////// Gun shells AP 80 - 95
   ("damage_process_pierce"	
        staff(ap_80_95aa)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.2)
;///////Engineer_Den + ////////////////	
        pierce_gun2(0.2)
        pierce_gun3(0.2)
;///////Engineer_Den - ////////////////		
        pierce_front_back_track(0.5)
        pierce_left_right_track(0.1)
        pierce_inventory__explosive(0.2)
    ;--------------------------
        pierce_body__burn(0.5)
        pierce_body__body_brake(0.25)
        pierce_body__body_destroy(0.85)
    ;--------------------------
		  crew_shock_time(3.95)
    ;--------------------------
        pierce_turret__explosive(0.2)
;///////Engineer_Den + ////////////////
         pierce_turret4__explosive(0.2)
         pierce_turret5__explosive(0.2)	
;///////Engineer_Den - ////////////////			

        pierce_turret_front__turret_brake(0.99)
        pierce_turret_back__turret_brake(0.99)
        pierce_turret_left_right__turret_brake(0.99)
		
;///////Engineer_Den + ////////////////
        pierce_turret2_front__turret2_brake(0.99)
        pierce_turret2_back__turret2_brake(0.99)
        pierce_turret2_left_right__turret2_brake(0.99)
        pierce_turret3_front__turret3_brake(0.99)
        pierce_turret3_back__turret3_brake(0.99)
        pierce_turret3_left_right__turret3_brake(0.99)
        pierce_turret4_front__turret4_brake(0.99)
        pierce_turret4_back__turret4_brake(0.99)
        pierce_turret4_left_right__turret4_brake(0.99)
        pierce_turret5_front__turret5_brake(0.99)
        pierce_turret5_back__turret5_brake(0.99)
        pierce_turret5_left_right__turret5_brake(0.99)
        pierce_turret4_front__gun2_brake(0)   pierce_mantlet2__gun2_brake(0)
        pierce_turret4_back__gun2_brake(0)
        pierce_turret4_left_right__gun2_brake(0)
        pierce_turret5_front__gun3_brake(0)   pierce_mantlet3__gun3_brake(0)
        pierce_turret5_back__gun3_brake(0)
        pierce_turret5_left_right__gun3_brake(0)
;///////Engineer_Den - ////////////////		

        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(0)
        pierce_engine__engine_burn(0)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.60)
        pierce_body__kill_gunner(0.60)
        pierce_body__kill_driver(0.60)
        pierce_body__kill_commander(0.60)
        pierce_body__kill_gunner2(0.60)
;///////Engineer_Den+ ////////////////
        pierce_body__kill_radist(0.60)
        pierce_turret__kill_radist(0.60)

        pierce_body__kill_gunner3(0.60)
        pierce_turret2__kill_gunner3(0.60)
        pierce_body__kill_gunner4(0.60)
        pierce_turret3__kill_gunner4(0.60)
        pierce_body__kill_gunner5(0.60)
        pierce_turret4__kill_gunner5(0.60)
        pierce_body__kill_charger5(0.60)
        pierce_turret4__kill_charger5(0.60)
        pierce_body__kill_gunner6(0.60)
        pierce_turret5__kill_gunner6(0.60)
        pierce_body__kill_charger6(0.60)
        pierce_turret5__kill_charger6(0.60)
;///////Engineer_Den - ////////////////			
    ;--------------------------
        pierce_turret__kill_charger(0.60)
        pierce_turret__kill_gunner(0.60)
        pierce_turret__kill_driver(0.60)
        pierce_turret__kill_commander(0.60)
        pierce_turret__kill_gunner2(0.60)
    )	
    ;///////////////////////////////////////////////////////// Gun shells AP 100 - 107
   ("damage_process_pierce"   
        staff(ap_100_107aa)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.2)
;///////Engineer_Den + ////////////////	
        pierce_gun2(0.2)
        pierce_gun3(0.2)
;///////Engineer_Den - ////////////////			
        pierce_front_back_track(0.10)
        pierce_left_right_track(0.1)
        pierce_inventory__explosive(0.2)
    ;--------------------------
        pierce_body__burn(0.5)
        pierce_body__body_brake(0.15)
        pierce_body__body_destroy(0.90)
    ;--------------------------
		  crew_shock_time(3.95)
    ;--------------------------
        pierce_turret__explosive(0.2)
;///////Engineer_Den + ////////////////
         pierce_turret4__explosive(0.2)
         pierce_turret5__explosive(0.2)	
;///////Engineer_Den - ////////////////			

        pierce_turret_front__turret_brake(0.99)
        pierce_turret_back__turret_brake(0.99)
        pierce_turret_left_right__turret_brake(0.99)
		
;///////Engineer_Den + ////////////////
        pierce_turret2_front__turret2_brake(0.99)
        pierce_turret2_back__turret2_brake(0.99)
        pierce_turret2_left_right__turret2_brake(0.99)
        pierce_turret3_front__turret3_brake(0.99)
        pierce_turret3_back__turret3_brake(0.99)
        pierce_turret3_left_right__turret3_brake(0.99)
        pierce_turret4_front__turret4_brake(0.99)
        pierce_turret4_back__turret4_brake(0.99)
        pierce_turret4_left_right__turret4_brake(0.99)
        pierce_turret5_front__turret5_brake(0.99)
        pierce_turret5_back__turret5_brake(0.99)
        pierce_turret5_left_right__turret5_brake(0.99)
        pierce_turret4_front__gun2_brake(0)   pierce_mantlet2__gun2_brake(0)
        pierce_turret4_back__gun2_brake(0)
        pierce_turret4_left_right__gun2_brake(0)
        pierce_turret5_front__gun3_brake(0)   pierce_mantlet3__gun3_brake(0)
        pierce_turret5_back__gun3_brake(0)
        pierce_turret5_left_right__gun3_brake(0)
;///////Engineer_Den - ////////////////

        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(0.95)
        pierce_engine__engine_burn(0.10)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.75)
        pierce_body__kill_gunner(0.75)
        pierce_body__kill_driver(0.75)
        pierce_body__kill_commander(0.75)
        pierce_body__kill_gunner2(0.75)
;///////Engineer_Den+ ////////////////
        pierce_body__kill_radist(0.75)
        pierce_turret__kill_radist(0.75)

        pierce_body__kill_gunner3(0.75)
        pierce_turret2__kill_gunner3(0.75)
        pierce_body__kill_gunner4(0.75)
        pierce_turret3__kill_gunner4(0.75)
        pierce_body__kill_gunner5(0.75)
        pierce_turret4__kill_gunner5(0.75)
        pierce_body__kill_charger5(0.75)
        pierce_turret4__kill_charger5(0.75)
        pierce_body__kill_gunner6(0.75)
        pierce_turret5__kill_gunner6(0.75)
        pierce_body__kill_charger6(0.75)
        pierce_turret5__kill_charger6(0.75)
;///////Engineer_Den - ////////////////			
    ;--------------------------
        pierce_turret__kill_charger(0.75)
        pierce_turret__kill_gunner(0.75)
        pierce_turret__kill_driver(0.75)
        pierce_turret__kill_commander(0.75)
        pierce_turret__kill_gunner2(0.75)
    )	
    ;///////////////////////////////////////////////////////// Gun shells AP 120 - 130
   ("damage_process_pierce"    
        staff(ap_120_130aa)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.95)
;///////Engineer_Den + ////////////////	
        pierce_gun2(0.95)
        pierce_gun3(0.95)
;///////Engineer_Den - ////////////////			
        pierce_front_back_track(0.95)
        pierce_left_right_track(0.95)
        pierce_inventory__explosive(0.95)
    ;--------------------------
        pierce_body__burn(0.5)
        pierce_body__body_brake(0.02)
        pierce_body__body_destroy(0.99)
    ;--------------------------
		  crew_shock_time(29.95)
    ;--------------------------
        pierce_turret__explosive(0.95)
;///////Engineer_Den + ////////////////
         pierce_turret4__explosive(0.95)
         pierce_turret5__explosive(0.95)	
;///////Engineer_Den - ////////////////			

        pierce_turret_front__turret_brake(0.99)
        pierce_turret_back__turret_brake(0.99)
        pierce_turret_left_right__turret_brake(0.99)
		
;///////Engineer_Den + ////////////////
        pierce_turret2_front__turret2_brake(0.99)
        pierce_turret2_back__turret2_brake(0.99)
        pierce_turret2_left_right__turret2_brake(0.99)
        pierce_turret3_front__turret3_brake(0.99)
        pierce_turret3_back__turret3_brake(0.99)
        pierce_turret3_left_right__turret3_brake(0.99)
        pierce_turret4_front__turret4_brake(0.99)
        pierce_turret4_back__turret4_brake(0.99)
        pierce_turret4_left_right__turret4_brake(0.99)
        pierce_turret5_front__turret5_brake(0.99)
        pierce_turret5_back__turret5_brake(0.99)
        pierce_turret5_left_right__turret5_brake(0.99)
        pierce_turret4_front__gun2_brake(0.95)   pierce_mantlet2__gun2_brake(0.95)
        pierce_turret4_back__gun2_brake(0.95)
        pierce_turret4_left_right__gun2_brake(0.95)
        pierce_turret5_front__gun3_brake(0.95)   pierce_mantlet3__gun3_brake(0.95)
        pierce_turret5_back__gun3_brake(0.95)
        pierce_turret5_left_right__gun3_brake(0.95)
;///////Engineer_Den - ////////////////		

        pierce_turret_front__gun_brake(0.95) pierce_mantlet__gun_brake(0.95)
        pierce_turret_back__gun_brake(0.95)
        pierce_turret_left_right__gun_brake(0.95)

    ;---------------------------
        pierce_engine__engine_brake(0.95)
        pierce_engine__engine_burn(0.10)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.95)
        pierce_body__kill_gunner(0.95)
        pierce_body__kill_driver(0.95)
        pierce_body__kill_commander(0.95)
        pierce_body__kill_gunner2(0.95)
;///////Engineer_Den+ ////////////////
        pierce_body__kill_radist(0.95)
        pierce_turret__kill_radist(0.95)

        pierce_body__kill_gunner3(0.95)
        pierce_turret2__kill_gunner3(0.95)
        pierce_body__kill_gunner4(0.95)
        pierce_turret3__kill_gunner4(0.95)
        pierce_body__kill_gunner5(0.95)
        pierce_turret4__kill_gunner5(0.95)
        pierce_body__kill_charger5(0.95)
        pierce_turret4__kill_charger5(0.95)
        pierce_body__kill_gunner6(0.95)
        pierce_turret5__kill_gunner6(0.95)
        pierce_body__kill_charger6(0.95)
        pierce_turret5__kill_charger6(0.95)
;///////Engineer_Den - ////////////////			
    ;--------------------------
        pierce_turret__kill_charger(0.95)
        pierce_turret__kill_gunner(0.95)
        pierce_turret__kill_driver(0.95)
        pierce_turret__kill_commander(0.95)
        pierce_turret__kill_gunner2(0.95)
    )
    ;///////////////////////////////////////////////////////// Gun shells AP 149 - 155
   ("damage_process_pierce"	
        staff(ap_149_155aa)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.95)
;///////Engineer_Den + ////////////////	
        pierce_gun2(0.95)
        pierce_gun3(0.95)
;///////Engineer_Den - ////////////////			
        pierce_front_back_track(0.95)
        pierce_left_right_track(0.95)
        pierce_inventory__explosive(0.95)
    ;--------------------------
        pierce_body__burn(0.5)
        pierce_body__body_brake(0.01)
        pierce_body__body_destroy(0.99)
    ;--------------------------
		  crew_shock_time(29.95)
    ;--------------------------
        pierce_turret__explosive(0.99)
;///////Engineer_Den + ////////////////
         pierce_turret4__explosive(0.99)
         pierce_turret5__explosive(0.99)	
;///////Engineer_Den - ////////////////		

        pierce_turret_front__turret_brake(0.99)
        pierce_turret_back__turret_brake(0.99)
        pierce_turret_left_right__turret_brake(0.99)
		
;///////Engineer_Den + ////////////////
        pierce_turret2_front__turret2_brake(0.99)
        pierce_turret2_back__turret2_brake(0.99)
        pierce_turret2_left_right__turret2_brake(0.99)
        pierce_turret3_front__turret3_brake(0.99)
        pierce_turret3_back__turret3_brake(0.99)
        pierce_turret3_left_right__turret3_brake(0.99)
        pierce_turret4_front__turret4_brake(0.99)
        pierce_turret4_back__turret4_brake(0.99)
        pierce_turret4_left_right__turret4_brake(0.99)
        pierce_turret5_front__turret5_brake(0.99)
        pierce_turret5_back__turret5_brake(0.99)
        pierce_turret5_left_right__turret5_brake(0.99)
        pierce_turret4_front__gun2_brake(0.95)   pierce_mantlet2__gun2_brake(0.95)
        pierce_turret4_back__gun2_brake(0.95)
        pierce_turret4_left_right__gun2_brake(0.95)
        pierce_turret5_front__gun3_brake(0.95)   pierce_mantlet3__gun3_brake(0.95)
        pierce_turret5_back__gun3_brake(0.95)
        pierce_turret5_left_right__gun3_brake(0.95)
;///////Engineer_Den - ////////////////		

        pierce_turret_front__gun_brake(0.95) pierce_mantlet__gun_brake(0.95)
        pierce_turret_back__gun_brake(0.95)
        pierce_turret_left_right__gun_brake(0.95)

    ;---------------------------
        pierce_engine__engine_brake(0.95)
        pierce_engine__engine_burn(0.10)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.95)
        pierce_body__kill_gunner(0.95)
        pierce_body__kill_driver(0.95)
        pierce_body__kill_commander(0.95)
        pierce_body__kill_gunner2(0.95)
;///////Engineer_Den+ ////////////////
        pierce_body__kill_radist(0.95)
        pierce_turret__kill_radist(0.95)

        pierce_body__kill_gunner3(0.95)
        pierce_turret2__kill_gunner3(0.95)
        pierce_body__kill_gunner4(0.95)
        pierce_turret3__kill_gunner4(0.95)
        pierce_body__kill_gunner5(0.95)
        pierce_turret4__kill_gunner5(0.95)
        pierce_body__kill_charger5(0.95)
        pierce_turret4__kill_charger5(0.95)
        pierce_body__kill_gunner6(0.95)
        pierce_turret5__kill_gunner6(0.95)
        pierce_body__kill_charger6(0.95)
        pierce_turret5__kill_charger6(0.95)
;///////Engineer_Den - ////////////////		
    ;--------------------------
        pierce_turret__kill_charger(0.95)
        pierce_turret__kill_gunner(0.95)
        pierce_turret__kill_driver(0.95)
        pierce_turret__kill_commander(0.95)
        pierce_turret__kill_gunner2(0.95)
    )
    ;///////////////////////////////////////////////////////// Gun shells AP 170 - 240
   ("damage_process_pierce"	
        staff(ap_170_240aa)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.95)
;///////Engineer_Den + ////////////////	
        pierce_gun2(0.95)
        pierce_gun3(0.95)
;///////Engineer_Den - ////////////////			
        pierce_front_back_track(0.95)
        pierce_left_right_track(0.95)
        pierce_inventory__explosive(0.95)
    ;--------------------------
        pierce_body__burn(0.5)
        pierce_body__body_brake(0.01)
        pierce_body__body_destroy(0.99)
    ;--------------------------
		  crew_shock_time(29.95)
    ;--------------------------
        pierce_turret__explosive(0.99)
;///////Engineer_Den + ////////////////
         pierce_turret4__explosive(0.99)
         pierce_turret5__explosive(0.99)	
;///////Engineer_Den - ////////////////			

        pierce_turret_front__turret_brake(0.99)
        pierce_turret_back__turret_brake(0.99)
        pierce_turret_left_right__turret_brake(0.99)
		
;///////Engineer_Den + ////////////////
        pierce_turret2_front__turret2_brake(0.99)
        pierce_turret2_back__turret2_brake(0.99)
        pierce_turret2_left_right__turret2_brake(0.99)
        pierce_turret3_front__turret3_brake(0.99)
        pierce_turret3_back__turret3_brake(0.99)
        pierce_turret3_left_right__turret3_brake(0.99)
        pierce_turret4_front__turret4_brake(0.99)
        pierce_turret4_back__turret4_brake(0.99)
        pierce_turret4_left_right__turret4_brake(0.99)
        pierce_turret5_front__turret5_brake(0.99)
        pierce_turret5_back__turret5_brake(0.99)
        pierce_turret5_left_right__turret5_brake(0.99)
        pierce_turret4_front__gun2_brake(0.95)   pierce_mantlet2__gun2_brake(0.95)
        pierce_turret4_back__gun2_brake(0.95)
        pierce_turret4_left_right__gun2_brake(0.95)
        pierce_turret5_front__gun3_brake(0.95)   pierce_mantlet3__gun3_brake(0.95)
        pierce_turret5_back__gun3_brake(0.95)
        pierce_turret5_left_right__gun3_brake(0.95)
;///////Engineer_Den - ////////////////		

        pierce_turret_front__gun_brake(0.95) pierce_mantlet__gun_brake(0.95)
        pierce_turret_back__gun_brake(0.95)
        pierce_turret_left_right__gun_brake(0.95)

    ;---------------------------
        pierce_engine__engine_brake(0.95)
        pierce_engine__engine_burn(0.10)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.95)
        pierce_body__kill_gunner(0.95)
        pierce_body__kill_driver(0.95)
        pierce_body__kill_commander(0.95)
        pierce_body__kill_gunner2(0.95)
;///////Engineer_Den+ ////////////////
        pierce_body__kill_radist(0.95)
        pierce_turret__kill_radist(0.95)

        pierce_body__kill_gunner3(0.95)
        pierce_turret2__kill_gunner3(0.95)
        pierce_body__kill_gunner4(0.95)
        pierce_turret3__kill_gunner4(0.95)
        pierce_body__kill_gunner5(0.95)
        pierce_turret4__kill_gunner5(0.95)
        pierce_body__kill_charger5(0.95)
        pierce_turret4__kill_charger5(0.95)
        pierce_body__kill_gunner6(0.95)
        pierce_turret5__kill_gunner6(0.95)
        pierce_body__kill_charger6(0.95)
        pierce_turret5__kill_charger6(0.95)
;///////Engineer_Den - ////////////////		
    ;--------------------------
        pierce_turret__kill_charger(0.95)
        pierce_turret__kill_gunner(0.95)
        pierce_turret__kill_driver(0.95)
        pierce_turret__kill_commander(0.95)
        pierce_turret__kill_gunner2(0.95)
    )
    ;///////////////////////////////////////////////////////// Gun shells AP 290 - 380
   ("damage_process_pierce"	
        staff(ap_290_380aa)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.95)
;///////Engineer_Den + ////////////////	
        pierce_gun2(0.95)
        pierce_gun3(0.95)
;///////Engineer_Den - ////////////////			
        pierce_front_back_track(0.95)
        pierce_left_right_track(0.95)
        pierce_inventory__explosive(0.95)
    ;--------------------------
        pierce_body__burn(0.5)
        pierce_body__body_brake(0.01)
        pierce_body__body_destroy(0.99)
    ;--------------------------
		  crew_shock_time(29.95)
    ;--------------------------
        pierce_turret__explosive(0.99)
;///////Engineer_Den + ////////////////
         pierce_turret4__explosive(0.99)
         pierce_turret5__explosive(0.99)	
;///////Engineer_Den - ////////////////			

        pierce_turret_front__turret_brake(0.99)
        pierce_turret_back__turret_brake(0.99)
        pierce_turret_left_right__turret_brake(0.99)
		
;///////Engineer_Den + ////////////////
        pierce_turret2_front__turret2_brake(0.99)
        pierce_turret2_back__turret2_brake(0.99)
        pierce_turret2_left_right__turret2_brake(0.99)
        pierce_turret3_front__turret3_brake(0.99)
        pierce_turret3_back__turret3_brake(0.99)
        pierce_turret3_left_right__turret3_brake(0.99)
        pierce_turret4_front__turret4_brake(0.99)
        pierce_turret4_back__turret4_brake(0.99)
        pierce_turret4_left_right__turret4_brake(0.99)
        pierce_turret5_front__turret5_brake(0.99)
        pierce_turret5_back__turret5_brake(0.99)
        pierce_turret5_left_right__turret5_brake(0.99)
        pierce_turret4_front__gun2_brake(0.95)   pierce_mantlet2__gun2_brake(0.95)
        pierce_turret4_back__gun2_brake(0.95)
        pierce_turret4_left_right__gun2_brake(0.95)
        pierce_turret5_front__gun3_brake(0.95)   pierce_mantlet3__gun3_brake(0.95)
        pierce_turret5_back__gun3_brake(0.95)
        pierce_turret5_left_right__gun3_brake(0.95)
;///////Engineer_Den - ////////////////		

        pierce_turret_front__gun_brake(0.95) pierce_mantlet__gun_brake(0.95)
        pierce_turret_back__gun_brake(0.95)
        pierce_turret_left_right__gun_brake(0.95)

    ;---------------------------
        pierce_engine__engine_brake(0.95)
        pierce_engine__engine_burn(0.10)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.95)
        pierce_body__kill_gunner(0.95)
        pierce_body__kill_driver(0.95)
        pierce_body__kill_commander(0.95)
        pierce_body__kill_gunner2(0.95)
;///////Engineer_Den+ ////////////////
        pierce_body__kill_radist(0.95)
        pierce_turret__kill_radist(0.95)

        pierce_body__kill_gunner3(0.95)
        pierce_turret2__kill_gunner3(0.95)
        pierce_body__kill_gunner4(0.95)
        pierce_turret3__kill_gunner4(0.95)
        pierce_body__kill_gunner5(0.95)
        pierce_turret4__kill_gunner5(0.95)
        pierce_body__kill_charger5(0.95)
        pierce_turret4__kill_charger5(0.95)
        pierce_body__kill_gunner6(0.95)
        pierce_turret5__kill_gunner6(0.95)
        pierce_body__kill_charger6(0.95)
        pierce_turret5__kill_charger6(0.95)
;///////Engineer_Den - ////////////////		
    ;--------------------------
        pierce_turret__kill_charger(0.95)
        pierce_turret__kill_gunner(0.95)
        pierce_turret__kill_driver(0.95)
        pierce_turret__kill_commander(0.95)
        pierce_turret__kill_gunner2(0.95)
    )
    ;///////////////////////////////////////////////////////// Gun shells AP 600
   ("damage_process_pierce"	
        staff(ap_600aa)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.95)
;///////Engineer_Den + ////////////////	
        pierce_gun2(0.95)
        pierce_gun3(0.95)
;///////Engineer_Den - ////////////////			
        pierce_front_back_track(0.95)
        pierce_left_right_track(0.95)
        pierce_inventory__explosive(0.95)
    ;--------------------------
        pierce_body__burn(0.5)
        pierce_body__body_brake(0.01)
        pierce_body__body_destroy(0.99)
    ;--------------------------
		  crew_shock_time(29.95)
    ;--------------------------
        pierce_turret__explosive(0.99)
;///////Engineer_Den + ////////////////
         pierce_turret4__explosive(0.99)
         pierce_turret5__explosive(0.99)	
;///////Engineer_Den - ////////////////			

        pierce_turret_front__turret_brake(0.99)
        pierce_turret_back__turret_brake(0.99)
        pierce_turret_left_right__turret_brake(0.99)
		
;///////Engineer_Den + ////////////////
        pierce_turret2_front__turret2_brake(0.99)
        pierce_turret2_back__turret2_brake(0.99)
        pierce_turret2_left_right__turret2_brake(0.99)
        pierce_turret3_front__turret3_brake(0.99)
        pierce_turret3_back__turret3_brake(0.99)
        pierce_turret3_left_right__turret3_brake(0.99)
        pierce_turret4_front__turret4_brake(0.99)
        pierce_turret4_back__turret4_brake(0.99)
        pierce_turret4_left_right__turret4_brake(0.99)
        pierce_turret5_front__turret5_brake(0.99)
        pierce_turret5_back__turret5_brake(0.99)
        pierce_turret5_left_right__turret5_brake(0.99)
        pierce_turret4_front__gun2_brake(0.95)   pierce_mantlet2__gun2_brake(0.95)
        pierce_turret4_back__gun2_brake(0.95)
        pierce_turret4_left_right__gun2_brake(0.95)
        pierce_turret5_front__gun3_brake(0.95)   pierce_mantlet3__gun3_brake(0.95)
        pierce_turret5_back__gun3_brake(0.95)
        pierce_turret5_left_right__gun3_brake(0.95)
;///////Engineer_Den - ////////////////		

        pierce_turret_front__gun_brake(0.95) pierce_mantlet__gun_brake(0.95)
        pierce_turret_back__gun_brake(0.95)
        pierce_turret_left_right__gun_brake(0.95)

    ;---------------------------
        pierce_engine__engine_brake(0.95)
        pierce_engine__engine_burn(0.10)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.95)
        pierce_body__kill_gunner(0.95)
        pierce_body__kill_driver(0.95)
        pierce_body__kill_commander(0.95)
        pierce_body__kill_gunner2(0.95)
;///////Engineer_Den+ ////////////////
        pierce_body__kill_radist(0.95)
        pierce_turret__kill_radist(0.95)

        pierce_body__kill_gunner3(0.95)
        pierce_turret2__kill_gunner3(0.95)
        pierce_body__kill_gunner4(0.95)
        pierce_turret3__kill_gunner4(0.95)
        pierce_body__kill_gunner5(0.95)
        pierce_turret4__kill_gunner5(0.95)
        pierce_body__kill_charger5(0.95)
        pierce_turret4__kill_charger5(0.95)
        pierce_body__kill_gunner6(0.95)
        pierce_turret5__kill_gunner6(0.95)
        pierce_body__kill_charger6(0.95)
        pierce_turret5__kill_charger6(0.95)
;///////Engineer_Den - ////////////////		
    ;--------------------------
        pierce_turret__kill_charger(0.95)
        pierce_turret__kill_gunner(0.95)
        pierce_turret__kill_driver(0.95)
        pierce_turret__kill_commander(0.95)
        pierce_turret__kill_gunner2(0.95)
    )		
	
	
    ;///////////////////////////////////////////////////////// Cumulative charge
   ("damage_process_pierce"
        staff(cumulative_charge)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0)
;///////Engineer_Den + ////////////////	
        pierce_gun2(0)
        pierce_gun3(0)
;///////Engineer_Den - ////////////////			
        pierce_front_back_track(0.90)
        pierce_left_right_track(0.40)
        pierce_inventory__explosive(0)
    ;--------------------------
        pierce_body__burn(0.70)
        pierce_body__body_brake(0.70)
        pierce_body__body_destroy(0.1)
    ;--------------------------
		crew_shock_time(6.00)
    ;--------------------------
        pierce_turret__explosive(0)
;///////Engineer_Den + ////////////////
         pierce_turret4__explosive(0)
         pierce_turret5__explosive(0)	
;///////Engineer_Den - ////////////////			

        pierce_turret_front__turret_brake(0.40)
        pierce_turret_back__turret_brake(0.40)
        pierce_turret_left_right__turret_brake(0.40)
		
;///////Engineer_Den + ////////////////
        pierce_turret2_front__turret2_brake(0.40)
        pierce_turret2_back__turret2_brake(0.40)
        pierce_turret2_left_right__turret2_brake(0.40)
        pierce_turret3_front__turret3_brake(0.40)
        pierce_turret3_back__turret3_brake(0.40)
        pierce_turret3_left_right__turret3_brake(0.40)
        pierce_turret4_front__turret4_brake(0.40)
        pierce_turret4_back__turret4_brake(0.40)
        pierce_turret4_left_right__turret4_brake(0.40)
        pierce_turret5_front__turret5_brake(0.40)
        pierce_turret5_back__turret5_brake(0.40)
        pierce_turret5_left_right__turret5_brake(0.40)
        pierce_turret4_front__gun2_brake(0.80)   pierce_mantlet2__gun2_brake(0.80)
        pierce_turret4_back__gun2_brake(0.40)
        pierce_turret4_left_right__gun2_brake(0.40)
        pierce_turret5_front__gun3_brake(0.80)   pierce_mantlet3__gun3_brake(0.80)
        pierce_turret5_back__gun3_brake(0.40)
        pierce_turret5_left_right__gun3_brake(0.40)
;///////Engineer_Den - ////////////////		

        pierce_turret_front__gun_brake(0.80) pierce_mantlet__gun_brake(0.80)
        pierce_turret_back__gun_brake(0.40)
        pierce_turret_left_right__gun_brake(0.40)

    ;---------------------------
        pierce_engine__engine_brake(1.00)
        pierce_engine__engine_burn(0.80)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.95)
        pierce_body__kill_gunner(0.95)
        pierce_body__kill_driver(0.95)
        pierce_body__kill_commander(0.95)
        pierce_body__kill_gunner2(0.95)
;///////Engineer_Den+ ////////////////
        pierce_body__kill_radist(0.95)
        pierce_turret__kill_radist(0.95)

        pierce_body__kill_gunner3(0.95)
        pierce_turret2__kill_gunner3(0.95)
        pierce_body__kill_gunner4(0.95)
        pierce_turret3__kill_gunner4(0.95)
        pierce_body__kill_gunner5(0.95)
        pierce_turret4__kill_gunner5(0.95)
        pierce_body__kill_charger5(0.95)
        pierce_turret4__kill_charger5(0.95)
        pierce_body__kill_gunner6(0.95)
        pierce_turret5__kill_gunner6(0.95)
        pierce_body__kill_charger6(0.95)
        pierce_turret5__kill_charger6(0.95)
;///////Engineer_Den - ////////////////		
    ;--------------------------
        pierce_turret__kill_charger(0.95)
        pierce_turret__kill_gunner(0.95)
        pierce_turret__kill_driver(0.95)
        pierce_turret__kill_commander(0.95)
        pierce_turret__kill_gunner2(0.95)
    )
    ;///////////////////////////////////////////////////////// Cumulative
   ("damage_process_pierce"
        staff(cumulative)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.50)
;///////Engineer_Den + ////////////////	
        pierce_gun2(0.50)
        pierce_gun3(0.50)
;///////Engineer_Den - ////////////////			
        pierce_front_back_track(0.20)
        pierce_left_right_track(0.10)
        pierce_inventory__explosive(0)
    ;--------------------------
        pierce_body__burn(0.2)
        pierce_body__body_brake(0.5)
        pierce_body__body_destroy(0.1)
    ;--------------------------
		crew_shock_time(35.00)
    ;--------------------------
        pierce_turret__explosive(0)
;///////Engineer_Den + ////////////////
         pierce_turret4__explosive(0)
         pierce_turret5__explosive(0)	
;///////Engineer_Den - ////////////////		

        pierce_turret_front__turret_brake(0.40)
        pierce_turret_back__turret_brake(0.40)
        pierce_turret_left_right__turret_brake(0.40)
		
;///////Engineer_Den + ////////////////
        pierce_turret2_front__turret2_brake(0.40)
        pierce_turret2_back__turret2_brake(0.40)
        pierce_turret2_left_right__turret2_brake(0.40)
        pierce_turret3_front__turret3_brake(0.40)
        pierce_turret3_back__turret3_brake(0.40)
        pierce_turret3_left_right__turret3_brake(0.40)
        pierce_turret4_front__turret4_brake(0.40)
        pierce_turret4_back__turret4_brake(0.40)
        pierce_turret4_left_right__turret4_brake(0.40)
        pierce_turret5_front__turret5_brake(0.40)
        pierce_turret5_back__turret5_brake(0.40)
        pierce_turret5_left_right__turret5_brake(0.40)
        pierce_turret4_front__gun2_brake(0)   pierce_mantlet2__gun2_brake(0)
        pierce_turret4_back__gun2_brake(0)
        pierce_turret4_left_right__gun2_brake(0)
        pierce_turret5_front__gun3_brake(0)   pierce_mantlet3__gun3_brake(0)
        pierce_turret5_back__gun3_brake(0)
        pierce_turret5_left_right__gun3_brake(0)
;///////Engineer_Den - ////////////////		

        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(1.00)
        pierce_engine__engine_burn(0.95)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.40)
        pierce_body__kill_gunner(0.40)
        pierce_body__kill_driver(0.40)
        pierce_body__kill_commander(0.40)
        pierce_body__kill_gunner2(0.40)
;///////Engineer_Den+ ////////////////
        pierce_body__kill_radist(0.40)
        pierce_turret__kill_radist(0.40)

        pierce_body__kill_gunner3(0.40)
        pierce_turret2__kill_gunner3(0.40)
        pierce_body__kill_gunner4(0.40)
        pierce_turret3__kill_gunner4(0.40)
        pierce_body__kill_gunner5(0.40)
        pierce_turret4__kill_gunner5(0.40)
        pierce_body__kill_charger5(0.40)
        pierce_turret4__kill_charger5(0.40)
        pierce_body__kill_gunner6(0.40)
        pierce_turret5__kill_gunner6(0.40)
        pierce_body__kill_charger6(0.40)
        pierce_turret5__kill_charger6(0.40)
;///////Engineer_Den - ////////////////		
    ;--------------------------
        pierce_turret__kill_charger(0.40)
        pierce_turret__kill_gunner(0.40)
        pierce_turret__kill_driver(0.40)
        pierce_turret__kill_commander(0.40)
        pierce_turret__kill_gunner2(0.40)
    )
    ;///////////////////////////////////////////////////////// Cumulative heavy 89mm+
   ("damage_process_pierce"
        staff(hcumulative)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.95)
;///////Engineer_Den + ////////////////	
        pierce_gun2(0.95)
        pierce_gun3(0.95)
;///////Engineer_Den - ////////////////			
        pierce_front_back_track(0.20)
        pierce_left_right_track(0.4)
        pierce_inventory__explosive(0)
    ;--------------------------
        pierce_body__burn(0.10)
        pierce_body__body_brake(0.30)
        pierce_body__body_destroy(0.1)
    ;--------------------------
		crew_shock_time(30.00)
    ;--------------------------
        pierce_turret__explosive(0)
;///////Engineer_Den + ////////////////
         pierce_turret4__explosive(0)
         pierce_turret5__explosive(0)	
;///////Engineer_Den - ////////////////		

        pierce_turret_front__turret_brake(0.30)
        pierce_turret_back__turret_brake(0.30)
        pierce_turret_left_right__turret_brake(0.30)
		
;///////Engineer_Den + ////////////////
        pierce_turret2_front__turret2_brake(0.30)
        pierce_turret2_back__turret2_brake(0.30)
        pierce_turret2_left_right__turret2_brake(0.30)
        pierce_turret3_front__turret3_brake(0.30)
        pierce_turret3_back__turret3_brake(0.30)
        pierce_turret3_left_right__turret3_brake(0.30)
        pierce_turret4_front__turret4_brake(0.30)
        pierce_turret4_back__turret4_brake(0.30)
        pierce_turret4_left_right__turret4_brake(0.30)
        pierce_turret5_front__turret5_brake(0.30)
        pierce_turret5_back__turret5_brake(0.30)
        pierce_turret5_left_right__turret5_brake(0.30)
        pierce_turret4_front__gun2_brake(0)   pierce_mantlet2__gun2_brake(0)
        pierce_turret4_back__gun2_brake(0)
        pierce_turret4_left_right__gun2_brake(0.2)
        pierce_turret5_front__gun3_brake(0)   pierce_mantlet3__gun3_brake(0)
        pierce_turret5_back__gun3_brake(0)
        pierce_turret5_left_right__gun3_brake(0)
;///////Engineer_Den - ////////////////		

        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(1.00)
        pierce_engine__engine_burn(0.80)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.99)
        pierce_body__kill_gunner(0.99)
        pierce_body__kill_driver(0.99)
        pierce_body__kill_commander(0.99)
        pierce_body__kill_gunner2(0.99)
;///////Engineer_Den+ ////////////////
        pierce_body__kill_radist(0.99)
        pierce_turret__kill_radist(0.99)

        pierce_body__kill_gunner3(0.99)
        pierce_turret2__kill_gunner3(0.99)
        pierce_body__kill_gunner4(0.99)
        pierce_turret3__kill_gunner4(0.99)
        pierce_body__kill_gunner5(0.99)
        pierce_turret4__kill_gunner5(0.99)
        pierce_body__kill_charger5(0.99)
        pierce_turret4__kill_charger5(0.99)
        pierce_body__kill_gunner6(0.99)
        pierce_turret5__kill_gunner6(0.99)
        pierce_body__kill_charger6(0.99)
        pierce_turret5__kill_charger6(0.99)
;///////Engineer_Den - ////////////////		
    ;--------------------------
        pierce_turret__kill_charger(0.99)
        pierce_turret__kill_gunner(0.99)
        pierce_turret__kill_driver(0.99)
        pierce_turret__kill_commander(0.99)
        pierce_turret__kill_gunner2(0.99)
    )	
    ;///////////////////////////////////////////////////////// Cumulative rifle granade
   ("damage_process_pierce"
        staff(grb_grenade)

    ;Probability component brake\destroy (Name_of_Event__Consequences) for this stuff=========
        pierce_gun(0.50)
;///////Engineer_Den + ////////////////	
        pierce_gun2(0.50)
        pierce_gun3(0.50)
;///////Engineer_Den - ////////////////		
        pierce_front_back_track(0.20)
        pierce_left_right_track(0.10)
        pierce_inventory__explosive(0)
    ;--------------------------
        pierce_body__burn(0.2)
        pierce_body__body_brake(0.5)
        pierce_body__body_destroy(0.1)
    ;--------------------------
		crew_shock_time(35.00)
    ;--------------------------
        pierce_turret__explosive(0)
;///////Engineer_Den + ////////////////
         pierce_turret4__explosive(0)
         pierce_turret5__explosive(0)	
;///////Engineer_Den - ////////////////		

        pierce_turret_front__turret_brake(0.40)
        pierce_turret_back__turret_brake(0.40)
        pierce_turret_left_right__turret_brake(0.40)
		
;///////Engineer_Den + ////////////////
        pierce_turret2_front__turret2_brake(0.40)
        pierce_turret2_back__turret2_brake(0.40)
        pierce_turret2_left_right__turret2_brake(0.40)
        pierce_turret3_front__turret3_brake(0.40)
        pierce_turret3_back__turret3_brake(0.40)
        pierce_turret3_left_right__turret3_brake(0.40)
        pierce_turret4_front__turret4_brake(0.40)
        pierce_turret4_back__turret4_brake(0.40)
        pierce_turret4_left_right__turret4_brake(0.40)
        pierce_turret5_front__turret5_brake(0.40)
        pierce_turret5_back__turret5_brake(0.40)
        pierce_turret5_left_right__turret5_brake(0.40)
        pierce_turret4_front__gun2_brake(0)   pierce_mantlet2__gun2_brake(0)
        pierce_turret4_back__gun2_brake(0)
        pierce_turret4_left_right__gun2_brake(0)
        pierce_turret5_front__gun3_brake(0)   pierce_mantlet3__gun3_brake(0)
        pierce_turret5_back__gun3_brake(0)
        pierce_turret5_left_right__gun3_brake(0)
;///////Engineer_Den - ////////////////			

        pierce_turret_front__gun_brake(0) pierce_mantlet__gun_brake(0)
        pierce_turret_back__gun_brake(0)
        pierce_turret_left_right__gun_brake(0)

    ;---------------------------
        pierce_engine__engine_brake(1.00)
        pierce_engine__engine_burn(0.95)

    ;Probability crew die
    ;--------------------------
        pierce_body__kill_charger(0.35)
        pierce_body__kill_gunner(0.35)
        pierce_body__kill_driver(0.35)
        pierce_body__kill_commander(0.35)
        pierce_body__kill_gunner2(0.35)
;///////Engineer_Den+ ////////////////
        pierce_body__kill_radist(0.35)
        pierce_turret__kill_radist(0.35)

        pierce_body__kill_gunner3(0.35)
        pierce_turret2__kill_gunner3(0.35)
        pierce_body__kill_gunner4(0.35)
        pierce_turret3__kill_gunner4(0.35)
        pierce_body__kill_gunner5(0.35)
        pierce_turret4__kill_gunner5(0.35)
        pierce_body__kill_charger5(0.35)
        pierce_turret4__kill_charger5(0.35)
        pierce_body__kill_gunner6(0.35)
        pierce_turret5__kill_gunner6(0.35)
        pierce_body__kill_charger6(0.35)
        pierce_turret5__kill_charger6(0.35)
;///////Engineer_Den - ////////////////		
    ;--------------------------
        pierce_turret__kill_charger(0.35)
        pierce_turret__kill_gunner(0.35)
        pierce_turret__kill_driver(0.35)
        pierce_turret__kill_commander(0.35)
        pierce_turret__kill_gunner2(0.35)
    )	

}; end of pierce
;=================================================================================================================================================
{on bullet_hit
    ;{if stuff "size_minimum"
    ;    ("blind" args 1)
    ;else stuff "size_small"
    ;    ("blind" args 2)
    ;else stuff "size_big"
    ;    ("blind" args 3)
    ;}

                    ;{if stuff "big shell extra"
                    ;    ;{ani_play "hit"}
                    ;else stuff "big shell"
                    ;    ;{ani_play "hit"}
                    ;}
    ;///////////////////////////////////////////////////////// Gun shells AP hit 14 - 19
;    ("damage_process_bullet_hit"
;       staff(ap_14_19a)
;
;        hit_body__explosive(0)
;        hit_body__engine_burn(0)
;        hit_body__body_destroy(0)
;        hit_body__body_brake(0)
;        ;--------------------------
;        hit_body__engine_brake(0)
;        ;--------------------------
;        hit_turret__explosive(0)
;        hit_turret_front__gun_brake(0)
;        hit_turret__turret_destroy(0)
;        hit_turret__turret_brake(0)
;        imp(0)
;        hit_tank__tank_destroy(0)
;        hit_engine__engine_brake(0)
;    )
    ;///////////////////////////////////////////////////////// Gun shells AP hit 20 - 28	
;    ("damage_process_bullet_hit"
;       staff(ap_20_28a)
;
;        hit_body__explosive(0)
;        hit_body__engine_burn(0)
;        hit_body__body_destroy(0)
;        hit_body__body_brake(0)
;        ;--------------------------
;        hit_body__engine_brake(0)
;        ;--------------------------
;        hit_turret__explosive(0)
;        hit_turret_front__gun_brake(0)
;        hit_turret__turret_destroy(0)
;        hit_turret__turret_brake(0)
;        imp(0)
;        hit_tank__tank_destroy(0)
;        hit_engine__engine_brake(0)
;    )
    ;///////////////////////////////////////////////////////// Gun shells AP hit 30 - 37	
;    ("damage_process_bullet_hit"
;       staff(ap_30_37a)
;
;        hit_body__explosive(0)
;        hit_body__engine_burn(0)
;        hit_body__body_destroy(0)
;        hit_body__body_brake(0)
;        ;--------------------------
;        hit_body__engine_brake(0)
;        ;--------------------------
;        hit_turret__explosive(0)
;        hit_turret_front__gun_brake(0)
;        hit_turret__turret_destroy(0)
;        hit_turret__turret_brake(0)
;        imp(0)
;        hit_tank__tank_destroy(0)
;        hit_engine__engine_brake(0)
;    )
    ;///////////////////////////////////////////////////////// Gun shells AP hit 40 - 57	
;    ("damage_process_bullet_hit"
;       staff(ap_40_57a)
;
;        hit_body__explosive(0)
;        hit_body__engine_burn(0)
;        hit_body__body_destroy(0)
;        hit_body__body_brake(0)
;        ;--------------------------
;        hit_body__engine_brake(0)
;        ;--------------------------
;        hit_turret__explosive(0)
;        hit_turret_front__gun_brake(0)
;        hit_turret__turret_destroy(0)
;        hit_turret__turret_brake(0)
;        imp(0)
;        hit_tank__tank_destroy(0)
;        hit_engine__engine_brake(0)
;    )
    ;///////////////////////////////////////////////////////// Gun shells APZ hit 20 - 28 Z	
;    ("damage_process_bullet_hit"
;       staff(fg_20_28az)
;
;        hit_body__explosive(0)
;        hit_body__engine_burn(0)
;        hit_body__body_destroy(0)
;        hit_body__body_brake(0)
;        ;--------------------------
;        hit_body__engine_brake(0)
;        ;--------------------------
;        hit_turret__explosive(0)
;        hit_turret_front__gun_brake(0)
;        hit_turret__turret_destroy(0)
;        hit_turret__turret_brake(0)
;        imp(0)
;        hit_tank__tank_destroy(0)
;        hit_engine__engine_brake(0)
;    )
    ;///////////////////////////////////////////////////////// Gun shells APZ hit 30 - 37 Z	
;    ("damage_process_bullet_hit"
;       staff(fg_30_37az)
;
;        hit_body__explosive(0)
;        hit_body__engine_burn(0)
;        hit_body__body_destroy(0)
;        hit_body__body_brake(0)
;        ;--------------------------
;        hit_body__engine_brake(0)
;        ;--------------------------
;        hit_turret__explosive(0)
;        hit_turret_front__gun_brake(0)
;        hit_turret__turret_destroy(0)
;        hit_turret__turret_brake(0)
;        imp(0)
;        hit_tank__tank_destroy(0)
;        hit_engine__engine_brake(0)
;    )
    ;///////////////////////////////////////////////////////// Gun shells APZ hit 40 - 57 Z	
;    ("damage_process_bullet_hit"
;       staff(fg_40_57az)
;
;        hit_body__explosive(0)
;        hit_body__engine_burn(0)
;        hit_body__body_destroy(0)
;        hit_body__body_brake(0)
;        ;--------------------------
;        hit_body__engine_brake(0)
;        ;--------------------------
;        hit_turret__explosive(0)
;        hit_turret_front__gun_brake(0)
;        hit_turret__turret_destroy(0)
;        hit_turret__turret_brake(0)
;        imp(0)
;        hit_tank__tank_destroy(0)
;        hit_engine__engine_brake(0)
;    )
    ;///////////////////////////////////////////////////////// Gun shells AP hit 70 - 77	
;    ("damage_process_bullet_hit"
;       staff(ap_70_77a)
;
;        hit_body__explosive(0)
;        hit_body__engine_burn(0)
;        hit_body__body_destroy(0)
;        hit_body__body_brake(0)
;        ;--------------------------
;        hit_body__engine_brake(0)
;        ;--------------------------
;        hit_turret__explosive(0)
;        hit_turret_front__gun_brake(0)
;        hit_turret__turret_destroy(0)
;        hit_turret__turret_brake(0)
;        imp(0)
;        hit_tank__tank_destroy(0)
;        hit_engine__engine_brake(0)
;    )
    ;///////////////////////////////////////////////////////// Gun shells AP hit 80 - 95	
;    ("damage_process_bullet_hit"
;       staff(ap_80_95a)
;
;        hit_body__explosive(0)
;        hit_body__engine_burn(0)
;        hit_body__body_destroy(0)
;        hit_body__body_brake(0)
;        ;--------------------------
;        hit_body__engine_brake(0)
;        ;--------------------------
;        hit_turret__explosive(0)
;        hit_turret_front__gun_brake(0)
;        hit_turret__turret_destroy(0)
;        hit_turret__turret_brake(0)
;        imp(0)
;        hit_tank__tank_destroy(0)
;        hit_engine__engine_brake(0)
;    )
    ;///////////////////////////////////////////////////////// Gun shells AP hit 100 - 107	
    ("damage_process_bullet_hit"
       staff(ap_100_107a)

        hit_body__explosive(0)
        hit_body__engine_burn(0)
        hit_body__body_destroy(0)
        hit_body__body_brake(0)
        ;--------------------------
        hit_body__engine_brake(0)
        ;--------------------------
        hit_turret__explosive(0)
        hit_turret_front__gun_brake(0.95)
        hit_turret__turret_destroy(0)
        hit_turret__turret_brake(0)
;///////Engineer_Den+ ////////////////
       hit_turret4__explosive(0)
       hit_turret5__explosive(0)
        hit_turret4_front__gun2_brake(0)
        hit_turret5_front__gun3_brake(0)
        hit_turret2__turret2_destroy(0)
        hit_turret2__turret2_brake(0)
        hit_turret3__turret3_destroy(0)
        hit_turret3__turret3_brake(0)
        hit_turret4__turret4_destroy(0)
        hit_turret4__turret4_brake(0)
        hit_turret5__turret5_destroy(0)
        hit_turret5__turret5_brake(0)       
;///////Engineer_Den- ////////////////		
        imp(0)
        hit_tank__tank_destroy(0)
        hit_engine__engine_brake(0)
    )	
    ;///////////////////////////////////////////////////////// Gun shells AP hit 120 - 130	
    ("damage_process_bullet_hit"
       staff(ap_120_130a)

        hit_body__explosive(0)
        hit_body__engine_burn(0)
        hit_body__body_destroy(0)
        hit_body__body_brake(0)
        ;--------------------------
        hit_body__engine_brake(0.20)
        ;--------------------------
        hit_turret__explosive(0)
        hit_turret_front__gun_brake(0.95)
        hit_turret__turret_destroy(0.95)
        hit_turret__turret_brake(0.95)
;///////Engineer_Den+ ////////////////
       hit_turret4__explosive(0.95)
       hit_turret5__explosive(0.95)
        hit_turret4_front__gun2_brake(0.95)
        hit_turret5_front__gun3_brake(0.95)
        hit_turret2__turret2_destroy(0.95)
        hit_turret2__turret2_brake(0.95)
        hit_turret3__turret3_destroy(0.95)
        hit_turret3__turret3_brake(0.95)
        hit_turret4__turret4_destroy(0.95)
        hit_turret4__turret4_brake(0.95)
        hit_turret5__turret5_destroy(0.95)
        hit_turret5__turret5_brake(0.95)       
;///////Engineer_Den- ////////////////		
        imp(0)
        hit_tank__tank_destroy(0)
        hit_engine__engine_brake(0.95)
    )
    ;///////////////////////////////////////////////////////// Gun shells AP hit 149 - 155	
    ("damage_process_bullet_hit"
       staff(ap_149_155a)

        hit_body__explosive(0)
        hit_body__engine_burn(0)
        hit_body__body_destroy(0)
        hit_body__body_brake(0.80)
        ;--------------------------
        hit_body__engine_brake(0.60)
        ;--------------------------
        hit_turret__explosive(0)
        hit_turret_front__gun_brake(0.95)
        hit_turret__turret_destroy(0.95)
        hit_turret__turret_brake(0.95)
;///////Engineer_Den+ ////////////////
       hit_turret4__explosive(0.95)
       hit_turret5__explosive(0.95)
        hit_turret4_front__gun2_brake(0.95)
        hit_turret5_front__gun3_brake(0.95)
        hit_turret2__turret2_destroy(0.95)
        hit_turret2__turret2_brake(0.95)
        hit_turret3__turret3_destroy(0.95)
        hit_turret3__turret3_brake(0.95)
        hit_turret4__turret4_destroy(0.95)
        hit_turret4__turret4_brake(0.95)
        hit_turret5__turret5_destroy(0.95)
        hit_turret5__turret5_brake(0.95)       
;///////Engineer_Den- ////////////////		
        imp(0)
        hit_tank__tank_destroy(0)
        hit_engine__engine_brake(0.95)
    )
    ;///////////////////////////////////////////////////////// Gun shells AP hit 170 - 240	
    ("damage_process_bullet_hit"	
       staff(ap_170_240a)

        hit_body__explosive(0)
        hit_body__engine_burn(0)
        hit_body__body_destroy(0.95)
        hit_body__body_brake(0.95)
        ;--------------------------
        hit_body__engine_brake(0.95)
        ;--------------------------
        hit_turret__explosive(0)
        hit_turret_front__gun_brake(0.95)
        hit_turret__turret_destroy(0.95)
        hit_turret__turret_brake(0.95)
;///////Engineer_Den+ ////////////////
       hit_turret4__explosive(0.95)
       hit_turret5__explosive(0.95)
        hit_turret4_front__gun2_brake(0.95)
        hit_turret5_front__gun3_brake(0.95)
        hit_turret2__turret2_destroy(0.95)
        hit_turret2__turret2_brake(0.95)
        hit_turret3__turret3_destroy(0.95)
        hit_turret3__turret3_brake(0.95)
        hit_turret4__turret4_destroy(0.95)
        hit_turret4__turret4_brake(0.95)
        hit_turret5__turret5_destroy(0.95)
        hit_turret5__turret5_brake(0.95)       
;///////Engineer_Den- ////////////////		
        imp(0)
        hit_tank__tank_destroy(0.95)
        hit_engine__engine_brake(0.95)
    )
	;///////////////////////////////////////////////////////// Gun shells AP hit 290 - 300	
    ("damage_process_bullet_hit"
       staff(ap_290_300a)

        hit_body__explosive(0)
        hit_body__engine_burn(0)
        hit_body__body_destroy(0.95)
        hit_body__body_brake(0.95)
        ;--------------------------
        hit_body__engine_brake(0.95)
        ;--------------------------
        hit_turret__explosive(0)
        hit_turret_front__gun_brake(0.95)
        hit_turret__turret_destroy(0.95)
        hit_turret__turret_brake(0.95)
;///////Engineer_Den+ ////////////////
       hit_turret4__explosive(0.95)
       hit_turret5__explosive(0.95)
        hit_turret4_front__gun2_brake(0.95)
        hit_turret5_front__gun3_brake(0.95)
        hit_turret2__turret2_destroy(0.95)
        hit_turret2__turret2_brake(0.95)
        hit_turret3__turret3_destroy(0.95)
        hit_turret3__turret3_brake(0.95)
        hit_turret4__turret4_destroy(0.95)
        hit_turret4__turret4_brake(0.95)
        hit_turret5__turret5_destroy(0.95)
        hit_turret5__turret5_brake(0.95)       
;///////Engineer_Den- ////////////////		
        imp(0)
        hit_tank__tank_destroy(0.95)
        hit_engine__engine_brake(0.95)
    )
    ;///////////////////////////////////////////////////////// Gun shells AP hit 600	
    ("damage_process_bullet_hit"	
       staff(ap_600a)

        hit_body__explosive(0)
        hit_body__engine_burn(0)
        hit_body__body_destroy(0.95)
        hit_body__body_brake(0.95)
        ;--------------------------
        hit_body__engine_brake(0.95)
        ;--------------------------
        hit_turret__explosive(0)
        hit_turret_front__gun_brake(0.95)
        hit_turret__turret_destroy(0.95)
        hit_turret__turret_brake(0.95)
;///////Engineer_Den+ ////////////////
       hit_turret4__explosive(0.95)
       hit_turret5__explosive(0.95)
        hit_turret4_front__gun2_brake(0.95)
        hit_turret5_front__gun3_brake(0.95)
        hit_turret2__turret2_destroy(0.95)
        hit_turret2__turret2_brake(0.95)
        hit_turret3__turret3_destroy(0.95)
        hit_turret3__turret3_brake(0.95)
        hit_turret4__turret4_destroy(0.95)
        hit_turret4__turret4_brake(0.95)
        hit_turret5__turret5_destroy(0.95)
        hit_turret5__turret5_brake(0.95)       
;///////Engineer_Den- ////////////////		
        imp(0)
        hit_tank__tank_destroy(0.95)
        hit_engine__engine_brake(0.95)
    )						
    ;///////////////////////////////////////////////////////// Gun shells FG hit 14 - 19
;    ("damage_process_bullet_hit"
;       staff(fg_14_19f)
;
;        hit_body__explosive(0)
;        hit_body__engine_burn(0)
;        hit_body__body_destroy(0)
;        hit_body__body_brake(0)
;        ;--------------------------
;        hit_body__engine_brake(0)
;        ;--------------------------
;        hit_turret__explosive(0)
;        hit_turret_front__gun_brake(0)
;        hit_turret__turret_destroy(0)
;        hit_turret__turret_brake(0)
;        imp(0)
;        hit_tank__tank_destroy(0)
;        hit_engine__engine_brake(0)
;    )
    ;///////////////////////////////////////////////////////// Gun shells FG hit 20 - 28	
;    ("damage_process_bullet_hit"
;       staff(fg_20_28f)
;
;        hit_body__explosive(0)
;        hit_body__engine_burn(0)
;        hit_body__body_destroy(0)
;        hit_body__body_brake(0)
;        ;--------------------------
;        hit_body__engine_brake(0)
;        ;--------------------------
;        hit_turret__explosive(0)
;        hit_turret_front__gun_brake(0)
;        hit_turret__turret_destroy(0)
;        hit_turret__turret_brake(0)
;        imp(0)
;        hit_tank__tank_destroy(0)
;        hit_engine__engine_brake(0)
;    )
    ;///////////////////////////////////////////////////////// Gun shells FG hit 30 - 37	
;    ("damage_process_bullet_hit"
;       staff(fg_30_37f)
;
;        hit_body__explosive(0)
;        hit_body__engine_burn(0)
;        hit_body__body_destroy(0)
;        hit_body__body_brake(0)
;        ;--------------------------
;        hit_body__engine_brake(0)
;        ;--------------------------
;        hit_turret__explosive(0)
;        hit_turret_front__gun_brake(0)
;        hit_turret__turret_destroy(0)
;        hit_turret__turret_brake(0)
;        imp(0)
;        hit_tank__tank_destroy(0)
;        hit_engine__engine_brake(0)
;    )
    ;///////////////////////////////////////////////////////// Gun shells FG hit 40 - 57	
;    ("damage_process_bullet_hit"
;       staff(fg_40_57f)
;
;        hit_body__explosive(0)
;        hit_body__engine_burn(0)
;        hit_body__body_destroy(0)
;        hit_body__body_brake(0)
;        ;--------------------------
;        hit_body__engine_brake(0)
;        ;--------------------------
;        hit_turret__explosive(0)
;        hit_turret_front__gun_brake(0)
;        hit_turret__turret_destroy(0)
;        hit_turret__turret_brake(0)
;        imp(0)
;        hit_tank__tank_destroy(0)
;        hit_engine__engine_brake(0)
;    )
    ;///////////////////////////////////////////////////////// Gun shells FG hit 70 - 77	
;    ("damage_process_bullet_hit"
;       staff(fg_70_77f)
;
;        hit_body__explosive(0)
;        hit_body__engine_burn(0)
;        hit_body__body_destroy(0)
;        hit_body__body_brake(0)
;        ;--------------------------
;        hit_body__engine_brake(0)
;        ;--------------------------
;        hit_turret__explosive(0)
;        hit_turret_front__gun_brake(0)
;        hit_turret__turret_destroy(0)
;        hit_turret__turret_brake(0)
;        imp(0)
;        hit_tank__tank_destroy(0)
;        hit_engine__engine_brake(0)
;    )
    ;///////////////////////////////////////////////////////// Gun shells FG hit 80 - 95	
;    ("damage_process_bullet_hit"
;       staff(fg_80_95f)
;
;        hit_body__explosive(0)
;        hit_body__engine_burn(0)
;        hit_body__body_destroy(0)
;        hit_body__body_brake(0)
;        ;--------------------------
;        hit_body__engine_brake(0)
;        ;--------------------------
;        hit_turret__explosive(0)
;        hit_turret_front__gun_brake(0)
;        hit_turret__turret_destroy(0)
;        hit_turret__turret_brake(0)
;        imp(0)
;        hit_tank__tank_destroy(0)
;        hit_engine__engine_brake(0)
;    )
    ;///////////////////////////////////////////////////////// Gun shells FG hit 100 - 107	
    ("damage_process_bullet_hit"
       staff(fg_100_107f)

        hit_body__explosive(0)
        hit_body__engine_burn(0)
        hit_body__body_destroy(0)
        hit_body__body_brake(0)
        ;--------------------------
        hit_body__engine_brake(0)
        ;--------------------------
        hit_turret__explosive(0)
        hit_turret_front__gun_brake(0.5)
        hit_turret__turret_destroy(0)
        hit_turret__turret_brake(0.5)
;///////Engineer_Den+ ////////////////
       hit_turret4__explosive(0.5)
       hit_turret5__explosive(0.5)
        hit_turret4_front__gun2_brake(0.5)
        hit_turret5_front__gun3_brake(0.5)
        hit_turret2__turret2_destroy(0.5)
        hit_turret2__turret2_brake(0.5)
        hit_turret3__turret3_destroy(0.5)
        hit_turret3__turret3_brake(0.5)
        hit_turret4__turret4_destroy(0.5)
        hit_turret4__turret4_brake(0.5)
        hit_turret5__turret5_destroy(0.5)
        hit_turret5__turret5_brake(0.5)       
;///////Engineer_Den- ////////////////		
        imp(0)
        hit_tank__tank_destroy(0)
        hit_engine__engine_brake(0.95)
    )
    ;///////////////////////////////////////////////////////// Gun shells FG hit 120 - 130	
    ("damage_process_bullet_hit"
       staff(fg_120_130f)

        hit_body__explosive(0)
        hit_body__engine_burn(0)
        hit_body__body_destroy(0)
        hit_body__body_brake(0.5)
        ;--------------------------
        hit_body__engine_brake(0.5)
        ;--------------------------
        hit_turret__explosive(0)
        hit_turret_front__gun_brake(0.95)
        hit_turret__turret_destroy(0.95)
        hit_turret__turret_brake(0.95)
;///////Engineer_Den+ ////////////////
       hit_turret4__explosive(0.95)
       hit_turret5__explosive(0.95)
        hit_turret4_front__gun2_brake(0.95)
        hit_turret5_front__gun3_brake(0.95)
        hit_turret2__turret2_destroy(0.95)
        hit_turret2__turret2_brake(0.95)
        hit_turret3__turret3_destroy(0.95)
        hit_turret3__turret3_brake(0.95)
        hit_turret4__turret4_destroy(0.95)
        hit_turret4__turret4_brake(0.95)
        hit_turret5__turret5_destroy(0.95)
        hit_turret5__turret5_brake(0.95)       
;///////Engineer_Den- ////////////////		
        imp(0)
        hit_tank__tank_destroy(0)
        hit_engine__engine_brake(0.95)
    )
    ;///////////////////////////////////////////////////////// Gun shells FG hit 149 - 155	
    ("damage_process_bullet_hit"
       staff(fg_149_155f)

        hit_body__explosive(0)
        hit_body__engine_burn(0.25)
        hit_body__body_destroy(0.95)
        hit_body__body_brake(0.95)
        ;--------------------------
        hit_body__engine_brake(0.95)
        ;--------------------------
        hit_turret__explosive(0)
        hit_turret_front__gun_brake(0.95)
        hit_turret__turret_destroy(0.95)
        hit_turret__turret_brake(0.95)
;///////Engineer_Den+ ////////////////
       hit_turret4__explosive(0.95)
       hit_turret5__explosive(0.95)
        hit_turret4_front__gun2_brake(0.95)
        hit_turret5_front__gun3_brake(0.95)
        hit_turret2__turret2_destroy(0.95)
        hit_turret2__turret2_brake(0.95)
        hit_turret3__turret3_destroy(0.95)
        hit_turret3__turret3_brake(0.95)
        hit_turret4__turret4_destroy(0.95)
        hit_turret4__turret4_brake(0.95)
        hit_turret5__turret5_destroy(0.95)
        hit_turret5__turret5_brake(0.95)       
;///////Engineer_Den- ////////////////		
        imp(0)
        hit_tank__tank_destroy(15)
        hit_engine__engine_brake(0.95)
    )	
    ;///////////////////////////////////////////////////////// Gun shells FG hit 170 - 240	
    ("damage_process_bullet_hit"
       staff(fg_170_240f)

        hit_body__explosive(0.95)
        hit_body__engine_burn(0.95)
        hit_body__body_destroy(0.95)
        hit_body__body_brake(0.95)
        ;--------------------------
        hit_body__engine_brake(0.95)
        ;--------------------------
        hit_turret__explosive(0.95)
        hit_turret_front__gun_brake(0.95)
        hit_turret__turret_destroy(0.95)
        hit_turret__turret_brake(0.95)
;///////Engineer_Den+ ////////////////
       hit_turret4__explosive(0.95)
       hit_turret5__explosive(0.95)
        hit_turret4_front__gun2_brake(0.95)
        hit_turret5_front__gun3_brake(0.95)
        hit_turret2__turret2_destroy(0.95)
        hit_turret2__turret2_brake(0.95)
        hit_turret3__turret3_destroy(0.95)
        hit_turret3__turret3_brake(0.95)
        hit_turret4__turret4_destroy(0.95)
        hit_turret4__turret4_brake(0.95)
        hit_turret5__turret5_destroy(0.95)
        hit_turret5__turret5_brake(0.95)       
;///////Engineer_Den- ////////////////		
        imp(0)
        hit_tank__tank_destroy(0.95)
        hit_engine__engine_brake(0.95)
    )
    ;///////////////////////////////////////////////////////// Gun shells FG hit 290 - 300	
    ("damage_process_bullet_hit"
       staff(fg_290_300f)

        hit_body__explosive(0.95)
        hit_body__engine_burn(0.95)
        hit_body__body_destroy(0.95)
        hit_body__body_brake(0.95)
        ;--------------------------
        hit_body__engine_brake(0.95)
        ;--------------------------
        hit_turret__explosive(0.95)
        hit_turret_front__gun_brake(0.95)
        hit_turret__turret_destroy(0.95)
        hit_turret__turret_brake(0.95)
;///////Engineer_Den+ ////////////////
       hit_turret4__explosive(0.95)
       hit_turret5__explosive(0.95)
        hit_turret4_front__gun2_brake(0.95)
        hit_turret5_front__gun3_brake(0.95)
        hit_turret2__turret2_destroy(0.95)
        hit_turret2__turret2_brake(0.95)
        hit_turret3__turret3_destroy(0.95)
        hit_turret3__turret3_brake(0.95)
        hit_turret4__turret4_destroy(0.95)
        hit_turret4__turret4_brake(0.95)
        hit_turret5__turret5_destroy(0.95)
        hit_turret5__turret5_brake(0.95)       
;///////Engineer_Den- ////////////////		
        imp(0)
        hit_tank__tank_destroy(0.95)
        hit_engine__engine_brake(0.95)
    )
    ;///////////////////////////////////////////////////////// Gun shells FG hit 600	
    ("damage_process_bullet_hit"
       staff(fg_600f)

        hit_body__explosive(0.95)
        hit_body__engine_burn(0.95)
        hit_body__body_destroy(0.95)
        hit_body__body_brake(0.95)
        ;--------------------------
        hit_body__engine_brake(0.95)
        ;--------------------------
        hit_turret__explosive(0.95)
        hit_turret_front__gun_brake(0.95)
        hit_turret__turret_destroy(0.95)
        hit_turret__turret_brake(0.95)
;///////Engineer_Den+ ////////////////
       hit_turret4__explosive(0.95)
       hit_turret5__explosive(0.95)
        hit_turret4_front__gun2_brake(0.95)
        hit_turret5_front__gun3_brake(0.95)
        hit_turret2__turret2_destroy(0.95)
        hit_turret2__turret2_brake(0.95)
        hit_turret3__turret3_destroy(0.95)
        hit_turret3__turret3_brake(0.95)
        hit_turret4__turret4_destroy(0.95)
        hit_turret4__turret4_brake(0.95)
        hit_turret5__turret5_destroy(0.95)
        hit_turret5__turret5_brake(0.95)       
;///////Engineer_Den- ////////////////		
        imp(0)
        hit_tank__tank_destroy(0.95)
        hit_engine__engine_brake(0.95)
    )	
}; end of bullet_hit

{on blast ;higher energy must be first
    ("blast_damage_contusion"
	blast_rand_contusion(0.95)
	blast_energy(38)
	blast_crew_shock_time(2.00)
    )
    ("blast_damage_contusion"
	blast_rand_contusion(0.80)
	blast_energy(26)
	blast_crew_shock_time(1.50)
    )
    ("blast_damage_contusion"
	blast_rand_contusion(0)
	blast_energy(24)
	blast_crew_shock_time(0.40)
    )
}
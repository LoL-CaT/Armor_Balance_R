; Bedford QLB
	(include "/properties/car.ext")
    (include "/properties/l_car_mobility.ext")
	(include "/properties/selection/vehicle.inc"  scale(1.1))
	{props "vehicle" "car" "truck" "wheeled" "vision_vehicle_minimum"}
	{targetClass "car" "fg bullet"}	
	("armor_medium" args 1.0)	
  	{able "emit_on_attack"}	

    ("wheel" args "wheelright1")
	("wheel" args "wheelleft1")
	("wheel" args "wheelright2")
	("wheel" args "wheelleft2")


	("crew_2_human")
	("board_animation"
		place(driver)
		board_begin(board_big-highcar)
		board_end(seat_driver_car)
		base(doorright)
	)
	("board_animation"
		place(commander)
		board_begin(board_big-highcar_driver)
		board_end(seat_passenger)
		base(doorleft)
	)
	
	        {Volume "bodyback"
		{thickness 2}
	}
	        {Volume "shield"
		{thickness 1}
	}

	{extender "shield"
		(mod "mp"
			{on}
		)
	}

	{mass 7200}
	{Chassis
	("car_trace" fx("tracewheel02") step(0.09) wheell("wlf") wheelr("wrf") bonel("FXtraceL1") boner("FXtraceR1"))
	("car_trace" fx("tracewheel02") step(0.09) wheell("wlr") wheelr("wrr") bonel("FXtraceL2") boner("FXtraceR2"))
		("mobility"
			speed(65)
			weight(7.2)
			power(72)
			fuel(151)	
		)
	}
	{Extension "bedf-ammo2.mdl"}



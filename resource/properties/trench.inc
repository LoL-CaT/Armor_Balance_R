;SDL
game_entity
	{props "trench"}
	{obstacleid "trench_wall"}
	{collider "construction"}
	{NoCastShadows}
	{extender "land_patch"
		{AlignEnabled 1}
		{AlignStacked 0}
		{AlignVolumes 1}
		{TerrainType "road" "bridge"}
	}
	(define "volume" 
		{Volume %0 {thickness 20} {tags "body"} {able {contact 0} {obstacle 1}}}
	)
	(define "boneLand" 
		{bone %0 {parameters "Ground;Land;Align;"}}
	)
	(define "boneAlign" 
		{bone %0 {parameters "Align;"}}
	)

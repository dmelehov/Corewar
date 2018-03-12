.name "Fucker"
.comment "Fuck the princess!"

start:
	st r1,11
	st r1,11
live:
	live %0
	live %0
	zjmp %:start
	fork %:jump
load:
	fork %:part1
	fork %:start
	ld %191103488,r2
	ld %11,r3
	ld %0,r10
	st r2,430
	zjmp %425
jump:
	ld %0, r2
	zjmp %:start
part1:
	fork %:part2
	ld %197119,r2
	ld %15,r3
	st r2,399
	ld %0,r10
	zjmp %383
part2:
	st r1,r2
	ld %7,r3
	ld %0,r10
	zjmp %362


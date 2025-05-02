all:
	clear
	@ gcc src/*.c -o bin/prog

run:
	all
	bin/prog

val:
	clear
	@ valgrind bin/prog
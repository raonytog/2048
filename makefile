all:
	clear
	@ gcc src/*.c -o bin/prog

run:
	make all
	bin/prog

val:
	clear
	@ valgrind bin/prog
CC=clang
OPTIONS=-std=c99 -O3 -c
all: mvmnt.o tmctl.o
	${CC} -o tmctl.out mvmnt.o tmctl.o
mvmnt.o: mvmnt.c
	${CC} ${OPTIONS} mvmnt.c
tmctl.o: mvmnt.h tmctl.c
	${CC} ${OPTIONS} tmctl.c
install:
	mv tmctl.out /usr/local/bin/tmctl

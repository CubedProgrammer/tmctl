# This file is part of tmctl.
# Copyright (C) 2022, github.com/CubedProgrammer, owner of said account.

# tmctl is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

# tmctl is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

# You should have received a copy of the GNU General Public License along with tmctl. If not, see <https://www.gnu.org/licenses/>. 

CC=clang
OPTIONS=-std=c99 -O3 -c
all: fmt.o mvmnt.o tmctl.o
	${CC} -o tmctl.out fmt.o mvmnt.o tmctl.o
fmt.o: fmt.c
	${CC} ${OPTIONS} fmt.c
mvmnt.o: mvmnt.c
	${CC} ${OPTIONS} mvmnt.c
tmctl.o: fmt.h mvmnt.h tmctl.c
	${CC} ${OPTIONS} tmctl.c
install:
	mv tmctl.out /usr/local/bin/tmctl

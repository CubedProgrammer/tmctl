// This file is part of tmctl.
// Copyright (C) 2022, github.com/CubedProgrammer, owner of said account.

// tmctl is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

// tmctl is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along with tmctl. If not, see <https://www.gnu.org/licenses/>. 

#include<stdio.h>

void up(unsigned q)
{
    if(q)
        printf("\033\133%uA", q);
}

void down(unsigned q)
{
    if(q)
        printf("\033\133%uB", q);
}

void right(unsigned q)
{
    if(q)
        printf("\033\133%uC", q);
}

void left(unsigned q)
{
    if(q)
        printf("\033\133%uD", q);
}

void nxtln(unsigned q)
{
    if(q)
        printf("\033\133%uE", q);
}

void prvln(unsigned q)
{
    if(q)
        printf("\033\133%uF", q);
}

void setpos(unsigned r, unsigned c)
{
    printf("\033\133%u;%uH", r, c);
}

// This file is part of tmctl.
// Copyright (C) 2022, github.com/CubedProgrammer, owner of said account.

// tmctl is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

// tmctl is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along with tmctl. If not, see <https://www.gnu.org/licenses/>. 

#include<stdio.h>

void resetfmt(void)
{
    fputs("\033\133m", stdout);
}

void boldfmt(void)
{
    fputs("\033\1331m", stdout);
}

void faintfmt(void)
{
    fputs("\033\1332m", stdout);
}

void italicfmt(void)
{
    fputs("\033\1333m", stdout);
}

void underlinefmt(void)
{
    fputs("\033\1334m", stdout);
}

void crossfmt(void)
{
    fputs("\033\1339m", stdout);
}

void fgfmt8(int col)
{
    printf("\033\133%dm", col);
}

void fgfmt(int col)
{
    int r = (col & 0xff0000) >> 16, g = (col & 0xff00) >> 8, b = col & 0xff;
    printf("\033\13338;2;%d;%d;%dm", r, g, b);
}

void bgfmt8(int col)
{
    printf("\033\133%dm", col + 10);
}

void bgfmt(int col)
{
    int r = (col & 0xff0000) >> 16, g = (col & 0xff00) >> 8, b = col & 0xff;
    printf("\033\13348;2;%d;%d;%dm", r, g, b);
}

void overlinefmt(void)
{
    fputs("\033\13353m", stdout);
}

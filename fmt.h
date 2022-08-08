// This file is part of tmctl.
// Copyright (C) 2022, github.com/CubedProgrammer, owner of said account.

// tmctl is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

// tmctl is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along with tmctl. If not, see <https://www.gnu.org/licenses/>. 

#ifndef Included_fmt_h
#define Included_fmt_h

#define BLACK 30
#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34
#define MAGENTA 35
#define CYAN 36
#define WHITE 37

void resetfmt(void);
void boldfmt(void);
void faintfmt(void);
void italicfmt(void);
void underlinefmt(void);
void crossfmt(void);
void fgfmt8(int col);
void fgfmt(int col);
void bgfmt8(int col);
void bgfmt(int col);
void overlinefmt(void);

#endif

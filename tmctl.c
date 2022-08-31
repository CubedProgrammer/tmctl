// This file is part of tmctl.
// Copyright (C) 2022, github.com/CubedProgrammer, owner of said account.

// tmctl is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

// tmctl is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along with tmctl. If not, see <https://www.gnu.org/licenses/>. 

#include<stdio.h>
#include<stdlib.h>
#ifdef _WIN32
#include<windows.h>
#endif
#include"fmt.h"
#include"interactive.h"
#include"mvmnt.h"

#define MAJOR 1
#define MINOR 3

unsigned parsecmd(const char *cmd, char **next, unsigned len)
{
    unsigned used = 0;
    unsigned x, y;
    for(const char *it = cmd; *it != '\0'; ++it)
    {
        switch(*it)
        {
            case'.':
                resetfmt();
                break;
            case'I':
                interactive();
                break;
            case'o':
                boldfmt();
                break;
            case'f':
                faintfmt();
                break;
            case'i':
                italicfmt();
                break;
            case'e':
                underlinefmt();
                break;
            case't':
                crossfmt();
                break;
            case'v':
                overlinefmt();
                break;
            case'k':
                fgfmt8(BLACK);
                break;
            case'r':
                fgfmt8(RED);
                break;
            case'g':
                fgfmt8(GREEN);
                break;
            case'y':
                fgfmt8(YELLOW);
                break;
            case'b':
                fgfmt8(BLUE);
                break;
            case'm':
                fgfmt8(MAGENTA);
                break;
            case'c':
                fgfmt8(CYAN);
                break;
            case'w':
                fgfmt8(WHITE);
                break;
            case'a':
                if(used == len)
                    y = 0xffffff;
                else
                {
                    y = strtol(next[used], NULL, 16);
                    ++used;
                }
                fgfmt(y);
                break;
            case'K':
                bgfmt8(BLACK);
                break;
            case'R':
                bgfmt8(RED);
                break;
            case'G':
                bgfmt8(GREEN);
                break;
            case'Y':
                bgfmt8(YELLOW);
                break;
            case'B':
                bgfmt8(BLUE);
                break;
            case'M':
                bgfmt8(MAGENTA);
                break;
            case'C':
                bgfmt8(CYAN);
                break;
            case'W':
                bgfmt8(WHITE);
                break;
            case'A':
                if(used == len)
                    y = 0;
                else
                {
                    y = strtol(next[used], NULL, 16);
                    ++used;
                }
                bgfmt(y);
                break;
            case'u':
                if(used == len)
                    x = 1;
                else
                {
                    x = atoi(next[used]);
                    ++used;
                }
                up(x);
                break;
            case'd':
                if(used == len)
                    x = 1;
                else
                {
                    x = atoi(next[used]);
                    ++used;
                }
                down(x);
                break;
            case'h':
                if(used == len)
                    x = 1;
                else
                {
                    x = atoi(next[used]);
                    ++used;
                }
                right(x);
                break;
            case'l':
                if(used == len)
                    x = 1;
                else
                {
                    x = atoi(next[used]);
                    ++used;
                }
                left(x);
                break;
            case'n':
                if(used == len)
                    x = 1;
                else
                {
                    x = atoi(next[used]);
                    ++used;
                }
                nxtln(x);
                break;
            case'p':
                if(used == len)
                    x = 1;
                else
                {
                    x = atoi(next[used]);
                    ++used;
                }
                prvln(x);
                break;
            case's':
                x = atoi(next[used]);
                y = atoi(next[++used]);
                setpos(x, y);
                ++used;
                break;
            default:
                fprintf(stderr, "Unrecognized command %c, ignored.\n", *it);
        }
    }
    return used;
}

int main(int argl, char *argv[])
{
#ifdef _WIN32
    DWORD cm;
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleMode(out, &cm);
    cm |= ENABLE_VIRTUAL_TERMINAL_PROCESSING
    SetConsoleMode(out, cm);
#endif
    int succ = 0;
    if(argl == 1)
    {
        printf("%s [COMMANDS...] [VALUES...]\n", *argv);
#ifdef PATCH
        printf("Version %d.%d.%d\n", MAJOR, MINOR, PATCH);
#else
        printf("Version %d.%d\n", MAJOR, MINOR);
#endif
        puts("\nLet n be the value for a command.");
        puts("Commands u, d, h, and l, moves n characters up, down, right, and left, respectively.");
        puts("Commands n and p moves to the next and previous line, respectively, n times.");
        puts("Defaults to moving one unit");
        puts("Command s sets the position to row r and column c, where r is the first value, and c is the second.");
        puts("Text formatting");
        puts("Commands o, f, i, e, t, and v sets bold, faint, italic, underline, strikethrough, and overline respectively.");
        puts("Commands k, r, g, y, b, m, c, w sets the foreground colour.");
        puts("Capitalized sets background colour.");
        puts("Commands a and A sets foreground or background colour to a true colour, based on next hexadecimal value.");
        puts("Defaults to white for foreground and black for background");
        puts("Command I will start interactive mode, press q to exit.");
        puts("Command . will reset formatting to normal.");
        printf("Example: '%s pr 3 5' moves to the beginning of the line three lines previous, and then five to the right.\n", *argv);
    }
    else
    {
        int nextarg = 0;
        for(int i = 1; i < argl; ++i)
        {
            nextarg = i + parsecmd(argv[i], argv + i + 1, argl - i - 1);
            if(nextarg)
                i = nextarg, nextarg = 0;
        }
    }
    return succ;
}

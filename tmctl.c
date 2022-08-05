#include<stdio.h>
#include<stdlib.h>
#include"mvmnt.h"

#define MAJOR 1
#define MINOR 0

unsigned parsecmd(const char *cmd, char **next)
{
    unsigned used = 0;
    unsigned x, y;
    for(const char *it = cmd; *it != '\0'; ++it)
    {
        switch(*it)
        {
            case'u':
                x = atoi(next[used]);
                ++used;
                up(x);
                break;
            case'd':
                x = atoi(next[used]);
                ++used;
                down(x);
                break;
            case'r':
                x = atoi(next[used]);
                ++used;
                right(x);
                break;
            case'l':
                x = atoi(next[used]);
                ++used;
                left(x);
                break;
            case'n':
                x = atoi(next[used]);
                ++used;
                nxtln(x);
                break;
            case'p':
                x = atoi(next[used]);
                ++used;
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
        puts("Commands u, d, r, and l, moves n characters up, down, right, and left, respectively.");
        puts("Commands n and p moves to the next and previous line, respectively, n times.");
        printf("Example: '%s pr 3 5' moves to the beginning of the line three lines previous, and then five to the right.\n", *argv);
    }
    else
    {
        int nextarg = 0;
        for(int i = 1; i < argl; ++i)
        {
            nextarg = i + parsecmd(argv[i], argv + i + 1);
            if(nextarg)
                i = nextarg, nextarg = 0;
        }
    }
    return succ;
}

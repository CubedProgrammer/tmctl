#include<stdio.h>
#include<termios.h>
#include<unistd.h>
#include"interactive.h"

void interactive(void)
{
    char seq[3];
    struct termios old, curr;
    tcgetattr(STDIN_FILENO, &old);
    curr = old;
    curr.c_lflag &= ~(ECHO|ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &curr);
    for(int c = rd(); c != 'q'; c = rd())
    {
        switch(c)
        {
            case 0x1b5b41:
            case 0x1b5b42:
            case 0x1b5b43:
            case 0x1b5b44:
                seq[0] = c >> 16;
                seq[1] = c >> 8;
                seq[2] = c;
                write(STDOUT_FILENO, seq, sizeof seq);
                break;
            default:
                putchar('\a');
                fflush(stdout);
        }
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &old);
}

int rd(void)
{
    int c;
    char seq[4];
    int cnt = read(STDIN_FILENO, seq, sizeof seq);
    if(cnt < 0)
        perror("read failed");
    else
    {
        c = 0;
        for(int i = 0; i < cnt; ++i)
            c <<= 8, c += seq[i];
    }
    return c;
}

#include<stdio.h>
#include<sys/ioctl.h>
#include<termios.h>
#include<unistd.h>
#include"interactive.h"

void interactive(void)
{
    char seq[3];
    struct winsize tsz;
    struct termios old, curr;
    int col, row;
    if(ioctl(STDIN_FILENO, TIOCGWINSZ, &tsz) == -1)
        perror("ioctl TIOCGWINSZ failed");
    row = tsz.ws_row;
    col = tsz.ws_col;
    tcgetattr(STDIN_FILENO, &old);
    curr = old;
    curr.c_lflag &= ~(ECHO|ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &curr);
    for(int c = rd(); c != 'q'; c = rd())
    {
        switch(c)
        {
            case 0x1b5b357e:
                printf("\033\133%dA", row - 1);
                break;
            case 0x1b5b367e:
                printf("\033\133%dB", col - 1);
                break;
            case 0x1b5b48:
                putchar('\r');
                break;
            case 0x1b5b46:
                printf("\r\033\133%dC", col - 1);
                break;
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

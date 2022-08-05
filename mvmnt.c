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

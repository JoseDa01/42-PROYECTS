

#include <stdio.h>
#include "libftprintf.h"

int main()
{
    //int a = 15;
    int b = -54;
    int s = -7;

    printf("-----------------\n");
    printf("%0*i|\n", s, b);
    ft_printf("%0*i|\n", s, b);
    printf("-----------------\n");
}

/*
    int a = 7;
    char *b = "hola";
    printf("-----------------\n");
    printf("%3s\n", b);
    ft_printf("%3s\n", b);
    printf("-----------------\n");
*/
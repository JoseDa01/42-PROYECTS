

#include <stdio.h>
#include "libftprintf.h"

int main()
{
    //int a = 15;
    int b = 3421;

    printf("-----------------\n");
    printf("%05k\n");
    ft_printf("%10.3i\n", b);
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
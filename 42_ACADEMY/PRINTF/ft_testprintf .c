

#include <stdio.h>
#include "libftprintf.h"

int main()
{
    char *b = "hola";
    printf("-----------------\n");
    printf("%12s\n", b);
    ft_printf("%12s\n", b);
    printf("-----------------\n");
}

/*
//int a = 7;
    char *b = "hola";
    printf("-----------------\n");
    printf("%3s\n", b);
    ft_printf("%3s\n", b);
    printf("-----------------\n");
*/
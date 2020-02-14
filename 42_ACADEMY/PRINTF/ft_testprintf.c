

#include <stdio.h>
#include "libftprintf.h"

int main()
{
    //int a = 15;
    //int b = 8375;

    printf("-----------------\n");
    printf("%-8.5da\n", 34);
    ft_printf("%-8.5da\n", 34);
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
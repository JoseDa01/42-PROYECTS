

#include <stdio.h>
#include "libftprintf.h"

int main()
{
    int a = 1;
    //char *b = "yolo";
    printf("-----------------\n");
    printf("%i\n", a);
    ft_printf("%i\n", a);
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
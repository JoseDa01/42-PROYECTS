

#include <stdio.h>
#include "libftprintf.h"

int main()
{
    char *b = NULL;
    printf("-----------------\n");
    printf("%s\n", b);
    ft_printf("hello, %s.\n", b);
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
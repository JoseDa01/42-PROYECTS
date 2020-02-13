/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtello-m <jtello-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:38:40 by jtello-m          #+#    #+#             */
/*   Updated: 2020/02/13 16:57:13 by jtello-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int main (void)
{
    //printf con %c (char)
    printf("Printf con %%c\n\n");
    char    ch = 'r';
    printf("printf says: %c\n", ch);
    ft_printf("ft_ printf says: %c\n", ch);
    printf("-----------------------\n");
    //printf con %s (string)
    printf("Printf con %%s\n\n");
    char    *str = "hola";
    printf("printf says: %s\n", str);
    ft_printf("ft_printf says: %s\n", str);
    printf("-----------------------\n");

   //printf con %p (puntero)
    printf("Printf con %%p\n\n");
    int x = 99;
    int *ptr;
    ptr = &x;
    printf("printf says: %p\n", ( void * )ptr);
    ft_printf("ftprintf says: %p\n", ( void * )ptr);
    printf("-----------------------\n");
    //printf con %d (numero entero)
    printf("Printf con %%d\n\n");
    int num = 100;
    printf("printf says: %d\n", num);
    ft_printf("ft_ printf says: %d\n", num);
    printf("-----------------------\n");
    //printf con %i (numero entero detectando la base) *Anotación: Hacer pruebas con otras bases.
    printf("Printf con %%i\n\n");
    int num1 = 100;
    printf("printf says: %i\n", num1);
    ft_printf("ft_ printf says: %i\n", num1);
    printf("-----------------------\n");
    //printf con %u (numero entero sin signo)
    printf("Printf con %%u\n\n");
    unsigned int    num2 = 100;
    printf("printf says: %u\n", num2);
    ft_printf("ft_ printf says: %u\n", num2);
    printf("-----------------------\n");
    //printf con %x (numero hexadecimal sin signo usa letras minúsculas abcdef)
    printf("Printf con %%x\n\n");
    int numhex = 100;
    printf("printf says: %x\n", numhex);
    ft_printf("ft_ printf says: %x\n", numhex);
    printf("-----------------------\n");
    //printf con %X (numero hexadecimalsin signo usa letras mayúsculas ABCDEF)
    printf("Printf con %%X\n\n");
    int numHEX = 100;
    printf("printf says: %X\n", numHEX);
    ft_printf("ft_ printf says: %X\n", numHEX);
    printf("-----------------------\n");
    //printf con %% (no recibe flag)
    printf("Printf con %%%%\n\n");
    printf("printf says: %%\n");
    ft_printf("ft_ printf says: %%\n");
    printf("-----------------------\n");
}
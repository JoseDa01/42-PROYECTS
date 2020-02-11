#include <stdlib.h>
#include <stdio.h>

int		ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char	*ft_itoa_base(int nbr, int base)
{
	char	*str;
	int		size;
	char	*tab;
	int		flag;
	int		tmp;
	flag = 0;
	size = 0;
	tab = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (0);
	if (nbr < 0 && base == 10)
		flag = 1;
	tmp = nbr;
	while (tmp /= base)
		size++;
	size = size + flag + 1;
	str = (char *)malloc(sizeof(char) * size  + 1);
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = tab[ft_abs(nbr % base)];
		size--;
		nbr /=base;
	}
    printf("%s\n", str);
	return (str);
}

int main()
{
    ft_itoa_base(1234, 16);
    return (0);
}
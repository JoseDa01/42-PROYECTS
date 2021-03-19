
#include <unistd.h>
#include <stdio.h>

float	atof(char *str)
{
	int i;
	float number;
	float flag;
	int sign;

	i = 0;
	number = 0;
	flag = 0;
	sign = 1;
	if (str[0] == '-')
		sign = -1;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			flag = 10;
		else if (str[i] >= '0' && str[i] <= '9')
		{
			if (flag == 0)
				number = number * 10 + str[i] - '0';
			else
			{
				number += (str[i] - '0') / flag;
				flag *= 10;
			}
		}
		i++;
	}
	return(sign * number);
}

int main()
{
	float a;
	a = atof("12.4320");

	printf("%f", a);
	return (0);
}
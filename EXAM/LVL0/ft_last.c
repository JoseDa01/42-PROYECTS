#include <unistd.h>

char *putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (str);
}


int main (int argc, char **argv)
{
	int i;

	i = argc;
	if (argc > 1){

	putstr(argv[i - 1]);
	}
	write(1, "\n", 1);

}

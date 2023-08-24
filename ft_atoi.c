#include <stdlib.h>
#include <stdio.h>


int ft_atoi(const char *str)
{
	int signe;
	int num;
	int i;

	i = 0;
	signe = 1;
	num = 0;
	if (!str)
		return (0);
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == 32)
		i++;
	if (str[i] == 45)
		signe *= -1;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while (str[i] >= '1' && str[i] <= '9')
	{
		num = (str[i] - '0') + (num * 10);
		i++;
	}
	return (num * signe);
}

int main()
{
	printf("%d\n", ft_atoi("45l15"));
	printf("%d", atoi("45l15"));
	// return (0);
}

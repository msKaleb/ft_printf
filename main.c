#include "libft/libft.h"
#include "libftprintf.h"

#include<stdio.h>

int	main(void)
{
	unsigned int	u;
	char			c;
	char			s[] = "test ft_printf";
	int				d;
	int				pret;

	c = 'z';
	d = -12;
	u = -69548;
	pret = printf("   printf: %c | %i | %u | %X | %s | %p %%", c, d, u, u, s, &c);
	//pret = printf("Porque putnbr() y putstr()\t no son suficientes");
	//pret = printf("   printf: %X %%%%", u);
	printf("\tres: %d\n", pret);
	pret = ft_printf("ft_printf: %c | %i | %u | %X | %s | %p %%", c, d, u, u, s, &c);
	//pret = ft_printf("Porque putnbr() y putstr()\t no son suficientes");
	//pret = ft_printf("ft_printf: %X %%%%", u);
	ft_printf("\tres: %d\n", pret);
}
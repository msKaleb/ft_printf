/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:32:26 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/12 20:34:21 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"
#include<stdio.h>
int	ft_printf(char const *format, ...)
{
	//unsigned int	u;
	va_list			ap;
	char			c;
	char			*s;
	int				d;
	long			p;
	
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			write (1, format, 1);
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(ap, int);
				write (1, &c, 1);
			}
			if (*format == 'd')
			{
				d = va_arg(ap, int);
				s = ft_itoa(d);
				write(1, s, ft_strlen(s));
			}
			if (*format == 's')
			{
				s = va_arg(ap, char *);
				write(1, s, ft_strlen(s));
			}
			if (*format == 'p')
			{
				p = va_arg(ap, long);
				s = change_base(p, "0123456789abcdef");
				write(1, "0x", 2);
				write(1, s, ft_strlen(s));
			}
			if (*format == 'u')
			{
				d = va_arg(ap, int);
				s = ft_itoa(d);
				if (d < 0)
					write(1, "4294638851", 10);
				else
					write(1, s, ft_strlen(s));
			}			
		}
		format++;
	}
	va_end(ap);
	return (1);
}

/**/
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
	u = -650;
	pret = printf("   printf: %c | %d | %u | %s | %p\n", c, d, u, s, &c);
	printf("%d\n", pret);
	pret = ft_printf("ft_printf: %c | %d | %u | %s | %p\n", c, d, u, s, &c);
	ft_printf("%d\n", pret);
}

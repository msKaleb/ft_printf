/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:32:26 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/13 18:48:15 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"
#include<stdio.h>
int	ft_printf(char const *format, ...)
{
	unsigned int	u;
	va_list			ap;
	char			c;
	char			*s;
	int				d;
	long			p;
	int				ret;
	
	ret = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			write (1, format, 1);
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				write (1, "%%", 1);
			if (*format == 'c')
			{
				c = va_arg(ap, int);
				write (1, &c, 1);
			}
			if (*format == 'd' || *format == 'i')
			{
				d = va_arg(ap, int);
				s = ft_itoa(d);
				write(1, s, ft_strlen(s));
				ret += ft_strlen(s) - 1;
			}
			if (*format == 's')
			{
				s = va_arg(ap, char *);
				write(1, s, ft_strlen(s));
				ret += ft_strlen(s) - 1;
			}
			if (*format == 'p' || *format == 'x' || *format == 'X')
			{
				p = va_arg(ap, long);
				s = change_base(p, *format);
				if (*format == 'p')
					write(1, "0x", 2);
				write(1, s, ft_strlen(s) + 1);
				ret += ft_strlen(s);
			}
			if (*format == 'u')
			{
				u = va_arg(ap, unsigned int);
				s = ft_itoa_u(u);
				write(1, s, ft_strlen(s));
				ret += ft_strlen(s) - 1;
			}			
		}
		ret += 1;
		format++;
	}
	va_end(ap);
	return (ret);
}
								/*retorno mal*/
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
	u = 69548;
	pret = printf("   printf: %c | %i | %x | %X | %s | %p | %%%%\n", c, d, u, u, s, &c);
	printf("res: %d\n", pret);
	pret = ft_printf("ft_printf: %c | %i | %x | %X | %s | %p | %%%%\n", c, d, u, u, s, &c);
	ft_printf("res: %d\n", pret);
}

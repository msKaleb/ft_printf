/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:32:26 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/12 18:56:17 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"

int	ft_printf(char const *format, ...)
{
	va_list	ap;
	char	c;
	char	*s;
	int		d;
	
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			write (1, &*format, 1);
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
		}
		format++;
	}
	va_end(ap);
	return (1);
}

/**/
int	main(void)
{
	char	c;
	char	s[] = "kaka";
	int		d;

	c = 'z';
	d = 12;
	ft_printf("hola: %c - %d - %s", c, d, s);
}

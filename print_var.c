/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:59:36 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/14 17:39:04 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"

int	print_char(char c)
{
	write (1, &c, 1);
	return (0);
}

int	print_str(char *s)
{
	write(1, s, ft_strlen(s));
	return (ft_strlen(s) - 1);
}

int	print_hex(long p, char format)
{
	char	*s;
	int		ret;

	ret = 0;
	s = change_base(p, format);
	if (format == 'p')
	{
		write(1, "0x", 2);
		ret += 2;
	}
	write(1, s, ft_strlen(s));
	ret += ft_strlen(s) - 1;
	return (ret);
}

int	print_uint(unsigned int u)
{
	char	*s;

	s = ft_itoa_u(u);
	write(1, s, ft_strlen(s));
	return (ft_strlen(s) - 1);
}

int	print_int(int d, char arg)
{
	char	*s;

	if (arg == 'c')
	{
		print_char(d);
		return (0);
	}
	s = ft_itoa(d);
	write(1, s, ft_strlen(s));
	return (ft_strlen(s) - 1);
}

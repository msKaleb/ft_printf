/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:20:31 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/13 17:21:26 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libftprintf.h"

void	rev_str(char *str, int len)
{
	int		i;
	char	aux;

	i = 0;
	while (i < len / 2)
	{
		aux = str[i];
		str[i] = str[(len - 1) - i];
		str[(len - 1) - i] = aux;
		i++;
	}
}

char	*change_base(long nbr, char arg)
{
	static char	res[1];
	char		*base;
	int			i;

	base = "0123456789abcdef";
	if (arg == 'X')
		base = "0123456789ABCDEF";
	if (nbr < 0)
		write (1, "-", 1);
	if (nbr < 0)
		nbr *= -1;
	i = 0;
	res[0] = '0';
	while (nbr > 0)
	{
		res[i] = base[nbr % 16];
		nbr /= 16;
		i++;
	}
	rev_str (res, i);
	if (i == 0)
		i = 1;
	//write (1, res, i);
	return (res);
}
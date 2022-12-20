/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:40:16 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/19 15:03:48 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
#include<stdio.h>
#include<limits.h>

int	main(void)
{
	unsigned int	u;
	char			c;
	//char			s[] = "test ft_printf";
	int				d;
	int				pret;

	c = 'z';
	d = -12;
	u = 69548;
	pret = 0;
	//pret = printf("sysprintf: %x", -10);
	pret = printf("\001\002\007\v\010\f\r\n");
	printf("\tres: %d\n", pret);
	//pret = ft_printf("ft_printf: %x", -10);
	pret = ft_printf("\001\002\007\v\010\f\r\n");
	ft_printf("\tres: %d\n", pret);
}

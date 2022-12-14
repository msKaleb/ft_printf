/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msoria-j <msoria-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:28:56 by msoria-j          #+#    #+#             */
/*   Updated: 2022/12/14 17:38:22 by msoria-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include<stdarg.h>
# include<unistd.h>
# include"./libft/libft.h"

char	*change_base(long nbr, char base);
char	*ft_itoa_u(unsigned int n);
int		print_char(char c);
int		print_str(char *s);
int		print_hex(long p, char format);
int		print_uint(unsigned int u);
int		print_int(int d, char arg);

#endif
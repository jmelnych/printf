/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:43:07 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/09 14:54:24 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

void	print_spaces(list_spec cr, int i)
{
	while (i > (cr.precs > ft_strlen(cr.str) ? cr.precs : ft_strlen(cr.str)))
		{
			write(1, " ", 1);
			i--;
		}
}

void	print_zeros(list_spec cr)
{
	int i;

	i = 0;
	while (i < (cr.precs - ft_strlen(cr.str)))
	{
		write(1, "0", 1);
		i++;
	}
}

void	print_digits(va_list *args, list_spec cr)
{
	int i;

	if (cr.mod == 4)
		cr.str = ft_itoabase(va_arg(*args, intmax_t), 1, 0);
	else if (cr.mod == 3)
		cr.str = ft_itoabase(va_arg(*args, long), 1, 0);
	else if (cr.mod == 0)
		cr.str = ft_itoabase(va_arg(*args, int), 1, 0);
	else if (cr.mod == 2)
		cr.str = ft_itoabase((short)va_arg(*args, int), 1, 0);
	else if (cr.mod == 1)
		cr.str = ft_itoabase((char)va_arg(*args, int), 1, 0);
	if (cr.precs)
	{
		if (cr.flag[0] != 1) // if no -
		{
			i = (cr.flag[1] == 1 ? cr.width - 1 : cr.width); //if I have space
			print_spaces(cr, i);
			while (cr.precs > ft_strlen(cr.str))
			{
				cr.str = ft_strjoin("0", cr.str);
			}
			if (cr.flag[0] == 2)
				cr.flag[0] = 0;
			ft_putnbr(cr.str);
		}
	// if (cr.width)
	// 	{
	// 		i = (cr.flag[1] == 1 ? cr.width - 1 : cr.width);
	// 		if (cr.precs > ft_strlen(cr.str))
	// 		{
	// 			print_zeros(cr);
	// 			ft_putnbr(cr.str);
	// 		}
	// 		print_spaces(cr, i);
	// 	}
	// 	//cr.flag[1] == 1 ? write(1, "+", 1) : i;
	// }
	// if (cr.precs && !cr.width)
	// {
	// 	if (cr.precs > ft_strlen(cr.str))
	// 	{
	// 		print_zeros(cr);
	// 		ft_putnbr(cr.str);
	// 	}
	// }
}
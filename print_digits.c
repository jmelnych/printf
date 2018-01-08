/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:43:07 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/08 17:37:44 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

void	print_spaces(list_spec cr, int i)
{
	while (i > (cr.precs > ft_numlen(cr.buf) ? cr.precs : ft_numlen(cr.buf)))
		{
			write(1, " ", 1);
			i--;
		}
}

void	print_zeros(list_spec cr)
{
	int i;

	i = 0;
	while (i < (cr.precs - ft_numlen(cr.buf)))
	{
		write(1, "0", 1);
		i++;
	}
}

void	print_digits(va_list *args, list_spec cr)
{
	int i;

	cr.buf = (va_arg(*args, int));
	if (cr.precs && cr.width)
	{
		if (cr.flag[0] == 0)
		{
			cr.flag[1] == 1 ? (i = cr.width - 1) : (i = cr.width);
			print_spaces(cr, i);
			if (cr.precs > ft_numlen(cr.buf))
			{
				print_zeros(cr);
			}
		}
		else
		{
			cr.flag[1] == 1 ? (i = cr.width - 1) : (i = cr.width);
			if (cr.precs > ft_numlen(cr.buf))
			{
				print_zeros(cr);
				ft_putnbr(cr.buf);
			}
			print_spaces(cr, i);
		}

		
		cr.flag[1] == 1 ? write(1, "+", 1) : i;
		ft_putnbr(cr.buf);
	}
	if (cr.precs && !cr.width)
	{
		if (cr.precs > ft_numlen(cr.buf))
		{
			i = 0;
			while (i < (cr.precs - ft_numlen(cr.buf)))
			{
				write(1, "0", 1);
				i++;
			}
			ft_putnbr(cr.buf);
		}
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:43:07 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/08 16:04:30 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

void	print_digits(va_list *args, list_spec cr)
{
	int i;

	cr.buf = (va_arg(*args, int));
	if (cr.precs && cr.width)
	{
		i = cr.width;
		while (i > (cr.precs > ft_numlen(cr.buf) ? cr.precs : ft_numlen(cr.buf)))
		{
			write(1, " ", 1);
			i--;
		}
		if (cr.precs > ft_numlen(cr.buf))
		{
			i = 0;
			while (i < (cr.precs - ft_numlen(cr.buf)))
			{
				write(1, "0", 1);
				i++;
			}
		}
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
		}
		ft_putnbr(cr.buf);
	}
}
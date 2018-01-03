/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 12:07:50 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/03 19:28:39 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printflib.h"

void	ft_putnbr(int nb)
{
	int a;
	int b;

	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			nb = nb % 1000000000;
		}
		nb = nb * (-1);
	}
	if ((nb / 10) != 0)
	{
		a = nb % 10;
		b = nb / 10;
		ft_putnbr(b);
		ft_putchar(a + '0');
	}
	if ((nb / 10) == 0)
	{
		ft_putchar(nb + '0');
	}
}

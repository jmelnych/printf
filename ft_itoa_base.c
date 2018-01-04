/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 12:22:46 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/04 16:05:40 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

static	size_t	ft_numlen(int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = n * (-1);
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa_base(int nb, int base, int sp)
{
	// int		is_negative;
	// size_t	len;
	// char	*str;

	// is_negative = 0;
	// len = ft_numlen(nb);
	// str = ft_strnew(len);
	// if (!str)
	// 	return (NULL);
	// if (base < 2 || base > 36)
	// 	return (0);
	// if (nb < 0)
	// {
	// 	nb = n * (-1);
	// 	is_negative = 1;
	// }
	// while (len--)
	// {
	// 	str[len] = nb % 10 + '0';
	// 	nb = nb / 10;
	// }
	// if (is_negative)
	// 	str[len++] = '-';
	// return (str);
}
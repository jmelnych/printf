/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:11:13 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/08 14:12:21 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

int	ft_unumlen(uintmax_t n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_numlen(intmax_t n, int c)
{
	int	len;

	if (!c)
		return (ft_unumlen(n));
	len = 1;
	if (n == -9223372036854775808)
		return (20);
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

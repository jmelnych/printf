/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 13:14:41 by vgladush          #+#    #+#             */
/*   Updated: 2018/01/09 14:36:08 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

static	char	*transbase(uintmax_t nbr, int base, int reg)
{
	int			i;
	int			tmp;
	int			ost;
	char		buf[65];

	tmp = 0;
	tmp = ((reg < 91 && reg > 64) ? 65 : 97);
	if (base < 2 && base > 36)
		return (0);
	i = 64;
	buf[i] = '\0';
	if (nbr == 0)
		return (ft_strdup("0"));
	while (nbr)
	{
		ost = nbr % base;
		nbr = nbr / base;
		i--;
		if (ost > 9)
			buf[i] = ost + tmp - 10;
		else
			buf[i] = ost + '0';
	}
	return (ft_strdup(buf + i));
}

static	char	*sigitoa(intmax_t c, char *res, int i)
{
	i = ft_numlen(c, 1);
	if (c < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if (!(res = (char *)malloc(i + 1)))
		return (0);
	res[i] = '\0';
	if (c < 0 && (c = -c))
	{
		res[0] = '-';
		while (i-- > 1)
		{
			res[i] = c % 10 + 48;
			c /= 10;
		}
	}
	else
	{
		while (i--)
		{
			res[i] = c % 10 + 48;
			c /= 10;
		}
	}
	return (res);
}

char			*ft_itoabase(uintmax_t c, int sys, int rg)
{
	int			i;
	char		*res;

	res = NULL;
	if (sys == 1)
		return (sigitoa(c, res, 0));
	else if (sys)
		return (transbase(c, sys, rg));
	i = ft_numlen(c, 0);
	if (!(res = (char *)malloc(i + 1)))
		return (0);
	res[i] = '\0';
	while (i--)
	{
		res[i] = c % 10 + 48;
		c /= 10;
	}
	return (res);
}

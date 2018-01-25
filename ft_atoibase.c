/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 16:07:53 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/25 17:00:39 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

int	ft_atoibase(char *str)
{
	printf("StR === %s\n", str);
	int i;
	int res;
	int j;

	j = 1;
	res = 0;
	i = ft_strlen(str);
	while (--i >= 0)
	{
		res += j * (str[i] - '0');
		j *= 2;
		printf("res === %d\n", res);
	}
	return (res);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_precs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 19:20:49 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/05 17:01:39 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

void	fill_precs(const char *fmt, list_spec *current)
{
	int i;

	i = 0;
	current->precs = 0;
	while (fmt[i] != '\0' && !check_type(fmt[i]))
	{
		if (fmt[i] == '.' && ft_isdigit(fmt[i + 1]))
		{
			current->precs = ft_atoi(fmt + i + 1);
			break;
		}
		i++; 
	}
}

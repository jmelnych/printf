/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 19:02:53 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/05 15:58:12 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

void fill_width(const char *fmt, list_spec *current)
{
	int i;

	i = 0;
	while (fmt[i] != '\0' && !check_type(fmt[i]))
	{
		if(fmt[i] > '0' && fmt[i] < '9')
			break;
		i++;
	}
		current->width = ft_atoi(fmt + i);
}
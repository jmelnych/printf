/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:42:39 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/05 16:09:18 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

int	save_spec(const char *fmt)
{
	list_spec current;

	fill_align(fmt, &current);
	// int i;

	// i = 0;
	// while (fmt[i] != '%' && fmt[i] != '\0')
	// {
		
	// 	i++;
	// }
	//check for "*"
	fill_width(fmt, &current);
	fill_precs(fmt, &current);
	return (0);
}
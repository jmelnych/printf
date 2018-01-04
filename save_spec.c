/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:42:39 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/04 19:30:35 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

int	save_spec(const char *fmt)
{
	list_spec current;
	int i;

	i = 0;
	while (fmt[i] != '%' && fmt[i] != '\0')
	{
		current = fill_align(fmt[i], current);
		i++;
	}
	if (current.flag[0] || current.flag[1] || current.flag[2] || current.flag[3])
		fmt++;
	//check for "*"
	current = fill_width(fmt, current);

	return (0);
}
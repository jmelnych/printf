/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:04:47 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/22 19:07:57 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

void	print_str(va_list *args, list_spec cr)
{
	char *buff;

	cr.str = va_arg(*args, char*);
	if (cr.precs != -1)
	{
		if (cr.precs < (int)ft_strlen(cr.str))
		{
			buff = ft_strdup(cr.str);
			buff[cr.precs] = '\0';
		}
		else
			buff = ft_strdup(cr.str);
	}
	if (cr.width)
	{
		
	}
	write(1, buff, ft_strlen(buff));
	free(buff);
}

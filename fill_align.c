/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_align.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 17:45:44 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/04 19:03:12 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

list_spec fill_align(char fmt, list_spec current)
{
	current.flag[0] = 0;
	current.flag[1] = 0;
	current.flag[2] = 0;
	current.flag[3] = 0;
	if (fmt == '-')
		current.flag[0] = 1;
	else if (fmt == '0')
		current.flag[3] = 1;
	if (fmt == '+')
		current.flag[1] = 1;
	else if (fmt == ' ')
		current.flag[2] = 1;
	return (current);
}
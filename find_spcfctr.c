/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_spcfctr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 17:08:25 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/03 20:51:29 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

int find_spcfctr(char c)
{
	if (c == 'd')
		return (1);
	if (c == 's')
		return (2);
	if (c == 'z')
		return (30);
	if (c == 'u')
		return (3);
	if (c == 'c')
		return (4);
	if (c == 'f')
		return (5);
	return (0);
}
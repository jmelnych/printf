/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:04:47 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/08 16:44:43 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

void	print_str(va_list *args, list_spec cr)
{
	cr.str = va_arg(*args, char*);
	write(1, cr.str, ft_strlen(cr.str));
}

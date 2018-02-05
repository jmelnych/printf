/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:18:53 by imelnych          #+#    #+#             */
/*   Updated: 2018/02/04 20:34:34 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

void		print_address(va_list *args, list_spec *cr)
{
	if (cr->mod == 4)
		cr->str = ft_itoabase(va_arg(*args, uintmax_t), 16, 'a');
	else if (cr->mod == 3)
		cr->str = ft_itoabase(va_arg(*args, unsigned long), 16, 'a');
	else if (cr->mod == 0)
		cr->str = ft_itoabase(va_arg(*args, unsigned int), 16, 'a');
	else if (cr->mod == 2)
		cr->str = ft_itoabase((unsigned short)va_arg(*args, int), 16, 'a');
	else if (cr->mod == 1)
		cr->str = ft_itoabase((unsigned char)va_arg(*args, int), 16, 'a');
	//cr->str = ft_strjoin_free("7ffe", cr->str, 2);
	if (cr->precs != -1)
	{
		if (cr->flag[0] == 2)
			cr->flag[0] = 0;
		while (cr->precs > (int)ft_strlen(cr->str))
			cr->str = ft_strjoin_free("0", cr->str, 2);
	}
	while (cr->flag[0] == 2 && cr->width - 2 > (int)ft_strlen(cr->str))
		cr->str = ft_strjoin_free("0", cr->str, 2);
	cr->str = ft_strjoin_free("0x", cr->str, 2);
	while (cr->width > (int)ft_strlen(cr->str))
		cr->str = ft_strjoin_free(" ", cr->str, 2);
	cr->count += write(1, cr->str, ft_strlen(cr->str));
}

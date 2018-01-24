/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:18:53 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/24 19:53:53 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

void		print_address(va_list *args, list_spec cr)
{
	if (cr.mod == 4)
		cr.str = ft_itoabase(va_arg(*args, uintmax_t), 16, 'a');
	else if (cr.mod == 3)
		cr.str = ft_itoabase(va_arg(*args, unsigned long), 16, 'a');
	else if (cr.mod == 0)
		cr.str = ft_itoabase(va_arg(*args, unsigned int), 16, 'a');
	else if (cr.mod == 2)
		cr.str = ft_itoabase((unsigned short)va_arg(*args, int), 16, 'a');
	else if (cr.mod == 1)
		cr.str = ft_itoabase((unsigned char)va_arg(*args, int), 16, 'a');
	if (cr.precs != -1) //if I have precision 
	{
		if (cr.flag[0] == 2)
			cr.flag[0] = 0; //switch off 0 flag if we have presc.
		while (cr.precs > (int)ft_strlen(cr.str))
			cr.str = ft_strjoin_free("0", cr.str, 2); // 2 str need free
	}
	while (cr.flag[0] == 2 && cr.width - 2 > (int)ft_strlen(cr.str))
		cr.str = ft_strjoin_free("0", cr.str, 2);
	cr.str = ft_strjoin_free("0x", cr.str, 2);
	while (cr.width > (int)ft_strlen(cr.str))
		cr.str = ft_strjoin_free(" ", cr.str, 2);
	write(1, cr.str, ft_strlen(cr.str));
}

//1. arg 16 0xfff...
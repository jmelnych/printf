/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:42:39 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/24 20:17:07 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

list_spec	save_spec(const char **fmt)
{
	list_spec cr;

	fill_align(*fmt, &cr);
	fill_width_precs(*fmt, &cr);
	fill_mod(*fmt, &cr);
	fill_type(fmt, &cr);
	//printf(" %d\t, %d\t, %d\t, %c\n", cr.width, cr.precs, cr.mod, cr.type);
	return (cr);
}


int main_call(const char **fmt, va_list *args)
{
	list_spec cr;

	cr = save_spec(fmt);
	if (cr.type == 'd' || cr.type == 'i' || cr.type == 'D')
		print_digits(args, cr);
	if (cr.type == 'u' || cr.type == 'U' || cr.type == 'o' || cr.type == 'O'
		|| cr.type == 'X' || cr.type == 'b' || cr.type == 'x')
		print_digits_unsigned(args, cr, (int)cr.type);
	if (cr.type == 'p')
		print_address(args, cr);
	if (cr.type == 's')
		print_str(args, cr);
	if (cr.type == 'c')
		print_c(args, cr);
	return (0);
}

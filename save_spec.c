/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:42:39 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/29 18:29:27 by imelnych         ###   ########.fr       */
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
	return (cr);
}

int			main_call(const char **fmt, va_list *args)
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
	if (cr.type == 'c' || cr.type == '%')
		print_c(args, cr);
	if (cr.type == 'S' || cr.type == 'C')
		print_unicode(args, cr);
	if (cr.type == '%')

	return (0);
}

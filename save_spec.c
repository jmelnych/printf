/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:42:39 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/30 14:39:38 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

static void		save_spec(const char **fmt, va_list *args, list_spec *cr)
{
	fill_align(*fmt, cr);
	fill_width(*fmt, cr, args);
	fill_mod(*fmt, cr);
	fill_type(fmt, cr);
}

void			main_call(const char **fmt, va_list *args, list_spec *cr)
{
	save_spec(fmt, args, cr);
	if (cr->type == 'd' || cr->type == 'i' || cr->type == 'D')
		print_digits(args, cr);
	if (cr->type == 'u' || cr->type == 'U' || cr->type == 'o' || cr->type == 'O'
		|| cr->type == 'X' || cr->type == 'b' || cr->type == 'x')
		print_digits_unsigned(args, cr, (int)cr->type);
	if (cr->type == 'p')
		print_address(args, cr);
	if (cr->type == 's')
		print_str(args, cr);
	if (cr->type == 'c' || cr->type == '%')
		print_c(args, cr);
	if (cr->type == 'S' || cr->type == 'C')
		print_unicode(args, cr);
}

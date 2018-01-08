/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 17:42:39 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/08 16:45:13 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

list_spec	save_spec(const char **fmt)
{
	list_spec cr;

	fill_align(*fmt, &cr);
	fill_width(*fmt, &cr);
	fill_precs(*fmt, &cr);
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
	if (cr.type == 's')
		print_str(args, cr);
	return (0);
}
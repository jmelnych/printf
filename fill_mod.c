/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:59:05 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/05 17:13:53 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

void	fill_mod(const char *fmt, list_spec *current)
{
	int i;

	i = 0;
	current->mod = 0;
	while (fmt[i] != '\0' && !check_type(fmt[i]))
	{
		if ((fmt[i] == 'l' && fmt[i + 1] == 'l') || fmt[i] == 'j' || fmt[i] == 'z')
			current->mod = 4;
		else if ((fmt[i] == 'l' && fmt[i + 1] != 'l') && current->mod < 4)
			current->mod = 3;
		else if ((fmt[i] == 'h' && fmt[i + 1] != 'h') && current->mod < 3)
			current->mod = 2;
		else if ((fmt[i] == 'h' && fmt[i + 1] == 'h') && current->mod < 2 && (++i))
			current->mod = 1;
		i++;
	}
}

// #define FLGLEN(x) x == 'h' || x == 'l' || x == 'j' || x == 'z' || (x > 47 && x < 58)
// #define FLGLE2(x) x == 'h' || x == 'l' || x == 'j' || x == 'z' || (x > 47 && x < 58)
// 		 || x == 

// while (FLG(s[i]) )
// {
// 	if ((s[i] == 'l' && s[i + 1] == 'l') || s[i] == 'j' || s[i] == 'z')
// 		list_spec->len = 4;
// 	else if ((s[i] == 'l' && s[i + 1] != 'l') && list_spec->len < 4)
// 		list_spec->len = 3;
// 	else if ((s[i] == 'h' && s[i + 1] != 'h') && list_spec->len < 3)
// 		list_spec->len = 2;
// 	else if ((s[i] == 'h' && s[i + 1] == 'h') && list_spec->len < 2 && (++i))
// 		list_spec->len = 1;
// 	i++;
// }
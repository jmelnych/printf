/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 15:43:07 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/22 17:46:04 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

void	print_digits(va_list *args, list_spec cr)
{
	int i;
	char c[2];

	c[0] = '0';
	c[1] = '\0';
	i = 0;
	if (cr.mod == 4)
		cr.str = ft_itoabase(va_arg(*args, intmax_t), 1, 0);
	else if (cr.mod == 3 || cr.type == 'D')
		cr.str = ft_itoabase(va_arg(*args, long), 1, 0);
	else if (cr.mod == 0)
		cr.str = ft_itoabase(va_arg(*args, int), 1, 0);
	else if (cr.mod == 2)
		cr.str = ft_itoabase((short)va_arg(*args, int), 1, 0);
	else if (cr.mod == 1)
		cr.str = ft_itoabase((char)va_arg(*args, int), 1, 0);
	if (cr.precs != -1) //if I have precision 
	{
		if (cr.flag[0] == 2)
			cr.flag[0] = 0; //switch off 0 flag if we have presc.
		if (*cr.str == '-')
		{
			*cr.str = '0';
			while (cr.precs > (int)ft_strlen(cr.str))
				cr.str = ft_strjoin("0", cr.str); // 2 str need free
			cr.str = ft_strjoin("-", cr.str);
		}
		else
		{
			while (cr.precs > (int)ft_strlen(cr.str))
				cr.str = ft_strjoin("0", cr.str); // 2 str need free
		}
	}
	if (cr.flag[1] == 1 && *cr.str != '-')
		cr.str = ft_strjoin("+", cr.str);
	if (cr.flag[1] == 2 && *cr.str != '-')
		cr.str = ft_strjoin(" ", cr.str);
	if (cr.width)
	{
		while (cr.flag[0] == 1 && cr.width > (int)ft_strlen(cr.str))
			cr.str = ft_strjoin(cr.str, " ");
		while (cr.flag[0] != 2 && cr.width > (int)ft_strlen(cr.str))
			cr.str = ft_strjoin(" ", cr.str);
		if (cr.flag[0] == 2)
		{
			if ((*cr.str == ' ' || *cr.str == '-' || *cr.str == '+')
				&& cr.width > (int)ft_strlen(cr.str))
			{
				i = 1;
				c[0] = *cr.str;
				*cr.str = '0';
			}
			while (cr.width > (int)ft_strlen(cr.str) + i)
				cr.str = ft_strjoin("0", cr.str);
			if (cr.width > (int)ft_strlen(cr.str))
				cr.str = ft_strjoin(c, cr.str);
		}
	}
	write(1, cr.str, ft_strlen(cr.str));
}

void	print_digits_unsigned(va_list *args, list_spec cr, int type)
{
	int system;
	char c[3];

	c[0] = '0';
	c[1] = (char)type;
	c[2] = '\0';
	system = 0;
	if (type == 'o' || type == 'O')
		system = 8;
	else if (type == 'x' || type == 'X')
		system = 16;
	else if (type == 'b')
		system = 2;
	if (cr.mod == 4)
		cr.str = ft_itoabase(va_arg(*args, uintmax_t), system, type);
	else if (cr.mod == 3 || type == 'O' || type == 'U')
		cr.str = ft_itoabase(va_arg(*args, unsigned long), system, type);
	else if (cr.mod == 0)
		cr.str = ft_itoabase(va_arg(*args, unsigned int), system, type);
	else if (cr.mod == 2)
		cr.str = ft_itoabase((unsigned short)va_arg(*args, int), system, type);
	else if (cr.mod == 1)
		cr.str = ft_itoabase((unsigned char)va_arg(*args, int), system, type);
	if (cr.precs != -1) //if I have precision 
	{
		if (cr.flag[0] == 2)
			cr.flag[0] = 0; //switch off 0 flag if we have presc.
		while (cr.precs > (int)ft_strlen(cr.str))
			cr.str = ft_strjoin("0", cr.str); // 2 str need free
	}
	if (cr.flag[2] == 1 && (type == 'x' || type == 'X'))
		cr.width -= 2;
	while (cr.flag[0] == 2 && cr.width > (int)ft_strlen(cr.str))
		cr.str = ft_strjoin("0", cr.str);
	if (cr.flag[2] == 1 && (type == 'o' || type == 'O') && *cr.str != '0')
		cr.str = ft_strjoin("0", cr.str);
	while (cr.flag[0] == 1 && cr.width > (int)ft_strlen(cr.str))
		cr.str = ft_strjoin(cr.str, " ");
	if (cr.flag[2] == 1 && (type == 'x' || type == 'X'))
		cr.str = ft_strjoin(c, cr.str);
	while (cr.flag[0] != 2 && cr.width + 2 > (int)ft_strlen(cr.str))
		cr.str = ft_strjoin(" ", cr.str);
	write(1, cr.str, ft_strlen(cr.str));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 08:50:58 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/08 15:38:51 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

void	fill_align(const char *fmt, list_spec *cr)
{
	int i;
	
	i = 0;
	//printf("OUR FMT: %s\n, -1 === %c", fmt, fmt[i-1]);
	while (i < FL)
		cr->flag[i++] = 0;
	i = 0;
	while (fmt[i] != '\0' && !check_type(fmt[i]))
	{
		if (fmt[i] == '-')
			cr->flag[0] = 1;
		else if (fmt[i] == '0' && !ft_isdigit(fmt[i - 1]) && !cr->flag[0])
			cr->flag[0] = 2;
		if (fmt[i] == '+')
			cr->flag[1] = 1;
		else if (fmt[i] == ' ' && !cr->flag[1])
			cr->flag[1] = 2;
		if (fmt[i] == '#')
			cr->flag[2] = 1;
		i++;
	}
}

void	fill_width_precs(const char *fmt, list_spec *cr)
{
	int i;

	i = 0;
	cr->width = 0;
	cr->precs = -1;
	while (fmt[i] != '\0' && !check_type(fmt[i]))
	{
		if(ft_isdigit(fmt[i]))
		{
			cr->width = ft_atoi(fmt + i);
			while (ft_isdigit(fmt[i]))
				i++;
		}
		else if (fmt[i] == '.')
		{
			i++;
			cr->precs = 0;
			if (ft_isdigit(fmt[i]))
				cr->precs = ft_atoi(fmt + i);
			while (ft_isdigit(fmt[i]))
				i++;
		}
		else
			i++;
	}
}

// void	fill_precs(const char *fmt, list_spec *cr)
// {
// 	int i;

// 	i = 0;
// 	cr->precs = 0;
// 	while (fmt[i] != '\0' && !check_type(fmt[i]))
// 	{
// 		if (fmt[i] == '.' && ft_isdigit(fmt[i + 1]))
// 		{
// 			cr->precs = ft_atoi(fmt + i + 1);
// 			break;
// 		}
// 		i++; 
// 	}
// }

void	fill_mod(const char *fmt, list_spec *cr)
{
	int i;

	i = 0;
	cr->mod = 0;
	while (fmt[i] != '\0' && !check_type(fmt[i]))
	{
		if ((fmt[i] == 'l' && fmt[i + 1] == 'l') || fmt[i] == 'j' || fmt[i] == 'z')
			cr->mod = 4;
		else if ((fmt[i] == 'l' && fmt[i + 1] != 'l') && cr->mod < 4)
			cr->mod = 3;
		else if ((fmt[i] == 'h' && fmt[i + 1] != 'h') && cr->mod < 3)
			cr->mod = 2;
		else if ((fmt[i] == 'h' && fmt[i + 1] == 'h') && cr->mod < 2 && (++i))
			cr->mod = 1;
		i++;
	}
}

void	fill_type(const char **fmt, list_spec *cr)
{
	int i;

	i = 0;
	cr->type = 0;
	while (**fmt != '\0')
	{
		if(check_type(**fmt))
		{
			cr->type = **fmt;
			break ;
		}
		(*fmt)++;
	}
}

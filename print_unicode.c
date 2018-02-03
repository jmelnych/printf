/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:12:00 by imelnych          #+#    #+#             */
/*   Updated: 2018/02/03 15:47:16 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

static char		*print_unistr(va_list *args, list_spec *cr)
{
	wchar_t	*s;
	char	*res;
	char	*tmp;

	if (!(res = ft_strnew(1)))
		return (0);
	s = va_arg(*args, wchar_t *);
	while (*s)
	{
		tmp = print_unichar((int)*s++);
		if (cr->precs == -1 ||
			cr->precs >= (int)ft_strlen(res) + (int)ft_strlen(tmp))
			res = ft_strjoin_free(res, tmp, 3);
		else
			break ;
	}
	return (res);
}

void			print_unicode(va_list *args, list_spec *cr)
{
	int		sb;

	if (cr->type == 'C')
	{
		if(!(sb = va_arg(*args, int)))
		{
			// printf("%s\n", "bsflsjfsfsjsjfsfj");
			// cr->str = ft_strnew(1);
			// cr->str[0] = sb;
			cr->count += write(1, "", 1);

		}
		cr->str = print_unichar(sb);
		//printf("RES ===%s\n", cr->str);
	}
	if (cr->type == 'S')
		cr->str = print_unistr(args, cr);
	while (cr->flag[0] == 2 && cr->width > (int)ft_strlen(cr->str))
		cr->str = ft_strjoin_free("0", cr->str, 2);
	while (cr->flag[0] == 1 && cr->width > (int)ft_strlen(cr->str))
		cr->str = ft_strjoin_free(cr->str, " ", 1);
	while (!cr->flag[0] && cr->width > (int)ft_strlen(cr->str))
		cr->str = ft_strjoin_free(" ", cr->str, 2);
	cr->count += write(1, cr->str, ft_strlen(cr->str));
	free(cr->str);
}

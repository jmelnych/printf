/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:12:00 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/26 17:44:13 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
0xxxxxxx
110xxxxx 10xxxxxx
1110xxxx 10xxxxxx 10xxxxxx
11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
**/

#include "printflib.h"

char	*print_unichar(int symb)
{
	//wchar_t symb;
	char *str;
	char *mask;
	int bit;
	int i;
	char *first_mask;
	int len;
	int j;
	char *res;
	int k;

	bit = 0;
	i = 0;
	first_mask = ft_strdup("00000000");
	str = ft_itoabase(symb, 2, 'b'); //1110 110001
	len = (int)ft_strlen(str);
	if (len > 16)
		bit = 4;
	else if (len > 11)
		bit = 3;
	else if (len > 7)
		bit = 2;
	if (!(res = ft_strnew(bit)))
		return (0);
	k = bit - 1;
	while (i < bit)
		first_mask[i++] = '1'; //11000000
	while (bit-- > 1)
	{
		mask = ft_strdup("10000000");
		j = 8;
		while (j-- > 2 && len >= 0)
			mask[j] = str[--len]; // 10110001
		res[k--] = (char)ft_atoibase(mask);
		free(mask);
	}
	j = 8;
	while (len--)
		first_mask[--j] = str[len];
	res[k] = (char)ft_atoibase(first_mask);
	return (res);
}


char	*print_unistr(va_list *args, list_spec cr)
{
	wchar_t *s;
	char	*res;
	char	*tmp;

	if (!(res = ft_strnew(1)))
		return (0);
	s = va_arg(*args, wchar_t *);
	while (*s)
	{
		tmp = print_unichar((int)*s++);
		if (cr.precs == -1 || cr.precs >= (int)ft_strlen(res) + (int)ft_strlen(tmp))
			res = ft_strjoin_free(res, tmp, 3);
		else
			break ;
	}
	return (res);
}

void	print_unicode(va_list *args, list_spec cr)
{
	int		sb;

	if (cr.type == 'C')
	{
		sb = va_arg(*args, int);
		cr.str = print_unichar(sb);
	}
	if (cr.type == 'S')
		cr.str = print_unistr(args, cr);
	while (cr.flag[0] == 2 && cr.width > (int)ft_strlen(cr.str))
		cr.str = ft_strjoin_free("0", cr.str, 2);
	while (cr.flag[0] == 1 && cr.width > (int)ft_strlen(cr.str))
		cr.str = ft_strjoin_free(cr.str, " ", 1);
	while (!cr.flag[0] && cr.width > (int)ft_strlen(cr.str))
		cr.str = ft_strjoin_free(" ", cr.str, 2);
	write(1, cr.str, ft_strlen(cr.str));
	free(cr.str);
}











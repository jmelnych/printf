/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 12:12:00 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/25 19:09:35 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
0xxxxxxx
110xxxxx 10xxxxxx
1110xxxx 10xxxxxx 10xxxxxx
11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
**/

#include "printflib.h"

char	*print_unichar(va_list *args)
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
	int symb = va_arg(*args, int);
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
	printf("LEN === %d\n", len);
	while (len--)
		first_mask[--j] = str[len];
	res[k] = (char)ft_atoibase(first_mask);
	printf("F Maks == %s\n", first_mask);
	printf("res ---> %s\n", res );
	return (res);
}


char	*print_unistr(va_list *args)
{
	
}

void	print_unicode(va_list *args, list_spec cr)
{
	char	*res;

	res = 0;
	if (cr.type == 'C')
		res = print_unichar(args);
	if (cr.type == 'S')
		res = print_unistr(args);
	printf("RES === %s\n", res);
}











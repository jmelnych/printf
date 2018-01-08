/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:11:19 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/08 16:24:41 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_change(char **c)
{
	**(c++) = 'd';
	**c = 'y';
	printf("%s\n", *c);
}

int main()
{
	char str;

 str = malloc(4);
 str = "abc\0"

	ft_change(&str);
	printf("%s\n", str);
	return 0;
}
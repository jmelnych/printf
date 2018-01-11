/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 13:45:41 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/11 14:15:08 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t i;
	size_t len1;

	i = 0;
	len1 = ft_strlen(s1);
	while (s2[i] != '\0')
	{
		s1[len1] = s2[i];
		len1++;
		i++;
	}
	s1[len1] = '\0';
	return (s1);
}

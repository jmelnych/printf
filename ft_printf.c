/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 13:20:40 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/04 12:26:46 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

int ft_printf(const char *fmt, ...)
{
	va_list args;
	int i;
	int alflag;
	int spec;
	int width;
	char *str;
	char c;

	c = 0;
	i = 0;
	alflag = 0;
	spec = 0;
	width = 0;
	str = 0;
	va_start(args, fmt); //to where, what-last param
	while (*fmt)
	{
		if (*fmt == '%')
		{
		 	fmt++;
		 	alflag = align(*fmt);
		 	if (alflag)
		 		fmt++;
		 	spec = find_spcfctr(*fmt);
		 	if (spec == 30)
		 	{
		 		fmt++;
		 		spec = find_spcfctr(*fmt);
		 	}
		 	if (spec == 2)
		 	{
			 	str = va_arg(args, char*);
				write(1, str, ft_strlen(str));
		 	}
		 	if (spec == 1 || spec == 3)
		 		ft_putnbr(va_arg(args, int));
		 	if (spec == 4)
		 	{
		 		c = va_arg(args, int);
		 		write(1, &c, 1);
		 	}
		 	//if (spec == 5)
		 		//handling float
		}
		else
			write(1, fmt, 1);
		fmt++;
	}
	va_end(args); 
	return (i);
}


int main(void)
{
	ft_printf("one === %d one.half === %c two === %s\n", -89123, 'a', "qwerty");
	printf("one === %f one.half === %c two === %s\n", 8.9123, 'a', "qwerty");

	
	return (0);
}

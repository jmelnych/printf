/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 13:20:40 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/05 16:55:12 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

int ft_printf(const char *fmt, ...)
{
	va_list args;

	//char *str;
	//char c;

	//c = 0;
	//str = 0;
	va_start(args, fmt); //to where, what-last param
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1) != '%')
		{
		 	fmt++;
		 	save_spec(fmt);
		 		// if (*fmt == 's')
			 	// {
				 // 	str = va_arg(args, char*);
					// write(1, str, ft_strlen(str));
			 	// }
			 	// if (*fmt == 'd')
			 	// 	ft_putnbr(va_arg(args, int));//change to ft_itoa_base?
			 	// if (*fmt == 'c')
			 	// {
			 	// 	c = va_arg(args, int);
			 	// 	write(1, &c, 1);
			 	// }
		}
		else
			write(1, fmt, 1);
		fmt++;
	}
	va_end(args); 
	return (1);
}


int main(void)
{
	//write(1, "α\n", 3);
	ft_printf("one === %#05.3d two === %s\n",  529, "abc");
	//printf("one === %s\n", "qwerty");

	
	return (0);
}

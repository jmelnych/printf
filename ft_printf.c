/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 13:20:40 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/22 19:07:31 by imelnych         ###   ########.fr       */
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
		if (*fmt == '%' && *(fmt + 1) != '%' && *(fmt + 1) != '\0')
		{
		 	fmt++;
		 	main_call(&fmt, &args);
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
	//printf("one === %-+11.5d two === %s\n", 529, "abc"); //+00529____
	//write(1, "α\n", 3);
	printf("ORIGIN: %020.4s\n", "hello world");
	ft_printf("MY FNC: %20.4s\n", "hello world"); // +522
	printf("ORIGIN: % +U\n", -222221111522);
	ft_printf("MY FNC: % +U\n", -222221111522);
	//printf("ORIGIN: %0# 15.10X\n", -522);
	//ft_printf("MY FNC: %0 #15.10X\n", -522); // -522
	// ft_printf("MINE\tone === %12.3d two === %s\n", 521, "abc");
	// printf("ORIG\tone === %12.3d two === %s\n", 521, "abc");
	//printf("one === %s\n", "qwerty");	
	return (0);
}


//str_join free
//

//sS

//cC



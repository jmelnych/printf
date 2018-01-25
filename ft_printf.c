/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 13:20:40 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/25 14:06:23 by imelnych         ###   ########.fr       */
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
	setlocale(LC_ALL, "en_US.UTF-8");
	//printf("%d\n", L'ȱ');
	//printf("one === %-+11.5d two === %s\n", 529, "abc"); //+00529____
	//write(1, "α\n", 3);
	//printf("ORIGIN PF: %5.8S\n", L"α\n");

	printf("ORIGIN: %.7C\n", L'α');
	ft_printf("MY FNC: %.7C\n", L'α'); // +522
	//printf("ORIGIN PF: % +U\n", -222221111522);
	//ft_printf("MY FNC: % +U\n", -222221111522);
	//printf("ORIGIN PF: %0# 15.10X\n", -522);
	//ft_printf("MY FNC: %0 #15.10X\n", -522); // -522
	return (0);
}


//S
//C



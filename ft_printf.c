/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 13:20:40 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/29 18:32:37 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

int	ft_printf(const char *fmt, ...)
{
	va_list args;

	va_start(args, fmt); //to where, what-last param
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1) != '%' && *(fmt + 1) != '\0')
		{
		 	fmt++;
		 	main_call(&fmt, &args);
		}
		else if (*fmt == '%' && *(fmt + 1) == '%')
		{
			write(1, fmt, 1);
			fmt++;
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
	//printf("ORIGIN: %09.8S\n", L"αȱ");
	//ft_printf("MY FNC: %09.8S\n", L"αȱ");
	//printf("ORIGIN: %.7C\n", L'α');
	// printf("ORIGIN: % 9s\n", "blabla");
	// ft_printf("MY FNC: % 9s\n", "blabla");
	// printf("ORIGIN: % 9c\n", 'a');
	// ft_printf("MY FNC: % 9c\n", 'a');
	// printf("ORIGIN: %05.3S\n", L"αȱ");
	// ft_printf("MY FNC: %05.3S\n", L"αȱ"); // +522
	//printf("ORIGIN: % +U\n", -222221111522);
	//ft_printf("MY FNC: % +U\n", -222221111522);
	//printf("ORIGIN: %0# 15.10X\n", -522);
	//ft_printf("MY FNC: %0 #15.10X\n", -522); // -522
	// printf("ORIGIN: %.3d\n", -2222211);
	// ft_printf("MY FNC: %.3d\n", -2222211);
	//ft_printf("MY FNC: %.*d\n", -2222211.5);

	printf("ORIGIN: %0*d\n", -8, -211);

	// printf("ORIGIN: %05%\n");
	// ft_printf("MY FNC: %05%\n");
	return (0);
}

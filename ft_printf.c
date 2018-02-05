/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 13:20:40 by imelnych          #+#    #+#             */
/*   Updated: 2018/02/04 20:30:12 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printflib.h"

int	ft_printf(const char *fmt, ...)
{
	va_list args;
	list_spec cr;

	cr.count = 0;
	va_start(args, fmt); //to where, what-last param
	while (*fmt)
	{
		if (*fmt == '%')
		{
		 	fmt++;
		 	if(!(main_call(&fmt, &args, &cr)))
		 		break ;
		}
		else
			cr.count += write(1, fmt, 1);
		fmt++;
	}
	va_end(args);
	return (cr.count);
}

// int main(void)
// {
// 	char *strlen;

// 	strlen = 0;
// 	int i;

// 	//i = 0;
// 	setlocale(LC_ALL, "en_US.UTF-8");
// 	//printf("%d\n", L'ȱ');
// 	//printf("one === %-+11.5d two === %s\n", 529, "abc"); //+00529____
// 	//printf("ORIGIN: %09.8S\n", L"αȱ");
// 	//ft_printf("MY FNC: %09.8S\n", L"αȱ");
// 	//printf("ORIGIN: %.7C\n", L'α');
// 	// printf("ORIGIN: % 9s\n", "blabla");
// 	// ft_printf("MY FNC: % 9s\n", "blabla");
// 	// printf("ORIGIN: % 9c\n", 'a');
// 	// ft_printf("MY FNC: % 9c\n", 'a');
// 	// printf("ORIGIN: %05.3S\n", L"αȱ");
// 	// ft_printf("MY FNC: %05.3S\n", L"αȱ"); // +522
// 	// printf("ORIGIN: % +U\n", -222221111522);
// 	// ft_printf("MY FNC: % +U\n", -222221111522);
// 	//printf("ORIGIN: %0# 15.10X\n", -522);
// 	//ft_printf("MY FNC: %0 #15.10X\n", -522); // -522
// 	// printf("ORIGIN: %.3d\n", -2222211);
// 	// ft_printf("MY FNC: %.3d\n", -2222211);
// 	//ft_printf("MY FNC: %.*d\n", -2222211.5);
// 	//printf("coun or = %d\n", printf("ORIGIN: %.**d\n", 5, 8, -211));
// 	//printf("coun my = %d", ft_printf("MY FNC: %.**d\n", 5, 8, -211));
// 	//printf("coun or = %d\n", printf("ORIGIN: %.xd\n", -211));
// 	//printf("coun my = %d\n", ft_printf("MY FNC: %.xd\n", -211));
// 	//printf("coun or = %d\n", printf("ORIGIN: %s\n", "jfjsfsfjs"));
// 	//printf("coun my = %d\n", ft_printf("MY FNC: %s\n", "jfjsfsfjs"));
// 	//printf("coun or = %d\n", printf("ORIGIN: %05.3S\n", L"αȱ"));
// 	//printf("coun my = %d\n", ft_printf("MY FNC: %05.3S\n", L"αȱ"));
// 	printf("\tcount org = %d\n",    printf("ORIGIN: %p", &i));
// 	printf("\tcount myf = %d\n", ft_printf("MY FNC: %p", &i));
// 	// printf("ORIGIN: %05%\n");
// 	// ft_printf("MY FNC: %05%\n");
// 	return (0);
// }

// nbr == 3785996732
// ost == 3785996732 % 16 = 12
// nbr = 236624795
// i = 63
// //
// ost = 11
// nbr = 14789049
// i = 62
// //
// ost = 9
// nbr = 14789049 / 16 = 924315
// i = 61
//

// ost = 924315 % 16 = 11
//nbr = 57769
//i = 60

//


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 13:20:40 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/02 19:02:41 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int find_spcfctr(char c)
{
	if (c == 's')
		return (1);
	return (0);
}

int ft_printf(const char *fmt, ...)
{
	va_list args;
	int i;

	i = 0;

	va_start(args, fmt); //where, what-last param
	while (*fmt != 0)
	{
		if (fmt[i] == '%')
		{
		 	i++;
		 	find_spcfctr(fmt[i]);
		 	//if (find_spcfctr == 1)
		 	i++;

		}
		else
			write(1, fmt, 1);	
		fmt++;
		//i += write(1, va_arg(args, int), 6);
	}
	va_end(args); 
	return (i);
}


int main(void)
{
	ft_printf("one === %s two === %s", "first", "secod\n");
	return (0);
}

// int ft_printf(int num, ...)
// {
// 	va_list arg;
// 	int count;

// 	count = 0;
// 	va_start(arg, num);
// 	va_end(arg);
// 	while(count < num)
// 	{
// 		printf("%d\n",va_arg(arg, int));
// 		count++;
// 	}
// 	return (1);
// }

// int main(void)
// {
// 	ft_printf(5, 0, 1, 3, 6, 2);
// 	return (0);
// }
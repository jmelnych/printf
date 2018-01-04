/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 16:40:26 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/04 19:09:46 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <string.h>
# include <unistd.h>
# include <stdio.h> //delme!!
# include <stdarg.h>
# include <stdlib.h>

typedef	struct
{
	char	flag[5];
	int		width;
	int		precs;
	int		len;
	char	type;
}			list_spec;

void		ft_bzero(void *s, size_t n);
int			ft_atoi(const char *str);
void		ft_putchar(char c);
size_t		ft_strlen(const char *str);
char		*ft_strnew(size_t size);
void		ft_putnbr(int nb); //delme?!!

int			ft_printf(const char *fmt, ...);
int			save_spec(const char *fmt);
char		*ft_itoa_base(int nb, int base);
list_spec	fill_align(char fmt, list_spec current);
list_spec 	fill_width(const char *fmt, list_spec current);


#endif
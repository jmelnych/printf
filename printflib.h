/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelnych <imelnych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 16:40:26 by imelnych          #+#    #+#             */
/*   Updated: 2018/01/11 14:15:19 by imelnych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <string.h>
# include <unistd.h>
# include <stdio.h> //delme!!
# include <stdarg.h>
# include <stdlib.h>
# define FL 3
# define TP "sSpdDioOuUxXcC" //

typedef	struct
{
	int		flag[FL];
	int		width;
	int		precs;
	int		mod;
	char	type;
	char	*str;
}			list_spec;

void		ft_bzero(void *s, size_t n);
int			ft_atoi(const char *str);
void		ft_putchar(char c);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s1);
char		*ft_strnew(size_t size);
void		ft_putnbr(int nb); //delme?!!
void		ft_putstr(char const *s);
int			ft_isdigit(char c);
int			ft_numlen(intmax_t n, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strcat(char *s1, const char *s2);

int			ft_printf(const char *fmt, ...);
void		print_digits(va_list *args, list_spec cr);
void		print_str(va_list *args, list_spec cr);
int			main_call(const char **fmt, va_list *args);
list_spec	save_spec(const char **fmt);
int			check_type(char c);
void		fill_align(const char *fmt, list_spec *cr);
void	 	fill_width_precs(const char *fmt, list_spec *cr);
void		fill_mod(const char *fmt, list_spec *cr);
void		fill_type(const char **fmt, list_spec *cr);
char		*ft_itoabase(uintmax_t c, int sys, int rg);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:25:45 by seopark           #+#    #+#             */
/*   Updated: 2021/06/11 15:16:17 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

typedef struct  s_flags
{
    int minus;
    int zero;
    int width;
    int dot;
    int precision;
    int star;

    int cnt;
//	int	printable;
}               t_flags;

/*		ft_printf.c		*/
int			ft_printf(const char *format, ...);
void		init_flags(t_flags *flags, int result);
void		check_specifier(const char *copy, t_flags *flags, va_list ap);
int			calc_num(char c, int num);
const char	*check_flags(const char *copy, t_flags *flags, va_list ap);
//void		handle_integer(t_flags *flags, va_list ap);

/*		print_string.c	*/
void		print_string(t_flags *flags, va_list ap);
void		print_str_precision(t_flags *flags, char *str);
void		print_str_width(t_flags *flags, char *str);


/*		libft.c 	*/
int			ft_strlen(const char *str);
void		ft_putchar(char c, t_flags *flags);
int			is_digit(char c);
int			is_spec(char c);


/*		ft_output.c		*/
void		print_width(t_flags *flags);
void		print_char(t_flags *flags, va_list ap);

/*		handle_flags.c	*/
void		handle_awidth(t_flags *flags, va_list ap);
const char	*handle_dot(const char *copy, t_flags *flags, va_list ap);
/*		ft_itoa.c		*/

#endif
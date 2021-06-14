/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:25:45 by seopark           #+#    #+#             */
/*   Updated: 2021/06/14 22:25:16 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

//# define INT 0
//# define UINT 1
//# define HEX 1

typedef struct  s_flags
{
    int minus;
    int zero;
    int width;
    int dot;
    int precision;
    int star;
    int cnt;
}               t_flags;

/*		ft_printf.c		*/
int			ft_printf(const char *format, ...);
void		init_flags(t_flags *flags, int result);
void		check_specifier(const char *copy, t_flags *flags, va_list ap);
int			calc_num(char c, int num);
const char	*check_flags(const char *copy, t_flags *flags, va_list ap);
const char	*calc_width(t_flags *flags, const char *copy);


void		handle_int_prec(t_flags *flags, char *str, int len, int negative);
void		handle_int_width(t_flags *flags, char *str, int len, int negative);
void		pre_handle_integer(t_flags *flags, char c, va_list ap);

/*		print_string.c	*/
void		print_string(t_flags *flags, va_list ap);
void		print_str_precision(t_flags *flags, char *str);
void		print_str_width(t_flags *flags, char *str);
void		print_int_width(t_flags *flags, char *str, int negative);

/*		libft_util.c 	*/
int			ft_strlen(const char *str);
void		ft_putchar(char c, t_flags *flags);
int			is_digit(char c);
int			is_spec(char c);
int			digit_len(long long num);


/*		ft_output.c		*/
void		print_width(t_flags *flags, int sign_zero);
void		print_char(t_flags *flags, va_list ap);

/*		handle_flags.c	*/
void		handle_awidth(t_flags *flags, va_list ap);
const char	*handle_dot(const char *copy, t_flags *flags, va_list ap);


/*		handle_hex.c	*/
//char		*handle_hex(char c, unsigned int num);
char		*handle_hex(char c, unsigned long long num);
void		ft_recursive(char *hex_str, unsigned long long num, int cnt, int upper);

/*		ft_itoa.c		*/
char		*ft_itoa(long long n);
char		*ft_convert(int sign, int len, long long num);
#endif

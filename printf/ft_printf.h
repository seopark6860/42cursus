/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seopark <seopark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:25:45 by seopark           #+#    #+#             */
/*   Updated: 2021/06/19 15:36:14 by seopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_flags
{
	int			minus;
	int			zero;
	int			width;
	int			dot;
	int			precision;
	int			star;
	int			cnt;
}				t_flags;

/*
**		ft_printf.c
*/
int				ft_printf(const char *format, ...);
void			init_flags(t_flags *flags, int result);
const char		*calc_width(t_flags *flags, const char *copy);
int				check_specifier(const char *copy, t_flags *flags, va_list ap);
const char		*check_flags(const char *c, t_flags *flags,
				int res, va_list ap);

/*
**		 parsing_num.c
*/
int				handle_zero_num(t_flags *flags, char *str);
void			handle_int_width(t_flags *flags, char *str,
				int len, int negative);
int				handle_integer(t_flags *flags, char c, char *str,
				long long num);
int				parsing_num(t_flags *flags, char c, va_list ap);

/*
** 		print_int.c
*/
void			handle_int_prec(t_flags *flags, char *str, int len,
				int negative);
void			print_int_prec(t_flags *flags, char *str, int negative);
void			print_int_width(t_flags *flags, char *str, int negative);

/*
** 		print_string.c
*/
void			print_str(t_flags *flags, char *str);
void			print_str_precision(t_flags *flags, char *str);
void			print_str_width(t_flags *flags, char *str);
void			print_string(t_flags *flags, va_list ap);

/*
** 		print_pointer
*/
void			print_pointer_width(t_flags *flags, char *str);
void			print_pointer_prec(t_flags *flags, char *str);

/*
** 		ft_output.c
*/
void			print_char(t_flags *flags, va_list ap);
void			print_width(t_flags *flags, int sign_zero);
void			print_minus(t_flags *flags, int negative);
void			print_percent(t_flags *flags);

/*
** 		libft_util.c
*/
int				printf_strlen(const char *str);
void			ft_putchar(char c, t_flags *flags);
int				is_digit(char c);
int				calc_num(char c, int num);
int				digit_len(long long num);

/*
** 		handle_flags.c
*/
void			handle_awidth(t_flags *flags, va_list ap);
void			handle_aprecision(t_flags *flags, va_list ap);
const char		*handle_dot(const char *copy, t_flags *flags, va_list ap);

/*
** 		handle_hex.c
*/
char			*printf_convert(int len, long long num);
char			*printf_itoa(long long n);
void			ft_recursive(char *hex_str, unsigned long long num,
				int cnt, int upper);
char			*handle_hex(char c, unsigned long long num);

/*
** 		handle_pointer.c
*/
int				handle_pointer_zero(t_flags *flags);
void			handle_pointer_width(t_flags *flags, char *str, int len);
void			handle_pointer_prec(t_flags *flags, char *str, int len);
void			handle_pointer(t_flags *flags, char *str, unsigned long long p);
#endif

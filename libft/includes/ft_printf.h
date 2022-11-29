/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 23:15:59 by amitcul           #+#    #+#             */
/*   Updated: 2022/11/29 12:49:23 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/**
 * Mandatory includes
*/

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>

# include "libft.h"

/**
 * Defines
*/

# define TYPE "%cspdiuxX"
# define MAX 1000000

/**
 * Structs
*/

typedef struct s_token
{
	char	type;

	int		asterisk;
	int		width_v;
	int		precision_v;
	int		dash;
	int		zero;
	int		dot;
	int		hash;
	int		space;
	int		plus;

}				t_token;

int		ft_printf(const char *format, ...);

int		get_value_from_format(t_token *token, const char *format, va_list *op);

/**
 * utils.c
*/
int		get_number_length(long long value, int base);
int		ft_abs(int x);
int		ft_max(int a, int b);
char	*to_hex(long long value);
void	add_sign(char **to_print, char sign);

/**
 * print_percent.c
*/
int		print_percent(t_token *token);

/**
 * print_c.c
*/
int		print_c(t_token *token, unsigned char value);

/**
 * print_s.c
*/
int		print_s(t_token *token, char *value);

/**
 * print_p.c
*/
int		print_p(t_token *token, unsigned long value);

/**
 * print_d.c
*/
int		print_d(t_token *token, int value);

/**
 * print_u.c
*/
int		print_u(t_token *token, long value);

/**
 * print_x.c
*/
int		print_x(t_token *token, unsigned int value);

/**
 * token.c
*/

int		fill_token(t_token *token, const char *format, va_list *op);
int		init_token(t_token **token);
#endif


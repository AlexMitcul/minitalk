/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 02:59:03 by amitcul           #+#    #+#             */
/*   Updated: 2022/11/29 12:38:00 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	to_upper_case(char **str)
{
	char	*p;

	p = *str;
	while (*p != '\0')
	{
		if (*p >= 'a' && *p <= 'z')
			*p -= 32;
		p++;
	}
}

static int	print_with_zeros(t_token *token, char *to_print)
{
	int	count;
	int	len;

	count = 0;
	len = ft_strlen(to_print);
	if (token->hash == 1 && token->type == 'x' && to_print[0] != '0')
		count += write(STDOUT_FILENO, "0x", 2);
	else if (token->hash == 1 && token->type == 'X' && to_print[0] != '0')
		count += write(STDOUT_FILENO, "0X", 2);
	if (token->hash == 1)
		token->width_v -= 2;
	if (token->zero == 1 && token->dot == 0)
		while ((token->width_v-- - len) > 0)
			count += write(STDOUT_FILENO, "0", 1);
	else
		while ((token->width_v-- - len) > 0)
			count += write(STDOUT_FILENO, " ", 1);
	count += write(STDOUT_FILENO, to_print, ft_strlen(to_print));
	return (count);
}

static int	write_with_width_field(t_token *token, char *to_print)
{
	int	count;
	int	len;

	count = 0;
	len = ft_strlen(to_print);
	if (token->hash == 1 && to_print[0] != '0')
		len += 2;
	if (token->dash == 1)
	{
		if (token->hash == 1 && token->type == 'X')
			count += write(STDOUT_FILENO, "0X", 2);
		else if (token->hash == 1 && token->type == 'x')
			count += write(STDOUT_FILENO, "0x", 2);
		if (token->hash == 1)
			count += write(STDOUT_FILENO, to_print, len - 2);
		else
			count += write(STDOUT_FILENO, to_print, len);
		while ((token->width_v--) - len > 0)
			count += write(STDOUT_FILENO, " ", 1);
	}
	else
		return (print_with_zeros(token, to_print));
	return (count);
}

int	print_x(t_token *t, unsigned int value)
{
	int		count;
	char	*h;
	char	*tmp;

	count = 0;
	h = to_hex(value);
	if (!h)
		return (0);
	if (t->type == 'X')
		to_upper_case(&h);
	if (t->dot && (t->precision_v > (int)ft_strlen(h) || !t->precision_v))
	{
		tmp = ft_memset(malloc(sizeof(char) * (t->precision_v + 1)), '0',
				t->precision_v);
		tmp[t->precision_v + 1] = '\0';
		strlcpy(tmp + (t->precision_v - ft_strlen(h)), h, ft_strlen(h) + 1);
		free(h);
		h = tmp;
	}
	if (t->width_v >= 0)
		count += write_with_width_field(t, h);
	else
		count += write(STDOUT_FILENO, h, ft_strlen(h));
	free(h);
	return (count);
}

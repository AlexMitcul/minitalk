/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 02:59:09 by amitcul           #+#    #+#             */
/*   Updated: 2022/11/29 12:37:29 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	build_result_with_zeros(t_token *token, char **to_print)
{
	char	*tmp;
	int		len;

	len = ft_strlen(*to_print);
	if (token->dot && (token->precision_v > len || token->precision_v == 0))
	{
		tmp = memset(malloc(sizeof(char) * (token->precision_v + 1)), (int) '0',
				token->precision_v);
		tmp[token->precision_v] = '\0';
		strlcpy(&(tmp[token->precision_v - len]), *to_print, len + 1);
		free(*to_print);
		*to_print = tmp;
	}
	else if (token->dot == 0 && token->zero)
	{
		token->width_v = ft_max(token->width_v, len);
		tmp = memset(malloc(sizeof(char) * (token->width_v + 1)), (int) '0',
				token->width_v);
		tmp[token->width_v] = '\0';
		strlcpy(&(tmp[token->width_v - len]), *to_print, token->width_v + 1);
		free(*to_print);
		*to_print = tmp;
	}
}

int	print_u(t_token *token, long value)
{
	int		count;
	char	*to_print;
	int		len;

	count = 0;
	to_print = ft_itoa(value);
	len = ft_strlen(to_print);
	if (value < 0)
		token->width_v = ft_max(token->width_v, len);
	if ((token->dot && (token->precision_v > len || token->precision_v == 0))
		|| token->zero)
		build_result_with_zeros(token, &to_print);
	if ((token->type == 'd' || token->type == 'i') && token->plus)
		add_sign(&to_print, '+');
	if ((token->type == 'd' || token->type == 'i') && token->plus == 0
		&& token->space)
		add_sign(&to_print, ' ');
	if (token->dash)
		count += ft_printf("%-*s", token->width_v, to_print);
	else
		count += ft_printf("%*s", token->width_v, to_print);
	free(to_print);
	return (count);
}

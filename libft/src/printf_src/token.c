/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:17:53 by amitcul           #+#    #+#             */
/*   Updated: 2022/11/29 12:37:50 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	init_token(t_token **token)
{
	*token = malloc(sizeof(t_token));
	if (!(*token))
		return (1);
	(*token)->type = 0;
	(*token)->asterisk = 0;
	(*token)->width_v = 0;
	(*token)->precision_v = 0;
	(*token)->dash = 0;
	(*token)->zero = 0;
	(*token)->dot = 0;
	(*token)->hash = 0;
	(*token)->space = 0;
	(*token)->plus = 0;
	return (0);
}

int	fill_token(t_token *token, const char *format, va_list *op)
{
	if (*format == '-')
		token->dash = 1;
	else if (*format == '0' && token->dot == 0)
		token->zero = 1;
	else if (*format == '.')
		token->dot = 1;
	else if (*format == '#')
		token->hash = 1;
	else if (*format == ' ')
		token->space = 1;
	else if (*format == '+')
		token->plus = 1;
	else if ((*format >= '1' && *format <= '9') || *format == '*')
		return (get_value_from_format(token, format, op));
	return (1);
}

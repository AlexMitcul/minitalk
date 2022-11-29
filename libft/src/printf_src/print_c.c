/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 03:05:38 by amitcul           #+#    #+#             */
/*   Updated: 2022/11/29 12:37:35 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	print_c(t_token *token, unsigned char value)
{
	int	count;

	count = 0;
	if (token->dash == 1)
	{
		count += write(STDOUT_FILENO, &value, 1);
		while (token->width_v-- > 1)
			count += write(STDOUT_FILENO, " ", 1);
	}
	else
	{
		while (token->width_v-- > 1)
			count += write(STDOUT_FILENO, " ", 1);
		count += write(STDOUT_FILENO, &value, 1);
	}
	return (count);
}

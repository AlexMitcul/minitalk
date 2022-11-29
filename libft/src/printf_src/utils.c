/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 02:20:17 by amitcul           #+#    #+#             */
/*   Updated: 2022/11/29 12:37:59 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	get_number_length(long long value, int base)
{
	int	length;

	if (value == 0)
		return (1);
	length = 0;
	while (value != 0)
	{
		length += 1;
		value = value / base;
	}
	return (length);
}

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

char	*to_hex(long long value)
{
	int		len;
	char	*res;

	len = get_number_length(value, 16);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	len--;
	while (len >= 0)
	{
		res[len] = "0123456789abcdef"[ft_abs(value % 16)];
		value = value / 16;
		len--;
	}
	return (res);
}

void	add_sign(char **to_print, char sign)
{
	char	*tmp;
	int		len;

	len = ft_strlen(*to_print);
	tmp = malloc(sizeof(char) * (len + 2));
	tmp[0] = sign;
	tmp[len + 1] = '\0';
	ft_strlcpy(tmp + 1, *to_print, len + 1);
	free(*to_print);
	*to_print = tmp;
}

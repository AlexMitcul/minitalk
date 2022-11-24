/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:20:34 by amitcul           #+#    #+#             */
/*   Updated: 2022/11/24 05:33:33 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

static int	ft_atoi(char *str)
{
	int	res;

	res = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r' || \
	*str == '\t' || *str == '\v')
		str++;
	while (*str == '+')
		str++;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			res = res * 10 + (*str - '0');
		else
			break ;
		str++;
	}
	return (res);
}

/**
 * SIGUSR1 will send 0
 * SIGUSR2 will send 1
*/
void	handle(char i, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		write(1, "Invalid arguments count (expected 3)\n", 37);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		handle(argv[2][i], pid);
		i++;
	}
	return (0);
}

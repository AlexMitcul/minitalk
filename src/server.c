/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 01:16:01 by amitcul           #+#    #+#             */
/*   Updated: 2023/01/11 23:28:50 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	signal_handler(int signal)
{
	static int	value = 0;
	static char	index = 0;

	if (index == 7)
	{
		ft_printf("%c", value);
		value = 0;
		index = 0;
		return ;
	}
	if (signal == SIGUSR1)
	value = value | (0x1 << index);
	index++;
}

int	main(int argc, char **argv)
{
	int		pid;

	(void)argv;
	if (argc != 1)
	{
		printf("Wrong input!\n");
		printf("Try: './server'\n");
		return (0);
	}
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, &signal_handler);
		signal(SIGUSR2, &signal_handler);
	}
	return (0);
}

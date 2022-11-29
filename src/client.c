/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:37:17 by amitcul           #+#    #+#             */
/*   Updated: 2022/11/29 14:37:35 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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
		usleep(200);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	char	*message;
	int		pid;
	int		i;

	if (argc != 3)
	{
		write(1, "Invalid arguments count (expected 3)\n", 37);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	message = strdup(argv[2]);
	while (message[i] != '\0')
	{
		handle(message[i], pid);
		i++;
	}
	free(message);
	return (0);
}

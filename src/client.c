/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:37:17 by amitcul           #+#    #+#             */
/*   Updated: 2023/01/11 23:28:52 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_character(int pid, char character)
{
	char	index;

	index = 0;
	while (index < 8)
	{
		if (character & (1 << index))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		index++;
		usleep(200);
	}
}

void	send_message(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i] != '\0')
	{
		send_character(pid, message[i]);
		i++;
	}
}

int	get_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i] != '\0')
	{
		if (ft_isdigit(pid[i]) == 0)
			return (-1);
		i++;
	}
	return (ft_atoi(pid));
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Wrong input!\n");
		ft_printf("Try: './client [PID] [message]'\n");
		return (0);
	}
	pid = get_pid(argv[1]);
	if (pid == -1)
	{
		ft_printf("Wrong PID.\n");
		return (0);
	}
	send_message(pid, argv[2]);
	return (0);
}

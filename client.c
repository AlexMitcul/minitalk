/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:20:34 by amitcul           #+#    #+#             */
/*   Updated: 2022/11/24 05:05:19 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include <signal.h>

#include <unistd.h>

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

int main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		printf("Invalid arguments count (expected 3)\n");
		return (0);
	}
	pid = atoi(argv[1]);
	printf("Need to send message [%s] to [%d] pid\n", argv[2], pid);

	int i = 0;
	while (argv[2][i] != '\0')
	{
		handle(argv[2][i], pid);
		i++;
	}
	return (0);
}

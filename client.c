/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:20:34 by amitcul           #+#    #+#             */
/*   Updated: 2022/11/24 01:31:00 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include <signal.h>

#include <unistd.h>

void	handle(char c, int pid)
{
	while (c > 0)
	{
		if (c & 1)
		{
			printf("Try to send 1\n");
			kill(pid, SIGUSR1);
		}
		else
		{
			printf("Try to send 0\n");
			kill(pid, SIGUSR2);
		}
		c = c >> 1;
		usleep(300);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 01:16:01 by amitcul           #+#    #+#             */
/*   Updated: 2023/01/12 16:30:55 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	value = 0;
	static char	index = 0;

	(void)context;
	if (signal == SIGUSR1)
	value = value | (0x01 << index);
	if (index == 7)
	{
		if (value == 0)
			kill(info->si_pid, SIGUSR1);
		ft_printf("%c", value);
		value = 0;
		index = 0;
		return ;
	}
	index++;
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		printf("Wrong input!\n");
		printf("Try: './server'\n");
		return (0);
	}
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	sa.sa_sigaction = &signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	return (0);
}

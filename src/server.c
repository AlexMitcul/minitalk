/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 01:16:01 by amitcul           #+#    #+#             */
/*   Updated: 2022/12/03 15:29:30 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	print_byte(int signal)
{
	static int	character;
	static int	bit;

	if (signal == SIGUSR1)
		character |= 0x01 << bit;
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", character);
		bit = 0;
		character = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	id;

	(void)argv;
	if (argc != 1)
	{
		printf("Wrong input!\n");
		printf("Try: './server'\n");
		return (0);
	}
	id = getpid();
	ft_printf("PID: %d\n", id);
	while (1)
	{
		signal(SIGUSR1, print_byte);
		signal(SIGUSR2, print_byte);
		pause();
	}
	return (0);
}

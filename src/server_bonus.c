/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:12:20 by amitcul           #+#    #+#             */
/*   Updated: 2022/11/29 12:24:18 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk_bonus.h"

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

static void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

static void	ft_putnbr(int nb)
{
	if (nb < 10)
		ft_putchar('0' + nb);
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

int	main(int argc, char **argv)
{
	pid_t	id;

	(void)argv;
	if (argc != 1)
	{
		write(1, "Error!\n", 7);
		return (0);
	}
	id = getpid();
	write(1, "PID: ", 5);
	ft_putnbr(id);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, print_byte);
		signal(SIGUSR2, print_byte);
		pause();
	}
	return (0);
}

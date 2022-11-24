/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 01:16:01 by amitcul           #+#    #+#             */
/*   Updated: 2022/11/24 01:32:39 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

static void sig_usr(int signo)
{
	if (signo == SIGUSR1)
		printf("1\n");
	else if (signo == SIGUSR2)
		printf("0\n");
}

void	print_byte(char c)
{
	char res = 0;

	// 127	1111111
	// c ==	1100011
	//


	while (c > 0)
	{
		res |= c & 127;
		printf("%d\n", res);
		c = c >> 1;
	}
	printf("res = %d\n", res);

}

int main(void)
{
	pid_t id = getpid();
	printf("PID: %d\n", id);

	if (signal(SIGUSR1, sig_usr) == SIG_ERR)
		printf("Error usr1\n");
	if (signal(SIGUSR2, sig_usr) == SIG_ERR)
		printf("Error usr2\n");
	for ( ; ; )
		pause();
	return (0);
}

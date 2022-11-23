/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 01:16:01 by amitcul           #+#    #+#             */
/*   Updated: 2022/11/23 01:34:16 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

static void sig_usr(int signo)
{
	if (signo == SIGUSR1)
		printf("get signal from usr1\n");
	else if (signo == SIGUSR2)
		printf("get signal from usr2\n");
	else
		printf("get signal %d\n", signo);
}

int main(void)
{
	// if (signal(SIGUSR1, sig_usr) == SIG_ERR)
	// 	printf("Error usr1");
	// if (signal(SIGUSR2, sig_usr) == SIG_ERR)
	// 	printf("Error usr2");
	// for ( ; ; )
	// 	pause();

	pid_t id = getpid();
	printf("PID: %d\n", id);

	return (0);
}

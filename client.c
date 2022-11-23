/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amitcul <amitcul@student.42porto.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:20:34 by amitcul           #+#    #+#             */
/*   Updated: 2022/11/23 01:34:18 by amitcul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

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

	return (0);
}

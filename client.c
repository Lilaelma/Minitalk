/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aclarenn <aclarenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:12:58 by aclarenn          #+#    #+#             */
/*   Updated: 2023/06/24 11:24:19 by aclarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "minitalk.h"

int	g_temp;

void	handle(int signal)
{
	if (signal == SIGUSR1)
		g_temp = 0;
	if (signal == SIGUSR2)
	{
		write(1, "OK\n", 2);
		exit(0);
	}
}

void	ft_send(int pid, char c)
{
	int	i;

	i = 7;
	while (i + 1)
	{
		if (c >> i & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				return ;
		}
		else
			if (kill(pid, SIGUSR2) == -1)
				return ;
		while (g_temp)
			;
		g_temp = 1;
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (1);
	signal(SIGUSR1, handle);
	signal(SIGUSR2, handle);
	g_temp = 1;
	i = 0;
	while (argv[2][i])
	{
		ft_send(pid, argv[2][i]);
		i++;
	}
	ft_send(pid, '\0');
	return (0);
}

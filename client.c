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
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_temp)
			;
		g_temp = 1;
		i--;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
		return (1);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		return (1);
	signal(SIGUSR1, handle);
	signal(SIGUSR2, handle);
	g_temp = 1;
	i = 0;
	while (av[2][i])
	{
		ft_send(pid, av[2][i]);
		i++;
	}
	ft_send(pid, '\0');
	return (0);
}

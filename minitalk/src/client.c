/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:42:31 by albartol          #+#    #+#             */
/*   Updated: 2024/01/13 16:18:11 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_check_pid(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if (!ft_isdigit(pid[i]))
			return (EXIT_FAILURE);
		i++;
	}
	if (i > 7 || ft_atoi(pid) > PID_MAX_LIMIT)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	handler(int signal)
{
	static unsigned int	sen;
	int					i;

	sen++;
	if (signal == SIGUSR2)
	{
		i = ft_printf("Señales enviadas: %u\n", sen);
		if (i == -1)
			exit(EXIT_FAILURE);
		exit(EXIT_SUCCESS);
	}
	usleep(50);
}

static void	ft_send_char(int c, pid_t pid)
{
	int	i;
	int	n;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
			n = kill(pid, SIGUSR1);
		else
			n = kill(pid, SIGUSR2);
		if (n == -1)
			exit(EXIT_FAILURE);
		pause();
		i++;
	}
}

static void	ft_send_str(char *str, pid_t pid)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(str))
	{
		ft_send_char(str[i], pid);
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid_server;
	struct sigaction	sig_act;
	unsigned int		mlen;

	if (argc != 3)
		return (EXIT_FAILURE);
	if (ft_check_pid(argv[1]))
		return (EXIT_FAILURE);
	pid_server = ft_atoi(argv[1]);
	sig_act.sa_handler = handler;
	sigaction(SIGUSR1, &sig_act, NULL);
	sigaction(SIGUSR2, &sig_act, NULL);
	mlen = (ft_strlen(argv[2]) + 1) * 8;
	if (ft_printf("Señales a enviar: %u\n", mlen) == -1)
		return (EXIT_FAILURE);
	ft_send_str(argv[2], pid_server);
	return (EXIT_SUCCESS);
}

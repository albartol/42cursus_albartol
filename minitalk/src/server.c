/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:42:40 by albartol          #+#    #+#             */
/*   Updated: 2024/01/15 18:39:54 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send_signal(short fin, pid_t pid, char *str)
{
	int	i;

	usleep(50);
	if (fin)
		i = kill(pid, SIGUSR1);
	else
		i = kill(pid, SIGUSR2);
	if (i == -1)
	{
		if (str)
			free(str);
		exit(EXIT_FAILURE);
	}
}

static void ft_exit_signal(char **str, pid_t *old_pid, int *i, int *c)
{
	if (*str)
		free(*str);
	*str = 0;
	*i = 0;
	*c = 0;
	usleep(50);
	kill(*old_pid, SIGUSR2);
	*old_pid = 0;
}

static void ft_print_message(char **str, int *fin, pid_t *old_pid)
{
	int	i;

	if (*str)
	{
		i = ft_printf("%s\n", *str);
		free(*str);
		if (i == -1)
			exit(EXIT_FAILURE);
		*fin = 0;
		*old_pid = 0;
		*str = 0;
	}
}

static void	ft_get_pid_handler(int signal, siginfo_t *info, void *context)
{
	static int		i;
	static int		c;
	static pid_t	old_pid;
	static char		*str;
	int				fin;

	(void)context;
	fin = 1;
	if (!old_pid)
		old_pid = info->si_pid;
	else if (old_pid != info->si_pid)
		ft_exit_signal(&str, &old_pid, &i, &c);
	if (signal == SIGUSR1)
		c |= (1 << i);
	i++;
	if (i >= 8)
	{
		if (c == 0)
			ft_print_message(&str, &fin, &old_pid);
		else
			str = ft_charjoin(str, c);
		i = 0;
		c = 0;
	}
	ft_send_signal(fin, info->si_pid, str);
}

int	main(void)
{
	pid_t				pid_server;
	struct sigaction	sig_act;

	pid_server = getpid();
	if (ft_printf("PID: %d\n", pid_server) == -1)
		return (EXIT_FAILURE);
	sig_act.sa_flags = SA_SIGINFO;
	sig_act.sa_sigaction = ft_get_pid_handler;
	sigaction(SIGUSR1, &sig_act, NULL);
	sigaction(SIGUSR2, &sig_act, NULL);
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}

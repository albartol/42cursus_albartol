/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:57:31 by albartol          #+#    #+#             */
/*   Updated: 2023/12/21 19:11:54 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack->next;
		while (temp)
		{
			if (*(int *)temp->content <= *(int *)stack->content)
				return (0);
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (1);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	ft_perror(const char *str)
{
	ft_putstr_fd((char *)str, 2);
	return (0);
}

int	ft_error_atoi(const char *str, t_list **stack, int *nbr, char **array)
{
	if (str)
		ft_putstr_fd((char *)str, 2);
	ft_clear(*stack);
	if (*nbr)
		free(nbr);
	ft_free_split(array);
	return (0);
}

long	ft_atoi_l(const char *str)
{
	int		i;
	long	nbr;
	int		sym;

	i = 0;
	nbr = 0;
	sym = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sym = -sym;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	nbr *= sym;
	return (nbr);
}

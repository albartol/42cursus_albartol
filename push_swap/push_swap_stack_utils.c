/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:16:26 by albartol          #+#    #+#             */
/*   Updated: 2024/01/10 12:36:58 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_split(char **a)
{
	int	i;
	int	n;

	i = 0;
	while (a[i])
	{
		n = -1;
		while (a[i][++n])
		{
			if (!ft_isdigit(a[i][n]) && ((a[i][n] == 45 || a[i][n] == 43)
					&& !ft_isdigit(a[i][n + 1])))
				return (0);
			if (!ft_isdigit(a[i][n]) && ft_isdigit(a[i][n - 1]))
				return (0);
			if (!ft_isdigit(a[i][n]) && !(a[i][n] == 45 || a[i][n] == 43))
				return (0);
		}
		if (n > 11 || (ft_atoi_l(a[i]) > INT_MAX || ft_atoi_l(a[i]) < INT_MIN))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check(char **argv)
{
	int		i;
	char	**array;

	i = 1;
	while (argv[i])
	{
		array = ft_split(argv[i], ' ');
		if (!array)
			return (0);
		if (!ft_check_split(array))
		{
			ft_free_split(array);
			return (0);
		}
		i++;
		ft_free_split(array);
	}
	return (1);
}

static int	ft_add_stack(char **argv, t_list **stack)
{
	int		i;
	int		*nbr;
	t_list	*temp;

	i = 0;
	while (argv[i])
	{
		nbr = (int *)malloc(sizeof(int));
		if (!nbr)
			return (ft_error_atoi(0, stack, nbr, argv));
		*nbr = ft_atoi(argv[i++]);
		temp = ft_lstnew(nbr);
		if (!temp)
			return (ft_error_atoi(0, stack, nbr, argv));
		ft_lstadd_back(stack, temp);
	}
	return (1);
}

t_list	*ft_create_stack(char **argv)
{
	int		i;
	t_list	*stack;
	char	**array;

	i = 1;
	stack = 0;
	while (argv[i])
	{
		array = ft_split(argv[i], ' ');
		if (!array)
			return (0);
		if (!ft_add_stack(array, &stack))
			return (0);
		i++;
		ft_free_split(array);
	}
	return (stack);
}

int	ft_check_stack(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack->next;
		while (temp)
		{
			if (*(int *)temp->content == *(int *)stack->content)
				return (0);
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (1);
}

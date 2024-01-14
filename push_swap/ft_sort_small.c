/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:42:11 by albartol          #+#    #+#             */
/*   Updated: 2023/12/30 15:40:43 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_sort(t_list **stack_a, t_list **stack_b, int *list, int i)
{
	t_list	*stack;
	int		n;

	if (i == 2 || ft_sorted(*stack_a))
		return ;
	n = 0;
	stack = *stack_a;
	while (stack && list[i] != *(int *)stack->content)
	{
		n++;
		stack = stack->next;
	}
	if (n > (i / 2) && n)
	{
		while (n++ <= i)
			ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	else
	{
		while (n--)
			ft_ra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	ft_stack_sort(stack_a, stack_b, list, i - 1);
}

void	ft_sort_3(t_list **stack_a)
{
	int	i;
	int	m;
	int	n;

	i = *(int *)(*stack_a)->content;
	m = *(int *)((*stack_a)->next)->content;
	n = *(int *)ft_lstlast(*stack_a)->content;
	if (i > m && i > n && m < n)
		ft_ra(stack_a);
	else if (n < m && n < i && i < m)
		ft_rra(stack_a);
	else if (i > m || (i < m && n > i))
		ft_sa(stack_a);
}

void	ft_stack_merge(t_list **stack_a, t_list **stack_b)
{
	while (!ft_sorted(*stack_a))
		ft_sort_3(stack_a);
	while (ft_lstsize(*stack_b))
		ft_pa(stack_b, stack_a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:02:17 by albartol          #+#    #+#             */
/*   Updated: 2023/12/30 14:48:35 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_small(t_list **stack_a, t_list **stack_b, int *list, int argc)
{
	if (ft_lstsize(*stack_a) <= 2)
	{
		if (ft_lstsize(*stack_a) <= 1)
			return ;
		if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
			ft_sa(stack_a);
		return ;
	}
	ft_stack_sort(stack_a, stack_b, list, argc - 1);
	ft_stack_merge(stack_a, stack_b);
}

int	ft_sort_medium(t_list **stack_a, t_list **stack_b, int *list, int argc)
{
	if (!ft_med_sort(stack_a, stack_b, list, argc - 1))
		return (0);
	ft_med_merge(stack_a, stack_b, list, 0);
	return (1);
}

int	ft_sort_big(t_list **stack_a, t_list **stack_b, int *list, int argc)
{
	if (!ft_big_sort(stack_a, stack_b, list, argc - 1))
		return (0);
	ft_med_merge(stack_a, stack_b, list, 0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:39:18 by albartol          #+#    #+#             */
/*   Updated: 2023/12/21 19:31:47 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push(t_list **stack_o, t_list **stack_d)
{
	t_list	*stack;

	if (!*stack_o)
		return (0);
	stack = *stack_o;
	*stack_o = stack->next;
	stack->next = *stack_d;
	*stack_d = stack;
	return (1);
}

int	ft_pa(t_list **stack_b, t_list **stack_a)
{
	if (!ft_push(stack_b, stack_a))
		return (-1);
	return (write(1, "pa\n", 3));
}

int	ft_pb(t_list **stack_a, t_list **stack_b)
{
	if (!ft_push(stack_a, stack_b))
		return (-1);
	return (write(1, "pb\n", 3));
}

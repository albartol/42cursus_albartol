/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:44:55 by albartol          #+#    #+#             */
/*   Updated: 2023/12/21 19:32:56 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_list **stack_o)
{
	t_list	*stack;
	t_list	*temp;

	if (!*stack_o)
		return (0);
	stack = *stack_o;
	if (!stack->next)
		return (0);
	temp = stack->next;
	stack->next = temp->next;
	temp->next = *stack_o;
	*stack_o = temp;
	return (1);
}

int	ft_sa(t_list **stack_a)
{
	if (!ft_swap(stack_a))
		return (-1);
	return (write(1, "sa\n", 3));
}

int	ft_sb(t_list **stack_b)
{
	if (!ft_swap(stack_b))
		return (-1);
	return (write(1, "sb\n", 3));
}

int	ft_ss(t_list **stack_a, t_list **stack_b)
{
	if (!ft_swap(stack_a))
		return (-1);
	if (!ft_swap(stack_b))
		return (-1);
	return (write(1, "ss\n", 3));
}

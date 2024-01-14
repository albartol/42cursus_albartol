/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:25:22 by albartol          #+#    #+#             */
/*   Updated: 2023/12/21 19:32:40 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate(t_list **stack_o)
{
	t_list	*stack;
	t_list	*temp;

	stack = *stack_o;
	temp = stack->next;
	while (stack && stack->next)
		stack = stack->next;
	stack->next = *stack_o;
	stack = stack->next;
	stack->next = 0;
	*stack_o = temp;
	return (1);
}

int	ft_ra(t_list **stack_a)
{
	if (!ft_rotate(stack_a))
		return (-1);
	return (write(1, "ra\n", 3));
}

int	ft_rb(t_list **stack_b)
{
	if (!ft_rotate(stack_b))
		return (-1);
	return (write(1, "rb\n", 3));
}

int	ft_rr(t_list **stack_a, t_list **stack_b)
{
	if (!ft_rotate(stack_a))
		return (-1);
	if (!ft_rotate(stack_b))
		return (-1);
	return (write(1, "rr\n", 3));
}

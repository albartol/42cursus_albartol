/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:42:25 by albartol          #+#    #+#             */
/*   Updated: 2023/12/21 19:32:27 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_reverse(t_list **stack_o)
{
	t_list	*stack;
	t_list	*temp;
	int		i;

	i = 0;
	stack = *stack_o;
	temp = stack;
	while (stack && stack->next)
	{
		stack = stack->next;
		i++;
	}
	*stack_o = stack;
	stack->next = temp;
	temp = *stack_o;
	while (i--)
		temp = temp->next;
	temp->next = 0;
	return (1);
}

int	ft_rra(t_list **stack_a)
{
	if (!ft_reverse(stack_a))
		return (-1);
	return (write(1, "rra\n", 4));
}

int	ft_rrb(t_list **stack_b)
{
	if (!ft_reverse(stack_b))
		return (-1);
	return (write(1, "rrb\n", 4));
}

int	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	if (!ft_reverse(stack_a))
		return (-1);
	if (!ft_reverse(stack_b))
		return (-1);
	return (write(1, "rrr\n", 4));
}

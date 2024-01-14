/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:58:51 by albartol          #+#    #+#             */
/*   Updated: 2023/12/30 15:11:19 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_in_stack(t_list *stack_a, int i)
{
	t_list	*stack;

	stack = stack_a;
	while (stack && --i)
		stack = stack->next;
	return (*(int *)stack->content);
}

int	ft_find_big(t_list *stack_a, int *list, int argc, int chunk_l)
{
	int		n;
	int		i;
	int		k;
	t_list	*stack;

	n = 0;
	i = ft_lstsize(stack_a);
	if (i <= 1)
		return (0);
	stack = stack_a;
	while (stack && n < i / 4)
	{
		if (*(int *)stack->content <= list[argc - chunk_l])
			return (n);
		n++;
		stack = stack->next;
	}
	k = i - i / 4;
	while (i > k)
	{
		if (ft_find_in_stack(stack_a, i--) <= list[argc - chunk_l])
			return (i + 1);
	}
	return (ft_find(stack_a, list, argc, chunk_l));
}

void	ft_chunk_big(t_list **stack_a, t_list **stack_b, int *val)
{
	int	n;

	n = val[1];
	if (n > (ft_lstsize(*stack_a) / 2) && n)
	{
		if (ft_lstsize(*stack_b) > 1 && *(int *)(*stack_b)->content > val[3])
			ft_rb(stack_b);
		while (n++ <= ft_lstsize(*stack_a))
			ft_rra(stack_a);
		ft_pb(stack_a, stack_b);
	}
	else
	{
		if (ft_lstsize(*stack_b) > 1 && *(int *)(*stack_b)->content > val[3]
			&& n)
		{
			ft_rr(stack_a, stack_b);
			n--;
		}
		if (ft_lstsize(*stack_b) > 1 && *(int *)(*stack_b)->content > val[3])
			ft_rb(stack_b);
		while (n--)
			ft_ra(stack_a);
		ft_pb(stack_a, stack_b);
	}
}

// val[0] = tamaño del chunk
// val[1] = posicion del valor a pasar de stack_a a stack_b
// val[2] = numero de argumentos
// val[3] = valor medio en el chunk actual
int	ft_big_sort(t_list **stack_a, t_list **stack_b, int *list, int argc)
{
	int	*val;

	val = (int *)malloc(sizeof(int) * 4);
	if (!val)
		return (0);
	val[0] = argc / 10;
	val[2] = argc;
	while (ft_lstsize(*stack_a) > 0 && val[2])
	{
		val[3] = list[val[2] - val[0] / 2];
		while (ft_lstsize(*stack_a) > val[2] - val[0])
		{
			val[1] = ft_find_big(*stack_a, list, val[2], val[0]);
			ft_chunk_big(stack_a, stack_b, val);
		}
		if (val[2] >= val[0])
			val[2] = val[2] - val[0];
		if (val[2] < val[0])
			val[0] = val[2];
	}
	free(val);
	return (1);
}

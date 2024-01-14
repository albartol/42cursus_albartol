/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:10:39 by albartol          #+#    #+#             */
/*   Updated: 2023/12/26 16:25:30 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find(t_list *stack_a, int *list, int argc, int chunk_l)
{
	int	n;

	n = 0;
	if (ft_lstsize(stack_a) <= 1)
		return (0);
	if (*(int *)stack_a->content <= list[argc - chunk_l])
		return (n);
	else if (*(int *)stack_a->next->content <= list[argc - chunk_l])
		return (n + 1);
	else if (*(int *)ft_lstlast(stack_a)->content <= list[argc - chunk_l])
		return (argc);
	while (stack_a && *(int *)stack_a->content > list[argc - chunk_l])
	{
		n++;
		stack_a = stack_a->next;
	}
	return (n);
}

// val[1] = posicion del valor a pasar de stack_a a stack_b
// val[2] = numero de argumentos
// val[3] = valor medio en el chunk actual
void	ft_chunk_med(t_list **stack_a, t_list **stack_b, int *val)
{
	int	n;

	n = val[1];
	if (n > (val[2] / 2) && n)
	{
		if (ft_lstsize(*stack_b) > 1 && *(int *)(*stack_b)->content > val[3])
			ft_rb(stack_b);
		while (n++ <= val[2])
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
int	ft_med_sort(t_list **stack_a, t_list **stack_b, int *list, int argc)
{
	int	*val;

	val = (int *)malloc(sizeof(int) * 4);
	if (!val)
		return (0);
	val[0] = argc / 5;
	val[2] = argc;
	while (ft_lstsize(*stack_a) > 0 && val[2])
	{
		val[3] = list[val[2] - val[0] / 2];
		while (ft_lstsize(*stack_a) > val[2] - val[0])
		{
			val[1] = ft_find(*stack_a, list, val[2], val[0]);
			ft_chunk_med(stack_a, stack_b, val);
		}
		if (val[2] >= val[0])
			val[2] = val[2] - val[0];
		if (val[2] < val[0])
			val[0] = val[2];
	}
	free(val);
	return (1);
}

void	ft_med_merge(t_list **stack_a, t_list **stack_b, int *list, int i)
{
	t_list	*stack;
	int		n;

	if (!ft_lstsize(*stack_b))
		return ;
	n = 0;
	stack = *stack_b;
	while (stack && list[i] != *(int *)stack->content)
	{
		n++;
		stack = stack->next;
	}
	if (n > (ft_lstsize(*stack_b) / 2) && n)
	{
		while (n++ < ft_lstsize(*stack_b))
			ft_rrb(stack_b);
		ft_pa(stack_b, stack_a);
	}
	else
	{
		while (n--)
			ft_rb(stack_b);
		ft_pa(stack_b, stack_a);
	}
	ft_med_merge(stack_a, stack_b, list, i + 1);
}

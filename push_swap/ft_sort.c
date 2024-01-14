/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:35:53 by albartol          #+#    #+#             */
/*   Updated: 2023/12/20 14:52:54 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_clear(t_list *stack_a)
{
	ft_lstclear(&stack_a, free);
	return (0);
}

static void	ft_rev_array(int *list, int argc)
{
	int	temp;
	int	i;

	i = 0;
	while (argc > i)
	{
		temp = list[argc];
		list[argc] = list[i];
		list[i] = temp;
		i++;
		argc--;
	}
}

static void	ft_create_array(int *list, t_list **stack_a)
{
	t_list	*stack;
	int		i;

	stack = *stack_a;
	i = 0;
	while (stack)
	{
		list[i++] = *(int *)stack->content;
		stack = stack->next;
	}
}

int	ft_sort(t_list **stack_a, t_list **stack_b, int argc)
{
	int	*list;
	int	*list_order;
	int	n;

	n = 1;
	list = (int *)ft_calloc(argc, sizeof(int));
	if (!list)
		return (0);
	list_order = (int *)ft_calloc(argc, sizeof(int));
	if (!list_order)
		return (0);
	ft_create_array(list, stack_a);
	ft_merge_sort(list, argc, list_order);
	ft_rev_array(list, argc - 1);
	if (argc < 100)
		ft_sort_small(stack_a, stack_b, list, argc);
	else if (argc < 500)
		n = ft_sort_medium(stack_a, stack_b, list, argc);
	else
		n = ft_sort_big(stack_a, stack_b, list, argc);
	free(list);
	free(list_order);
	return (n);
}

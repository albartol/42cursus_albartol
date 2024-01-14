/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:38:07 by albartol          #+#    #+#             */
/*   Updated: 2023/12/30 15:47:42 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void ft_leaks(void)
{
	system("leaks push_swap");
} */

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_b = 0;
	if (argc < 2)
		return (0);
	if (!ft_check(argv))
		return (ft_perror("Error\n"));
	stack_a = ft_create_stack(argv);
	if (!stack_a)
		return (0);
	if (!ft_check_stack(stack_a))
	{
		ft_clear(stack_a);
		return (ft_perror("Error\n"));
	}
	if (ft_sorted(stack_a))
		return (ft_clear(stack_a));
	if (!ft_sort(&stack_a, &stack_b, ft_lstsize(stack_a)))
		ft_clear(stack_b);
	ft_clear(stack_a);
	return (0);
}

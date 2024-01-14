/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:04:26 by albartol          #+#    #+#             */
/*   Updated: 2023/12/23 14:12:33 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_check_input(char *input, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(input, "rra\n", 4))
		ft_rra_b(stack_a);
	else if (!ft_strncmp(input, "rrb\n", 4))
		ft_rrb_b(stack_b);
	else if (!ft_strncmp(input, "rrr\n", 4))
		ft_rrr_b(stack_a, stack_b);
	else if (!ft_strncmp(input, "ra\n", 3))
		ft_ra_b(stack_a);
	else if (!ft_strncmp(input, "rb\n", 3))
		ft_rb_b(stack_b);
	else if (!ft_strncmp(input, "rr\n", 3))
		ft_rr_b(stack_a, stack_b);
	else if (!ft_strncmp(input, "sa\n", 3))
		ft_sa_b(stack_a);
	else if (!ft_strncmp(input, "sb\n", 3))
		ft_sb_b(stack_b);
	else if (!ft_strncmp(input, "ss\n", 3))
		ft_ss_b(stack_a, stack_b);
	else if (!ft_strncmp(input, "pa\n", 3))
		ft_pa_b(stack_b, stack_a);
	else if (!ft_strncmp(input, "pb\n", 3))
		ft_pb_b(stack_a, stack_b);
	else
		return (0);
	return (1);
}

void	ft_check_order(t_list **stack_a, t_list **stack_b)
{
	if (ft_sorted(*stack_a) && !*stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	ft_process_input(t_list *input, t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = input;
	while (temp)
	{
		if (!ft_check_input(temp->content, stack_a, stack_b))
		{
			ft_clear(input);
			return (ft_perror("Error\n"));
		}
		temp = temp->next;
	}
	ft_check_order(stack_a, stack_b);
	ft_clear(input);
	return (1);
}

void	ft_read_input(t_list **input)
{
	char	*exit;

	while (1)
	{
		exit = get_next_line(0);
		if (!exit)
			return ;
		if (*exit != '\n')
			ft_lstadd_back(input, ft_lstnew(exit));
		else
			free(exit);
	}
}

void	ft_sort_manual(t_list **stack_a, t_list **stack_b)
{
	t_list	*input;

	input = 0;
	ft_read_input(&input);
	if (!input)
	{
		ft_check_order(stack_a, stack_b);
		return ;
	}
	ft_process_input(input, stack_a, stack_b);
}

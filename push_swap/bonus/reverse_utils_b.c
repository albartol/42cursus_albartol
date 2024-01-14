/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_utils_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:42:25 by albartol          #+#    #+#             */
/*   Updated: 2023/12/21 19:45:59 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rra_b(t_list **stack_a)
{
	ft_reverse(stack_a);
}

void	ft_rrb_b(t_list **stack_b)
{
	ft_reverse(stack_b);
}

void	ft_rrr_b(t_list **stack_a, t_list **stack_b)
{
	ft_reverse(stack_a);
	ft_reverse(stack_b);
}

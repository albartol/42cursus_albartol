/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:44:55 by albartol          #+#    #+#             */
/*   Updated: 2023/12/21 19:46:05 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sa_b(t_list **stack_a)
{
	ft_swap(stack_a);
}

void	ft_sb_b(t_list **stack_b)
{
	ft_swap(stack_b);
}

void	ft_ss_b(t_list **stack_a, t_list **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
}

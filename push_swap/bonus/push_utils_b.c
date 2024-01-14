/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:39:18 by albartol          #+#    #+#             */
/*   Updated: 2023/12/21 19:45:56 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_pa_b(t_list **stack_b, t_list **stack_a)
{
	ft_push(stack_b, stack_a);
}

void	ft_pb_b(t_list **stack_a, t_list **stack_b)
{
	ft_push(stack_a, stack_b);
}

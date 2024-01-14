/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:25:22 by albartol          #+#    #+#             */
/*   Updated: 2023/12/21 19:46:02 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_ra_b(t_list **stack_a)
{
	ft_rotate(stack_a);
}

void	ft_rb_b(t_list **stack_b)
{
	ft_rotate(stack_b);
}

void	ft_rr_b(t_list **stack_a, t_list **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
}

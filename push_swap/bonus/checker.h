/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:18:03 by albartol          #+#    #+#             */
/*   Updated: 2023/12/22 15:04:49 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"

void	ft_sort_manual(t_list **satck_a, t_list **satck_b);
int		ft_check_input(char *input, t_list **satck_a, t_list **satck_b);
void	ft_check_order(t_list **stack_a, t_list **stack_b);
int		ft_process_input(t_list *input, t_list **stack_a, t_list **stack_b);
void	ft_read_input(t_list **input);

// operaciones para los stacks
void	ft_sa_b(t_list **stack_a);
void	ft_sb_b(t_list **stack_b);
void	ft_ss_b(t_list **stack_a, t_list **stack_b);
void	ft_pa_b(t_list **stack_b, t_list **stack_a);
void	ft_pb_b(t_list **stack_a, t_list **stack_b);
void	ft_ra_b(t_list **stack_a);
void	ft_rb_b(t_list **stack_b);
void	ft_rr_b(t_list **stack_a, t_list **stack_b);
void	ft_rra_b(t_list **stack_a);
void	ft_rrb_b(t_list **stack_b);
void	ft_rrr_b(t_list **stack_a, t_list **stack_b);

#endif
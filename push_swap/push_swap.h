/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:24:22 by albartol          #+#    #+#             */
/*   Updated: 2023/12/26 16:24:32 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

// control de errores y creacion del stack
int		ft_perror(const char *str);
int		ft_error_atoi(const char *str, t_list **stack, int *nbr, char **array);
long	ft_atoi_l(const char *str);
t_list	*ft_create_stack(char **argv);
int		ft_check(char **argv);
int		ft_check_stack(t_list *stack);
int		ft_sorted(t_list *stack);
void	ft_free_split(char **split);
int		ft_clear(t_list *stack_a);

// operaciones base
int		ft_push(t_list **stack_o, t_list **stack_d);
int		ft_reverse(t_list **stack_o);
int		ft_rotate(t_list **stack_o);
int		ft_swap(t_list **stack_o);

// operaciones para los stacks
int		ft_sa(t_list **stack_a);
int		ft_sb(t_list **stack_b);
int		ft_ss(t_list **stack_a, t_list **stack_b);
int		ft_pa(t_list **stack_b, t_list **stack_a);
int		ft_pb(t_list **stack_a, t_list **stack_b);
int		ft_ra(t_list **stack_a);
int		ft_rb(t_list **stack_b);
int		ft_rr(t_list **stack_a, t_list **stack_b);
int		ft_rra(t_list **stack_a);
int		ft_rrb(t_list **stack_b);
int		ft_rrr(t_list **stack_a, t_list **stack_b);

// algoritmo
int		ft_sort(t_list **satck_a, t_list **satck_b, int argc);

// merge_sort array
void	ft_merge_sort(int *list, int i, int *list_order);

// ordenar el stack
void	ft_sort_small(t_list **stack_a, t_list **stack_b, int *list, int argc);
int		ft_sort_medium(t_list **stack_a, t_list **stack_b, int *list, int argc);
int		ft_sort_big(t_list **stack_a, t_list **stack_b, int *list, int argc);

// utils para sort medium y sort big
int		ft_find(t_list *stack_a, int *list, int argc, int chunk_l);
void	ft_chunk_med(t_list **stack_a, t_list **stack_b, int *val);
void	ft_chunk_big(t_list **stack_a, t_list **stack_b, int *val);
void	ft_med_merge(t_list **stack_a, t_list **stack_b, int *list, int i);

// ft_sort_small
void	ft_stack_sort(t_list **stack_a, t_list **stack_b, int *list, int i);
void	ft_stack_merge(t_list **stack_a, t_list **stack_b);
void	ft_sort_3(t_list **stack_a);

// ft_sort_medium
int		ft_med_sort(t_list **stack_a, t_list **stack_b, int *list, int argc);

// ft_sort_big
int		ft_big_sort(t_list **stack_a, t_list **stack_b, int *list, int argc);

#endif
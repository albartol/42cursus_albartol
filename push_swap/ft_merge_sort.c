/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:27:15 by albartol          #+#    #+#             */
/*   Updated: 2023/12/20 14:38:35 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_merge(int *list, int i, int n, int *list_order)
{
	int	j;
	int	m;
	int	end;
	int	middle;

	j = i;
	end = n;
	m = (n + i) / 2;
	middle = m;
	while (j < end)
	{
		if (i < middle && (m >= end || list[i] <= list[m]))
			list_order[j++] = list[i++];
		else
			list_order[j++] = list[m++];
	}
}

static void	ft_merge_split(int *list, int i, int n, int *list_order)
{
	int	m;

	if (n - i <= 1)
		return ;
	m = (n + i) / 2;
	ft_merge_split(list_order, i, m, list);
	ft_merge_split(list_order, m, n, list);
	ft_merge(list_order, i, n, list);
}

void	ft_merge_sort(int *list, int i, int *list_order)
{
	int	n;

	n = 0;
	while (i--)
	{
		list_order[n] = list[n];
		n++;
	}
	ft_merge_split(list, 0, n, list_order);
}

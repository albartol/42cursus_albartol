/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albartol <albartol@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:38:32 by albartol          #+#    #+#             */
/*   Updated: 2023/10/04 13:23:23 by albartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*tmp_list;
	void	*tmp;

	if (!lst || !f || !del)
		return (0);
	list = 0;
	while (lst)
	{
		tmp = f(lst->content);
		tmp_list = ft_lstnew(tmp);
		if (!tmp_list)
		{
			free(tmp);
			ft_lstclear(&list, del);
			return (0);
		}
		ft_lstadd_back(&list, tmp_list);
		lst = lst->next;
	}
	return (list);
}

/* t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*list;

	if (!lst)
		return (0);
	temp = ft_lstnew(f(lst->content));
	if (!temp)
	{
		ft_lstclear(&temp, del);
		return (0);
	}
	list = temp;
	while (lst->next)
	{
		lst = lst->next;
		list->next = ft_lstnew(f(lst->content));
		if (!list->next)
		{
			ft_lstclear(&temp, del);
			return (0);
		}
		list = list->next;
	}
	return (temp);
} */

/* t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*list;

	temp = (t_list *)malloc(sizeof(*temp));
	if (!temp)
		return (0);
	list = temp;
	list->next = 0;
	list->content = f(lst->content);
	lst = lst->next;
	while (lst)
	{
		list->next = (t_list *)malloc(sizeof(list));
		if (!list->next)
		{
			ft_lstclear(&temp, del);
			return (0);
		}
		list = list->next;
		list->next = 0;
		list->content = f(lst->content);
		lst = lst->next;
	}
	return (temp);
} */

/* #include <stdio.h>

int	main(void)
{
  t_list *l1;
  t_list *l2;
  t_list *l3;

  l1 = malloc(sizeof(l1));
  l2 = malloc(sizeof(l2));
  l3 = malloc(sizeof(l3));

  l1->content = 1;
  l1->next = l2;

  l2->content = 2;
  l2->next = l3;

  l3->content = 3;
  l3->next = NULL;

  t_list *res = ft_lstmap(l1,f,del);

  return (0);
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:54:39 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/14 12:23:48 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *node;

	if (!lst || !f)
		return (NULL);
	node = f(lst);
	head = node;
	while (lst->next)
	{
		lst = lst->next;
		if (!(node->next = f(lst)))
		{
			while (head)
			{
				node = head;
				free(node);
				head = head->next;
			}
			return (NULL);
		}
		node = node->next;
	}
	return (head);
}

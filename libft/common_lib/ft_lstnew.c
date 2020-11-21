/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:57:09 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/14 12:21:11 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		node->content_size = 0;
		node->content = NULL;
	}
	else
	{
		if (!(node->content = malloc(content_size)))
		{
			free(node);
			return (NULL);
		}
		ft_memccpy(node->content, content, 0, content_size);
		node->content_size = content_size;
	}
	node->next = NULL;
	return (node);
}

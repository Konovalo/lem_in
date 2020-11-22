/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:42:41 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/22 15:21:52 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLL_H
# define DLL_H
# include <stdlib.h>
typedef struct		s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	const void		*data;
}					t_node;

t_node				*dll_new_node(const void *data);
t_node				*dll_add_last(t_node **list, void *data);
void				*dll_peek_last(t_node *list);
t_node				*dll_add_first(t_node **list, void *data);
void				*dll_peek_first(t_node *list);
void				*dll_get_first(t_node **list);
void				*dll_get_last(t_node **list);
t_node				*dll_add_n(t_node **list, void *data, int n);
void				*dll_peek_n(t_node *list, int n);
void				*dll_get_n(t_node **list, int n);
t_node				*dll_push(t_node **list, void *data);
void				*dll_pop(t_node **list);
void				*dll_peek(t_node *list);
void				*dll_get(t_node **list);
int					dll_length(t_node *list);

#endif
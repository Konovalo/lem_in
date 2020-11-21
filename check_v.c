/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_v.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heantoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 14:41:08 by heantoni          #+#    #+#             */
/*   Updated: 2020/11/21 22:15:37 by heantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commons_structures.h"

void			init(t_read *read, int argc)
{
	read->n = 0;
	read->argc = argc;
	read->fd = 0;
	read->k = 0;
	read->ant = -1;
	read->v = NULL;
	read->tim = 0;
	read->time.s1 = NULL;
	read->time.s2 = NULL;
	read->time.s3 = NULL;
}

void			bfs_null(t_node **v_list)
{
	t_node		*klist;

	klist = *v_list;
	while (klist)
	{
		((t_vertex*)(klist->data))->bfs_level = 0;
		((t_vertex*)(klist->data))->visited = 0;
		klist = klist->next;
	}
}

void			sort_node(t_node **node)
{
	t_node		**new_node;
	t_node		*data_n;
	int			k;

	new_node = node;
	while ((*new_node)->next)
	{
		if (ft_ll_length((t_node*)(*new_node)->data) > \
				ft_ll_length((t_node*)((*new_node)->next)->data))
		{
			data_n = (t_node*)((*new_node)->next)->data;
			((*new_node)->next)->data = (*new_node)->data;
			(*new_node)->data = data_n;
			new_node = node;
		}
		else
			new_node = &((*new_node)->next);
	}
}

int				read_map(char **a, t_read *re, t_graph *graph)
{
	char		*line;
	t_node		*v_list;
	t_node		*e_list;

	line = NULL;
	v_list = NULL;
	e_list = NULL;
	if (re->argc == 2)
		re->fd = open(a[1], O_RDONLY);
	if (re->argc > 2 || re->fd < 0)
		return (-1);
	while (get_next_line(re->fd, &line) != 0)
	{
		if (cut_line(line, re, &v_list, &e_list) < 0)
		{
			free(line);
			return (0);
		}
		free(line);
	}
	if (re->argc == 2)
		close(re->fd);
	graph->vertex = v_list;
	graph->edges = e_list;
	return (0);
}

int				main(int argc, char *argv[])
{
	t_read		read;
	t_graph		graph;
	t_node		*paths;
	t_ant_node	*an;

	an = NULL;
	init(&read, argc);
	if (read_map(argv, &read, &graph) < 0)
		return (-1);
	bfs(&graph, &paths);
	zap_ant(&an, ft_ll_length(paths));
	poisk(&paths);
	sort_node(&paths);
	read.kol = read.ant;
	ants(&read, paths, an);
	print_ant(read, paths, an);
	free_mem(graph.vertex, graph.edges);
	free_mem_an(an);
	free_paths(paths);
	return (0);
}

//gcc check_v.c commons_structures.h libft/headers/ft_gnl.h libft/ft_gnl/ft_gnl.c -Ilibft/headers -Llibft -lft

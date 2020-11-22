/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 14:38:25 by aeclipso          #+#    #+#             */
/*   Updated: 2020/11/22 16:53:20 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "dll.h"
# include "libft.h"

# define FALSE	0
# define TRUE	1

/*
** Количество вершин. Присваивается при анализе входных данных.
*/

int g_vert_num;


/*
** Множество типов вершин.
*/

typedef enum s_vertex_type
{
	START, MIDDLE, END
} e_vertex_type;


/*
** Вершина графа.
**
** x, y - координаты;
** name - имя вершины;
** type - тип вершины;
** io - моделирование "задвоения" (in/out) вершины, содержит ссылки на 
** текущую вершину;
** f_io_direct - направленеи "ребара" между "задвоенными" вершинами,
** 0 - in->out. 1 - out->in.
** bfs_level - счётчик итераций алгоритма поиска в ширину;
** edges - список рёбер.
*/

typedef struct s_vertex
{
	int x;
	int y;
	char *name;
	e_vertex_type type;
	int bfs_level;
	int visited;
	t_node			*i_edges;
	int				k;
} t_vertex;

/*
** Ребро графа.
**
** vertex - ссылки на элементы массива io соотв вершины. Моделирование
** связей между "задвоенными" вершинами.
** f_edge_direct - направление ребра: 0 -  без направления, >0 - от вершины
** vertex[0] к вершине [1], <0 - в обратном направлении.
** visit_cout - счётчик проходов алгоритмом поиска пути по ребру.
*/

typedef struct s_edge
{
	t_vertex *vertex[2];
	int visit_count;
	
} t_edge;

typedef struct	s_graph
{
	t_node	*vertex;
	t_node		*edges;
} t_graph;

// взять, проерка на наличие start и end

typedef struct  s_time
{
    char			*s1;
    char			*s2;
    char			*s3;
	e_vertex_type   type;
}               t_time;

typedef struct  s_read
{
	t_time		time;
	int			len;
    int         n;
	int			argc;
    int         k;
	int			ant;
	t_vertex	*v;
	int			tim;
	int         fd;
	int			i;
	int			kol;
}               t_read;




typedef struct              s_ant_node
{
    int                     ant;
    struct s_ant_node       *next;
}                           t_ant_node;

/*
** Множество режимов работы алгоритма bfs
*/
typedef enum s_bfs_work_mode
{
	FIRST_ALG_PASS, SECOND_ALG_PASS
} e_bfs_work_mode;

typedef struct		s_temp
{
	t_vertex		*v1;
	t_vertex		*v2;
	t_vertex		*v3;
	t_vertex		*v4;
	int				kol;
}					t_temp;

/*
** Текущий режим работы алоритма bfs
*/
e_bfs_work_mode g_bfs_work_mode;


/*
**  ants.c
*/
void			ants2(t_node *et1, t_node *e, t_ant_node **ann, t_ant_node **an);
int				yslovee2(t_node *etog1, t_ant_node *an);
int				yslovee1(t_node *etog1, t_ant_node *an);
void			ants(t_read *read, t_node *etog, t_ant_node *ann);
/*
** bfs.c  prot!
*/
void			bfs_add_to_lists(t_node **queue, t_node **visited_vertexes, t_vertex *v);
void			bfs_clear_service(t_node	**list, t_node **queue);
void			return_trip(t_vertex *v, t_node **found_paths);
void			iterate_edges(t_vertex *curr_vert, t_node **queue, t_node **visited_vertexes);
void			free_visited_vertex(t_node	**list);
int				edge_get_opp_v1(t_edge *e, t_vertex *v);

/*
**  bfs.c
*/
void			bfs2(t_node **found_paths, t_node **visited_vertexes, \
		t_node **queue, t_vertex *sv);
void			bfs(t_graph *graph, t_node **found_paths);
void			return_trip2(t_node *curr_edge, t_vertex *v, \
		t_vertex *prev_vert, t_vertex **opp_vert);
void			return_trip(t_vertex *v, t_node **found_paths);
void			iterate_edges(t_vertex *curr_vert, t_node **queue, \
		t_node **visited_vertexes);

/*
** bfs2.c
*/
int				edge_get_opp_v1(t_edge *e, t_vertex *v);
void			free_visited_vertex(t_node **list);
void			zap_ant(t_ant_node **ant, int y);
void			bfs_add_to_lists(t_node **queue, t_node **visited_vertexes, \
		t_vertex *v);
void			bfs_clear_service(t_node **list, t_node **queue);

/*
** check_v.c
*/

void			init(t_read *read, int argc);
void			bfs_null(t_node **v_list);
void			sort_node(t_node **node);
int				read_map(char **a, t_read *re, t_graph *graph);

/*
** cut_line.c
*/

int				cut_line(char *line, t_read *read, t_node **v, t_node **e);
int				cut_line2(char *l, t_read *read, t_node **v_l, t_node **e_list);
int				cut_line7(char *l, t_read *read, t_node **v_l, t_node **e_list);
int				cut_line4(char *l, t_read **read);
int				cut_line5(char *l, t_read **read);

/*
** cut_line2.c
*/

int				check_cut(t_vertex **ver, t_time *time, t_read *read, \
		t_node **v_list);
int				cut_line3(char *line, t_read *re, t_node **v_list);

/*
** edge_list_operations.c
*/

t_node			*edge_list_add_all(t_node **node, t_edge *e);
t_node			*edge_list_add_first(t_node **node, t_edge *e);
t_ant_node		*ft_ll_add_last_an(t_ant_node **list, int k);
t_node			*vertex_list_add_last(t_node **list, t_vertex *v);
t_ant_node		*vertex_list_add_last_an(t_ant_node **list, int a);

/*
** edge_operations.c
*/

t_edge			*edge_create(t_vertex *v1, t_vertex *v2);
void			edge_reverse(t_edge *e);
t_vertex		*edge_get_opp_v(t_edge *e, t_vertex *v);

/*
** free_all.c
*/

void			free_vertex(t_vertex *vertex);
void			free_mem(t_node *v_list, t_node *e_list);
void			free_mem_an(t_ant_node *an);
void			free_paths(t_node *paths);

/*
** poisk.c
*/

int				poisk3(t_node *vrem2, t_node *vrem1);
void			poisk4(t_node *vrem2, t_node *vrem1);
void			poisk2(t_node **one, t_node *vrem1);
void			poisk(t_node **paths);

/*
** print_ant.c
*/

int				zap_print_ant(t_node **mass, int *ogi, t_ant_node *an, t_node *paths, t_read read);
void			print_ant(t_read read, t_node *paths, t_ant_node *an);

/*
** vertex_list_operations.c
*/

t_vertex		*vertex_list_get_first(t_node **list);
t_node			*vertex_list_push(t_node **stack, t_vertex *v);
t_vertex		*vertex_list_pop(t_node **stack);
t_node			*vertex_list_add_first(t_node **list, t_vertex *v);
t_ant_node		*ft_ll_new_node_an(int k);

/*
** vertex_operations.c 
*/

int				vertex_cmp_forked(t_vertex *v1, t_vertex *v2);
int				vertex_cmp2(t_vertex *v1, t_vertex *v2);
int				vertex_cmp(t_vertex *v1, t_vertex *v2);
t_vertex		*vertex_create(int x, int y, char *name, e_vertex_type type, int k);

/*
** zap_edge_two.c
*/

void			zap_edge8(t_node **e_list, t_vertex **v2, t_vertex **v4);
void			zap_edge7(t_node **e_list, t_vertex **v2, t_vertex **v3);
void			zap_edge6(t_node **e_list, t_vertex **v1, t_vertex **v4);
void			zap_edge5(t_node **e_list, t_vertex **v2, t_vertex **v3, t_vertex **v4);
void			zap_edge4(t_node **e_list, t_vertex **v1, t_vertex **v3, t_vertex **v4);

/*
** zap_edge_one.c
*/

void			zap_edge3(t_node **e_list, t_vertex **v1, t_vertex **v2, t_vertex **v3);
void			zap_edge2(t_node **e_list, t_vertex **v1, t_vertex **v2, t_vertex **v4);
int				zap_edge_ver(t_node **v_list, t_time  *time, t_temp *temp);
void			ini_temp( t_temp *temp);
int				zap_edge(t_node **v_list, t_node **e_list, t_time  *time);

/*
** zap_vertex.c
*/

e_vertex_type	zap_type(t_read **read);
int				v_n(char *str);
int				check(t_node **new_node, t_time *time);
int				zap_vertex(t_vertex **ver, t_time *time, t_read *read, t_node **v_list);

#endif
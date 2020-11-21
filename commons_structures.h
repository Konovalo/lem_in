#ifndef INC_21_SCHOOL_08_LEM_IN_COMMONS_STRUCTURES_H
#define INC_21_SCHOOL_08_LEM_IN_COMMONS_STRUCTURES_H

# include <stdlib.h>
# include "libft.h"
# include "ft_gnl.h"
# include "ft_printf.h"
# include <stddef.h>
# include <limits.h>
# include <fcntl.h>

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

typedef struct s_temp
{
	t_vertex        *v1;
    t_vertex        *v2;
    t_vertex        *v3;
    t_vertex        *v4;
	int				kol;
} t_temp;

/*
** Текущий режим работы алоритма bfs
*/
e_bfs_work_mode g_bfs_work_mode;

/* Для отладки. Релиз - УДАЛИТЬ*/
#include "vertex_operations.c"
#include "vertex_list_operations.c"
#include "edge_operations.c"
#include "edge_list_operations.c"
#include "bfs.c"
#include "print_ant.c"
#include "free_all.c"
#include "cut_line.c"
#include "ants.c"
#include "poisk.c"
#include "zap_vertex.c"
#include "zap_edge_one.c"
#include "zap_edge_two.c"
#include "bfs2.c"
#include "cut_line2.c"
/*УДАЛИТЬ*/ 

//void    sort_node(t_node **node);
//void    print_ant(t_read read, t_node *paths, t_ant_node *an);

#endif
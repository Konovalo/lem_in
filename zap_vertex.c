#include "commons_structures.h"

e_vertex_type   zap_type(t_read **read)
{
    e_vertex_type   type;

    if ((*read)->n == 1)
    {
        type = START;
        (*read)->n = 2;
    }
    else
    {
        if ((*read)->k == 1)
    {
        type = END;
        (*read)->k = 2;
    }
    else
        type = MIDDLE;
    }
    return (type);
}

int     v_n(char *str)
{
    int n;

    n = ft_atoi(str);
    if (ft_sizenbr(n) != ft_strlen(str))
        return (-1);
    return (1);
}

int     check(t_node **new_node, t_time *time)
{
    if (((t_vertex*)((*new_node)->data))->name && ft_strcmp(time->s1, ((t_vertex*)((*new_node)->data))->name) == 0)
            return (-1);
        if (((t_vertex*)((*new_node)->data))->name && (ft_atoi(time->s2) == ((t_vertex*)((*new_node)->data))->x) \
        && (ft_atoi(time->s3) == ((t_vertex*)((*new_node)->data))->y))
            return (-1);
    return (1);
}

int     zap_vertex(t_vertex **ver, t_time *time, t_read *read, t_node **v_list)
{
    t_node          **new_node;
     
    new_node = v_list;
    while ((*new_node))
    {
        if (check(new_node, time) < 0)
            return (-1);
        new_node = &((*new_node)->next);
    }
    read->time.type = zap_type(&read);
    if (read->time.type == START)
        read->v = vertex_create(ft_atoi(time->s2), ft_atoi(time->s3), time->s1, read->time.type, 0);
    if (read->time.type == END)
            vertex_list_add_first(v_list, vertex_create(ft_atoi(time->s2), ft_atoi(time->s3), time->s1, read->time.type, 1));
    if (read->time.type != START && read->time.type != END)
        {
            vertex_list_add_first(v_list, vertex_create(ft_atoi(time->s2), ft_atoi(time->s3), time->s1, read->time.type, 0));
            vertex_list_add_first(v_list, vertex_create(ft_atoi(time->s2), ft_atoi(time->s3), time->s1, read->time.type, 1));
        }
    //free(time->str1);
    //free(time->str2);
   //free(time->str3);
    //free(time);
    return (1);
}
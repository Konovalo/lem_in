#include "lemin.h"

void    zap_edge8(t_node **e_list, t_vertex **v2, t_vertex **v4);
void    zap_edge7(t_node **e_list, t_vertex **v2, t_vertex **v3);
void    zap_edge6(t_node **e_list, t_vertex **v1, t_vertex **v4);
void    zap_edge5(t_node **e_list, t_vertex **v2, t_vertex **v3, t_vertex **v4);
void    zap_edge4(t_node **e_list, t_vertex **v1, t_vertex **v3, t_vertex **v4);


void    zap_edge3(t_node **e_list, t_vertex **v1, t_vertex **v2, t_vertex **v3)
{
    t_edge          *e1 = NULL;
    t_edge          *e3 = NULL;

    e1 = edge_create((*v3), (*v1));
    e3 = edge_create((*v2), (*v3));
    edge_list_add_all(e_list, e1);
    edge_list_add_all(e_list, e3);
    edge_list_add_first(&((*v2)->i_edges), e3);
    edge_list_add_first(&((*v3)->i_edges), e3);
    edge_list_add_first(&((*v3)->i_edges), e1);
    edge_list_add_first(&((*v1)->i_edges), e1);
}


void    zap_edge2(t_node **e_list, t_vertex **v1, t_vertex **v2, t_vertex **v4)
{
    t_edge          *e1 = NULL;
    t_edge          *e3 = NULL;

    e1 = edge_create(*v1, *v4);
    e3 = edge_create(*v4, *v2);
    edge_list_add_all(e_list, e1);
    edge_list_add_all(e_list, e3);
    edge_list_add_first(&((*v4)->i_edges), e1);
    edge_list_add_first(&((*v4)->i_edges), e3);
    edge_list_add_first(&((*v1)->i_edges), e1);
    edge_list_add_first(&((*v2)->i_edges), e3);
}


int           zap_edge_ver(t_node **v_list, t_time  *time, t_temp *temp)
{
    int kol;

    kol = 0;
    t_node          **new_node;
     new_node = v_list;
    while ((*new_node) && kol < 4)
    {
         if (((t_vertex*)((*new_node)->data))->name)
            {
                if (ft_strcmp(time->s1, ((t_vertex*)((*new_node)->data))->name) == 0)
            {
                if (((t_vertex*)((*new_node)->data))->k == 0)
                    temp->v1 = (t_vertex*)((*new_node)->data);
                else
                    temp->v3 = (t_vertex*)((*new_node)->data);
                kol++;
            }
            else
            {
                if (ft_strcmp(time->s2, ((t_vertex*)((*new_node)->data))->name) == 0)
                {
                    if (((t_vertex*)((*new_node)->data))->k == 0)
                        temp->v2 = (t_vertex*)((*new_node)->data);
                    else
                        temp->v4 = (t_vertex*)((*new_node)->data);
                    kol++;
                }
            }
            }
        new_node = &((*new_node)->next);
    }
    //ft_strdel(&(time->str1));
    //ft_strdel(&(time->str2));
    return (kol);
}

void    ini_temp( t_temp    *temp)
{
    temp->v1 = (t_vertex*)NULL;
    temp->v2 = (t_vertex*)NULL;
    temp->v3 = (t_vertex*)NULL;
    temp->v4 = (t_vertex*)NULL;
}

int                 zap_edge(t_node **v_list, t_node **e_list, t_time  *time)
{
    t_temp          temp;

    ini_temp(&temp);
    if (zap_edge_ver(v_list, time, &temp) < 2)
        return (-1);
    if ((temp.v1 && temp.v2 && ft_strcmp(temp.v1->name, temp.v2->name) != 0) || (temp.v3 && temp.v2 && ft_strcmp(temp.v3->name, temp.v2->name) != 0) || (temp.v4 && temp.v1 && ft_strcmp(temp.v4->name, temp.v1->name) != 0))
    {
        if (temp.v1 && temp.v2 && temp.v1->type != START && temp.v2->type != START && temp.v4->type != END && temp.v3->type != END)
        {
            zap_edge6(e_list, &temp.v1, &temp.v4);
            zap_edge7(e_list, &temp.v2, &temp.v3);
            zap_edge8(e_list, &temp.v2, &temp.v4);
        }
        if (temp.v1 && temp.v2 && temp.v1->type == START && temp.v2->type != END)
            zap_edge2(e_list, &temp.v1, &temp.v2, &temp.v4);
        if (temp.v2 && temp.v1 && temp.v2->type == START && temp.v1->type != END)
            zap_edge3(e_list, &temp.v1, &temp.v2, &temp.v3);
        if (temp.v1 && temp.v4 && temp.v1->type != START && temp.v4->type == END)
            zap_edge4(e_list, &temp.v1, &temp.v3, &temp.v4);
        if (temp.v2 && temp.v3 && temp.v2->type != START && temp.v3->type == END)
             zap_edge5(e_list, &temp.v2, &temp.v3, &temp.v4);
    }
    return (1);
}
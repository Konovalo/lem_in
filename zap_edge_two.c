#include "lemin.h"

void    zap_edge8(t_node **e_list, t_vertex **v2, t_vertex **v4)
{
      t_edge          *e3 = NULL;
     e3 = edge_create((*v4), (*v2));
            edge_list_add_all(e_list, e3);
            edge_list_add_first(&((*v4)->i_edges), e3);
            edge_list_add_first(&((*v2)->i_edges), e3);
    //free(e3);
}

void    zap_edge7(t_node **e_list, t_vertex **v2, t_vertex **v3)
{
    t_edge          *e2 = NULL;

     e2 = edge_create((*v2), (*v3));
            edge_list_add_all(e_list, e2);
            edge_list_add_first(&((*v3)->i_edges), e2);
	        edge_list_add_first(&((*v2)->i_edges), e2);

}

void    zap_edge6(t_node **e_list, t_vertex **v1, t_vertex **v4)
{
    t_edge          *e1 = NULL;

     e1 = edge_create((*v1), (*v4));
 edge_list_add_all(e_list, e1);
 edge_list_add_first(&((*v1)->i_edges), e1);
 edge_list_add_first(&((*v4)->i_edges), e1);
}

void    zap_edge5(t_node **e_list, t_vertex **v2, t_vertex **v3, t_vertex **v4)
{
    t_edge          *e1 = NULL;
    t_edge          *e3 = NULL;

    e1 = edge_create((*v4), (*v2));
    e3 = edge_create((*v2), (*v3));
    edge_list_add_all(e_list, e1);
    edge_list_add_all(e_list, e3);
    edge_list_add_first(&((*v3)->i_edges), e3);
    edge_list_add_first(&((*v2)->i_edges), e3);
    edge_list_add_first(&((*v2)->i_edges), e1);
    edge_list_add_first(&((*v4)->i_edges), e1);
}


void    zap_edge4(t_node **e_list, t_vertex **v1, t_vertex **v3, t_vertex **v4)
{
    t_edge          *e1 = NULL;
    t_edge          *e3 = NULL;

    e1 = edge_create((*v3), (*v1));
    e3 = edge_create((*v1), (*v4));
    edge_list_add_all(e_list, e1);
    edge_list_add_all(e_list, e3);
    edge_list_add_first(&((*v3)->i_edges), e1);
    edge_list_add_first(&((*v1)->i_edges), e1);
    edge_list_add_first(&((*v1)->i_edges), e3);
    edge_list_add_first(&((*v4)->i_edges), e3);
}
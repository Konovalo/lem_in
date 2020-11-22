/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_line2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 22:51:22 by heantoni          #+#    #+#             */
/*   Updated: 2020/11/22 16:23:58 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int				check_cut(t_vertex **ver, t_time *time, t_read *read, \
		t_node **v_list)
{
	if (zap_vertex(ver, time, read, v_list) < 0)
	{
		ft_strdel(&(read->time.s2));
		ft_strdel(&(read->time.s3));
		return (-1);
	}
	return (0);
}

int				cut_line3(char *line, t_read *re, t_node **v_list)
{
	t_vertex	*ver;
	int			one;

	re->i++;
	one = re->i;
	while (re->i < re->len && line[re->i] != ' ')
		re->i++;
	if (re->i < re->len)
		line[re->i] = '\0';
	else
		return (-1);
	if ((!(re->time.s2 = ft_strdup(&line[one]))) || v_n(re->time.s2) < 0)
		return (-1);
	re->i++;
	if ((!(re->time.s3 = ft_strdup(&line[re->i]))) || v_n(re->time.s3) < 0)
		return (-1);
	if (re->len != ft_strlen(re->time.s1) + ft_strlen(re->time.s2) \
	+ ft_strlen(re->time.s3) + 2)
		return (-1);
	if (check_cut(&ver, &(re->time), re, v_list) < 0)
		return (-1);
	ft_strdel(&(re->time.s2));
	ft_strdel(&(re->time.s3));
	return (1);
}

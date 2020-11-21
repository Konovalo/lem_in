/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaozu <kchaozu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:46:46 by kchaozu           #+#    #+#             */
/*   Updated: 2019/12/07 15:46:52 by kchaozu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Обработка и вывод значения модификатора преобразования СТРОКА.
**
** Возврат: ссылка на конец буфера, NULL в случае неудачи записи.
*/

char	*put_str(const char *s)
{
	int	len;

	if (!s)
		s = NULL_STR;
	len = ft_strlen(s);
	if (g_conv.precision < 0)
		g_conv.precision = len;
	else if (g_conv.precision < len && g_conv.dotpresent)
		len = g_conv.precision;
	if (!buff_addstr(s, len))
		return (NULL);
	return (g_buff.ptr);
}

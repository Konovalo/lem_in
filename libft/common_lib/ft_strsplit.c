/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lronnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:06:07 by lronnet           #+#    #+#             */
/*   Updated: 2019/09/14 12:19:54 by lronnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cntwrd(const char *s, int c)
{
	int	cnt;

	cnt = 0;
	if (s)
	{
		while (*s)
		{
			while (*s == c)
				s++;
			if (*s)
			{
				while (*s && *s++ != c)
					;
				cnt++;
			}
		}
	}
	return (cnt);
}

static void	*deleteall(char ***res, int i)
{
	while (i > 0)
		free(*res[i--]);
	free(*res);
	return (NULL);
}

static char	*letsdoit(char *s, char c)
{
	while (*s == c)
		s++;
	return (s);
}

char		**ft_strsplit(char const *s, char c)
{
	int		len_w;
	int		i;
	char	*st_wrd;
	char	**res;

	if (!(res = (char **)malloc(sizeof(char *) * (cntwrd(s, c) + 1))))
		return (NULL);
	i = 0;
	while (s && *s)
	{
		len_w = 0;
		s = letsdoit((char *)s, c);
		if (*s)
		{
			st_wrd = (char *)s;
			while (*s && *s++ != c)
				len_w++;
			if (!(res[i] = (char *)malloc(sizeof(char) * (len_w + 1))))
				return (deleteall(&res, i));
			ft_strncpy(res[i], st_wrd, len_w);
			res[i++][len_w] = 0;
		}
	}
	res[i] = 0;
	return (res);
}

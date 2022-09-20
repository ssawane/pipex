/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawane <ssawane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:52:14 by ssawane           #+#    #+#             */
/*   Updated: 2022/01/09 15:00:32 by ssawane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	words(char *t, char c)
{
	int	sl;
	int	n;
	int	i;

	sl = 0;
	n = 0;
	i = 0;
	while (t[i])
	{
		if (t[i] != c && !n)
		{
			sl++;
			n = 1;
		}
		if (t[i] == c)
			n = 0;
		i++;
	}
	return (sl);
}

char	*record(char *t, int *start, int finish)
{
	char	*w;
	int		i;

	i = 0;
	w = malloc(sizeof(char) * (finish - *start + 1));
	while (*start < finish)
	{
		w[i] = t[*start];
		*start += 1;
		i++;
	}
	w[i] = '\0';
	*start = -1;
	return (w);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	int		n;
	int		j;

	i = 0;
	n = -1;
	j = 0;
	if (!s)
		return (NULL);
	str = malloc((words((char *)s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (i <= (size_t)ft_strlen((char *)s))
	{
		if (s[i] != c && n < 0)
			n = i;
		else if ((s[i] == c || i == (size_t)ft_strlen((char *)s)) && n >= 0)
		{
			str[j++] = record((char *)s, &n, i);
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

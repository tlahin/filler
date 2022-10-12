/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:11:27 by tlahin            #+#    #+#             */
/*   Updated: 2021/12/13 12:34:24 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

static char	*ft_getword(char *s, char c)
{
	char	*word;

	word = s;
	while (*s && *s != c)
		s++;
	*s = '\0';
	return (ft_strdup(word));
}

static void	ft_freewords(char **arr, size_t i)
{
	while (i--)
		ft_strdel(&(arr[i]));
	free(*arr);
}

static char	**ft_gatherwords(char *s, char c, size_t wordcount, char **arr)
{
	char	*word;
	size_t	i;

	i = 0;
	while (i < wordcount)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			word = ft_getword(s, c);
			if (!(word))
			{
				ft_freewords(arr, i);
				return (NULL);
			}
			arr[i++] = word;
			s += (ft_strlen(word) + 1);
		}
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**arr;
	char	*line;

	if (s == NULL)
		return (NULL);
	line = ft_strdup((char *)s);
	if (!s || !line)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (ft_wordcount(line, c) + 1));
	if (arr)
		arr = ft_gatherwords(line, c, ft_wordcount(line, c), arr);
	free(line);
	return (arr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:40:15 by tlahin            #+#    #+#             */
/*   Updated: 2021/12/07 15:00:02 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trimstart(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_trimend(char const *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (i > 0)
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			return (i);
		i--;
	}
	return (-1);
}

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*str;

	if (!s)
		return (NULL);
	start = ft_trimstart(s);
	end = ft_trimend(s);
	if (start == -1 || end == -1)
		return (ft_strnew(0));
	str = ft_strsub(s, start, end - start + 1);
	return (str);
}

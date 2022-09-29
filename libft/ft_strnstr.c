/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:12:50 by tlahin            #+#    #+#             */
/*   Updated: 2021/12/13 12:26:17 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;
	size_t	i;
	size_t	n;

	j = 0;
	i = 0;
	n = ft_strlen(needle);
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		if ((i + n) <= len && haystack[i] == needle[j])
			if (ft_strncmp(&haystack[i], needle, n) == 0)
				return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

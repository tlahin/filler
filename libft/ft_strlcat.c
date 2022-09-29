/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 15:12:05 by tlahin            #+#    #+#             */
/*   Updated: 2021/12/13 11:05:00 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*s;
	size_t	res;
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	res = 0;
	i = 0;
	s = (char *)src;
	if (size > dstlen)
		res = dstlen + srclen;
	else
		res = srclen + size;
	while ((dstlen + 1) < size && s[i])
	{
		dst[dstlen] = s[i];
		dstlen++;
		i++;
	}
	dst[dstlen] = '\0';
	return (res);
}

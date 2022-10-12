/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:55:51 by tlahin            #+#    #+#             */
/*   Updated: 2021/12/13 12:22:28 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (i < n && ((unsigned char *)s1)[i] && ((unsigned char *)s2)[i]
				&& ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
			i++;
		if (i == n)
			i--;
		if (((((unsigned char *)s1)[i] - ((unsigned char *)s2)[i])) == 0)
			return (1);
	}
	return (0);
}

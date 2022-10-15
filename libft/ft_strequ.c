/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:31:08 by tlahin            #+#    #+#             */
/*   Updated: 2021/12/13 12:55:24 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	i;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while (((unsigned char *)s1)[i] && ((unsigned char *)s2)[i]
				&& ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
			i++;
		if (((((unsigned char *)s1)[i] - ((unsigned char *)s2)[i])) == 0)
			return (1);
	}
	return (0);
}

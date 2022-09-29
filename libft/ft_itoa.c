/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:11:48 by tlahin            #+#    #+#             */
/*   Updated: 2022/05/09 17:13:53 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*to_str(char *str, int i, int len)
{
	while (i > 0)
	{
		str[len--] = (char) i % 10 + '0';
		i = i / 10;
	}
	return (str);
}

char	*ft_itoa(int i)
{
	char	*str;
	int		len;

	len = (int ) ft_intlen(i);
	str = (char *)malloc(sizeof(char) * ((size_t)len + 1));
	if (!(str))
		return (NULL);
	str[len--] = '\0';
	if (i == 0)
		str[0] = '0';
	if (i < 0)
	{
		if (i == -2147483648)
		{
			str[len--] = '8';
			i = i / 10;
		}
		i = -i;
		str[0] = '-';
	}
	str = to_str(str, i, len);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:40:43 by tlahin            #+#    #+#             */
/*   Updated: 2022/09/17 17:40:52 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen_max(uintmax_t number)
{
	int	len;

	len = 1;
	number /= 10;
	while (number > 0)
	{
		len++;
		number /= 10;
	}
	return (len);
}

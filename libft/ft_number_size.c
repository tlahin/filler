/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:39:11 by tlahin            #+#    #+#             */
/*   Updated: 2022/09/17 17:39:12 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_number_size(intmax_t number)
{
	int	len;

	if (number < 0)
		number *= -1;
	len = 1;
	number = number / 10;
	while (number > 0)
	{
		number /= 10;
		len++;
	}
	return (len);
}

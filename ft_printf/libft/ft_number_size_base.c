/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_size_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:38:55 by tlahin            #+#    #+#             */
/*   Updated: 2022/09/17 17:38:56 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_number_size_base(uintmax_t number, int base)
{
	int	len;

	len = 0;
	while (number)
	{
		number /= base;
		len++;
	}
	return (len);
}

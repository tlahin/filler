/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:32:58 by tlahin            #+#    #+#             */
/*   Updated: 2022/10/10 08:32:59 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_bankers(long double number, int prec)
{
	int			decider;
	long double	tmp;
	long long	even;

	tmp = number;
	while (prec-- > 0)
		tmp *= 10;
	even = (long long)tmp;
	tmp -= even;
	tmp *= 10;
	decider = (int)tmp;
	tmp -= decider;
	if (decider == 5 || decider == -5)
	{
		if ((even % 2 == 1 || even % 2 == -1) \
			|| (tmp > 0.0 || tmp < -0.0))
			return (1);
	}
	else if (decider > 5 || decider < -5)
		return (1);
	return (0);
}

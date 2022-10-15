/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:38:09 by tlahin            #+#    #+#             */
/*   Updated: 2022/09/17 17:38:11 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long double	ft_rounding(long double number, int prec)
{
	long double	rounding;
	int			i;

	i = 0;
	rounding = 0.5;
	if (number < 0)
		rounding *= -1;
	while (i++ < prec)
		rounding *= 0.10;
	return (rounding);
}

static char	*joining(char *whole, char *decimals)
{
	char	*joint;

	joint = ft_strjoin(whole, decimals);
	free(whole);
	free(decimals);
	return (joint);
}

static char	get_dot(char *decimals, char dot, int prec, int i)
{
	if (dot == '.' && prec > 0)
		decimals[i] = '.';
	else
		decimals[i] = '\0';
	return (decimals[i]);
}

static long double	ftoa_helper(long double number, int prec)
{
	if (prec >= 0)
	{
		if (ft_bankers(number, prec) == 1)
			number += ft_rounding(number, prec);
	}
	else
		number += 0;
	if (number < 0)
	{
		number *= -1;
	}
	return (number);
}

char	*ft_ftoa(long double number, int prec, char dot, int i)
{
	char				*joint;
	char				*whole;
	char				*decimals;
	unsigned long long	dec;

	if (prec == -1)
		prec = 6;
	number = ftoa_helper(number, prec);
	whole = ft_itoa_uintmax(number);
	dec = number;
	if (prec > 0)
		number -= dec;
	decimals = ft_strnew(prec + 1);
	decimals[i] = get_dot(decimals, dot, prec, i);
	i++;
	while (prec-- > 0)
	{
		number *= 10;
		dec = number;
		number -= dec;
		decimals[i++] = dec + '0';
	}
	joint = joining(whole, decimals);
	return (joint);
}

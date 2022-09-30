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
#include <stdio.h>

static long double	ft_rounding(long double number, int prec)
{
	long double	rounding;

	rounding = 0.5;
	if (number < 0)
		rounding *= -1;
	while (prec--)
		rounding *= 0.10;
	return (rounding);
}

static char	*joining(char *whole, char *dec_part)
{
	char	*joint;

	joint = ft_strjoin(whole, dec_part);
	free(whole);
	free(dec_part);
	return (joint);
}

static char	get_dot(char *dec_part, char dot, int prec, int i)
{
	if (dot == '.' && prec > 0)
		dec_part[i] = '.';
	else
		dec_part[i] = '\0';
	return (dec_part[i]);
}

static long double	ftoa_helper_1(long double number, int prec)
{
	if (prec >= 0)
	{
		number += ft_rounding(number, prec);
	}
	else
		number += 0;
	if (number < 0)
		number *= -1;
	return (number);
}

char	*ft_ftoa(long double number, int prec, char dot, int i)
{
	char				*joint;
	char				*whole;
	char				*dec_part;
	unsigned long long	dec;

	if (prec == -1)
		prec = 6;
	number = ftoa_helper_1(number, prec);
	whole = ft_itoa_uintmax(number);
	dec = number;
	if (prec > 0)
		number -= dec;
	dec_part = ft_strnew(prec + 1);
	dec_part[i] = get_dot(dec_part, dot, prec, i);
	i++;
	while (prec-- > 0)
	{
		number *= 10;
		dec = number;
		number -= dec;
		dec_part[i++] = dec + '0';
	}
	joint = joining(whole, dec_part);
	return (joint);
}

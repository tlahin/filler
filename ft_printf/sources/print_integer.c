/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:31:26 by tlahin            #+#    #+#             */
/*   Updated: 2022/09/15 12:31:28 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	*pre_length(t_data *info, intmax_t number)
{
	if (number >= 0)
	{
		if (info->prefix[1] == '+')
			info->get_plus = '+';
		else if (info->prefix[2] == ' ')
			info->get_plus = ' ';
		else
			info->get_plus = '\0';
	}
	else
		info->nega = true;
	if (number == 0)
		info->s_len += 1;
	else
		info->s_len += ft_number_size(number);
	return (info);
}

static int	zero_helper(t_data *info, int zero)
{
	if (info->prec >= 0 && info->prec >= info->s_len)
		zero = info->prec - info->s_len;
	else if (info->prec >= 0 && info->prec < info->s_len)
		zero = 0;
	else if (info->prec == -1)
	{
		zero = info->width - info->s_len;
		if (info->nega)
			zero -= 1;
		if (info->prefix[2] == ' ' && info->prefix[1] != '+' && !info->nega)
			zero -= 1;
	}
	if (info->prefix[1] == '+' && !info->nega && info->prec == -1)
		zero -= 1;
	return (zero);
}

static int	get_zero(t_data *info)
{
	int	zero;

	zero = 0;
	if (info->prefix[4] == '0' && info->prefix[0] != '-')
		zero = zero_helper(info, zero);
	else if (info->prefix[0] == '-' || info->prefix[4] != '0')
	{
		if (info->prec > 0 && info->prec > info->s_len)
			zero = info->prec - info->s_len;
	}
	return (zero);
}

t_data	*print_integer(t_data *info)
{
	long long	number;
	int			zero;

	number = cast_di(info);
	pre_length(info, number);
	if (number == 0 && info->prec == 0)
	{
		put_simple_di(info, number);
		return (info);
	}
	if (info->nega && number != (-9223372036854775807 - 1))
		number *= -1;
	zero = get_zero(info);
	if (info->get_plus != '\0' || info->nega)
		info->s_len += 1;
	put_di(info, zero);
	if (number == -9223372036854775807 - 1)
		max(info);
	else
		putnumbermax(number);
	if (info->prefix[0] == '-')
		print_alternative(info, ' ', info->width - zero - info->s_len);
	info->len += info->s_len;
	return (info);
}

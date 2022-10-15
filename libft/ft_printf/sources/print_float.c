/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:16:39 by tlahin            #+#    #+#             */
/*   Updated: 2022/09/17 17:16:40 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	collect_f(t_data *info, long double number, int not_empty)
{
	if (info->prec == 0 && info->prefix[3] == '#')
		not_empty++;
	if (number < 0 || (info->prefix[1] == '+' && number >= 0))
		not_empty++;
	else if (info->prefix[2] == ' ' && number >= 0)
		not_empty++;
	return (not_empty);
}

static void	put_f(t_data *info, long double number, int not_empty, \
					int zero)
{
	if (!info->prefix[0] && !info->prefix[4])
		print_alternative(info, ' ', info->width - not_empty);
	if (info->prefix[2] == ' ' && number >= 0 && \
			info->prefix[1] != '+')
		write(1, " ", 1);
	if (info->nega)
		write (1, "-", 1);
	if (number >= 0 && info->prefix[1] == '+')
		write (1, "+", 1);
	if (info->prefix[4] == '0' && zero >= 1)
		print_alternative(info, '0', zero);
}

t_data	*float_helper(t_data *info, long double number)
{
	if (number != number)
	{
		print_alternative(info, ' ', info->width - 3);
		ft_putstr("nan");
		info->len += 3;
		info->valid = false;
	}
	check_inf(info, number);
	if (number < 0)
	{
		info->nega = true;
	}
	return (info);
}

t_data	*print_float(t_data *info)
{
	long double	number;
	char		*flot;
	int			not_empty;
	int			zero;

	zero = 0;
	number = cast_flot(info);
	float_helper(info, number);
	if (info->valid == false)
		return (info);
	flot = ft_ftoa(number, info->prec, '.', info->j);
	not_empty = ft_strlen(flot);
	not_empty = collect_f(info, number, not_empty);
	if (!info->prefix[0] && info->width > info->prec && info->width > not_empty)
		zero = info->width - not_empty;
	put_f(info, number, not_empty, zero);
	ft_putstr(flot);
	if (info->prefix[3] && info->prec == 0)
		write(1, ".", 1);
	if (info->prefix[0] == '-')
		print_alternative(info, ' ', info->width - not_empty);
	info->len += not_empty;
	free(flot);
	return (info);
}

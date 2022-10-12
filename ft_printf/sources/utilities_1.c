/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:12:32 by tlahin            #+#    #+#             */
/*   Updated: 2022/09/17 17:12:34 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	inf_helper(t_data *info)
{
	if (info->prefix[2] == ' ' && info->prefix[4] == '0' \
		&& info->width == 0)
		print_alternative(info, ' ', 1);
	else if (info->prefix[1] == '+')
	{
		print_alternative(info, ' ', info->width - 4);
		print_alternative(info, '+', 1);
	}
	else
		print_alternative(info, ' ', info->width - 3);
	ft_putstr("inf");
	info->len += 3;
}

t_data	*check_inf(t_data *info, long double number)
{
	if (number == (-1.0 / 0.0) || number == (1.0 / 0.0))
	{
		if (number == (-1.0 / 0.0))
		{
			print_alternative(info, ' ', info->width - 4);
			ft_putstr("-inf");
			info->len += 4;
		}
		else if (number == (1.0 / 0.0))
			inf_helper(info);
		info->valid = false;
	}
	return (info);
}

void	put_simple_di(t_data *info, intmax_t number)
{
	if (number == 0 && info->prec == 0)
	{
		if (info->get_plus != '\0')
			info->width--;
		if (info->prefix[0] != '-')
			print_alternative(info, ' ', info->width);
		if (info->prefix[1] == '+')
			print_alternative(info, '+', 1);
		else if (info->prefix[2] == ' ')
			print_alternative(info, ' ', 1);
		if (info->prefix[1] == '-')
			print_alternative(info, ' ', info->width);
	}
}

void	put_di(t_data *info, int zero)
{
	if (info->prefix[0] != '-')
		print_alternative(info, ' ', info->width - zero - info->s_len);
	if (info->nega)
		write(1, "-", 1);
	if (info->get_plus != '\0')
	{
		write(1, &info->get_plus, 1);
	}
	print_alternative(info, '0', zero);
}

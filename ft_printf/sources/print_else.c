/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_else.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:21:37 by tlahin            #+#    #+#             */
/*   Updated: 2022/09/17 17:21:39 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*print_percent(t_data *info)
{
	if (info->prefix[4] == '0' && !info->prefix[0] && info->prec <= 0)
	{
		info->prec = info->width;
		info->width = 0;
	}
	if (info->prefix[0] != '-')
		print_alternative(info, ' ', info->width - 1);
	if (info->prefix[4] == '0')
		print_alternative(info, '0', info->prec - 1);
	write(1, "%", 1);
	if (info->prefix[0] == '-')
		print_alternative(info, ' ', info->width - 1);
	info->len += 1;
	return (info);
}

void	print_else(t_data *info)
{
	if (info->c_fmt[info->i] == '%')
		print_percent(info);
	else
		print_alternative(info, ' ', info->width - 1);
}

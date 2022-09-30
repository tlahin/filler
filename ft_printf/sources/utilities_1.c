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

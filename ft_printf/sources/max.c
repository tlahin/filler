/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:12:29 by tlahin            #+#    #+#             */
/*   Updated: 2022/09/16 13:12:31 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	max(t_data *info)
{
	put_max();
	info->s_len += 18;
}

void	put_max(void)
{
	write(1, "9223372036854775808", 19);
}

void	putnumbermax(intmax_t number)
{
	if (number > 9)
		putnumbermax(number / 10);
	ft_putchar(number % 10 + '0');
}

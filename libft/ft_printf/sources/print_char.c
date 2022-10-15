/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:30:36 by tlahin            #+#    #+#             */
/*   Updated: 2022/09/15 12:30:38 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*print_char(t_data *info)
{
	if (info->prefix[0] == '-' && info->width > 0 && \
		(info->prefix[4] == 0 || info->prefix[4] == '\0'))
	{
		ft_putchar(va_arg(info->args, int));
		info->len += 1;
		while (info->width - 1 >= 1)
		{
			print_alternative(info, ' ', 1);
			info->width--;
		}
	}
	else
	{
		while ((info->width -1) > 0)
		{
			print_alternative(info, ' ', 1);
			info->width--;
		}
		ft_putchar(va_arg(info->args, int));
		info->len += 1;
	}
	return (info);
}

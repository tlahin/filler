/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:26:42 by tlahin            #+#    #+#             */
/*   Updated: 2022/09/15 12:26:47 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*printer(t_data *info)
{
	char	*specifier;

	specifier = &info->specifier;
	if (ft_strchr("cspdiouxXf%", (int)info->srch_fmt[info->i]))
	{
		if (*specifier == 'c')
			print_char(info);
		else if (*specifier == 's')
			print_str(info);
		else if (*specifier == 'p')
			print_pointer(info);
		else if (*specifier == 'd' || *specifier == 'i' )
			print_integer(info);
		else if (*specifier == 'o')
			print_octal(info);
		else if (*specifier == 'x' || *specifier == 'X')
			print_hex(info);
		else if (*specifier == 'u')
			print_unsigned(info);
		else if (*specifier == 'f')
			print_float(info);
		else
			print_else(info);
	}
	return (info);
}

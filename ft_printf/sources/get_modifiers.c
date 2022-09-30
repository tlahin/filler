/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_modifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:17:42 by tlahin            #+#    #+#             */
/*   Updated: 2022/09/15 12:17:44 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*get_modifiers(t_data *info)
{
	info->i++;
	if (info->srch_fmt[info->i] != '\0')
		check_prefix(info);
	if (info->srch_fmt[info->i] != '\0')
		check_width(info);
	if (info->srch_fmt[info->i] != '\0')
		check_precision(info);
	if (info->srch_fmt[info->i] != '\0')
		check_argument(info);
	if (info->srch_fmt[info->i] != '\0')
		check_specifier(info);
	if (info->srch_fmt[info->i] != '\0')
		printer(info);
	return (info);
}

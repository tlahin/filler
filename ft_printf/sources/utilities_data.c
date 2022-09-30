/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:25:04 by tlahin            #+#    #+#             */
/*   Updated: 2022/09/15 12:25:06 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*reset_data(t_data *info)
{
	info->j = 0;
	info->nega = false;
	info->get_plus = '\0';
	info->specifier = '\0';
	info->prec = -1;
	info->width = 0;
	info->s_len = 0;
	info->prefix[0] = '\0';
	info->prefix[1] = '\0';
	info->prefix[2] = '\0';
	info->prefix[3] = '\0';
	info->prefix[4] = '\0';
	info->prefix[5] = '\0';
	info->length_flags[0] = '\0';
	info->length_flags[1] = '\0';
	info->length_flags[2] = '\0';
	return (info);
}

t_data	*init_data(t_data *info)
{
	info->i = 0;
	info->len = 0;
	info->padding = 0;
	info->s_len = 0;
	info->format_flags = "#0-+ ";
	info->arg_flags = "lhL";
	info->spec_flags = "cspdiouxXf%";
	info->hex_chars = "0123456789abcdef";
	info->c_fmt = (char *)info->fmt;
	info->srch_fmt = (char *)info->fmt;
	info->j = 0;
	info->valid = true;
	return (info);
}

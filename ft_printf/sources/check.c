/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:19:46 by tlahin            #+#    #+#             */
/*   Updated: 2022/09/15 12:20:17 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*check_precision(t_data *info)
{
	if (info->srch_fmt[info->i] == '.')
	{
		info->prec = 0;
		info->i++;
	}
	while (ft_isdigit(info->srch_fmt[info->i]))
	{
		info->prec *= 10;
		info->prec += (info->srch_fmt[info->i] - 48);
		info->i++;
	}
	return (info);
}

t_data	*check_argument(t_data *info)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (info->arg_flags[i] != '\0')
	{
		while (info->arg_flags[i] == info->srch_fmt[info->i])
		{
			info->length_flags[j] = info->srch_fmt[info->i];
			info->length_flags[j + 1] = '\0';
			j++;
			info->i++;
		}
		i++;
	}
	return (info);
}

t_data	*check_specifier(t_data *info)
{
	int	i;

	i = 0;
	while (info->spec_flags[i] != '\0')
	{
		if (info->srch_fmt[info->i] == info->spec_flags[i])
			info->specifier = info->srch_fmt[info->i];
		i++;
	}
	return (info);
}

t_data	*check_width(t_data *info)
{
	while (ft_isdigit(info->srch_fmt[info->i]))
	{
		info->width *= 10;
		info->width += (info->srch_fmt[info->i] - 48);
		info->i++;
	}
	return (info);
}

t_data	*check_prefix(t_data *info)
{
	size_t	i;

	i = 0;
	while (info->format_flags[i] != '\0')
	{
		while (info->format_flags[i] == info->srch_fmt[info->i])
		{
			if (info->srch_fmt[info->i] == '-')
				info->prefix[0] = '-';
			if (info->srch_fmt[info->i] == '+')
				info->prefix[1] = '+';
			if (info->srch_fmt[info->i] == ' ')
				info->prefix[2] = ' ';
			if (info->srch_fmt[info->i] == '#')
				info->prefix[3] = '#';
			if (info->srch_fmt[info->i] == '0')
				info->prefix[4] = '0';
			i = 0;
			info->i++;
		}
		i++;
	}
	return (info);
}

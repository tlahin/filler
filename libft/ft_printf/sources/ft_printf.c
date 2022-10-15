/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:43:16 by tlahin            #+#    #+#             */
/*   Updated: 2022/06/27 12:43:18 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	validate(t_data *info)
{
	int	i;

	i = info->i + 1;
	while (!ft_strchr("cspdiouxXf%", (int)info->c_fmt[i]))
		i++;
	if (info->c_fmt[i] != '\0')
		return (1);
	return (0);
}

static int	parse(t_data *info)
{
	int	valid;

	valid = -1;
	if (ft_strcmp(info->c_fmt, "%") == 0)
		return (0);
	while (info->c_fmt[info->i] != '\0')
	{
		if (info->c_fmt[info->i] == '%')
		{
			valid = validate(info);
			if (valid == 0)
				return (0);
			reset_data(info);
			get_modifiers(info);
		}
		else
		{
			write (1, &info->c_fmt[info->i], 1);
			info->len++;
		}
		info->i++;
	}
	return (info->len);
}

int	ft_printf(const char *format, ...)
{
	t_data	*info;

	info = (t_data *)malloc(sizeof(t_data));
	if (!info)
		return (0);
	info->fmt = format;
	info = init_data(info);
	if (format)
	{
		va_start(info->args, format);
		info->len = parse(info);
		va_end(info->args);
	}
	free(info);
	return (info->len);
}

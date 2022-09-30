/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:30:58 by tlahin            #+#    #+#             */
/*   Updated: 2022/09/15 12:30:59 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	octal_zero(t_data *info, uintmax_t number)
{
	if (info->prefix[3] == '#' && number)
		write(1, "0", 1);
}

static int	collect_o(t_data *info, uintmax_t number)
{
	int	not_empty;

	if (info->prefix[3] == '#' && number)
		info->s_len++;
	not_empty = info->s_len;
	if (info->prefix[4] == '0' && info->prec == -1 && info->prefix[0] != '-')
		info->prec = info->width;
	else if (info->prefix[0] == '-' && info->prefix[4] == '0'\
			&& info->prec == -1)
		info->prec = info->s_len;
	if (info->s_len <= info->prec && info->prec > 0)
		not_empty = info->prec;
	number += 0;
	return (not_empty);
}

static char	*octal_helper(t_data *info, uintmax_t number, char *tmp)
{
	if (number == 0)
		tmp = ft_strdup("0");
	else
		tmp = ft_itoa_base(number, 8);
	if (number == 0)
		info->s_len += 1;
	else
		info->s_len = ft_strlen(tmp);
	return (tmp);
}

t_data	*print_octal(t_data *info)
{
	char		*tmp;
	uintmax_t	number;
	int			not_empty;

	tmp = "";
	number = cast_xou(info);
	if (number == 0 && info->prec == 0 && info->prefix[3] != '#')
	{
		print_alternative(info, ' ', info->width);
		return (info);
	}
	tmp = octal_helper(info, number, tmp);
	not_empty = collect_o(info, number);
	if (info->prefix[0] != '-')
		print_alternative(info, ' ', info->width - not_empty);
	octal_zero(info, number);
	print_alternative(info, '0', info->prec - info->s_len);
	ft_putstr(tmp);
	if (info->prefix[0] == '-')
		print_alternative(info, ' ', info->width - not_empty);
	info->len += info->s_len;
	free(tmp);
	return (info);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:14:21 by tlahin            #+#    #+#             */
/*   Updated: 2022/09/17 17:14:26 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_u_0(t_data *info, uintmax_t number)
{
	if (number && number == 0)
		print_alternative(info, '0', 1);
}

static int	collect_u(t_data *info)
{
	int	not_empty;

	not_empty = info->s_len;
	if (info->prefix[4] == '0' && info->prec == -1 && info->prefix[3] != '-')
		info->prec = info->width;
	if (info->s_len <= info->prec && info->prec > 0)
		not_empty = info->prec;
	if (info->prefix[0] != '-')
		print_alternative(info, ' ', info->width - not_empty);
	return (not_empty);
}

static char	*unsigned_helper(uintmax_t number, char *tmp)
{
	if (number == 9223372036854775807)
		tmp = ft_strdup("9223372036854775807");
	else
	{
		if (number == 0)
			tmp = ft_strdup("0");
		else
			tmp = ft_itoa_uintmax(number);
	}
	return (tmp);
}

t_data	*print_unsigned(t_data *info)
{
	char		*tmp;
	uintmax_t	number;
	int			not_empty;

	tmp = "";
	number = cast_xou(info);
	if (number == 0 && info->prec == 0)
	{
		print_alternative(info, ' ', info->width);
		return (info);
	}
	tmp = unsigned_helper(number, tmp);
	if (number == 0)
		info->s_len += 1;
	else
		info->s_len += ft_strlen(tmp);
	not_empty = collect_u(info);
	print_u_0(info, number);
	print_alternative(info, '0', info->prec - info->s_len);
	ft_putstr(tmp);
	info->len += ft_strlen(tmp);
	if (info->prefix[0] == '-')
		print_alternative(info, ' ', info->width - not_empty);
	free(tmp);
	return (info);
}

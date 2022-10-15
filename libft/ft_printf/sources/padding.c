/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:22:24 by tlahin            #+#    #+#             */
/*   Updated: 2022/09/17 17:22:25 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*padding(t_data *info, int middle, int hash, uintmax_t number)
{
	int	prec;

	prec = info->prec;
	if (!number)
		info->padding = info->width - info->s_len - middle;
	else if (info->prefix[4] != '0' && prec == -1)
		info->padding = info->width - info->s_len - hash;
	else if (info->prefix[4] == '0' && prec != -1 && prec < info->s_len)
		info->padding = info->width - info->s_len - hash;
	else if (info->prefix[4] != '0' && info->prec != -1)
		info->padding = info->width - info->s_len - hash - middle;
	else if (info->prefix[4] == '0' && prec && prec > info->s_len)
		info->padding = info->width - prec - hash;
	else if (info->prefix[4] == '0' && info->prefix[0] == '-'\
			&& info->prec == -1)
		info->padding = info->width - info->s_len - hash - middle;
	else
		info->padding = 0;
	return (info);
}

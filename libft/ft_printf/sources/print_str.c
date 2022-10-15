/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:30:45 by tlahin            #+#    #+#             */
/*   Updated: 2022/09/15 12:30:47 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_data	*print_str(t_data *info)
{
	char	*tmp;
	int		len;

	tmp = va_arg(info->args, char *);
	if (info->prec == -1 && tmp)
		tmp = ft_strdup(tmp);
	else if (info->prec == -1 && !tmp)
		tmp = ft_strdup("(null)");
	else if (info->prec > -1 && tmp)
		tmp = ft_strndup(tmp, info->prec);
	else if (info->prec > -1 && !tmp)
		tmp = ft_strndup("(null)", info->prec);
	len = ft_strlen(tmp);
	if (info->prefix[0] != '-' && info->prefix[4] == '0')
		print_alternative(info, '0', info->width - len);
	else if (info->prefix[0] != '-')
		print_alternative(info, ' ', info->width - len);
	ft_putstr(tmp);
	if (info->prefix[0] == '-')
		print_alternative(info, ' ', info->width - len);
	info->len += ft_strlen(tmp);
	free(tmp);
	return (info);
}

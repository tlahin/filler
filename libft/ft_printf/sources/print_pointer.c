/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:31:55 by tlahin            #+#    #+#             */
/*   Updated: 2022/09/15 12:31:57 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	zeroer(t_data *info)
{
	int		zero;

	zero = 0;
	if (info->prefix[4] != '0')
	{
		if (info->prec > 0 && info->prec > info->s_len)
			zero = info->prec - info->s_len;
		else if (info->prec == -1 && info->width > info->s_len)
			zero = 0;
	}
	else if (info->prefix[4] == '0')
	{
		if (info->width > info->s_len && info->prec == -1)
			zero = info->width - info->s_len - 2;
		else if (info->width > info->s_len && info->prec > 0)
			zero = info->prec - info->s_len;
	}
	return (zero);
}

static t_data	*handle_str(t_data *info, char *tmp)
{
	if (info->prec == 0)
	{
		ft_putstr("\0");
		info->len--;
	}
	else
		ft_putstr(tmp);
	return (info);
}

static char	*pointer_helper(uintmax_t number, char *tmp)
{
	if (number == 0)
		tmp = ft_strdup("0");
	else
		tmp = ft_itoa_base(number, 16);
	return (tmp);
}

t_data	*print_pointer(t_data *info)
{
	char		*tmp;
	uintmax_t	number;
	int			zero;

	tmp = "";
	number = (unsigned long)va_arg(info->args, unsigned long int);
	number = (uintmax_t)number;
	tmp = pointer_helper(number, tmp);
	info->s_len = ft_strlen(tmp);
	zero = zeroer(info);
	if (info->prefix[0] != '-')
		print_alternative(info, ' ', info->width - info->s_len - zero - 2);
	write(1, "0x", 2);
	print_alternative(info, '0', zero);
	info->len += 2;
	handle_str(info, tmp);
	info->len += info->s_len;
	if (info->prefix[0] == '-')
		print_alternative(info, ' ', info->width - info->s_len - zero - 2);
	free(tmp);
	return (info);
}

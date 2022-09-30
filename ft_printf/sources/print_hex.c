/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:31:09 by tlahin            #+#    #+#             */
/*   Updated: 2022/09/15 12:31:11 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data	*print_0(t_data *info, char specifier, uintmax_t number)
{
	if (number && info->prefix[3] == '#')
	{
		if (specifier == 'X')
		{
			write(1, "0X", 2);
			info->len += 2;
		}
		else if (specifier == 'x')
		{
			write(1, "0x", 2);
			info->len += 2;
		}
	}
	return (info);
}

static void	put_hex(t_data *info, uintmax_t number, int middle, char *tmp)
{
	if (info->prefix[4] == '0' && info->width == 0 && number == 0)
		print_alternative(info, '0', 1);
	if (info->prefix[0] != '-')
		print_alternative(info, ' ', info->padding);
	print_0(info, info->specifier, number);
	print_alternative(info, '0', middle);
	if (info->specifier == 'X')
		ft_str_toupper(tmp);
	else
		ft_putstr(tmp);
	if (info->prefix[0] == '-')
		print_alternative(info, ' ', info->padding);
}

static int	collect_middle(t_data *info, uintmax_t number, int s_len, int hash)
{
	int		middle;
	int		prec;

	prec = info->prec;
	if (info->prefix[4] == '0' && prec == -1 && !number)
		middle = info->width - s_len;
	else if (!number && (prec == 0 || prec == -1))
		middle = 1;
	else if (info->prefix[4] == '0' && prec == -1)
		middle = info->width - s_len - hash;
	else if (info->prefix[4] == '0' && info->prefix[3] == '#' && prec != -1)
		middle = prec - s_len;
	else if (info->prefix[4] != '0' && prec && prec > s_len)
		middle = prec - s_len;
	else if (info->prefix[4] != '0' && prec == -1 && number)
		middle = 0;
	else
		middle = prec - s_len - hash;
	if (info->prefix[4] == '0' && info->prefix[0] == '-' && info->prec == -1)
		middle = 0;
	if (middle < 0)
		return (0);
	else
		return (middle);
}

t_data	*print_hex(t_data *info)
{
	char		*tmp;
	uintmax_t	number;
	int			middle;
	int			hash;

	hash = 0;
	number = cast_xou(info);
	if (number == 0 && info->prec == 0)
	{
		print_alternative(info, ' ', info->width);
		return (info);
	}
	tmp = ft_itoa_base(number, 16);
	if (number && info->prefix[3] == '#')
		hash = 2;
	info->s_len = ft_strlen(tmp);
	middle = collect_middle(info, number, info->s_len, hash);
	padding(info, middle, hash, number);
	put_hex(info, number, middle, tmp);
	info->len += info->s_len;
	free(tmp);
	return (info);
}

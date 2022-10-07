/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:52:13 by tlahin            #+#    #+#             */
/*   Updated: 2022/10/07 12:52:14 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	save_result(t_struct *data, int val, t_cords board, t_cords piece)
{
	data->hottest_val = val;
	data->result.row = board.row - piece.row;
	data->result.col = board.col - piece.col;
}

int	print(t_struct *data)
{
	if (data->hottest_val >= 0)
	{
		ft_printf("%d %d\n", data->result.row, data->result.col);
		return (0);
	}
	else
	{
		ft_printf("0 0\n");
		return (-1);
	}
}

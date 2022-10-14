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

void	save_result(t_struct *filler, int value, t_cords board, t_cords piece)
{
	filler->best_val = value;
	filler->result.row = board.row - piece.row;
	filler->result.col = board.col - piece.col;
}

int	print_result(t_struct *filler)
{
	if (filler->best_val >= 0)
	{
		ft_printf("%d %d\n", filler->result.row, filler->result.col);
		return (0);
	}
	else
	{
		ft_printf("0 0\n");
		return (-1);
	}
}

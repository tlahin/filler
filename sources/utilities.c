/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:13:46 by tlahin            #+#    #+#             */
/*   Updated: 2022/10/06 09:13:47 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_cords	get_offset(int row, int col, t_cords piece, t_cords board)
{
	t_cords	tmp;

	tmp.row = row + board.row - piece.row;
	tmp.col = col + board.col - piece.col;
	return (tmp);
}

static void	reset_points(t_struct *data)
{
	data->piece_start.row = -1;
	data->piece_start.col = -1;
	data->piece_end.row = -1;
	data->piece_end.col = -1;
}

void	find_borders(t_struct *data)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	reset_points(data);
	while (row < data->piece_size.row)
	{
		while (col < data->piece_size.col)
		{
			if (data->piece[row][col] == '*')
			{
				if (data->piece_start.row == -1)
					data->piece_start.row = row;
				if (data->piece_start.col == -1
					|| data->piece_start.col > col)
					data->piece_start.col = col;
				data->piece_end.row = row;
				if (data->piece_end.col < col)
					data->piece_end.col = col;
			}
			col++;
		}
		row++;
	}
}

bool	on_board(t_struct *data, int row, int col)
{
	if (row >= 0 && col >= 0
		&& row < data->board_size.row
		&& col < data->board_size.col)
		return (true);
	else
		return (false);
}

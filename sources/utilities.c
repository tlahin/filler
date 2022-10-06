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

static void	reset_points(t_struct *data)
{
	data->piece_start.rows = -1;
	data->piece_start.cols = -1;
	data->piece_end.rows = -1;
	data->piece_end.cols = -1;
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
				if (data->piece_start.rows == -1)
					data->piece_start.rows = row;
				if (data->piece_start.cols == -1
					|| data->piece_start.cols > col)
					data->piece_start.cols = col;
				data->piece_end.rows = row;
				if (data->piece_end.cols < col)
					data->piece_end.cols = col;
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
		return (true)
	else
		return (false);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:15:57 by tlahin            #+#    #+#             */
/*   Updated: 2022/10/06 10:15:58 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void place_piece(t_struct *data, t_cords board_cords)
{
	t_cords	piece_cords;
	int		piece_row;
	int		piece_col;
	int		tmp_value;

	piece_row = data->piece_start.row;
	piece_col = data->piece_end.col - 1;
	while (piece_row <= data->piece_end.row)
	{
		while (piece_col++ <= data->piece_end.col - 1)
		{
			if (data->piece[piece_row][piece_col] == '*')
			{
				piece_cords.row = piece_row;
				piece_cords.col = piece_col;
				data->connections = 0;
				data->tmp_val = 0;
				tmp_value = fit_piece(data, board_cords, piece_cords);
				if (tmp_value > 0
					&& (data->hottest_val == -1 || data->hottest_val > tmp_value))
					save_result(data, tmp_value, board_cords, piece_cords);
			}
		}
		piece_row++;
	}
}

static bool is_placeable(t_struct *data, int row, int col)
{
	int	x;
	int	y;

	if (info->board[row][col] != data->player)
		return (false);
	x = row - 1;
	y = col - 1;
	while (x <= row + 1)
	{
		while (y <= col + 1)
		{
			if (on_board(data, x, y)
				&& (x != row && y != col)
				&& data->board[x][y] == '.')
				return (true);
			y++;
		}
		x++;
	}
	return (false);
}

int	solve(t_struct *data)
{
	t_cords	tmp_cords;
	int		row;
	int		col;

	data->hottest_val = -1;
	row = 0;
	col = 0;
	while (row < data->board_size.row)
	{
		while (col < data->board_size.col)
		{
			tmp_cords.row = row;
			tmp_cords.col = col;
			if (data->board[row][col] == data->player
				&& is_placeable(data, row, col))
				put_piece(data, tmp_cords);
			col++;
		}
		row++;
	}
	return (0); //print_result(data)
}

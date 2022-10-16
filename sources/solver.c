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

/*
** Checks if the surrounding cordinates are empty
** and within the board limits.
*/

static bool	can_place(t_struct *filler, int row, int col)
{
	int	x;
	int	y;

	if (filler->board[row][col] != filler->player)
		return (false);
	x = row - 1;
	while (x <= row + 1)
	{
		y = col - 1;
		while (y <= col + 1)
		{
			if (on_board(filler, x, y)
				&& (x != row && y != col)
				&& filler->board[x][y] == '.')
				return (true);
			y++;
		}
		x++;
	}
	return (false);
}

static bool	invalid_point(t_struct *filler, int row, int col)
{
	return (!on_board(filler, row, col)
		|| !(filler->board[row][col] == filler->player
		|| filler->board[row][col] == '.'));
}

/*
** Checking if the piece fits on the board and is connected
** to the player, if so it returns the heatvalue found in the cordinates
*/

static int	fit_piece(t_struct *filler, t_cords board, t_cords piece)
{
	int		row;
	int		col;
	t_cords	temp;

	row = filler->piece_start.row - 1;
	while (row++ <= filler->piece_end.row - 1)
	{
		col = filler->piece_start.col - 1;
		while (col++ <= filler->piece_end.col - 1)
		{
			temp = calculate_offset(row, col, piece, board);
			if (filler->piece[row][col] == '*')
			{
				if (invalid_point(filler, temp.row, temp.col))
					return (-1);
				if (filler->board[temp.row][temp.col] == filler->player)
					filler->connections++;
				filler->tmp_val += filler->heatmap[temp.row][temp.col];
			}
		}
	}
	if (filler->connections == 1)
		return (filler->tmp_val);
	return (-1);
}

/*
** Using fit_piece function and find the best
** position for the piece by comparing heatvalues
*/

static void	place_piece(t_struct *filler, t_cords board_cords)
{
	int		piece_row;
	int		piece_col;
	int		temp_value;
	t_cords	piece_cords;

	piece_row = filler->piece_start.row;
	while (piece_row <= filler->piece_end.row)
	{
		piece_col = filler->piece_start.col - 1;
		while (piece_col++ <= filler->piece_end.col - 1)
		{
			if (filler->piece[piece_row][piece_col] == '*')
			{
				piece_cords.row = piece_row;
				piece_cords.col = piece_col;
				filler->connections = 0;
				filler->tmp_val = 0;
				temp_value = fit_piece(filler, board_cords, piece_cords);
				if (temp_value > 0
					&& (filler->hot_val == -1 || filler->hot_val > temp_value))
					save_result(filler, temp_value, board_cords, piece_cords);
			}
		}
		piece_row++;
	}
}

/*
** Loops through the whole board,
** checking if the spot is connected to the player
** and that it is a valid place for the given piece.
** If so, it places the piece on the board and prints
** the cordinates saved in the struct
*/

int	solve(t_struct *filler)
{
	int		row;
	int		col;
	t_cords	temp_cord;

	filler->hot_val = -1;
	row = 0;
	while (row < filler->board_size.rows)
	{
		col = 0;
		while (col < filler->board_size.cols)
		{
			temp_cord.row = row;
			temp_cord.col = col;
			if (filler->board[row][col] == filler->player
				&& can_place(filler, row, col))
				place_piece(filler, temp_cord);
			col++;
		}
		row++;
	}
	return (print_result(filler));
}

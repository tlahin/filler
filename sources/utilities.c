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

t_cords	calculate_offset(int row, int col, t_cords piece, t_cords board)
{
	t_cords	tmp;

	tmp.row = row + board.row - piece.row;
	tmp.col = col + board.col - piece.col;
	return (tmp);
}

static void	reset_points(t_struct *filler)
{
	filler->piece_start.row = -1;
	filler->piece_start.col = -1;
	filler->piece_end.row = -1;
	filler->piece_end.col = -1;
}

void	find_borders(t_struct *filler)
{
	int	row;
	int	col;

	reset_points(filler);
	row = 0;
	while (row < filler->piece_size.rows)
	{
		col = 0;
		while (col < filler->piece_size.cols)
		{
			if (filler->piece[row][col] == '*')
			{
				if (filler->piece_start.row == -1)
					filler->piece_start.row = row;
				if (filler->piece_start.col == -1
					|| filler->piece_start.col > col)
					filler->piece_start.col = col;
				filler->piece_end.row = row;
				if (filler->piece_end.col < col)
					filler->piece_end.col = col;
			}
			col++;
		}
		row++;
	}
}

char	parse_char(char c)
{
	if (c == 'x')
		return ('X');
	else if (c == 'o')
		return ('O');
	else
		return (c);
}

bool	on_board(t_struct *filler, int row, int col)
{
	return (row >= 0 && col >= 0
		&& row < filler->board_size.rows
		&& col < filler->board_size.cols);
}

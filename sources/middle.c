/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   middle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:37:11 by tlahin            #+#    #+#             */
/*   Updated: 2022/10/06 09:37:12 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	update_middles(t_struct *filler)
{
	filler->middle_captured = middle_is_captured(filler);
	filler->middle_row_captured = middle_row_is_captured(filler);
}

/*
** Checks if the middle space is taken or not
*/

bool	middle_is_captured(t_struct *filler)
{
	int	row;
	int	col;

	row = filler->board_size.rows / 2;
	col = filler->board_size.cols / 2;
	while (row <= filler->board_size.rows / 2 + 1)
	{
		while (col <= filler->board_size.cols / 2 + 1)
		{
			if (filler->board[row][col] != '.')
				return (true);
			col++;
		}
		row++;
	}
	return (false);
}

/*
** Checks if middle row has pieces that belong to the player
*/

bool	middle_row_is_captured(t_struct *filler)
{
	int	row;
	int	col;

	row = filler->board_size.rows / 2;
	col = 0;
	while (col < filler->board_size.cols)
	{
		if (filler->board[row][col] == filler->player)
			return (true);
		col++;
	}
	return (false);
}

int	distance_to_middle(t_struct *filler, int row, int col)
{
	int	middle_row;
	int	middle_col;

	middle_row = filler->board_size.rows / 2;
	middle_col = filler->board_size.cols / 2;
	return (ft_abs(middle_row - row) + ft_abs(middle_col - col));
}

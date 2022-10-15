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

void	update_centers(t_struct *filler)
{
	filler->center_captured = center_is_captured(filler);
	filler->center_row_captured = center_row_is_captured(filler);
}

/*
** Checks if the middle space is taken or not
*/

bool	center_is_captured(t_struct *filler)
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

bool	center_row_is_captured(t_struct *filler)
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

int	distance_to_center(t_struct *filler, int row, int col)
{
	int	center_row;
	int	center_col;

	center_row = filler->board_size.rows / 2;
	center_col = filler->board_size.cols / 2;
	return (ft_abs(center_row - row) + ft_abs(center_col - col));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:13:34 by tlahin            #+#    #+#             */
/*   Updated: 2022/10/06 09:13:35 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	reset_heatmap(t_struct *filler)
{
	int	row;
	int	col;

	row = 0;
	while (row < filler->board_size.rows)
	{
		col = 0;
		while (col < filler->board_size.cols)
		{
			if (filler->board[row][col] == filler->enemy)
				filler->heatmap[row][col] = 0;
			else
				filler->heatmap[row][col] = -1;
			col++;
		}
		row++;
	}
}

static void	set_neighbours(t_struct *filler, int depth, int row, int col)
{
	int	x;
	int	y;

	x = row - 1;
	while (x <= row + 1)
	{
		y = col - 1;
		while (y <= col + 1)
		{
			if (x > 0 && x < filler->board_size.rows
				&& y > 0 && y < filler->board_size.cols
				&& (x != row && y != col)
				&& filler->heatmap[x][y] == -1)
				filler->heatmap[x][y] = depth;
			y++;
		}
		x++;
	}
}

static void	set_heatmap(t_struct *filler, int depth)
{
	int	row;
	int	col;

	row = 0;
	while (row < filler->board_size.rows)
	{
		col = 0;
		while (col < filler->board_size.cols)
		{
			if (filler->heatmap[row][col] == depth)
				set_neighbours(filler, depth + 1, row, col);
			col++;
		}
		row++;
	}
}

static void	go_to_center(t_struct *filler)
{
	int	row;
	int	col;

	row = 0;
	while (row < filler->board_size.rows)
	{
		col = 0;
		while (col < filler->board_size.cols)
		{
			if (filler->center_row_captured)
				filler->heatmap[row][col] = distance_to_center(filler, row, col);
			else
				filler->heatmap[row][col] = \
				ft_abs(filler->board_size.rows / 2 - row);
			col++;
		}
		row++;
	}
}

void	update_heatmap(t_struct *filler)
{
	int	depth;

	if (!filler->center_captured)
		go_to_center(filler);
	else
	{
		reset_heatmap(filler);
		depth = 0;
		while (depth < filler->board_size.rows + filler->board_size.cols)
		{
			set_heatmap(filler, depth);
			depth++;
		}
	}
}

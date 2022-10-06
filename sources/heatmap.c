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

static void	set_near(t_struct *data, int heat, int row, int col)
{
	int	x;
	int	y;

	x = row - 1;
	y = col - 1;
	while (x <= row + 1)
	{
		while (y <= col + 1)
		{
			if (x > 0 && x < data->board_size.row
				&& y > 0 && y < data->board_size.col
				&& (x != row && y != col)
				&& data->heatmap[x][y] == -1)
				data->heatmap[x][y] = heat;
			y++;
		}
		x++;
	}
}

static void	set_heatmap(t_struct *data, int heat)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < data->board_size.row)
	{
		while (col < data->board_size.col)
		{
			if (data->heatmap[row][col] == heat)
				set_near(data, heat + 1, row, col);
			col++;
		}
		row++;
	}
}

static void	reset_heatmap(t_struct *data)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < data->board_size.row)
	{
		while (col < data->board_size.col)
		{
			if (data->board[row][col] == data->enemy)
				data->heatmap[row][col] = 0;
			else
				data->heatmap[row][col] = -1;
			col++;
		}
		row++;
	}
}

static void	get_middle(t_struct *data)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < data->board_size.row)
	{
		while (col < data->board_size.col)
		{
			if (data->board_size.col)
				data->heatmap[row][col] = distance_to_middle(data, row, col);
			else
				data->heatmap[row][col] = ft_abs(data->board_size.row \
				/ 2 - row);
			col++;
		}
		row++;
	}
}

void	update_heatmap(t_struct *data)
{
	int	heat;

	heat = 0;
	if (!data->middle_taken)
		get_middle(data);
	else
	{
		reset_heatmap(data);
		while (heat < data->board_size.row + data->board_size.col)
		{
			set_heatmap(data, heat);
			heat++;
		}
	}
}

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

void	update_middle(t_struct *data)
{
	data->middle_taken = is_middle_taken(data);
	data->middle_row_taken = is_middle_row_taken(data);
}

bool	is_middle_taken(t_struct *data)
{
	int	row;
	int	col;

	row = data->board_size.rows / 2;
	col = data->board_size.cols / 2;
	while (row <= data->board_size.rows / 2 + 1)
	{
		while (col <= data->board_size.cols / 2 + 1)
		{
			if (data->board[row][col] != '.')
				return (true);
			col++;
		}
		row++;
	}
	return (false);
}

bool	is_middle_row_taken(t_struct *data)
{
	int	row;
	int	col;

	row = data->board_size.rows / 2;
	col = 0;
	while (col < data->board_size.cols)
	{
		if (data->board[row][col] == data->player)
			return (true);
		col++;
	}
	return (false);
}

int	distance_to_middle(t_struct *data, int row, int col)
{
	int	middle_row;
	int	middle_col;

	middle_row = data->board_size.rows / 2;
	middle_col = data->board_size.cols / 2;
	return (ft_abs(middle_row - row) + ft_abs(middle_col - col));
}

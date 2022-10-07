/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:14:02 by tlahin            #+#    #+#             */
/*   Updated: 2022/10/06 09:14:04 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	number_parser(char last)
{
	char	tmp;
	int		nbr;

	tmp = last;
	nbr = 0;
	while (ft_isdigit(tmp))
	{
		nbr = nbr * 10 + (tmp - '0');
		if (read(0, &tmp, 1) < 0)
			return (-1);
	}
	return (nbr);
}

int	size_parser(int *row, int *col)
{
	char	tmp;
	int		state;

	tmp = '#';
	state = 1;
	while (!ft_isdigit(tmp) && state > 0)
		state = read(0, &tmp, 1);
	*row = number_parser(tmp);
	state = read(0, &tmp, 1);
	while (!ft_isdigit(tmp) && state > 0)
		state = read(0, &tmp, 1);
	*col = number_parser(tmp);
	if (*row <= 0 || *col <= 0 || state == -1)
		return (-1);
	return (0);
}

int	piece_parser(t_struct *data)
{
	char	tmp[1];
	int		row;
	int		col;

	row = 0;
	col = 0;
	if (size_parser(&data->piece_size.row, &data->piece_size.col) == -1)
		return (-1);
	data->piece = make_char_arr(data->piece_size.row, \
		data->piece_size.col);
	if (!data->piece)
		return (-1);
	while (row < data->piece_size.row)
	{
		while (col < data->piece_size.col)
		{
			if (read(0, tmp, 1) == -1)
				return (-1);
			if (ft_strchr("*.", tmp[0]))
				data->piece[row][col++] = tmp[0];
		}
		row++;
	}
	find_borders(data);
	return (0);
}

int	board_parser(t_struct *data)
{
	char	tmp[1];
	int		row;
	int		col;

	row = 0;
	col = 0;
	while (row < data->board_size.row)
	{
		while (col < data->board_size.col)
		{
			if (read(0, tmp, 1) == -1)
				return (-1);
			if (ft_strchr("XOxo.", tmp[0]))
			{
				data->board[row][col] = ft_toupper(tmp[0]);
				//char_parser(tmp[0]);
				col++;
			}
		}
		row++;
	}
	update_middle(data);
	return (0);
}

int	player_parser(t_struct *data)
{
	char	tmp;

	tmp = '#';
	while (!ft_isdigit(tmp))
	{
		if (read(0, &tmp, 1) < 0)
			return (-1);
	}
	if (tmp == '1')
	{
		data->player = 'O';
		data->enemy = 'X';
	}
	else if (tmp == '2')
	{
		data->player = 'X';
		data->enemy = 'O';
	}
	else
		return (-1);
	return (0);
}

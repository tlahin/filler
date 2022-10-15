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

/*
** Input is converted into a integer, if the number has multiple digits,
** we read more and go through the loop and thus getting the full "number"
*/

int	parse_number(char last)
{
	char	temp;
	int		n;

	temp = last;
	n = 0;
	while (ft_isdigit(temp))
	{
		n = n * 10 + (temp - '0');
		if (read(0, &temp, 1) < 0)
			return (-1);
	}
	return (n);
}

/*
** Reading a character at a time till we find a digit,
** seeing if I am a player 1 or player 2 and set
** player variables accordingly
*/

int	parse_player(t_struct *filler)
{
	char	temp;

	temp = '$';
	while (!ft_isdigit(temp))
	{
		if (read(0, &temp, 1) < 0)
			return (-1);
	}
	if (temp == '1')
	{
		filler->player = 'O';
		filler->enemy = 'X';
	}
	else if (temp == '2')
	{
		filler->player = 'X';
		filler->enemy = 'O';
	}
	else
		return (-1);
	return (0);
}

/*
** Reading untill a digit is found and
** save it into a rows variable aka height,
** same operation is done to get the cols value aka width
*/

int	parse_size(int *rows, int *cols)
{
	char	temp;
	int		status;

	temp = ',';
	status = 1;
	while (!ft_isdigit(temp) && status > 0)
		status = read(0, &temp, 1);
	*rows = parse_number(temp);
	status = read(0, &temp, 1);
	while (!ft_isdigit(temp) && status > 0)
		status = read(0, &temp, 1);
	*cols = parse_number(temp);
	if (*rows <= 0 || *cols <= 0 || status == -1)
		return (-1);
	return (0);
}

/*
** Loops throught the whole board and validates the contents
*/

int	parse_board(t_struct *filler)
{
	int		row;
	int		column;
	char	temp[1];

	row = 0;
	while (row < filler->board_size.rows)
	{
		column = 0;
		while (column < filler->board_size.cols)
		{
			if (read(0, temp, 1) == -1)
				return (-1);
			if (ft_strchr("XxOo.", temp[0]))
			{
				filler->board[row][column] = parse_char(temp[0]);
				column++;
			}
		}
		row++;
	}
	update_centers(filler);
	return (0);
}

/*
** Gets the piece size and validates its contents
*/

int	parse_piece(t_struct *filler)
{
	int		row;
	int		column;
	char	temp[1];

	if (parse_size(&filler->piece_size.rows, &filler->piece_size.cols) == -1)
		return (-1);
	filler->piece = create_char_array(filler->piece_size.rows, \
		filler->piece_size.cols);
	if (!filler->piece)
		return (-1);
	row = 0;
	while (row < filler->piece_size.rows)
	{
		column = 0;
		while (column < filler->piece_size.cols)
		{
			if (read(0, temp, 1) == -1)
				return (-1);
			if (ft_strchr("*.", temp[0]))
				filler->piece[row][column++] = temp[0];
		}
		row++;
	}
	find_borders(filler);
	return (0);
}

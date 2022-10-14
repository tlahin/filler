/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:19:16 by tlahin            #+#    #+#             */
/*   Updated: 2022/10/03 13:19:17 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Initializing all the variables in the struct
** and create both board and heatmap arrays
*/

int	init__filler(t_struct *filler)
{
	ft_bzero(filler, sizeof(*filler));
	if (parse_player(filler) == -1 \
		|| parse_size(&filler->board_size.rows, &filler->board_size.cols) == -1)
		return (-1);
	filler->board = create_char_array(filler->board_size.rows, \
		filler->board_size.cols);
	filler->heatmap = create_int_array(filler);
	if (!filler->heatmap || !filler->board)
		return (-1);
	return (0);
}

/*
** Frees the both char and int arrays
*/

int	free_stuff(t_struct *filler, int ret)
{
	if (filler->board)
		free_char_array(filler->board);
	if (filler->heatmap)
		free_int_array(filler->heatmap, filler);
	return (ret);
}

int	main(void)
{
	t_struct	filler;
	int			state;

	state = 1;
	if (init__filler(&filler) == -1)
		return (free_stuff(&filler, -1));
	while (state >= 0)
	{
		if (parse_board(&filler) == 0 && parse_piece(&filler) == 0)
		{
			update_heatmap(&filler);
			state = solve(&filler);
			free_char_array(filler.piece);
		}
		else
			state = -1;
	}
	return (free_stuff(&filler, state));
}

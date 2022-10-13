/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:21:19 by tlahin            #+#    #+#             */
/*   Updated: 2022/10/03 13:21:21 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../ft_printf/includes/ft_printf.h"
# include <stdio.h>

/*
** Structures
*/

typedef struct s_size
{
	int			rows;
	int			cols;
}				t_size;

typedef struct s_cords
{
	int			row;
	int			col;
}				t_cords;

typedef struct s_struct
{
	t_size		board_size;
	t_size		piece_size;
	char		enemy;
	char		player;
	char		**board;
	int			**heatmap;
	char		**piece;
	t_cords		board_cords;
	t_cords		piece_cords;
	int			hottest_val;
	int			tmp_val;
	int			connections;
	t_cords		result;
	int			row_dir;
	int			col_dir;
	t_cords		piece_start;
	t_cords		piece_end;
	bool		middle_taken;
	bool		middle_row_taken;
}				t_struct;

/*
** Main and arrs
*/

int		main(void);
char	**make_char_arr(int rows, int cols);
int		**make_int_arr(t_struct *data);
void	free_char_arr(char **arr);
void	free_int_arr(int **arr, t_struct *data);

/*
** Parsers
*/

int		number_parser(char last);
int		size_parser(int *row, int *col);
int		piece_parser(t_struct *data);
int		board_parser(t_struct *data);
int		player_parser(t_struct *data);
char	char_parser(char c);

/*
** Heatmap
*/

void	update_heatmap(t_struct *data);

/*
** Middles
*/

bool	is_middle_row_taken(t_struct *data);
bool	is_middle_taken(t_struct *data);
void	update_middle(t_struct *data);
int		distance_to_middle(t_struct *data, int row, int col);

/*
** Utilities
*/

t_cords	get_offset(int row, int col, t_cords piece, t_cords board);
bool	on_board(t_struct *data, int row, int col);
void	find_borders(t_struct *data);

/*
** Solver
*/

int		solve(t_struct *data);

/*
** Printter
*/

int		print(t_struct *data);
void	save_result(t_struct *data, int val, t_cords board, t_cords piece);

#endif

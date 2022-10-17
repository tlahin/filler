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

# include "../libft/libft.h"
# include "../libft/ft_printf/includes/ft_printf.h"

/*
** Structures
*/

typedef struct s_size
{
	int			rows;
	int			cols;
}	t_size;

typedef struct s_cords
{
	int			row;
	int			col;
}	t_cords;

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
	int			hot_val;
	int			tmp_val;
	int			connections;
	t_cords		result;
	int			row_dir;
	int			col_dir;
	t_cords		piece_start;
	t_cords		piece_end;
	bool		center_captured;
	bool		center_row_captured;
}	t_struct;

/*
** Main and arrays
*/

int		main(void);
char	**create_char_array(int rows, int cols);
int		**create_int_array(t_struct *data);
void	free_char_array(char **arr);
void	free_int_array(int **arr, t_struct *data);

/*
** Parsers
*/

int		parse_number(char last);
int		parse_size(int *row, int *col);
int		parse_piece(t_struct *data);
int		parse_board(t_struct *data);
int		parse_player(t_struct *data);

/*
** Heatmap
*/

void	update_heatmap(t_struct *data);

/*
** Middles
*/

bool	center_row_is_captured(t_struct *data);
bool	center_is_captured(t_struct *data);
void	update_centers(t_struct *data);
int		distance_to_center(t_struct *data, int row, int col);

/*
** Utilities
*/

t_cords	calculate_offset(int row, int col, t_cords piece, t_cords board);
bool	on_board(t_struct *data, int row, int col);
void	find_borders(t_struct *data);
char	parse_char(char c);

/*
** Solver
*/

int		solve(t_struct *data);

/*
** Printter
*/

void	save_result(t_struct *data, int val, t_cords board, t_cords piece);
int		print_result(t_struct *data);

#endif

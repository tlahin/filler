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
# include <stdio.h> //?

int main(void);

typedef struct  s_size
{
    int         row;
    int         col;
}               t_size;

typedef struct  s_cords
{
    int         rows;
    int         cols;
}               t_cords;

typedef struct  s_struct
{
    t_size      board_size;
    t_size      piece_size;
    char        enemy;
    char        player;
    char        **board;
    char        **heatmap;
    char        **piece;
    t_cords     board_cords;
    t_cords     piece_cords;
    int         hottest_val;
    int         tmp_val;
    int         connections;
    t_cords     result;
    int         row_dir;
    int         col_dir;
    t_cords     piece_start;
    t_cords     piece_end;
    bool        center_captured;
    bool        center_row_captured;
}               t_struct;

#endif


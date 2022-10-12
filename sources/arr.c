/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:13:23 by tlahin            #+#    #+#             */
/*   Updated: 2022/10/06 09:13:25 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_char_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_strdel(&arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
}

void	free_int_arr(int **arr, t_struct *data)
{
	int	i;

	i = 0;
	while (i < data->board_size.rows)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**make_char_arr(int rows, int cols)
{
	char	**arr;
	int		i;

	arr = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		arr[i] = ft_strnew(cols);
		if (!arr[i])
		{
			free_char_arr(arr);
			return (NULL);
		}
		i++;
	}
	arr[i] = 0;
	return (arr);
}

int	**make_int_arr(t_struct *data)
{
	int	**arr;
	int	i;

	i = 0;
	arr = (int **)malloc(sizeof(int *) * data->board_size.rows);
	if (!arr)
		return (NULL);
	while (i < data->board_size.rows)
	{
		arr[i] = (int *)malloc(sizeof(int) * data->board_size.cols);
		if (!arr[i])
		{
			free_int_arr(arr, data);
			return (NULL);
		}
		i++;
	}
	return (arr);
}

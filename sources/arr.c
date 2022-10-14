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

void	free_char_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

char	**create_char_array(int rows, int cols)
{
	char	**array;
	int		i;

	array = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		array[i] = ft_strnew(cols);
		if (!array[i])
		{
			free_char_array(array);
			return (NULL);
		}
		i++;
	}
	array[i] = 0;
	return (array);
}

void	free_int_array(int **array, t_struct *filler)
{
	int	i;

	i = 0;
	while (i < filler->board_size.rows)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	**create_int_array(t_struct *filler)
{
	int	**array;
	int	i;

	array = (int **)malloc(sizeof(int *) * filler->board_size.rows);
	if (!array)
		return (NULL);
	i = 0;
	while (i < filler->board_size.rows)
	{
		array[i] = (int *)malloc(sizeof(int) * filler->board_size.cols);
		if (!array[i])
		{
			free_int_array(array, filler);
			return (NULL);
		}
		i++;
	}
	return (array);
}

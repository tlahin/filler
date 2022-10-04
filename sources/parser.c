//header

#include "filler.h"

int size_parser(int *row, int *col)
{
    char    tmp;
    int     state;

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

int player_parser(t_struct *data)
{
    char    tmp;

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
//header

#include "filler.h"

void    free_char_arr(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        arr[i] = NULL;
        i++;
    }
    free(arr);
    arr = NULL;
}

void    free_int_arr(int **arr, t_struct *data)
{
    int i;

    i = 0;
    while (i < data->board_size.row)
    {
        free(arr[i]);
        i++;
    }
    free(arr);
}

char    **make_char_arr(int rows, int cols)
{
    char    **arr;
    int     i;

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
    arr[i] = '\0';
    return (arr);
}

int **make_int_arr(t_struct *data)
{
    int **arr;
    int i;

    i = 0;
    arr = (int **)malloc(sizeof(int *) * data->board_size.row);
    if (!arr)
        return (NULL);
    while (i < data->board_size.row)
    {
        arr[i] = (int *)malloc(sizeof(int) * data->board_size.col);
        if (!arr[i])
        {
            free_int_arr(arr, data);
            return (NULL);
        }
        i++;
    }
    return (arr);
}
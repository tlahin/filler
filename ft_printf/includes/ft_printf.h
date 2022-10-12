/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:43:25 by tlahin            #+#    #+#             */
/*   Updated: 2022/06/27 12:43:26 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdbool.h>

typedef struct s_data
{
	const char	*fmt;
	char		*c_fmt;
	char		*srch_fmt;
	va_list		args;
	size_t		i;
	int			len;
	int			padding;
	char		specifier;
	long int	width;
	int			s_len;
	long int	prec;
	char		length_flags[3];
	char		prefix[6];
	char		*hex_chars;
	char		*format_flags;
	char		*arg_flags;
	char		*spec_flags;
	char		get_plus;
	bool		nega;
	int			j;
	bool		valid;
}				t_data;

int			ft_printf(const char *format, ...);
t_data		*get_modifiers(t_data *info);
t_data		*printer(t_data *info);
t_data		*check_specifier(t_data *info);
t_data		*check_argument(t_data *info);
t_data		*check_prefix(t_data *info);
t_data		*check_width(t_data *info);
t_data		*check_precision(t_data *info);
t_data		*print_char(t_data *info);
t_data		*print_str(t_data *info);
t_data		*print_pointer(t_data *info);
t_data		*print_integer(t_data *info);
t_data		*print_octal(t_data *info);
t_data		*print_hex(t_data *info);
t_data		*print_unsigned(t_data *info);
t_data		*print_float(t_data *info);
void		print_else(t_data *info);
t_data		*print_alternative(t_data *info, int c, int amount);
t_data		*padding(t_data *info, int middle, int hash, uintmax_t number);
intmax_t	cast_di(t_data *info);
uintmax_t	cast_xou(t_data *info);
long double	cast_flot(t_data *info);
void		max(t_data *info);
void		put_max(void);
void		putnumbermax(intmax_t number);
t_data		*init_data(t_data *info);
t_data		*reset_data(t_data *info);
void		put_simple_di(t_data *info, intmax_t number);
void		put_di(t_data *info, int zero);
t_data		*check_inf(t_data *info, long double number);

#endif

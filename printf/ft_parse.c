/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 05:39:26 by gjailbir          #+#    #+#             */
/*   Updated: 2021/06/23 22:14:46 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_zeroing(t_box *box)
{
	box->flag = ' ';
	box->width = 0;
	box->precision = 0;
	box->descriptor = 0;
	box->dot = 0;
	box->flag_width = 0;
}

int	ft_parse_flag(const char *str, t_box *box)
{
	int	i;

	i = 0;
	while (str[i] == '0' || str[i] == '-')
	{
		if (str[i] == '-')
			box->flag = '-';
		else if (str[i] == '0' && box->flag == ' ')
			box->flag = '0';
		i++;
	}
	return (i);
}

int	ft_parse_width(const char *str, t_box *box, va_list args)
{
	int		i;

	i = 0;
	if (str[i] == '*')
	{
		box->width = va_arg(args, int);
		if (box->width < 0)
		{
			box->flag = '-';
			box->width = -box->width;
		}
		return (1);
	}
	while (ft_isdigit(str[i]))
		box->width = (box->width * 10) + (str[i++] - '0');
	return (i);
}

int	ft_parse_precision(const char *str, t_box *box, va_list args)
{
	int	i;
	int	sign;

	i = 1;
	sign = 1;
	if (str[0] != '.')
		return (0);
	box->dot = 1;
	if (str[i] == '*')
	{
		box->precision = va_arg(args, int);
		return (2);
	}
	if (str[i] == '-')
		sign *= -1;
	while (ft_isdigit(str[i]))
		box->precision = (box->precision * 10) + (str[i++] - '0');
	box->precision *= sign;
	return (i);
}

int	ft_parse_descriptor(const char *str, t_box *box)
{
	char	*descriptors;

	descriptors = "cspdiu%xX";
	while (*descriptors)
	{
		if (*str == *descriptors++)
		{
			box->descriptor = *str;
			return (1);
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 21:39:28 by gjailbir          #+#    #+#             */
/*   Updated: 2021/06/24 20:00:18 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_descriptors(va_list args, t_box *box)
{
	if (box->descriptor == 'd' || box->descriptor == 'i')
		ft_int_dr(args, box);
	else if (box->descriptor == 'x' || box->descriptor == 'X')
		ft_hex_dr(args, box);
	else if (box->descriptor == 'u')
		ft_un_dr(args, box);
	else if (box->descriptor == 'c')
		ft_chr_dr(args, box);
	else if (box->descriptor == 's')
		ft_str_dr(args, box);
	else if (box->descriptor == 'p')
		ft_point_dr(args, box);
	else if (box->descriptor == '%')
		ft_perc_dr(box);
}

int	ft_parse(const char *str, va_list args)
{
	t_box	*box;
	int		len;

	box = malloc(sizeof(t_box));
	if (!box)
		return (0);
	box->len = 0;
	while (*str)
	{
		if (*str != '%')
			ft_putchar_ln(*str++, box);
		else if (*str++ == '%')
		{
			ft_zeroing(box);
			str += ft_parse_flag(str, box);
			str += ft_parse_width(str, box, args);
			str += ft_parse_precision(str, box, args);
			str += ft_parse_descriptor(str, box);
			ft_descriptors(args, box);
		}
	}
	len = box->len;
	free(box);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	va_start(args, str);
	len = ft_parse(str, args);
	va_end(args);
	return (len);
}

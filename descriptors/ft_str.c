/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 08:51:48 by gjailbir          #+#    #+#             */
/*   Updated: 2021/06/23 22:02:01 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_right_edge_str(char *str, t_box *box)
{
	while (box->width-- > 0)
		ft_putchar_ln(' ', box);
	while (*str && (box->precision-- > 0 || box->dot == 0))
		ft_putchar_ln(*str++, box);
}

void	ft_left_edge_str(char *str, t_box *box)
{
	while (*str && (box->precision-- > 0 || box->dot == 0))
		ft_putchar_ln(*str++, box);
	while (box->width-- > 0)
		ft_putchar_ln(' ', box);
}

void	ft_str_dr(va_list args, t_box *box)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	if (box->precision < 0)
		box->precision = ft_strlen(str);
	if (box->precision >= (int) ft_strlen(str) || box->dot == 0)
		box->width -= ft_strlen(str);
	else
		box->width -= box->precision;
	if (box->flag == ' ' || box->flag == '0')
		ft_right_edge_str(str, box);
	else if (box->flag == '-')
		ft_left_edge_str(str, box);
}

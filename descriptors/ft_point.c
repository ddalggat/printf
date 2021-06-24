/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 09:40:54 by gjailbir          #+#    #+#             */
/*   Updated: 2021/06/24 20:53:55 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_right_edge_point(unsigned long num, t_box *box)
{
	while (box->width-- > 0)
		ft_putchar_ln(' ', box);
	if (box->flag == '0')
	{
		ft_putchar_ln('0', box);
		ft_putchar_ln('x', box);
	}
	while (box->precision-- > 0)
		ft_putchar_ln('0', box);
	ft_putpoint_ln(num, box);
}

void	ft_left_edge_point(unsigned long num, t_box *box)
{
	while (box->precision-- > 0)
		ft_putchar_ln('0', box);
	ft_putpoint_ln(num, box);
	while (box->width-- > 0)
		ft_putchar_ln(' ', box);
}

void	ft_costyli_point(unsigned long num, t_box *box)
{
	int		len;

	len = ft_len_num_point(num) + 2;
	box->precision = box->precision - len;
	if (box->precision < 0)
		box->precision = 0;
	box->width = box->width - box->precision - len;
	if (box->dot < 0 && num == 0)
		box->width--;
	if (box->flag == '0' && box->dot == 0)
	{
		box->precision = box->width;
		box->width = 0;
	}
}

void	ft_point_dr(va_list args, t_box *box)
{
	unsigned long	num;

	num = va_arg(args, unsigned long);
	ft_costyli_point(num, box);
	if (box->flag == ' ' || box->flag == '0')
		ft_right_edge_point(num, box);
	if (box->flag == '-')
		ft_left_edge_point(num, box);
}

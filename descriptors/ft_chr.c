/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 07:01:17 by gjailbir          #+#    #+#             */
/*   Updated: 2021/06/23 22:01:31 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_right_edge_chr(char c, t_box *box)
{
	while (box->width-- > 0)
		ft_putchar_ln(' ', box);
	ft_putchar_ln(c, box);
}

void	ft_left_edge_chr(char c, t_box *box)
{
	ft_putchar_ln(c, box);
	while (box->width-- > 0)
		ft_putchar_ln(' ', box);
}

void	ft_costyli_chr(t_box *box)
{
	box->precision = box->precision - 1;
	if (box->precision < 0)
		box->precision = 0;
	box->width = box->width - box->precision - 1;
	if (box->flag == '0' && box->dot == -1)
	{
		box->precision = box->width;
		box->width = 0;
	}
}

void	ft_chr_dr(va_list args, t_box *box)
{
	char	chr;

	chr = va_arg(args, int);
	ft_costyli_chr(box);
	if (box->flag == ' ' || box->flag == '0')
		ft_right_edge_chr(chr, box);
	if (box->flag == '-')
		ft_left_edge_chr(chr, box);
}

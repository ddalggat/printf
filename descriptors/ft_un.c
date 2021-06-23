/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 04:22:05 by gjailbir          #+#    #+#             */
/*   Updated: 2021/06/23 22:03:59 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_flag_zero_un(t_box *box)
{
	if (box->flag == '0')
	{
		while (box->width-- > 0)
			ft_putchar_ln('0', box);
	}
	else
	{
		while (box->width-- > 0)
			ft_putchar_ln(' ', box);
	}
}

void	ft_flag_space_un(int len, t_box *box)
{
	if (box->precision < 0)
		box->precision = 0;
	box->width = box->width - box->precision - len;
	while (box->width-- > 0)
		ft_putchar_ln(' ', box);
	while (box->precision-- > 0)
		ft_putchar_ln('0', box);
}

void	ft_right_edge_un(unsigned int num, int len, t_box *box)
{
	int	prc;

	prc = box->precision;
	box->precision = box->precision - len;
	if (!box->dot || (box->flag == '0' && prc < 0))
	{
		box->width = box->width - len;
		ft_flag_zero_un(box);
	}
	else
	{
		if (box->precision == -1 && num == 0 )
		{
			while (box->width-- > 0)
				ft_putchar_ln(' ', box);
			return ;
		}
		ft_flag_space_un(len, box);
	}
	ft_putnbr(num, box);
}

void	ft_flag_minus_un(unsigned int num, int len, t_box *box, int bla)
{
	if (bla == 0 && num == 0 && len == 1)
		return ;
	if (num == 0 && box->precision <= 0 && box->width == 0 && len != 1)
		return ;
	if (box->precision < 0)
		box->precision = 0;
	box->width = box->width - box->precision - len;
	while (box->precision-- > 0)
		ft_putchar_ln('0', box);
	ft_putnbr(num, box);
	while (box->width-- > 0)
		ft_putchar_ln(' ', box);
}

void	ft_left_edge_un(unsigned int num, int len, t_box *box)
{
	int	bla;

	bla = box->precision;
	box->precision = box->precision - len;
	if (!box->dot)
	{
		box->precision = 0;
		box->width = box->width - len;
		ft_putnbr(num, box);
		while (box->width-- > 0)
			ft_putchar_ln(' ', box);
	}
	else
	{
		if (box->precision == -1 && num == 0 && box->width != 0)
		{
			while (box->width-- > 0)
				ft_putchar_ln(' ', box);
			return ;
		}
		ft_flag_minus_un(num, len, box, bla);
	}
}

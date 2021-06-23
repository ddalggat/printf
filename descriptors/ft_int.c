/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 05:44:23 by gjailbir          #+#    #+#             */
/*   Updated: 2021/06/23 22:17:17 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_flag_zero(int num, t_box *box)
{
	if (box->flag == '0')
	{
		if (num < 0)
			ft_putchar_ln('-', box);
		while (box->width-- > 0)
			ft_putchar_ln('0', box);
	}
	else
	{
		while (box->width-- > 0)
			ft_putchar_ln(' ', box);
		if (num < 0)
			ft_putchar_ln('-', box);
	}
}

void	ft_flag_space(int num, int len, t_box *box)
{
	if (box->precision < 0)
		box->precision = 0;
	box->width = box->width - box->precision - len;
	while (box->width-- > 0)
		ft_putchar_ln(' ', box);
	if (num < 0)
		ft_putchar_ln('-', box);
	while (box->precision-- > 0)
		ft_putchar_ln('0', box);
}

void	ft_right_edge(int num, int len, t_box *box)
{
	int	prc;

	prc = box->precision;
	box->precision = box->precision - len;
	if (num < 0)
		box->precision += 1;
	if (!box->dot || (box->flag == '0' && prc < 0))
	{
		box->width = box->width - len;
		ft_flag_zero(num, box);
	}
	else
	{
		if (box->precision == -1 && num == 0 )
		{
			while (box->width-- > 0)
				ft_putchar_ln(' ', box);
			return ;
		}
		ft_flag_space(num, len, box);
	}
	ft_putnbr(num, box);
}

void	ft_flag_minus(int num, int len, t_box *box, int bla)
{
	if (box->precision == -1 && num == 0 && box->width != 0)
	{
		while (box->width-- > 0)
			ft_putchar_ln(' ', box);
		return ;
	}
	if (bla == 0 && num == 0 && len == 1)
		return ;
	if ((num == 0 && box->precision <= 0 && box->width == 0 && len != 1))
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

void	ft_left_edge(int num, int len, t_box *box)
{
	int	bla;

	bla = box->precision;
	box->precision = box->precision - len;
	if (num < 0)
	{
		box->precision += 1;
		ft_putchar_ln('-', box);
	}
	if (!box->dot)
	{
		box->precision = 0;
		box->width = box->width - len;
		ft_putnbr(num, box);
		while (box->width-- > 0)
			ft_putchar_ln(' ', box);
	}
	else
		ft_flag_minus(num, len, box, bla);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 02:46:49 by gjailbir          #+#    #+#             */
/*   Updated: 2021/06/23 22:05:44 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_flag_zero_hex(t_box *box)
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

void	ft_flag_space_hex(unsigned int len, t_box *box)
{
	if (box->precision < 0)
		box->precision = 0;
	box->width = box->width - box->precision - len;
	while (box->width-- > 0)
		ft_putchar_ln(' ', box);
	while (box->precision-- > 0)
		ft_putchar_ln('0', box);
}

void	ft_right_edge_hex(unsigned int num, int len, t_box *box)
{
	int	tmp;

	tmp = box->precision;
	box->precision = box->precision - len;
	if (!box->dot || tmp < 0)
	{
		box->width = box->width - len;
		ft_flag_zero_hex(box);
	}
	else
	{
		if (box->precision == -1 && num == 0 )
		{
			while (box->width-- > 0)
				ft_putchar_ln(' ', box);
			return ;
		}
		ft_flag_space_hex(len, box);
	}
	ft_putnbr_hex(num, box);
}

void	ft_flag_minus_hex(unsigned int num, int len, t_box *box)
{
	if (box->precision < 0)
		box->precision = 0;
	box->width = box->width - box->precision - len;
	while (box->precision-- > 0)
		ft_putchar_ln('0', box);
	if (box->width == -1 && box->precision == -1 && num == 0
		&& box->flag_width != 0)
		return ;
	else
		ft_putnbr_hex(num, box);
	while (box->width-- > 0)
	{
		ft_putchar_ln(' ', box);
	}
}

void	ft_left_edge_hex(unsigned int num, int len, t_box *box)
{
	if (box->width == 0 && box->precision == 0)
		box->flag_width = 1;
	box->precision = box->precision - len;
	if (!box->dot)
	{
		box->precision = 0;
		box->width = box->width - len;
		ft_putnbr_hex(num, box);
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
		ft_flag_minus_hex(num, len, box);
	}
}

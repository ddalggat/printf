/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 01:39:15 by gjailbir          #+#    #+#             */
/*   Updated: 2021/06/19 09:08:27 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_right_edge_perc(t_box *box, char c)
{
	while (box->width-- > 0)
		ft_putchar_ln(c, box);
	ft_putchar_ln('%', box);
}

void	ft_left_edge_perc(t_box *box, char c)
{
	ft_putchar_ln('%', box);
	while (box->width-- > 0)
		ft_putchar_ln(c, box);
}

void	ft_perc_dr(t_box *box)
{
	box->width--;
	if (box->flag == ' ')
		ft_right_edge_perc(box, ' ');
	else if (box->flag == '0')
		ft_right_edge_perc(box, '0');
	else if (box->flag == '-')
		ft_left_edge_perc(box, ' ');
}

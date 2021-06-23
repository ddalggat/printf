/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_descriptors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 06:24:42 by gjailbir          #+#    #+#             */
/*   Updated: 2021/06/23 22:02:45 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_int_dr(va_list args, t_box *box)
{
	int	num;
	int	len;

	num = va_arg(args, int);
	len = ft_len_num(num);
	if (box->flag == ' ' || box->flag == '0')
		ft_right_edge(num, len, box);
	if (box->flag == '-')
		ft_left_edge(num, len, box);
}

void	ft_hex_dr(va_list args, t_box *box)
{
	int	num;
	int	len;

	num = va_arg(args, unsigned int);
	len = ft_len_num_hex(num);
	if (box->flag == ' ' || box->flag == '0')
		ft_right_edge_hex(num, len, box);
	if (box->flag == '-')
		ft_left_edge_hex(num, len, box);
}

void	ft_un_dr(va_list args, t_box *box)
{
	unsigned int	num;
	int				len;

	num = va_arg(args, unsigned int);
	len = ft_len_num_un(num);
	if (box->flag == ' ' || box->flag == '0')
		ft_right_edge_un(num, len, box);
	if (box->flag == '-')
		ft_left_edge_un(num, len, box);
}

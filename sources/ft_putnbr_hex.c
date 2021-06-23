/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 08:37:38 by gjailbir          #+#    #+#             */
/*   Updated: 2021/06/19 09:09:12 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_hex(unsigned int n, t_box *box)
{
	int		i;
	long	num;
	short	tmp;
	char	list[25];

	i = 0;
	num = (long) n;
	if (!n)
		ft_putchar_ln('0', box);
	while (num > 0)
	{
		tmp = num % 16;
		ft_int_to_chr(tmp, i, list, box);
		i++;
		num /= 16;
	}
	while (i-- > 0)
		ft_putchar_ln(list[i], box);
}

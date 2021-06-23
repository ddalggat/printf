/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint_ln.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 08:37:30 by gjailbir          #+#    #+#             */
/*   Updated: 2021/06/19 09:09:18 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putpoint_ln(unsigned long n, t_box *box)
{
	int				i;
	unsigned long	num;
	char			list[2048];

	i = 0;
	num = n;
	ft_putchar_ln('0', box);
	ft_putchar_ln('x', box);
	if (!n && (box->dot != 0 || box->precision < 0))
		ft_putchar_ln('0', box);
	while (num > 0)
	{
		if (box->descriptor == 'p' && (num % 16) > 9)
			list[i++] = num % 16 + 87;
		else
			list[i++] = num % 16 + 48;
		num /= 16;
	}
	while (i-- > 0)
		ft_putchar_ln(list[i], box);
}

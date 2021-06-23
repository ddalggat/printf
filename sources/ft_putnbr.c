/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 08:37:35 by gjailbir          #+#    #+#             */
/*   Updated: 2021/06/19 11:40:53 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr(long n, t_box *box)
{
	int		i;
	long	num;
	char	list[2048];

	i = 0;
	num = n;
	if (!n)
		ft_putchar_ln('0', box);
	if (num < 0)
		num = -num;
	while (num > 0)
	{
		list[i++] = (char)(num % 10 + 48);
		num /= 10;
	}
	while (i-- > 0)
		ft_putchar_ln(list[i], box);
}

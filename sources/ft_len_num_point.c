/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_num_point.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 08:38:05 by gjailbir          #+#    #+#             */
/*   Updated: 2021/06/19 09:09:01 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_len_num_point(unsigned long num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0 && ++i)
		num /= 16;
	return (i);
}

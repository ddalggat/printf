/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_num_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 08:38:08 by gjailbir          #+#    #+#             */
/*   Updated: 2021/06/19 09:08:59 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_len_num_hex(unsigned int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0 && ++i)
		num /= 16;
	return (i);
}

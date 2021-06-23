/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 08:38:11 by gjailbir          #+#    #+#             */
/*   Updated: 2021/06/19 09:16:14 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_int_to_chr(short tmp, int i, char *list, t_box *box)
{
	if (tmp <= 9 && tmp >= 0)
		list[i] = tmp + '0';
	else if (box->descriptor == 'x')
		list[i] = tmp + 87;
	else if (box->descriptor == 'X')
		list[i] = tmp + 55;
}

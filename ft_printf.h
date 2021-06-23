/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjailbir <gjailbir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:20:15 by gjailbir          #+#    #+#             */
/*   Updated: 2021/06/23 22:15:10 by gjailbir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_box {
	int	flag;
	int	descriptor;
	int	width;
	int	precision;
	int	dot;
	int	len;
	int	flag_width;
}	t_box;

/***_source_functions_***/
void	ft_putchar_ln(char c, t_box *box);
void	ft_putnbr(long n, t_box *box);
void	ft_putnbr_hex(unsigned int n, t_box *box);
void	ft_putpoint_ln(unsigned long n, t_box *box);
void	ft_int_to_chr(short tmp, int i, char *list, t_box *box);
int		ft_isdigit(int c);
int		ft_len_num(long num);
int		ft_len_num_hex(unsigned int num);
int		ft_len_num_point(unsigned long num);
int		ft_len_num_un(long num);
size_t	ft_strlen(char *str);

/***_parse_functions_***/
void	ft_zeroing(t_box *box);
int		ft_parse_flag(const char *str, t_box *box);
int		ft_parse_width(const char *str, t_box *box, va_list args);
int		ft_parse_precision(const char *str, t_box *box, va_list args);
int		ft_parse_descriptor(const char *str, t_box *box);

/***_descriptors_functions_***/
void	ft_int_dr(va_list args, t_box *box);
void	ft_hex_dr(va_list args, t_box *box);
void	ft_un_dr(va_list args, t_box *box);
void	ft_chr_dr(va_list args, t_box *box);
void	ft_str_dr(va_list args, t_box *box);
void	ft_point_dr(va_list args, t_box *box);
void	ft_perc_dr(t_box *box);

/***_int_functions_***/
void	ft_right_edge(int num, int len, t_box *box);
void	ft_left_edge(int num, int len, t_box *box);

/***_hex_functions_***/
void	ft_right_edge_hex(unsigned int num, int len, t_box *box);
void	ft_left_edge_hex(unsigned int num, int len, t_box *box);

/***_un_functions_***/
void	ft_right_edge_un(unsigned int num, int len, t_box *box);
void	ft_left_edge_un(unsigned int num, int len, t_box *box);

int		ft_printf(const char *str, ...);

#endif
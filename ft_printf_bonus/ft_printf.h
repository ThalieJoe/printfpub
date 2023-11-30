/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:34:02 by stouitou          #+#    #+#             */
/*   Updated: 2023/11/30 16:56:04 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_print
{
	va_list	args;
	int		wdt;
	int		htg;
	int		zero;
	int		pnt;
	int		dash;
	int		tl;
	int		sign;
	int		is_zero;
	int		perc;
	int		sp;
}	t_print;

int		ft_printf(const char *format, ...);
void	ft_checkcase(t_print *tab, char c);
int		ft_eval_format(t_print *tab, const char *str, int i);
void	ft_left_cs(t_print *tab, int i);
void	ft_right_cs(t_print *tab, int i);
void	ft_print_char(t_print *tab);
void	ft_print_str(t_print *tab);
void	ft_print_int(t_print *tab);
void	ft_print_ptr(t_print *tab);
void	ft_print_uint(t_print *tab);
void	ft_print_hexal(t_print *tab);
void	ft_print_hexau(t_print *tab);
void	ft_putnbr(long int n);
int		ft_nbrlen(long int n);
int		ft_unbrlen(long unsigned int n, char *base);
int		ft_itoabase(long unsigned int n, char *base);

#endif

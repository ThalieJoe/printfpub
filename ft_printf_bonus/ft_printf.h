/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:34:02 by stouitou          #+#    #+#             */
/*   Updated: 2023/11/29 15:09:49 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_print
{
	va_list	args;
	int	wdt;
	int	prc;
	int	zero;
	int	pnt;
	int	dash;
	int	tl;
	int	sign;
	int	is_zero;
	int	perc;
	int	sp;
} t_print;

int	ft_printf(const char *format, ...);
void	ft_checkcase(t_print *tab, char c);
int	ft_eval_format(t_print *tab, const char *str, int i);
void	ft_left_cs(t_print *tab, int i);
void	ft_right_cs(t_print *tab, int i);
void	ft_print_char(t_print *tab);
void	ft_print_str(t_print *tab);
void	ft_print_int(t_print *tab);
int	ft_nbrlen(long int n);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:00:00 by stouitou          #+#    #+#             */
/*   Updated: 2023/11/30 13:09:21 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_checkcase(t_print *tab, char c)
{
	if (c == 'c')
		ft_print_char(tab);
	if (c == 's')
		ft_print_str(tab);
	if (c == 'p')
		ft_print_ptr(tab);
	if (c == 'd' || c == 'i')
		ft_print_int(tab);
	if (c == 'u')
		ft_print_uint(tab);
	if (c == 'x')
		ft_print_hexal(tab);
	if (c == 'X')
		ft_print_hexau(tab);
	if (c == '%')
		tab->tl += write(1, "%", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:27:44 by stouitou          #+#    #+#             */
/*   Updated: 2023/11/29 17:06:48 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_print_char(t_print *tab)
{
	char	c;

	c = va_arg(tab->args, int);
//	ft_update_tab(tab, 1);
	if (tab->wdt && !tab->dash && !tab->pnt)
		ft_right_cs(tab, tab->wdt - 1);
	tab->tl += write(1, &c, 1);
	if (tab->wdt && tab->dash)
		ft_left_cs(tab, tab->wdt - 1);
	tab->wdt = 0;
	tab->pnt = 0;
}

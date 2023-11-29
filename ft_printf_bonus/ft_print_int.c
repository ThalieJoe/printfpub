/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:48:07 by stouitou          #+#    #+#             */
/*   Updated: 2023/11/29 17:16:53 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_print_int(t_print *tab)
{
	int	d;

	d = va_arg(tab->args, int);
	if (d < 0)
		tab->sign = 0;
	if (!tab->dash && tab->wdt > ft_nbrlen(d))
		ft_right_cs(tab, tab->wdt - ft_nbrlen(d));
	ft_putnbr_fd(d, 1);
	tab->tl += ft_nbrlen(d);
	if (tab->dash && tab->wdt > ft_nbrlen(d))
		ft_left_cs(tab, tab->wdt - ft_nbrlen(d));
	tab->wdt = 0;
	tab->pnt = 0;
}

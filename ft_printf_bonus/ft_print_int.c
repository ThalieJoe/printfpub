/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:48:07 by stouitou          #+#    #+#             */
/*   Updated: 2023/11/30 17:21:47 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_print_int(t_print *tab)
{
	long	d;
	int	len;

	d = va_arg(tab->args, int);
	len = ft_nbrlen(d);
	if (d < 0 && tab->pnt)
	{	
		tab->tl += write(1, "-", 1);
		tab->sign = 0;
		d *= -1;
		len -= 1;
	}
	else if (d < 0)
		tab->sign = 0;
	if ((!tab->dash || tab->pnt) && tab->wdt > len)
		ft_right_cs(tab, tab->wdt - len);
	if (tab->wdt == 0 && tab->pnt && d == 0)
		tab->pnt = 0;
	else
	{
		ft_putnbr(d);
		tab->tl += len;
	}
	if (tab->dash && tab->wdt > len && !tab->pnt)
		ft_left_cs(tab, tab->wdt - len);
	tab->wdt = 0;
	tab->pnt = 0;
}

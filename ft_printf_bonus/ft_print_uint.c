/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:00:48 by stouitou          #+#    #+#             */
/*   Updated: 2023/11/30 14:23:28 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_print_uint(t_print *tab)
{
	unsigned long	u;
	int				len;

	u = va_arg(tab->args, unsigned int);
	len = ft_unbrlen(u, "0123456789");
	if (!tab->dash && tab->wdt > len)
		ft_right_cs(tab, tab->wdt - len);
	tab->tl += ft_itoabase(u, "0123456789");
	if (tab->dash && tab->wdt > len)
		ft_left_cs(tab, tab->wdt - len);
	tab->wdt = 0;
	tab->pnt = 0;
}

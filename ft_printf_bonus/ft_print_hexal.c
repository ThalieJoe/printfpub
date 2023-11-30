/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:27:30 by stouitou          #+#    #+#             */
/*   Updated: 2023/11/30 14:23:55 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_print_hexal(t_print *tab)
{
	unsigned int	x;
	int				len;

	x = va_arg(tab->args, unsigned int);
	len = ft_unbrlen(x, "0123456789abcdef");
	if (tab->htg && x != 0)
		len += 2;
	if (!tab->dash && tab->wdt > len)
		ft_right_cs(tab, tab->wdt - len);
	if (tab->htg && x != 0)
		tab->tl += write(1, "0x", 2);
	tab->tl += ft_itoabase(x, "0123456789abcdef");
	if (tab->dash && tab->wdt > len)
		ft_left_cs(tab, tab->wdt - len);
	tab->wdt = 0;
	tab->pnt = 0;
	tab->htg = 0;
}

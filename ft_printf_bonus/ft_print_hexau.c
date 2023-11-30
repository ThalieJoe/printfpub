/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexau.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:45:48 by stouitou          #+#    #+#             */
/*   Updated: 2023/11/30 14:22:32 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_print_hexau(t_print *tab)
{
	unsigned int	xu;
	int				len;

	xu = va_arg(tab->args, unsigned int);
	len = ft_unbrlen(xu, "0123456789ABCDEF");
	if (tab->htg && xu != 0)
		len += 2;
	if ((!tab->dash || (tab->dash && tab->pnt)) && tab->wdt > len)
		ft_right_cs(tab, tab->wdt - len);
	if (tab->htg && xu != 0)
		tab->tl += write(1, "0X", 2);
	tab->tl += ft_itoabase(xu, "0123456789ABCDEF");
	if (tab->dash && tab->wdt > len && !tab->pnt)
		ft_left_cs(tab, tab->wdt - len);
	tab->wdt = 0;
	tab->pnt = 0;
	tab->htg = 0;
}

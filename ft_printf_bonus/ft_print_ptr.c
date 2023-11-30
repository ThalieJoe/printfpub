/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:08:59 by stouitou          #+#    #+#             */
/*   Updated: 2023/11/30 15:51:40 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_print_ptr(t_print *tab)
{
	void	*p;
	int		len;

	p = va_arg(tab->args, void *);
	len = ft_unbrlen((unsigned long int)p, "0123456789abcdef");
	if (p == NULL)
		len = 5;
	if (!tab->dash && tab->wdt > len + 2 && p)
		ft_right_cs(tab, tab->wdt - len - 2);
	else if (!tab->dash && tab->wdt > len && !p)
		ft_right_cs(tab, tab->wdt - len);
	if (p == NULL)
		tab->tl += write(1, "(nil)", 5);
	else
	{
		if (tab->sign)
			tab->tl += write(1, "+", 1);
		tab->tl += write(1, "0x", 2);
		tab->tl += ft_itoabase((unsigned long int)p, "0123456789abcdef");
	}
	if (tab->dash && tab->wdt > len + 2)
		ft_left_cs(tab, tab->wdt - len - 2);
	tab->wdt = 0;
	tab->pnt = 0;
}

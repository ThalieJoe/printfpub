/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:00:59 by stouitou          #+#    #+#             */
/*   Updated: 2023/11/29 17:07:18 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_print_str(t_print *tab)
{
	char	*str;
	int		i;

	str = va_arg(tab->args, char *);
	i = 0;
	if (!tab->dash && tab->wdt > ft_strlen(str) && !tab->pnt)
		ft_right_cs(tab, tab->wdt - ft_strlen(str));
	while (str[i])
	{
		if (tab->pnt && i == tab->wdt)
			break ;
		tab->tl += write(1, &str[i], 1);
		i++;
	}
	if (tab->dash && tab->wdt > ft_strlen(str))
		ft_left_cs(tab, tab->wdt - ft_strlen(str));
	tab->wdt = 0;
	tab->pnt = 0;
}

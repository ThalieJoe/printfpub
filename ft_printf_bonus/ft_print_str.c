/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:00:59 by stouitou          #+#    #+#             */
/*   Updated: 2023/11/30 14:38:55 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_print(t_print *tab, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (tab->pnt && i == tab->wdt)
			break ;
		tab->tl += write(1, &str[i], 1);
		i++;
	}
}

void	ft_print_str(t_print *tab)
{
	char	*str;
	int		len;
	int		strnull;

	str = va_arg(tab->args, char *);
	strnull = 0;
	if (str == NULL)
	{
		str = "(null)";
		strnull = 1;
	}
	len = ft_strlen(str);
	if (!tab->dash && tab->wdt > len && !tab->pnt)
		ft_right_cs(tab, tab->wdt - len);
	if (!strnull || (strnull && !tab->pnt))
		ft_print(tab, str);
	if (tab->dash && tab->wdt > len)
		ft_left_cs(tab, tab->wdt - len);
	tab->wdt = 0;
	tab->pnt = 0;
}

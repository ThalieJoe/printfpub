/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:49:37 by stouitou          #+#    #+#             */
/*   Updated: 2023/11/30 17:30:05 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_ischarset(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_eval_format(t_print *tab, const char *str, int i)
{
	char	*charset;

	charset = "cspdiuxX%";
	while (!ft_ischarset(str[i], charset))
	{
		if (str[i] == '.')
			tab->pnt = 1;
		if (str[i] == '-')
			tab->dash = 1;
		if (str[i] == '+')
			tab->sign = 1;
		if (str[i] == '0' && !ft_isdigit(str[i - 1]))
			tab->is_zero = 1;
		if (str[i] == '#')
			tab->htg = 1;
		if (str[i] == '%')
			tab->perc = 1;
		if (ft_isdigit(str[i]) && (str[i - 1] != '-' && str[i + 1] != '.'))
			tab->wdt = tab->wdt * 10 + (str[i] - '0');
		i++;
	}
	ft_checkcase(tab, str[i]);
	return (i);
}

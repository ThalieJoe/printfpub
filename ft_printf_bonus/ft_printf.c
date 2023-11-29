/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:37:38 by stouitou          #+#    #+#             */
/*   Updated: 2023/11/29 17:23:44 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

t_print	*ft_initialise_tab(t_print *tab)
{
	tab->wdt = 0;
	tab->prc = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->dash = 0;
	tab->tl = 0;
	tab->sign = 0;
	tab->is_zero = 0;
	tab->perc = 0;
	tab->sp = 0;
	return (tab);
}

int	ft_printf(const char *format, ...)
{
	int	i;
	int	ret;
	t_print	*tab;

	tab = (t_print *)malloc(sizeof(t_print));
	if (tab == NULL)
		return (-1);
	ft_initialise_tab(tab);
	va_start(tab->args, format);
	i = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i = ft_eval_format(tab, format, i + 1);
		else
			ret += write(1, &format[i], 1);
		i++;
	}
	va_end(tab->args);
	ret += tab->tl;
	return (ret);
}

int	main(void)
{
	char	c;
	char	*s;
	int	d;
	int	i;

	c = 'G';
	s = "Hello";
	d = -123;
	i = 123;
	printf("%d\n", ft_printf("Char: %1c\nString: %.10s\nDec: <%20d>\nInt: <%020i>\n", c, s, d, i));
	printf("%d\n", printf("Char: %1c\nString: %.10s\nDec: <%20d>\nInt: <%020i>\n", c, s, d, i));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:27:17 by stouitou          #+#    #+#             */
/*   Updated: 2023/11/29 17:27:59 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_right_cs(t_print *tab, int i)
{
	while (i)
	{
		if (!(i - 1) && tab->sign)
			tab->tl += write(1, "+", 1);
		else if ((tab->is_zero || tab->pnt) && !tab->sign)
			tab->tl += write(1, "0", 1);
		else
			tab->tl += write(1, " ", 1);
		i--;
	}
	tab->is_zero = 0;
	tab->pnt = 0;
}

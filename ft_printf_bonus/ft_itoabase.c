/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:35:20 by stouitou          #+#    #+#             */
/*   Updated: 2023/11/30 14:53:58 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_itoabase(unsigned long int n, char *base)
{
	char	*number;
	int		len;
	int		i;

	len = ft_unbrlen(n, base);
	number = (char *)malloc((len + 1) * sizeof(char));
	if (number == NULL)
		return (0);
	i = len;
	number[i] = '\0';
	i--;
	while (i >= 0)
	{
		number[i] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
		i--;
	}
	ft_putstr_fd(number, 1);
	free(number);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:21:39 by stouitou          #+#    #+#             */
/*   Updated: 2023/11/30 11:09:42 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_unbrlen(long unsigned int n, char *base)
{
	int	len;

	len = 1;
	while (n >= ft_strlen(base))
	{
		n /= ft_strlen(base);
		len++;
	}
	return (len);
}

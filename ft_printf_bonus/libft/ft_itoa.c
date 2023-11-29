/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:54:20 by stouitou          #+#    #+#             */
/*   Updated: 2023/11/15 13:08:16 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_intlen(long int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len = 1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static long int	ft_valabs(long int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

static char	*ft_intzero(void)
{
	char	*num;

	num = (char *)malloc(2 * sizeof(char));
	if (num == NULL)
		return (NULL);
	num[0] = '0';
	num[1] = '\0';
	return (num);
}

char	*ft_itoa(int n)
{
	long int	nb;
	char		*num;
	int			i;

	nb = n;
	if (nb == 0)
	{
		num = ft_intzero();
		return (num);
	}
	num = (char *)malloc((ft_intlen(nb) + 1) * sizeof(char));
	if (num == NULL)
		return (NULL);
	i = ft_intlen(nb);
	num[i] = '\0';
	i--;
	if (nb < 0)
		num[0] = '-';
	nb = ft_valabs(nb);
	while (nb > 0)
	{
		num[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (num);
}

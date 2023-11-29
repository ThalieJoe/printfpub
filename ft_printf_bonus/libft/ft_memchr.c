/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:24:48 by stouitou          #+#    #+#             */
/*   Updated: 2023/11/14 17:55:28 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		d;
	size_t				i;

	str = (const unsigned char *)s;
	d = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == d)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

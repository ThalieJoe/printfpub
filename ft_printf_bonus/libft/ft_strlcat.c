/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:28:49 by stouitou          #+#    #+#             */
/*   Updated: 2023/11/16 14:40:22 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;

	if ((!dest && size == 0) || (!src && size == 0))
		return (0);
	dest_len = ft_strlen(dest);
	if (size <= dest_len)
		return (ft_strlen(src) + size);
	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while ((i + j < size - 1) && src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest_len + ft_strlen(src));
}

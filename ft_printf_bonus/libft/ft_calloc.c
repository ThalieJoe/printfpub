/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:22:20 by stouitou          #+#    #+#             */
/*   Updated: 2023/11/15 12:12:26 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*calloc;

	if ((nmemb > 65535 && size > 65535) || (nmemb * size > 65535))
		return (NULL);
	calloc = (void *)malloc(size * nmemb);
	if (calloc == NULL)
		return (NULL);
	ft_bzero(calloc, nmemb * size);
	return (calloc);
}

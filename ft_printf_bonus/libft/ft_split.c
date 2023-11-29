/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stouitou <stouitou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:37:57 by stouitou          #+#    #+#             */
/*   Updated: 2023/11/16 12:54:36 by stouitou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	count;
	int		i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count += 1;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static int	ft_wlen(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

static char	*ft_strndup(const char *s, char c)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (ft_wlen(s, c) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < ft_wlen(s, c))
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**ft_freesplit(char **split, size_t j)
{
	if (split[j] == NULL)
	{
		while (j > 0)
		{
			free(split[j]);
			j--;
		}
		free(split);
		return (NULL);
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	split = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	i = 0;
	while (s[i] == c && c != '\0')
		i++;
	j = 0;
	while (j < ft_count_words(s, c))
	{
		split[j] = ft_strndup(&s[i], c);
		ft_freesplit(split, j);
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c)
			i++;
		j++;
	}
	split[j] = NULL;
	return (split);
}

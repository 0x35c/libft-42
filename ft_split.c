/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:08:50 by ulayus            #+#    #+#             */
/*   Updated: 2022/10/03 14:05:07 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 1;
	while (s[i] == c)
		i++;
	if (i == ft_strlen(s))
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			if (s[i + 1] != c && s[i + 1])
				count++;
		i++;
	}
	return (count);
}

size_t	count_char(char const *s, char c, size_t i)
{
	size_t	count;

	count = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

size_t	ft_strccpy(const char *s, char *str, char c, size_t j)
{
	size_t	i;

	i = 0;
	while (s[j] == c && s[j])
		j++;
	while (s[j] && s[j] != c)
	{
		str[i] = s[j];
		i++;
		j++;
	}
	str[i] = 0;
	while (s[j] == c && s[j])
		j++;
	return (j);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**strs;

	if (!s)
		return (0);
	strs = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (strs == NULL)
		return (0);
	i = 0;
	j = 0;
	while (s[i] && j < count_word(s, c) + 1)
	{
		strs[j] = malloc(count_char(s, c, i) + 1);
		if (!strs[j])
			return (0);
		i = ft_strccpy(s, strs[j], c, i);
		j++;
	}
	strs[j] = 0;
	return (strs);
}

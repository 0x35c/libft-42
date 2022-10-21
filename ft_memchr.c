/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:26:14 by ulayus            #+#    #+#             */
/*   Updated: 2022/09/30 19:49:26 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;

	if (!n)
		return (0);
	str = (char *) s;
	if (c == '\0')
	{
		s += ft_strlen(str);
		return ((void *)s);
	}
	while (n && *str)
	{
		if (*str == c)
			return ((void *)s);
		n--;
		str++;
		s++;
	}
	return (0);
}

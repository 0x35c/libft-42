/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:19:30 by ulayus            #+#    #+#             */
/*   Updated: 2022/10/01 02:08:12 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array;

	if (!nmemb)
		return (0);
	if (size * nmemb / nmemb != size)
		return (0);
	array = malloc(nmemb * size);
	if (!array)
		return (0);
	ft_bzero(array, nmemb * size);
	return ((void *)array);
}

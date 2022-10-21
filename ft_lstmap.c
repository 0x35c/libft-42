/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:21:25 by ulayus            #+#    #+#             */
/*   Updated: 2022/10/03 14:48:56 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*begin;

	new = malloc(sizeof(t_list));
	if (!lst || !f)
        return (0);
	begin = new;
    while (lst)
    {
		new->next = malloc(sizeof(t_list));
		if (!new->next)
		{
			ft_lstclear(&begin, del);
			return (0);
		}
		new->content = f(lst->content);
		lst = lst->next;
		new = new->next;
    }
	return (begin);
}

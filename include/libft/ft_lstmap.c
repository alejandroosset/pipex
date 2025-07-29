/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:48:32 by aosset-o          #+#    #+#             */
/*   Updated: 2025/04/24 16:53:51 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*aux;

	if (!lst || !f || !del)
		return (NULL);
	res = NULL;
	while (lst)
	{
		aux = malloc(sizeof(t_list));
		if (!aux)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		aux->content = f(lst->content);
		aux->next = NULL;
		ft_lstadd_back(&res, aux);
		lst = lst->next;
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:29:51 by aosset-o          #+#    #+#             */
/*   Updated: 2025/04/24 11:44:09 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*res;

	aux = *lst;
	if (!aux)
		return ;
	while (aux)
	{
		res = aux->next;
		del(aux->content);
		free(aux);
		aux = res;
	}
	*lst = NULL;
}

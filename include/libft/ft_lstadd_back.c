/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:59:43 by aosset-o          #+#    #+#             */
/*   Updated: 2025/04/24 11:16:31 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temporal;

	temporal = (*lst);
	if ((*lst))
	{
		while (temporal->next != NULL)
			temporal = temporal->next;
		temporal->next = new;
	}
	if (!(*lst))
		(*lst) = new;
}

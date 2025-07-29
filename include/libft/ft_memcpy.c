/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:21:07 by aosset-o          #+#    #+#             */
/*   Updated: 2025/04/11 13:25:17 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

/*#include <string.h>
#include <stdio.h>

int main(void)
{
	char source[] = "";
	char target[] = "";
  	printf( "Before memcpy, target is \"%s\"\n", target );
  	memcpy( target, source, sizeof(source));
  	printf( "After memcpy, target becomes \"%s\"\n", target );
}*/
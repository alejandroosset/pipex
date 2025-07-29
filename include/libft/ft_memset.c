/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:31:07 by aosset-o          #+#    #+#             */
/*   Updated: 2025/04/11 10:42:57 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*aux;
	size_t			i;

	aux = s;
	i = 0;
	while (i < n)
	{
		aux[i] = c;
		i++;
	}
	return (aux);
}
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
   char buffer[20];
   char *string;

   ft_memset(buffer, 0, sizeof(buffer));
   string = (char *) ft_memset(buffer,'A', 10);
   printf("\nBuffer contents: %s\n", string);
   ft_memset(buffer+10, 'B', 10);
   printf("\nBuffer contents: %s\n", buffer);
}*/
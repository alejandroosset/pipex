/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:55:41 by aosset-o          #+#    #+#             */
/*   Updated: 2025/04/12 11:22:34 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen((char *)little) == 0 || little == NULL)
		return ((char *)big);
	while (big[i])
	{
		while (little[j] == big[i + j] && (i + j) < len)
		{
			if (j + 1 == ft_strlen((char *)little))
				return ((char *)big + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>

int	main(void) {
	const char *haystack = "Hola, este es un ejemplo de prueba.";
	const char *needle = "ejemplo";
	size_t len = 20;

	char *result = ft_strnstr(haystack, needle, len);

	if (result != NULL) {
		printf("Cadena encontrada: \"%s\"\n", result);
	} else {
		printf("Cadena no encontrada.\n", len);
	}

	return (0);
}*/
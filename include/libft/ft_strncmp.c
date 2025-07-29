/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:53:41 by aosset-o          #+#    #+#             */
/*   Updated: 2025/04/11 17:23:49 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	dif;
	int	i;

	i = 0;
	dif = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && n > 0)
	{
		if (s1[i] != s2[i])
		{
			dif = (unsigned char)s1[i] - (unsigned char)s2[i];
			return (dif);
		}
		i++;
		n--;
	}
	return (dif);
}

/*#include <stdio.h>
#include <string.h>
int	main(void)
{
	//char str1[] = "bfb";
	char str2[] = "gfg";
	unsigned n = 2;
	
	//printf("%d", ft_strncmp(NULL, str2, n));
	printf("%d", strncmp(NULL, str2, n));
	return (0);
}*/

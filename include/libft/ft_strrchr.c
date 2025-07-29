/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:47:14 by aosset-o          #+#    #+#             */
/*   Updated: 2025/04/21 10:39:42 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s);
	if ((char)c == '\0')
		return ((char *)&s[i]);
	while (i > 0)
	{
		if (s[i -1] == (char)c)
		{
			return ((char *)&s[i - 1]);
		}
		i--;
	}
	return (NULL);
}

/*#include <string.h>

int	main(void)
{
	const char *str = "hello world";
	int c = 'w';

	write(1, strrchr(str, c), 1);
	write(1, "\n", 1);
	write(1, ft_strrchr(str, c), 1);
}*/
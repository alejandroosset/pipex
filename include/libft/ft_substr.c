/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:50:50 by aosset-o          #+#    #+#             */
/*   Updated: 2025/04/23 16:27:55 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (start > ft_strlen(s))
	{
		str = malloc(1 * sizeof(char));
		if (str == NULL)
			return (str);
		str[0] = '\0';
		return (str);
	}
	if ((start + len) > ft_strlen(s))
		len = ft_strlen(s) - start;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (str);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
// int main (void)
// {
// 	char *c=ft_substr("0123456789",9,10);
// 	printf("%s\n",c);
// 	return(0);
// }

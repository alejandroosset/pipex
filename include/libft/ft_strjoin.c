/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:18:29 by aosset-o          #+#    #+#             */
/*   Updated: 2025/04/23 16:28:26 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = 0;
	if ((s1[0] == '\0' && s2[0] == '\0'))
	{
		str = malloc(1 * sizeof(char));
		if (str == NULL)
			return (str);
		str[0] = '\0';
		return (str);
	}
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (str);
	str = ft_memcpy(str, s1, ft_strlen(s1));
	i = 0;
	while (s2[i] != '\0')
	{
		str[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	return (str[ft_strlen(s1) + ft_strlen(s2)] = '\0', str);
}

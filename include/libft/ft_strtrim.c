/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:32:38 by aosset-o          #+#    #+#             */
/*   Updated: 2025/04/22 13:58:50 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		count;
	int		count_rev;

	count = 0;
	count_rev = 0;
	while (ft_strchr(set, (int)s1[count]) != NULL)
		count++;
	while (ft_strrchr(set, (int)s1[ft_strlen(s1) - count_rev - 1]) != NULL)
		count_rev++;
	if (!s1)
		return (NULL);
	else if (!set)
		return (ft_strdup(s1));
	str = ft_substr(s1, count, (ft_strlen(s1) - count - count_rev));
	return (str);
}
/*#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strtrim("aaaaabcbdefabcada", "abc"));
	return (0);
}*/

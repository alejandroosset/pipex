/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:01:53 by aosset-o          #+#    #+#             */
/*   Updated: 2025/04/24 14:11:58 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	cwords;
	int	i;

	cwords = 0;
	i = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c)
			cwords++;
		i++;
	}
	if (s[0] == c && s[i - 1] == c)
		return (cwords - 1);
	else if (s[0] == c || s[i - 1] == c)
		return (cwords);
	return (cwords + 1);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static void	split_str(char **ptr, char *str, char c, int nwords)
{
	int		i;
	char	*aux;

	i = 0;
	if ((nwords > 0) && *str)
	{
		while (i < (nwords - 1))
		{
			aux = ft_strchr(str, c);
			ptr[i++] = ft_substr(str, 0, aux - str);
			if (ptr == 0)
			{
				ft_free(ptr, i);
				return ;
			}
			while (*aux == c)
				aux++;
			str = aux;
		}
		ptr[i++] = ft_strdup(str);
		ptr[i] = 0;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	char	*str;
	char	a[2];

	a[0] = c;
	a[1] = '\0';
	if (s)
	{
		str = ft_strtrim(s, a);
		if (str)
		{
			ptr = ft_calloc((count_words(s, c) + 1), sizeof(char *));
			if (ptr)
				split_str(ptr, str, c, count_words(s, c));
			free(str);
			return (ptr);
		}
	}
	return (NULL);
}

/*#include <stdio.h>
int	main(void)
{
	printf("%d\n", count_words("     aa    bbb      ", ' '));
	

	for (int i = 0; expected[i]; i++)
	{
			if (expected[i] != ((void*)0))
			{
				printf("mal\n");
				return (0);
			}
	}
	printf("bien\n");
	free(expected);
	return (0);
}*/
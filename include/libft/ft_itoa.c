/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:46:02 by aosset-o          #+#    #+#             */
/*   Updated: 2025/04/23 16:44:15 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		count++;
	}
	count++;
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long int	nbr;

	nbr = n;
	len = count_digits(nbr);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (str);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (nbr)
	{
		str[len] = ((nbr % 10) + '0');
		nbr = nbr / 10;
		len--;
	}
	return (str);
}
/*#include <stdio.h>
int main (void)
{
	printf("%d\n", count_digits(-12345));
	return(0);
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aosset-o <aosset-o@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:47:59 by aosset-o          #+#    #+#             */
/*   Updated: 2025/04/11 13:02:49 by aosset-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*#include <stdio.h>
#include <string.h>
int main(void)
{
   char buffer[50];
 
   ft_bzero(buffer+10, 10);
   printf("\nBuffer contents: %s\n", buffer);
      
   bzero(buffer+10, 10);
   printf("\nBuffer contents: %s\n", buffer);
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlefebvr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:39:28 by tlefebvr          #+#    #+#             */
/*   Updated: 2021/11/01 13:07:42 by tlefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<string.h>
#include<stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, unsigned int n)
{
	size_t	i;
	size_t	c;
	size_t	n_len;
	char	*hay;

	i = 0;
	hay = (char *)str;
	n_len = ft_strlen(to_find);
	if (n_len == 0 || str == to_find)
		return (hay);
	while (hay[i] != '\0' && i < n)
	{
		c = 0;
		while (hay[i + c] != '\0' && to_find[c] != '\0'
			&& hay[i + c] == to_find[c] && i + c < n)
			c++;
		if (c == n_len)
			return (hay + i);
		i++;
	}
	return (0);
}

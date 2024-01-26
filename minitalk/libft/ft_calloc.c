/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlefebvr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:02:14 by tlefebvr          #+#    #+#             */
/*   Updated: 2021/11/01 14:39:50 by tlefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t siz)
{
	unsigned int	n;
	char			*ptr;

	n = count * siz;
	ptr = malloc(n);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, n);
	return (ptr);
}

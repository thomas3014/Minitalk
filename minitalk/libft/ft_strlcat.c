/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlefebvr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:35:50 by tlefebvr          #+#    #+#             */
/*   Updated: 2021/10/27 14:50:51 by tlefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	dstsize;
	size_t	k;
	size_t	srcsize;

	dstsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	if (siz == 0)
		return (srcsize);
	if (siz < dstsize)
		srcsize += siz;
	else
		srcsize += dstsize;
	k = 0;
	while (src[k] != '\0' && (dstsize + k) < siz - 1)
	{
		dst[dstsize + k] = src[k];
		k++;
	}
	dst[dstsize + k] = '\0';
	return (srcsize);
}

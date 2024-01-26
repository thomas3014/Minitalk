/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlefebvr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:38:33 by tlefebvr          #+#    #+#             */
/*   Updated: 2021/10/28 13:16:13 by tlefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ret;
	int		i;

	ret = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			ret = &((char *)str)[i];
		i++;
	}
	if (c == '\0')
		ret = &((char *)str)[i];
	return (ret);
}

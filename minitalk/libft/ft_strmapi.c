/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlefebvr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 13:16:45 by tlefebvr          #+#    #+#             */
/*   Updated: 2021/10/20 14:29:38 by tlefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		num;

	if (s == NULL || f == NULL)
		return (NULL);
	str = (char *) malloc (sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
	{
		return (NULL);
	}
	num = 0;
	while (s[num])
	{
		str[num] = f(num, s[num]);
		num++;
	}
	str[num] = '\0';
	return (str);
}

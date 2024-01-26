/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlefebvr <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:16:01 by tlefebvr          #+#    #+#             */
/*   Updated: 2021/10/21 09:36:57 by tlefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	num;

	num = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[num])
	{
		f(num, s + num);
		num++;
	}
}

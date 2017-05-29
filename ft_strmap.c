/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 14:21:55 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/09 14:04:50 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*s1;
	size_t	n;
	size_t	i;

	s1 = NULL;
	if (s != NULL)
	{
		n = ft_strlen(s);
		s1 = ft_strnew(n);
		if (s1 != NULL)
		{
			i = 0;
			while (i < n)
			{
				s1[i] = f(s[i]);
				i++;
			}
		}
	}
	return (s1);
}

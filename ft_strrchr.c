/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:08:48 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/07 14:19:14 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*res;

	res = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			res = (char*)(s + i);
		i++;
	}
	if (s[i] == c)
		res = (char*)(s + i);
	return (res);
}

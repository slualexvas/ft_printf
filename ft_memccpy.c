/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:36:10 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/09 13:58:45 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const char	*s_src;
	char		*s_dst;
	size_t		i;

	s_src = src;
	s_dst = dst;
	i = 0;
	while (i < n)
	{
		s_dst[i] = s_src[i];
		if (s_dst[i] == c)
			break ;
		i++;
	}
	if (i == n)
		return (NULL);
	else
		return (dst + i + 1);
}

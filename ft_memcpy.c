/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:28:44 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/28 11:04:21 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*s_src;
	char		*s_dst;
	size_t		i;

	s_src = src;
	s_dst = dst;
	if (src < dst)
	{
		i = n;
		while (--i < n)
			s_dst[i] = s_src[i];
	}
	else
	{
		i = 0;
		--i;
		while (++i < n)
			s_dst[i] = s_src[i];
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 12:14:52 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/09 13:54:58 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*s;
	size_t	i;

	s = (char*)malloc(size);
	if (s != NULL)
	{
		i = 0;
		while (i < size)
			s[i++] = '\0';
	}
	return (void*)(s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 14:48:21 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/09 13:52:33 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;

	if (s == NULL)
		return (NULL);
	if (start + len > ft_strlen(s))
		return (NULL);
	s1 = ft_strnew(len);
	if (s1 == NULL)
		return (NULL);
	ft_memcpy(s1, (char*)(s + start), len);
	s1[len] = '\0';
	return (s1);
}

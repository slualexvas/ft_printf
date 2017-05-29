/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 14:48:21 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/04 15:23:45 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	n1;
	size_t	n2;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	if (s1 != NULL && s2 == NULL)
		return (ft_strdup(s1));
	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	s = ft_strnew(n1 + n2);
	if (s == NULL)
		return (NULL);
	ft_memcpy((void*)s, (void*)s1, n1);
	ft_memcpy((void*)(s + n1), (void*)s2, n2);
	s[n1 + n2] = '\0';
	return (s);
}

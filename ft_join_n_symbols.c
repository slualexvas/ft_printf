/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_n_symbols.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 19:21:43 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/14 19:41:53 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join_n_symbols(char *s, char c, int n, int is_before)
{
	char	*res;
	int		s_len;
	int		i;

	if (n <= 0)
		return (ft_strdup(s));
	s_len = ft_strlen(s);
	res = ft_strnew(s_len + n);
	i = 0;
	if (is_before == 0)
	{
		ft_strcpy(res, s);
		i = s_len;
		while (i < s_len + n)
			res[i++] = c;
	}
	else
	{
		ft_strcpy(res + n, s);
		i = 0;
		while (i < n)
			res[i++] = c;
	}
	return (res);
}

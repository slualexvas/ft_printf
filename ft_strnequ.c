/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 14:37:53 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/09 14:09:01 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		res;

	res = 0;
	if (s1 != NULL && s2 != NULL)
		if (ft_strncmp(s1, s2, n) == 0)
			res = 1;
	return (res);
}

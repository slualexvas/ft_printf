/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 07:01:16 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/04 07:23:04 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_int(char *s)
{
	int		i;
	char	*s1;
	int		res;

	i = 0;
	res = 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\v' || s[i] == '\f'
			|| s[i] == '\r' || s[i] == '\n')
		i++;
	if (s[i] == '+')
		i++;
	if (s[i - 1] == '+' && s[i] == '-')
		res = 0;
	while (s[i] == '0')
		i++;
	if (s[i] == '\0')
		i--;
	s1 = ft_itoa(ft_atoi(s + i));
	if (ft_strcmp(s + i, s1) != 0)
		res = 0;
	ft_strdel(&s1);
	return (res);
}

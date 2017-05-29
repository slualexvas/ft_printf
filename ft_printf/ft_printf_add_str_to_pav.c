/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add_str_to_pav.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 11:39:31 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/29 10:58:37 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_printf_add_str_to_pav(t_pav *pav, const char *s, size_t s_len)
{
	char	*s1;
	char	**pstr;

	pstr = pav->pstr;
	if (*pstr == NULL)
	{
		(*pstr) = ft_strnew(s_len);
		ft_memcpy(*pstr, s, s_len);
		pav->res = s_len;
		return (1);
	}
	s1 = ft_strnew(pav->res);
	if (s1 == NULL)
		return (-1);
	ft_memcpy(s1, *pstr, pav->res);
	ft_strdel(pstr);
	(*pstr) = ft_strnew((size_t)pav->res + s_len);
	if (*pstr == NULL)
		return (-1);
	ft_memcpy(*pstr, s1, pav->res);
	ft_memcpy(((*pstr) + pav->res), s, s_len);
	ft_strdel(&s1);
	pav->res += s_len;
	return (1);
}

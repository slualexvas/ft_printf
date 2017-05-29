/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_v.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 10:32:34 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/29 15:13:05 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_vec_to_str(t_vec v, int precision)
{
	char	*res;
	char	*res1;

	res1 = NULL;
	ft_sprintf(&res1, "(%%.%df ; %%.%df ; %%.%df)",
			precision, precision, precision);
	res = NULL;
	if (precision > 1)
		ft_sprintf(&res, res1, v.x, v.y, v.z);
	return (res);
}

void	ft_printf_v(t_pav *pav)
{
	t_vec	v;
	int		precision;
	char	*s;

	if (pav->pcv.conv_char != 'v')
		return ;
	v = va_arg(pav->args, t_vec);
	precision = 6;
	if (pav->pcv.precision != -1)
		precision = pav->pcv.precision;
	s = ft_vec_to_str(v, precision);
	ft_printf_add_str_using_width(pav, s, ft_strlen(s));
	ft_strdel(&s);
}

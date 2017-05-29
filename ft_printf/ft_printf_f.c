/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 19:46:15 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/29 11:52:36 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_printf_f(t_pav *pav)
{
	double	f;
	int		precision;
	char	*s;

	if (ft_tolower(pav->pcv.conv_char) != 'f')
		return ;
	if (pav->pcv.len_modifier != PRINTF_LEN_LL)
		f = va_arg(pav->args, double);
	else
		f = va_arg(pav->args, long double);
	precision = 6;
	if (pav->pcv.precision != -1)
		precision = pav->pcv.precision;
	s = ft_longdouble_to_str_base(f, 10, 0, precision);
	ft_printf_add_str_using_width(pav, s, ft_strlen(s));
	ft_strdel(&s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 12:44:50 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/29 16:34:35 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

intmax_t			ft_printf_di_get_var(t_pav *pav)
{
	intmax_t	n;

	n = va_arg(pav->args, intmax_t);
	if (pav->pcv.len_modifier == 0)
		n = (int)n;
	else if (pav->pcv.len_modifier == PRINTF_LEN_L)
		n = (long int)n;
	else if (pav->pcv.len_modifier == PRINTF_LEN_H)
		n = (short int)n;
	else if (pav->pcv.len_modifier == PRINTF_LEN_LL)
		n = (long long int)n;
	else if (pav->pcv.len_modifier == PRINTF_LEN_HH)
		n = (signed char)n;
	else if (pav->pcv.len_modifier == PRINTF_LEN_Z)
		n = (size_t)n;
	return (n);
}

void				ft_printf_di_get_sign(t_pav *pav, intmax_t n)
{
	if (n < 0)
		pav->pcv.sign = '-';
	else if (n >= 0 && pav->pcv.plus == 1)
		pav->pcv.sign = '+';
	else if (n >= 0 && pav->pcv.space == 1)
		pav->pcv.sign = ' ';
}

void				ft_printf_di(t_pav *pav)
{
	intmax_t	n;
	uintmax_t	nabs;
	char		*s;
	size_t		min_ndigits;

	if (ft_strchr("di", pav->pcv.conv_char) == NULL)
		return ;
	n = ft_printf_di_get_var(pav);
	if (n < 0)
		nabs = (uintmax_t)(-(n + 1) + 1);
	else
		nabs = (uintmax_t)n;
	min_ndigits = pav->pcv.precision;
	if (pav->pcv.precision < 0)
		min_ndigits = 0;
	s = ft_uintmax_to_str_base(nabs, 10, 0, min_ndigits);
	ft_printf_di_get_sign(pav, n);
	if (n == 0 && pav->pcv.precision == 0)
		s[0] = '\0';
	ft_printf_add_str_using_width(pav, s, ft_strlen(s));
	ft_strdel(&s);
}

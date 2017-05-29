/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_boux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:35:39 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/29 15:34:38 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

uintmax_t		ft_printf_boux_get_var(t_pav *pav)
{
	uintmax_t	n;

	n = va_arg(pav->args, uintmax_t);
	if (pav->pcv.len_modifier == 0)
		n = (unsigned int)n;
	else if (pav->pcv.len_modifier == PRINTF_LEN_L)
		n = (unsigned long int)n;
	else if (pav->pcv.len_modifier == PRINTF_LEN_H)
		n = (unsigned short int)n;
	else if (pav->pcv.len_modifier == PRINTF_LEN_LL)
		n = (unsigned long long int)n;
	else if (pav->pcv.len_modifier == PRINTF_LEN_HH)
		n = (unsigned char)n;
	return (n);
}

unsigned char	ft_printf_base_by_char(char c)
{
	if (c == 'b')
		return (2);
	else if (c == 'o')
		return (8);
	else if (c == 'u')
		return (10);
	else if (c == 'x' || c == 'X')
		return (16);
	else
		return (0);
}

void			ft_printf_boux(t_pav *pav)
{
	uintmax_t	n;
	char		*s;
	size_t		min_ndigits;

	if (ft_strchr("ouxXb", pav->pcv.conv_char) == NULL)
		return ;
	n = ft_printf_boux_get_var(pav);
	min_ndigits = pav->pcv.precision;
	if (pav->pcv.precision < 0)
		min_ndigits = 0;
	s = ft_uintmax_to_str_base(n, ft_printf_base_by_char(pav->pcv.conv_char),
			ft_isupper(pav->pcv.conv_char), min_ndigits);
	if (n == 0 && pav->pcv.precision == 0)
		s[0] = '\0';
	ft_printf_add_str_using_width(pav, s, ft_strlen(s));
	ft_strdel(&s);
}

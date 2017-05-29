/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 18:55:46 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/29 15:34:20 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_wstrlen(const wchar_t *ws)
{
	size_t	res;

	res = 0;
	while (*(ws++) != L'\0')
		res++;
	return (res);
}

void	ft_wcstombs(wchar_t *s, char **s1, size_t *s1_len, int ws_len)
{
	int		s_len;
	char	*s2;
	int		ws_i;

	if (ws_len < 0)
		ws_len = (int)ft_wstrlen(s);
	s_len = (int)(ws_len * sizeof(wchar_t));
	*s1 = ft_strnew(s_len);
	s2 = *s1;
	ws_i = 0;
	while (*s != L'\0' && ws_i < ws_len)
	{
		ft_wctomb(*s, s2, &s_len);
		s2 += s_len;
		ws_i++;
		s++;
	}
	(*s1_len) = (int)(s2 - (*s1));
}

void	ft_printf_uppercase_s(t_pav *pav)
{
	wchar_t		*s;
	char		*s1;
	size_t		s1_len;

	if (pav->pcv.conv_char != 'S')
		return ;
	s = va_arg(pav->args, wchar_t*);
	if (s == NULL)
		ft_wcstombs(L"(null)", &s1, &s1_len, pav->pcv.precision);
	else
		ft_wcstombs(s, &s1, &s1_len, pav->pcv.precision);
	if ((int)s1_len > pav->pcv.precision && pav->pcv.precision >= 0)
		s1_len = (size_t)pav->pcv.precision;
	ft_printf_add_str_using_width(pav, s1, s1_len);
	ft_strdel(&s1);
}

void	ft_printf_s(t_pav *pav)
{
	char	*s;
	size_t	s_len;
	char	*s1;

	ft_printf_uppercase_s(pav);
	if (pav->pcv.conv_char != 's' || pav->pcv.conv_printed != 0)
		return ;
	if (pav->pcv.len_modifier == PRINTF_LEN_L)
	{
		pav->pcv.conv_char = 'S';
		ft_printf_uppercase_s(pav);
		if (pav->pcv.conv_printed != 0)
			return ;
	}
	s1 = va_arg(pav->args, char*);
	if (s1 == NULL)
		s = ft_strdup("(null)");
	else
		s = ft_strdup(s1);
	s_len = ft_strlen(s);
	if (pav->pcv.precision != -1 && s_len > (size_t)pav->pcv.precision)
		s_len = (int)pav->pcv.precision;
	ft_printf_add_str_using_width(pav, s, s_len);
	ft_strdel(&s);
}

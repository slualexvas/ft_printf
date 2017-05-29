/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 12:58:30 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/29 16:54:17 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_printf_uppercase_c(t_pav *pav)
{
	if (pav->pcv.conv_char != 'C' || pav->pcv.conv_printed == 1)
		return ;
	pav->pcv.conv_char = 'c';
	pav->pcv.len_modifier = PRINTF_LEN_L;
}

void		ft_wctomb_part2(wchar_t c, char *s, int *s_len)
{
	if (c <= 0x10FFFF)
	{
		s[0] = (c >> 18) + 0xF0;
		s[1] = ((c >> 12) & 0x3F) + 0x80;
		s[2] = ((c >> 6) & 0x3F) + 0x80;
		s[3] = (c & 0x3F) + 0x80;
		*s_len = 4;
	}
	else
		*s_len = 0;
}

void		ft_wctomb(wchar_t c, char *s, int *s_len)
{
	if (c <= 0x7F)
	{
		s[0] = c;
		*s_len = 1;
	}
	else if (c <= 0x7FF)
	{
		s[0] = (c >> 6) + 0xC0;
		s[1] = (c & 0x3F) + 0x80;
		*s_len = 2;
	}
	else if (c <= 0xFFFF)
	{
		s[0] = (c >> 12) + 0xE0;
		s[1] = ((c >> 6) & 0x3F) + 0x80;
		s[2] = (c & 0x3F) + 0x80;
		*s_len = 3;
	}
	else if (c <= 0x10FFFF)
		ft_wctomb_part2(c, s, s_len);
	else
		*s_len = 0;
}

void		ft_printf_c(t_pav *pav)
{
	int		c;
	char	s[4];
	int		s_len;

	if (ft_tolower(pav->pcv.conv_char) != 'c' || pav->pcv.conv_printed == 1)
		return ;
	c = va_arg(pav->args, int);
	if (pav->pcv.len_modifier == 0)
		ft_printf_add_str_using_width(pav, (char*)&c, 1);
	else if (pav->pcv.len_modifier == PRINTF_LEN_L)
	{
		ft_wctomb(c, s, &s_len);
		ft_printf_add_str_using_width(pav, s, s_len);
	}
}

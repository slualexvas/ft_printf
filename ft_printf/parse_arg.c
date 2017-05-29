/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:00:52 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/29 16:33:48 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	parse_flags(t_pav *pav)
{
	char	c;

	c = pav->fmt[pav->i];
	while (ft_strchr("0-+ #", c) != NULL)
	{
		if (c == '#')
			pav->pcv.reshetka = 1;
		else if (c == '0')
			pav->pcv.zero = 1;
		else if (c == '-')
			pav->pcv.minus = 1;
		else if (c == '+')
			pav->pcv.plus = 1;
		else if (c == ' ')
			pav->pcv.space = 1;
		pav->i++;
		c = pav->fmt[pav->i];
	}
}

void	parse_minimum_field_width(t_pav *pav)
{
	if (ft_isdigit(pav->fmt[pav->i]) == 0)
		return ;
	pav->pcv.width = ft_atoi(pav->fmt + pav->i);
	while (ft_isdigit(pav->fmt[pav->i]) == 1)
		pav->i++;
}

void	parse_precision(t_pav *pav)
{
	if (pav->fmt[pav->i] != '.')
		return ;
	pav->i++;
	if (ft_isdigit(pav->fmt[pav->i]) != 0)
		pav->pcv.precision = ft_atoi(pav->fmt + pav->i);
	else
		pav->pcv.precision = 0;
	while (ft_isdigit(pav->fmt[pav->i]) == 1)
		pav->i++;
}

void	parse_length_modifier(t_pav *pav)
{
	char	c1;
	char	c2;

	c1 = pav->fmt[pav->i];
	c2 = '\0';
	if (c1 != '\0')
		c2 = pav->fmt[pav->i + 1];
	if (c1 == 'l' && c2 == 'l')
		pav->pcv.len_modifier = PRINTF_LEN_LL;
	else if (c1 == 'h' && c2 == 'h')
		pav->pcv.len_modifier = PRINTF_LEN_HH;
	else if (c1 == 'l')
		pav->pcv.len_modifier = PRINTF_LEN_L;
	else if (c1 == 'h')
		pav->pcv.len_modifier = PRINTF_LEN_H;
	else if (c1 == 'j')
		pav->pcv.len_modifier = PRINTF_LEN_J;
	else if (c1 == 'z')
		pav->pcv.len_modifier = PRINTF_LEN_Z;
	if (pav->pcv.len_modifier != 0)
		(pav->i)++;
	if (pav->pcv.len_modifier == PRINTF_LEN_LL
			|| pav->pcv.len_modifier == PRINTF_LEN_HH)
		(pav->i)++;
}

void	parse_arg(t_pav *pav)
{
	size_t	i1;

	if (pav->fmt[pav->i] != '%')
		return ;
	pav->i++;
	i1 = pav->i;
	parse_flags(pav);
	parse_minimum_field_width(pav);
	parse_precision(pav);
	parse_length_modifier(pav);
	if (pav->i < pav->fmt_len)
	{
		pav->pcv.conv_char = pav->fmt[pav->i];
		pav->i++;
	}
	pav->pcv.conv_len = pav->i - i1;
}

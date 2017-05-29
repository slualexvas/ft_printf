/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add_str_using_width.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 13:53:01 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/29 16:31:44 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_printf_use_reshetka(t_pav *pav, char *s, char **line_reshetka)
{
	if (pav->pcv.reshetka == 1)
	{
		if (pav->pcv.conv_char == 'o' && s[0] != '0')
		{
			(*line_reshetka) = ft_strdup("0");
		}
		else if (ft_tolower(pav->pcv.conv_char) == 'x' &&
				(pav->pcv.was_p != 0 || ft_atoi(s) != 0))
		{
			(*line_reshetka) = ft_strdup("0x");
			(*line_reshetka)[1] = pav->pcv.conv_char;
		}
	}
	if ((*line_reshetka) == NULL)
		(*line_reshetka) = ft_strdup("");
}

int			ft_printf_add_str_with_zeros(t_pav *pav,
				char *s, size_t s_len, int n_f)
{
	char	*s_f;
	char	*line_reshetka;

	line_reshetka = NULL;
	ft_printf_use_reshetka(pav, s, &line_reshetka);
	if (pav->pcv.sign != '\0')
		ft_printf_add_str_to_pav(pav, &(pav->pcv.sign), 1);
	ft_printf_add_str_to_pav(pav, line_reshetka, ft_strlen(line_reshetka));
	if (n_f > 0)
	{
		s_f = ft_strnew(n_f);
		ft_memset(s_f, '0', n_f);
		ft_printf_add_str_to_pav(pav, s_f, n_f);
		ft_strdel(&s_f);
	}
	ft_printf_add_str_to_pav(pav, s, s_len);
	return (1);
}

int			ft_printf_add_str_with_minus(t_pav *pav,
				char *s, size_t s_len, int n_f)
{
	char	*s_f;
	char	*line_reshetka;

	line_reshetka = NULL;
	ft_printf_use_reshetka(pav, s, &line_reshetka);
	if (pav->pcv.sign != '\0')
		ft_printf_add_str_to_pav(pav, &(pav->pcv.sign), 1);
	ft_printf_add_str_to_pav(pav, line_reshetka, ft_strlen(line_reshetka));
	ft_printf_add_str_to_pav(pav, s, s_len);
	if (n_f > 0)
	{
		s_f = ft_strnew(n_f);
		ft_memset(s_f, ' ', n_f);
		ft_printf_add_str_to_pav(pav, s_f, n_f);
		ft_strdel(&s_f);
	}
	return (1);
}

int			ft_printf_add_str_without_minus(t_pav *pav,
				char *s, size_t s_len, int n_f)
{
	char	*s_f;
	char	*line_reshetka;

	if (n_f > 0)
	{
		s_f = ft_strnew(n_f);
		ft_memset(s_f, ' ', n_f);
		ft_printf_add_str_to_pav(pav, s_f, n_f);
		ft_strdel(&s_f);
	}
	line_reshetka = NULL;
	ft_printf_use_reshetka(pav, s, &line_reshetka);
	if (pav->pcv.sign != '\0')
		ft_printf_add_str_to_pav(pav, &(pav->pcv.sign), 1);
	ft_printf_add_str_to_pav(pav, line_reshetka, ft_strlen(line_reshetka));
	ft_printf_add_str_to_pav(pav, s, s_len);
	return (1);
}

int			ft_printf_add_str_using_width(t_pav *pav, char *s, size_t s_len)
{
	int		n_f;
	char	*line_reshetka;

	line_reshetka = NULL;
	ft_printf_use_reshetka(pav, s, &line_reshetka);
	n_f = pav->pcv.width - s_len - ft_strlen(line_reshetka);
	if (pav->pcv.sign != '\0')
		n_f--;
	if (((ft_strchr("diouxX", pav->pcv.conv_char) == NULL)
		|| pav->pcv.precision == -1) && pav->pcv.zero == 1
			&& pav->pcv.conv_char != 'n' && pav->pcv.minus == 0)
		ft_printf_add_str_with_zeros(pav, s, s_len, n_f);
	else if (pav->pcv.minus == 0)
		ft_printf_add_str_without_minus(pav, s, s_len, n_f);
	else
		ft_printf_add_str_with_minus(pav, s, s_len, n_f);
	ft_strdel(&line_reshetka);
	pav->pcv.conv_printed = 1;
	return (1);
}

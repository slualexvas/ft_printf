/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pav.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/14 14:00:50 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/27 10:38:46 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	init_pcv(t_pcv *pcv)
{
	pcv->conv_printed = 0;
	pcv->reshetka = 0;
	pcv->zero = 0;
	pcv->minus = 0;
	pcv->plus = 0;
	pcv->space = 0;
	pcv->width = 0;
	pcv->conv_char = '\0';
	pcv->conv_len = 0;
	pcv->len_modifier = 0;
	pcv->precision = -1;
	pcv->sign = '\0';
	pcv->was_p = 0;
}

void	init_pav(t_pav *pav, char **pstr, const char *fmt, va_list args)
{
	pav->pstr = pstr;
	pav->fmt = fmt;
	va_copy(pav->args, args);
	pav->i = 0;
	pav->fmt_len = ft_strlen(fmt);
	pav->res = 0;
	init_pcv(&(pav->pcv));
}

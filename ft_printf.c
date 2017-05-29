/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 17:57:37 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/29 14:36:13 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	proceed_arg(t_pav *pav)
{
	if (pav == NULL)
		return ;
	ft_printf_c(pav);
	ft_printf_s(pav);
	ft_printf_di(pav);
	ft_printf_boux(pav);
	ft_printf_p(pav);
	ft_printf_uppercase_doucs(pav);
	ft_printf_f(pav);
	ft_printf_v(pav);
	ft_printf_percent(pav);
	ft_printf_default(pav);
}

void	seek_next_percent(t_pav *pav)
{
	size_t	i1;
	size_t	len;

	i1 = pav->i;
	while (pav->i < pav->fmt_len && pav->fmt[pav->i] != '%')
		(pav->i)++;
	len = (pav->i - i1);
	ft_printf_add_str_to_pav(pav, (char*)(pav->fmt + i1), len);
}

int		ft_vsprintf(char **pstr, const char *fmt, va_list args)
{
	t_pav	pav;

	init_pav(&pav, pstr, fmt, args);
	if (fmt == NULL)
		return (-1);
	while (pav.i < pav.fmt_len)
	{
		seek_next_percent(&pav);
		if (pav.fmt[pav.i] == '%')
		{
			init_pcv(&(pav.pcv));
			parse_arg(&pav);
			if (pav.pcv.conv_char != '\0')
				proceed_arg(&pav);
		}
	}
	return (pav.res);
}

int		ft_sprintf(char **pstr, const char *fmt, ...)
{
	va_list	ap;
	int		res;

	va_start(ap, fmt);
	res = ft_vsprintf(pstr, fmt, ap);
	va_end(ap);
	return (res);
}

int		ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		res;
	char	*s;

	s = NULL;
	va_start(ap, fmt);
	res = ft_vsprintf(&s, fmt, ap);
	va_end(ap);
	if (res > 0)
		write(1, s, res);
	ft_strdel(&s);
	return (res);
}

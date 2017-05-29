/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 20:04:41 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/26 20:08:50 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_printf_percent(t_pav *pav)
{
	if (pav->pcv.conv_char == '%')
	{
		ft_printf_add_str_using_width(pav, "%", 1);
	}
}

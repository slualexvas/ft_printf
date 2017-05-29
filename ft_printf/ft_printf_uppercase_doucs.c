/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_DOU.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 19:20:52 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/29 14:32:15 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_printf_uppercase_doucs(t_pav *pav)
{
	if (ft_strchr("DOU", pav->pcv.conv_char) != NULL)
	{
		pav->pcv.conv_char = ft_tolower(pav->pcv.conv_char);
		pav->pcv.len_modifier = PRINTF_LEN_L;
		ft_printf_c(pav);
		ft_printf_s(pav);
		ft_printf_di(pav);
		ft_printf_boux(pav);
	}
}

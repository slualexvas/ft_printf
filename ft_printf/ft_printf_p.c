/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 18:37:43 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/26 18:39:57 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_printf_p(t_pav *pav)
{
	if (pav->pcv.conv_char != 'p')
		return ;
	pav->pcv.conv_char = 'x';
	pav->pcv.len_modifier = PRINTF_LEN_L;
	pav->pcv.reshetka = 1;
	pav->pcv.was_p = 1;
	ft_printf_boux(pav);
}

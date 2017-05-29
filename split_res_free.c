/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_res_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:41:11 by oslutsky          #+#    #+#             */
/*   Updated: 2017/05/12 12:46:10 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	split_res_free(char ***split_res)
{
	int	i;

	if (split_res == NULL || (*split_res) == NULL)
		return ;
	i = 0;
	while ((*split_res)[i] != NULL)
		free((*split_res)[i++]);
	free(*split_res);
	(*split_res) = NULL;
}

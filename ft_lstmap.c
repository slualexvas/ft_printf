/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oslutsky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 21:28:44 by oslutsky          #+#    #+#             */
/*   Updated: 2016/12/09 13:46:48 by oslutsky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res_start;
	t_list	*res;

	if (lst == NULL)
		return (NULL);
	res = f(lst);
	res_start = res;
	lst = lst->next;
	while (lst != NULL)
	{
		res->next = f(lst);
		if (res->next == NULL)
			return (NULL);
		res = res->next;
		lst = lst->next;
	}
	return (res_start);
}

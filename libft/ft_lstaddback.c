/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmney <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 00:32:55 by hmney             #+#    #+#             */
/*   Updated: 2018/10/12 00:48:15 by hmney            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **begin_list, void const *content,
		size_t content_size)
{
	t_list *new_elem;
	t_list *temp;

	new_elem = ft_lstnew(content, content_size);
	if (*begin_list == NULL)
		*begin_list = new_elem;
	else
	{
		temp = *begin_list;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_elem;
	}
}

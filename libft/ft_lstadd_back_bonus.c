/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:51:22 by dongjlee          #+#    #+#             */
/*   Updated: 2022/03/13 18:23:26 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (lst == 0 || new == 0)
	{
		return ;
	}
	if ((*lst) == 0)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != 0)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	new->next = 0;
}

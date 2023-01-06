/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:45:21 by jnoh              #+#    #+#             */
/*   Updated: 2023/01/03 01:53:51 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	gnl_lstadd_back(t_gnllist **lst, t_gnllist *new)
{
	t_gnllist	*tmp;

	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp)
	{
		if (!(tmp->next))
			break ;
		tmp = tmp->next;
	}
	tmp->next = new;
}

void	gnl_update_lastbuffer(int fd, t_gnllist *lst, char *lastbuffer)
{
	t_gnllist	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->fd == fd)
		{
			tmp->lastbuffer = lastbuffer;
			return ;
		}
		tmp = tmp->next;
	}
	return ;
}

char	*gnl_getnode(int fd, t_gnllist **lst)
{
	t_gnllist	*tmp;
	t_gnllist	*new;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp->lastbuffer);
		tmp = tmp->next;
	}
	if (!(*lst) || !tmp)
	{
		new = (t_gnllist *)malloc(sizeof(t_gnllist));
		if (!new)
			return (0);
		new->fd = fd;
		new->lastbuffer = 0;
		new->next = 0;
		gnl_lstadd_back(lst, new);
		return (new->lastbuffer);
	}
	return (0);
}

int	gnl_get_line(char **buffer, char **lastbuffer, char **ret, int fd)
{
	int		read_size;
	char	*tmp;

	while (1)
	{
		if (gnl_strchr(*lastbuffer, '\n'))
		{
			*ret = gnl_strdup_until_add(*lastbuffer, '\n', '\n');
			tmp = *lastbuffer;
			*lastbuffer = gnl_strdup_until_add(gnl_strchr(tmp, '\n') \
				+ 1, 0, -1);
			gnl_free(&tmp);
			return (1);
		}
		read_size = read(fd, *buffer, BUFFER_SIZE);
		if (read_size < 0 || (read_size == 0 && !gnl_strchr(*lastbuffer, '\n')))
		{
			*ret = 0;
			return (read_size);
		}
		(*buffer)[read_size] = 0;
		tmp = *lastbuffer;
		*lastbuffer = gnl_strcat(tmp, *buffer);
		gnl_free(&tmp);
	}
}

char	*get_next_line(int fd)
{
	static t_gnllist	*list;
	char				*buffer;
	char				*ret;
	char				*lastbuffer;
	int					result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!(buffer))
		return (0);
	lastbuffer = gnl_getnode(fd, &list);
	result = gnl_get_line(&buffer, &lastbuffer, &ret, fd);
	gnl_free(&buffer);
	if (result == 0)
	{
		ret = gnl_strdup_until_add(lastbuffer, 0, -1);
		if ((ret && !ret[0]) || !lastbuffer || !lastbuffer[0])
			gnl_free(&ret);
	}
	gnl_update_lastbuffer(fd, list, lastbuffer);
	if (result <= 0)
		gnl_deletenode(&list, fd);
	return (ret);
}

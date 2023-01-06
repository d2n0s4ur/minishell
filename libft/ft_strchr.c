/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:46:09 by dongjlee          #+#    #+#             */
/*   Updated: 2023/01/01 15:46:52 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned char			target;
	int						i;
	int						flag;

	target = (unsigned char)c;
	flag = 0;
	i = 0;
	while (flag != 1)
	{
		if (s[i] == target)
		{
			return ((char *)s + i);
		}
		if (s[i] == '\0')
		{
			flag = 1;
		}
		i++;
	}
	return (0);
}

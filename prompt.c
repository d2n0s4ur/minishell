/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:10:31 by dongjlee          #+#    #+#             */
/*   Updated: 2023/01/03 17:37:01 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_status;

static char	*get_user(t_prompt prompt)
{
	char	**user;
	char	*temp;

	user = NULL;
	get_username(&user, "/usr/bin/whoami", "whoami", prompt.envp);
	if (!user)
		user = ft_extend_matrix(user, "guest");
	temp = ft_strjoin("", *user);
	ft_free_matrix(&user);
	return (temp);
}

char	*mini_getprompt(t_prompt prompt)
{
	char	*temp;
	char	*temp2;

	temp2 = get_user(prompt);
	temp = ft_strjoin(temp2, "@minishell $ ");
	free(temp2);
	return (temp);
}

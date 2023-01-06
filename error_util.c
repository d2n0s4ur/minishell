/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjlee <dongjlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:55:48 by dongjlee          #+#    #+#             */
/*   Updated: 2023/01/03 17:59:28 by dongjlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_atoi2_child(const char *nptr, long *nbr, int sign, int flag)
{
	int	len;

	len = ft_strlen(nptr);
	if (!ft_isdigit(*nptr))
		return (-1);
	while (ft_isdigit(*nptr))
	{
		*nbr = 10 * (*nbr) + (*nptr - '0');
		nptr++;
	}
	if (*nptr && !ft_isspace(*nptr))
		return (-1);
	if (!flag && (len >= 20 || (len == 19 && *nbr < 0)))
		return (-1);
	*nbr *= sign;
	return (0);
}

int	ft_atoi2(const char *nptr, long *nbr)
{
	int		sign;
	int		flag;

	sign = 1;
	*nbr = (long long int)0;
	flag = 0;
	if (!ft_strcmp(nptr, "-9223372036854775808"))
		flag = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
		sign = -sign;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	return (ft_atoi2_child(nptr, nbr, sign, flag));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:33:26 by avogt             #+#    #+#             */
/*   Updated: 2021/03/19 14:22:31 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mini.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result_tmp;

	result_tmp = 0;
	sign = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\r' || *str == '\f')
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
		result_tmp = (result_tmp * 10) + (*str++ - '0');
	return (result_tmp * sign);
}

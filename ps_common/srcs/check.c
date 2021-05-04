/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 13:28:43 by avogt             #+#    #+#             */
/*   Updated: 2021/05/03 13:42:45 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_common.h"

int	stack_is_empty(t_stack *stack)
{
	if (stack->first == NULL)
		return (1);
	return (0);
}

int	stack_is_sorted(t_stack *stack)
{
	t_list	*lst;
	int		is_sorted;

	is_sorted = -1;
	lst = stack->first;
	while (lst->next != NULL)
	{
		is_sorted = lst->number - lst->next->number;
		if (is_sorted >= 0)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	is_a_num(char *str)
{
	int	i;
	int neg;

	i = 0;
	neg = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] != '\0')
		return (0);
	return (ft_check_integer(str, neg));
}

int	ft_check_integer(char *s, int neg)
{
	const char	max[10] = "2147483647";
	int			i;

	i = -1;
	if (ft_strlen(s) == 0 || ft_strlen(s) - neg >= 11)
		return (0);
	else if (ft_strlen(s) - neg < 10)
		return (1);
	while (++i < 10)
	{
		if (i == 9)
		{
			if (neg == 1 && s[i + neg] > '8')
				return (0);
			else if (neg == 0 && s[i + neg] > '7')
				return (0);
		}
		else if (s[i + neg] < max[i])
			return (1);
		else if (s[i + neg] > max[i])
			return (0);
	}
	return (1);
}

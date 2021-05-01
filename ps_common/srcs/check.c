/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 13:28:43 by avogt             #+#    #+#             */
/*   Updated: 2021/04/29 15:30:06 by avogt            ###   ########.fr       */
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

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

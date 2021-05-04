/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates_ck.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:07:08 by avogt             #+#    #+#             */
/*   Updated: 2021/05/03 14:16:30 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static char	*inner_loop(t_stack *stack, int i, int num1, int max)
{
	int		j;
	t_list	*tmp2;

	tmp2 = stack->first;
	j = -1;
	while (++j < max)
	{
		if (i != j)
		{
			if (num1 == tmp2->number)
				return ("There is two same numbers");
		}
		tmp2 = tmp2->next;
	}
	return (NULL);
}

char		*check_duplicates_ck(t_stack *stack)
{
	int		i;
	t_list	*tmp;
	char	*s;
	int		max;

	max = stack_len(stack);
	s = NULL;
	tmp = stack->first;
	i = -1;
	while (++i < max)
	{
		s = inner_loop(stack, i, tmp->number, max);
		if (s != NULL)
			return (s);
		tmp = tmp->next;
	}
	return (NULL);
}

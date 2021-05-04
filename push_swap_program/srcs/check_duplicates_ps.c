/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates_ps.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:33:20 by avogt             #+#    #+#             */
/*   Updated: 2021/05/03 14:06:22 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	*inner_loop(t_helper *helper, t_stack *stack, int i, int num1)
{
	int		j;
	int		pos;
	t_list	*tmp2;

	pos = helper->len_stack - 1;
	tmp2 = stack->first;
	j = -1;
	while (++j < helper->len_stack)
	{
		if (i != j)
		{
			if (num1 == tmp2->number)
				return ("There is two same numbers");
			if (num1 < tmp2->number)
				pos--;
		}
		tmp2 = tmp2->next;
	}
	helper->tab[i] = pos;
	return (NULL);
}

char		*check_duplicates_ps(t_stack *stack, t_helper *helper)
{
	int		i;
	t_list	*tmp;
	char	*s;

	s = NULL;
	tmp = stack->first;
	i = -1;
	while (++i < helper->len_stack)
	{
		s = inner_loop(helper, stack, i, tmp->number);
		if (s != NULL)
			return (s);
		tmp = tmp->next;
	}
	return (NULL);
}

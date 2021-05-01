/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:31:33 by avogt             #+#    #+#             */
/*   Updated: 2021/04/26 18:29:21 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_two(t_helper *helper, t_operation **op, int stack)
{
	if (stack_is_sorted_tab(helper, stack))
		return ;
	if (stack == 0)
		refresh_helper(helper, 0, op);
	else
		refresh_helper(helper, 1, op);
}

void	sort_three(t_helper *helper, t_operation **op)
{
	int i;

	i = 0;
	if (helper->tab[i] > helper->tab[i + 1]
			&& helper->tab[i] > helper->tab[i + 2])
		refresh_helper(helper, 5, op);
	if (helper->tab[i] > helper->tab[i + 1]
			&& helper->tab[i] < helper->tab[i + 2])
		refresh_helper(helper, 0, op);
	if (helper->tab[i] < helper->tab[i + 1]
			&& helper->tab[i + 1] > helper->tab[i + 2])
	{
		refresh_helper(helper, 8, op);
		if (helper->tab[i] > helper->tab[i + 1])
			refresh_helper(helper, 0, op);
	}
	while (!(helper->tab[i] < helper->tab[i + 1]
			&& helper->tab[i + 1] < helper->tab[i + 2]))
		refresh_helper(helper, 5, op);
}

void	sort_five(t_helper *helper, t_operation **op)
{
	int	i;

	i = 2;
	while (++i < 5)
		refresh_helper(helper, 4, op);
	sort_three(helper, op);
	while (helper->end_stack2 - helper->end_stack1 > 0)
	{
		if (helper->tab[helper->end_stack1 + 1] >
				helper->tab[helper->end_stack1])
		{
			refresh_helper(helper, 3, op);
			refresh_helper(helper, 5, op);
			continue ;
		}
		while (helper->tab[helper->end_stack1 + 1] > helper->tab[0])
			refresh_helper(helper, 5, op);
		refresh_helper(helper, 3, op);
		while (helper->tab[0] > helper->tab[helper->end_stack1])
			refresh_helper(helper, 5, op);
	}
}

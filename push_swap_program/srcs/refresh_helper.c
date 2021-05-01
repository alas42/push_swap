/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:33:33 by avogt             #+#    #+#             */
/*   Updated: 2021/04/26 17:35:25 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	refresh_helper_swap(t_helper *helper, int n_op)
{
	int tmp;

	tmp = 0;
	if (n_op == 0)
	{
		tmp = helper->tab[0];
		helper->tab[0] = helper->tab[1];
		helper->tab[1] = tmp;
	}
	else if (n_op == 1)
	{
		tmp = helper->tab[helper->end_stack1 + 2];
		helper->tab[helper->end_stack1 + 2] =
			helper->tab[helper->end_stack1 + 1];
		helper->tab[helper->end_stack1 + 1] = tmp;
	}
	else
	{
		refresh_helper_swap(helper, 0);
		refresh_helper_swap(helper, 1);
	}
}

static void	refresh_helper_rotate(t_helper *helper, int n_op)
{
	int	i;
	int tmp;

	i = -1;
	tmp = 0;
	if (n_op == 5)
	{
		tmp = helper->tab[0];
		while (++i < helper->end_stack1)
			helper->tab[i] = helper->tab[i + 1];
		helper->tab[helper->end_stack1] = tmp;
	}
	else if (n_op == 6)
	{
		i = helper->end_stack1;
		tmp = helper->tab[helper->end_stack1 + 1];
		while (++i < helper->end_stack2)
			helper->tab[i] = helper->tab[i + 1];
		helper->tab[helper->end_stack2] = tmp;
	}
	else
	{
		refresh_helper_rotate(helper, 5);
		refresh_helper_rotate(helper, 6);
	}
}

static void	refresh_helper_rrotate(t_helper *helper, int n_op)
{
	int	i;
	int tmp;

	i = helper->end_stack1 + 1;
	tmp = 0;
	if (n_op == 8)
	{
		tmp = helper->tab[helper->end_stack1];
		while (--i > 0)
			helper->tab[i] = helper->tab[i - 1];
		helper->tab[0] = tmp;
	}
	else if (n_op == 9)
	{
		i = helper->end_stack2 + 1;
		tmp = helper->tab[helper->end_stack2];
		while (--i > helper->end_stack1 + 1)
			helper->tab[i] = helper->tab[i - 1];
		helper->tab[helper->end_stack1 + 1] = tmp;
	}
	else
	{
		refresh_helper_rrotate(helper, 8);
		refresh_helper_rrotate(helper, 9);
	}
}

static void	refresh_helper_push(t_helper *helper, int n_op)
{
	int	i;
	int tmp;

	i = -1;
	tmp = 0;
	if (n_op == 3)
	{
		tmp = helper->tab[helper->end_stack1 + 1];
		i = helper->end_stack1 + 2;
		while (--i > 0)
			helper->tab[i] = helper->tab[i - 1];
		helper->end_stack1++;
		helper->tab[0] = tmp;
	}
	else
	{
		tmp = helper->tab[0];
		while (++i < helper->end_stack1)
			helper->tab[i] = helper->tab[i + 1];
		helper->tab[helper->end_stack1] = tmp;
		helper->end_stack1--;
	}
}

void		refresh_helper(t_helper *helper, int n_op, t_operation **op)
{
	add_to_operation(op, n_op);
	if (n_op >= 0 && n_op <= 2)
		refresh_helper_swap(helper, n_op);
	else if (n_op >= 5 && n_op <= 7)
		refresh_helper_rotate(helper, n_op);
	else if (n_op >= 8 && n_op <= 10)
		refresh_helper_rrotate(helper, n_op);
	else
		refresh_helper_push(helper, n_op);
}

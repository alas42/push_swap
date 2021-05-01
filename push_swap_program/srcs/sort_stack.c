/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:32:36 by avogt             #+#    #+#             */
/*   Updated: 2021/04/29 15:46:56 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	loop_rotate(t_helper *helper, t_operation **op, int times, int s)
{
	if (times > 0)
		while (times-- > 0)
			refresh_helper(helper, 5 + s, op);
	else if (times < 0)
		while (times++ < 0)
			refresh_helper(helper, 8 + s, op);
}

int		get_rot_a(t_helper *helper, int block_num, int len_b)
{
	int i;
	int	tmp;

	tmp = 10000;
	i = -1;
	while (++i <= helper->end_stack1 / 2)
		if (helper->tab[i] / len_b == block_num)
		{
			tmp = i;
			break ;
		}
	i = -1;
	while (++i <= helper->end_stack1 / 2)
		if (helper->tab[helper->end_stack1 - i] / len_b == block_num)
		{
			if (tmp * -1 < (i + 1) * -1)
				tmp = (i + 1) * -1;
			break ;
		}
	if (tmp == 10000)
		tmp = 0;
	return (tmp);
}

int		get_rot_b(t_helper *helper, int len_b, int max)
{
	int i;

	i = -1;
	while (++i < len_b)
		if (helper->tab[helper->end_stack1 + 1 + i] == max)
			return (i);
	i = -1;
	while (++i < len_b)
		if (helper->tab[helper->end_stack2 - i] == max)
			return ((i + 1) * -1);
	return (0);
}

int		stack_is_sorted_tab(t_helper *helper, int stack)
{
	int	i;
	int	is_sorted;

	if (stack == 0)
	{
		i = 0;
		while (i < helper->end_stack1)
		{
			is_sorted = helper->tab[i] - helper->tab[i + 1];
			if (is_sorted >= 0)
				return (0);
			i++;
		}
		return (1);
	}
	i = helper->end_stack1 + 1;
	while (i < helper->end_stack2)
	{
		is_sorted = helper->tab[i] - helper->tab[i + 1];
		if (is_sorted <= 0)
			return (0);
		i++;
	}
	return (1);
}

void	sort_stack(t_helper *helper, t_operation **op)
{
	int nb;

	nb = 1;
	if (helper->len_stack == 1)
		return ;
	else if (helper->len_stack == 2)
		sort_two(helper, op, 0);
	else if (helper->len_stack == 3)
		sort_three(helper, op);
	else if (helper->len_stack == 5)
		sort_five(helper, op);
	else
	{
		if (helper->len_stack < 100)
			nb = helper->len_stack / 2;
		if (helper->len_stack >= 100)
			nb = helper->len_stack / 6;
		if (helper->len_stack >= 400)
			nb = helper->len_stack / 11;
		sort_many(helper, op, nb);
	}
}

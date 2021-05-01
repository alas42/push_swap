/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:36:40 by avogt             #+#    #+#             */
/*   Updated: 2021/04/29 15:56:37 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_n_blocks(int len_stack, int len_block, int *last_block)
{
	int	blocks;

	blocks = len_stack / len_block;
	if (len_stack % len_block != 0)
	{
		*last_block = len_stack % len_block;
		blocks++;
	}
	return (blocks);
}

static void	get_blocks_in_b(t_helper *helper,
		t_operation **op, int len_b, int last)
{
	int i;
	int k;
	int rotations;

	i = -1;
	while (++i < helper->blocks)
	{
		k = -1;
		rotations = 0;
		if (i == helper->blocks - 1)
			len_b = last;
		while (++k < len_b)
		{
			if (i == helper->blocks - 1)
			{
				refresh_helper(helper, 4, op);
				continue ;
			}
			rotations = get_rot_a(helper, i, len_b);
			loop_rotate(helper, op, rotations, 0);
			refresh_helper(helper, 4, op);
		}
	}
}

static void	get_blocks_in_a(t_helper *helper, t_operation **op,
		int len_b, int first)
{
	int i;
	int k;
	int	rotations;
	int odd_block;

	odd_block = first;
	i = -1;
	while (++i < helper->blocks)
	{
		k = -1;
		rotations = 0;
		if (i > 0)
			first = len_b;
		while (++k < first)
		{
			rotations = get_rot_b(helper, first - k,
					helper->len_stack - odd_block -
					(first * i) + (first - (k + 1)));
			if (i == 0)
				rotations = get_rot_b(helper, first - k,
					helper->len_stack - (k + 1));
			loop_rotate(helper, op, rotations, 1);
			refresh_helper(helper, 3, op);
		}
	}
}

void		sort_many(t_helper *helper, t_operation **op, int len)
{
	int last;

	last = len;
	helper->blocks = get_n_blocks(helper->len_stack, len, &last);
	get_blocks_in_b(helper, op, len, last);
	get_blocks_in_a(helper, op, len, last);
}

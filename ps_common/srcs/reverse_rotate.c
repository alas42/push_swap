/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:12:50 by avogt             #+#    #+#             */
/*   Updated: 2021/04/27 17:40:59 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_common.h"

static void	reverse_rotate(t_stack *stack)
{
	int n_loop;
	int i;

	i = 0;
	n_loop = stack_len(stack) - 1;
	while (i < n_loop)
	{
		rotate_stack(stack);
		i++;
	}
}

void		reverse_rotate_stack(t_stack *stack)
{
	int		len_stack;

	len_stack = stack_len(stack);
	if (len_stack > 1)
		reverse_rotate(stack);
}

void		reverse_rotate_all(t_stack *stack1, t_stack *stack2)
{
	reverse_rotate_stack(stack1);
	reverse_rotate_stack(stack2);
}

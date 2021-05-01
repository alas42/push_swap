/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:13:46 by avogt             #+#    #+#             */
/*   Updated: 2021/04/26 17:48:49 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_common.h"

static void	swap(t_stack *stack)
{
	t_list	*tmp;
	t_list	*tmp_first;

	tmp = stack->first->next->next;
	tmp_first = stack->first;
	stack->first = stack->first->next;
	stack->first->next = tmp_first;
	stack->first->next->next = tmp;
}

void		swap_stack(t_stack *stack)
{
	if (stack_len(stack) > 1)
		swap(stack);
}

void		swap_all(t_stack *stack1, t_stack *stack2)
{
	swap_stack(stack1);
	swap_stack(stack2);
}

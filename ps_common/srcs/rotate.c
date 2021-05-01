/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:12:07 by avogt             #+#    #+#             */
/*   Updated: 2021/04/27 16:38:01 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_common.h"

static void	rotate(t_stack *stack)
{
	t_list	*first;
	t_list	*tmp;

	first = stack->first;
	stack->first = stack->first->next;
	tmp = stack->first;
	while (tmp->next != NULL)
		tmp = tmp->next;
	first->next = NULL;
	tmp->next = first;
}

void		rotate_stack(t_stack *stack)
{
	if (stack_len(stack) > 1)
		rotate(stack);
}

void		rotate_all(t_stack *stack1, t_stack *stack2)
{
	rotate_stack(stack1);
	rotate_stack(stack2);
}

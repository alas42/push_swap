/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:13:25 by avogt             #+#    #+#             */
/*   Updated: 2021/04/26 17:47:46 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_common.h"

static void	push(t_stack *stack1, t_stack *stack2)
{
	t_list	*tmp[2];

	if (stack2->first == NULL)
	{
		tmp[0] = stack1->first->next;
		tmp[1] = NULL;
		stack2->first = stack1->first;
		stack2->first->next = tmp[1];
		stack1->first = tmp[0];
	}
	else
	{
		tmp[0] = stack1->first->next;
		tmp[1] = stack2->first;
		stack2->first = stack1->first;
		stack2->first->next = tmp[1];
		stack1->first = tmp[0];
	}
}

void		push_stack(t_stack *stack1, t_stack *stack2)
{
	if (stack_len(stack1) > 0)
		push(stack1, stack2);
	else
		return ;
}

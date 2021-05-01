/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 18:06:36 by avogt             #+#    #+#             */
/*   Updated: 2021/04/26 17:48:22 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_common.h"

static void	free_stack(t_stack *stack)
{
	t_list	*ptr;

	ptr = NULL;
	while (stack->first)
	{
		ptr = stack->first;
		stack->first = stack->first->next;
		free(ptr);
	}
	free(stack);
}

void		free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a != NULL)
		free_stack(stack_a);
	if (stack_b != NULL)
		free_stack(stack_b);
}

void		free_operations(t_operation *operation)
{
	t_operation *ptr;

	ptr = NULL;
	while (operation)
	{
		ptr = operation;
		operation = operation->next;
		free(ptr);
	}
	operation = NULL;
}

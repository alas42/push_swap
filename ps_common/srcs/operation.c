/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:33:23 by avogt             #+#    #+#             */
/*   Updated: 2021/04/26 17:48:05 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_common.h"

static void	print_operations(t_operation *tmp)
{
	if (tmp->op == 0)
		printf("sa\n");
	else if (tmp->op == 1)
		printf("sb\n");
	else if (tmp->op == 2)
		printf("ss\n");
	else if (tmp->op == 3)
		printf("pa\n");
	else if (tmp->op == 4)
		printf("pb\n");
	else if (tmp->op == 5)
		printf("ra\n");
	else if (tmp->op == 6)
		printf("rb\n");
	else if (tmp->op == 7)
		printf("rr\n");
	else if (tmp->op == 8)
		printf("rra\n");
	else if (tmp->op == 9)
		printf("rrb\n");
	else
		printf("rrr\n");
}

int			operation_len(t_operation *operation)
{
	t_operation	*tmp;
	int			len;

	len = 0;
	tmp = operation;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

void		loop_print_operation(t_operation *operation)
{
	t_operation	*tmp;

	tmp = operation;
	while (tmp != NULL)
	{
		print_operations(tmp);
		tmp = tmp->next;
	}
}

char		*add_to_operation(t_operation **operation, int op)
{
	t_operation	*new;
	t_operation	*tmp;

	tmp = NULL;
	new = NULL;
	new = (t_operation *)malloc(sizeof(t_operation));
	if (new == NULL)
		return ("Failed allocation for the operations");
	new->op = op;
	new->next = NULL;
	if (*operation)
	{
		tmp = *operation;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*operation = new;
	return (NULL);
}

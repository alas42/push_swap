/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:08:47 by avogt             #+#    #+#             */
/*   Updated: 2021/04/29 15:30:01 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	direct_operations(t_stack *a, t_stack *b, t_operation *tmp)
{
	if (tmp->op == 0)
		swap_stack(a);
	else if (tmp->op == 1)
		swap_stack(b);
	else if (tmp->op == 2)
		swap_all(a, b);
	else if (tmp->op == 3)
		push_stack(b, a);
	else if (tmp->op == 4)
		push_stack(a, b);
	else if (tmp->op == 5)
		rotate_stack(a);
	else if (tmp->op == 6)
		rotate_stack(b);
	else if (tmp->op == 7)
		rotate_all(a, b);
	else if (tmp->op == 8)
		reverse_rotate_stack(a);
	else if (tmp->op == 9)
		reverse_rotate_stack(b);
	else
		reverse_rotate_all(a, b);
}

static int	execute_operations(t_stack *a, t_stack *b, t_operation *operation)
{
	t_operation	*tmp;

	tmp = operation;
	while (tmp)
	{
		direct_operations(a, b, tmp);
		tmp = tmp->next;
	}
	if (!stack_is_empty(b))
		printf("KO\n");
	if (stack_is_sorted(a))
		printf("OK\n");
	else
		printf("KO\n");
	free_operations(operation);
	free_stacks(a, b);
	return (1);
}

int			main(int argc, char *argv[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_operation	*operation;
	char		*str;
	int			len_stack;

	len_stack = 0;
	str = NULL;
	operation = NULL;
	stack_a = initalize_stack();
	stack_b = initalize_stack();
	if (stack_a == NULL || stack_b == NULL)
		ft_error("Failed allocation for the stacks", stack_a, stack_b);
	if (argc < 2)
		ft_quit(stack_a, stack_b);
	str = fill_stack(argc, argv, stack_a, &len_stack);
	if (str != NULL)
		ft_error(str, stack_a, stack_b);
	str = parse_stdin(&operation);
	if (str != NULL)
	{
		free_operations(operation);
		ft_error(str, stack_a, stack_b);
	}
	return (execute_operations(stack_a, stack_b, operation));
}

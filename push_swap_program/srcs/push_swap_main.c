/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:25:51 by avogt             #+#    #+#             */
/*   Updated: 2021/05/03 14:08:01 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*prologue(t_stack *a, t_stack *b, t_helper *helper, char *argv[])
{
	int		len_stack;
	char	*str;
	int		nb_args;

	nb_args = 0;
	str = NULL;
	len_stack = 0;
	while (argv[nb_args] != NULL)
		nb_args++;
	str = fill_stack(nb_args, argv, a, &len_stack);
	initialize_helper(helper, len_stack);
	if (helper->len_stack == -1)
		ft_error("Failed allocation", a, b, helper);
	if (helper->len_stack == 1)
		return (NULL);
	if (str != NULL)
		ft_error(str, a, b, helper);
	str = check_duplicates_ps(a, helper);
	if (str != NULL)
		ft_error(str, a, b, helper);
	return (NULL);
}

int		ending_print(t_operation *op)
{
	loop_print_operation(op);
	free_operations(op);
	return (1);
}

int		main(int argc, char *argv[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_operation	*operation;
	t_helper	*helper;

	helper = NULL;
	operation = NULL;
	stack_a = initalize_stack();
	stack_b = initalize_stack();
	if (stack_a == NULL || stack_b == NULL)
		ft_error("Failed allocation for the stacks", stack_a, stack_b, NULL);
	if (argc < 2)
		ft_quit(stack_a, stack_b);
	helper = (t_helper *)malloc(sizeof(t_helper));
	if ((!helper))
		ft_error("Failed allocation", stack_a, stack_b, helper);
	prologue(stack_a, stack_b, helper, argv);
	sort_stack(helper, &operation);
	ending_print(operation);
	free_stacks(stack_a, stack_b);
	free(helper->tab);
	free(helper);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 13:32:00 by avogt             #+#    #+#             */
/*   Updated: 2021/04/30 10:50:26 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_common.h"

void	add_to_stack(t_stack *stack, int n)
{
	t_list	*new;
	t_list	*tmp;

	tmp = stack->first;
	new = malloc(sizeof(t_list));
	if (new == NULL)
		exit(EXIT_FAILURE);
	new->number = n;
	new->next = NULL;
	if (stack->first == NULL)
		stack->first = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
/*
char	*check_integer(char *s)
{
	
}
*/
char	*fill_stack_string(char *argv[], t_stack *stack, int *len_stack)
{
	char	**args;
	int		i;
	int		n;

	i = 0;
	n = 0;
	args = ft_split(argv[1], ' ');
	if (args == NULL)
		return ("Failed to malloced the tab from argv[1]");
	while (args[i] != NULL)
	{
		if (!is_a_num(args[i]))
			return ("an argument is not an int");
		n = ft_atoi(args[i]);
		if (!(n <= INT_MAX && n >= INT_MIN))
			printf("%d\n", n);
		add_to_stack(stack, n);
		i++;
		*len_stack = *len_stack + 1;
	}
	return (NULL);
}

char	*fill_stack(int argc, char *argv[], t_stack *stack, int *len_stack)
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	if (argc == 2)
		return (fill_stack_string(argv, stack, len_stack));
	while (i < argc)
	{
		if (!is_a_num(argv[i]))
			return ("an argument is not an int");
		n = ft_atoi(argv[i]);
		if (!(n <= INT_MAX && n >= INT_MIN))
			printf("%d\n", n);
		add_to_stack(stack, n);
		*len_stack = *len_stack + 1;
		i++;
	}
	return (NULL);
}

t_stack	*initalize_stack(void)
{
	t_stack *stack;

	stack = NULL;
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->first = NULL;
	return (stack);
}

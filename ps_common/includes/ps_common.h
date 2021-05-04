/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_common.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:45:02 by avogt             #+#    #+#             */
/*   Updated: 2021/05/03 14:02:47 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_COMMON_H
# define PS_COMMON_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../../libft_mini/libft_mini.h"

typedef struct			s_list
{
	int					number;
	struct s_list		*next;
}						t_list;

typedef struct			s_stack
{
	struct s_list		*first;
}						t_stack;

typedef struct			s_operation
{
	int					op;
	struct s_operation	*next;
}						t_operation;

typedef struct			s_helper
{
	int					len_stack;
	int					*tab;
	int					end_stack1;
	int					end_stack2;
	int					blocks;
}						t_helper;

int						stack_len(t_stack *stack);
void					print_operation(t_operation *operation);
void					loop_print_operation(t_operation *operation);
void					free_operations(t_operation *operation);
void					free_stacks(t_stack *stack_a, t_stack *stack_b);
void					free_onestring(char **args);
void					ft_error(char *s, t_stack *a, t_stack *b, t_helper *h);
void					ft_quit(t_stack *stack_a, t_stack *stack_b);
int						stack_is_sorted(t_stack *stack);
int						stack_is_empty(t_stack *stack);
int						is_a_num(char *str);
t_stack					*initalize_stack(void);
void					add_to_stack(t_stack *stack, int n);
char					*fill_stack_string(char *av[], t_stack *s, int *len);
char					*fill_stack(int ac, char *av[], t_stack *s, int *len);
char					*add_to_operation(t_operation **operation, int op);
void					swap_stack(t_stack *stack);
void					swap_all(t_stack *stack_a, t_stack *stack_b);
void					push_stack(t_stack *stack1, t_stack *stack2);
void					rotate_stack(t_stack *stack);
void					rotate_all(t_stack *stack_a, t_stack *stack_b);
void					reverse_rotate_stack(t_stack *stack);
void					reverse_rotate_all(t_stack *stack_a, t_stack *stack_b);
int						ft_check_integer(char *s, int neg);
char					*check_duplicates(t_stack *stack, t_helper *helper);
#endif

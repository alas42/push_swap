/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:09:24 by avogt             #+#    #+#             */
/*   Updated: 2021/05/03 14:21:22 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../ps_common/includes/ps_common.h"

char			*prologue(t_stack *a, t_stack *b, t_helper *h, char *av[]);
int				ending_print(t_operation *op);
void			sort_stack(t_helper *helper, t_operation **op);
int				stack_is_sorted_tab(t_helper *helper, int stack);
void			initialize_helper(t_helper *helper, int len_stack);
void			refresh_helper(t_helper *helper, int n_op, t_operation **op);
void			sort_two(t_helper *helper, t_operation **op, int stack);
void			sort_three(t_helper *helper, t_operation **op);
void			sort_five(t_helper *helper, t_operation **op);
void			sort_many(t_helper *h, t_operation **op, int len);
int				get_rot_b(t_helper *helper, int len_b, int max);
int				get_rot_a(t_helper *helper, int block_num, int len_b);
void			loop_rotate(t_helper *helper, t_operation **op,
				int times, int s);
char			*check_duplicates_ps(t_stack *stack, t_helper *helper);
#endif

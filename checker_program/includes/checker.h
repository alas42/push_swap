/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avogt <avogt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:08:52 by avogt             #+#    #+#             */
/*   Updated: 2021/05/03 14:14:36 by avogt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../ps_common/includes/ps_common.h"

char			*parse_stdin(t_operation **operation);
char			*check_duplicates_ck(t_stack *stack);
#endif

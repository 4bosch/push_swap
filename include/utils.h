/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 13:26:22 by abosch            #+#    #+#             */
/*   Updated: 2020/03/06 13:26:24 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "stack.h"
# include "operation.h"

void	fast_rotate(int pos, t_stack **stack, int len, char stackletter);
int		get_min_max(t_stack *s, char maxmin);
void	destroy_stack(t_stack *s);
void	destroy_stacks(t_stack *a, t_stack *b);

#endif

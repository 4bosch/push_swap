/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:06:02 by abosch            #+#    #+#             */
/*   Updated: 2020/03/06 13:26:06 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "checks.h"
# include "stack.h"
# include "print.h"
# include "operation.h"
# include "utils.h"

void	two_sort(t_stack **stack_a);
void	three_sort(t_stack **stack_a);
void	little_sort(t_stack **stack_a, t_stack **stack_b);
void	choose_sort(int len, t_stack **a, t_stack **b);

#endif

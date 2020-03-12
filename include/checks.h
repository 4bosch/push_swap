/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:21:18 by abosch            #+#    #+#             */
/*   Updated: 2019/05/14 15:40:13 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKS_H
# define CHECKS_H

# include "stack.h"

int		is_argvalid(int ac, char **av, t_stack **stack);
int		is_sorted(t_stack *stack_a, t_stack *stack_b);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 18:11:09 by abosch            #+#    #+#             */
/*   Updated: 2020/03/06 13:25:33 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H

# include "stack.h"

/*
** swap and print s(letter)
*/
void	swap(t_stack **head, char letter);
/*
** push and print p(letter)
*/
void	push(t_stack **pop, t_stack **push, char letter);
/*
** rotate and print r(letter)
*/
void	rotate(t_stack **head, char letter);
/*
** reverse rotate and print rr(letter)
*/
void	reverse_rotate(t_stack **head, char letter);
/*
** swap the two stack and print ss if booleanPrint is true
*/
void	dual_swap(t_stack **a, t_stack **b, char boolean_print);
/*
** rotate the two stack and print rr if booleanPrint is true
*/
void	dual_rotate(t_stack **a, t_stack **b, char boolean_print);
/*
** reverse rotate the two stack and print rrr if booleanPrint is true
*/
void	dual_reverse_rotate(t_stack **a, t_stack **b, char boolean_print);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:46:28 by abosch            #+#    #+#             */
/*   Updated: 2020/03/06 13:27:45 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "libft.h"

typedef struct	s_stack
{
	int				value;
	int				nval;
	struct s_stack	*next;
}				t_stack;

/*
**	Create the stack a with the binary input and return it
*/
t_stack			*create_initial_stack(int ac, char **av);

/*
**	Return the stack lenght
*/
int				stacklen(t_stack *stack);

/*
**	Convert the values to a normalized value which is easier to sort
*/
void			value2norm(t_stack *s);

#endif

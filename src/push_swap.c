/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:16:08 by abosch            #+#    #+#             */
/*   Updated: 2020/03/05 13:27:28 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "operation.h"
#include "checks.h"
#include "stack.h"
#include "print.h"

int		main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac == 1)
		return (0);
	else if (!is_argvalid(ac, av, &stack_a))
		ft_puterr("Error", 2);
	else
	{
		value2norm(stack_a);
		stack_b = NULL;
		choose_sort(stacklen(stack_a), &stack_a, &stack_b);
	}
	destroy_stack(stack_a);
	return (0);
}

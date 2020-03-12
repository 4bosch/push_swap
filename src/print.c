/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 17:35:20 by abosch            #+#    #+#             */
/*   Updated: 2019/05/16 11:23:21 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

static	void	print_stack_header(t_stack *a, t_stack *b)
{
	if (a != NULL && b != NULL)
	{
		ft_printf("      Stack A               Stack B\n"
			"|------------------|  |------------------|\n");
	}
	else if (a == NULL && b != NULL)
	{
		ft_printf("      Stack A               Stack B\n"
			"        Vide          |------------------|\n");
	}
	else if (a != NULL && b == NULL)
	{
		ft_printf("      Stack A               Stack B\n"
			"|------------------|          Vide\n");
	}
}

static	void	print_stack_content(t_stack *a, t_stack *b)
{
	while (a != NULL || b != NULL)
	{
		if (a != NULL && b != NULL)
		{
			ft_printf("|%10d, %6d|  |%10d, %6d|\n", a->value, a->nval, b->value,
				b->nval);
			ft_printf("|------------------|  |------------------|\n");
			a = a->next;
			b = b->next;
		}
		else if (a == NULL && b != NULL)
		{
			ft_printf("                      |%10d, %6d|\n", b->value, b->nval);
			ft_printf("                      |------------------|\n");
			b = b->next;
		}
		else if (a != NULL && b == NULL)
		{
			ft_printf("|%10d, %6d|\n", a->value, a->nval);
			ft_printf("|------------------|\n");
			a = a->next;
		}
	}
}

void			print_stacks(t_stack *a, t_stack *b)
{
	print_stack_header(a, b);
	print_stack_content(a, b);
}

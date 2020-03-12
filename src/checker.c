/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 15:29:20 by abosch            #+#    #+#             */
/*   Updated: 2020/03/10 12:38:29 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "operation.h"
#include "checks.h"
#include "stack.h"
#include "print.h"
#include "utils.h"

static	int		is_instruction(char *s)
{
	if (!ft_strncmp(s, "pa", 2))
		return (1);
	else if (!ft_strncmp(s, "pb", 2))
		return (2);
	else if (!ft_strncmp(s, "sa", 2))
		return (3);
	else if (!ft_strncmp(s, "sb", 2))
		return (4);
	else if (!ft_strncmp(s, "ss", 2))
		return (5);
	else if (!ft_strncmp(s, "rra", 3))
		return (9);
	else if (!ft_strncmp(s, "rrb", 3))
		return (10);
	else if (!ft_strncmp(s, "rrr", 3))
		return (11);
	else if (!ft_strncmp(s, "ra", 2))
		return (6);
	else if (!ft_strncmp(s, "rb", 2))
		return (7);
	else if (!ft_strncmp(s, "rr", 2))
		return (8);
	else
		return (0);
}

static	void	operation(int op, t_stack **a, t_stack **b)
{
	if (op == 1)
		push(b, a, 0);
	else if (op == 2)
		push(a, b, 0);
	else if (op == 3)
		swap(a, 0);
	else if (op == 4)
		swap(b, 0);
	else if (op == 5)
		dual_swap(a, b, 0);
	else if (op == 6)
		rotate(a, 0);
	else if (op == 7)
		rotate(b, 0);
	else if (op == 8)
		dual_rotate(a, b, 0);
	else if (op == 9)
		reverse_rotate(a, 0);
	else if (op == 10)
		reverse_rotate(b, 0);
	else if (op == 11)
		dual_reverse_rotate(a, b, 0);
}

static	int		execute(char *s, t_stack **a, t_stack **b)
{
	int	i;
	int order;

	i = -1;
	while (s[++i] != '\0')
	{
		order = is_instruction(s + i);
		if (order == 0)
			return (0);
		else if (order < 9)
			i++;
		else
			i += 2;
		operation(order, a, b);
	}
	return (1);
}

void			print_end_checker(t_stack *a, t_stack *b)
{
	if (is_sorted(a, b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int				main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*input;
	int		ret;

	stack_b = NULL;
	if (ac == 1)
		return (0);
	else if (!is_argvalid(ac, av, &stack_a))
		ft_puterr("Error", 2);
	else
	{
		while ((ret = get_next_line(0, &input)) > 0)
		{
			if (!execute(input, &stack_a, &stack_b))
				ft_puterr("Error", 2);
			free(input);
		}
		if (ret == -1)
			ft_puterr("Error", 2);
		print_end_checker(stack_a, stack_b);
	}
	destroy_stacks(stack_a, stack_b);
	return (0);
}

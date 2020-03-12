/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:57:06 by abosch            #+#    #+#             */
/*   Updated: 2020/03/05 15:04:01 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

/*
** Check if every numbers are present in the input no more than once
*/

static int	is_members_alone(int ac, char **av, t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		i;

	*stack = create_initial_stack(ac, av);
	tmp1 = *stack;
	i = 0;
	while (i < 2 && tmp1 != NULL)
	{
		i = 0;
		tmp2 = *stack;
		while (i < 2 && tmp2 != NULL)
		{
			if (tmp2->value == tmp1->value)
				i++;
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	if (i < 2)
		return (1);
	else
		return (0);
}

/*
** Like the name says it check if the binary arguments are valid or not.
** The numbers can not be present more than once and are integers.
** If there are other characters than digit and blank, the input isn't valid
*/

int			is_argvalid(int ac, char **av, t_stack **stack)
{
	int			i;
	int			cnt;
	long long	nbr;

	if (ac < 2)
		return (0);
	cnt = ac;
	while (--cnt > 0)
	{
		i = -1;
		if (!ft_isdigit(av[cnt][++i]) && (av[cnt][i] != '-'
				|| av[cnt][i] != '+') && !ft_isdigit(av[cnt][i + 1]))
			return (0);
		while (av[cnt][++i] != '\0')
			if (!ft_isdigit(av[cnt][i]) && av[cnt][i] != ' '
					&& (av[cnt][i] != '-' || av[cnt][i] != '+')
					&& !ft_isdigit(av[cnt][i + 1]))
				return (0);
		if (ft_strlen(av[cnt]) > 11)
			return (0);
		nbr = ft_atoll(av[cnt]);
		if (nbr > 2147483647 || nbr < -2147483648)
			return (0);
	}
	return (is_members_alone(ac, av, stack));
}

/*
** Check if the stacks are sorted, b has to be empty and a sorted
*/

int			is_sorted(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	if (stacklen(b) != 0)
		return (0);
	else
	{
		while (a->next != NULL)
		{
			tmp = a->next;
			while (tmp != NULL)
			{
				if (tmp->value < a->value)
					return (0);
				tmp = tmp->next;
			}
			a = a->next;
		}
		return (1);
	}
}

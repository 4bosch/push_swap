/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:07:28 by abosch            #+#    #+#             */
/*   Updated: 2020/03/05 15:07:39 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** Choose adequate rotate operation and rotate to get the value on the top
*/

void	fast_rotate(int pos, t_stack **stack, int len, char s)
{
	int cnt;

	if (pos == 0)
		return ;
	else if (pos > len / 2)
		while (pos++ < len)
			reverse_rotate(stack, s);
	else
	{
		cnt = pos;
		while (cnt-- > 0)
			rotate(stack, s);
	}
}

/*
** Find the position in the stack of the minimum value if maxmin equals 0
** If it is not it find the position in the stack of the maximum value
*/

int		get_min_max(t_stack *s, char maxmin)
{
	int	i;
	int	pos;
	int test;

	i = 0;
	pos = 0;
	test = s->value;
	while (s != NULL)
	{
		if ((maxmin == 0) ? s->value < test : test < s->value)
		{
			pos = i;
			test = s->value;
		}
		i++;
		s = s->next;
	}
	return (pos);
}

void	destroy_stack(t_stack *s)
{
	t_stack	*next;

	while (s != NULL)
	{
		next = s->next;
		free(s);
		s = next;
	}
}

void	destroy_stacks(t_stack *a, t_stack *b)
{
	destroy_stack(a);
	destroy_stack(b);
}

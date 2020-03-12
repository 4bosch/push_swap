/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:05:19 by abosch            #+#    #+#             */
/*   Updated: 2020/03/05 15:05:27 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "utils.h"

/*
** A sort for 2 numbers
*/

void			two_sort(t_stack **s)
{
	if (!is_sorted(*s, NULL))
		swap(s, 'a');
}

/*
** A sort for 3 numbers
*/

void			three_sort(t_stack **s)
{
	int	first;
	int	mid;
	int	last;

	first = (*s)->value;
	mid = (*s)->next->value;
	last = (*s)->next->next->value;
	if (first < mid && first < last && last < mid)
	{
		swap(s, 'a');
		rotate(s, 'a');
	}
	else if (mid < first && first < last && mid < last)
		swap(s, 'a');
	else if (first < mid && last < mid && last < first)
		reverse_rotate(s, 'a');
	else if (first > mid && first > last && last > mid)
		rotate(s, 'a');
	else if (first > mid && first > last && mid > last)
	{
		rotate(s, 'a');
		swap(s, 'a');
	}
}

void			little_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	int		len;

	len = stacklen(*stack_a);
	while (len > 3)
	{
		min = get_min_max(*stack_a, 0);
		fast_rotate(min, stack_a, len, 'a');
		push(stack_a, stack_b, 'b');
		len--;
	}
	three_sort(stack_a);
	while (*stack_b != NULL)
	{
		push(stack_b, stack_a, 'a');
	}
}

void			norm_sort(t_stack **a, t_stack **b, int inc)
{
	int	rmax;
	int	i;

	rmax = 0;
	i = 1;
	while (*a != NULL)
	{
		rmax += inc;
		while (*a != NULL && i <= rmax)
		{
			if ((*a)->nval <= rmax)
			{
				i++;
				push(a, b, 'b');
			}
			else
				reverse_rotate(a, 'a');
		}
	}
	while (*b != NULL)
	{
		fast_rotate(get_min_max(*b, 1), b, stacklen(*b), 'b');
		push(b, a, 'a');
	}
}

void			choose_sort(int len, t_stack **a, t_stack **b)
{
	if (len == 1)
		return ;
	else if (len == 2)
		two_sort(a);
	else if (len == 3)
		three_sort(a);
	else if (len < 10)
		little_sort(a, b);
	else if (len <= 25)
		norm_sort(a, b, 5);
	else if (len <= 50)
		norm_sort(a, b, 10);
	else if (len <= 50)
		norm_sort(a, b, 15);
	else if (len <= 100)
		norm_sort(a, b, 20);
	else if (len <= 200)
		norm_sort(a, b, 30);
	else if (len <= 300)
		norm_sort(a, b, 40);
	else if (len <= 500)
		norm_sort(a, b, 50);
	else
		norm_sort(a, b, 75);
}

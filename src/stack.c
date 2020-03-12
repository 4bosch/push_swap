/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:27:32 by abosch            #+#    #+#             */
/*   Updated: 2020/03/05 15:07:23 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "operation.h"

/*
** Alloc space for a new node and fill it
*/

static t_stack	*new_node(int value)
{
	t_stack	*node;

	if (!(node = (t_stack*)malloc(sizeof(t_stack))))
		ft_puterr("stack.c:1:Malloc failed\n", 2);
	node->value = value;
	node->nval = 0;
	node->next = NULL;
	return (node);
}

/*
** Parse arguments, create and add new node to the list
*/

static void		string_number(int i, char **av, t_stack **node)
{
	int	j;

	j = -1;
	while (av[i][++j] != '\0' && av[i][j] != ' ')
		;
	if (av[i][j++] == ' ')
	{
		while (av[i][j] != '\0')
		{
			if (ft_isdigit(av[i][j]) || ((av[i][j] == '+' || av[i][j] == '-')
						&& ft_isdigit(av[i][j + 1])))
			{
				(*node)->next = new_node(ft_atoi(av[i] + j));
				(*node) = (*node)->next;
			}
			while (av[i][++j] != ' ' && av[i][j] != '\0')
				;
			if (av[i][j] != '\0')
				j++;
		}
	}
}

/*
**	Convert the values to a normalized value which is easier to sort
**	For example :
**	---------------------
**	| 9 | 30 | 21 | 100 |
**	---------------------
**	Will be
**	-----------------
**	| 1 | 3 | 2 | 4 |
**	-----------------
*/

void			value2norm(t_stack *s)
{
	t_stack	*head;
	t_stack	*tmp;

	head = s;
	while (s != NULL)
	{
		s->nval = stacklen(head);
		tmp = head;
		while (tmp != NULL)
		{
			if (s->value < tmp->value)
				s->nval--;
			tmp = tmp->next;
		}
		s = s->next;
	}
}

/*
** Create the stack a with the binary input and return it
*/

t_stack			*create_initial_stack(int ac, char **av)
{
	t_stack	*list;
	t_stack	*tmp;
	int		i;

	i = 0;
	list = new_node(ft_atoi(av[++i]));
	tmp = list;
	string_number(i, av, &tmp);
	while (++i < ac)
	{
		tmp->next = new_node(ft_atoi(av[i]));
		tmp = tmp->next;
		string_number(i, av, &tmp);
	}
	return (list);
}

/*
** Return the stack lenght
*/

int				stacklen(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

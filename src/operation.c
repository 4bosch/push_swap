/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:04:39 by abosch            #+#    #+#             */
/*   Updated: 2019/05/10 16:21:52 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

void	swap(t_stack **head, char c)
{
	t_stack	*tmp;

	if (c != 0)
		ft_printf("s%c\n", c);
	if (head == NULL || stacklen(*head) < 2)
		return ;
	tmp = (*head)->next;
	(*head)->next = (*head)->next->next;
	tmp->next = *head;
	*head = tmp;
}

void	dual_swap(t_stack **a, t_stack **b, char c)
{
	swap(a, 0);
	swap(b, 0);
	if (c != 0)
		ft_printf("ss\n");
}

void	push(t_stack **pop, t_stack **push, char c)
{
	t_stack	*tmp;

	if (*pop == NULL)
		return ;
	if (c != 0)
		ft_printf("p%c\n", c);
	tmp = *pop;
	*pop = (*pop)->next;
	tmp->next = *push;
	*push = tmp;
}

void	rotate(t_stack **head, char c)
{
	t_stack	*tmp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	if (c != 0)
		ft_printf("r%c\n", c);
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *head;
	*head = (*head)->next;
	tmp->next->next = NULL;
}

void	reverse_rotate(t_stack **head, char c)
{
	t_stack	*tmp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	if (c != 0)
		ft_printf("rr%c\n", c);
	tmp = *head;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = *head;
	*head = tmp->next;
	tmp->next = NULL;
}

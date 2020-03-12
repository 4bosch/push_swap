/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:01:12 by abosch            #+#    #+#             */
/*   Updated: 2019/07/05 16:01:13 by abosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"

void	dual_rotate(t_stack **a, t_stack **b, char c)
{
	rotate(a, 0);
	rotate(b, 0);
	if (c != 0)
		ft_printf("rr\n");
}

void	dual_reverse_rotate(t_stack **a, t_stack **b, char c)
{
	reverse_rotate(a, 0);
	reverse_rotate(b, 0);
	if (c != 0)
		ft_printf("rrr\n");
}

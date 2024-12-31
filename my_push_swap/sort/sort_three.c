/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:35:17 by haslan            #+#    #+#             */
/*   Updated: 2024/03/09 15:01:03 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	olnly_3_number(t_ps *ps)
{
	int	a;
	int	b;
	int	c;

	a = ps->list_a->head->data;
	b = ps->list_a->head->next->data;
	c = ps->list_a->tail->data;
	if (a < b && b < c)
	{
		ft_sa(ps);
		ft_rra(ps);
	}
	else if (a < c && c < b)
		ft_rra(ps);
	else if (b < a && a < c)
		ft_ra(ps);
	else if (b < c && c < a)
		ft_sa(ps);
	else if (c < a && a < b)
	{
		ft_rra(ps);
		ft_sa(ps);
	}
}

int	find_min_num_index(t_list *stack)
{
	t_node	*move;
	int		min;
	int		index;
	int		min_index;

	index = 1;
	min = 2147483647;
	move = stack->tail;
	while (move)
	{
		if (move->data < min)
		{
			min = move->data;
			min_index = index;
		}
		index++;
		move = move->prev;
	}
	return (min_index);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fonctions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:36:55 by haslan            #+#    #+#             */
/*   Updated: 2024/03/09 17:10:10 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	ft_abs(long num)
{
	if (num < 0)
		return ((-1) * num);
	return (num);
}

int	ft_min_way_len(int len, int index)
{
	int	up;
	int	down;

	up = index - 1;
	down = len - index + 1;
	if (up > down)
		return ((-1) * down);
	else
		return (up);
}

int	get_index(t_list *stack, int index)
{
	t_node	*move;
	int		i;

	move = stack->tail;
	i = 1;
	while (move && i != index)
	{
		move = move->prev;
		i++;
	}
	return (move->data);
}

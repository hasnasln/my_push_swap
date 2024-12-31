/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:38:02 by haslan            #+#    #+#             */
/*   Updated: 2024/03/13 15:58:37 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	last_set_and_push_a(t_ps *ps, int move)
{
	if (move < 0)
	{
		while (move != 0)
		{
			ft_rrb(ps);
			move++;
		}
	}
	else if (move > 0)
	{
		while (move != 0)
		{
			ft_rb(ps);
			move--;
		}
	}
	else
		ft_rrb(ps);
	while (ps->len_b > 0)
		ft_pa(ps);
}

static int	find_close_number_index(t_list *stack, int number)
{
	t_node	*move;
	long	diff;
	int		index;
	int		i;

	i = 1;
	diff = 0x7FFFFFFF;
	move = stack->tail;
	while (move)
	{
		if (diff > ft_abs((move->data) - (number)))
		{
			diff = ft_abs((move->data) - (number));
			index = i;
		}
		i++;
		move = move->prev;
	}
	return (index);
}

static void	find_and_push(t_ps *ps)
{
	t_node	*move;
	int		total;
	int		i;
	int		j;

	i = 0;
	ps->min_step = 0x7FFFFFFF;
	move = ps->list_a->tail;
	while (move)
	{
		i++;
		j = find_close_number_index(ps->list_b, move->data);
		total = ft_abs(ft_min_way_len(ps->len_a, i));
		total += ft_abs(ft_min_way_len(ps->len_b, j));
		if (total < ps->min_step)
		{
			ps->step_a = ft_min_way_len(ps->len_a, i);
			ps->step_b = ft_min_way_len(ps->len_b, j);
			ps->min_step = total;
			if (get_index(ps->list_a, i) < get_index(ps->list_b, j))
				ps->step_b ++;
		}
		move = move->prev;
	}
	set_and_push(ps);
}

static void	sort_stack(t_ps *ps)
{
	int	i;
	int	up;
	int	down;

	i = -1;
	while (++i < 2)
		ft_pb(ps);
	while (ps->len_a > 0)
		find_and_push(ps);
	up = find_min_num_index(ps->list_b);
	down = ps->len_b - up;
	if (up < down)
		i = up;
	else if (down < up)
		i = down * (-1);
	last_set_and_push_a(ps, i);
}

void	ps_sort(t_ps *ps)
{
	sort_array(ps->array, ps->len_arr, ps);
	if (ps->len_a == 2)
		ft_sa(ps);
	else if (ps->len_a == 3)
		olnly_3_number(ps);
	else if (ps->len_a <= 5)
		sort_low_numbers(ps);
	else
		sort_stack(ps);
}

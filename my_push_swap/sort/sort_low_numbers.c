/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_low_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:02:20 by haslan            #+#    #+#             */
/*   Updated: 2024/03/09 15:30:40 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_push_b(t_ps *ps)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (ps->step_a < 0)
		while (++i < ft_abs(ps->step_a))
			ft_rra(ps);
	else if (ps->step_a > 0)
		while (++i < ft_abs(ps->step_a))
			ft_ra(ps);
	if (ps->step_b < 0)
		while (++j < ft_abs(ps->step_b))
			ft_rrb(ps);
	else if (ps->step_b > 0)
		while (++j < ft_abs(ps->step_b))
			ft_rb(ps);
	ft_pb(ps);
}

static void	push_min_step_a(t_ps *ps)
{
	ps->step_a = 0;
	ps->step_b = 0;
	ps->step_a = ft_min_way_len(ps->len_a, find_min_num_index(ps->list_a));
	ft_push_b(ps);
}

void	sort_low_numbers(t_ps *ps)
{
	while (ps->len_a > 3)
		push_min_step_a(ps);
	olnly_3_number(ps);
	while (ps->len_b > 0)
		ft_pa(ps);
}

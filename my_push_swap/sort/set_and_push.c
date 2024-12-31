/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:35:46 by haslan            #+#    #+#             */
/*   Updated: 2024/03/02 13:35:47 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_and_push_2(t_ps *ps)
{
	while (ps->step_b != 0)
	{
		if (ps->step_b < 0)
		{
			ft_rrb(ps);
			ps->step_b++;
		}
		else if (ps->step_b > 0)
		{
			ft_rb(ps);
			ps->step_b--;
		}
	}
}

void	set_and_push(t_ps *ps)
{
	while (ps->step_a != 0)
	{
		if (ps->step_a < 0)
		{
			ft_rra(ps);
			ps->step_a++;
		}
		else if (ps->step_a > 0)
		{
			ft_ra(ps);
			ps->step_a--;
		}
	}
	set_and_push_2(ps);
	ft_pb(ps);
}

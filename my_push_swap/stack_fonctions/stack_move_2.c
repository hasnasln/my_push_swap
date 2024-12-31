/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_move_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:42:26 by haslan            #+#    #+#             */
/*   Updated: 2024/03/09 15:00:49 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_ps *ps)
{
	ft_putstr("ra\n");
	if (ps->len_a > 1)
		if (ft_move_up_list(ps->list_a))
			my_exit(ps, W_ERROR);
}

void	ft_rb(t_ps *ps)
{
	ft_putstr("rb\n");
	if (ps->len_b > 1)
		if (ft_move_up_list(ps->list_b))
			my_exit(ps, W_ERROR);
}

void	ft_rra(t_ps *ps)
{
	ft_putstr("rra\n");
	if (ft_move_down_list(ps->list_a))
		my_exit(ps, W_ERROR);
}

void	ft_rrb(t_ps *ps)
{
	ft_putstr("rrb\n");
	if (ft_move_down_list(ps->list_b))
		my_exit(ps, W_ERROR);
}

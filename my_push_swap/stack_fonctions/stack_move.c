/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:42:55 by haslan            #+#    #+#             */
/*   Updated: 2024/03/09 15:00:57 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_ps *ps)
{
	ft_putstr("sa\n");
	if (ft_swap_list(ps->list_a))
		my_exit(ps, W_ERROR);
}

void	ft_sb(t_ps *ps)
{
	ft_putstr("sb\n");
	if (ft_swap_list(ps->list_b))
		my_exit(ps, W_ERROR);
}

void	ft_pa(t_ps *ps)
{
	ft_putstr("pa\n");
	if (ft_push_list(ps->list_b, ps->list_a))
		my_exit(ps, W_ERROR);
	ps->len_b--;
	ps->len_a++;
}

void	ft_pb(t_ps *ps)
{
	ft_putstr("pb\n");
	if (ft_push_list(ps->list_a, ps->list_b))
		my_exit(ps, W_ERROR);
	ps->len_a--;
	ps->len_b++;
}

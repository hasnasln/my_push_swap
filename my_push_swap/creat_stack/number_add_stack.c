/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_add_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:39:07 by haslan            #+#    #+#             */
/*   Updated: 2024/03/09 17:14:32 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	numbers_add_stack(t_ps *ps)
{
	int	i;

	i = ps->len_arr - 1;
	while (i >= 0)
	{
		if (ft_add_list(ps->list_a, ps->array[i]))
			my_exit(ps, W_ERROR);
		i--;
	}
}

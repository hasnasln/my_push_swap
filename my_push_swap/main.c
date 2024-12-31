/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:00:59 by haslan            #+#    #+#             */
/*   Updated: 2024/03/13 15:50:43 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	*ps;

	ps = determinate_ps();
	create_number(argc, argv, ps);
	numbers_add_stack(ps);
	ps_sort(ps);
	my_exit(ps, DW_ERROR);
}

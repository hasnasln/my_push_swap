/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinate_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:39:02 by haslan            #+#    #+#             */
/*   Updated: 2024/03/02 16:39:44 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

t_ps	*determinate_ps(void)
{
	t_ps	*ps;

	ps = (t_ps *)malloc(sizeof(t_ps));
	if (ps == NULL)
		my_exit(ps, W_ERROR);
	ps->list_b = NULL;
	ps->array = NULL;
	ps->list_a = (t_list *)malloc(sizeof(t_list));
	if (ps->list_a == NULL)
		my_exit(ps, W_ERROR);
	ps->list_a->head = NULL;
	ps->list_a->tail = NULL;
	ps->list_b = (t_list *)malloc(sizeof(t_list));
	if (ps->list_b == NULL)
		my_exit(ps, W_ERROR);
	ps->list_b->head = NULL;
	ps->list_b->tail = NULL;
	ps->len_b = 0;
	return (ps);
}

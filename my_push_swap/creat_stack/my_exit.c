/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:39:05 by haslan            #+#    #+#             */
/*   Updated: 2024/03/13 16:00:05 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>
#include <unistd.h>

static void	free_list(t_list *list)
{
	t_node	*temp;

	while (list->head != NULL)
	{
		temp = list->head;
		list->head = list->head->next;
		free(temp);
	}
	free(list);
}

void	my_exit(t_ps *ps, int code)
{
	if (code == W_ERROR)
		write(2, "Error\n", 6);
	if (ps)
	{
		if (ps->list_a != NULL)
			free_list(ps->list_a);
		if (ps->list_b != NULL)
			free_list(ps->list_b);
		if (ps->array != NULL)
			free(ps->array);
		free(ps);
	}
	exit (0);
}

void	free_split_result(char **r_split)
{
	int	i;

	i = 0;
	while (r_split[i])
	{
		free(r_split[i]);
		i++;
	}
	free(r_split);
}

void	free_splitr_and_exit(char **str, t_ps *ps, int flag)
{
	if (flag == SPLITR)
		free_split_result(str);
	my_exit(ps, W_ERROR);
}

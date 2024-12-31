/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pop_peek.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:43:27 by haslan            #+#    #+#             */
/*   Updated: 2024/03/13 16:00:35 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

int	ft_peek_list(t_list	*list)
{
	return (list->tail->data);
}

int	ft_pop_list(t_list	*list)
{
	int	value;

	value = list->tail->data;
	if (list->tail->prev == NULL)
	{
		free(list->tail);
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		list->tail = list->tail->prev;
		free(list->tail->next);
		list->tail->next = NULL;
	}
	return (value);
}

int	ft_add_list(t_list	*list, int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (1);
	node->data = value;
	node->next = NULL;
	node->prev = list->tail;
	if (list->tail == NULL)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		list->tail->next = node;
		list->tail = node;
	}
	return (0);
}

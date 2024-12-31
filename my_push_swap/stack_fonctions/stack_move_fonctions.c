/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_move_fonctions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:41:39 by haslan            #+#    #+#             */
/*   Updated: 2024/03/13 16:00:44 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>

int	ft_push_list(t_list *dest, t_list *target)
{
	if (ft_add_list(target, ft_pop_list(dest)))
		return (1);
	return (0);
}

int	ft_swap_list(t_list *list)
{
	int	value;

	if (list->head == NULL || list->tail == NULL)
		return (1);
	if (list->head->next == NULL || list->tail->prev == NULL)
		return (1);
	value = list->tail->data;
	list->tail->data = list->tail->prev->data;
	list->tail->prev->data = value;
	return (0);
}

int	ft_move_up_list(t_list *list)
{
	int		value;
	t_node	*node;

	if (list == NULL)
		return (1);
	if (list->head == NULL || list->tail == NULL)
		return (1);
	if (list->head->next == NULL || list->tail->prev == NULL)
		return (1);
	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (1);
	value = ft_pop_list(list);
	node->data = value;
	node->next = list->head;
	node->prev = NULL;
	list->head->prev = node;
	list->head = node;
	return (0);
}

int	ft_move_down_list(t_list *list)
{
	int	value;

	if (list == NULL)
		return (1);
	if (list->head == NULL || list->tail == NULL)
		return (1);
	if (list->head->next == NULL || list->tail->prev == NULL)
		return (1);
	value = list->head->data;
	list->head = list->head->next;
	free(list->head->prev);
	list->head->prev = NULL;
	if (ft_add_list(list, value))
		return (1);
	return (0);
}

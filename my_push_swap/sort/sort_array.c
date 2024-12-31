/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:35:57 by haslan            #+#    #+#             */
/*   Updated: 2024/03/13 15:59:29 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_sorted(int	*array, int length)
{
	int	i;

	i = -1;
	while (++i < length -1)
		if (array[i] >= array[i + 1])
			return (0);
	return (1);
}

static void	repetive_number(int	*array, int length, t_ps *ps)
{
	int	i;

	i = -1;
	while (++i < length -1)
		if (array[i] == array[i + 1])
			my_exit(ps, W_ERROR);
}

void	sort_array(int	*array, int length, t_ps *ps)
{
	int	i;
	int	j;
	int	temp;

	if (is_sorted(array, length))
		my_exit(ps, DW_ERROR);
	i = 0;
	while (i < length - 1)
	{
		j = i + 1;
		while (j < length)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
	repetive_number(array, length, ps);
}

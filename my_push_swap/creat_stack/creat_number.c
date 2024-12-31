/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:39:00 by haslan            #+#    #+#             */
/*   Updated: 2024/03/13 14:55:19 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdlib.h>
#include <limits.h>

static void	tptia(char **str, t_ps *ps, int flag)
{
	int		i;
	long	temp;

	i = 0;
	if (!all_is_number(str))
		free_splitr_and_exit(str, ps, flag);
	ps->array = (int *)malloc(sizeof(int) * ps->len_arr);
	if (ps->array == NULL)
		free_splitr_and_exit(str, ps, flag);
	while (str[i] != NULL)
	{
		temp = ft_atoi(str[i]);
		if (temp > INT_MAX || temp < INT_MIN)
			free_splitr_and_exit(str, ps, flag);
		ps->array[i] = temp;
		i++;
	}
	if (flag == SPLITR)
		free_split_result(str);
	if (ps->len_arr == 1)
		my_exit(ps, DW_ERROR);
}

static void	sptia(char *str, t_ps *ps)
{
	char	**split_r;

	split_r = ft_split(str, ' ');
	if (!split_r)
		my_exit(ps, W_ERROR);
	ps->len_arr = 0;
	while (split_r[ps->len_arr])
		ps->len_arr += 1;
	ps->len_a = ps->len_arr;
	tptia(split_r, ps, SPLITR);
}

void	create_number(int argc, char **argv, t_ps *ps)
{
	if (argc == 1)
		my_exit(ps, DW_ERROR);
	else if (argc == 2)
		sptia(argv[1], ps);
	else
	{
		ps->len_arr = argc - 1;
		ps->len_a = ps->len_arr;
		tptia(&(argv[1]), ps, NSPLITR);
	}
}

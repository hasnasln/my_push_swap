/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:41:04 by haslan            #+#    #+#             */
/*   Updated: 2024/05/23 17:17:20 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
#include <stdlib.h>
#include <stdio.h>

static void	creat_and_difene_philo_arry(t_data *datat);

int	create(t_data *data)
{
	creat_and_difene_philo_arry(data);
	if (creat_and_init_muteks(data, -1, 0))
		return (printf("Mutex error"), -1);
	if (create_pthread(data) == -1)
	{
		printf("pthread_hatası");
		return (-1);
	}
	return (0);
}

static void	creat_and_difene_philo_arry(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nop)
	{
		data->all_philo[i].id = i;
		data->all_philo[i].en = BEFORE_START;
		data->all_philo[i].lmt = BEFORE_START;
		data->all_philo[i].take_left = BEFORE_START;
		data->all_philo[i].take_right = BEFORE_START;
		data->all_philo[i].rigth_m = NULL;
		data->all_philo[i].left_m = NULL;
		data->all_philo[i].print_m = NULL;
		data->all_philo[i].eat_m = NULL;
		data->all_philo[i].pt_id = BEFORE_START;
		data->all_philo[i].data = data;
	}
}

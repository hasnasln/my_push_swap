/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:41:13 by haslan            #+#    #+#             */
/*   Updated: 2024/05/28 10:07:35 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
#include <stdlib.h>

static int	create_and_init_2(t_data *data, int rv);
static int	pass_aout_forks(t_data *data);
static int	helper_init_mutex(t_data *data, int i);

int	creat_and_init_muteks(t_data *data, int i, int rv)
{
	while (++i < data->nop)
	{
		rv = pthread_mutex_init(&data->mt[i], NULL);
		if (rv != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&data->mt[i]);
			free(data->mt);
			free(data->all_philo);
			free(data->all_eat_m);
			return (-1);
		}
	}
	i = -1;
	while (++i < data->nop)
	{
		rv = pthread_mutex_init(&data->all_eat_m[i], NULL);
		if (rv != 0)
			return (helper_init_mutex(data, i));
	}
	if (create_and_init_2(data, rv) == -1)
		return (-1);
	return (pass_aout_forks(data));
}

static int	create_and_init_2(t_data *data, int rv)
{
	rv = pthread_mutex_init(&data->print_m, NULL);
	if (rv != 0)
		return (helper_init_mutex(data, data->nop));
	rv = pthread_mutex_init(&data->detective_m, NULL);
	if (rv != 0)
	{
		pthread_mutex_destroy(&data->print_m);
		return (helper_init_mutex(data, data->nop));
	}
	return (SUCCES);
}

static int	helper_init_mutex(t_data *data, int i)
{
	while (--i >= 0)
		pthread_mutex_destroy(&data->all_eat_m[i]);
	i = -1;
	while (++i < data->nop)
		pthread_mutex_destroy(&data->mt[i]);
	free(data->all_eat_m);
	free(data->all_philo);
	free(data->mt);
	return (-1);
}

static int	pass_aout_forks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nop)
	{
		data->all_philo[i].print_m = &data->print_m;
		data->all_philo[i].eat_m = &data->all_eat_m[i];
		data->all_philo[i].left_m = &data->mt[i];
		if (i == 0 && (data->nop != 1))
			data->all_philo[i].rigth_m = &data->mt[data->nop - 1];
		else if (i != 0)
			data->all_philo[i].rigth_m = &data->mt[i - 1];
	}
	return (0);
}

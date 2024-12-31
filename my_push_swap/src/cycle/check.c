/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:40:37 by haslan            #+#    #+#             */
/*   Updated: 2024/05/23 17:07:18 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
#include <unistd.h>
#include <pthread.h>

static int	goin_or_stop(t_data *data);
static int	philo_dead(t_philo *philo);
static int	satiated(t_data *data);

void	*detective(void *incoing_data)
{
	t_data	*data;

	data = (t_data *)incoing_data;
	while (look_ssf(data) != STOP)
	{
		if (goin_or_stop(data) == 1)
			return (NULL);
		usleep(50);
	}
	return ((void *)0);
}

static int	goin_or_stop(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nop)
	{
		if (philo_dead(&data->all_philo[i]) == DEAD)
			return (DEAD);
		if (data->nme != NOT_ENTERED)
			if (satiated(data) == 0)
				return (1);
	}
	return (0);
}

static int	satiated(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nop)
	{
		pthread_mutex_lock(&data->all_eat_m[i]);
		if (data->all_philo[i].en != data->nme)
		{
			pthread_mutex_unlock(&data->all_eat_m[i]);
			return (-1);
		}
		pthread_mutex_unlock(&data->all_eat_m[i]);
	}
	pthread_mutex_lock(&data->detective_m);
	data->ssf = STOP;
	pthread_mutex_unlock(&data->detective_m);
	return (0);
}

static int	philo_dead(t_philo *philo)
{
	long long int	time;

	pthread_mutex_lock(philo->eat_m);
	time = my_system_time();
	if (time - philo->lmt >= philo->data->ttd)
	{
		pps(philo, "Dead");
		pthread_mutex_lock(&philo->data->detective_m);
		philo->data->ssf = STOP;
		pthread_mutex_unlock(&philo->data->detective_m);
		pthread_mutex_unlock(philo->eat_m);
		return (DEAD);
	}
	pthread_mutex_unlock(philo->eat_m);
	return (ALIVE);
}

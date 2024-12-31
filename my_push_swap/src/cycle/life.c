/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:38:05 by haslan            #+#    #+#             */
/*   Updated: 2024/05/28 10:05:50 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
#include <unistd.h>

static void	philo_think(t_philo *philo);
static void	philo_eating(t_philo *philo);

void	*life(void *incoming_data)
{
	t_philo	*philo;

	philo = (t_philo *)incoming_data;
	while (philo->data->ssf != START)
	{
	}
	pthread_mutex_lock(philo->eat_m);
	philo->lmt = my_system_time();
	pthread_mutex_unlock(philo->eat_m);
	if (philo->id % 2 == 1)
		usleep(200 * philo->data->nop);
	while (look_ssf(philo->data) != STOP && philo->en != philo->data->nme)
	{
		philo_eating(philo);
		if (look_ssf(philo->data))
			philo_think(philo);
	}
	return (NULL);
}

static void	philo_eating(t_philo *philo)
{
	take_fork(philo);
	while ((philo->take_left != 1 || philo->take_right != 1)
		&& (look_ssf(philo->data) != STOP))
	{
	}
	pps(philo, "Eating");
	pthread_mutex_lock(philo->eat_m);
	philo->lmt = my_system_time();
	pthread_mutex_unlock(philo->eat_m);
	my_wait(philo->data->tte, philo);
	if (look_ssf(philo->data) != STOP)
	{
		pthread_mutex_lock(philo->eat_m);
		philo->en++;
		pthread_mutex_unlock(philo->eat_m);
	}
	pps(philo, "Sleping");
	if (philo->take_left == 1)
		pthread_mutex_unlock(philo->left_m);
	if (philo->take_right == 1)
		pthread_mutex_unlock(philo->rigth_m);
	philo->take_right = 0;
	philo->take_left = 0;
	my_wait(philo->data->tts, philo);
}

static void	philo_think(t_philo *philo)
{
	pps(philo, "Thinking");
}

int	look_ssf(t_data *data)
{
	pthread_mutex_lock(&data->detective_m);
	if (data->ssf == STOP)
	{
		pthread_mutex_unlock(&data->detective_m);
		return (STOP);
	}
	pthread_mutex_unlock(&data->detective_m);
	return (START);
}

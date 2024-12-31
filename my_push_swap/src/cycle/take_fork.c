/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:40:58 by haslan            #+#    #+#             */
/*   Updated: 2024/05/23 10:51:55 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	take_fork(t_philo *philo)
{
	if ((philo->left_m) && look_ssf(philo->data) != STOP)
	{
		pthread_mutex_lock(philo->left_m);
		pps(philo, "Take left fork");
		philo->take_left = 1;
	}
	if ((philo->rigth_m) && look_ssf(philo->data) != STOP)
	{
		pthread_mutex_lock(philo->rigth_m);
		pps(philo, "Take right fork");
		philo->take_right = 1;
	}
	return (0);
}

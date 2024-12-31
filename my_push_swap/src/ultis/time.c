/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:41:21 by haslan            #+#    #+#             */
/*   Updated: 2024/05/23 10:58:35 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
#include <sys/time.h>
#include <unistd.h>

long long int	my_system_time(void)
{
	struct timeval	system_time;
	int				rv;

	rv = gettimeofday(&system_time, NULL);
	if (rv != 0)
		return (-1);
	return ((system_time.tv_sec * 1000) + (system_time.tv_usec / 1000));
}

void	my_wait(long long int time, t_philo *philo)
{
	long long int	start;

	start = my_system_time();
	while ((my_system_time() - start < time) && (philo->data->aod == NOT_FIND))
		usleep(100);
}

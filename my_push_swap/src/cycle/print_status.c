/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:40:54 by haslan            #+#    #+#             */
/*   Updated: 2024/05/23 17:00:55 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../include/philo.h"

void	pps(t_philo *philo, char *status)
{
	if (look_ssf(philo->data) != STOP)
	{
		pthread_mutex_lock(philo->print_m);
		if (philo->data->aod == 0 && status[0] != 'D')
			printf("%s%-5lld%s %s%5d%s %s%-30s%s\n", MAGENTA,
				(my_system_time() - philo->data->sst),
				RESET, GREEN, (philo->id + 1), RESET, CYAN, status, RESET);
		else if (status[0] == 'D')
		{
			philo->data->aod = 1;
			printf("%s%-5lld%s %s%5d%s %s%-30s%s\n", RED,
				(my_system_time() - philo->data->sst),
				RESET, RED, (philo->id + 1), RESET, RED, status, RESET);
		}
		pthread_mutex_unlock(philo->print_m);
	}
}

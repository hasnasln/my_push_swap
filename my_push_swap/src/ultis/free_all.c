/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:41:18 by haslan            #+#    #+#             */
/*   Updated: 2024/05/23 10:54:38 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
#include <stdlib.h>

int	free_all(t_data *data)
{
	int	i;

	i = -1;
	if (!data)
		return (-1);
	while (++i < data->nop)
	{
		if (&data->mt[i])
			pthread_mutex_destroy(&data->mt[i]);
		if (&data->all_eat_m[i])
			pthread_mutex_destroy(&data->all_eat_m[i]);
	}
	if (data->all_eat_m)
		free(data->all_eat_m);
	if (data->mt)
		free(data->mt);
	pthread_mutex_destroy(&data->print_m);
	pthread_mutex_destroy(&data->detective_m);
	free(data->all_philo);
	return (0);
}

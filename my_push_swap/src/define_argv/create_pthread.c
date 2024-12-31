/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pthread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:41:07 by haslan            #+#    #+#             */
/*   Updated: 2024/05/23 16:57:20 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
#include <stdio.h>

int	create_pthread(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nop)
	{
		if (pthread_create(&data->all_philo[i].pt_id, NULL,
				&life, &data->all_philo[i]))
		{
			printf("pthread hatası");
			return (-1);
		}
	}
	data->sst = my_system_time();
	data->ssf = START;
	if (pthread_create(&data->detective, NULL, &detective, data))
	{
		printf("pthread hatası");
		return (-1);
	}
	wait_all_pthread(data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:41:01 by haslan            #+#    #+#             */
/*   Updated: 2024/05/23 10:58:47 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "../../include/philo.h"

void	wait_all_pthread(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nop)
		pthread_join(data->all_philo[i].pt_id, NULL);
	pthread_join(data->detective, NULL);
}

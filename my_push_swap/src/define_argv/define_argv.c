/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:41:10 by haslan            #+#    #+#             */
/*   Updated: 2024/05/23 11:18:28 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"
#include <stdlib.h>
#include <stdio.h>

static int	helper_define(t_data *data);

int	define_argv(t_data *data, char **argv)
{
	data->nop = ft_atoi(argv[1]);
	data->ttd = ft_atoi(argv[2]);
	data->tte = ft_atoi(argv[3]);
	data->tts = ft_atoi(argv[4]);
	if (argv[5])
		data->nme = ft_atoi(argv[5]);
	else
		data->nme = NOT_ENTERED;
	data->ssf = BEFORE_START;
	data->aod = NOT_FIND;
	data->sst = 0;
	data->mt = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->nop);
	if (!data->mt)
		return (printf("Malloc hatası"), FAIL);
	data->all_philo = (t_philo *)malloc(sizeof(t_philo) * data->nop);
	if (!data->all_philo)
	{
		free(data->mt);
		return (printf("Malloc hatası"), FAIL);
	}
	data->all_eat_m = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * data->nop);
	if (!data->all_eat_m)
		return (helper_define(data));
	return (SUCCES);
}

static int	helper_define(t_data *data)
{
	free(data->mt);
	free(data->all_philo);
	printf("Malloc hatası");
	return (-1);
}

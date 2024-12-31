/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argv_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:39:53 by haslan            #+#    #+#             */
/*   Updated: 2024/05/23 11:10:20 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../include/philo.h"

void	print_limit_error(void)
{
	printf("outside of limits");
}

void	print_ture_arguman(void)
{
	printf("%s./phile%s ", RED, RESET);
	printf("%s[%s%snumber_of_philosophers%s %s]%s", GREEN, RESET,
		BLUE, RESET, GREEN, RESET);
	printf("%s[%s%stime_to_die%s %s]%s", GREEN, RESET,
		BLUE, RESET, GREEN, RESET);
	printf("%s[%s%stime_to_eat%s %s]%s", GREEN, RESET,
		BLUE, RESET, GREEN, RESET);
	printf("%s[%s%stime_to_sleep%s %s]%s", GREEN, RESET,
		BLUE, RESET, GREEN, RESET);
	printf("%s[%s%soptional-> number_of_times_each\
		_philosopher_must_eat%s%s]%s\n", GREEN, RESET,
		BLUE, RESET, GREEN, RESET);
}

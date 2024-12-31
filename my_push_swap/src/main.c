/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:41:24 by haslan            #+#    #+#             */
/*   Updated: 2024/05/23 11:35:59 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!argv_correct(argc, argv))
		return (0);
	if (define_argv(&data, argv) == FAIL)
		return (0);
	if (create(&data) == -1)
		return (0);
	free_all(&data);
	return (0);
}

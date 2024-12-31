/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_correct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 10:40:14 by haslan            #+#    #+#             */
/*   Updated: 2024/05/23 11:10:28 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../../include/philo.h"

long	ft_atoi(const char *str)
{
	int		sing;
	long	result;

	result = 0;
	sing = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sing = 1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		result = (result * 10) + (*str - 48);
		str++;
	}
	if (sing)
		return (result * (-1));
	return (result);
}

static int	all_is_number(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i] != (void *)0)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

static int	all_is_int(char **argv)
{
	int		i;
	long	result;

	i = 0;
	while (argv[i] != (void *)0)
	{
		result = ft_atoi(argv[i]);
		if (result > INT_MAX || result < INT_MIN)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static int	argv_is_true(int argc)
{
	if (argc < 5 || argc > 6)
		return (FALSE);
	return (TRUE);
}

int	argv_correct(int argc, char **argv)
{
	if (argv_is_true(argc) && (all_is_number(&(argv[1]))))
	{
		if (all_is_int(&(argv[1])))
			return (TRUE);
		return (print_limit_error(), FALSE);
	}
	return (print_ture_arguman(), FALSE);
}

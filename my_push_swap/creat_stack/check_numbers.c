/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:38:57 by haslan            #+#    #+#             */
/*   Updated: 2024/03/09 15:03:05 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_is_number(char *str)
{
	int	i;
	int	flag;

	flag = 1;
	i = 0;
	if (str[0] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
		flag = 0;
	}
	if (flag)
		return (0);
	return (1);
}

int	all_is_number(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_is_number(str[i]))
			return (0);
		i++;
	}
	return (1);
}

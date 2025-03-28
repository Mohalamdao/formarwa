/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamdao <molamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:19:54 by molamdao          #+#    #+#             */
/*   Updated: 2025/03/28 15:46:00 by molamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing(char **av, int i, int y)
{
	while (av[++i])
		if (av[i][0] == '-')
			return (ft_printf("Error: Negative number\n"), 1);
	i = 1;
	while (av[i])
	{
		y = 0;
		while (av[i][y])
		{
			if (ft_isdigit(av[i][y]) == 0)
			{
				ft_printf("Error: Invalid character,only numbers allowed\n");
				return (1);
			}
			y++;
		}
		i++;
	}
	if (ft_check_num(av) == 1)
		return (1);
	return (0);
}

int	ft_check_num(char **av)
{
	int	i;

	i = 1;
	while (av[++i])
	{
		if (i == 5)
			break ;
		if (ft_atoi(av[i]) < 60)
		{
			ft_printf("Error: Value lower than 60 ms\n");
			return (1);
		}
	}
	return (0);
}

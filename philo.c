/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamdao <molamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:19:59 by molamdao          #+#    #+#             */
/*   Updated: 2025/03/28 15:55:40 by molamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_fork(t_data **data)
{
	int	i;

	i = 0;
	(*data)->fork = malloc(sizeof(pthread_mutex_t) * (*data)->nbr_philo);
	if (!(*data)->fork)
		return (1);
	while (i < (*data)->nbr_philo)
	{
		pthread_mutex_init(&(*data)->fork[i], NULL);
		i++;
	}
	return (0);
}

int	init_philo(t_data **data, int i)
{
	long long	res;

	(*data)->philo = NULL;
	(*data)->philo = malloc(sizeof(t_philo) * (*data)->nbr_philo);
	if (!(*data)->philo)
		return (1);
	while (i < (*data)->nbr_philo)
	{
		(*data)->philo[i].num_meal = 0;
		(*data)->philo[i].death = 0;
		(*data)->philo[i].id = i + 1;
		(*data)->philo[i].left_fork = (*data)->philo[i].id - 1;
		if ((*data)->philo[i].id + 1 != (*data)->nbr_philo)
		{
			res = ((*data)->philo[i].id) % (*data)->nbr_philo;
			(*data)->philo[i].right_fork = res;
		}
		else
			(*data)->philo[i].right_fork = ((*data)->philo[i].id);
		(*data)->philo[i].last_eat = get_time();
		(*data)->philo[i].data = *data;
		i++;
	}
	return (0);
}

int	init_data(int ac, char **av, t_data **data)
{
	*data = malloc(sizeof(t_data));
	if (data == NULL)
		return (1);
	(*data)->die = 0;
	(*data)->nbr_philo = ft_atoi(av[1]);
	(*data)->time_die = ft_atoi(av[2]);
	(*data)->eat = ft_atoi(av[3]);
	(*data)->sleep = ft_atoi(av[4]);
	(*data)->start_time = get_time();
	pthread_mutex_init(&(*data)->moment_death, NULL);
	pthread_mutex_init(&(*data)->write_lock, NULL);
	if (init_fork(data) == 1)
		return (1);
	if (ac == 6)
		(*data)->nbr_eat = ft_atoi(av[5]);
	else
		(*data)->nbr_eat = -1;
	if (init_philo(data, 0) == 1)
		return (1);
	return (0);
}

int	main_part_2(t_data **data, int ac, char **av, int i)
{
	if (ac < 5 || ac > 6)
	{
		ft_printf("Error: Too many or too few arguments\n");
		return (1);
	}
	if (parsing(av, 0, 0) == 1)
		return (1);
	if (init_data(ac, av, data))
	{
		ft_printf("Error\n");
		free_all(*data, (*data)->philo);
		return (1);
	}
	while (i < (*data)->nbr_philo)
	{
		if (pthread_create(&(*data)->philo[i].thread, NULL, &routine_philo,
				&(*data)->philo[i]) != 0)
		{
			ft_printf("Error\n");
			free_all(*data, (*data)->philo);
			return (1);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;
	int		i;

	data = NULL;
	i = 0;
	if (main_part_2(&data, ac, av, 0) == 1)
		return (1);
	ft_check_death(data);
	while (i < data->nbr_philo)
	{
		if (pthread_join(data->philo[i].thread, (void *)&data->philo[i]) != 0)
			return (ft_printf("Error\n"), free_all(data, data->philo), 1);
		i++;
	}
	free_all(data, data->philo);
}

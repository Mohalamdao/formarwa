/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamdao <molamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:19:45 by molamdao          #+#    #+#             */
/*   Updated: 2025/03/28 15:46:35 by molamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	is_sleep(long long time, t_data *data)
{
	long long	start;

	start = get_time();
	while (!data->die)
	{
		if (get_time() - start >= time)
			break ;
		usleep(2 * data->nbr_philo);
	}
}

void	ft_check_eat(t_data *data)
{
	int			i;
	long long	time;

	i = 0;
	while (i < data->nbr_philo)
	{
		if (get_time() - data->philo[i].last_eat > data->time_die)
		{
			if (data->nbr_eat == data->philo->num_meal)
				break ;
			time = get_time() - data->start_time;
			pthread_mutex_lock(&data->moment_death);
			data->die = 1;
			pthread_mutex_unlock(&data->moment_death);
			pthread_mutex_lock(&data->write_lock);
			printf("%lld	%d  died\n", time, data->philo[i].id);
			pthread_mutex_unlock(&data->write_lock);
			return ;
		}
		i++;
	}
}

void	free_all(t_data *data, t_philo *philo)
{
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(data->fork);
	pthread_mutex_destroy(&data->moment_death);
	if (data->fork != NULL)
		free(data->fork);
	if (philo != NULL)
		free(philo);
	if (data != NULL)
		free(data);
}

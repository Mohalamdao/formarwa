/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamdao <molamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:19:50 by molamdao          #+#    #+#             */
/*   Updated: 2025/03/28 15:36:11 by molamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_data *data, t_philo *philo)
{
	long long	time;

	time = get_time() - data->start_time;
	pthread_mutex_lock(&data->write_lock);
	if (is_alive(philo))
	{
		printf("%lld	%d  is thinking\n", time, philo->id);
	}
	pthread_mutex_unlock(&data->write_lock);
}

void	pick_fork(t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(&philo->data->fork[philo->left_fork]);
	time = get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->write_lock);
	if (is_alive(philo))
		printf("%lld	%d  has taken a fork\n", time, philo->id);
	pthread_mutex_unlock(&philo->data->write_lock);
	pthread_mutex_lock(&philo->data->fork[philo->right_fork]);
	time = get_time() - philo->data->start_time;
	pthread_mutex_unlock(&philo->data->write_lock);
	if (is_alive(philo))
		printf("%lld	%d  has taken a fork\n", time, philo->id);
	pthread_mutex_unlock(&philo->data->write_lock);
}

void	is_eating(t_philo *philo)
{
	long long	time;

	if (philo->data->die)
		return ;
	time = get_time() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->write_lock);
	if (is_alive(philo))
	{
		printf("%lld	%d  is eating\n", time, philo->id);
		philo->num_meal++;
	}
	pthread_mutex_unlock(&philo->data->write_lock);
	pthread_mutex_lock(&philo->data->moment_death);
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->data->moment_death);
	is_sleep(philo->data->eat, philo->data);
	pthread_mutex_unlock(&philo->data->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->fork[philo->right_fork]);
}

void	is_sleeping(t_data *data, t_philo *philo)
{
	long long	time;

	if (is_alive(philo))
	{
		time = get_time() - philo->data->start_time;
		if (is_alive(philo))
		{
			pthread_mutex_lock(&data->write_lock);
			printf("%lld	%d  is sleeping\n", time, philo->id);
			pthread_mutex_unlock(&data->write_lock);
			is_sleep(data->sleep, data);
		}
	}
}

int	ft_all_eat(t_data *data)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (i < data->nbr_philo)
	{
		if (data->philo[i].num_meal == data->nbr_eat)
			y++;
		i++;
	}
	if (y == data->nbr_philo)
		return (1);
	return (0);
}

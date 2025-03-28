/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamdao <molamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:20:02 by molamdao          #+#    #+#             */
/*   Updated: 2025/03/28 15:55:51 by molamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_philo(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (data->nbr_philo == 1)
	{
		printf("%lld	%d  has taken a fork\n", get_time()
			- philo->data->start_time, philo->id);
		is_sleep(data->time_die, philo->data);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(100);
	while (!data->die)
	{
		if (philo->data->nbr_eat == philo->num_meal)
			return (NULL);
		pick_fork(philo);
		is_eating(philo);
		is_sleeping(data, philo);
		thinking(data, philo);
	}
	return (NULL);
}

long long	ft_atoi(const char *str1)
{
	int			i;
	long long	nb;
	int			sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str1[i] == 32 || (str1[i] >= 9 && str1[i] <= 13))
		i++;
	if (str1[i] == '-' || str1[i] == '+')
	{
		if (str1[i] == '-')
			sign *= -1;
		i++;
	}
	while (str1[i] >= '0' && str1[i] <= '9')
	{
		nb *= 10;
		nb = nb + (str1[i++] - 48);
	}
	return (nb * sign);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_alive(t_philo *philo)
{
	return (philo->data->die != 1);
}

void	ft_check_death(t_data *data)
{
	while (1)
	{
		if (ft_all_eat(data) == 1)
			return ;
		ft_check_eat(data);
		if (data->die == 1)
			return ;
	}
	return ;
}

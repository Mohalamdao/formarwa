/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molamdao <molamdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:46:46 by molamdao          #+#    #+#             */
/*   Updated: 2025/03/28 16:02:04 by molamdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "./ft_printf/ft_printf.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef pthread_mutex_t	t_mutex;
struct					s_data;

typedef struct s_philo
{
	pthread_t			thread;
	_Atomic long long	last_eat;
	int					death;
	int					id;
	int					left_fork;
	int					right_fork;
	int					num_meal;
	struct s_data		*data;
}						t_philo;

typedef struct s_data
{
	int					nbr_philo;
	t_philo				*philo;
	pthread_mutex_t		*fork;
	_Atomic int			die;
	long long			time_die;
	int					eat;
	long long			sleep;
	int					nbr_eat;
	long long			start_time;
	t_mutex				write_lock;
	t_mutex				moment_death;
}						t_data;

/*                  LIBFT                   */
int						ft_isdigit(int c);
long long				ft_atoi(const char *str1);
void					free_all(t_data *data, t_philo *philo);
int						ft_all_eat(t_data *data);
int						is_alive(t_philo *philo);

/*					MAIN					*/
int						main_part_2(t_data **data, int ac, char **av, int i);
int						init_philo(t_data **data, int i);
long long				get_time(void);
int						main(int ac, char **av);
void					*routine_philo(void *arg);

/*					Activity					*/
void					thinking(t_data *data, t_philo *philo);
void					pick_fork(t_philo *philo);
void					is_sleep(long long time, t_data *data);
void					is_eating(t_philo *philo);
void					is_sleeping(t_data *data, t_philo *philo);
void					ft_check_eat(t_data *data);

/*					PARSING						*/
int						parsing(char **av, int i, int y);
int						ft_check_num(char **av);
void					ft_check_death(t_data *data);

#endif
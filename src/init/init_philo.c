/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:30:22 by mpoussie          #+#    #+#             */
/*   Updated: 2023/11/21 10:07:35 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	p_init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i++ < data->nbr_philo)
	{
		if (pthread_mutex_init(&(data->fork[i - 1]), NULL))
			return (false);
	}
	if (pthread_mutex_init(&(data->m_write), NULL))
		return (false);
	if (pthread_mutex_init(&(data->m_eat), NULL))
		return (false);
	if (pthread_mutex_init(&(data->m_die), NULL))
		return (false);
	return (true);
}

bool	p_init_philosophers(t_data *data)
{
	int	i;

	if (p_init_mutex(data) == false)
	{
		printf(ERROR_INIT_MUTEX);
		return (false);
	}
	i = data->nbr_philo;
	while (--i >= 0)
	{
		data->philo[i].id = i;
		data->philo[i].last_eat = 0;
		data->philo[i].count_eat = 0;
		data->philo[i].fork_left_id = i;
		data->philo[i].fork_right_id = (i + 1) % data->nbr_philo;
		data->philo[i].data = data;
	}
	return (true);
}

bool	p_init_data(t_data *data, int argc, char **argv)
{
	data->nbr_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->running = 0;
	data->p_die = 0;
	data->nbr_eat = -1;
	if (data->nbr_philo < 2 || data->time_die < 0 || data->time_eat < 0
		|| data->time_sleep < 0 || data->nbr_philo > 250)
	{
		printf(ERROR_INIT_VALUE);
		return (false);
	}
	if (argc != ARG__MAX)
	{
		p_init_philosophers(data);
		return (true);
	}
	data->nbr_eat = ft_atoi(argv[5]);
	if (data->nbr_eat <= 0)
	{
		printf(ERROR_INIT_VALUE);
		return (false);
	}
	return (true);
}

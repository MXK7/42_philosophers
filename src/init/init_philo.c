/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:30:22 by mpoussie          #+#    #+#             */
/*   Updated: 2023/11/17 01:02:58 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	p_init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i++ < data->nbr_philo)
	{
		if (pthread_mutex_init(&(data->fork[i]), NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&(data->m_write), NULL))
		return (1);
	if (pthread_mutex_init(&(data->m_eat), NULL))
		return (1);
	return (0);
}

int	p_init_philosophers(t_data *data, int argc, char **argv)
{
	int	i;

	p_init_data(data, argc, argv);
	p_init_mutex(data);
	data->first_time = p_get_time();
	data->running = 0;
	data->p_die = 0;
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
	return (1);
}

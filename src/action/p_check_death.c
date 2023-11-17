/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_check_death.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:38:59 by mpoussie          #+#    #+#             */
/*   Updated: 2023/11/17 01:05:14 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_check_death(t_data *data, t_philo *philo)
{
	int	i;

	while (!(data->running))
	{
		i = -1;
		pthread_mutex_lock(&(data->m_die));
		while (++i < data->nbr_philo && !(data->p_die))
		{
			pthread_mutex_lock(&(data->m_eat));
			if (p_time_diff(philo[i].last_eat, p_get_time()) > data->time_die)
			{
				ft_message("died.", i, data);
				data->p_die++;
			}
			pthread_mutex_unlock(&(data->m_eat));
			usleep(100);
		}
		pthread_mutex_lock(&(data->m_die));
		if (data->p_die)
		{
			pthread_mutex_unlock(&(data->m_die));
			break ;
		}
		pthread_mutex_unlock(&(data->m_die));
		i = 0;
		while (i < data->nbr_philo && philo[i].count_eat >= data->nbr_eat)
			i++;
		if (i == data->nbr_philo)
			data->running = 1;
	}
}

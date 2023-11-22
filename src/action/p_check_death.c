/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_check_death.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:38:59 by mpoussie          #+#    #+#             */
/*   Updated: 2023/11/21 09:33:19 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	p_check_death(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(philo->data->m_die));
	if (data->p_die == 1)
	{
		pthread_mutex_unlock(&(philo->data->m_die));
		return (true);
	}
	pthread_mutex_unlock(&(philo->data->m_die));
	return (false);
}

void	p_handle_death(t_data *data, t_philo *philo)
{
	int	i;

	while (!(data->running))
	{
		i = -1;
		while (++i < data->nbr_philo && p_check_death(data, philo) != true)
		{
			pthread_mutex_lock(&(data->m_eat));
			if (p_time_diff(philo[i].last_eat, p_get_time()) > data->time_die)
			{
				ft_message("died.", i, data, philo);
				data->p_die = 1;
			}
			pthread_mutex_unlock(&(data->m_eat));
			usleep(100);
		}
		if (p_check_death(data, philo) == true)
			break ;
		i = 0;
		while (data->nbr_eat != -1 && i < data->nbr_philo
			&& philo[i].count_eat >= data->nbr_eat)
			i++;
		if (i == data->nbr_philo)
			data->running = 1;
	}
}

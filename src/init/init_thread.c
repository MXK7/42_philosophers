/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:44:04 by mpoussie          #+#    #+#             */
/*   Updated: 2023/11/17 01:12:58 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	p_exit(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philo)
		pthread_join(philo[i].thread, NULL);
	i = -1;
	while (++i < data->nbr_philo)
		pthread_mutex_destroy(&(data->fork[i]));
	pthread_mutex_destroy(&(data->m_write));
	pthread_mutex_destroy(&(data->m_die));
}

int	p_init_thread(t_data *data)
{
	int	i;
	t_philo *philo;

	i = 0;
	philo = data->philo;
	data->first_time = p_get_time();
	while (i < data->nbr_philo)
	{
		if (pthread_create(&(philo[i].thread), NULL, p_init_action, &(philo[i])))
		{
			printf(ERROR_PTHREAD);
			return (0);
		}
		pthread_mutex_lock(&(data->m_eat));
		philo[i].last_eat = p_get_time();
		pthread_mutex_unlock(&(data->m_eat));
		i++;
	}
	p_check_death(data, data->philo);
	p_exit(data, philo);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:44:04 by mpoussie          #+#    #+#             */
/*   Updated: 2023/11/21 09:38:29 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	p_exit(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->nbr_philo)
		pthread_mutex_destroy(&(data->fork[i]));
	i = -1;
	while (++i < data->nbr_philo)
		pthread_join(philo[i].thread, NULL);
	pthread_mutex_destroy(&(data->m_write));
	pthread_mutex_destroy(&(data->m_die));
}

bool	p_init_thread(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = data->philo;
	data->first_time = p_get_time();
	while (i < data->nbr_philo)
	{
		pthread_create(&(philo[i].thread), NULL, p_init_action, &(philo[i]));
		philo[i].last_eat = p_get_time();
		i++;
	}
	p_handle_death(data, data->philo);
	p_exit(data, philo);
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_eats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:47:44 by mpoussie          #+#    #+#             */
/*   Updated: 2023/11/21 09:50:00 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_eats(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&(data->fork[philo->fork_left_id]));
	ft_message("has taken a fork.", philo->id, data, philo);
	pthread_mutex_lock(&(data->fork[philo->fork_right_id]));
	ft_message("has taken a fork.", philo->id, data, philo);
	pthread_mutex_lock(&(data->m_eat));
	ft_message("is eating.", philo->id, data, philo);
	philo->last_eat = p_get_time();
	pthread_mutex_unlock(&(data->m_eat));
	p_sleep(data->time_eat, data, philo);
	(philo->count_eat)++;
	pthread_mutex_unlock(&(data->fork[philo->fork_left_id]));
	pthread_mutex_unlock(&(data->fork[philo->fork_right_id]));
}

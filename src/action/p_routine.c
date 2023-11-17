/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_routine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:47:44 by mpoussie          #+#    #+#             */
/*   Updated: 2023/11/17 01:05:21 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_eats(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&(data->fork[philo->fork_left_id]));
	ft_message("has taken a fork.", philo->id, data);
	pthread_mutex_lock(&(data->fork[philo->fork_right_id]));
	ft_message("has taken a fork.", philo->id, data);
	pthread_mutex_lock(&(data->m_eat));
	ft_message("is eating.", philo->id, data);
	philo->last_eat = p_get_time();
	pthread_mutex_unlock(&(data->m_eat));
	p_usleep(data->time_eat, data);
	pthread_mutex_unlock(&(data->fork[philo->fork_right_id]));
	pthread_mutex_unlock(&(data->fork[philo->fork_left_id]));
}

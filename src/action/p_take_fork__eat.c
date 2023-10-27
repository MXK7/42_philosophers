/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_take_fork__eat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:47:44 by mpoussie          #+#    #+#             */
/*   Updated: 2023/10/27 18:33:03 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_take_fork__eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork_left);
	pthread_mutex_lock(&philo->data->m_write);
	ft_message("has taken a fork.", philo);
	pthread_mutex_unlock(&philo->data->m_write);
	if (!philo->fork_right)
	{
		ft_usleep(philo->data->time_die * 2);
		return ;
	}
	pthread_mutex_lock(philo->fork_right);
	pthread_mutex_lock(&philo->data->m_write);
	ft_message("has taken a fork.", philo);
	pthread_mutex_unlock(&philo->data->m_write);
	pthread_mutex_lock(&philo->data->m_write);
	ft_message("is eating.", philo);
	pthread_mutex_lock(&philo->data->m_time_eat);
	philo->ms_eat = p_get_time();
	pthread_mutex_unlock(&philo->data->m_time_eat);
	pthread_mutex_unlock(&philo->data->m_write);
	ft_usleep(philo->data->time_eat);
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(&philo->fork_left);
}

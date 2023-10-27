/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sleep_think.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 14:51:47 by mpoussie          #+#    #+#             */
/*   Updated: 2023/10/27 16:27:03 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_sleep_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_write);
	ft_message("is sleeping.", philo);
	pthread_mutex_unlock(&philo->data->m_write);
	ft_usleep(philo->data->time_sleep);
	pthread_mutex_lock(&philo->data->m_write);
	ft_message("is thinking.", philo);
	pthread_mutex_unlock(&philo->data->m_write);
}

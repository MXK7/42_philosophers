/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_is_dead.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:20:56 by mpoussie          #+#    #+#             */
/*   Updated: 2023/11/08 19:58:18 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*p_is_dead(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	ft_usleep(philo->data->time_die + 1);
	pthread_mutex_lock(&philo->data->m_time_eat);
	pthread_mutex_lock(&philo->data->m_finish);
	if (!p_check_death(philo, 0, true) && !philo->finish && ((p_get_time()
				- philo->ms_eat) >= (long)(philo->data->time_die)))
	{
		pthread_mutex_unlock(&philo->data->m_time_eat);
		pthread_mutex_unlock(&philo->data->m_finish);
		pthread_mutex_lock(&philo->data->m_write);
		ft_message("died.", philo);
		pthread_mutex_unlock(&philo->data->m_write);
		p_check_death(philo, 1, false);
		philo->finish = 1;
	}
	pthread_mutex_unlock(&philo->data->m_time_eat);
	pthread_mutex_unlock(&philo->data->m_finish);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_check_death.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:38:59 by mpoussie          #+#    #+#             */
/*   Updated: 2023/11/08 18:55:27 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	p_check_death(t_philo *philo, int i, bool use_stop)
{
	pthread_mutex_lock(&philo->data->m_dead);
	if (i && use_stop != false)
		philo->data->stop = i;
	if (philo->data->stop)
	{
		pthread_mutex_unlock(&philo->data->m_dead);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->m_dead);
	return (0);
}

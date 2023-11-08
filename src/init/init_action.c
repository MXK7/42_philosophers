/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:28:05 by mpoussie          #+#    #+#             */
/*   Updated: 2023/11/08 19:40:58 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*p_init_action(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if ((philo->index % 2) == 0)
		ft_usleep(philo->data->time_eat / 10);
	while (!p_check_death(philo, 0, true))
	{
		if (p_check_death(philo, 0, false))
			break ;
		pthread_create(&philo->t_death_id, NULL, p_is_dead, data);
		p_routine(philo);
		pthread_detach(philo->t_death_id);
		if ((int)philo->nbr_eat == philo->data->m_eat)
		{
			pthread_mutex_lock(&philo->data->m_finish);
			philo->finish = 1;
			philo->data->nbr_philo_finish++;
			if (philo->data->nbr_philo_finish == philo->data->nbr_philo)
			{
				pthread_mutex_unlock(&philo->data->m_finish);
				p_check_death(philo, 2, false);
			}
			pthread_mutex_unlock(&philo->data->m_finish);
			// philo->nbr_eat++;
			return (NULL);
		}
	}
	ft_usleep(1);
	return (NULL);
}

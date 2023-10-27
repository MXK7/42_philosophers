/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:28:05 by mpoussie          #+#    #+#             */
/*   Updated: 2023/10/27 21:43:39 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	p_action(t_philo *philo)
{
	p_take_fork__eat(philo);
	p_sleep_think(philo);
}

void	*p_init_action(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if ((philo->index % 2) == 0)
		ft_usleep(philo->data->time_eat);
	printf("44");
	while (p_check_death(philo, 0))
	{
		pthread_create(&philo->t_death_id, NULL, p_is_dead, data);
		p_action(data);
		pthread_detach(philo->t_death_id);
		if ((int)++philo->nbr_eat == philo->data->m_eat)
		{
			pthread_mutex_lock(&philo->data->m_finish);
			philo->running = 1;
			philo->data->nbr_philo_finish++;
			if (philo->data->nbr_philo_finish == philo->data->nbr_philo)
			{
				pthread_mutex_unlock(&philo->data->m_finish);
				p_check_death(philo, 2);
			}
			pthread_mutex_unlock(&philo->data->m_finish);
			return (NULL);
		}
	}
	return (NULL);
}

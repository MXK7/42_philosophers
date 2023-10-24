/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_init_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 15:44:31 by mpoussie          #+#    #+#             */
/*   Updated: 2023/10/03 15:51:44 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*p_init_action(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (true)
	{
		if (philo->nbr_eat == philo->data->eat_count)
			break;
		printf("[PLAYER %d - %lld] : Philosophers think.\n", philo->index, p_time_diff(philo->ms_eat, p_get_time()));
		pthread_mutex_lock(&philo->fork_left);
		printf("[PLAYER %d - %lld] : Philosopher takes a fork.\n", philo->index, p_time_diff(philo->ms_eat, p_get_time()));
		if (philo->is_dead == 1)
			break;
		pthread_mutex_lock(philo->fork_right);
		printf("[PLAYER %d - %lld] : Philosopher takes a fork.\n", philo->index, p_time_diff(philo->ms_eat, p_get_time()));
		printf("[PLAYER %d - %lld] : Philosopher is eating.\n", philo->index, p_time_diff(philo->ms_eat, p_get_time()));
		ft_usleep(philo->data->time_eat);
		pthread_mutex_unlock(&philo->fork_left);
        pthread_mutex_unlock(philo->fork_right);
		if (philo->is_dead == 1)
			break;
		philo->ms_eat = p_get_time();
		philo->end_eat = p_time_diff(philo->first_time, p_get_time()) * 1000;
		philo->nbr_eat++;
		if (philo->is_dead == 1)
			break;
		printf("[PLAYER %d - %lld] : Philosopher is sleeping.\n", philo->index, p_time_diff(philo->ms_eat, p_get_time()));
		ft_usleep(philo->data->time_sleep);
	}
	printf("[PLAYER %d] : End philosopher .\n", philo->index);
	return (NULL);
}
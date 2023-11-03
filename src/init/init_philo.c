/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:30:22 by mpoussie          #+#    #+#             */
/*   Updated: 2023/11/03 18:30:34 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	p_init_mutex(t_game *game)
{
	pthread_mutex_init(&(game->data.m_dead), NULL);
	pthread_mutex_init(&(game->data.m_finish), NULL);
	pthread_mutex_init(&(game->data.m_write), NULL);
	pthread_mutex_init(&(game->data.m_time_eat), NULL);
}

int	p_init_philosophers(t_game *game)
{
	int	i;

	i = 0;
	game->data.first_time = p_get_time();
	game->data.stop = 0;
	game->data.nbr_philo_finish = 0;
	p_init_mutex(game);
	while (i < game->data.nbr_philo)
	{
		game->philo[i].index = i + 1;
		game->philo[i].is_dead = 0;
		game->philo[i].nbr_eat = 0;
		game->philo[i].fork_right = NULL;
		game->philo[i].ms_eat = game->data.first_time;
		pthread_mutex_init(&(game->philo[i].fork_left), NULL);
		if (i == game->data.nbr_philo - 1)
			game->philo[i].fork_right = &game->philo[0].fork_left;
		else
			game->philo[i].fork_right = &game->philo[i + 1].fork_left;
		i++;
	}
	return (0);
}

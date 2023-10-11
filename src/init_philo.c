/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:30:22 by mpoussie          #+#    #+#             */
/*   Updated: 2023/10/11 19:56:12 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philosophers(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->nbr_philo)
	{
		game->philos[i].index = i + 1;
		game->philos[i].is_dead = 0;
		game->philos[i].nbr_eat = 0;
		game->philos[i].last_eat = game->first_time;
		pthread_mutex_init(&game->forks[i].mutex, 0);
		// game->forks[i].mutex = ;
		i++;
	}
}

void	p_init_data(t_game *game, int argc, char **argv)
{
	game->nbr_philo = ft_atoi(argv[1]);
	game->time_die = ft_atoi(argv[2]);
	game->time_eat = ft_atoi(argv[3]);
	game->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		game->eat_count = ft_atoi(argv[5]);
	else
		game->eat_count = -1;
	game->philos = malloc(sizeof(t_philo *) * 1000);
	init_philosophers(game);
}

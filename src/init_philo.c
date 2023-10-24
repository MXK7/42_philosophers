/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:30:22 by mpoussie          #+#    #+#             */
/*   Updated: 2023/10/23 21:09:50 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static void	init_mutex(t_game *game)
// {
// 	// pthread_mutex_init(&philo->data.write_mutex, NULL);
// 	// pthread_mutex_init(&game->philo.data.finish, NULL);
// 	pthread_mutex_init(&(game->philo->data->m_dead), NULL);
// 	pthread_mutex_init(&(game->philo->data->m_time_eat), NULL);
// }

static int	init_philosophers(t_game *game)
{
	int	i;

	i = 0;
	// printf("4654\n");
	// init_mutex(game);
	// printf("4654\n");
	game->data.running = p_get_time();
	while (i < game->data.nbr_philo)
	{
		game->philo[i].index = i + 1;
		game->philo[i].is_dead = 0;
		game->philo[i].nbr_eat = 0;
		game->philo[i].ms_eat = game->data.first_time;
		// pthread_mutex_init(&(game->philo[i].data->m_dead), NULL);
		// pthread_mutex_init(&(game->philo[i].data->m_time_eat), NULL);
		pthread_mutex_init(&(game->philo[i].fork_left), NULL);
		if (game->data.nbr_philo == 1)
			return (1);
		if (i == game->data.nbr_philo)
			game->philo[i].fork_right = &game->philo[0].fork_left;
		else
			game->philo[i].fork_right = &game->philo[i + 1].fork_left;
		i++;
	}
	return (0);
}

void	p_init_data(t_game *game, int argc, char **argv)
{
	game->data.nbr_philo = ft_atoi(argv[1]);
	game->data.time_die = ft_atoi(argv[2]);
	game->data.time_eat = ft_atoi(argv[3]);
	game->data.time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		game->data.eat_count = ft_atoi(argv[5]);
	else
		game->data.eat_count = -1;
	init_philosophers(game);
}

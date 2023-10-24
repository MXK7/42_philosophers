/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:44:04 by mpoussie          #+#    #+#             */
/*   Updated: 2023/10/24 19:41:18 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void p_check_death(t_game *game)
{
	int i;

	game->data.count_philo_death = 0;
	while (game->data.count_philo_death <= game->data.nbr_philo)
	{
		i = 0;
		while (i < game->data.nbr_philo)
		{
            if (game->philo[i].last_eat >= 0)
            {
                if (p_time_diff(game->philo[i].last_eat, p_get_time()) > game->data.time_die)
                {
                    game->philo[i].is_dead = 1;
                    game->philo[i].last_eat = -1;
                    game->data.count_philo_death++;
                    printf("%lld test is_dead : %d du philo %d\n===============\n",p_time_diff(game->data.first_time, p_get_time()), game->philo[i].is_dead, i + 1);
                }
			}
			i++;
		}
	}
}

void	p_init_thread(t_game *game)
{
	int	i;

	i = 0;
	game->data.first_time = p_get_time();
	while (i < game->data.nbr_philo)
	{
		game->philo[i].data = &game->data;
		// printf("CREATE THREAD N*%d\n", i + 1);
		pthread_create(&game->philo[i].thread, 0, &p_init_action, (void *)&game->philo[i]);
		i++;
	}
    p_check_death(game);
	i = 0;
	while (i < game->data.nbr_philo)
	{
		pthread_join(game->philo[i].thread, 0);
		i++;
	}
}

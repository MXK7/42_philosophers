/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:35:09 by mpoussie          #+#    #+#             */
/*   Updated: 2023/11/03 17:06:54 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	check_death2(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->data->m_dead);
// 	if (philo->data->stop)
// 	{
// 		pthread_mutex_unlock(&philo->data->m_dead);
// 		return (1);
// 	}
// 	pthread_mutex_unlock(&philo->data->m_dead);
// 	return (0);
// }

static int	p_check_args(int argc, char **argv)
{
	int	i;
	int	*tab;

	tab = malloc(sizeof(int *) * (argc - 1));
	i = 1;
	while (i <= argc - 1)
	{
		if (ft_atoi(argv[i]) == 0)
		{
			free(tab);
			printf(ERROR_DIGIT);
			return (1);
		}
		tab[i] = ft_atoi(argv[i]);
		i++;
	}
	if (tab[1] < 1)
	{
		printf(ERROR_INT_MIN);
		return (1);
	}
	free(tab);
	return (0);
}

static void	p_stop(t_game *game)
{
	int	i;

	i = 0;
	while (!p_check_death(game->philo, 0))
		ft_usleep(10);
	while (i < game->data.nbr_philo)
	{
		pthread_join(game->philo[i].thread, NULL);
		i++;
	}
	pthread_mutex_destroy(&game->philo->data->m_write);
	pthread_mutex_destroy(&game->philo->data->m_dead);
	pthread_mutex_destroy(&game->philo->data->m_finish);
	pthread_mutex_destroy(&game->philo->data->m_time_eat);
	i = 0;
	while (i < game->data.nbr_philo)
	{
		pthread_mutex_destroy(&game->philo[i].fork_left);
		i++;
	}
	if (game->data.stop == 2)
		printf("Each philosopher ate %d time(s)\n", game->data.m_eat);
	free(game->philo);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == ARG__MIN || argc == ARG__MAX)
	{
		if (!p_check_args(argc, argv))
		{
			p_init_data(&game, argc, argv);
			game.philo = malloc(sizeof(t_philo) * game.data.nbr_philo);
			if (game.philo == NULL)
			{
				printf(ERROR_ALLOC);
				return (0);
			}
			if (!p_init_philosophers(&game) && !p_init_thread(&game))
			{
				free(game.philo);
				return (0);
			}
			p_stop(&game);
		}
	}
	else
		printf(ERROR_ARGS);
	return (0);
}

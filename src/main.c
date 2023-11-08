/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:35:09 by mpoussie          #+#    #+#             */
/*   Updated: 2023/11/08 19:56:13 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

// static void	p_stop(t_game *game)
// {
// 	int	i;

// 	i = -1;
// 	while (!p_check_death(game->philo, 0, true))
// 	{
// 		ft_usleep(1);
// 		if (game->philo->finish == 1)
// 			break;
// 	}
// 	// while (++i != game->data.nbr_philo)
// 	// {
// 	// 	printf("nbr%d\ni:%d\n", game->data.nbr_philo, i);
// 	// 	if (i == game->data.nbr_philo)
// 	// 		break;
// 	// 	pthread_join(game->philo[i].thread, NULL);
// 	// 	pthread_mutex_destroy(&game->philo[i].fork_left);
// 	// }
// 	if (game->data.stop == 2)
// 		printf("Each philosopher ate %d time(s)\n", game->data.m_eat);
// 	free(game->philo);
// }



void	exit_launcher(t_game *game)
{
	int i;

	i = -1;
	while (++i < game->data.nbr_philo)
		pthread_join(game->philo[i].thread, NULL);
	i = -1;
	while (++i < game->data.nbr_philo)
		pthread_mutex_destroy(&(game->philo[i].fork_left));
	pthread_mutex_destroy(&(game->data.m_write));
}

void	p_stop(t_game *game)
{
	while (!p_check_death(game->philo, 0, true))
	{
		ft_usleep(1);
		if (game->philo->finish == 1)
			break;
	}
	exit_launcher(game);
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
			if (!p_init_philosophers(&game) || !p_init_thread(&game))
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

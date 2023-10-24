/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:35:09 by mpoussie          #+#    #+#             */
/*   Updated: 2023/10/24 18:07:50 by mpoussie         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == ARG__MIN || argc == ARG__MAX)
	{
		if (!p_check_args(argc, argv))
		{
			game.philo = malloc(sizeof(t_philo) * game.data.nbr_philo);
			if (game.philo == NULL)
			{
				printf(ERROR_ALLOC);
				return (0);
			}
			p_init_data(&game, argc, argv);
			p_init_thread(&game);
		}
	}
	else
		printf(ERROR_ARGS);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:35:09 by mpoussie          #+#    #+#             */
/*   Updated: 2023/10/11 20:11:08 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	p_check_args(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
	{
		printf(ERROR_ARGS);
		return (1);
	}
	i = 1;
	while (i <= argc)
	{
		if (!ft_isdigit(ft_atoi(argv[i])))
		{
			printf(ERROR_DIGIT);
			return (1);
		}
		i++;
	}
	if (ft_atoi(argv[1]) < 1)
	{
		printf(ERROR_INT_MIN);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (!p_check_args(argc, argv))
	{
		p_init_data(&game, argc, argv);
		p_init_thread(&game);
	}
	return (0);
}

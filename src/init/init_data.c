/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:30:22 by mpoussie          #+#    #+#             */
/*   Updated: 2023/11/07 17:51:32 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_init_data(t_game *game, int argc, char **argv)
{
	game->data.nbr_philo = ft_atoi(argv[1]);
	game->data.time_die = ft_atoi(argv[2]);
	game->data.time_eat = ft_atoi(argv[3]);
	game->data.time_sleep = ft_atoi(argv[4]);
	if (argc == ARG__MAX)
		game->data.eat_count = ft_atoi(argv[5]);
	else
		game->data.eat_count = -1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:44:04 by mpoussie          #+#    #+#             */
/*   Updated: 2023/10/11 19:56:00 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_init_thread(t_game *game)
{
	int	i;

	i = 0;
	game->first_time = p_get_time();
	while (i < game->nbr_philo)
	{
		printf("CREATE THREAD N*%d\n", i + 1);
		pthread_create(&game->philos[i].thread, 0, &p_init_action, (void *)&game->philos[i]);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:44:04 by mpoussie          #+#    #+#             */
/*   Updated: 2023/10/31 20:07:09 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	p_init_thread(t_game *game)
{
	int	i;

	i = 0;
	// game->data.first_time = p_get_time();
	while (i < game->data.nbr_philo)
	{
		game->philo[i].data = &game->data;
		// pthread_create(&game->philo[i].thread, 0, &p_init_action, (void *)&game->philo[i]);
		if (pthread_create(&game->philo[i].thread, 0, &p_init_action, (void *)&game->philo[i]) != 0)
			return (printf(ERROR_PTHREAD));
		i++;
	}
	return (1);
}

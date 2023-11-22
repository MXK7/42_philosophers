/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:28:05 by mpoussie          #+#    #+#             */
/*   Updated: 2023/11/20 13:49:48 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*p_init_action(void *v_philo)
{
	int		i;
	t_philo	*philo;
	t_data	*data;

	i = 0;
	philo = (t_philo *)v_philo;
	data = philo->data;
	if (philo->id % 2)
		usleep(15000);
	while (p_check_death(data, philo) != true)
	{
		p_eats(philo);
		if (data->running)
			break ;
		ft_message("is sleeping.", philo->id, data, philo);
		p_sleep(data->time_sleep, data, philo);
		ft_message("is thinking.", philo->id, data, philo);
		i++;
	}
	return (NULL);
}

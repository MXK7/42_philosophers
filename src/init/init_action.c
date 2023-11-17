/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:28:05 by mpoussie          #+#    #+#             */
/*   Updated: 2023/11/17 01:05:07 by mpoussie         ###   ########.fr       */
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
	while (!(data->p_die))
	{
		p_eats(philo);
		if (data->running)
			break ;
		ft_message("is sleeping.", philo->id, data);
		p_usleep(data->time_sleep, data);
		ft_message("is thinking.", philo->id, data);
		i++;
	}
	return (NULL);
}

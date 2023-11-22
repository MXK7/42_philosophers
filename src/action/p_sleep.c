/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sleep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:31:05 by mpoussie          #+#    #+#             */
/*   Updated: 2023/11/21 09:28:25 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_sleep(long long time, t_data *data, t_philo *philo)
{
	long long	i;

	i = p_get_time();
	while (p_check_death(data, philo) != true)
	{
		if (p_time_diff(i, p_get_time()) >= time)
			break ;
		usleep(50);
	}
}

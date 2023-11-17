/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_sleep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:31:05 by mpoussie          #+#    #+#             */
/*   Updated: 2023/11/17 01:05:41 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_usleep(long long time, t_data *data)
{
	long long	i;

	i = p_get_time();
	while (!(data->p_die))
	{
		if (p_time_diff(i, p_get_time()) >= time)
			break ;
		usleep(50);
	}
}

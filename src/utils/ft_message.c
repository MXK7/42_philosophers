/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:44:20 by mpoussie          #+#    #+#             */
/*   Updated: 2023/11/20 14:24:58 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_message(char *str, int id, t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&(data->m_write));
	if (p_check_death(data, philo) != true)
	{
		printf("TIME [%lli] ", p_get_time() - data->first_time);
		printf("Philosophers [%d] : %s\n", id + 1, str);
	}
	pthread_mutex_unlock(&(data->m_write));
	return ;
}

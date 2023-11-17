/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:44:20 by mpoussie          #+#    #+#             */
/*   Updated: 2023/11/16 22:41:50 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_message(char *str, int id, t_data *data)
{
	pthread_mutex_lock(&(data->m_write));
	if (!(data->p_die))
	{
		printf("TIME : %ld\n", p_get_time() - data->first_time);
		printf("Philosophers [%d] : %s\n", id, str);
	}
	pthread_mutex_unlock(&(data->m_write));
	return ;
}

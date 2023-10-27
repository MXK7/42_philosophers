/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:44:20 by mpoussie          #+#    #+#             */
/*   Updated: 2023/10/27 15:02:52 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_message(char *str, t_philo *philo)
{
	long int	time;

	time = -1;
	time = p_get_time() - philo->data->first_time;
	if (time >= 0 && time <= 2147483647 && !p_check_death(philo, 0))
	{
		printf("TIME : %ld\n", time);
		printf("Philosophers [%d] : %s \n\n", philo->index, str);
	}
}

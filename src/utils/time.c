/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:26:25 by mpoussie          #+#    #+#             */
/*   Updated: 2023/10/27 16:27:18 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	p_time_diff(long long i, long long time)
{
	return (time - i);
}

/*
 @tv_sec : Stocke les secondes
 @tv_usec : Stocke les microsecondes
*/
unsigned long int	p_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (unsigned long int)1000) + (time.tv_usec / 1000));
}

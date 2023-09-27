/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:30:22 by mpoussie          #+#    #+#             */
/*   Updated: 2023/09/27 17:13:59 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../philo.h"

static void	init_philosophers(t_info *info, t_player *player, char **argv)
{
	int	i;

	i = 0;
	while (i < info->nbr_philo)
	{
		info->player[i].info = i + 1;
		info->player[i].index = 0;
		info->player[i].is_dead = 0;
		info->player[i].nbr_eat = 0;
		info->player[i].last_eat = info->first_time;
		pthread_mutex_init(&info->player[i].left_fork, 0);
		if (i == info->nbr_philo - 1)
			info->player[i].right_fork = &info->player[0].left_fork;
		else
			info->player[i].right_fork = &info->player[i + 1].left_fork;
		i++;
	}
}

void	init_data(t_info *info, t_player *player, int argc, char **argv)
{
	info->nbr_philo = ft_atoi(argv[1]);
	info->time_die = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->nbr_eating = ft_atoi(argv[5]);
	else
		info->nbr_eating = -1;
	info->player = malloc(sizeof(t_info) * info->nbr_philo);
	init_philosophers(info, player, argv);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:35:36 by mpoussie          #+#    #+#             */
/*   Updated: 2023/09/21 13:53:57 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOHPERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_player
{
	int nbr_eat;
	int is_dead;
	int index;
	long long last_eat;
	long long end_eat;
	pthread_t		thread;
	pthread_mutex_t *right_fork;
	pthread_mutex_t left_fork;

	struct t_info *info;
}				t_player;

typedef struct s_info
{
	int			nbr_philo;
	int 		nbr_eating;

	int			time_die;
	int			time_eat;
	int			time_sleep;
	
	int			running;
	int			first_time;

	struct s_player	*player;
}				t_info;


int		ft_atoi(const char *str);
void 	init_data(t_info *info, int argc, char **argv);
void	init_philo(t_info *info, t_player *player, char **argv);

#endif
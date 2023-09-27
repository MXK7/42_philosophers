/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:14:27 by mpoussie          #+#    #+#             */
/*   Updated: 2023/09/27 17:27:20 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_ARGS "You need 4 or 5 arguments.\n"
# define ERROR_ARGS_1 "Argument 1 must be greater than 0.\n"

typedef struct s_player
{
	int				nbr_eat;
	int				is_dead;
	int				index;
	long long		last_eat;
	long long		end_eat;
	pthread_t		thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	left_fork;

	struct t_info	*info;
}					t_player;

typedef struct s_info
{
	int				nbr_philo;
	int				nbr_eating;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				running;
	int				first_time;
	struct s_player	*player;
}					t_info;

int					ft_atoi(const char *str);
void				init_data(t_info *info, t_player *player, int argc,
						char **argv);
void				init_philo(t_info *info, t_player *player, char **argv);

long long			p_time_diff(long long i, long long time);
unsigned long		p_get_time(void);
#endif
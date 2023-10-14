/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:14:27 by mpoussie          #+#    #+#             */
/*   Updated: 2023/10/14 18:37:48 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define ERROR_ARGS "You need 4 or 5 arguments.\n"
# define ERROR_INT_MIN "Argument 1 must be greater than 0.\n"
# define ERROR_DIGIT "Argument is not numbers.\n"

typedef struct s_fork
{
	pthread_mutex_t	mutex;
}					t_fork;

typedef struct s_philo
{
	int				index;
	int				nbr_eat;
	int				is_dead;
	long long		last_eat;
	long long		end_eat;
	pthread_t		thread;
}					t_philo;

typedef struct s_game
{
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nbr_philo;
	int				eat_count;
	int				first_time;
	int				running;
	t_philo			*philos;
	t_fork			*forks;
}					t_game;

// ############# UTILS ############# //
int					ft_atoi(const char *str);
int					ft_isdigit(int c);

long long			p_time_diff(long long i, long long time);
unsigned long		p_get_time(void);

// ############# INIT ############# //
void				*p_init_action(void *args);
void				p_init_data(t_game *game, int argc, char **argv);
void				p_init_thread(t_game *game);

#endif
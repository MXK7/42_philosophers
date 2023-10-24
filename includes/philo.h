/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:14:27 by mpoussie          #+#    #+#             */
/*   Updated: 2023/10/24 18:09:46 by mpoussie         ###   ########.fr       */
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
# define ERROR_ALLOC "Allocation memory is NULL.\n"

typedef struct s_data
{
	int				time_die;
	int				time_sleep;
	int				nbr_philo;
	int				time_eat;
	int				eat_count;
	int				first_time;
	int				running;
	int				count_philo_death;

	pthread_mutex_t	m_time_eat;
	pthread_mutex_t	m_dead;
}					t_data;

typedef struct s_philo
{
	int				index;
	int				nbr_eat;
	int				is_dead;
	int				first_time;

	long long		ms_eat;
	long long		end_eat;
	long long		last_eat;

	pthread_mutex_t	*fork_right;
	pthread_mutex_t	fork_left;

	pthread_t		thread;
	pthread_t		t_death_id;

	t_data			*data;
}					t_philo;

typedef struct s_game
{
	t_philo			*philo;
	t_data			data;
}					t_game;

typedef enum e_args
{
	ARG_PN,
	ARG_NBR_PHILO,
	ARG_T_TO_DIE,
	ARG_T_TO_EAT,
	ARG_T_TO_SLEEP,
	ARG_MIN_EAT_O,
	ARG__MIN = ARG_T_TO_SLEEP + 1,
	ARG__MAX = ARG_MIN_EAT_O + 1,
}					t_args;

// ############# UTILS ############# //
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
int					ft_usleep(int time);

long long			p_time_diff(long long i, long long time);
unsigned long int	p_get_time(void);

// ############# INIT ############# //
void				*p_init_action(void *data);
void				p_init_data(t_game *game, int argc, char **argv);
void				p_init_thread(t_game *game);

#endif
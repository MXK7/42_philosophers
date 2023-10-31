/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:14:27 by mpoussie          #+#    #+#             */
/*   Updated: 2023/10/31 16:20:15 by mpoussie         ###   ########.fr       */
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
# define ERROR_PTHREAD "Thread did not return.\n"

typedef struct s_data
{
	int				m_eat;
	int				time_eat;
	int				time_die;
	int				eat_count;
	int				nbr_philo;
	int				time_sleep;
	int				first_time;
	int				nbr_philo_finish;
	int				count_philo_death;
	int				stop;

	pthread_mutex_t	m_finish;
	pthread_mutex_t	m_dead;
	pthread_mutex_t	m_write;
	pthread_mutex_t	m_time_eat;
}					t_data;

typedef struct s_philo
{
	int				index;
	int				first_time;
	int				finish;

	int				is_dead;
	long long		ms_eat;
	long long		end_eat;
	long long		last_eat;

	unsigned int	nbr_eat;

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
void				ft_usleep(long int time_in_ms);
void				ft_message(char *str, t_philo *philo);

long long			p_time_diff(long long i, long long time);
unsigned long int	p_get_time(void);

// ############# INIT ############# //
void				p_init_data(t_game *game, int argc, char **argv);
int					p_init_thread(t_game *game);
int					p_init_philosophers(t_game *game);
void				*p_init_action(void *data);

// ############# ACTIONS ############# //
void				*p_is_dead(void *data);
int					p_check_death(t_philo *philo, int i);
void				p_take_fork__eat(t_philo *philo);
void				p_sleep_think(t_philo *philo);

#endif
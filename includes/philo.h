/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:14:27 by mpoussie          #+#    #+#             */
/*   Updated: 2023/11/17 00:10:16 by mpoussie         ###   ########.fr       */
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
# define ERROR_GET_TIME "An error has occurred while executing the [@P_GET_TIME] function.\n"

struct s_data;

typedef struct s_philo
{
	int				id;
	int				fork_right_id;
	int				fork_left_id;
	size_t			count_eat;
	size_t			last_eat;
	struct s_data	*data;
	pthread_t		thread;
}					t_philo;

typedef struct s_data
{
	int				p_die;
	int				running;
	int				nbr_philo;
	int				time_eat;
	int				time_die;
	int				time_sleep;
	size_t			nbr_eat;
	size_t			first_time;
	pthread_mutex_t	m_eat;
	pthread_mutex_t	m_write;
	pthread_mutex_t	m_die;
	pthread_mutex_t	fork[250];
	t_philo			philo[250];
}					t_data;

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
void				ft_message(char *str, int id, t_data *data);

long long			p_time_diff(long long i, long long time);
size_t				p_get_time(void);

// ############# INIT ############# //
void				p_init_data(t_data *data, int argc, char **argv);
int					p_init_thread(t_data *game);
int					p_init_philosophers(t_data *data, int argc, char **argv);
void				*p_init_action(void *v_philo);

// ############# ACTIONS ############# //
void				p_usleep(long long time, t_data *data);
void				p_check_death(t_data *data, t_philo *philo);
void				p_eats(t_philo *philo);

#endif
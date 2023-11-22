/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:35:09 by mpoussie          #+#    #+#             */
/*   Updated: 2023/11/21 10:08:47 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	p_check_args(int argc, char **argv)
{
	int	i;
	int	*tab;

	tab = malloc(sizeof(int *) * (argc - 1));
	i = 1;
	while (i <= argc - 1)
	{
		if (ft_atoi(argv[i]) == 0)
		{
			free(tab);
			printf(ERROR_DIGIT);
			return (false);
		}
		tab[i] = ft_atoi(argv[i]);
		i++;
	}
	if (tab[1] < 1)
	{
		printf(ERROR_INT_MIN);
		return (false);
	}
	free(tab);
	return (true);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (1);
	if (argc == ARG__MIN || argc == ARG__MAX)
	{
		if ((p_check_args(argc, argv) == true) && (p_init_data(data, argc,
					argv) == true))
		{
			if (p_init_philosophers(data) == true)
				p_init_thread(data);
		}
	}
	else
		printf(ERROR_ARGS);
	free(data);
	return (0);
}

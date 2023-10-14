/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:35:09 by mpoussie          #+#    #+#             */
/*   Updated: 2023/10/14 19:38:38 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	p_check_args(int argc, char **argv)
{
	int	i;
	int	*tab;

	tab = malloc(sizeof(int *) * (argc - 1));
	i = 1;
	while (i <= argc - 1)
	{
		printf("%d %s,", ft_atoi(argv[i]), argv[i]);
		if (ft_atoi(argv[i]) == 0)
		{
			free(tab);
			printf(ERROR_DIGIT);
			return (1);
		}
		tab[i] = ft_atoi(argv[i]);
		i++;
	}
	printf("\n%d\n", tab[1]);
	if (tab[1] < 1)
	{
		printf(ERROR_INT_MIN);
		return (1);
	}
	free(tab);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 5 || argc == 6)
	{
		if (!p_check_args(argc, argv))
		{
			p_init_data(&game, argc, argv);
			p_init_thread(&game);
		}
	}
	else
		printf(ERROR_ARGS);
	return (0);
}

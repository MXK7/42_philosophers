#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 4
#define ITERATIONS 2

// Variable partagée par les threads
int				shared_variable = 0;

// Mutex pour synchroniser l'accès à la variable partagée
pthread_mutex_t	mutex = PTHREAD_MUTEX_INITIALIZER;

// Fonction exécutée par les threads
void	*thread_function(void *arg)
{
	for (int i = 0; i < ITERATIONS; ++i)
	{
		// Verrouiller le mutex
		pthread_mutex_lock(&mutex);
		// Accéder et modifier la variable partagée
		shared_variable++;
		// Déverrouiller le mutex
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(NULL);
}

int	main(void)
{
	pthread_t	threads[NUM_THREADS];

	// Créer les threads
	for (int i = 0; i < NUM_THREADS; ++i)
	{
		if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0)
		{
			perror("Erreur lors de la création du thread");
			exit(1);
		}
	}
	// Attendre la fin des threads
	for (int i = 0; i < NUM_THREADS; ++i)
	{
		if (pthread_join(threads[i], NULL) != 0)
		{
			perror("Erreur lors de l'attente du thread");
			exit(1);
		}
	}
	// Afficher la valeur finale de la variable partagée
	printf("Valeur finale de la variable partagée : %d\n", shared_variable);
	// Détruire le mutex
	pthread_mutex_destroy(&mutex);
	return (0);
}

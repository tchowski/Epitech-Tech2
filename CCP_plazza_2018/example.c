#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_cond_t condition = PTHREAD_COND_INITIALIZER; /* Création de la condition */
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; /* Création du mutex */

void* threadAlarme (void* arg);
void* threadCompteur (void* arg);

int main (void)
{
	pthread_t monThreadCompteur;
	pthread_t monThreadAlarme;

	pthread_create (&monThreadCompteur, NULL, threadCompteur, (void*)NULL);
	pthread_create (&monThreadAlarme, NULL, threadAlarme, (void*)NULL); /* Création des threads */

	pthread_join (monThreadCompteur, NULL);
	pthread_join (monThreadAlarme, NULL); /* Attente de la fin des threads */

	return 0;
}

void* threadCompteur (void* arg)
{
	int compteur = 0, nombre = 0;

	srand(time(NULL));

	while(1) /* Boucle infinie */
	{
		nombre = rand()%10; /* On tire un nombre entre 0 et 10 */
		compteur += nombre; /* On ajoute ce nombre à la variable compteur */

		printf("\n%d", compteur);

		if(compteur >= 20) /* Si compteur est plus grand ou égal à 20 */
		{
			pthread_mutex_lock (&mutex); /* On verrouille le mutex */
			pthread_cond_signal (&condition); /* On délivre le signal : condition remplie */
			pthread_mutex_unlock (&mutex); /* On déverrouille le mutex */

			compteur = 0; /* On remet la variable compteur à 0 */
		}

		sleep (1); /* On laisse 1 seconde de repos */
	}

	pthread_exit(NULL); /* Fin du thread */
}

void* threadAlarme (void* arg)
{
	while(1) /* Boucle infinie */
	{
		pthread_mutex_lock(&mutex); /* On verrouille le mutex */
		pthread_cond_wait (&condition, &mutex); /* On attend que la condition soit remplie */
		printf("\nLE COMPTEUR A DÉPASSÉ 20.");
		pthread_mutex_unlock(&mutex); /* On déverrouille le mutex */
	}

	pthread_exit(NULL); /* Fin du thread */
}

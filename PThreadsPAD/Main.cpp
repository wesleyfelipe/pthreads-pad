#include <stdio.h>
#include <stdlib.h>
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>

#define N 10000
#define N_THREADS 5
int saldo = 100;
pthread_mutex_t m;

void * deposita(void *str) {
	int i, a;
	for (i = 0; i<N; i++) {
		pthread_mutex_lock(&m);
		a = saldo; a = a + 1; saldo = a;
		pthread_mutex_unlock(&m);
	}
	return 0;
}

void * retira(void *str) {
	int i, b;
	for (i = 0; i<N; i++) {
		pthread_mutex_lock(&m);
		b = saldo; b = b - 1; saldo = b;
		pthread_mutex_unlock(&m);
	}
	return 0;
}

int main() {

	pthread_t threads_deposita[N_THREADS];
	pthread_t threads_retira[N_THREADS];

	pthread_mutex_init(&m, NULL);

	for (int i = 0; i < N_THREADS; i++) {
		pthread_t thid1, thid2;

		pthread_create(&thid1, NULL, deposita, NULL);
		threads_deposita[i] = thid1;

		pthread_create(&thid2, NULL, retira, NULL);
		threads_retira[i] = thid2;

	}

	for (int i = 0; i < N_THREADS; i++) {
		pthread_join(threads_retira[i], NULL);
		pthread_join(threads_deposita[i], NULL);
	}

	printf("SALDO ATUAL = %d\n", saldo);
	return 0;
}
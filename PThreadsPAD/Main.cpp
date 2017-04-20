#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>

#include "FiltroBrilho.h"

using namespace std;

#define QTD_THREADS 5

void *doSomething(void *parameter);
void teste_threads();

int main(int argc, char** argv) {
	teste_threads();
}

/* Metodo criado só para validar se Pthreads está funcionando*/
void teste_threads() {
	alterarBrilho();

	pthread_t threads[QTD_THREADS];

	for (int i = 0; i < QTD_THREADS; i++) {
		pthread_t thread_obj;
		pthread_create(&thread_obj, NULL, doSomething, NULL);
		threads[i] = thread_obj;
	}

	for (int i = 0; i < QTD_THREADS; i++) {
		pthread_join(threads[i], NULL);
	}
}

void *doSomething(void *parameter) {
	printf("Eu sou uma thread\n");
	return (void *)0;
}
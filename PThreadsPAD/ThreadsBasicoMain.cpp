#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>

using namespace std;

#define QTD_THREADS 5

void *doSomething(void *parameter);

int main(int argc, char** argv) {
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
	printf("Eu sou a thread %d\n", pthread_self());
	return (void *)0;
}
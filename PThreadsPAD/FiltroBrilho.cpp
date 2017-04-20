#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>

#include "Imagem.h"

using namespace std;

#define QTD_THREADS 5

Imagem *imagem;

void *alterarBrilhoThread(void *parameter);

void alterarBrilho(Imagem* img) {
	printf("Altura da imagem: %d\n", img->getHeight());
	printf("Largura da imagem: %d\n", img->getWidth());
	printf("Total de pixels: %d\n", img->getHeight() * img->getWidth());

	imagem = img;

	pthread_t threads[QTD_THREADS];

	for (int i = 0; i < QTD_THREADS; i++) {
		pthread_t thread_obj;
		pthread_create(&thread_obj, NULL, alterarBrilhoThread, (void*) i);
		threads[i] = thread_obj;
	}

	for (int i = 0; i < QTD_THREADS; i++) {
		pthread_join(threads[i], NULL);
	}

	Sleep(10000);
}

void *alterarBrilhoThread(void *parameter) {
	int index = (int) parameter;
	printf("Teste %d\n", index);
	return (void *)0;
}

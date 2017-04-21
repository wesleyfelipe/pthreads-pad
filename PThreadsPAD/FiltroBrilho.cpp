#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>

#include "Imagem.h"

using namespace std;

#define QTD_THREADS 5

Imagem *imagem;
int qtdPixelsThread;

void *alterarBrilhoThread(void *parameter);

Imagem* alterarBrilho(Imagem* img) {
	int totalPixels = img->getHeight() * img->getWidth();
	qtdPixelsThread = (int) (totalPixels / QTD_THREADS) + 1;


	printf("Altura da imagem: %d\n", img->getHeight());
	printf("Largura da imagem: %d\n", img->getWidth());
	printf("Total de pixels: %d\n", totalPixels);

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
	//Sleep(20000);

	return imagem;
}

void *alterarBrilhoThread(void *parameter) {
	int index = (int) parameter;
	printf("Teste %d\n", index);
	printf("Vou trabalhar com %d pixels \n", qtdPixelsThread);
	return (void *)0;
}

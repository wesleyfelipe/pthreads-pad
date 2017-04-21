#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>

#include "Imagem.h"

using namespace std;

Imagem *imagem;
int qtdPixelsThread;
int fatorBrilho;
int totalPixels;

void *alterarBrilhoThread(void *parameter);
int getCorBrilho(int cor, int fatorBrilho);

Imagem* alterarBrilho(Imagem* img, int fBrilho, int qtdThreads) {
	totalPixels = img->getHeight() * img->getWidth();
	qtdPixelsThread = (int) (totalPixels / qtdThreads) + 1;

	imagem = img;
	fatorBrilho = fBrilho;

	pthread_t *threads = new pthread_t[qtdThreads];

	for (int i = 0; i < qtdThreads; i++) {
		pthread_t thread_obj;
		pthread_create(&thread_obj, NULL, alterarBrilhoThread, (void*) i);
		threads[i] = thread_obj;
	}

	for (int i = 0; i < qtdThreads; i++) {
		pthread_join(threads[i], NULL);
	}

	return imagem;
}

void *alterarBrilhoThread(void *parameter) {
	int index = (int) parameter;
	
	int i = index * qtdPixelsThread;
	int f = i + qtdPixelsThread;

	printf("Sou a Thread %d. Vou trabalhar entre os pixels %d e %d. Fator de brilho = %d\n", index, i, i + qtdPixelsThread, fatorBrilho);

	while (i <= totalPixels && i < f) {
		int rgb = (getCorBrilho(imagem->getR(i), fatorBrilho) << 16)
			| (getCorBrilho(imagem->getG(i), fatorBrilho) << 8)
			| getCorBrilho(imagem->getB(i), fatorBrilho);
		imagem->setRGB(i, rgb);
		i++;
	}
	return (void *)0;
}

int getCorBrilho(int cor, int fatorBrilho) {
	int result = cor + fatorBrilho;

	if (result > 255) {
		return 255;
	}

	if (result < 0) {
		return 0;
	}

	return result;
}

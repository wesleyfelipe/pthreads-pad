#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>

#include "Imagem.h"

using namespace std;

Imagem *imagem;
Imagem *imagemResultado;
int qtdPixelsThread;
int totalPixels;

void *medianaThread(void *parameter);

Imagem* aplicarMediana(Imagem* img, int qtdThreads) {
	totalPixels = img->getHeight() * img->getWidth();
	qtdPixelsThread = (int) (totalPixels / qtdThreads) + 1;

	imagem = img;
	imagemResultado = new Imagem(imagem->getWidth(), imagem->getHeight());

	pthread_t *threads = new pthread_t[qtdThreads];

	for (int i = 0; i < qtdThreads; i++) {
		pthread_t thread_obj;
		pthread_create(&thread_obj, NULL, medianaThread, (void*) i);
		threads[i] = thread_obj;
	}

	for (int i = 0; i < qtdThreads; i++) {
		pthread_join(threads[i], NULL);
	}

	return imagemResultado;
}

void *medianaThread(void *parameter) {
	int index = (int) parameter;
	
	int i = index * qtdPixelsThread;
	int f = i + qtdPixelsThread;

	printf("Sou a Thread %d. Vou trabalhar entre os pixels %d e %d.\n", index, i, i + qtdPixelsThread);

	while (i < totalPixels && i < f) {
		int posy = (int)i / imagem->getWidth();
		int posx = i - posy * imagem->getWidth();

		int posx_esq = (posx - 1);
		if (posx_esq < 0) {
			posx_esq = imagem->getWidth() - 1;
		}

		int posx_dir = (posx + 1);
		if (posx_dir >= imagem->getWidth()) {
			posx_dir = 0;
		}

		int posy_up = (posy - 1);
		if (posy_up < 0) {
			posy_up = imagem->getHeight() -1;
		}

		int posy_down = (posy + 1);
		if (posy_down >= imagem->getHeight()) {
			posy_down = 0;
		}


		int v1_px = (posx_esq) + (posy_up) * imagem->getWidth();
		int v2_px = (posx) + (posy_up) * imagem->getWidth();
		int v3_px = (posx_dir) + (posy_up) * imagem->getWidth();

		int v4_px = (posx_esq) + (posy) * imagem->getWidth();
		int v5_px = i;
		int v6_px = (posx_dir) + (posy) * imagem->getWidth();

		int v7_px = (posx_esq) + (posy_down)* imagem->getWidth();
		int v8_px = (posx) + (posy_down)* imagem->getWidth();
		int v9_px = (posx_dir) + (posy_down)* imagem->getWidth();


		int r = (imagem->getR(v1_px) + imagem->getR(v2_px) + imagem->getR(v3_px) +
			imagem->getR(v4_px) + imagem->getR(v5_px) + imagem->getR(v6_px) +
			imagem->getR(v7_px) + imagem->getR(v8_px) + imagem->getR(v9_px)) / 9;

		int g = (imagem->getG(v1_px) + imagem->getG(v2_px) + imagem->getG(v3_px) +
			imagem->getG(v4_px) + imagem->getG(v5_px) + imagem->getG(v6_px) +
			imagem->getG(v7_px) + imagem->getG(v8_px) + imagem->getG(v9_px)) / 9;

		int b = (imagem->getB(v1_px) + imagem->getB(v2_px) + imagem->getB(v3_px) +
			imagem->getB(v4_px) + imagem->getB(v5_px) + imagem->getB(v6_px) +
			imagem->getB(v7_px) + imagem->getB(v8_px) + imagem->getB(v9_px)) / 9;

		int rgb = (r << 16) | (g << 8) | b;
		imagemResultado->setRGB(i, rgb);
		i++;
	}
	return (void *)0;
}


#include <windows.h>

#include <iostream>
#include <fstream>
#include <string>

#include "Imagem.h"
#include "ImageReader.h"

using namespace std;


//metodo para ler arquivos de imagem ppm p3 (modo texto)
Imagem* lerImagem(char* localImagem) {

	ifstream arq(localImagem);

	char tipo[3];
	arq.getline(tipo, 3);

	char temp[256];
	arq.getline(temp, 256);

	int w = 0;
	arq >> w;
	int h = 0;
	arq >> h;

	Imagem *image = new Imagem(w, h);
	int maxvalue;
	arq >> maxvalue;

	int r = 0;
	int g = 0;
	int b = 0;

	int rgb = 0;

	for (int y = h - 1; y >= 0; y--) {
		for (int x = w - 1; x >= 0; x--) {
			arq >> b >> g >> r;
			rgb = (r << 16) | (g << 8) | b;
			image->setRGB(x, y, rgb);
		}
	}
	arq.close();

	return image;

}
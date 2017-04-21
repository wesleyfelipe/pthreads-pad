#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

#include "FiltroBrilho.h"
#include "ImageReader.h"
#include "ImageWriter.h"
#include "Imagem.h"

using namespace std;

void executarFiltro();

int main(int argc, char** argv) {
	executarFiltro();
}

void executarFiltro() {
	Imagem* imagem = lerImagem("Imagens/baby-groot.ppm");
	imagem = alterarBrilho(imagem, -20);
	gravarImagemPPM3(imagem, "Imagens/baby-groot2.ppm");
}
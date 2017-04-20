#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

#include "FiltroBrilho.h"
#include "ImageReader.h"
#include "Imagem.h"

using namespace std;

void executarFiltro();

int main(int argc, char** argv) {
	executarFiltro();
}

void executarFiltro() {
	Imagem* imagem = lerImagem("Imagens/background.ppm");
	alterarBrilho(imagem);
}
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

#include "FiltroBrilho.h"
#include "ImageReader.h"
#include "ImageWriter.h"
#include "Imagem.h"

using namespace std;

void executarFiltro(char* nomeArquivo,  char* nomeArquivoResultado, int fBrilho, int qtdThreads);

int main(int argc, char** argv) {
	executarFiltro("Imagens/baby-groot.ppm", "Imagens/baby-groot2.ppm", 30, 5);
}

void executarFiltro(char* nomeArquivo, char* nomeArquivoResultado, int fBrilho, int qtdThreads) {
	Imagem* imagem = lerImagem(nomeArquivo);
	imagem = alterarBrilho(imagem, fBrilho, qtdThreads);
	gravarImagemPPM3(imagem, nomeArquivoResultado);
}
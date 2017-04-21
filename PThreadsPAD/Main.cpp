#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "FiltroBrilho.h"
#include "ImageReader.h"
#include "ImageWriter.h"
#include "Imagem.h"

using namespace std;

void executarFiltro(char* nomeArquivo,  char* nomeArquivoResultado, int fBrilho, int qtdThreads);

int main(int argc, char** argv) {

	printf("Iniciando programa \n");
	clock_t tStart = clock();

	executarFiltro("Imagens/baby-groot.ppm", "Imagens/baby-groot2.ppm", 30, 5);

	printf("Execução encerrada.\n");
	printf("Tempo total de execução: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
}

void executarFiltro(char* nomeArquivo, char* nomeArquivoResultado, int fBrilho, int qtdThreads) {
	Imagem* imagem = lerImagem(nomeArquivo);
	imagem = alterarBrilho(imagem, fBrilho, qtdThreads);
	gravarImagemPPM3(imagem, nomeArquivoResultado);
}
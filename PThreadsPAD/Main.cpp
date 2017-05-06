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

void executarTestesPerformance(char* nomeArquivo, int maxThreads);

int main(int argc, char** argv) {

	printf("Iniciando teste de performance. \n");

	executarTestesPerformance("Imagens/baby-groot.ppm", 3);

	printf("Teste de performance finalizado. \n");

}

void executarTestesPerformance(char* nomeArquivo, int maxThreads) {

	//for (int i = 1; i <= maxThreads; i++) {

		int i =  maxThreads;

		printf("------------------------------------ \n");
		printf("Iniciando programa. Qtd de threads: %d\n", i);
		clock_t tStart = clock();

		executarFiltro(nomeArquivo, "Imagens/resultado.ppm", -100, i);

		printf("Execucao encerrada.\n");
		printf("Tempo total de execucao: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
		printf("------------------------------------ \n");
	//}
}

void executarFiltro(char* nomeArquivo, char* nomeArquivoResultado, int fBrilho, int qtdThreads) {
	Imagem* imagem = lerImagem(nomeArquivo);
	imagem = alterarBrilho(imagem, fBrilho, qtdThreads);
	gravarImagemPPM3(imagem, nomeArquivoResultado);
}
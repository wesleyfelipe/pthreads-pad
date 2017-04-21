#include <windows.h>
#include <fstream>

#include "Imagem.h"

using namespace std;

void gravarImagemPPM3(Imagem * img, char* nomeArquivo) {
	printf("Gravando arquivo ... \n");

	ofstream outFile;

	outFile.open(nomeArquivo);
	if (!outFile)
	{
		printf("Erro ao gravar arquivo.");
		abort();
	}

	outFile << "P3" << endl;
	outFile << "#CREATOR: Filtro de brilho" << endl;
	outFile << img->getWidth() << " " << img->getHeight() << endl;
	outFile << 255 << endl;

	for (int i = (img->getHeight() * img->getWidth()) -1; i >= 0 ; i--) {
		outFile << img->getB(i) << endl;
		outFile << img->getG(i) << endl;
		outFile << img->getR(i) << endl;
	}

	outFile.close();
}
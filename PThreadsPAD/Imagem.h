//Classe Imagem
#ifndef IMAGEM_H
#define IMAGEM_H 

class Imagem {
public:

	Imagem(int width, int height) {
		this->width = width;
		this->height = height;
		pixels = new int[width * height];
	}

	~Imagem(void) {
		delete[] pixels;
	}

	void setRGB(int x, int y, int rgb) {
		pixels[x + y * width] = rgb;
	}

	int getRGB(int x, int y) {
		return pixels[x + y * width];
	}

	int getR(int pixel) {
		return pixels[pixel] >> 16;
	}

	int getG(int pixel) {
		return (pixels[pixel] >> 8) & 255;
	}

	int getB(int pixel) {
		return pixels[pixel] & 255;
	}

	int getWidth() {
		return width;
	}

	int getHeight() {
		return height;
	}

	int* getPixels() {
		return pixels;
	}

	void setPixel(int p[]) {
		pixels = p;
	}

private:
	int width, height;
	int *pixels;
};

#endif

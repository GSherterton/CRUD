#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "Produto.h"

class Perfume : public Produto{
	private:
		float volume;
		std::string fragrancia;
		std::string modelo;

	public:
		Perfume();
		Perfume(std::string marca, float preco, int codigo, float volume, std::string fragrancia, std::string modelo);

		float getVolume();
		std::string getFragrancia();
		std::string getModelo();
		void setVolume(float volume);
		void setFragrancia(std::string fragrancia);
		void setModelo(std::string modelo);

		void exibe();
		void exibeArquivo(std::ofstream& fp);
};

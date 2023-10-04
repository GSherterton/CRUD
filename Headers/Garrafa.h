#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "Produto.h"

class Garrafa : public Produto{
	private:
		float volume;
		std::string cor;
		std::string modelo;

	public:
		Garrafa();
		Garrafa(std::string marca, float preco, int codigo, float volume, std::string cor, std::string modelo);

		float getVolume();
		std::string getCor();
		std::string getModelo();
		void setVolume(float volume);
		void setCor(std::string cor);
		void setModelo(std::string modelo);

		void exibe();
		void exibeArquivo(std::ofstream& fp);
};

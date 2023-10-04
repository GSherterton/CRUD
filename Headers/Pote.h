#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "Produto.h"

class Pote : public Produto{
	private:
		std::string material;
		std::string cor;
		float volume;
		std::string modelo;

	public:
		Pote();
		Pote(std::string marca, float preco, int codigo, std::string material, std::string cor, float volume, std::string modelo);

		std::string getMaterial();
		std::string getCor();
		float getVolume();
		std::string getModelo();
		void setMaterial(std::string material);
		void setCor(std::string cor);
		void setVolume(float volume);
		void setModelo(std::string modelo);

		void exibe();
		void exibeArquivo(std::ofstream& fp);
};

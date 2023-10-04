#pragma once
#include <string>
#include <vector>
#include <iostream>

class Endereco{
	private:
		std::string rua;
		int numero;
		std::string bairro;
		std::string cidade;
		std::string estado;
		std::string cep;

	public:
		Endereco();
		Endereco(std::string rua, int numero, std::string bairro, std::string cidade, std::string estado, std::string cep);
		
		std::string getRua();
		int getNumero();
		std::string getBairro();
		std::string getCidade();
		std::string getEstado();
		std::string getCep();
		void setRua(std::string rua);
		void setNumero(int numero);
		void setBairro(std::string bairro);
		void setCidade(std::string cidade);
		void setEstado(std::string estado);
		void setCep(std::string cep);

		void exibe();
};

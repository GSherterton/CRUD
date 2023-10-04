#pragma once
#include <string>
#include <vector>
#include <iostream>

#include "Data.h"
#include "Endereco.h"

class Pessoa{
	private:
		Data dataDeNascimento;
		Endereco endereco;
		std::string nome;
		std::string telefone;
		std::string cpf;

	public:
		Pessoa();
		Pessoa(Data data, Endereco endereco, std::string nome, std::string telefone, std::string cpf);

		Data getDataDeNascimento();
		Endereco getEndereco();
		std::string getNome();
		std::string getTelefone();
		std::string getCpf();
		void setDataDeNascimento(Data data);
		void setEndereco(Endereco endereco);
		void setNome(std::string nome);
		void setTelefone(std::string telefone);
		void setCpf(std::string cpf);

		void exibe();
};

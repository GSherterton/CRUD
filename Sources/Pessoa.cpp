#include <string>
#include <vector>
#include <iostream>

#include "Pessoa.h"

using namespace std;

Pessoa::Pessoa(){}

Pessoa::Pessoa(Data data, Endereco endereco, string nome, string telefone, string cpf ){
	this->dataDeNascimento = data;
	this->endereco = endereco;
	this->nome = nome;
	this->telefone = telefone;
	this->cpf = cpf;
}

Data Pessoa::getDataDeNascimento(){
	return dataDeNascimento;
}

Endereco Pessoa::getEndereco(){
	return endereco;
}

string Pessoa::getNome(){
	return nome;
}

string Pessoa::getTelefone(){
	return telefone;
}

string Pessoa::getCpf(){
	return cpf;
}

void Pessoa::setDataDeNascimento(Data data){
	this->dataDeNascimento = data;
}

void Pessoa::setEndereco(Endereco endereco){
	this->endereco = endereco;
}

void Pessoa::setNome(string nome){
	this->nome = nome;
}

void Pessoa::setTelefone(string telefone){
	this->telefone = telefone;
}

void Pessoa::setCpf(string cpf){
	this->cpf = cpf;
}

void Pessoa::exibe(){
	cout << nome << endl;
	cout << "CPF: " << cpf << " | Telefone: " << telefone << endl;
	dataDeNascimento.exibe();
	endereco.exibe();
}

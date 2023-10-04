#include <string>
#include <vector>
#include <iostream>

#include "Endereco.h"

using namespace std;

Endereco::Endereco(){}

Endereco::Endereco(string rua, int numero, string bairro, string cidade, string estado, string cep){
	this->rua = rua;
	this->numero = numero;
	this->bairro = bairro;
	this->cidade = cidade;
	this->estado = estado;
	this->cep = cep;
}

string Endereco::getRua(){
	return rua;
}

int Endereco::getNumero(){
	return numero;
}

string Endereco::getBairro(){
	return bairro;
}

string Endereco::getCidade(){
	return cidade;
}

string Endereco::getEstado(){
	return estado;
}

string Endereco::getCep(){
	return cep;
}

void Endereco::setRua(string rua){
	this->rua = rua;
}

void Endereco::setNumero(int numero){
	this->numero = numero;
}

void Endereco::setBairro(string bairro){
	this->bairro = bairro;
}

void Endereco::setCidade(string cidade){
	this->cidade = cidade;
}

void Endereco::setEstado(string estado){
	this->estado = estado;
}

void Endereco::setCep(string cep){
	this->cep = cep;
}

void Endereco::exibe(){
	cout << rua << ", " << numero << ", " << bairro << ". "
	<< cidade << " - " << estado << ". CEP: " << cep << endl;
}

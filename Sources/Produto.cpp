#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

#include "Produto.h"

using namespace std;

Produto::Produto(){}

Produto::Produto(string marca, float preco, int codigo, int tipo){
	this->marca = marca;
	this->preco = preco;
	this->codigo = codigo;
	this->tipo = tipo;
}

string Produto::getMarca(){
	return marca;
}

float Produto::getPreco(){
	return preco;
}

int Produto::getCodigo(){
	return codigo;
}

void Produto::setMarca(string marca){
	this->marca = marca;
}

void Produto::setPreco(float preco){
	this->preco = preco;
}

void Produto::setCodigo(int codigo){
	this->codigo = codigo;
}

void Produto::exibe(){
	cout << "Produto " << codigo << "\nMarca: " << marca << " | Preco: R$" << fixed << setprecision(2) << preco << endl;
}

void Produto::exibeArquivo(ofstream& fp){
	fp << marca << endl;
	fp << preco << " " << codigo << endl;
}

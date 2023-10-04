#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

#include "Garrafa.h"

using namespace std;

Garrafa::Garrafa(){}

Garrafa::Garrafa(string marca, float preco, int codigo, float volume, string cor, string modelo) : Produto(marca, preco, codigo, 3){
	this->volume = volume;
	this->cor = cor;
	this->modelo = modelo;
}

float Garrafa::getVolume(){
	return volume;
}

string Garrafa::getCor(){
	return cor;
}

string Garrafa::getModelo(){
	return modelo;
}

void Garrafa::setVolume(float volume){
	this->volume = volume;
}

void Garrafa::setCor(string cor){
	this->cor = cor;
}

void Garrafa::setModelo(string modelo){
	this->modelo = modelo;
}

void Garrafa::exibe(){
	Produto::exibe();
	cout << "Nome: " << modelo << " | Volume: ";
	
	if(volume < 1){
		cout << fixed << setprecision(0) << volume*1000 << " mL";
	}else if(volume - ((int)volume) == 0){
		cout << fixed << setprecision(0) << volume << " L";
	}else{
		cout << fixed << setprecision(1) << volume << " L";
	}
	
	cout << "\nCor: " << cor << endl;
}

void Garrafa::exibeArquivo(ofstream& fp){
	fp << "3" << endl;
	Produto::exibeArquivo(fp);
	fp << volume << endl;
	fp << cor << endl;
	fp << modelo << endl;
}
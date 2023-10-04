#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

#include "Pote.h"

using namespace std;

Pote::Pote(){}

Pote::Pote(string marca, float preco, int codigo, string material, string cor, float volume, string modelo) : Produto(marca, preco, codigo, 2){
	this->material = material;
	this->cor = cor;
	this->volume = volume;
	this->modelo = modelo;
}

string Pote::getMaterial(){
	return material;
}

string Pote::getCor(){
	return cor;
}

float Pote::getVolume(){
	return volume;
}

string Pote::getModelo(){
	return modelo;
}

void Pote::setMaterial(string material){
	this->material = material;
}

void Pote::setCor(string cor){
	this->cor = cor;
}

void Pote::setVolume(float volume){
	this->volume = volume;
}

void Pote::setModelo(string modelo){
	this->modelo = modelo;
}

void Pote::exibe(){
	Produto::exibe();
	cout << "Nome: " << modelo << " | Volume: ";

	if(volume < 1){
		cout << fixed << setprecision(0) << volume*1000 << " mL";
	}else if(volume - ((int)volume) == 0){
		cout << fixed << setprecision(0) << volume << " L";
	}else{
		cout << fixed << setprecision(1) << volume << " L";
	}
	
	cout << "\nCor: " << cor << " | Material: " << material << endl;
}

void Pote::exibeArquivo(ofstream& fp){
	fp << "2" << endl;
	Produto::exibeArquivo(fp);
	fp << volume << endl;
	fp << cor << endl;
	fp << material << endl;
	fp << modelo << endl;
}

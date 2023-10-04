#include <string>
#include <vector>
#include <iostream>

#include "Perfume.h"

using namespace std;

Perfume::Perfume(){}

Perfume::Perfume(string marca, float preco, int codigo, float volume, string fragrancia, string modelo) : Produto(marca, preco, codigo, 1){
	this->volume = volume;
	this->fragrancia = fragrancia;
	this->modelo = modelo;
}

float Perfume::getVolume(){
	return volume;
}

string Perfume::getFragrancia(){
	return fragrancia;
}

string Perfume::getModelo(){
	return modelo;
}

void Perfume::setVolume(float volume){
	this->volume = volume;
}

void Perfume::setFragrancia(string fragrancia){
	this->fragrancia = fragrancia;
}

void Perfume::setModelo(string modelo){
	this->modelo = modelo;
}

void Perfume::exibe(){
	Produto::exibe();
	cout << "Nome: " << modelo << " | Volume: " << (int)volume << " mL\nFragrancia: " << fragrancia << endl;
}

void Perfume::exibeArquivo(ofstream& fp){
	fp << "1" << endl;
	Produto::exibeArquivo(fp);
	fp << volume << endl;
	fp << fragrancia << endl;
	fp << modelo << endl;
}
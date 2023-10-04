#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>

#include "Data.h"

using namespace std;

Data::Data(){}

Data::Data(int dia, int mes, int ano){
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
}

int Data::getDia(){
	return dia;
}

int Data::getMes(){
	return mes;
}

int Data::getAno(){
	return ano;
}

void Data::setDia(int dia){
	this->dia = dia;
}

void Data::setMes(int mes){
	this->mes = mes;
}

void Data::setAno(int ano){
	this->ano = ano;
}

void Data::exibe(){
	printf("%02d/%02d/%d\n", dia, mes, ano);
}

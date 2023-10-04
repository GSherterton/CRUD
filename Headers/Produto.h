#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class Produto{
	protected:
		std::string marca;		/*--------------------------*/  
		float preco;			/*	identificação do tipo	*/
		int codigo;				/*	1- Perfume				*/
		int tipo;				/*	2- Pote					*/
								/*	3- Garrafa				*/
								/*--------------------------*/

	public:
		Produto();
		Produto(std::string marca, float preco, int codigo, int tipo);

		std::string getMarca();
		float getPreco();
		int getCodigo();
		void setMarca(std::string marca);
		void setPreco(float preco);
		void setCodigo(int codigo);

		virtual void exibe();
		virtual void exibeArquivo(std::ofstream& fp);
};

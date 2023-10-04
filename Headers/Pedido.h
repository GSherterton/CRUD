#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "Produto.h"

class Pedido{
	private:
		int numero;
		std::vector<Produto*> produto;
		std::vector<int> qtdComprada;
		float valorTotal;

	public:
		Pedido();
		Pedido(int numero);

		int getQuantidadeDeProdutos();

		void clearTerminal();
		int size();
		float adicionarProduto(Produto* prod, int quantidade);
		float removerProduto(int codigo);
		float alterarProduto(int codigo, int quantidade);
		void listarProdutos();
		int selecionarProduto();
		int procurarProduto();

		int getNumero();
		float getValorTotal();
		void setNumero(int numero);
		void setValorTotal(float valor);

		void exibe();
		void exibeArquivo(std::ofstream& fp);
};

#pragma once
#include <string>
#include <vector>
#include <iostream>

#include "Pedido.h"
#include "Pessoa.h"
#include "Pote.h"
#include "Garrafa.h"
#include "Perfume.h"

class Cliente : public Pessoa{
	private:
		float debito;
		std::vector<Pedido> pedido;

	public:
		Cliente();
		Cliente(Data data, Endereco endereco, std::string nome, std::string telefone, std::string cpf);

		void clearTerminal();
		void easterEgg();

		float getDebito();
		void setDebito(float debito);
		void pagar(float valor);
		int getQuantidadeDePedidos();
		int getQuantidadeDeProdutos();
		
		Produto* lerPerfume();
		Produto* lerPote();
		Produto* lerGarrafa();

		void escolhaProduto(int codigo);

		Pedido* procuraPedido(int index);
		void menuPedido();
		int escolhaTipo();
		void abrirPedido();
		void adicionarProdutoNoPedido(Produto* produto, int quantidade);
		void alterarUltimoPedido();
		void listarPedidos();
};

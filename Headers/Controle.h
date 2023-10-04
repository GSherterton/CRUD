#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

#include "Pessoa.h"
#include "Pote.h"
#include "Perfume.h"
#include "Garrafa.h"
#include "Pedido.h"
#include "Cliente.h"
#include "Estoque.h"

class Controle{
    private:
        std::vector<Cliente> cliente;

    public:
        Controle();

        void clearTerminal();
        void easterEgg();

        void carregarClientes();
        //void carregarEstoque();//vai ficar pra proxima versao
        void salvarClientes();

        Data lerDataDeNascimento();
        Endereco lerEndereco();
        Cliente lerCliente();

        void cadastrarCliente();

        void alterarCliente(Cliente* auxCliente);
        void removerCliente(Cliente* auxCliente);
        void listarClientes();
        Cliente* selecionarCliente();
        Cliente* procurarCliente();

        void escolhaCliente(Cliente* auxCliente);

        float debitoTotal();
        int quantidadePedido();
        int quantidadeProdutos();

        void relatorioGeral();

        void clientes();
        //void estoque();
        //void relatorios();

        void inicio();        
};

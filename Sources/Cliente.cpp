#include <string>
#include <vector>
#include <iostream>

#ifdef _WIN32
#define WINDOWS_SYSTEM
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "Cliente.h"

using namespace std;

Cliente::Cliente(){
	debito = 0;
}

Cliente::Cliente(Data data, Endereco endereco, string nome, string telefone, string cpf) : Pessoa(data, endereco, nome, telefone, cpf){
	debito = 0;
}

void Cliente::clearTerminal(){
    #ifdef WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Cliente::easterEgg(){
    clearTerminal();
    cout << ".............................                                                             ..............................\n"
            "......................                                                                           .......................\n"
            ".................                                                                                     ..................\n"
            ".............                                                                                             ..............\n"
            "..........                                                                                                   ...........\n"
            ".......                                                                                                         ........\n"
            ".....                     .:::::::.                                                                               ......\n"
            "....                   ..               .      .!!                                                                 .....\n"
            "...                     ..                     !#!     :.. .... .. . . .       .      .:    ..                      ....\n"
            "..                          .:::!:             !#.                            .  .!!!##!   ..                        ...\n"
            "..                              .:        ##: .#: :#::#    .##:   :#        .#:    !##:   !#.                        ...\n"
            "...                              .         :#!#: .!#!.!!!##!:.#:.:#. :.###:  ###!!. ##!#. .###!:                     ...\n"
            "...                          .                               #!                                                     ....\n"
            "....                                                       .!.                                                     .....\n"
            "......                                                                                                           .......\n"
            "........                                                                                                       .........\n"
            "...........                                                                                                  ...........\n"
            "..............                                                                                           ...............\n"
            "..................                                                                                    ..................\n"
            "........................                                                                       .........................\n"
            "..............................                                                           ...............................\n" << endl;
    #ifdef WINDOWS_SYSTEM
    Sleep( 700 );
    #else
    usleep( 500000 );
    #endif

    clearTerminal();
}

float Cliente::getDebito(){
	return debito;
}

void Cliente::setDebito(float debito){
	this->debito = debito;
}

void Cliente::pagar(float valor){
	this->debito -= valor;	
}

int Cliente::getQuantidadeDePedidos(){
    return pedido.size();
}

int Cliente::getQuantidadeDeProdutos(){
    int valor = 0;

    for(int i = 0; i < pedido.size(); i++){
        valor += pedido[i].getQuantidadeDeProdutos();
    }

    return valor;
}

Produto* Cliente::lerPerfume(){
    Produto *produto;

    //aux
    string marca, fragrancia, modelo;
    float preco, volume;
    int codigo;

    cout << "Digite a marca: ";
    getline(cin, marca);
    cout << "Digite o preco: ";
    cin >> preco;
    cout << "Digite o codigo: ";
    cin >> codigo;
    cout << "Digite o volume: ";
    cin >> volume;
    cin.ignore();
    cout << "Digite a fragrancia: ";
    getline(cin, fragrancia);
    cout << "Digite o nome: ";
    getline(cin, modelo);

    produto = new Perfume(marca, preco, codigo, volume, fragrancia, modelo);

    return produto;
}

Produto* Cliente::lerPote(){
    Produto *produto;

    //aux
    string marca, material, cor, modelo;
    float preco, volume;
    int codigo;

    cout << "Digite a marca: ";
    getline(cin, marca);
    cout << "Digite o preco: ";
    cin >> preco;
    cout << "Digite o codigo: ";
    cin >> codigo;
    cin.ignore();
    cout << "Digite o material: ";
    getline(cin, material);
    cout << "Digite a cor: ";
    getline(cin, cor);
    cout << "Digite o volume: ";
    cin >> volume;
    cin.ignore();
    cout << "Digite o nome: ";
    getline(cin, modelo);

    produto = new Pote(marca, preco, codigo, material, cor, volume, modelo);

    return produto;
}

Produto* Cliente::lerGarrafa(){
    Produto *produto;

    //aux
    string marca, cor, modelo;
    float preco, volume;
    int codigo;

    cout << "Digite a marca: ";
    getline(cin, marca);
    cout << "Digite o preco: ";
    cin >> preco;
    cout << "Digite o codigo: ";
    cin >> codigo;
    cout << "Digite o volume: ";
    cin >> volume;
    cin.ignore();
    cout << "Digite a cor: ";
    getline(cin, cor);
    cout << "Digite o nome: ";
    getline(cin, modelo);

    produto = new Garrafa(marca, preco, codigo, volume, cor, modelo);

    return produto;
}

void Cliente::escolhaProduto(int codigo){
	int num, quantidade;

    if(codigo == 0){
        return;
    }

    clearTerminal();
    while(1){
        cout << "Escolha uma opcao:\n"
                "1- Alterar Produto\n"
                "2- Remover Produto\n"
                "3- Sair\n\n";
        
        cin >> num;
        cin.ignore();

        clearTerminal();

        switch(num){
            case 1:
				cout << "Digite a nova quantidade que deseja: ";
				cin >> quantidade;

				debito += pedido[pedido.size()-1].alterarProduto(codigo, quantidade);

                return;
            case 2:
				debito += pedido[pedido.size()-1].removerProduto(codigo);
            
                return;
            case 3:
                return;
            default:
                cout << "Opcao Invalida!\n\n";
        }
    }
}

Pedido* Cliente::procuraPedido(int index){
	return &pedido[index];
}

void Cliente::menuPedido(){
	cout << "Opcoes:\n"
			"1- Adicionar Produto\n"
			"2- Listar Produtos\n"
			"3- Selecionar Produto\n"
			"4- Procurar Produto\n"
			"5- Sair\n\n";
}

int Cliente::escolhaTipo(){
	int tipo;

	while(1){
		cout << "Qual tipo de produto voce deseja adicionar?\n"
				"1- Perfume    2- Pote    3- Garrafa    4- Sair\n";

		cin >> tipo;
		cin.ignore();
        clearTerminal();

		if(tipo == 1 || tipo == 2 || tipo == 3 || tipo == 4){
			return tipo;
		}else{
			cout << "Tipo nao encontrado!\n";
		}
	}

	return -1;
}

void Cliente::abrirPedido(){
	pedido.push_back(Pedido(pedido.size()+1));
}

void Cliente::adicionarProdutoNoPedido(Produto* produto, int quantidade){
	pedido[pedido.size()-1].adicionarProduto(produto, quantidade);
}

void Cliente::alterarUltimoPedido(){
	int num, quantidade, codigo, tipo;
	Produto *produto;

	while(1){
		menuPedido();

		cin >> num;
        easterEgg();
		clearTerminal();

		switch(num){
			case 1://Adicionar Produto
                tipo = escolhaTipo();

                if(tipo == 4){
                    break;
                }

				switch(tipo){
					case 1:
						produto = lerPerfume();
                        clearTerminal();

						break;
					case 2:
						produto = lerPote();
                        clearTerminal();

						break;
					case 3:
						produto = lerGarrafa();
                        clearTerminal();

						break;
				} 
				
				cout << "Quantas unidades desse produto voce deseja adicionar?\n";
				cin >> quantidade;
				debito += pedido[pedido.size()-1].adicionarProduto(produto, quantidade);

				break;
			case 2://Listar Produtos
				pedido[pedido.size()-1].listarProdutos();//ate aqui ta ok

				break;
			case 3://Selecionar Produto
				escolhaProduto(pedido[pedido.size()-1].selecionarProduto());//depois altera ou remove
				break;
			case 4://Procurar Produto
				escolhaProduto(pedido[pedido.size()-1].procurarProduto());
				break;
			case 5://Sair
				return;
			default:
				cout << "Opcao Invalida!\n\n";
		}
	}
}

void Cliente::listarPedidos(){
    if(pedido.size() == 0){
		cout << "Nao ha pedidos abertos!\n\n";
		return;
	}

	int index = 0;
	char escolha;

	while(1){
        clearTerminal();
        pedido[index].exibe();

        if(index == 0 && index == pedido.size()-1){
            while(1){
                cout << "0- Sair\t\t\t\t\t(  )\n";

                cin >> escolha;

                if(escolha == '0'){
                    break;
                }else{
                    clearTerminal();
                    pedido[index].exibe();
                }
            }
        }else if(index == 0){
            while(1){
                cout << "0- Sair\t\t\t\t\t( >)\n";

                cin >> escolha;

                if(escolha == '>'){
                    index++;
                    break;
                }else if(escolha == '0'){
                    break;
                }else{
                    clearTerminal();
                    pedido[index].exibe();
                }
            }
        }else if(index == pedido.size()-1){
            while(1){
                cout << "0- Sair\t\t\t\t(< )\n";

                cin >> escolha;

                if(escolha == '<'){
                    index--;
                    break;
                }else if(escolha == '0'){
                    break;
                }else{
                    clearTerminal();
                    pedido[index].exibe();
                }
            }
        }else{
            while(1){
                cout << "0- Sair\t\t\t\t\t(<>)\n";
                
                cin >> escolha;

                if(escolha == '<'){
                    index--;
                    break;
                }else if(escolha == '>'){
                    index++;
                    break;
                }else if(escolha == '0'){
                    break;
                }
            }
        }
        if(escolha == '0'){
            break;
        }
    }
    clearTerminal();
}

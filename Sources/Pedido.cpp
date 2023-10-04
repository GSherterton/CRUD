#include <string>
#include <vector>
#include <iostream>

#include "Pedido.h"

using namespace std;

Pedido::Pedido(){}

Pedido::Pedido(int numero){
	this->numero = numero;
	valorTotal = 0;
}

int Pedido::getQuantidadeDeProdutos(){
	int valor = 0;

	for(int i = 0; i < qtdComprada.size(); i++){
		valor += qtdComprada[i];
	}

	return valor;
}

void Pedido::clearTerminal(){
	#ifdef WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

int Pedido::size(){
	return produto.size();
}

float Pedido::adicionarProduto(Produto* prod, int quantidade){
	float saldo;

	for(int i = 0; i < produto.size(); i++){
		if(prod->getCodigo() == produto[i]->getCodigo()){
			qtdComprada[i] += quantidade;
			valorTotal += (quantidade * prod->getPreco());

			saldo = (quantidade * prod->getPreco());
			return saldo;
		}
	}

	produto.push_back(prod);
	qtdComprada.push_back(quantidade);
	valorTotal += (quantidade * prod->getPreco());

	saldo = (quantidade * prod->getPreco());
	return saldo;
}

float Pedido::removerProduto(int codigo){
	float saldo;

	for(int i = 0; i < produto.size(); i++){
		if(codigo == produto[i]->getCodigo()){
			valorTotal -= (qtdComprada[i] * produto[i]->getPreco());
			saldo = (qtdComprada[i] * produto[i]->getPreco());

			if(produto[i] != NULL){
				delete produto[i];
			}
			
			produto.erase(produto.begin()+i);
			qtdComprada.erase(qtdComprada.begin()+i);

			return saldo;
		}
	}

	clearTerminal();
	cout << "Produto nao encontrado\n";
	
	return 0;
}

float Pedido::alterarProduto(int codigo, int quantidade){
	float saldo;

	if(quantidade == 0){
		removerProduto(codigo);
	}

	for(int i = 0; i < produto.size(); i++){
		if(codigo == produto[i]->getCodigo()){
			valorTotal -= ((qtdComprada[i]-quantidade) * produto[i]->getPreco());
			saldo = ((qtdComprada[i]-quantidade) * produto[i]->getPreco());

			qtdComprada[i] = quantidade;

			return saldo;
		}
	}

	clearTerminal();
	cout << "Produto nao encontrado\n";
	return 0;
}

void Pedido::listarProdutos(){
	if(produto.size() == 0){
		cout << "Nao ha produtos disponiveis!\n\n";
		return;
	}

    for(int i = 0; i < produto.size(); i++){
        produto[i]->exibe();
        cout << endl;
    }
}

int Pedido::selecionarProduto(){
	if(produto.size() == 0){
		cout << "Nao ha produtos disponiveis!\n\n";
		return 0;
	}

	int index = 0;
	char escolha;

	while(1){
        clearTerminal();
        produto[index]->exibe();

        if(index == 0 && index == produto.size()-1){
            while(1){
                cout << "\n0- Sair\t1- Escolher\t\t\t(  )\n";

                cin >> escolha;

                if(escolha == '0'){
                    break;
                }else if(escolha == '1'){
                    return produto[index]->getCodigo();
                }else{
                    clearTerminal();
                    produto[index]->exibe();
                }
            }
        }else if(index == 0){
            while(1){
                cout << "\n0- Sair\t1- Escolher\t\t\t( >)\n";

                cin >> escolha;

                if(escolha == '>'){
                    index++;
                    break;
                }else if(escolha == '0'){
                    break;
                }else if(escolha == '1'){
					return produto[index]->getCodigo();
                }else{
                    clearTerminal();
                    produto[index]->exibe();
                }
            }
        }else if(index == produto.size()-1){
            while(1){
                cout << "\n0- Sair\t1- Escolher\t\t\t(< )\n";

                cin >> escolha;

                if(escolha == '<'){
                    index--;
                    break;
                }else if(escolha == '0'){
                    break;
                }else if(escolha == '1'){
                    return produto[index]->getCodigo();
                }else{
                    clearTerminal();
                    produto[index]->exibe();
                }
            }
        }else{
            while(1){
                cout << "\n0- Sair\t1- Escolher\t\t\t(<>)\n";
                
                cin >> escolha;

                if(escolha == '<'){
                    index--;
                    break;
                }else if(escolha == '>'){
                    index++;
                    break;
                }else if(escolha == '0'){
                    break;
                }else if(escolha == '1'){
                    return produto[index]->getCodigo();
                }
            }
        }
        if(escolha == '0'){
            break;
        }
    }
    clearTerminal();

    return 0;
}

int Pedido::procurarProduto(){//estou procurando apenas pelo codigo
	if(produto.size() == 0){
		cout << "Nao ha produtos disponiveis!\n\n";
		return 0;
	}
    
    int codigo;
    int escolha;
	bool achou;

    while(1){
		clearTerminal();
		achou = 0;
        cout << "Digite o nome do produto que deseja procurar: ";
        cin >> codigo;

        for(int i = 0; i < produto.size(); i++){
            if(produto[i]->getCodigo() == codigo){
                produto[i]->exibe();
				codigo = produto[i]->getCodigo();
				achou = 1;
				break;
            }
        }

		if(!achou){
			cout << "Nenhum produto encontrado com esse codigo\n";
		}else{
			cout << "\nO produto desejado eh esse? (0- Nao | 1- Sim)\n";

			cin >> escolha;
			if(escolha == 1){
				return codigo;
			}
		}

        cout << "Deseja procurar de novo? (0- Nao | 1- Sim)\n";
        cin >> escolha;
        cin.ignore();

        if(escolha == 0){
            clearTerminal();
            return 0;
        }
    }
}

int Pedido::getNumero(){
	return numero;
}

float Pedido::getValorTotal(){
	return valorTotal;
}

void Pedido::setNumero(int numero){

}

void Pedido::setValorTotal(float valor){
	this->valorTotal = valor;
}

void Pedido::exibe(){
	for(int i = 0; i < produto.size(); i++){
		produto[i]->exibe();
		cout << "Quantidade Comprada: " << qtdComprada[i] << endl;
		cout << endl;
	}
	
}

void Pedido::exibeArquivo(ofstream& fp){
	for(int i = 0; i < produto.size(); i++){
		produto[i]->exibeArquivo(fp);
		fp << qtdComprada[i] << endl;
	}
}
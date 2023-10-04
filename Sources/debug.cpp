#include "Controle.h"
#include "Cliente.h"

using namespace std;

/*--------------------------/
/	identificação do tipo	/
/	1- Perfume				/
/	2- Pote					/
/	3- Garrafa				/
/--------------------------*/

//como ler sem dar enter
//conio.h (windows) -> getch | kbhit
//getch (windows) -> procurar no stackoverflow

//adicionar easteregg do jequiti



//system("clear");//limpar terminal no linux
//system("cls");//limpar terminal no Windows


int main(){
    Controle controle;

    controle.clearTerminal();
    controle.carregarClientes();
    cout << "Bem vindo(a) ao PGR\n\n";//Programa de Gestao de Revendas

    controle.inicio();
    

    controle.salvarClientes();

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------//

//debug de Pessoa, Endereco e data
    /*Pessoa pessoa;
    Data data = Data(8, 3, 2004);
    Endereco endereco = Endereco("Rua Joao Cabral de Lucena", 305, "bessa", "Joao Pessoa", "Paraiba", "58020-81");

    data.exibe();
    endereco.exibe();
    pessoa = Pessoa(data, endereco, "Gabriel Sherterton Araujo de Freitas", "(83) 98742-7393", "106.094.654-81");
    pessoa.exibe();*/

//---------------------------------------------------------------------------------------------------------------------//

//debug de Produto, perfume, pote e garrafa
    /*Produto *produto;
    //Perfume perfume;
    //Pote pote;
    //Garrafa garrafa;

    //produto = Produto("Tupperware", 18.50, 1009);
    //produto.exibe();

    produto = new Perfume("Boticario", 197.99, 1001, 200, "amadeirado", "Malbec");
    produto->exibe();
    cout << endl;

    produto = new Pote("Tupperware", 39.99, 1003, "plastico", "vermelho", 0.25, "vasilhame");
    produto->exibe();
    cout << endl;

    produto = new Garrafa("Tupperware", 39.99, 1007, 1.5, "vermelha", "freezer");
    produto->exibe();
    cout << endl;*/

//---------------------------------------------------------------------------------------------------------------------//

//debug do Pedido
    /*Pedido pedido;
    pedido = Pedido(1);

    Produto *produto;
    string marca, fragrancia, modelo;
    float preco, volume;
    int codigo, quantidade;

    int num = 1;

    while(num){
        cin >> num;

        switch(num){
            case 1://adicionarProduto
                cin.ignore();
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
                cout << "Digite o modelo: ";
                getline(cin, modelo);
                cout << "Digite a quantidade: ";
                cin >> quantidade;

                produto = new Perfume(marca, preco, codigo, volume, fragrancia, modelo);

                pedido.adicionarProduto(produto, quantidade);

                break;
            case 2://removerProduto
                cout << "Digite o codigo: ";
                cin >> codigo;

                pedido.removerProduto(codigo);

                break;
            case 3://alterarProduto
                cout << "Digite o codigo: ";
                cin >> codigo;
                cout << "Digite a quantidade: ";
                cin >> quantidade;

                pedido.alterarProduto(codigo, quantidade);

                break;
        }

        cout << "\nPedidos:\n";
        pedido.exibe();
    }*/

//---------------------------------------------------------------------------------------------------------------------//

//debug de Cliente
    /*Data data = Data(8, 3, 2004);
    Endereco endereco = Endereco("Rua Joao Cabral de Lucena", 305, "bessa", "Joao Pessoa", "Paraiba", "58020-81");

    Cliente cliente;
    cliente = Cliente(data, endereco, "Gabriel Sherterton Araujo de Freitas", "(83) 98742-7393", "106.094.654-81");
    
    cliente.abrirPedido();*/

//---------------------------------------------------------------------------------------------------------------------//
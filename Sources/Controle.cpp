#include <string>
#include <vector>
#include <iostream>

#ifdef _WIN32
#define WINDOWS_SYSTEM
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "Controle.h"

using namespace std;

Controle::Controle(){}

void Controle::clearTerminal(){
    #ifdef WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Controle::easterEgg(){
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

void Controle::carregarClientes(){
    int contador = 0;
    ifstream fp;
    Cliente auxCliente;
    int i = 0, j = 0;

    //aux de pessoa
    Data data;
    Endereco endereco;
    int dia, mes, ano, numero;
    string rua, bairro, cidade, estado, cep;
    string nome, telefone, cpf;
    float debito;

    //aux de pedidos e produtos
    char simbolo;
    int tipo, codigo, quantidade;
    string marca, material, cor, modelo, fragrancia;
    float preco, volume;
    Produto *produto;
    
    fp.open("clientes.txt");

    if(!fp.is_open()){
        cout << "Nao foi possivel abrir o arquivo \n";
        return;
    }

    while(1){//ler cada pessoa
        contador = 0;
        getline(fp, nome);

        if(fp.eof()){
            break;
        }

        getline(fp, telefone);
        getline(fp, cpf);
        fp >> dia;
        fp >> mes;
        fp >> ano;
        fp.ignore();
        getline(fp, rua);
        fp >> numero;
        fp.ignore();
        getline(fp, bairro);
        getline(fp, cidade);
        getline(fp, estado);
        getline(fp, cep);
        fp >> debito;

        data = Data(dia, mes, ano);
        endereco = Endereco(rua, numero, bairro, cidade, estado, cep);
        auxCliente = Cliente(data, endereco, nome, telefone, cpf);

        cliente.push_back(auxCliente);
        cliente[i].setDebito(debito);

        while(1){//ler cada produto e pedido
            fp >> simbolo;

            //cout << endl << "Simbolo: " << simbolo << endl;

            if(simbolo == '/'){
                fp.ignore();
                j = 0;
                break;
            }else if(j == 0 && contador == 0){
                cliente[i].abrirPedido();
                tipo = simbolo - '0';
            }else if(simbolo == '-'){
                cliente[i].abrirPedido();
                j++;
                fp >> tipo;
            }else{
                tipo = simbolo - '0';
            }

            //cout << endl << "Tipo: " << tipo << endl;

            fp.ignore();
            getline(fp, marca);
            fp >> preco;
            fp >> codigo;

            switch(tipo){
                case 1://perfume
                    fp >> volume;
                    fp.ignore();
                    getline(fp, fragrancia);
                    getline(fp, modelo);

                    produto = new Perfume(marca, preco, codigo, volume, fragrancia, modelo);
                    break;
                case 2://pote
                    fp >> volume;
                    fp.ignore();
                    getline(fp, cor);
                    getline(fp, material);
                    getline(fp, modelo);

                    produto = new Pote(marca, preco, codigo, material, cor, volume, modelo);
                    break;
                case 3://garrafa
                    fp >> volume;
                    fp.ignore();
                    getline(fp, cor);
                    getline(fp, modelo);

                    produto = new Garrafa(marca, preco, codigo, volume, cor, modelo);
                    break;
            }
            
            fp >> quantidade;

            cliente[i].adicionarProdutoNoPedido(produto, quantidade);
            contador++;
        }

        //identificacao de pedidos no arquivo
        //  '-' significa que acabou um pedido
        //  '/' significa que acabou todos os pedidos

        //ler os pedidos ate que ache um '/'
        i++;
    }

    fp.close();

    cout << "Clientes carregados com sucesso\n";
}

//void Controle::carregarEstoque(){}

void Controle::salvarClientes(){
    ofstream fp;
    Cliente auxCliente;

    //aux de pessoa
    Data data;
    Endereco endereco;
    int dia, mes, ano, numero;
    string rua, bairro, cidade, estado, cep;
    string nome, telefone, cpf;
    float debito;

    fp.open("clientes.txt");

    if(!fp.is_open()){
        cout << "Nao foi possivel abrir o arquivo \n";
        return;
    }

    for(int i = 0; i < cliente.size(); i++){
        fp << cliente[i].getNome() << endl;
        fp << cliente[i].getTelefone() << endl;
        fp << cliente[i].getCpf() << endl;

        data = cliente[i].getDataDeNascimento();
        endereco = cliente[i].getEndereco();

        fp << data.getDia() << " " << data.getMes() << " " << data.getAno() << endl;

        fp << endereco.getRua() << endl;
        fp << endereco.getNumero() << endl;
        fp << endereco.getBairro() << endl;
        fp << endereco.getCidade() << endl;
        fp << endereco.getEstado() <<  endl;
        fp << endereco.getCep() << endl;
        fp << cliente[i].getDebito() << endl;

        for(int j = 0; j < cliente[i].getQuantidadeDePedidos(); j++){
            if(j != 0){
                fp << "-" << endl;
            }
            (cliente[i].procuraPedido(j))->exibeArquivo(fp);
        }
        fp << "/" << endl;
    }
}

Data Controle::lerDataDeNascimento(){
    Data data;

    int dia, mes, ano;

    cout << "Data de Nascimento: ";
    cin >> dia >> mes >> ano;
    cin.ignore();

    data = Data(dia, mes, ano);

    return data;
}

Endereco Controle::lerEndereco(){
    Endereco endereco;

    string rua;
    int numero;
    string bairro, cidade, estado, cep;

    cout << "Endereco\n";

    cout << "Rua: ";
    getline(cin, rua);
    cout << "Numero: ";
    cin >> numero;
    cin.ignore();
    cout << "Bairro: ";
    getline(cin, bairro);
    cout << "Cidade: ";
    getline(cin, cidade);
    cout << "Estado: ";
    getline(cin, estado);
    cout << "CEP: ";
    getline(cin, cep);

    endereco = Endereco(rua, numero, bairro, cidade, estado, cep);

    return endereco;
}

Cliente Controle::lerCliente(){
    Cliente cliente;
    string nome, telefone, cpf;//auxiliares

    cout << "Preencha as informacoes do cliente:\n";

    cout << "Nome: ";
    getline(cin, nome);
    cout << "Telefone: ";
    getline(cin, telefone);
    cout << "CPF: ";
    getline(cin, cpf);

    Data data = lerDataDeNascimento();
    Endereco endereco = lerEndereco();

    cliente = Cliente(data, endereco, nome, telefone, cpf);

    clearTerminal();

    return cliente;
}

void Controle::cadastrarCliente(){
    cliente.push_back(lerCliente());
}

void Controle::alterarCliente(Cliente* auxCliente){
    int num;

    //auxiliares
    string nome;
    string cpf;
    string telefone;
    Data data;
    int dia, mes, ano;

    while(1){
        cout << "Escolha um campo que deseja alterar:\n"
                "1- Nome\n"
                "2- CPF\n"
                "3- Telefone\n"
                "4- Data de Nascimento\n"
                "5- Endereco\n"
                "6- Sair\n\n";

        cin >> num;
        cin.ignore();

        clearTerminal();

        switch(num){
            case 1:
                cout << "Digite o nome: ";
                getline(cin, nome);

                auxCliente->setNome(nome);
                clearTerminal();

                break;
            case 2:
                cout << "Digite o CPF: ";
                getline(cin, cpf);

                auxCliente->setCpf(cpf);
                clearTerminal();

                break;
            case 3:
                cout << "Digite o telefone: ";
                getline(cin, telefone);

                auxCliente->setTelefone(telefone);
                clearTerminal();
                
                break;
            case 4:
                auxCliente->setDataDeNascimento(lerDataDeNascimento());
                clearTerminal();

                break;
            case 5:
                auxCliente->setEndereco(lerEndereco());
                clearTerminal();

                break;
            case 6:
                return;
            default:
                cout << "Opcao Invalida!\n\n";
        }

    }
}

void Controle::removerCliente(Cliente* auxCliente){
    int i;

    for(i = 0; i < cliente.size(); i++){
        if(auxCliente == &cliente[i]){
            break;
        }
    }

    cliente.erase(cliente.begin()+ i);
}

void Controle::listarClientes(){
    if(cliente.size() == 0 ){
        cout << "Nao ha clientes disponiveis!\n\n";
        return;
    }

    for(int i = 0; i < cliente.size(); i++){
        cliente[i].exibe();
        cout << endl;
    }
}

Cliente* Controle::selecionarCliente(){
    if(cliente.size() == 0){
        cout << "Nao ha clientes disponiveis!\n\n";
        return NULL;
    }

    int index = 0;
    char escolha;

    while(1){
        clearTerminal();
        cliente[index].exibe();

        if(index == 0 && index == cliente.size()-1){
            while(1){
                cout << "\n0- Sair\t1- Escolher\t\t\t(  )\n";

                cin >> escolha;

                if(escolha == '0'){
                    break;
                }else if(escolha == '1'){
                    return &cliente[index];
                }else{
                    clearTerminal();
                    cliente[index].exibe();
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
                    return &cliente[index];
                }else{
                    clearTerminal();
                    cliente[index].exibe();
                }
            }
        }else if(index == cliente.size()-1){
            while(1){
                cout << "\n0- Sair | 1- Escolher\t\t\t(< )\n";

                cin >> escolha;

                if(escolha == '<'){
                    index--;
                    break;
                }else if(escolha == '0'){
                    break;
                }else if(escolha == '1'){
                    return &cliente[index];
                }else{
                    clearTerminal();
                    cliente[index].exibe();
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
                    return &cliente[index];
                }
            }
        }
        if(escolha == '0'){
            break;
        }
    }
    clearTerminal();

    return NULL;
}

Cliente* Controle::procurarCliente(){
    if(cliente.size() == 0){
        cout << "Nao ha clientes disponiveis!\n\n";
        return NULL;
    }
    
    string nome;
    int contador = 0;
    Cliente* pessoa;
    int escolha;

    while(1){
        clearTerminal();
        cout << "Digite o nome do cliente que deseja procurar: ";
        getline(cin, nome);

        contador = 0;
        for(int i = 0; i < cliente.size(); i++){
            if((cliente[i].getNome()).find(nome) != string::npos){
                contador++;
                pessoa = &cliente[i];
            }
        }

        if(contador == 1){
            pessoa->exibe();

            cout << "\nO cliente desejado eh esse? (0- Nao | 1- Sim)\n";

            cin >> escolha;

            if(escolha == 1){
                return pessoa;
            }
        }

        if(contador == 0){
            cout << "Nenhuma pessoa encontrada com esse nome\n";
        }else if(contador > 1){
            cout << "Mais de uma pessoa encontrada com esse nome\n";
        }

        cout << "Deseja procurar de novo? (0- Nao | 1- Sim)\n";
        cin >> escolha;
        cin.ignore();

        if(escolha == 0){
            clearTerminal();
            return NULL;
        }
    }
}

void Controle::escolhaCliente(Cliente* auxCliente){
    int num;

    if(auxCliente == NULL){
        return;
    }

    clearTerminal();
    while(1){
        cout << "Escolha uma opcao:\n"
                "1- Alterar Cliente\n"
                "2- Remover Cliente\n"
                "3- Abrir Pedido\n"
                "4- Alterar Ultimo Pedido\n"
                "5- Listar Pedidos\n"
                "6- Sair\n\n";
        
        cin >> num;
        cin.ignore();

        clearTerminal();

        switch(num){
            case 1:
                alterarCliente(auxCliente);
                
                break;
            case 2:
                removerCliente(auxCliente);
            
                break;
            case 3:
                auxCliente->abrirPedido();
                auxCliente->alterarUltimoPedido();

                break;
            case 4:
                auxCliente->alterarUltimoPedido();

                break;
            case 5:
                auxCliente->listarPedidos();

                break;
            case 6:
                return;
            default:
                cout << "Opcao Invalida!\n\n";
        }
    }

}

float Controle::debitoTotal(){
    float valor = 0;

    for(int i = 0; i < cliente.size(); i++){
        valor += cliente[i].getDebito();
    }

    return valor;
}

int Controle::quantidadePedido(){
    int valor = 0;

    for(int i = 0; i < cliente.size(); i++){
        valor += cliente[i].getQuantidadeDePedidos();
    }

    return valor;
}

int Controle::quantidadeProdutos(){
    int valor = 0;

    for(int i = 0; i < cliente.size(); i++){
        valor += cliente[i].getQuantidadeDeProdutos();
    }

    return valor;
}

void Controle::relatorioGeral(){
    cout << "Quantidade de clientes cadastrados: " << cliente.size() << endl;
    cout << "Valor total dos pedidos: R$" << debitoTotal() << endl;
    cout << "Quantidade de pedidos abertos: " << quantidadePedido() << endl;
    cout << "Quantidade de produtos vendidos: " << quantidadeProdutos() << endl;
    cout << endl;
}

void Controle::clientes(){
    char escolha;
    int num;

    while(1){
        cout << "Escolha uma opcao:\n"
                "1- Adicionar Cliente\n"
                "2- Listar Clientes\n"
                "3- Selecionar Cliente\n"//esse vai puxar os pedidos do cliente
                "4- Procurar Cliente\n"
                "5- Sair\n\n";

        cin >> escolha;
        cin.ignore();

        clearTerminal();

        if(escolha > '0' || escolha < '9'){
            num = escolha - '0';
        }else{
            continue;
        }

        switch(num){
            case 1:
                cadastrarCliente();

                break;
            case 2:
                listarClientes();

                break;
            case 3:
                escolhaCliente(selecionarCliente());

                break;
            case 4:
                escolhaCliente(procurarCliente());

                break;
            case 5:
                return;
            default:
                cout << "Opcao Invalida!\n\n";
        }

    }
}

//void Controle::estoque(){}

/*
void Controle::relatorios(){
    int num;

    while(1){
        cout << "Escolha uma opcao:\n"
                "1- Relatorios Especificos\n"
                "2- Relatorios Gerais\n"                
                "3- Sair\n\n";

        cin >> num;
        cin.ignore();

        clearTerminal();

        switch(num){
            case 1:
                relatorios();

                break;
            case 2:
                relatorioGeral();

                break;
            case 3:
                return;
            default:
                cout << "Opcao Invalida!\n\n";
        }
    }
}
*/

void Controle::inicio(){
    char escolha;
    int num;

    while(1){
        cout << "Escolha uma opcao:\n"
                "1- Clientes\n"
                //"2- Estoque\n"
                "2- Relatorios\n"
                "3- Sair\n\n";
            
        cin >> escolha;

        clearTerminal();

        if(escolha > '0' || escolha < '9'){
            num = escolha - '0';
        }else{
            continue;
        }

        switch(num){
            case 1:
                clientes();

                break;
            /*case 2:
                //estoque();

                break;*/
            case 2:
                relatorioGeral();

                break;
            case 3:
                return;
            default:
                cout << "Opcao Invalida!\n\n";
        }
    }
}

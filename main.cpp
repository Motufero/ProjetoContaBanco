#include<iostream>
#include<stdio.h>

#include<vector>

#include "contaBanco.h"



using namespace std;


void iniciar (){
    ContaBanco contaAtual;
    vector<ContaBanco> contas = {};
    int origem;  //conta originadora da transferencia
    int destino;  //conta receptora da transferencia
    float valor;
    int verOrigem = 0;   //verificar se a conta origem da transferencia existe
    int verDestino = 0;  //verificar se a conta destino da transferencia existe

    int escolha;
    int provis;
    int tamanho = contas.size();
	int novaTaxaJuros;

    do {
        cout << "\n----------------------------------------------"<<endl;
        cout << "\nDigite '1' para criar uma conta." << endl;
        cout << "\nDigite '2' para depositar na conta." << endl;
        cout << "\nDigite '3' para sacar da conta." << endl;
        cout << "\nDigite '4' para exibir dados da conta." << endl;
        cout << "\nDigite '5' para exibir as contas." << endl;
        cout << "\nDigite '6' para realizar uma transferencia." << endl;
		cout << "\nDigite '7' para render juros em uma conta poupanca." << endl;
		cout << "\nDigite '8' para render juros para as contas tipo 'poupanca'." << endl;
        cout << "\nDigite '10' para sair." << endl;

        cin >> escolha;

        switch (escolha)
        {
		case 1:
            contaAtual.criarConta();
            contas.push_back(contaAtual);
            tamanho = contas.size();
            break;
        case 2:
            cout<< "\nDIGITE O NUMERO DA CONTA: "<<endl;
            cin >> provis;
            for (int i = 0; i < tamanho; i++){
                if(contas[i].getId()==provis){
                    contas[i].depositar();
                }
            }
            break;
        case 3:
            cout<< "\nDIGITE O NUMERO DA CONTA: "<<endl;
            cin >> provis;
            for (int i = 0; i < tamanho; i++){
                if(contas[i].getId()==provis){
                    contas[i].sacar();
                }
            }
            break;
        case 4:
            cout<< "\nDIGITE O NUMERO DA CONTA: "<<endl;
            cin >> provis;
            for (int i = 0; i < tamanho; i++){
                if(contas[i].getId()==provis){
                    contas[i].exibirDados();
                    break;
                }
            }
            break;
       case 5:
            for (int i = 0; i < tamanho; i++){
                //cout<<"\nConta: "<<contas[i].getId()<<endl;
                contas[i].exibirDados();
            }
            break;
        case 6:
            cout << "\nDigite a conta de Origem: " << endl;
            cin >> origem;
            cout << "\nDigite a conta de destino: " << endl;
            cin >> destino;
            cout << "\nDigite o valor da transferencia: " << endl;
            cin >> valor;
            for (int i = 0; i < tamanho; i++)
            {
                if (origem == contas[i].getId())
            {
                verOrigem = 1;
            }
                if (destino == contas[i].getId())
            {
                verDestino = 1;
            }
            }
            if (verDestino == 1 && verOrigem == 1)
            {
                for (int i = 0; i < tamanho; i++)
                {
                    if (origem == contas[i].getId())
                {
                    contas[i].sacar(valor);
                }
                if (destino == contas[i].getId())
                {
                    contas[i].depositar(valor);
                }
                }
            cout<<"\nDeposito realizado com sucesso. "<<endl;
            }
            break;
		case 7:
			cout<< "\nDIGITE O NUMERO DA CONTA: "<<endl;
            cin >> provis;
            for (int i = 0; i < tamanho; i++){
                if(contas[i].getId()==provis && contas[i].getTipoDeConta() == 2){
                    contas[i].renderJuros();
                    break;
                }
            }

		break;
		case 8:
			cout << "\nDigite o novo valor de juros: " <<endl;
			cin >> novaTaxaJuros;
            for (int i = 0; i < tamanho; i++){
                if (contas[i].getTipoDeConta()==2) {
					contas[i].setJuros(novaTaxaJuros);
				}
            }
			cout << "\nTaxa atualizada para todas as contas de tipo poupanca. " <<endl;
            break;

        case 10:
            cout << "\nSAINDO..." << endl;
            exit(1);
        default:
            cout << "\n ERRO, escolha uma opcao valida. " << endl;
            break;
        }
    }while(escolha =! (0));


}

int main(){
    cout<<"\n_____________________SEJA_BEM_VINDO!_______________________"<<endl;

    iniciar();
    return 0;
}


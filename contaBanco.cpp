#include<iostream>
#include<stdio.h>
#include<cmath>

#include<vector>

#include "contaBanco.h"

using namespace std;

ContaBanco::ContaBanco(){}

int ContaBanco::getId(){
	return this->idConta;
}

int ContaBanco::getTipoDeConta(){
    return this->tipoDeConta;
}

void ContaBanco::depositar(float dep){
	saldo = saldo  + dep;
}

void ContaBanco::sacar(float dep){
	saldo = saldo  - dep;
}

void ContaBanco::depositar(){
	float deposito;
    cout<<"\n--------------DEPOSITANDO-------------------"<<endl;
    cout<<"\nDigite o valor a depositar:"<<endl;
    cin>>deposito;
    saldo = saldo + deposito;
    cout<<"\nValor depositado com exito!"<<endl;
    if (tipoDeConta == 1) {
        this->calcularBonus(deposito, 0);
    }

}

void ContaBanco::sacar(){
    float saque;
    cout<<"\n------------------SACANDO-------------------"<<endl;
    cout<<"\nDigite o valor a sacar:"<<endl;
    cin>>saque;
    saldo = saldo - saque;
    cout<<"\nValor sacado com exito!"<<endl;

}

void ContaBanco::calcularBonus(float valor, int tipoDeOperacao){
    if (tipoDeOperacao == 0){ // 0 = deposito
        contadorDeposito += valor;
        while (contadorDeposito >= 100){
            contadorDeposito = contadorDeposito - 100;
            bonus = bonus + 1;
        }
    }
    if (tipoDeOperacao == 1){ //1 = transferencia
        contadorTransf += valor;
        while (contadorTransf >= 150){
            contadorTransf = contadorTransf - 150;
            bonus = bonus + 1;
        }

    }
}

void ContaBanco::renderJuros(){
	cout<<"\n---------------------RENDENDO-JUROS----------------"<<endl;
	float temp;
	temp = saldo + (taxaJuros/100 * saldo);
	saldo = floorf(temp*100) / 100;
	cout<< "\nSaldo da conta atualizado para: " << saldo << "R$" <<endl; 
}

void ContaBanco::setJuros(float newJuros){
	this->taxaJuros = newJuros;
}

void ContaBanco::exibirDados(){
    cout<<"\n----------------DADOS-DA-CONTA-----------------"<<endl;
	if (this->tipoDeConta==2){
        cout<<"\nCONTA POUPANCA, seu juros e: "<<taxaJuros<<"% "<<endl;
    }
    if (this->tipoDeConta==1){
        cout<<"\nCONTA BONUS, seu bonus e: "<<bonus<<" pontos!"<<endl;
    }
    if (this->tipoDeConta==0){
        cout<<"\nCONTA PADRAO"<<endl;
    }

    cout<<"\nSeu numero de conta: "<<idConta<<endl;
    cout<<"\nSeu saldo: "<<saldo<<"R$"<<endl;

}

void ContaBanco::criarConta(){
    int temporario;
	int temporarioTipo;

    cout<<"\n---------------CRIANDO-CONTA-----------------"<<endl;
	cout<<"\nDigite o tipo da conta: 0 para normal, 1 para bonus, 2 para poupança."<<endl;
    cin>>temporarioTipo;
    if (temporarioTipo == 0){
        this->tipoDeConta = 0;
		this->taxaJuros = 0;
    }
    if (temporarioTipo == 1){
        this->tipoDeConta = 1;
        this->bonus = 10;
        this->contadorDeposito = 0;
        this->contadorTransf = 0;
    }
    if (temporarioTipo == 2){
        this->tipoDeConta = 2;
        this->taxaJuros = 5;
    }
	else {
		//TO-DO encerrar a função
	}

    cout<<"\nDigite o numero da conta (deve ser maior que zero): "<<endl;
    cin>>temporario;
    if (temporario > 0){
        this->idConta = temporario;
        this->saldo = 0;
        cout<<"\nConta criada com sucesso! "<<endl;
    }
    else{
        cout<<"\nERRO, numero da conta não pode ser menor ou igual a zero! "<<endl;
    }

}



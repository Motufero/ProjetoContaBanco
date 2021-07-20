#include<iostream>
#include<stdio.h>

#include<vector>

#include "contaBanco.h"

using namespace std;

ContaBanco::ContaBanco(){}

int ContaBanco::getId(){
	return this->idConta;
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

}

void ContaBanco::sacar(){
    float saque;
    cout<<"\n------------------SACANDO-------------------"<<endl;
    cout<<"\nDigite o valor a sacar:"<<endl;
    cin>>saque;
    saldo = saldo - saque;
    cout<<"\nValor sacado com exito!"<<endl;

}

void ContaBanco::exibirDados(){
    cout<<"\n----------------DADOS-DA-CONTA-----------------"<<endl;
    cout<<"\nSeu numero de conta: "<<idConta<<endl;
    cout<<"\nSeu saldo: "<<saldo<<"R$"<<endl;

}

void ContaBanco::criarConta(){
    int temporario;
    cout<<"\n---------------CRIANDO-CONTA-----------------"<<endl;
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



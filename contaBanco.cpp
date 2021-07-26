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
	if (this->tipoDeConta==1){
        cout<<"\nCONTA BONUS, seu bonus e: "<<bonus<<" pontos!"<<endl;
    }
	if (this->tipoDeConta==0){
        cout<<"\nCONTA PADRAO"<<endl;
    }

    cout<<"\nSeu numero de conta: "<<idConta<<endl;
    cout<<"\nSeu saldo: "<<saldo<<"R$"<<endl;
}

void calcularBonus(float valor){}

void ContaBanco::criarConta(){
    int temporarioID;
	int temporarioTipo;

    cout<<"\n---------------CRIANDO-CONTA-----------------"<<endl;
	cout<<"\nDigite o tipo da conta: 0 para normal, 1 para bonus"<<endl;
	cin>>temporarioTipo;
	if (temporarioTipo == 0){
		this->tipoDeConta = 0;
		this->bonus = 0;
	}	
	if (temporarioTipo == 1){
		this->tipoDeConta = 1;
		this->bonus = 10;
	}	

	else {
		cout<<"\nValor invalido, terminando processo..."<<endl;
		exit;
	}
    cout<<"\nDigite o numero da conta (deve ser maior que zero): "<<endl;
    cin>>temporarioID;
    if (temporarioID > 0){
        this->idConta = temporarioID;
        this->saldo = 0;
        cout<<"\nConta criada com sucesso! "<<endl;
    }
    else{
        cout<<"\nERRO, numero da conta não pode ser menor ou igual a zero! "<<endl;
    }

}



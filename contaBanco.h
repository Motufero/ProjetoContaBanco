#include <iostream>

#ifndef _CONTABANCO_H_
#define _CONTABANCO_H_

class ContaBanco{
		int tipoDeConta;
		int bonus;
        int idConta;
        float saldo;

    public:
        ContaBanco();
		void calcularBonus(float);
        void criarConta();
        void depositar();
        void sacar();
        void depositar(float);
        void sacar(float);
        void exibirDados();
        int getId();

};

#endif


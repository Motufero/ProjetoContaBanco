#include <iostream>

#ifndef _CONTABANCO_H_
#define _CONTABANCO_H_

class ContaBanco{
        int idConta;
        float saldo;

    public:
        ContaBanco();
        void criarConta();
        void depositar();
        void sacar();
        void depositar(float);
        void sacar(float);
        void exibirDados();
        int getId();

};

#endif


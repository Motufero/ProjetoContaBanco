#include <iostream>

#ifndef _CONTABANCO_H_
#define _CONTABANCO_H_

class ContaBanco{
		int tipoDeConta;
		float taxaJuros;

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
        int getTipoDeConta();

		void setJuros(float); 
		void renderJuros(); 

};

#endif


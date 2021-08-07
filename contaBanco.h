#include <iostream>

#ifndef _CONTABANCO_H_
#define _CONTABANCO_H_

class ContaBanco{
		
		int tipoDeConta;
		float taxaJuros;

        int idConta;
        float saldo;

        int bonus;
        float contadorDeposito; //para manter a contagem de bonus entre depositos
        float contadorTransf; //para manter a contagem de bonus entre transferencias


    public:
        ContaBanco();
        void calcularBonus(float, int);
        void criarConta();
        void depositar();
        void sacar();
        void depositar(float);
        void sacar(float);
        void exibirDados();
        int getId();
        int getTipoDeConta();
		float getSaldo();

		void setJuros(float); 
		void renderJuros(); 

};

#endif


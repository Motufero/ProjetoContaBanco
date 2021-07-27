#include <iostream>

#ifndef _CONTABANCO_H_
#define _CONTABANCO_H_

class ContaBanco{

		int tipoDeConta;
		
		//para conta bonus:
		int bonus;
		float contadorDeposito; //para manter a contagem de bonus entre depositos
		float contadorTransf; //para manter a contagem de bonus entre transferencias

        int idConta;
        float saldo;
		//TO-DO Usar herança para separar os tipos de contas.		

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
};

#endif


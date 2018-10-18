#ifndef ARVORE_B
#define ARVORE_B

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <math.h>
using namespace std;

class Arvore_B {

	vector<int> arvore;
	int elementos;

public:
	Arvore_B(int elemento);
	~Arvore_B();
    int getElementos();
	void insercao (int elemento/*, int pos*/);
	void remocao (int elemento);
	void impressao_pre(int pos);
	void impressao_em(int pos);
	void impressao_pos(int pos);
	void busca (int elemento);

};

Arvore_B::Arvore_B(int elemento){
	arvore.push_back(elemento);
	elementos = 1;
}


Arvore_B::~Arvore_B(){}


int Arvore_B::getElementos(){

    elementos = 0;

    for (unsigned int i = 0; i < arvore.size(); i++){
        if (arvore[i] != -1000000){
            elementos++;
        }
    }

    return elementos;
}


void Arvore_B::insercao (int elemento /*, int posicao*/){

    for (unsigned int i = 0; i < arvore.size(); i++){
        if (arvore[i] == -1000000){
            arvore[i] = elemento;
            return;
        }
    }


    arvore.push_back(elemento);

    /*float aux = floor((posicao - 1)/2);

	if (arvore[aux].data() != nullptr){
		cout << "Posicao indicada é invalida" << endl;
		return;
	}

	arvore[posicao] = elemento;
	cout << "elemento adicionado" << endl;*/
}

void Arvore_B::remocao(int elemento){
	unsigned int pos;

	for (unsigned int i = 0; i < arvore.size(); i++){
		if (arvore[i] == elemento){
			pos = int (i);
			i = arvore.size();
		}
	}

	int filho_esquerdo = (2 * pos) + 1;
	int filho_direito = (2 * pos) + 2;


	if (filho_esquerdo < int (arvore.size())){
		remocao(arvore[filho_esquerdo]);
	}

	if (filho_direito < int (arvore.size())){
		remocao(arvore[filho_direito]);
	}

	arvore[pos] = -1000000;
}

void Arvore_B::impressao_pre(int pos){

	int filho_direito = (2 * pos) + 2;
	int filho_esquerdo = (2 * pos) + 1;

	cout << arvore[pos] << "  ";


	if (filho_esquerdo < int (arvore.size()) && arvore[filho_esquerdo] != -1000000){
		impressao_pre(filho_esquerdo);
	}

	if (filho_direito < int (arvore.size()) && arvore[filho_direito] != -1000000){
		impressao_pre(filho_direito);
	}

}


void Arvore_B::impressao_em(int pos){
	int filho_direito = (2 * pos) + 2;
	int filho_esquerdo = (2 * pos) + 1;

	if (filho_esquerdo <= int (arvore.size()) && arvore[filho_esquerdo] != -1000000){
		impressao_pre(filho_esquerdo);
	}

	cout << arvore[pos] << "  ";

	if (filho_direito <= int (arvore.size()) && arvore[filho_direito] != -1000000){
		impressao_pre(filho_direito);
	}

}

void Arvore_B::impressao_pos(int pos){

	int filho_direito = (2 * pos) + 2;
	int filho_esquerdo = (2 * pos) + 1;


	if (filho_esquerdo <= int (arvore.size()) && arvore[filho_esquerdo] != -1000000){
		impressao_pre(filho_esquerdo);
	}

	if (filho_direito <= int (arvore.size()) && arvore[filho_direito] != -1000000){
		impressao_pre(filho_direito);
	}

	cout << arvore[pos] << "  ";

}

void Arvore_B::busca (int elemento){

	int aux = 0;

	for (unsigned int i = 0; i < arvore.size(); i++){
		if (arvore[i] == elemento){
			cout << "Elemento esta presente na arvore" << endl;
			i = arvore.size();
			aux = 1;
		}
	}

	if (aux == 0){
		cout << "Não esta presente na arvore"<< endl;
	}

}

#endif

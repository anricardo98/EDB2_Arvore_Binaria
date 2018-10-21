#ifndef ARVORE_B
#define ARVORE_B
#define NULO -1000000

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

	//processo de insercao
	void insercao (int elemento, int pai);
	int busca_pai (int elemento_, int indice);

	//processo de remocao
	void remocao (int elemento);
	int remocao_ (int elemento, int indice);
	void remocao_filhos(int indice);

	//processo de impressao por cada tipo de percorrer
	void impressao_pre(int indice);
	void impressao_em(int indice);
	void impressao_pos(int indice);

	//processo de busca por pré ordem
	void busca (int elemento);
	int busca_ (int elemento, int indice);

};

Arvore_B::Arvore_B(int elemento){
	arvore.push_back(elemento);
	elementos = 1;
}


Arvore_B::~Arvore_B(){}


int Arvore_B::getElementos(){

    elementos = 0;

    for (unsigned int i = 0; i < arvore.size(); i++){
        if (arvore[i] != NULO){
            elementos++;
        }
    }

    return elementos;
}

void Arvore_B::insercao(int elemento, int pai){

	int indice_pai = busca_pai(pai, 0);

	if (indice_pai == NULO){
		cout << "Elemento pai indicado nao presente na arvore: " << pai << endl;
		return;
	}

	int filho_esquerdo = (2 * indice_pai) + 1;
	int filho_direito = (2 * indice_pai) + 2;

	if (filho_direito > int (arvore.size())){

		int tamanho_ant = int (arvore.size());

		int acrescentar = tamanho_ant + 1;

		for (int i = 0; i < acrescentar; i++){
			arvore.push_back(NULO);
		}
	}

	if (arvore[filho_esquerdo] == NULO){

		arvore[filho_esquerdo] = elemento;

	} else if (arvore[filho_direito] == NULO){

		arvore[filho_direito] = elemento;

	} else {

		cout << "No preenchido: " << pai << endl;
		cout << "Filho esquerdo: " << arvore[filho_esquerdo] << endl;
		cout << "Filho esquerdo: " << arvore[filho_direito] << endl;
	}

}

int Arvore_B::busca_pai(int elemento_, int indice_){

	int aux;
	int tamanho = int (arvore.size());
	int filho_esquerdo = (2 * indice_) + 1;
	int filho_direito = (2 * indice_) + 2;

	if (arvore[indice_] == elemento_ ){

        return indice_;

	} else {

        aux = NULO;

	}

    if (arvore[filho_esquerdo] != NULO && filho_esquerdo < tamanho){
        aux = busca_pai(elemento_, filho_esquerdo);

        if (aux != NULO){
            return aux;
        }
    }

    if (arvore[filho_direito] != NULO && filho_direito < tamanho){
        aux = busca_pai(elemento_, filho_direito);
    }

    return aux;
}



void Arvore_B::remocao(int elemento){
	int aux = remocao_(elemento, 0);

	if (aux == 0){
		cout << "Nao e possivel remover este elemento:" << elemento << endl;
	}
}

int Arvore_B::remocao_(int elemento, int indice){

	int aux = 0;

	int filho_esquerdo = (2 * indice) + 1;
	int filho_direito = (2 * indice) + 2;

	if (arvore[indice] == elemento){

		if (filho_esquerdo < int (arvore.size()) && arvore[filho_esquerdo] != NULO){
			remocao_filhos(filho_esquerdo);
		}

		if (filho_direito < int (arvore.size()) && arvore[filho_direito] != NULO){
			remocao_filhos(filho_direito);
		}

		arvore[indice] = NULO;

		return 1;
	}


	if (filho_esquerdo < int (arvore.size()) && arvore[filho_esquerdo] != NULO && aux == 0){
		aux = remocao_(elemento, filho_esquerdo);
	}

	if (filho_direito < int (arvore.size()) && arvore[filho_direito] != NULO && aux == 0){
		aux = remocao_(elemento, filho_direito);
	}


	return aux;
}

void Arvore_B::remocao_filhos(int indice){

	int filho_esquerdo = (2 * indice) + 1;
	int filho_direito = (2 * indice) + 2;

	if (filho_esquerdo < int (arvore.size()) && arvore[filho_esquerdo] != NULO){
		remocao_filhos(filho_esquerdo);
	}

	if (filho_direito < int (arvore.size()) && arvore[filho_direito] != NULO){
		remocao_filhos(filho_direito);
	}

	arvore[indice] = NULO;

	return;
}


void Arvore_B::impressao_pre(int indice){

	int filho_direito = (2 * indice) + 2;
	int filho_esquerdo = (2 * indice) + 1;

	cout << arvore[indice] << "  ";


	if (filho_esquerdo < int (arvore.size()) && arvore[filho_esquerdo] != NULO){
		impressao_pre(filho_esquerdo);
	}

	if (filho_direito < int (arvore.size()) && arvore[filho_direito] != NULO){
		impressao_pre(filho_direito);
	}

}


void Arvore_B::impressao_em(int indice){
	int filho_direito = (2 * indice) + 2;
	int filho_esquerdo = (2 * indice) + 1;

	if (filho_esquerdo <= int (arvore.size()) && arvore[filho_esquerdo] != NULO){
		impressao_pre(filho_esquerdo);
	}

	cout << arvore[indice] << "  ";

	if (filho_direito <= int (arvore.size()) && arvore[filho_direito] != NULO){
		impressao_pre(filho_direito);
	}

}

void Arvore_B::impressao_pos(int indice){

	int filho_direito = (2 * indice) + 2;
	int filho_esquerdo = (2 * indice) + 1;


	if (filho_esquerdo <= int (arvore.size()) && arvore[filho_esquerdo] != -1000000){
		impressao_pre(filho_esquerdo);
	}

	if (filho_direito <= int (arvore.size()) && arvore[filho_direito] != -1000000){
		impressao_pre(filho_direito);
	}

	cout << arvore[indice] << "  ";

}




void Arvore_B::busca (int elemento){
	int aux = busca_(elemento, 0);

	if (aux == 0){
		cout << "O elemento nao esta presente na lista" << endl;
	}


}

int Arvore_B::busca_ (int elemento, int indice){

	int aux = 0;
	if (arvore[indice] == elemento){

		cout << "O elemento esta presente na lista" << endl;
		return 1;
	}

	int filho_direito = (2 * indice) + 2;
	int filho_esquerdo = (2 * indice) + 1;


	if (filho_esquerdo <= int (arvore.size()) && arvore[filho_esquerdo] != -1000000){
		aux = busca_(elemento, filho_esquerdo);
	}

	if (filho_direito <= int (arvore.size()) && arvore[filho_direito] != -1000000){
		aux = busca_(elemento, filho_direito);
	}

	return aux;

}

#endif

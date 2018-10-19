#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <math.h>
#include "arvore_binaria.hpp"
using namespace std;

int main (){

	Arvore_B tree(1);
	tree.insercao(2, 1);
	tree.insercao(3, 1);
	tree.insercao(4, 2);
	tree.insercao(5, 2);
	tree.insercao(6, 3);
	tree.insercao(7, 3);
	tree.insercao(8, 4);
	tree.insercao(9, 4);
	tree.insercao(10, 5);
	tree.insercao(11, 5);
	tree.insercao(13, 1);

	cout << "A arvore tem: " << tree.getElementos() << " elementos" << endl;

	tree.impressao_pre(0);
	cout << endl;

	tree.impressao_em(0);
	cout << endl;

	tree.impressao_pos(0);
	cout << endl;

	tree.busca(6);
	tree.busca(13);

	tree.remocao(3);

	tree.busca(3);

	tree.impressao_pre(0);
	cout << endl;

	tree.insercao(13, 1);
	tree.insercao(22, 13);
	tree.insercao(23, 13);
	tree.insercao(15, 15);

	cout << "A arvore tem: " << tree.getElementos() << " elementos" << endl;

	tree.impressao_pre(0);
	cout << endl;
	tree.impressao_em(0);
	cout << endl;
	tree.impressao_pos(0);
	cout << endl;

	cout << endl;

	return 0;
}

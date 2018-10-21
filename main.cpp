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
	tree.insercao(9, 6);
	tree.insercao(10, 7);
	tree.insercao(11, 7);
	tree.insercao(14, 8);
	tree.insercao(19, 8);
	tree.insercao(20, 8);
	tree.insercao(116, 11);

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

	tree.remocao(2);
	tree.remocao(116);

	tree.busca(3);

	tree.impressao_pre(0);
	cout << endl;

	tree.insercao(13, 1);
	tree.insercao(22, 13);
	tree.insercao(23, 13);
	tree.insercao(15, 15);
	tree.insercao(222, 22);

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

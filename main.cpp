#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <math.h>
#include "C:\Users\anric\ED2-Arvore-Binaria\arvore_binaria.hpp"
using namespace std;

int main (){

	Arvore_B tree(1);
	tree.insercao(2);
	tree.insercao(3);
	tree.insercao(4);
	tree.insercao(5);
	tree.insercao(6);
	tree.insercao(7);
	tree.insercao(8);
	tree.insercao(9);
	tree.insercao(10);
	tree.insercao(11);

	cout << "A arvore tem: " << tree.getElementos() << "elementos" << endl;

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

	tree.insercao(13);
	tree.insercao(22);
	tree.insercao(23);
	tree.insercao(15);

	cout << "A arvore tem: " << tree.getElementos() << "elementos" << endl;

	tree.impressao_pre(0);
	cout << endl;
	tree.impressao_em(0);
	cout << endl;
	tree.impressao_pos(0);
	cout << endl;

	cout << endl;

	tree.~Arvore_B();
	return 0;
}

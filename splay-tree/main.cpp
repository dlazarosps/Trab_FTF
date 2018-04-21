#include "splay.h"
#include <iostream>

#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <cstdlib>      // std::rand, std::srand
#include <cstdio>

#include <iterator>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 3){
        cerr << "Uso correto: ./main [input file] [output file] " << endl;
        return 0;
    }

    //Inicia Árvore
	splay* root = NULL;

    //Carrega nodo a serem inseridos
    std::ifstream is(argv[1]);
    std::istream_iterator<KEY_TYPE> start(is), end;
    std::vector<KEY_TYPE> v_nodes(start, end);

    //insere na arvore
    for(int i = 0; i < v_nodes.size(); i++)
        root = Insert(v_nodes[i], root);

    //salva print da saida em arquivo output
    freopen(argv[2],"w",stdout);
    InOrder(root);
    fclose (stdout);

	return 0;
}

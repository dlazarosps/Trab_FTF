/*
*   Main Program RBTree
*   @autor Douglas Lázaro
*   @version 0.1
*/

#include <bits/stdc++.h>
#include <vector>
#include "RBTree.h"

#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

#define MAX 2001
using namespace std;

//função para printar em tela
void printvector(std::vector<int> v_nodes){
    std::copy(v_nodes.begin(), v_nodes.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << endl;
    std::cout << "--------" <<endl;
}


// random generator function:
int myrandom (int i) { return std::rand()%i;}

int main(int argc, char * argv[]) {

    if (argc != 1)
    {
        cerr << "Uso correto: ./main > output " << endl;
        return 0;
    }

    RBTree rbTree1; //arvore R&B
    vector<int>v_nodes(MAX); //vetor de nós
    int i = -((MAX-1)/2); //limite inferior de valores

    // Preenche array com valores de -i até +i
    std::generate(v_nodes.begin(), v_nodes.end(), [&]{ return i++; });

    // Imprime vetor conforme ordem de inserção
    // printvector(v_nodes);
    
    // Embaralhar elementos do vetor
    std::random_shuffle (v_nodes.begin(), v_nodes.end(),  myrandom);

    // Imprime vetor após elementos embaralhados
    // printvector(v_nodes);

    //insere na arvore
    for(int i = 0; i < v_nodes.size(); i++)
        rbTree1.insertValue(v_nodes[i]);
    
    rbTree1.inorder();
    // rbTree1.preorder();

    return 0;
}
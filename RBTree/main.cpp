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
#include <cstdio>

// #define MAX 50001 
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

    if (argc != 3){
        cerr << "Uso correto: ./main <input size> <output file> " << endl;
        return 0;
    }


    int max = atoi(argv[1]); //input size
    RBTree rbTree1; //arvore R&B
    vector<int>v_nodes(max+1); //vetor de nós
    int i = -((max)/2); //limite inferior de valores

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

    //salva print da saida em arquivo output
    freopen(argv[2],"w",stdout);
    rbTree1.inorder();
    // rbTree1.preorder();
    fclose (stdout);

    return 0;
}
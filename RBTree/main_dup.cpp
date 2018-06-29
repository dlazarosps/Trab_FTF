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

#include <iterator>
#include <fstream>

using namespace std;

RBTree runner(char* input){

    RBTree rbTree; //arvore R&B

    //input file
    ifstream is(input);
    istream_iterator<int> start(is), end;
    vector<int> v_nodes(start, end);

    //insere na arvore
    for(int i = 0; i < v_nodes.size(); i++)
        rbTree.insertValue(v_nodes[i]);

    return rbTree;
}

int main(int argc, char * argv[]) {

    if (argc != 4){
        cerr << "Uso correto: ./main [input file] [output file] [log file]" << endl;
        return 0;
    }

    RBTree rbTree1, rbTree2; //arvore R&B

    rbTree1 = runner(argv[1]);
    rbTree2 = runner(argv[1]);

    //salva print da saida em arquivo output
    freopen(argv[2],"w",stdout);
    rbTree1.inorder();
    // rbTree1.preorder();
    fclose (stdout);

    //salva print da saida em arquivo output
    freopen(argv[3],"w",stdout);
    rbTree2.inorder();
    // rbTree1.preorder();
    fclose (stdout);

    return 0;
}
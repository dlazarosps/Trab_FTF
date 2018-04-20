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

int main(int argc, char * argv[]) {

    if (argc != 3){
        cerr << "Uso correto: ./main [input file] [output file] " << endl;
        return 0;
    }

    std::ifstream is(argv[1]);
    std::istream_iterator<int> start(is), end;
    std::vector<int> v_nodes(start, end);
    
    // print the v_nodes to stdout
    /*
        std::cout << "Read " << v_nodes.size() << " v_nodes" << std::endl;
        std::cout << "v_nodes read in:\n";
        std::copy(v_nodes.begin(), v_nodes.end(), 
            std::ostream_iterator<double>(std::cout, " "));
        std::cout << std::endl;
    */


    RBTree rbTree1; //arvore R&B

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
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

#include <omp.h>

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

void compare_output(char *input1, char *input2, char *detectLog) {

    fstream file1(input1), file2(input2);
    FILE *fp;
    char string1[256], string2[256];
    int j; j = 0;
    
    while(!file1.eof())
    {
        file1.getline(string1,256);
        file2.getline(string2,256);
        j++;
        if(strcmp(string1,string2) != 0)
        {
            if (fp = fopen(detectLog, "a")) {
                fprintf(fp, "[%d]: %s %s\n",j,string1,string2);
                fclose(fp);
            }
        }
    }
}

int main(int argc, char * argv[]) {

    if (argc != 5){
        cerr << "Uso correto: ./main [input file] [output file] [log file] [output2 file]" << endl;
        return 0;
    }

    // tempo de execução INIT
    clock_t start_time, stop_time;
    double diff_time;

    start_time = clock();

    RBTree rbTree1, rbTree2; //arvore R&B
    // char output2[9] = "output2_";

    //aplica algoritmo nas duas cópias
    // #pragma omp parallel
    // #pragma omp single
    rbTree1 = runner(argv[1]);
    rbTree2 = runner(argv[1]);

    //salva print da saida em arquivo output
    // #pragma omp task
    freopen(argv[2],"w",stdout);
    rbTree1.inorder();
    fclose (stdout);


    // salva print da saida em arquivo output2
    // #pragma omp task
    freopen(argv[4],"w",stdout);
    rbTree2.inorder();
    fclose (stdout);

    // #pragma omp taskwait

    compare_output(argv[2], argv[4], argv[3]);

    // tempo de execução FIM
    stop_time = clock();
    diff_time = ((stop_time - start_time) / double(CLOCKS_PER_SEC)*1000)/1000;

    cerr << "Time: " << diff_time << "s" << endl;

    return 0;
}
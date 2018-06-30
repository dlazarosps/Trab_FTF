#include "splay.h"
#include <bits/stdc++.h>

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

splay* runner(char* input){

    splay* splay = NULL; //arvore 

    //input file
    ifstream is(input);
    istream_iterator<KEY_TYPE> start(is), end;
    vector<KEY_TYPE> v_nodes(start, end);

    //insere na arvore
    for(int i = 0; i < v_nodes.size(); i++)
        splay = Insert(v_nodes[i], splay);

    return splay;
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

int main(int argc, char* argv[])
{
    if (argc != 5){
        cerr << "Uso correto: ./main [input file] [output file] [log file] [output2 file]" << endl;
        return 0;
    }

    //Inicia Árvore
    splay* root1 = NULL;
    splay* root2 = NULL;
 
    root1 = runner(argv[1]);

    //salva print da saida em arquivo output
    // #pragma omp task
    freopen(argv[2],"w",stdout);
    InOrder(root1);
    fclose (stdout);

    // salva print da saida em arquivo output2
    // #pragma omp task
    root2 = runner(argv[1]);
    freopen(argv[4],"w",stdout);
    InOrder(root2);
    fclose (stdout);

    compare_output(argv[2], argv[4], argv[3]);

	return 0;
}

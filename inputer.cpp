#include <bits/stdc++.h>
#include <vector>
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <cstdio>
#include <string>

using namespace std;

//função para printar em tela
void printvector(std::vector<int> v_nodes){
    std::copy(v_nodes.begin(), v_nodes.end(), std::ostream_iterator<int>(std::cout, "\n"));
    // std::cout << endl;
    // std::cout << "--------" <<endl;
}

// random generator function:
int myrandom (int i) { return std::rand()%i;}


int main(int argc, char const *argv[])
{
	if (argc != 3){
        cerr << "Uso correto: ./inputer [input size] [output file] " << endl;
        return 0;
    }
	
	int max = atoi(argv[1]); //input size

    vector<int>v_nodes(max+1); //vetor de nós
    
    int i = -((max)/2); //limite inferior de valores
	
    // Preenche array com valores de -i até +i
    std::generate(v_nodes.begin(), v_nodes.end(), [&]{ return i++; });

    // Imprime vetor conforme ordem de inserção
    // printvector(v_nodes);
    
    // Embaralhar elementos do vetor
    std::random_shuffle (v_nodes.begin(), v_nodes.end(),  myrandom);

    // Imprime vetor após elementos embaralhados
    // Salva print da saida em arquivo output
    freopen(argv[2],"w",stdout);
    	printvector(v_nodes);
    fclose (stdout);

    int result;
  	std::string oldname = argv[2];
  	std::string newname = oldname + "_" + argv[1];

  	//renomeia o arquivo output com o número de inputs
	result= rename(oldname.c_str() , newname.c_str());

	if (result)
	    cerr << "Error ao renomear arquivo"  << endl;
	else
		cerr << "Arquivo Renomeado" << endl;

	return 0;
}
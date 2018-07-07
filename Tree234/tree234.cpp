
#include <bits/stdc++.h>
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <fstream>		// std::fstream
#include <omp.h>
#include "tree234.h"


using namespace std;

//MARK: Construtor - Cria a Arvore
Arvore234::Arvore234(){
	//A raiz da arvore e criada
	//o primeiro filho recebe nulo
	raiz = new NO;
	for(int i=0;i<4;i++){raiz->ponteiros[i] = 0;}
	raiz->quantDados = 0;
	raiz->pai = 0;
}

//MARK: Privado - E Raiz?
//verifica se o NO atual e raiz, comparando o NO pai com nulo
bool Arvore234::eRaiz(NO **atual){ //**
	if((*atual)->pai == 0)
		return true;
	else
		return false;
}

//Verifica se o NO e folha, observando se o filho mais a esquerda (posicao 0) e nulo
bool Arvore234::eFolha(NO **atual){ //**
	if((*atual)->ponteiros[0] == 0)
		return true;
	else
		return false;
}


//Verifica se o NO atual contem o valor.
bool Arvore234::estanoNo(NO **atual, int valor){ //**
	int quant = (*atual)->quantDados;
	for(int i=0;i<=quant-1;i++){
		if((*atual)->dados[i] == valor)
			return true;
	}
	return false;
}


//Funcao utilizada tanto na funcao de busca e insercao
//procura em qual filho do NO possivelmente esta o valor buscado
NO* Arvore234::encontraNoFilho(NO **atual, int valor){ //**
	int quant = (*atual)->quantDados;
	if(eFolha(atual))//se for folha nao tem filhos posiveis, retorna nulo
		return 0;
	else{//senao buscar posicao do possivel filho
		for(int i=0;i<=quant-1;i++){ //percorre o vetor ate a posicao quant-1
			if((*atual)->dados[i] > valor){ // se o dado da posicao atual for maior que o valor buscado
				return (*atual)->ponteiros[i];	//retorna o finho na posicao [i] do no atual
			}
		}
		return (*atual)->ponteiros[quant]; //caso o valor buscado seja maior que todos os elementos, retorna o ultimo filho
	}
}

//MARK: Publico - Buscar determinado valor na arvore.
NO* Arvore234::busca(int valor){ //**
	NO *atual = raiz;
	while(atual!=0){ //percorre ate encontrar uma folha
		if(estanoNo(&atual, valor)){ //confere se o valor esta no NO atual
			return atual; //se sim retorna o NO atual
		}
		else{
			atual = encontraNoFilho(&atual, valor); //busca o proximo possivel filho
		}
	}
	return 0;
}


void Arvore234::inserir(int valor){
	NO *atual = raiz;
	while(1){
		if (atual->quantDados == 3){
			divide(&atual);//caso o NO esteja cheio, iremos dividir
			atual = atual->pai; //o no atual agora passa ser o pai apos a divisao
			atual = encontraNoFilho(&atual, valor); //busca o filho onde serÃ¡ inserido
		}
		else if(eFolha(&atual)){
			break;//se for folha, interrompe a busca pela posicao
		}else{
			atual = encontraNoFilho(&atual, valor);//caso nao seja necessario dividir, buscar o filho onde sera inserido
		}
	}
	//apos buscar a posicao para ser alocado, insere o valor na posicao encontrada/atual;
	inserirValor(&atual, valor);

}



//Raiz e o primeiro caso, se nao for raiz, tem o SENAO que dividira o NO atual
void Arvore234::divide(NO **atual){
	//se for raiz
	if((*atual)->pai == 0){
		//cria novo NO B que sera a proxima raiz
		NO *B = new NO;
		for(int i=0;i<4;i++){B->ponteiros[i]=0;}
		B->ponteiros[1] = *atual;
		B->pai = 0;
		B->quantDados = 1;
		B->dados[0] = (*atual)->dados[1];

		//cria novo NO C
		//sera o irmao a direita do NO atual
		NO *C = new NO;
		for(int i=0;i<4;i++){C->ponteiros[i]=0;}
		C->ponteiros[1] = *atual;
		C->pai = B;
		C->quantDados = 1;
		C->dados[0] = (*atual)->dados[2];
		if(!eFolha(atual)){
			C->ponteiros[0] = (*atual)->ponteiros[2];
			((*atual)->ponteiros[2])->pai = C;
			C->ponteiros[1] = (*atual)->ponteiros[3];
			((*atual)->ponteiros[3])->pai = C;
		}

		//apontamentos do NO B para os filhos
		B->ponteiros[0] = *atual;
		B->ponteiros[1] = C;
		(*atual)->pai = B;
		(*atual)->quantDados = 1;
		raiz = B; //raiz atributo da classe
	}
	//Caso o NO a ser dividido nao for RAIZ
	else{
		NO *paiNo = (*atual)->pai;
		//envia B para o pai do atual
		paiNo->dados[paiNo->quantDados++] = (*atual)->dados[1];

		//cria novo NO C
		NO *C = new NO;
		for(int i=0;i<3;i++){C->ponteiros[i]=0;}
		C->ponteiros[1] = *atual;
		C->pai = paiNo;
		C->quantDados = 1;
		C->dados[0] = (*atual)->dados[2];
		if(!eFolha(atual)){
			C->ponteiros[0] = (*atual)->ponteiros[2];
			((*atual)->ponteiros[2])->pai = C;
			C->ponteiros[1] = (*atual)->ponteiros[3];
			((*atual)->ponteiros[3])->pai = C;
		}

		paiNo->ponteiros[paiNo->quantDados] = C;
		(*atual)->quantDados = 1;
	}
	bubblesort(&(*atual)->pai);
}


//Quando a busca pela espaco estiver pronto, chamamos a funcao que ira inserir
//o valor na arvore
void Arvore234::inserirValor(NO **atual, int valor){
	int quant = (*atual)->quantDados;
	(*atual)->dados[quant] = valor;
	(*atual)->quantDados++;
	bubblesort(atual);
}


void Arvore234::bubblesort(NO **atual){
	int quant = (*atual)->quantDados;
	int temp;
	//ordena os valores do nó
	for(int i=0;i<quant;i++){
		for(int j=i+1;j<quant;j++){
			if((*atual)->dados[i]>(*atual)->dados[j]){
				temp = (*atual)->dados[i];
				(*atual)->dados[i] = (*atual)->dados[j];
				(*atual)->dados[j] = temp;
			}
		}
	}
	//se o no nao for folha, realiza um bubblesort para ordenar os filhos do NO.
	if(!eFolha(atual)){
		NO *temp_no;
		for(int i=0;i<=quant;i++){
			for(int j=i+1;j<=quant;j++){
				if(((*atual)->ponteiros[i])->dados[0]>((*atual)->ponteiros[j])->dados[0]){
					temp_no = (*atual)->ponteiros[i];
					(*atual)->ponteiros[i] = (*atual)->ponteiros[j];
					(*atual)->ponteiros[j] = temp_no;
				}
			}
		}
	}
}


NO* Arvore234::encontraSucessor(NO *atual, int valor){
	if(!eFolha(&atual)){
		for(int i=0;i<atual->quantDados;i++){
			if(atual->dados[i] == valor){
				atual = atual->ponteiros[i+1];
				break;
			}
		}
	}
	while(!eFolha(&atual)){
		atual = atual->ponteiros[0];
	}
	return atual;
}


void Arvore234::exclui(NO *atual, int valor){
	int pos;
	for(int i=0;i<atual->quantDados;i++){
		if(atual->dados[i]==valor){
			pos = i;
		}
	}
	for(int j=pos;j<atual->quantDados-1;j++){
		atual->dados[j] = atual->dados[j+1];
	}
	atual->quantDados--;
}

//MARK: Privado - Verifica se é possivel realizar rotação com algum dos irmãos, caso seja, rota e retorna true.
bool Arvore234::rotar(NO *atual){
	int posicao;
	NO *noPai = atual->pai;
	NO *noIrmao;
	if(!eRaiz(&atual)){
		for(int i=0;i<=noPai->quantDados;i++){
			if(noPai->ponteiros[i]==atual){
				posicao = i;
				break;
			}
		}
		int quantIrmao;
		if(posicao>0){
			noIrmao = noPai->ponteiros[posicao-1];
			quantIrmao = noIrmao->quantDados;
			if(noIrmao->quantDados>1){
				inserirValor(&atual, noPai->dados[posicao-1]);
				noPai->dados[posicao-1] = noIrmao->dados[quantIrmao-1];
				exclui(noIrmao, noIrmao->dados[quantIrmao-1]);
				return true;
			}
		}
		if(posicao<noPai->quantDados){
			noIrmao = noPai->ponteiros[posicao+1];
			if(noIrmao->quantDados>1){
				inserirValor(&atual, noPai->dados[posicao]);
				noPai->dados[posicao] = noIrmao->dados[0];
				exclui(noIrmao, noIrmao->dados[0]);
				return true;
			}
		}
	}
	return false;
}


//MARK: Privado - Remover, contem bugs, nao estamos conseguindo aplicar a rotacao.
void Arvore234::remover(int valor){
	NO *atual = busca(valor);
	NO *tempNo;
	int valorTroca;

	if(atual!=0){
		if(!eFolha(&atual)){
			//encontre uma folha com o sucessor S(valorTroca) mais próximo de K(valor)
			for(int i=0;i<atual->quantDados;i++){
				if(atual->dados[i]==valor){
					tempNo = encontraSucessor(atual,valor);
					//copia S sobre K no node;
					atual->dados[i]=tempNo->dados[0];
					valorTroca = atual->dados[i];
					break;
				}
			}
			//atual = a folha que contem S;
			atual = tempNo;
			//remove s de atual;
			exclui(atual, valorTroca);
		}
		else{
			//remova K de node;
			exclui(atual, valor);
		}
	}
	while(1){
		if(atual->quantDados!=0){
			return;
		}
		else if(rotar(atual)){ //senão se há um irmão de node com chaves suficientes então execute a rotação.
			return;
		}
		else{
			NO *noPai = atual->pai;
			//Se o ascendente tem somente uma chave então faça a fusão de node, seu irmão e o ascendente para formar uma nova raiz;
			if(noPai->quantDados==1){
				if(noPai->ponteiros[0]!=atual)
					inserirValor(&noPai, (noPai->ponteiros[0])->dados[0]);
				if(noPai->ponteiros[1]!=atual)
					inserirValor(&noPai, (noPai->ponteiros[1])->dados[0]);
				atual = noPai;
				//falta liberar o espaco na memoria
				atual->ponteiros[0] = 0;
				return;
			}
			else{
				//faça a fusão de node e seu irmão;
				int posicao;
				NO *noIrmao;
				//procura em qual posição de filho está o atual.
				for(int i=0;i<=noPai->quantDados;i++){
					if(noPai->ponteiros[i]==atual){
						posicao = i;
						break;
					}
				}
				//se não for a ultima posição rota para a direita
				if(posicao<noPai->quantDados){
					noIrmao = noPai->ponteiros[posicao+1];
					inserirValor(&atual, noPai->dados[posicao]);
					inserirValor(&atual, noIrmao->dados[0]);
					exclui(noPai,noPai->dados[posicao]);
					//falta liberar memoria
					for(int i=posicao+1;i<noPai->quantDados+1;i++){
						noPai->ponteiros[i] = noPai->ponteiros[i+1];
					}
					return;
				}
				//senão rota para a esquerda
				else{
					noIrmao = noPai->ponteiros[posicao-1];
					inserirValor(&atual, noPai->dados[posicao-1]);
					inserirValor(&atual, noIrmao->dados[0]);
					//falta liberar memoria
					noPai->ponteiros[posicao-1] = atual;
					exclui(noPai,noPai->dados[posicao-1]);
					return;
				}
			}
		}
	}
}

//MARK: Privado - Imprimir
void Arvore234::imprime(NO *atual){
	int quant=atual->quantDados;
	for(int i=0;i<quant;i++)
		cout << std::bitset<16>(atual->dados[i]) << endl;
	cout << endl;
	if(!eFolha(&atual)){
		for(int i=0;i<=quant;i++)
			imprime(atual->ponteiros[i]);
	}
}

//MARK: Usuario - Imprimir
void Arvore234::imprime(){
	imprime(raiz);
}

//MARK: Usuario - Buscar
// verifica se o valor esta na arvore.
bool Arvore234::buscaValor(int valor){
	if(busca(valor)!=0)
		return true;
	else
		return false;
}


// //MARK: Privado - Imprimir
// void Arvore234::compare_output(NO *atual_output1, NO *atual_output2, char const *detectLog){
// 	int quant=atual_output1->quantDados;
// 	FILE *fp;
// 	fp = fopen(detectLog, "a");
// 	for(int i=0;i<quant;i++) {
// 		//fprintf(stderr, "%d   %d \n",atual_output1->dados[i], atual_output2->dados[i] );
// 		if (atual_output1->dados[i] != atual_output2->dados[i]){
// 			fprintf(fp, "[%d]: %u %u\n",i,atual_output1->dados[i],atual_output2->dados[i]);
// 		}
// 	}
// 	fclose(fp);
// 	if(!eFolha(&atual_output1)){
// 		for(int i=0;i<=quant;i++)
// 			compare_output(atual_output1->ponteiros[i], atual_output2->ponteiros[i], detectLog );
// 	}
//
//
// }
//
// void Arvore234::compare_output(Arvore234 a1, Arvore234 b1, char const *detectLog){
// 	Arvore234 a = a1;
// 	Arvore234 b = b1;
//
// 	compare_output(a.raiz, b.raiz, detectLog);
// }

Arvore234 runner(char* input){

    Arvore234 a1; //arvore R&B

    //input file
    ifstream is(input);
    istream_iterator<int> start(is), end;
    vector<int> v_nodes(start, end);

    //insere na arvore
    for(int i = 0; i < v_nodes.size(); i++)
        a1.inserir(v_nodes[i]);

    return a1;
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

	int omp_num_threads;
	char *detectLogFile;


	if (argc != 5){
			cerr << "Uso correto: ./main [input file] [output file] [detectLog file] [output2 file]" << endl;
			return 0;
	} else {

		// omp_num_threads = atoi(argv[1]);
		detectLogFile = argv[3];

	 }

	//omp_set_num_threads(omp_num_threads);

	clock_t start_time, stop_time;
   double diff_time;

   start_time = clock();

	//Isso é uma Instancia da classe
	Arvore234 arvore1 = runner(argv[1]); //Var1
	Arvore234 arvore2 = runner(argv[1]); //Var2

	// std::ifstream is(argv[2]);
	// std::istream_iterator<int> start(is), end;
	// std::vector<int> v_nodes(start, end);
	//
	// //insere na arvore
	// for(int i = 0; i < v_nodes.size()+1; i++) {
	// 		arvore1.inserir(v_nodes[i]);
	// 		arvore2.inserir(v_nodes[i]);
	// }

	//salva print da saida em arquivo output
	// #pragma omp task
	freopen(argv[2],"w",stdout);
	arvore1.imprime();
	fclose (stdout);


	// salva print da saida em arquivo output2
	// #pragma omp task
	freopen(argv[4],"w",stdout);
	arvore2.imprime();
	fclose (stdout);

	compare_output(argv[2], argv[4], argv[3]);


	stop_time = clock();
	diff_time = ((stop_time - start_time) / double(CLOCKS_PER_SEC)*1000)/1000;

	cerr << "Time: " << diff_time << "s" << endl;
	// freopen(argv[3],"w",stdout);
	// arvore1.imprime();
	//
	// fclose(stdout);


	return 0;



}

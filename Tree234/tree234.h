

//Estrutura da Arvore 2-3-4
typedef struct no {
	struct no* pai;
	int dados[3];
	int quantDados;
	struct no* ponteiros[4];
} NO;


//Classe da Arvore 2-3-4
class Arvore234{
	public:
		Arvore234();
		void inserir(int);
		void imprime();
		void remover(int);
		bool buscaValor(int);
		// void compare_output(NO *atual_output1, NO *atual_output2, char const *detectLog);
		// void compare_output(Arvore234 a1, Arvore234 b1, char const *detectLog);

	private:
		NO *raiz;
		NO *busca(int);
		void insere(NO**, int);
		void divide(NO**);
		bool estanoNo(NO**, int);
		bool eRaiz(NO**);
		bool eFolha(NO**);
		NO *encontraNoFilho(NO**,int);
		void inserirValor(NO**, int);
		void imprime(NO*);
		void bubblesort(NO**);
		NO *encontraSucessor(NO*, int);
		bool rotar(NO*);
		void exclui(NO*, int);
};

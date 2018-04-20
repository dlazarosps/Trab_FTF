# Trab_FTF
Trabalho de FTF - Injeção de Falhas - UFRGS

## Árvores (Data-Structs)
* AVL Tree
* Binary Tree
* BTree
* RB Tree (_Red and Black_)

## Algoritmo de Teste
Código _INPUTER_
* __MAX:__ PARM_SIZE (_quantidade de nós_)
* __RANGE:__ \[  -MAX/2, MAX/2 \] 
```
- Popula lista de nós conforme o RANGE
- Embaralha os nós na lista
- gera arquivo de input
```

Como gerar inputs
` $ make PARM_SIZE= ` __XYZ__ (_quantidade de nós_)

 Código _MAIN_
* __INPUTFILE:__ arquivo de entrada gerado pelo inputer
* __OUTPUTFILE:__ gold_ OU output_ (_Carol-FI_)
```
- Lê arquivo de input
- insere todos nós na árvore
- imprime nós da árvore em ordem crescente
- salva saída em binário
```
### Diretório 
```
~$ ls
 . Trab_FTF
 ├── /AVL
 ├── /Btree
 ├── /BinaryTree
 ├── /CarolFI (local)
 ├── /Inputs
 ├── /RBTree
 ├── inputter.cpp
 ├── Makefile
 └─ README.md
```

## CAROL-FI
A linha de comando para executar o CAROL-FI é a seguinte:

Então, para executar o injetor de falhas, use o seguinte comando:
```{r, engine='bash', code_block_name} 
$ ./fault_injector.py -c <conf file> -i <# tests>
```
### Como executar um teste simples
Para testar o RBTree, execute o make na pasta RBTree '/ RBTree'. Uma pasta no diretório / tmp será criada com os binários e arquivos necessários.

Supondo que você tenha clonado o repositório em seu diretório inicial, você poderá executar o teste simples com os seguintes comandos:
```{r, engine='bash', code_block_name} 
$ cd ~/Trab_FTF/RBTree/
$ make
```
Então, para executar o injetor de falhas, use o seguinte comando:
```{r, engine='bash', code_block_name} 
$ cd ~/carol-fi
$ ./fault_injector.py -c ../RBTree/RBTree.conf -i 10
```

## Links
* Repositório CAROL-FI <https://github.com/UFRGS-CAROL/carol-fi>
* Repositório RBTree <https://github.com/anandarao/Red-Black-Tree>
* Repositório AVLTree <https://gist.github.com/Zedonax/4107974>
